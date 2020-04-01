#
#            DMBS Build System
#     Released into the public domain.
#
#  dean [at] fourwalledcubicle [dot] com
#        www.fourwalledcubicle.com
#

# Run "make help" for target help.

MCU          = atmega328p
ARCH         = AVR8
F_CPU        = 8000000
OPTIMIZATION = s
TARGET       = example
SRC          = $(TARGET).c
CC_FLAGS     = -Iconfig
LD_FLAGS     = 

AVRDUDE_MCU	 		= m328p
AVRDUDE_PROGRAMMER 	= usbasp
# set ISP clock period at least 4us (for able to program 1MHz default MCU clock)
AVRDUDE_BITCLK	   	= 4.0
AVRDUDE_LFUSE 		= 0xE2
AVRDUDE_HFUSE 		= 0xDC
AVRDUDE_EFUSE 		= 0xFF

# CLUNET_BOOTLOADER_SUPPORT - bootloader support configuration
# 0: main project without any bootloader support
# 1: main project with bootloader support (without bootloader code)
# 2: main project with bootloader support (with bootloader code)
# 3: bootloader code only (target will be renamed to 'bootloader')
CLUNET_BOOTLOADER_SUPPORT = 1
# CLUNET_BOOTLOADER_ADDRESS - bootloader byte address in hex format (datasheet word address must be multiply by 2)
# Must be defined if CLUNET_BOOTLOADER_SUPPORT > 0
CLUNET_BOOTLOADER_ADDRESS = 0x7C00

# Default target
all:

# Include libraries and DMBS build script makefiles
DMBS_PATH   ?= ../../../../fork/dmbs/DMBS
LIB_PATH    ?= ../../libs

# Include Clunet module
include $(LIB_PATH)/clunet-avr-dmbs/clunet.mk

include $(DMBS_PATH)/core.mk
include $(DMBS_PATH)/gcc.mk
include $(DMBS_PATH)/cppcheck.mk
include $(DMBS_PATH)/doxygen.mk
include $(DMBS_PATH)/dfu.mk
include $(DMBS_PATH)/hid.mk
include $(DMBS_PATH)/avrdude.mk
include $(DMBS_PATH)/atprogram.mk
