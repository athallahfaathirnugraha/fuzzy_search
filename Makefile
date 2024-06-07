INCLUDE := -I include

ifeq ($(RELEASE),1)
CFLAGS := $(INCLUDE)
TAR_DIR := release
else
CFLAGS := $(INCLUDE) -DDEBUG -g 
TAR_DIR := debug
endif

SRCS := $(wildcard src/*.c)
OBJS := $(patsubst src/%.c,obj/$(TAR_DIR)/%.o,$(SRCS))
DEPREQ := $(patsubst src/%.c,depreq/$(TAR_DIR)/%.d,$(SRCS))

.PHONY: clean_all clean

out/$(TAR_DIR)/libfsearch.a: $(DEPREQ) $(OBJS) $(DEPS)
	@echo "creating library ($@)"
	mkdir -p $(dir $@)
	ar rcs $@ $(OBJS)

depreq/$(TAR_DIR)/%.d: src/%.c
	@echo "creating dependency file $@"
	mkdir -p $(dir $@)
	rm -rf $@
	touch $@
	printf "$@ obj/$(patsubst depreq/%,%,$(dir $@))" >> $@
	gcc $(CFLAGS) -MM $< >> $@

-include $(DEPREQ)

obj/$(TAR_DIR)/%.o: src/%.c depreq/$(TAR_DIR)/%.d
	@echo "creating object file $@"
	mkdir -p $(dir $@)
	gcc -c $(CFLAGS) $< -o $@

clean:
	@echo "cleaning"
	rm -rf depreq obj out

clean_all: clean