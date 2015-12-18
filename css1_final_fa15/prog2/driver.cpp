// Louis Paul Romero
// December 17, 2015
// Program 2

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& fin, string ary[][C]);

void printArray(string ary[][C]);

//void Array(ifstream& A_in, string [][C]);

int main()
{
	ifstream finNorthPoleText;
	ofstream foutStatusText;
	string arrayOfData[R][C];
	
	finNorthPoleText.open("northpole.txt");
	foutStatusText.open("status.txt");
	
	if(finNorthPoleText.fail()||foutStatusText.fail())
	{
		cout << "Error opening file" << endl;
		exit(1);	
	}

	
	fillArray(finNorthPoleText, arrayOfData);
	//printArray(arrayOfData);

	finNorthPoleText.close();
	foutStatusText.close();
	
		
	return 0;
}

// ********************************
void fillArray(ifstream& fin, string ary[][C])
{
	for(int ix = 0; ix < R; ix++)
	{
		for(int jx = 0; jx < C; jx ++)
		{
			fin >> ary[R][C];		
		}
	}

}//end fillArray

void printArray(string ary[][C])
{
	for(int ix = 0; ix < R; ix++)
	{
		for(int jx = 0; jx < C; jx++)
		{
			cout << ary[R][C];		
		}
		cout << endl;
	}
}//end printArray




 
