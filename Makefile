XBE_TITLE=beep
SRCS = $(wildcard $(CURDIR)/*.c)
NXDK_DIR = $(CURDIR)/../..
GEN_XISO = $(XBE_TITLE).iso

include $(NXDK_DIR)/Makefile
