#include "wchar.h"

unsigned short checkSymbol(char ch)
{
	switch(ch)
	{
	case ' ':
		return 26;
	case '.':
		return 27;
	case ',':
		return 28;
	case '\'':
		return 29;
	case '!':
		return 30;
	case '?':
		return 31;
	default :
		return ch;
	}
}

myWchar_t * toWchar(char* s)
{
  int arrSize = 0;//size of char*
  while (s[arrSize] != '\0')
  {	
	  if ((s[arrSize] < 'a' || s[arrSize] > 'z') && s[arrSize] != ' ' && s[arrSize] != '.' && s[arrSize] != '\'' && s[arrSize] != ',' 
		  && s[arrSize] != '!'
		  && s[arrSize] != '?')
	  {
		throw;
	  }
	  arrSize++;
  }
  int size = (arrSize) / 3 + (!arrSize%3==0);	//size of wchar*
  
  myWchar_t* arrOfwchar = new myWchar_t[size];
  unsigned short res = 0;
  for (int i = 0, j = 0; i < arrSize; i += 3,j++)
  {
    if (s[i] == '\0')
		break;
	res = checkSymbol(s[i]);	
	if (res > 25 && res < 32)
		arrOfwchar[j].sym1 = res;
	else 
		arrOfwchar[j].sym1 = s[i] - 97;
    if (s[i+1] == '\0')
		break;
    res = checkSymbol(s[i+1]);	
	if (res > 25 && res < 32)
		arrOfwchar[j].sym2 = res; 
	else
		arrOfwchar[j].sym2 = s[i+1] - 97;
    if (s[i+2] == '\0')
		break;
	res = checkSymbol(s[i+2]);	
	if (res > 25 && res < 32)
		arrOfwchar[j].sym3 = res; 
	else
		arrOfwchar[j].sym3 = s[i+2] - 97;
  }
  return arrOfwchar;
}

char convertToChar(unsigned short sh)
{
	switch(sh)
	{
		case 26:
			return ' ';
		case 27:
			return '.';
		case 28:
			return ',';
		case 29:
			return '\'';
		case 30:
			return '!';
		case 31:
			return '?';
		default:
			return sh + 97;
	}
}
char*& toChar(myWchar_t*& s, size_t size)
{
  char* res = new char[size+1];
  char tempResult = 0;
  for (size_t i = 0, j = 0; i < size; i+=3, j++)
  {
	res[i] = convertToChar(s[j].sym1);
	if (i + 1 >= size) break;
    res[i+1] = convertToChar(s[j].sym2);
	if (i + 2 >= size) break;
    res[i+2] = convertToChar(s[j].sym3);
  }
  res[size] = '\0';
  return res;
}