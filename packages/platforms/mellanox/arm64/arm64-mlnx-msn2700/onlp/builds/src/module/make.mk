###############################################################################
#
# 
#
###############################################################################
THIS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
arm64_mlnx_msn2700_INCLUDES := -I $(THIS_DIR)inc
arm64_mlnx_msn2700_INTERNAL_INCLUDES := -I $(THIS_DIR)src
arm64_mlnx_msn2700_DEPENDMODULE_ENTRIES := init:arm64_mlnx_msn2700 ucli:arm64_mlnx_msn2700

