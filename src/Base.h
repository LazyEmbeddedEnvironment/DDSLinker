//
// Created by jonb on 3/21/19.
//
#pragma once

#include <string>
#include <ddslinker/GetTypeName.h>
#include <friend/appbase/AppBase.h>

using namespace std;

namespace Friend {
namespace DDS {

namespace bpo = boost::program_options;
using bpo::options_description;
using bpo::variables_map;

template <typename T>
class Base : public appbase::plugin<Base<T>> {
public:
    APPBASE_PLUGIN_REQUIRES( (AppBase::AppBase) );
    virtual void set_program_options( options_description& cli, options_description& cfg ) override {};
    void plugin_initialize( const variables_map& options ) {};
    void plugin_startup() {};
    void plugin_shutdown() {};

    Base();
    virtual ~Base() {};
    explicit Base(const string& name);
    virtual void create(const string& name);
    virtual T read();
    virtual bool isConnected() = 0;
private:
    string _myName;
    T _lastState;
};

// Implemantation
template<typename T>
Base<T>::Base() = default;
template<typename T>
Base<T>::Base(const string &name) {
    this->create(name);
}
template<typename T>
void Base<T>::create(const string &name) {
    this->_myName = GetTypeName<T>()+"."+name;
}
template<typename T>
T Base<T>::read() {
    return _lastState; // TODO what to do for initial conditions
}

} // namespace DDS
} // namespace Friend

