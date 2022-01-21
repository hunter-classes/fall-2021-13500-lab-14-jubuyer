#pragma once

#include <iostream>

template <class T>
class MyVector {
private:
  int cap = 128;
  T *data = new T[cap];
  int storage;
public:
  MyVector();
  int size();
  int capacity();
  bool empty();
  void push_back(T item);
  void pop_back(int n);
  void pop_back();
  void clear();
  void resize(int renew);
  T &operator[] (int n);
};

#include "funcs.cxx"
