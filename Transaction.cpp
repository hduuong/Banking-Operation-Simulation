// file Transaction.cpp
// @author Duong H Chau
// @version Lab5


#include "Transaction.h"
//-----------------------------------------------------------------------
// constructor
// give default values to the private members
Transaction::Transaction(){
	transType = ' ';
	sourceAcct = 0;
	toAcct = 0;
	amount = 0;
}
//-----------------------------------------------------------------------
// constructor
// takes in values for the private members through params
// @param type type of transaction
// @param from ID of the account processes the transaction
// @param amt amount of money being processed
// @param to ID of the account recieve the amount
Transaction::Transaction(char type,int from,int amt,int to){
	transType = type;
	sourceAcct = from;
	toAcct = to;
	amount = amt;
}
//-----------------------------------------------------------------------
// operator<<
// overload the << operator to display the transaction
// @param output the output object
// @param transaction the transaction that needed to be printed out
// @return the output onject
ostream& operator<<(ostream& output, const Transaction& transaction){
	string fromA;
	int acc = transaction.getSourceAcct() % 10;
	switch (acc){
	case 0:
		fromA = "Money Market Fund";
		break;
	case 1:
		fromA = "Prime Money Market Fund";
		break;
	case 2:
		fromA = "Long-Term Bond Fund";
		break;
	case 3:
		fromA = "Short-Term Bond Fund";
		break;
	case 4:
		fromA = "500 Index Fund";
		break;
	case 5:
		fromA = "Capital Value Fund";
		break;
	case 6:
		fromA = "Growth Equity Fund";
		break;
	case 7:
		fromA = "Growth Index Fund";
		break;
	case 8:
		fromA = "Value Fund";
		break;
	case 9:
		fromA = "Value Stock Fund";
		break;
	}
	if(transaction.getTranType() == 'D'){
		output << "deposit   $" << setw(6) << transaction.getAmount() << "   into " << fromA <<endl;
	}else if(transaction.getTranType() == 'W'){
		output << "withdraw  $" << setw(6) << transaction.getAmount() << "   from " << fromA <<endl;
	}else if(transaction.getTranType() == 'M'){
		int receiveID = transaction.getToAcct() / 10;
		int receiveAcc = transaction.getToAcct() % 10;
		string toAcc;
		switch (receiveAcc){
		case 0:
			toAcc = "Money Market Fund";
			break;
		case 1:
			toAcc = "Prime Money Market Fund";
			break;
		case 2:
			toAcc = "Long-Term Bond Fund";
			break;
		case 3:
			toAcc = "Short-Term Bond Fund";
			break;
		case 4:
			toAcc = "500 Index Fund";
			break;
		case 5:
			toAcc = "Capital Value Fund";
			break;
		case 6:
			toAcc = "Growth Equity Fund";
			break;
		case 7:
			toAcc = "Growth Index Fund";
			break;
		case 8:
			toAcc = "Value Fund";
			break;
		case 9:
			toAcc = "Value Stock Fund";
			break;
		}
		output << "move      $" << setw(6) << transaction.getAmount() << "   from " << fromA <<endl;
		output << "                    to " << toAcc << " for client " << receiveID <<endl;
	}else {
		output << "history" << endl;
	}

	return output;
}
int Transaction::getAmount()const{
	return amount;
}

int Transaction::getSourceAcct()const{
	return sourceAcct;
}

int Transaction::getToAcct()const{
	return toAcct;
}

char Transaction::getTranType()const{
	return transType;
}