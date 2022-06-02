


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}



//User function Template for C++

string reverseWord(string str){

char temp;    
int len = str.length();
int i=0;
  for(i; i<len/2; i++){
      temp = str[i];
      str[i] = str[len-i-1];
      str[len-i-1] = temp;
  }
  return str;
}