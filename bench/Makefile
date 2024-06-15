TESTS := $(wildcard src/*.c)
OUTS := $(patsubst src/%.c,out/%.bench,$(TESTS))

.PHONY: all clean

all: $(OUTS)

out/%.bench: src/%.c ../out/debug/libfsearch.a src/bench.h
	@echo "creating $@"
	mkdir -p $(dir $@)
	gcc $< ../out/debug/libfsearch.a -I ../include -DDEBUG -g -o $@

clean:
	@echo "cleaning tests"
	rm -rf out