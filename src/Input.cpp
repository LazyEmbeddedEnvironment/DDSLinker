#include "ddslinker/Input.h"

#include <iostream>


namespace Friend {
namespace DDS {
template<typename T>
Input<T>::Input() {}
template<typename T>
void Input<T>::create(const string& name, const readCallback& callback) {

}


void TemporaryFunction (){ Input<int> tempObj; } // Useless but crucial
} // namespace DDSLinker
} // namespace Friend
