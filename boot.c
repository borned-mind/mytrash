


inline void putch(char ch){
		__asm__ volatile
		(
		"cmp ah, 0x0e\n"
		"je put\n"
		"mov ah, 0x0e\n"
		"put:\n"
		"mov al, %0\n"
		"int 0x10\n" : "=r" (ch)
		);
}

inline void PrintString(char*string){
	while(*string){
		putch(*string);
		string++;
	}
}




