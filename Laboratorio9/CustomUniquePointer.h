#ifndef CUSTOMUNIQUEPOINTER_H
#define CUSTOMUNIQUEPOINTER_H

template <typename T> class CustomUniquePointer {
private:
  T *ptr;

public:
  CustomUniquePointer();
};

#include "CustomUniquePointer.hpp"

#endif