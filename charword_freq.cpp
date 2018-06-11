/*
Name: Gregory Hudson
Professor Lofton Bullard
Foundations of Computer Science (COP 3014)
Module 8: Programming #7
Due date: 3/13/16
Due time: 11:59pm
Points: 10

Description: The Countfreq counts the amount of phrases or words read from the input file stream
as well as the occurences of each letter

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//function prototypes

void Countfreq(int A[], string &);
void Output(int A[]);


//function definitons

/*
Name: Countfreq
preconditons: The data from the input file stream is assigned to a string.
postcondition:The frequency of each letter of the phrase or word  in the string,
as well as the number of  letters in the array.


*/
void Countfreq(int A[], string & phrase) {

	int strlength;
	strlength = phrase.length();

	for (int i = 0; i < 27; i++)
	{

		A[i] = 0;   //all of the indexes of array A are 0 now
					
	}
	

     for (int i = 0; i < strlength; i++) {

		if (phrase[i] == ' ' && phrase[i - 1] != ',' && phrase[i - 1] != '.' && phrase[i - 1] != '\n' && phrase[i - 1] != ' ') {
			A[0]++;
		}
		else if (phrase[i] == ','  && phrase[i - 1] != ' ' && phrase[i - 1] != '.' && phrase[i - 1] != '\n' && phrase[i - 1] != ',') {
			A[0]++;
		}
		else if (phrase[i] == '.'  && phrase[i - 1] != ',' && phrase[i - 1] != ' ' && phrase[i - 1] != '\n' && phrase[i - 1] != '.') {
			A[0]++;
		}
		else if (phrase[i] == '\n'  && phrase[i - 1] != ',' && phrase[i - 1] != '.' && phrase[i - 1] != ' ' && phrase[i - 1] != '\n') {
			A[0]++;
		}

		if ((toascii(phrase[i]) - 64) < 27) {

			A[toascii(phrase[i]) - 64] = A[toascii(phrase[i]) - 64]++;
		}
		else if ((toascii(phrase[i]) - 96) < 27) {

			A[toascii(phrase[i]) - 96] = A[toascii(phrase[i]) - 96]++;
		}

	}

}

/*
Name:Output
preconditon:The frequency of each letter of the word or phrase in the 
string is now written in the array
postconditon: The frequency is printed to the window display if the 
frequency is not zero.
*/
void Output(int A[]) {

	cout << A[0] << " words" << endl;  //prints the amount of words there are

	for (int i = 1; i < 27; i++) {

		if (A[i] != 0) {
			cout << A[i] << " " << static_cast <char> (i + 96) << endl; 
			
			//prints each index of the array if the frequency is greater than zero.
			//static function will change  (i+96) into a character variable.


		}
	}
}
 


//Driver for program

int main() {

	string input;
	int freq[27];

	ifstream in;
	in.open("mytext.dat");

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else {
		
		while (!in.eof()) {

			getline(in, input);  //recieves what is placed into the input file and places it into the array input
			Countfreq(freq, input);
			Output(freq);

		}
			
		in.close();
		return 0;
	}
}
