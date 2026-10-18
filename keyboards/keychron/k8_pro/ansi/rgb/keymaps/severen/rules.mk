BOOTMAGIC_ENABLE = yes

TAP_DANCE_ENABLE = yes
SPACE_CADET_ENABLE = no

LTO_ENABLE = yes

# Required by the Keychron wireless driver.
VIA_ENABLE = yes

# GCC 16 warns about an unused variable in the Keychron wireless driver.
ALLOW_WARNINGS = yes

# Keychron's common makefile defines VIA_INSECURE, which undoes QMK's fix for
# the VIA key tester keylogger issue (qmk/qmk_firmware#25414). This disables
# the key tester in VIA and Keychron Launcher.
OPT_DEFS := $(filter-out -DVIA_INSECURE,$(OPT_DEFS))
