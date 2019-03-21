//
// Created by jonb on 3/21/19.
//
#pragma once

#include <string>

using namespace std;

namespace Friend {
namespace DDS {

template <typename T>
class Base {
public:
    Base();
    explicit Base(const string& name);
    virtual void create(const string& name);
    virtual T read();
    virtual bool isConnected();
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
    this->_myName = name;
}
template<typename T>
T Base<T>::read() {
    return _lastState; // TODO what to do for initial conditions
}
template<typename T>
bool Base<T>::isConnected() {
    return false;
}


} // namespace DDS
} // namespace Friend

