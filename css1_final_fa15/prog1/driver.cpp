// Louis Paul Romero
// December 17, 2015
// CSS-1 Fa15 Final Exam Prog 1

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>


using namespace std;

void fillVector(vector<string>& PW, ifstream& fin);

void isInPasswordFile(string ary[], int n,vector<string>& PW, ofstream& fout);

void printVector(vector<string>& PW);
int main()
{
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!","ambystomidae"};
	
	ifstream finFromPasswordFile;
	ofstream foutToGoodWordsFile;
	vector<string> passwordVector; 

	finFromPasswordFile.open("passwords.txt");
	foutToGoodWordsFile.open("good_words.txt");
	
	if(finFromPasswordFile.fail()||foutToGoodWordsFile.fail())
	{
		cout << "Error opening file!" << endl;
		exit(1);	
	}

	

	fillVector(passwordVector, finFromPasswordFile);
	foutToGoodWordsFile << "Louis Paul Romero" << endl;
	isInPasswordFile(possible, SIZE, passwordVector, foutToGoodWordsFile);



	finFromPasswordFile.close();
	foutToGoodWordsFile.close();
	return 0;
}


//*************************************
void fillVector(vector<string>& PW, ifstream& fin)
{
	string wordFromFile;

	while(fin >>wordFromFile)
	{
		PW.push_back(wordFromFile);
	}
	
	
}// end fill Vector(_)

void printVector(vector<string>& PW)
{
	for(int ix = 0; ix < PW.size(); ix++)
	{
		cout << PW[ix] << endl;
	}
}

void isInPasswordFile(string ary[], int n, vector<string>& PW, ofstream& fout)
{
	int counter = 0;

	for(int ix = 0; ix < n; ix++)
	{
		for(int jx = 0; jx < PW.size(); jx++)
		{				
			if(ary[ix] == PW[jx])
			{
				counter++;
							
			}
		}

		if(counter == 0)//means no matches in password file so word is good
		{
			fout << ary[ix] << endl;	
		}
		else
		{
			counter = 0;		
		}
	}	
}




