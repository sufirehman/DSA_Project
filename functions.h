#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"queues.h"
queues q;
using namespace std;
string s[] = { "Phe","Phe","Leu","Leu","Ser","Ser","Ser","Ser"
			,"Tyr","Tyr","STOP","STOP","Cys","Cys","STOP","Trp"
			,"Leu","Leu","Leu","Leu","Pro","Pro","Pro","Pro"
			,"His","His","Gin","Gin","Arg","Arg","Arg","Arg"
			,"Ile","Ile","Ile","Met","Thr","Thr","Thr","Thr"
			,"Asn","Asn","Lys","Lys","Ser","Ser","Arg","Arg"
			,"Val","Val","Val","Val","Ala","Ala","Ala","Ala"
			,"Asp","Asp","Glu","Glu","Gly","Gly","Gly","Gly"
};
///converting form DNA to mRNA
char convert(char input);
bool is_start(char a, char b, char c);
bool is_end(char a, char b, char c);
void Convert_to_mRNA(string INPUT, int size) {

	ofstream outputfile("mRNA.txt");
	int flag = 0;
	for (int i = 0; i < size; i++) {
	
		if (is_start(INPUT[i],INPUT[i + 1],INPUT[i + 2])&&i<size-2) {
			flag = 1;
		
		}

		if (i<size-2 && flag == 1 && is_end(INPUT[i],INPUT[i+1],INPUT[i+2])) {
			flag = 0;
			while (!q.is_empty()) {
				outputfile << q.Dequeue();
			}
			outputfile << convert(INPUT[i]) << convert(INPUT[i + 1]) << convert(INPUT[i + 2])<<" ";
			outputfile << endl;

			i = i + 2;
		}

		if (flag == 1&&i<size-2) {

			q.Enqueue(convert(INPUT[i]));
			q.Enqueue(convert(INPUT[i+1]));
			q.Enqueue(convert(INPUT[i+2]));
			q.Enqueue(' ');
			i = i + 2;
		}

		
	}
}




char convert(char input) {    // DNA TO mRNA
	switch (input) {
	case 'A':
		return 'U';
	case 'G':
		return 'C';
	case 'C':             //A G C T are only used in DNA
		return 'G';       //data Validation
	case 'T':
		return 'A';
	default:
		cout << "invaild DNA SEQUANCE";
		getchar();
		exit(1);
		break;
	}
}
bool is_start(char a, char b, char c) {
	if (a == 'T'&& b == 'A'&& c == 'C') {                                   //DNA MUST STARTS FROM TAC
		return 1;
	}
	else return 0;
}
bool is_end(char a, char b, char c) {
	if ((a == 'A'&& b == 'T'&& c == 'T') || (a == 'A'&&b == 'T'&&c == 'C') || (a == 'A'&&b == 'C'&& c == 'T')) {
		return 1;                                                        //DNA MUST END WITH ATT || ATC || ACT 
	}
	else return 0;
}


//////converting form mRNA to protien
int Decode(char input) {
	switch (input) {
	case 'U':
		return 0;
	case 'C':
		return 1;        // only these are used in mRNA
	case 'A':           
		return 2;
	case 'G':
		return 3;
	default:
		return -1;
	}
}
void convert_to_Protien(string input, int size) {
	size = size - (size % 4);
	cout << endl << endl;
	int i = 0;
	while (i < size) {        
		cout << s[16 * Decode(input[i]) + 4 * Decode(input[i + 1]) + Decode(input[i + 2])] << " ";
			i = i + 4;
	}
	return;
}
