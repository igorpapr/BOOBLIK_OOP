#include <iostream>
#include <string>
#include "wchar.h"
using namespace std;
int main(void)
{
  char str[] = "   whata!niceda' yt..omor?row";
  cout<<"Char[]: \t"<<str<<endl;
  myWchar_t* wstr = toWchar(str);
  cout<<"Wchar_t[]: \t"<<toChar(wstr, strlen(str)) << endl;
}