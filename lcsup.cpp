#define EDGE 0
#define UP 1
#define LEFT 2
#define MATCH 3

#include "lcsup.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[]) {
	int i = 0;
	int j = 0;
	

	//Check Command Line Arguments
	if(argc==4) {
		/*cout << argv[1] << endl;
		cout << argv[2] << endl;
		cout << argv[3] << endl;*/
	} else {
		cout << "Incorrect number of arguments." << endl;
	}
	
	//Read strings from input
	ifstream input1;
	input1.open(argv[2], ios::out | ios::in);
	string word1;
	getline(input1, word1);
	input1.close();
	
	ifstream input2;
	input2.open(argv[1], ios::out | ios::in);
	string word2;
	getline(input2, word2);
	input2.close();
	
	ofstream output;
	output.open(argv[3], ios::out | ios::in | ios::trunc);

	
	
	/* cout << word1 << endl;
	cout << word2 << endl; */
	
	
	//Start Clock
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	int length1 = word1.length();
	int length2 = word2.length();
	
	int lcsVal[length2+1][length1+1] = {};
	int lcsDir[length2+1][length1+1] = {};
	
	for(i=1;i<=length2;i++) {
		for(j=1;j<=length1;j++) {
			if(word2[i-1]==word1[j-1]) {
				//cout << "Comparing " << i << word2[i-1] << " " << j << word1[j-1] << endl;
				lcsVal[i][j] = lcsVal[i-1][j-1] + 1;
				lcsDir[i][j] = MATCH;
			} else if(lcsVal[i-1][j]>=lcsVal[i][j-1]) {
				lcsVal[i][j] = lcsVal[i-1][j];
				lcsDir[i][j] = LEFT;
			} else {
				lcsVal[i][j] = lcsVal[i][j-1];
				lcsDir[i][j] = UP;
			}
		}
	}
	
	string lcs = "";
	i = length2;
	j = length1;
	
	while(lcsDir[i][j]!=EDGE) {
		if(lcsDir[i][j]==LEFT) {
			i--;
		} else if(lcsDir[i][j]==UP) {
			j--;
		} else {
			lcs = word2[i-1] + lcs;
			j--;
			i--;
		}
	}
	
	//End Clock μs
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(t2 - t1).count();
	
	if(length1<=10 && length2 <=10) {
		for(i=0;i<=length2;i++) {
			for(j=0;j<=length1;j++) {
				if(j>0) {
					output << " ";
				}
				output << lcsVal[i][j];
			}
			output << endl;
		}
		if(lcs.length()==0) {
			lcs = "0";
		}
		output << lcs << endl;
		output << duration << "ns" << endl;
	} else {
		output << lcs.length() << endl;
		output << duration << "ns" << endl;
	}
	output.close();
	return 0;
}

