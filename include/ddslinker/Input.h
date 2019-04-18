#pragma once

#include <string>
#include <functional>

#include "Base.h"

using namespace std;

namespace Friend {
namespace DDS {

template <typename T>
class Input : public Friend::DDS::Base<T> {
public:
    typedef function<void(T&)> readCallback;
    Input();
    Input(const string& name);
    Input(const string& name, const readCallback& callback);
    virtual void create(const string& name);
    virtual void create(const string& name, const readCallback& callback);
    bool isConnected() override { return false; };
private:
    readCallback _callback;
};

template<typename T>
Input<T>::Input() {}
template<typename T>
Input<T>::Input(const string &name) {

}
template<typename T>
Input<T>::Input(const string &name, const Input::readCallback &callback) {

}
template<typename T>
void Input<T>::create(const string &name) {

}
template<typename T>
void Input<T>::create(const string& name, const readCallback& callback) {

}

} // namespace DDSLinker
} // namespace Friend

