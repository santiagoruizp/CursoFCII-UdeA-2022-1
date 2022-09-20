#include <iostream>
#include <string>
using namespace std;

string convert(string& s){
  for (int i=0; i< s.length();i++ ){
    if (!(s[i] == 'a' || s[i] == 'e'
            || s[i] == 'i' || s[i] == 'o'
            || s[i] == 'u') )
   {
    s[i]= toupper(s[i]);
    }
  }
  return s;

}
int main ()
{
  string name;

  //cout << "Please, enter your full name: "<<endl;
  getline (std::cin,name);
  
  cout<<convert(name)<<endl;
  return 0;
}