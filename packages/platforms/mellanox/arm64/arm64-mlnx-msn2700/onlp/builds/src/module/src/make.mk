###############################################################################
#
# 
#
###############################################################################

LIBRARY := arm64mlnx_msn2700
$(LIBRARY)_SUBDIR := $(dir $(lastword $(MAKEFILE_LIST)))
include $(BUILDER)/lib.mk
