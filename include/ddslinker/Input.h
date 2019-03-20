#pragma once

#include <string>
#include <functional>
#include <yarp/os/Port.h>
#include <yarp/os/Bottle.h>
#include <yarp/os/ConnectionReader.h>


using yarp::os::Bottle;
using yarp::os::Port;
using yarp::os::ConnectionReader;
using yarp::os::PortReader;
using namespace std;
namespace Friend {
namespace DDS {
template <typename T>
class Input {
public:
    Input();
//    typedef function<void(T&)> readCallback;
//    void create(const string& name, const readCallback& callback);
private:
    Port port;
};
class YarpReaderDataProcessor : public PortReader {
public:
    typedef std::function<void(ConnectionReader&)> readCallback;
    virtual void setCallback(const readCallback& callback) { _callback = callback; }
    virtual bool read(ConnectionReader& data) override  {
        _callback(data);
        return true;
    }
private:
    readCallback _callback;
};

} // namespace DDSLinker
} // namespace Friend

