#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <climits>

using namespace std;

void cipher(string &s, char code[3])
{
	for(int i = 0; i < s.length(); i += 3)
	{
		s[i] ^= code[0];
	}
	for(int i = 1; i < s.length(); i += 3)
	{
		s[i] ^= code[1];
	}
	for(int i = 2; i < s.length(); i += 3)
	{
		s[i] ^= code[2];
	}
}

int main()
{
  ifstream fin;

  fin.open("cipher.txt");

  int temp;
  string characters;
  char code[3] = {1,1,1};

  while(fin >> temp)
  {
  	characters.push_back(static_cast<char>(temp));
  }

  string word;
  cout << "enter a word (rebirth) or done for done: ";
	cin >> word;
  while(word != "done")
  {
	  for(code[0] = 1; code[0] != 0; code[0]++)
	  {
	  	cout << (int) code[0] << endl;
	  	for(code[1] = 1; code[1] != 0; code[1]++)
		  {
		  	for(code[2] = 1; code[2] != 0; code[2]++)
			  {
			  	//xor
			  	cipher(characters, code);

			  	//print
			  	if(characters.find(word) != string::npos)
			  	{
			  		cout << "using code " << (int) code[0] << " " << (int) code[1] << " " << (int) code[2] << " produced" << endl;
			  		cout << characters << endl;
			  	}
			  	//unxor
			  	cipher(characters, code);
			  }
			}
	  }
	  cout << "enter a word (rebirth) or done for done: ";
  	cin >> word;
	}

  cout << "enter the correct code (103 111 100) ";
  cin >> temp;
  code[0] = temp;
  cin >> temp;
  code[1] = temp;
  cin >> temp;
  code[2] = temp;
  temp = 0;

	cipher(characters, code);

	for(auto c : characters)
	{
		temp += c;
	}

	cout << "the sum was " << temp << endl;
}