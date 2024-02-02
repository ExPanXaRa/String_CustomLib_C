CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -g

LIBS=-lcheck
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBS += -lsubunit -lm -pthread -lrt
endif

TARGET=s21_string

SRCS=s21*.c base_functions/*.c

OBJS=s21*.o

TEST_SRC=check_s21_string.c tests_sscanf/*.c  tests_sprintf/*.c


TEST_TARG=s21_string_test

all: s21_string.a test gcov_report

s21_string.a:
	$(CC) $(SRCS) $(CFLAGS) -c
	ar rsc libs21_string.a $(OBJS)
	ranlib libs21_string.a
	ar rsc s21_string.a $(OBJS)
	ranlib s21_string.a
	rm -f $(OBJS)

test: s21_string.a
	$(CC) $(TEST_SRC) $(CFLAGS) $(LIBS) -L. -ls21_string -o $(TEST_TARG)
	./$(TEST_TARG)
	rm -f $(TEST_TARG) *.o

test_val: s21_string.a
	$(CC) $(TEST_SRC) $(CFLAGS) $(LIBS) -L. -ls21_string -o $(TEST_TARG)
	./$(TEST_TARG)
	valgrind --tool=memcheck --leak-check=yes -s ./$(TEST_TARG)

gcov_report: 
	$(CC) --coverage $(FLAGS) $(SRCS) $(TEST_SRC) -o $(TEST_TARG) $(LIBS)
	./$(TEST_TARG)
	lcov -t "$(TEST_TARG)" -o $(TEST_TARG).info -c -d .
	genhtml -o report $(TEST_TARG).info
	rm -f *.gcda *.gcno *.info $(TEST_TARG)

check_linters:
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format -n *.[ch] tests_sscanf/*.[ch] tests_sprintf/*.[ch] base_functions/*.[ch]
	rm -rf .clang-format

fix_linters:
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format -i *.[ch] tests_sscanf/*.[ch] tests_sprintf/*.[ch] base_functions/*.[ch]
	rm -rf .clang-format

clean_lib:
	rm -f *.[oa]

clean_cov:
	rm -f *.gcno *.gcda *.info *.gcov $(TEST_TARG)


cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem *.[ch] base_functions/*.c

clean: clean_lib clean_cov
	rm -f $(TEST_TARG)
	rm -rf report

rebuild: clean all
