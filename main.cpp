// file main.cpp
// @author Duong H Chau
// @version lab5

#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Firm.h"
using namespace std;
//-----------------------------------------------------------------------
// main
// read in data file and command file
// process the command and display the outcome
int main(){
	ifstream infile("lab5data.txt"); 
	if (!infile)  {
		cout << "Data File could not be opened." << endl;
		return 1;
	}
	ifstream infile2("lab5command.txt"); 
	if (!infile)  {
		cout << "Command File could not be opened." << endl;
		return 1;
	}
	Firm theFirm;
	theFirm.readClientFile(infile);
	theFirm.readTransaction(infile2);
	theFirm.processTransaction();
	cout<<endl<<"REPORT"<<endl;
	theFirm.displayEOD();
	return 0;
}