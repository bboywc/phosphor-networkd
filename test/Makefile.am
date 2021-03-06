AM_CPPFLAGS = -I${top_srcdir} -I${top_builddir}

TESTS = $(check_PROGRAMS)

check_PROGRAMS = test test_dns_updater test_watch

test_SOURCES = \
	test_util.cpp \
	mock_syscall.cpp \
	test_network_manager.cpp \
	test_ethernet_interface.cpp \
	test_config_parser.cpp \
	test_vlan_interface.cpp

test_dns_updater_SOURCES = test_dns_updater.cpp
test_watch_SOURCES = test_watch.cpp

generic_cpp_flags = -Igtest $(GTEST_CPPFLAGS) $(AM_CPPFLAGS)

generic_cxx_flags = $(PTHREAD_CFLAGS) \
					$(SYSTEMD_CFLAGS) \
					$(SDBUSPLUS_CFLAGS) \
					$(PHOSPHOR_LOGGING_CFLAGS) \
					$(PHOSPHOR_DBUS_INTERFACES_CFLAGS)

generic_ld_flags =  -lgtest_main -lgtest -lstdc++fs \
					$(OESDK_TESTCASE_FLAGS) \
					$(SYSTEMD_LIBS) \
					$(SDBUSPLUS_LIBS) \
					$(PHOSPHOR_LOGGING_LIBS) \
					$(PHOSPHOR_DBUS_INTERFACES_LIBS)

test_CPPFLAGS = ${generic_cpp_flags}
test_CXXFLAGS = ${generic_cxx_flags}
test_LDFLAGS  = ${generic_ld_flags}

test_dns_updater_CPPFLAGS = ${generic_cpp_flags}
test_dns_updater_CXXFLAGS = ${generic_cxx_flags}
test_dns_updater_LDFLAGS  = ${generic_ld_flags}

test_watch_CPPFLAGS = ${generic_cpp_flags}
test_watch_CXXFLAGS = ${generic_cxx_flags}
test_watch_LDFLAGS  = ${generic_ld_flags}

test_LDADD = $(top_builddir)/ethernet_interface.o \
			$(top_builddir)/network_manager.o \
			$(top_builddir)/network_config.o \
			$(top_builddir)/ipaddress.o \
			$(top_builddir)/routing_table.o \
			$(top_builddir)/util.o \
			$(top_builddir)/timer.o \
			$(top_builddir)/system_configuration.o \
			$(top_builddir)/dhcp_configuration.o \
			$(top_builddir)/config_parser.o \
			$(top_builddir)/vlan_interface.o \
			$(top_builddir)/xyz/openbmc_project/Network/VLAN/Create/phosphor_network_manager-server.o \
			$(top_builddir)/xyz/openbmc_project/Network/IP/Create/phosphor_network_manager-server.o

test_dns_updater_LDADD = $(top_builddir)/dns_updater.o
test_watch_LDADD = $(top_builddir)/watch.o
