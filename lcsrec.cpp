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

int lcsm(string a, string b) {
	//cout << a << " vs " << b << endl;
	if(a.length()==0 || b.length()==0) {
		return 0;
	} else if(a[a.length()-1] == b[b.length()-1]) {
		return lcsm(a.substr(0,a.length()-1),b.substr(0,b.length()-1)) + 1;
	} else {
		int n1 = lcsm(a.substr(0,a.length()-1),b.substr(0,b.length()));
		int n2 = lcsm(a.substr(0,a.length()),b.substr(0,b.length()-1));
		return max(n1, n2);
	}
	cout << "Whoops" << endl;
	return -1;
}

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
	int lcslength = 0;
	
	lcslength = lcsm(word1, word2);
	
	//End Clock μs
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(t2 - t1).count();
	

	output << lcslength << endl;
	output << duration << "ns" << endl;
	output.close();
	return 0;
}

