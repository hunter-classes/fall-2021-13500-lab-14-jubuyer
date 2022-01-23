#include <iostream>

#include "MyVector.h"

template <class T>
MyVector<T>::MyVector() {
  storage = 0;
  cap = 128;
}

template <class T>
T &MyVector<T>::operator[] (int n) {
  try {
    if((n > storage) || (n < 0)) { //storage is the actual number of values in MyVector
      throw 1;
    }
  } catch (int e) {
    std::cerr << "\x1B[31mErr: Out of Bounds\033[0m" << '\n';
    exit(0);
  }
  return data[n];
}

template <class T>
void MyVector<T>::push_back(T item) {
  if (storage == cap) {
    resize(cap*2);
  }
  data[storage] = item;
  storage++;
}

template <class T>
T MyVector<T>::pop_back() {
  try {
    if(storage <= 0) { //storage is the actual number of values in MyVector
      throw 1;
    }
  } catch (int e) {
    std::cerr << "\x1B[31mErr: Out of Bounds\033[0m" << '\n';
    exit(0);
  }
  storage--;
  T temp = data[storage];
  data[storage] = 0;

  return temp;
}

template <class T>
T MyVector<T>::pop_back(int n) {
  try {
    if((n > storage) || (n < 0)) { //storage is the actual number of values in MyVector
      throw 1;
    }
  } catch (int e) {
    std::cerr << "\x1B[31mErr: Out of Bounds\033[0m" << '\n';
    exit(0);
  }

  T *arr = new T[cap];
  T temp = data[n];
  for(int i = 0; i < n; i++) {
    arr[i] = data[i];
  }

  for(int i = n; i < cap-1; i++) {
    arr[i] = data[i+1];
  }

  delete[] data;
  data = arr;
  storage--;
  return temp;
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
  for (int i = 0; i < cap; i ++) {
    arr[i] = data[i];
  }

  delete [] data;
  data = arr;
}

template <class T>
bool MyVector<T>::empty() {
  if (storage > 0) {
    return false;
  }

  return true;
}

template <class T>
void MyVector<T>::clear() {
  T *arr = new T[cap];
  for (int i = 0; i < cap; i ++) {
    arr[i] = 0;
  }

  storage = 0;
  delete [] data;
  data = arr;
}
