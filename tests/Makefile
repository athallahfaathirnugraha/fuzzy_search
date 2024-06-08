TESTS := $(wildcard src/*.c)
OUTS := $(patsubst src/%.c,out/%.test,$(TESTS))

.PHONY: all clean clean_libtap

all: $(OUTS)

out/%.test: src/%.c ../out/debug/libfsearch.a deps/libtap/libtap.a
	@echo "creating $@"
	mkdir -p $(dir $@)
	gcc $< deps/libtap/libtap.a ../out/debug/libfsearch.a -I ../include -I deps/libtap -DDEBUG -g -o $@

deps/libtap/libtap.a:
	cd deps/libtap && \
	make

clean_libtap:
	cd deps/libtap && \
	git clean -d -x -f && \
	git reset --hard

clean:
	@echo "cleaning tests"
	rm -rf out