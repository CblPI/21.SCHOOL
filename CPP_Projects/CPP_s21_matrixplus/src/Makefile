CC = g++
OS = $(shell uname)
ifeq ($(OS),Darwin)
    FLAGS = -lgtest -Wall -Wextra -Werror -std=c++17
endif
ifeq ($(OS),Linux)
    FLAGS = -lgtest -pthread -lrt -lm -lsubunit -Wall -Wextra -Werror -lcheck -lpthread -std=c++17
endif

all: clean s21_matrix_oop.a test

launch: clean
	$(CC) $(FLAGS) s21_matrix_oop.cpp -o test
s21_matrix_oop.a: s21_matrix_oop.o
	ar rcs s21_matrix_oop.a s21_matrix_oop.o

s21_matrix_oop.o:
	$(CC) $(FLAGS) -c s21_matrix_oop.cpp -o s21_matrix_oop.o

test: clean s21_matrix_oop.a 
	$(CC) --coverage test.cpp s21_matrix_oop.cpp -o test $(FLAGS)
	./test

gcov_report : test
	lcov -t "test" -o report.info --no-external -c -d .
	genhtml -o report/ report.info

style_check:
	clang-format -n *.h *.cpp

valgrind: test
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./test

clean:
	@rm -rf s21_matrix_oop ./s21_matrix_oop.a ./s21_matrix_oop.o ./test *.gcda *.gcno report.info cov_res report
