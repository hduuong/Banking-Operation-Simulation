// file Firm.cpp
// @author Duong H Chau
// @version LAB5

#include "Firm.h"
//-----------------------------------------------------------------------
// constructor
// a default constructor
Firm::Firm(){
}
//-----------------------------------------------------------------------
// destructor
Firm::~Firm(){
}
//-----------------------------------------------------------------------
// readClientFile
// this reads the client file and instantiate the tree of clients
// @param infile the input file.
void Firm::readClientFile(ifstream& infile){
	string fname;
	string lname;
	int acctNumber, a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
	Client *aClient;

	infile >> lname;
	while(!infile.eof()){
		infile >> fname >> acctNumber >> a1 >> a2 >> a3 >> a4 >> a5
			>> a6 >> a7 >> a8 >> a9 >> a10;
		aClient = new Client(lname,fname,acctNumber,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10);
		clients.insert(aClient);
		infile >> lname;
	}
}
//-----------------------------------------------------------------------
// readTransaction
// this reads the command file and build the stack of transactions
// checks invalid command line of input
// @param infile the input file
// @return true if successfully read in the file
bool Firm::readTransaction(ifstream& infile){
	char type;
	int from,to,amount;
	Transaction  aTrans;
	infile >> type;
	while(!infile.eof()){
		if(type == 'W' || type == 'D'){                   // transaction type Withdraw or Deposite
			infile >> from >> amount;
			aTrans = Transaction(type,from,amount);
		}else if(type == 'M'){                            // transaction type Move
			infile >> from >> amount >> to;
			aTrans = Transaction(type,from,amount,to);
		}else if(type == 'H'){                            // transaction type History
			infile >> from;
			aTrans = Transaction(type,from);
		}else{                                             // incorrect type of transaction
			cout << "Unknown transaction type '" << type << "' requested "<< endl;
			infile >> from >> amount;                      // get rid of bad data, assuming there only 3 datas in a bad one  
		}
		transactions.push(aTrans);
		infile >> type;
	}
	return true;
}
//-----------------------------------------------------------------------
// processTransaction
// process the transaction stack
// @return true if successfull
bool Firm::processTransaction(){
	Transaction aTran;
	Client* client;
	while(transactions.size() != 0){
		aTran = transactions.front();
		char type = aTran.getTranType();
		if(type == 'M')                            // MOVE/TRANSFER TRANSACTION
			moveFunds(aTran.getSourceAcct(), aTran.getAmount(), aTran.getToAcct());

		else if(type == 'H')                                            // HISTORY TRANSACTION
			getClientHistory(aTran.getSourceAcct());

		else{
			int index = aTran.getSourceAcct() % 10;       // %10 to get the index of client's account
			int id = aTran.getSourceAcct() / 10;          // /10 to get the client's ID
			Client temp(id);                              // instantiate a Client that holds the ID
			bool found = clients.retrieve(temp,client);   // retrieve the actual client with same ID from the tree
			if(!found){
				cout<<"Unknown client ID "<< id << " requested "<<endl;
			}else{
				if(type == 'D')                                  // DEPOSIT TRANSACTION
					client->depositToAccount(index,aTran.getAmount());
		
				if(type == 'W')                            // WITHDRAW TRANSACTION
					client->widthdrawlFromAccount(index,aTran.getAmount());
			}
		}
		transactions.pop();
	}
	client = NULL;
	return true;
}
//-----------------------------------------------------------------------
// moveFunds
// transfer fund from one account to another
// @param ID the account moving the balance from
// @param amount the amount of money need to be move
// @param toID the account the money transfer to
// @retrun true if successfull, false otherwise

bool Firm::moveFunds(int ID, int amount, int toID){
	int firstIndex = ID % 10;
	int secondIndex = toID % 10;
	int firstID = ID / 10;
	int secondID = toID / 10;
	Client* sender,* receiver;
	Client temp(firstID);    
	Client temp2(secondID);    
	bool found = clients.retrieve(temp,sender);
	bool find = clients.retrieve(temp2,receiver);
	if(!found || !find){
		cout<<"Unknown client ID "<< firstID << " or " << secondID << " requested "<<endl;
		return false;
	}
	if(sender->widthdrawlFromAccount(firstIndex,amount) != 0){
		sender->deleteMostRecent();
		sender->addHistory('M',ID,amount,toID);
		receiver->depositToAccount(secondIndex,amount);
		return true;
	}else
		return false;
}
//-----------------------------------------------------------------------
// getClientHistory
// display the History of transaction of a specified client
// @param clientID the ID of the client
void Firm::getClientHistory(int clientID)const{
	Client temp(clientID);
	Client* client;
	bool found = clients.retrieve(temp,client);
	if(!found){
		cout <<"Unknown client ID "<< clientID << " requested "<<endl;
	}else{
		client->getHistory();
		client = NULL;
	}
}
//-----------------------------------------------------------------------
// displayEOD
// display the tree of clients
void Firm::displayEOD()const{
	clients.display();
}