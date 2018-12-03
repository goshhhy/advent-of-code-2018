CFLAGS := -O2 -s
working_dir := $(shell pwd)
out := $(shell basename $(working_dir))

all: $(out)

$(out): $(out).c
	$(CC) $(CFLAGS) -o $@ $<