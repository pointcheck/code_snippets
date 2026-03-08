all:
	@echo "User targets buildc and testc or buildcpp and testcpp"

buildc: libpreloadc.so

buildcpp: libpreloadcpp.so

libpreloadc.so:	libpreload.c
	@echo
	@echo "=== Building malloc wrapper in C"
	cc -c -fPIC -o libpreload.o libpreload.c
	cc -shared -o libpreloadc.so libpreload.o

libpreloadcpp.so: libpreload.cpp
	@echo
	@echo "=== Building malloc wrapper in C++"
	c++ -c -fPIC -o libpreload.o libpreload.cpp
	c++ -shared -o libpreloadcpp.so libpreload.o

testc: libpreloadc.so
	@echo
	@echo "=== Testing malloc wrapper written in C"
	@uname -a
	LD_PRELOAD=./libpreloadc.so /bin/ls -al

testcpp: libpreloadcpp.so
	@echo
	@echo "=== Testing malloc wrapper written in C++"
	@uname -a
	LD_PRELOAD=./libpreloadcpp.so /bin/ls -al

clean:
	rm -rf libpreload.o libpreloadc.so libpreloadcpp.so

