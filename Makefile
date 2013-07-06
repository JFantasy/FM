SRCS = $(wildcard *.cpp)

OBJS = action.o \
	   httpcurl.o \
	   songinfo.o \
	   userinfo.o \
	   cJSON.o \
	   test.o

CC = clang

CXX = clang++

INCLUDES = 

LIBS = -lcurl

Run: $(OBJS)
	$(CXX) $^ -o $@ $(INCLUDES) $(LIBS)

test.o:test.cpp
	$(CXX) -c -o $@ $^

action.o:action.cpp
	$(CXX) -c -o $@ $^

httpcurl.o:httpcurl.cpp
	$(CXX) -c -o $@ $^

songinfo.o:songinfo.cpp
	$(CXX) -c -o $@ $^

userinfo.o:userinfo.cpp
	$(CXX) -c -o $@ $^

cJSON.o:cJSON.c
	$(CC) -c -o $@ $^

clean:
	rm *.o test
