#include <iostream>

#include "funcs.h"

int main(int argc, char const *argv[]) {
  std::cout << "testing lol" << '\n';
  MyVector<int> vect;
  MyVector<int> sizing;

  std::cout << "testing size and capacity lol" << '\n';

  std::cout << sizing.size() << '\n';
  std::cout << sizing.capacity() << '\n';

  for(int i = 0; i < 200; i++) {
    sizing.push_back(i);
  }
  std::cout << sizing.size() << '\n';
  std::cout << sizing.capacity() << "\n\n";

  MyVector<std::string> vect2;
  std::cout << vect2.size() << '\n';
  std::cout << vect2.capacity() << '\n';

  std::cout << "\ntesting empty() lol" << '\n';
  vect.empty() ? std::cout << "is empty" << '\n' : std::cout << "not empty\n";

  // Throws exception, exits program (works properly)
  // std::cout << "\ntesting operator[] lol" << '\n';
  // //vect does not have any elements, should throw err
  // std::cout << vect[3] << "\n";

  std::cout << "\ntesting push_back() lol" << '\n';

  vect.push_back(121);
  std::cout << "vect[0] = "<< vect[0] << '\n';
  vect.push_back(111);
  std::cout << "vect[1] = "<< vect[1] << '\n';
  std::cout << "vector size is: " << vect.size() << '\n';

  std::cout << "\ntesting pop_back() lol" << '\n';
  std::cout << "pop_back returns "<< vect.pop_back() << '\n';
  std::cout << "vector size is now: " << vect.size() << '\n';

  //empty vector, should throw exception, print err and exit program
  //vect2.pop_back();

  vect.push_back(32);
  vect.push_back(123);
  vect.push_back(94);
  vect.push_back(44);
  vect.push_back(71234);
  vect.push_back(414);
  vect.push_back(7115);
  vect.push_back(4643);

  for(int i = 0; i < vect.size(); i++) {
    std::cout << vect[i] << '\t';
  }
  std::cout << '\n';

  std::cout << "pop_back returns "<< vect.pop_back() << '\n';
  for(int i = 0; i < vect.size(); i++) {
    std::cout << vect[i] << '\t';
  }
  std::cout << '\n';

  std::cout << "\ntesting pop_back(n) lol" << '\n';
  for(int i = 0; i < vect.size(); i++) {
    std::cout << vect[i] << '\t';
  }
  std::cout << '\n';
  std::cout << "pop_back(2) returns "<< vect.pop_back(2) << '\n';
  std::cout << "vector size is now: " << vect.size() << '\n';

  std::cout << "updated vector: ";
  for(int i = 0; i < vect.size(); i++) {
    std::cout << vect[i] << '\t';
  }
  std::cout << '\n';

  std::cout << "\ntesting clear() lol" << '\n';
  vect.clear();
  std::cout << vect.size() << '\n';
  std::cout << vect.capacity() << '\n';

  for(int i = 0; i < vect.size(); i++) {
    std::cout << vect[i] << '\t';
  }

  return 0;
}
