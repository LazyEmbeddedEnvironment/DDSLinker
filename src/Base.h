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
class Base : public AppBase::AppBase {
public:
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
    this->_myName = GetTypeName<T>()+"."+getAppName()+"."+to_string(getInstance())+"."+name;
}
template<typename T>
T Base<T>::read() {
    return _lastState; // TODO what to do for initial conditions, maybe use std variant map for base types
}

} // namespace DDS
} // namespace Friend

