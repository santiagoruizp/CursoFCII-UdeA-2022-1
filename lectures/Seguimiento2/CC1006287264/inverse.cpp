#include <iostream>
#include <string>
using namespace std;

 
// Function to reverse a string
string reverse(string& str)
{
    int n = str.length();
 

    for (int i = 0; i < n / 2; i++)
        {swap(str[i], str[n - i - 1]);
        }
    return str;
}
 
// Driver program
int main()
{
    string str = "geeksforgeeks";
    reverse(str);
    cout << str;
    return 0;
}