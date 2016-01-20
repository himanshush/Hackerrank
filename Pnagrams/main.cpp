#include <iostream>       // std::cout
#include <string>         // std::string
#include <locale>         // std::locale, std::tolower
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace :: std;
unsigned int ch[26];
int main ()
{
  locale loc;
  string str;
  std::getline(std::cin,str);
  //cout << str << endl;
  int tmp;
  int found = 1;
  for (std::string::size_type i=0; i<str.length(); ++i)
  {
    //std::cout << std::tolower(str[i],loc);
    tmp = std::tolower(str[i],loc)-'a';
    //cout << tmp;
    if(tmp >=0 && tmp <26)
        ch[tmp] =1;
  }
  for(int i=0;i<26;i++)
  {
      if(ch[i]==0)
      {
          found = 0;
          break;
      }
  }
  if(found == 1)
    cout << "pangram" << endl;
  else
    cout << "not pangram" <<endl;
  return 0;
}
