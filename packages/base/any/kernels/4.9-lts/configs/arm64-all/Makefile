############################################################
# <bsn.cl fy=2015 v=onl>
#
#           Copyright 2015 Big Switch Networks, Inc.
#
# Licensed under the Eclipse Public License, Version 1.0 (the
# "License"); you may not use this file except in compliance
# with the License. You may obtain a copy of the License at
#
#        http://www.eclipse.org/legal/epl-v10.html
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
# either express or implied. See the License for the specific
# language governing permissions and limitations under the
# License.
#
# </bsn.cl>
############################################################
THIS_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
include $(ONL)/make/config.mk

ifndef K_TARGET_DIR
K_TARGET_DIR := $(THIS_DIR)
endif

MODSYNCLIST_EXTRA = arch/arm64/include arch/arm64/Makefile arch/arm64/lib
K_PATCH_SERIES=series

include ../../kconfig.mk
K_CONFIG := arm64-all.config
K_BUILD_TARGET := Image Image.gz arm64-mlnx-msn2700-r0.dtb
K_COPY_SRC := arch/arm64/boot/Image
K_COPY_GZIP := 1
ifndef K_COPY_DST
K_COPY_DST := kernel-4.9-lts-arm64-all
endif

export ARCH := arm64
DTS_LIST := arm64-mlnx-msn2700-r0

include $(ONL)/make/kbuild.mk

