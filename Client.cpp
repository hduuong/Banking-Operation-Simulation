// file Client.cpp
// @author Duong H Chau
// @version LAB5

#include "Client.h"
//-----------------------------------------------------------------------
// operator<<
// print out the information of a client
// the information includes owner, 10 accounts.
// @param output the output object
// @param client the client that needed to be printed out
// @return the output object
ostream& operator<<(ostream& output, const Client& client){
	output << client.getID() << "  " << client.owner <<endl;;
	output << "Initial Balances:  " << setw(6) << client.accounts[0].getStartBalance()
		<< setw(6) << client.accounts[1].getStartBalance()
		<< setw(6) << client.accounts[2].getStartBalance()
		<< setw(6) << client.accounts[3].getStartBalance()
		<< setw(6) << client.accounts[4].getStartBalance()
		<< setw(6) << client.accounts[5].getStartBalance()
		<< setw(6) << client.accounts[6].getStartBalance()
		<< setw(6) << client.accounts[7].getStartBalance()
		<< setw(6) << client.accounts[8].getStartBalance()
		<< setw(6) << client.accounts[9].getStartBalance() << endl;
	
	output << "Final Balances:    " << setw(6) << client.accounts[0].getBalance()
		<< setw(6) << client.accounts[1].getBalance()
		<< setw(6) << client.accounts[2].getBalance()
		<< setw(6) << client.accounts[3].getBalance()
		<< setw(6) << client.accounts[4].getBalance()
		<< setw(6) << client.accounts[5].getBalance()
		<< setw(6) << client.accounts[6].getBalance()
		<< setw(6) << client.accounts[7].getBalance()
		<< setw(6) << client.accounts[8].getBalance()
		<< setw(6) << client.accounts[9].getBalance() << endl;

	return output;
}
//-----------------------------------------------------------------------
// constructor
// construct a client with all the information given in the params
// @param last the owner's lastname
// @param first the owner's firstname
// @param id the client's ID
// @param a1 amount money used to instantiate MoneyMarket
// @param a2 amount money used to instantiate PrimeMoneyMarket
// @param a3 amount money used to instantiate LongTermBond
// @param a4 amount money used to instantiate ShortTermBond
// @param a5 amount money used to instantiate FHIFund
// @param a6 amount money used to instantiate CVFund
// @param a7 amount money used to instantiate GEFund
// @param a8 amount money used to instantiate GIfund
// @param a9 amount money used to instantiate ValueFund
// @param a10 amount money used to instantiate VSIndex
Client::Client(string last, string first, int id, int a1, int a2, int a3, int a4,
			   int a5, int a6, int a7, int a8, int a9, int a10){
				   owner.setFirstName(first);
				   owner.setLastName(last);
				   ID = id;
				   accounts[0] = MoneyMarket(a1);        //[1] has to exist first inorder to instantiate [0]
				   accounts[1] = PMoneyMarket(a2);       //also the otherway around. 2 ways dependancy
				   accounts[2] = LTermBond(a3);          //make a new METHOD that do add reference of account to pointer
				   accounts[3] = STermBond(a4);
				   accounts[4] = FHIFund(a5);
				   accounts[5] = CVFund(a6);
				   accounts[6] = GEFund(a7);
				   accounts[7] = GIFund(a8);
				   accounts[8] = ValueFund(a9);
				   accounts[9] = VSIndex(a10);
				   
				   
}
//-----------------------------------------------------------------------
// constructor
// a temp contructor that only takes in an ID
// this is used to find the real client that has same ID
// @param id the ID of the client
Client::Client(int id){
	ID = id;
}
//-----------------------------------------------------------------------
// detructor
// clear out all the values/memories of the client
Client::~Client(){
	clearAccounts();
	history.clear();
}
//-----------------------------------------------------------------------
// getID
// get the client's ID
// return the client's ID
int Client::getID()const{
	return ID;
}

