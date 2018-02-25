#include<iostream>
#include<vector>

template <class T>
class cont{
	private:
		std::vector<T> v;
	public:
		void operator =(std::initializer_list<T> l) noexcept{
			v=l;
		}
		void insert (std::initializer_list<T> l) noexcept{
			v.insert(v.end(),l.begin(),l.end() );
		}
		decltype( auto ) getv(void){
			return (v); // will return link
		}
};

int main(void){
//	char some_char(256); // warning
//	char some_char_{128}; //compile error

	auto z = {1,2,3,4,5}; // IS std::Initializer_list
	//std::initializer_list<int> z{1,2,3,4,5};
	for(auto x : z)
		std::cout << x << std::endl;
	std::cout << std::endl;
	for( auto x : {1,2,3} )
		std::cout << x << std::endl;
	std::cout << std::endl;

	cont<int> c{};
	c={1,2,3};
	c.insert( {4,5,6} );
	c.getv()[5]=7;
	for(auto x : c.getv()){
		std::cout << x << std::endl;
	}
}
