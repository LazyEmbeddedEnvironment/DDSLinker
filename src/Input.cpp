#include "ddslinker/Input.h"

#include <iostream>


namespace Friend {
namespace DDS {
template<typename T>
Input<T>::Input() {}


void TemporaryFunction (){ Input<int> tempObj; } // Useless but crucial
} // namespace DDSLinker
} // namespace Friend
