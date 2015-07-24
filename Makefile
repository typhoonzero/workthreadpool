LIB_SRC_FILES = src/workthreadpool.cpp src/lckfree.cpp
TEST_SRC_FILES = src/main.cpp
INCLUDE_DIR = src
STD_FLAG = -std=c++0x 

all: main.o libs
	g++ $(STD_FLAG) -o test_workthreadpool main.o libworkthreadpool.so -lpthread
	
main.o: $(TEST_SRC_FILES)
	g++ $(STD_FLAG) -c $(TEST_SRC_FILES) -I$(INCLUDE_DIR)

libs: $(LIB_SRC_FILES)
	g++ $(STD_FLAG) -o libworkthreadpool.so -fPIC -O2 -shared -Wl,--no-as-needed -Isrc $(LIB_SRC_FILES) -lpthread

.PHONY : clean
clean :
	rm -f test_workthreadpool main.o libworkthreadpool.so
