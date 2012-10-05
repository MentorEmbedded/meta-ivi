COMPATIBLE_MACHINE = "pandaboard"

require linux.inc

# The main PR is now using MACHINE_KERNEL_PR, for omap4 see conf/machine/include/omap4.inc
MACHINE_KERNEL_PR_append = "a"

CORTEXA8FIXUP = "no"

# Linaro workign kernel 3.4.11+
#SRCREV = "a5c60c099296fcfc0c8fa8085c40883971486512"
SRCREV = "67c858c2ac6bf304f700246501d574861ea4b0b3"



SRC_URI = "git://git.linaro.org/landing-teams/working/ti/kernel.git;protocol=git \
           file://kernel_af_bus.patch \
           file://defconfig \
	  "

S = "${WORKDIR}/git"
