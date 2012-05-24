HOMEPAGE = "http://www.ofono.org"
SUMMARY  = "open source telephony"
DESCRIPTION = "oFono is a stack for mobile telephony devices on Linux. oFono supports speaking to telephony devices through specific drivers, or with generic AT commands."
LICENSE  = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=eb723b61539feef013de476e68b5c50a \
                    file://src/ofono.h;beginline=1;endline=20;md5=3ce17d5978ef3445def265b98899c2ee"

inherit autotools pkgconfig update-rc.d

DEPENDS  = "dbus glib-2.0 udev mobile-broadband-provider-info ${@base_contains('DISTRO_FEATURES', 'bluetooth','bluez4', '', d)} ${@base_contains('DISTRO_FEATURES', 'systemd', 'systemd', '', d)}"

INITSCRIPT_NAME = ""
INITSCRIPT_PARAMS = ""

do_install_append() {
	if [[ "${DISTRO_FEATURES}" == *"systemd"*  ]]
	then
		rm -rf ${D}${sysconfdir}/init.d/
	else
		install -d ${D}${sysconfdir}/init.d/
		install -m 0755 ${WORKDIR}/ofono ${D}${sysconfdir}/init.d/ofono
	fi
}

PACKAGES =+ "${PN}-tests ${PN}-systemd"

FILES_${PN}-systemd += "${base_libdir}/systemd/system"
FILES_${PN} += "${base_libdir}/udev ${systemd_unitdir}"
FILES_${PN}-tests = "${libdir}/ofono"

RDEPENDS_${PN}-tests = "python python-pygobject"
# Systemd service needs systemd
RDEPENDS_${PN}-systemd = "systemd"
