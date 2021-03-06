DESCRIPTION = "GENIVI P1 Abstract components (AC)"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${IVI_COREBASE}/meta-ivi/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"
PR = "r0"

inherit packagegroup

PACKAGES = "\
    packagegroup-abstract-component-p1 \
    "

ALLOW_EMPTY_${PN} = "1"

RDEPENDS_${PN} += "\
    bluez4 \
    bluez4-systemd \
    eglibc \
    layer-management \
    obex-client \
    obexd \
    "
