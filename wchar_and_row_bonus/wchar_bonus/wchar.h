#pragma once
struct myWchar_t {
  unsigned short sym1 : 5;
  unsigned short sym2 : 5;
  unsigned short sym3 : 5;
};
myWchar_t * toWchar( char* s);
char*& toChar(myWchar_t*& s, size_t size);