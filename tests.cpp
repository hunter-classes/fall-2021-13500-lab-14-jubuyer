#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "MyVector.h"

TEST_CASE("size()") {
  MyVector<int> test1;
  MyVector<std::string> test2;
  CHECK(test2.size() == 0);
  CHECK(test1.size() == 0);
  test1.push_back(1);
  CHECK(test1.size() == 1);
  test1.push_back(2);
  CHECK(test1.size() == 2);
}

TEST_CASE("capacity()") {
  MyVector<int> test;
  CHECK(test.capacity() == 128);

  SUBCASE("Testing dynamic resizing") {
    MyVector<int> sizing;
    CHECK(sizing.capacity() == 128);

    for(int i = 0; i < 200; i++) {
      sizing.push_back(i);
    }

    CHECK(sizing.capacity() == 256);

    for(int i = 0; i < 200; i++) {
      sizing.push_back(i);
    }

    CHECK(sizing.capacity() == 512);
  }
}

TEST_CASE("empty()") {
  MyVector<char> test;
  CHECK(test.empty() == true);
  test.push_back('a');
  CHECK(test.empty() == false);
}

TEST_CASE("push_back() and operator[]") {
  MyVector<std::string> test;
  test.push_back("hehe");
  test.push_back("teehee");
  test.push_back("why");
  test.push_back("do");
  test.push_back("i");
  test.push_back("do");
  test.push_back("this");

  CHECK(test[0] == "hehe");
  CHECK(test[1] == "teehee");
  CHECK(test[2] == "why");
  CHECK(test[3] == "do");
  CHECK(test[4] == "i");
  CHECK(test[5] == "do");
  CHECK(test[6] == "this");
}

TEST_CASE("pop_back()") {
  MyVector<std::string> test;
  test.push_back("hehe");
  test.push_back("teehee");
  test.push_back("why");
  test.push_back("do");
  test.push_back("i");
  test.push_back("do");
  test.push_back("this");

  CHECK(test.pop_back() == "this");
  CHECK(test.pop_back() == "do");
  CHECK(test.pop_back() == "i");
  CHECK(test.pop_back() == "do");
  CHECK(test.pop_back() == "why");
  CHECK(test.pop_back() == "teehee");
  CHECK(test.pop_back() == "hehe");

  CHECK(test.empty() == true);

  SUBCASE("push_back then pop_back") {
    test.push_back("test");
    CHECK(test.size() == 1);

    CHECK(test.pop_back() == "test");
  }
}

TEST_CASE("pop_back(n)") {
  MyVector<std::string> test;
  test.push_back("hehe"); //popped
  test.push_back("teehee"); //popped
  test.push_back("why"); //popped
  test.push_back("do"); //popped
  test.push_back("i"); //popped
  test.push_back("do"); //popped
  test.push_back("this"); //popped

  CHECK(test.pop_back(2) == "why");
  CHECK(test.pop_back(0) == "hehe");
  CHECK(test.pop_back(0) == "teehee");
  CHECK(test.pop_back(1) == "i");
  CHECK(test.pop_back(2) == "this");
  CHECK(test.pop_back(1) == "do");
  CHECK(test.pop_back(0) == "do");
}

TEST_CASE("clear()") {
  MyVector<std::string> test;
  test.push_back("hehe");
  test.push_back("teehee");
  test.push_back("why");
  test.push_back("do");
  test.push_back("i");
  test.push_back("do");
  test.push_back("this");

  CHECK(test.size() == 7);

  test.clear();
  
  CHECK(test.size() == 0);
}
