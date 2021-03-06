#pragma once

#include <ifaddrs.h>

#include <list>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <set>
#include <chrono>
#include <systemd/sd-event.h>

namespace phosphor
{
namespace network
{

using namespace std::chrono_literals;

// wait for three seconds before restarting the networkd
constexpr auto restartTimeout = 3s;

// refresh the objets after five seconds as network
// configuration takes 3-4 sec after systemd-networkd restart.
constexpr auto refreshTimeout = restartTimeout + 7s;

namespace systemd
{
namespace config
{

constexpr auto networkFilePrefix = "00-bmc-";
constexpr auto networkFileSuffix = ".network";
constexpr auto deviceFileSuffix = ".netdev";

}// namespace config
}// namespace systemd

using IntfName = std::string;

struct AddrInfo {
    uint8_t addrType;
    std::string ipaddress;
    uint16_t prefix;
};

using Addr_t = ifaddrs*;

struct AddrDeleter
{
    void operator()(Addr_t ptr) const
    {
        freeifaddrs(ptr);
    }
};

using AddrPtr = std::unique_ptr<ifaddrs, AddrDeleter>;

/* Need a custom deleter for freeing up sd_event */
struct EventDeleter
{
    void operator()(sd_event* event) const
    {
        event = sd_event_unref(event);
    }
};
using EventPtr = std::unique_ptr<sd_event, EventDeleter>;

template<typename T>
using UniquePtr = std::unique_ptr<T, std::function<void(T*)>>;

using AddrList = std::list<AddrInfo>;
using IntfAddrMap = std::map<IntfName, AddrList>;
using InterfaceList = std::set<IntfName>;

}//namespace network
}//namespace phosphor
