CC := gcc
LD := gcc
CCFLAGS := -Wall -Wextra -g
LDFLAGS := -g
INCLDIRS := CUT/src ../include
LIBS := -lm

CUT_SRC := CUT/src/cut.c
CUT_OBJ := $(CUT_SRC:%.c=%.o)
TEST_DIRS := $(filter-out CUT/,$(wildcard */))
SRCS := $(CUT_SRC) $(foreach dir,$(TEST_DIRS),$(wildcard $(dir)*.c))
OBJS := $(SRCS:%.c=%.o)

INC_PARAMS=$(foreach d, $(INCLDIRS), -I$d)

TARGETS := test $(TEST_DIRS:%=%test)

all: $(TARGETS)

test: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

define make_dir_test_rule
$1test: $(CUT_OBJ) $$(patsubst %.c,%.o,$$(wildcard $1*.c))
	$(LD) $(LDFLAGS) -o $$@ $$^ $(LIBS)
endef

$(foreach dir,$(TEST_DIRS),$(eval $(call make_dir_test_rule,$(dir))))

%.o: %.c
	$(CC) $(CCFLAGS) $(INC_PARAMS) -c -o $@ $<

clean:
	rm -rf $(TARGETS) $(OBJS)
