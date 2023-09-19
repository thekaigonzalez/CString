ALL:
	@cpplint string-test-1.c string.c
	@clang-format --style=GNU -i string-test-1.c string.c string.h
	@gcc	string-test-1.c string.c -o testes/string-test-1 -Wno-implicit-int