//-----------------------------------------------------------------------
// getOwner
// print out the name of the owner
void Client::getOwner()const{
	cout << owner << endl;
}
//-----------------------------------------------------------------------
// clearAccounts
// go through the list of accounts and clear them
void Client::clearAccounts(){
	for(int i = 0; i < 10; i++){
		accounts[i].clearAcct();
	}
}
//-----------------------------------------------------------------------
// getHistory
// display the history of transaction
// go through the list of transactions using iterator and print out.
void Client::getHistory()const{       
	cout<< endl << "History of transactions for client "<< owner <<", client ID = "<< ID <<endl;
	cout<<"Type      Amount  Detail" <<endl;
	cout<<"--------- ------- --------------------------------------"<<endl;
	list<Transaction>::const_iterator iterator;
	for(iterator = history.begin(); iterator!= history.end(); ++iterator){
		cout << *iterator;
	}
	cout<<"history"<<endl <<endl;
}
//-----------------------------------------------------------------------
// addHistory
// add a successful transaction to the history list
// @param type type of transaction
// @param from ID of the account processes the transaction
// @param amt amount of money being processed
// @param to ID of the account recieve the amount
void Client::addHistory(char type, int from, int amt, int to){
	Transaction newTransaction(type,from,amt,to);
	history.push_back(newTransaction);
}
//-----------------------------------------------------------------------
// depositToAccount
// deposit an amount of money into a specific account
// update the transaction history if successfull
// @param index the specified account
// @amount the amount of money
// @return true if successfull, false if not
bool Client::depositToAccount(int index, int amount){
	bool complete = accounts[index].deposit(amount);
	if(complete){
		int ii = ID*10 + index;
		addHistory('D',ii,amount,0);
		return true;
	}else{
		return false;
	}
}
//-----------------------------------------------------------------------
// WithdrawFromAccount
// withdraw an amount of money into a specific account
// if the specified account is one of the special 4, do overdraft.
// update the transaction history if successfull
// @param index the specified account
// @amount the amount of money
// @return true if successfull, false if not
int Client::widthdrawlFromAccount(int index, int amount){
	if(amount < 0) return 0;
	bool complete = accounts[index].withdraw(amount);
	if(complete){
		int ii = ID*10 + index;
		addHistory('W',ii,amount,0);
		return amount;
	}else{
		// handle the overdraft if it is one of the 4 special accounts
		switch (index){
		case 0:
			if((accounts[0].getBalance() + accounts[1].getBalance()) < amount)
				break;
			accounts[1].withdraw(amount - accounts[0].getBalance());   //the amount left to be withdraw
			accounts[0].withdraw(accounts[0].getBalance());  //empty out the first account;
			addHistory('W',ID*10 + index,amount,0);
			return amount;
		case 1:
			if((accounts[0].getBalance() + accounts[1].getBalance()) < amount)
				break;
			accounts[0].withdraw(amount - accounts[1].getBalance());   //the amount left to be withdraw
			accounts[1].withdraw(accounts[1].getBalance());  //empty out the first account;
			addHistory('W',ID*10 + index,amount,0);
			return amount;
		case 2:
			if((accounts[2].getBalance() + accounts[3].getBalance()) < amount)
				break;
			accounts[3].withdraw(amount - accounts[2].getBalance());   //the amount left to be withdraw
			accounts[2].withdraw(accounts[2].getBalance());  //empty out the first account;
			addHistory('W',ID*10 + index,amount,0);
			return amount;
		case 3:
			if((accounts[2].getBalance() + accounts[3].getBalance()) < amount)
				break;
			accounts[2].withdraw(amount - accounts[3].getBalance());   //the amount left to be withdraw
			accounts[3].withdraw(accounts[3].getBalance());  //empty out the first account;
			addHistory('W',ID*10 + index,amount,0);
			return amount;
		}
		string acc;
		switch (index){
		case 0:
			acc = "Money Market Fund";
			break;
		case 1:
			acc = "Prime Money Market Fund";
			break;
		case 2:
			acc = "Long-Term Bond Fund";
			break;
		case 3:
			acc = "Short-Term Bond Fund";
			break;
		case 4:
			acc = "500 Index Fund";
			break;
		case 5:
			acc = "Capital Value Fund";
			break;
		case 6:
			acc = "Growth Equity Fund";
			break;
		case 7:
			acc = "Growth Index Fund";
			break;
		case 8:
			acc = "Value Fund";
			break;
		case 9:
			acc = "Value Stock Fund";
			break;
		}
		cout << "Withdrawal not performed on " << acc << " for client " << ID << endl;
		cout << "    insufficient funds" << endl;
		return 0;
	}
}
//-----------------------------------------------------------------------
// deleteMostRecent
// delete the most recent transaction
// this use to delete the withdraw transaction when the move transaction is processed
void Client::deleteMostRecent(){
	history.pop_back();
}
//-----------------------------------------------------------------------
// operator<
// overload the < operator
// this only compare the clients' IDs
// @param aClient the client comparing to
// @return true if less than, false otherwise
bool Client::operator<(const Client& aClient) const{
	if(ID < aClient.getID() )return true;
	return false;
}
//-----------------------------------------------------------------------
// operator>
// overload the > operator
// this only compare the clients' IDs
// @param aClient the client comparing to
// @return true if greater than, false otherwise
bool Client::operator>(const Client& aClient) const{
	if(ID > aClient.getID() )return true;
	return false;
}
//-----------------------------------------------------------------------
// operator==
// overload the == operator
// this only compare the clients' IDs
// @param aClient the client comparing to
// @return true if equals, false otherwise
bool Client::operator==(const Client& aClient) const{
	if(ID == aClient.getID() )return true;
	return false;
}