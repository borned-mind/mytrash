#include<memory>
#include<iostream>
int main(void){
			std::shared_ptr<int> ip(new int(3), [](int* dPtr){free(dPtr);std::cout << "I am deleted" << std::endl;}  );
			std::shared_ptr<int> s(ip);
			s=nullptr;
			// ip have it
			std::cout << *ip << std::endl;
			ip=nullptr; // now not.
			/*
				operator overloading^
				will do delete when all references to pointer be free
			*/


			std::unique_ptr<int> ip1;/*
				not allow copying ( operator=(std::unique_ptr) operator=(T)...)
			*/
//			std::unique_ptr<int> err=ip1;
			std::auto_ptr<int> ip2(new int[4]); /*
				 [[deprecated]]
				give all to other when copying
			*/
			std::auto_ptr<int> tmp(ip2);
			if( ip2.get() == nullptr ) {
				std::cout << "is nullptr" << std::endl;
				if(tmp.get() != nullptr) std::cout << " and is not nullptr " << std::endl;
			}

			std::weak_ptr<int> ip3;
			/*delete cycle. not allow work without lock(shared_ptr)
				*/
}
