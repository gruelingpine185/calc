
inc_dir = inc/$(project_name)
src_dir := src
bin_dir := bin

project_name := calc
project := $(bin_dir)/$(project_name)

main := $(src_dir)/main.c
headers := $(wildcard $(inc_dir)/*.h)
sources := $(wildcard $(src_dir)/*.c)
objects := $(patsubst $(src_dir)/%.c, $(bin_dir)/%.o, $(filter-out $(main), $(sources)))

c_std := -std=c11
c_opt := -O2
c_wrn := -Wall -Wextra -pedantic
c_inc := -I$(inc_dir)

CC ?= clang
CFLAGS := $(c_std) $(c_opt) $(c_wrn) $(c_inc)


.PHONY: all clean
all:
	@$(MAKE) $(project)
clean:
	rm -rf $(wildcard $(bin_dir) $(project) *.o)

$(project): $(main) $(objects)
	$(CC) $(CFLAGS) $^ -o $@

$(bin_dir)/%.o: $(src_dir)/%.c $(inc_dir)/%.h $(bin_dir)
	$(CC) $(CFLAGS) -c $< -o $@

$(bin_dir):
	-mkdir $@
