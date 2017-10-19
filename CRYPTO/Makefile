COMPILER=gcc
nameprogram=check
namelibrary=cryptome
libraryexest=so
libpath=lib
build=tmp
srcpath=src
binpath=bin
all:
	$(COMPILER) -c $(srcpath)/lib$(namelibrary).c -fPIC -o $(build)/lib$(namelibrary).o
	$(COMPILER) -shared $(build)/lib$(namelibrary).o -o $(libpath)/lib$(namelibrary).$(libraryexest)
	$(COMPILER) $(srcpath)/main.c -L./$(libpath) -l$(namelibrary) -o $(binpath)/$(nameprogram)
clean:
	rm $(build)/*
	rm $(libpath)/*
	rm $(binpath)/*
