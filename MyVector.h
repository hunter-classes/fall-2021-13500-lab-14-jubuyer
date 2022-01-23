#pragma once

#include <iostream>

template <class T>
class MyVector {
private:
  int cap = 128; //initial capacity
  T *data = new T[cap]; //initialized dynamic array
  int storage; // actual size of vector (# of elements)
public:
  MyVector(); //done
  int size(); //done
  int capacity(); //done
  bool empty(); //done
  void push_back(T item); //done
  T pop_back(int n); //done
  T pop_back(); //done
  void clear(); //done
  void resize(int renew); // used to update capacity (done)
  T &operator[] (int n); //done
};

#include "MyVector.cxx"
