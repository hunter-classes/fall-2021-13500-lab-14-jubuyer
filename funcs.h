#pragma once

#include <iostream>

template <class T>
class MyVector {
private:
  int cap = 128; //initial capacity
  T *data = new T[cap]; //initialized dynamic array
  int storage; // actual size of vector (# of elements)
public:
  MyVector();
  int size();
  int capacity();
  bool empty();
  void push_back(T item);
  void pop_back(int n);
  void pop_back();
  void clear();
  void resize(int renew); // used to update capacity
  T &operator[] (int n);
};

#include "funcs.cxx"
