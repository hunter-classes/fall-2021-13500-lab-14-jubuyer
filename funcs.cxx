#include <iostream>

#include "funcs.h"

template <class T>
MyVector<T>::MyVector() {
  storage = 0;
  cap = 128;
}

template <class T>
int MyVector<T>::size() {
  return storage;
}

template <class T>
int MyVector<T>::capacity() {
  return cap;
}

template <class T>
void MyVector<T>::resize(int renew) {
  cap = renew;
  T *arr = new T[renew];
  data = arr;
}

template <class T>
bool MyVector<T>::empty() {
  if (storage > 0) {
    return false;
  }

  return true;
}
