.PHONY: clean main release debug

clean:
	make clean --makefile=Makefile.build

main: release

release:
	make -j $(thread_count) release --makefile=Makefile.build user_compile_flags="$(compile_flags) -Doverride=''" user_link_flags="$(link_flags) -s" program_name="$(program_name)"

debug:
	make -j $(thread_count) debug --makefile=Makefile.build user_compile_flags="$(compile_flags) -std=c++11 -O0 -g3 -D_DEBUG" user_link_flags="$(link_flags)" program_name="$(program_name)"
