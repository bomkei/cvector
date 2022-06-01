TARGET	= libcvector.a

BUILD		= lib
OUTPUT	= $(BUILD)/$(TARGET)

INCLUDE	= include
SOURCE	= src

CFILES	= $(wildcard $(SOURCE)/*.c)
OFILES	= $(patsubst %.c, $(BUILD)/%.o, $(notdir $(CFILES)))

CFLAGS	= -O2 -std=c17 $(foreach dir,$(INCLUDE),-I$(CURDIR)/$(dir))

all: $(OUTPUT)

$(BUILD)/%.o: $(SOURCE)/%.c
	@[ -d $(BUILD) ] || mkdir -p $(BUILD)
	@echo $(notdir $<)
	@clang $(CFLAGS) -c -o $@ $<

$(OUTPUT): $(OFILES)
	@[ -d $(BUILD) ] || mkdir -p $(BUILD)
	@echo linking...
	@ar rsc $@ $^