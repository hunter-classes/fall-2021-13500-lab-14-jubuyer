#pragma once

#include <iostream>

template <class T>
class MyVector {
public:
  int size();
  int capacity();
  bool empty();
  void push_back(T item);
  void pop_back(int n);
  void pop_back();
  void clear();
  T operator[](int n);
private:

}

#include "funcs.cxx"
