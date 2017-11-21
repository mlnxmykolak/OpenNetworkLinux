###############################################################################
#
# 
#
###############################################################################
THIS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
arm64mlnx_msn2700_INCLUDES := -I $(THIS_DIR)inc
arm64mlnx_msn2700_INTERNAL_INCLUDES := -I $(THIS_DIR)src
arm64mlnx_msn2700_DEPENDMODULE_ENTRIES := init:arm64mlnx_msn2700 ucli:arm64mlnx_msn2700

