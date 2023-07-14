CC=g++
CFLAGS= -std=c++17
OS := $(shell uname -s)
ifeq ($(OS), Darwin)
  LDFLAGS= -lgtest -lstdc++
else
  LDFLAGS=-lgtest -lsubunit -lrt -lpthread -lm
endif

EXECUTABLE=result_file
LCOVEXEC=$(EXECUTABLE).info
REPORTDIR=report
QPATH=~/Qt/$(QVER)/gcc_64/bin
QVER=$(shell ls ~/Qt/ | grep -e "^[5|6].")

all:  build install tests dvi

build:
	[ -d ../build ] || mkdir ../build 
	cp qcustomplot.h ../build
	export PATH=$(QPATH):$$PATH; cd ../build; qmake ../src/View/Calc_v2.pro; make

rebuild: clean build

install: build
	mv ../build/Calc_v2 .
	
uninstall:
	rm -rf Calc_v2

tests:
	g++ -std=c++17 -coverage -c Sources/model.cc
	g++ -std=c++17 -c test.cc
	g++ -std=c++17 -coverage test.cc -o test model.o -lgtest -lstdc++
	./test

dist: 
	[ -f  Calc_v2 ] || install
	tar -cvzf smartcalc_1.0.tar.gz Calc_v2
	mkdir -p dist
	mv smartcalc_1.0.tar.gz dist

gcov_report: tests
	lcov -t $(EXECUTABLE) -o $(LCOVEXEC) --no-external -c -d .
	genhtml -o $(REPORTDIR) $(LCOVEXEC)
	firefox report/index.html

check:
	cp -f ../materials/linters/.clang-format clang-format
	clang-format -i Headers/*.h Sources/*.cc *.h *.cc
	clang-format -n Headers/*.h Sources/*.cc *.h *.cc
	rm -rf clang-format

valgrind: tests
	valgrind --leak-check=full  --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind.txt ./test

clean:
	rm -rf *.o *.gcda *.gcno *.gcov *.info test report dist Calc_v2 ../build *.html *.txt

dvi:
	makeinfo --html --no-split -o README.html smartcalc.texi --force
	firefox README.html


