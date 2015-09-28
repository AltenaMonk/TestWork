.PHONY: clean main release debug unittest.clean unittest.release unittest.debug unittest.execute

program_name	:= program
compile_flags	:=
thread_count	:= 6
link_flags	:=

clean:
	make clean --makefile=Makefile.build
	make unittest.clean

main: release

release:
	make -j $(thread_count) release --makefile=Makefile.build user_compile_flags="$(compile_flags) -Doverride=''" user_link_flags="$(link_flags) -s" program_name="$(program_name)"

debug:
	make -j $(thread_count) debug --makefile=Makefile.build user_compile_flags="$(compile_flags) -std=c++11 -O0 -g3 -D_DEBUG" user_link_flags="$(link_flags)" program_name="$(program_name)"

unittest.clean:
	make --directory=./test clean

unittest.release:
	make --directory=./test release user_compile_flags="$(compile_flags)"

unittest.debug:
	make --directory=./test debug user_compile_flags="$(compile_flags) -std=c++11"

unittest.execute:
	test/binaries/test --gtest_catch_exceptions=1
