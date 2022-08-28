#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;
int main ()
{
		//header
	cout<<"+-----------------------------------------------------------+"<<endl;
	cout<<"|               Computer Science and Engineering            |"<<endl;
	cout<<"|                CSCE 1030 - Computer Science I             |"<<endl;
	cout<<"|          TranAnhThu Nguyen tn0273 tn0273@my.unt.edu       |"<<endl;
	cout<<"+-----------------------------------------------------------+"<<endl;
		// end of header

	const int ACCOUNT_LENGTH=6;
	enum Type {Commercial=1, Residential=2}; 
	int i; //for loop
	int num_prop;
	string acc_name; //account name, only alphabets or spaces
	string acc_num; //account number, length exactly equals 6, only alphanumeric

	// input account name 
	cout<<"Enter your name: "; getline(cin,acc_name);
	char name;
	bool validName=true;


	//check account name validity
	for (i=0; i<acc_name.size(); ++i) {
		name=acc_name.at(i);
		do {
			if ((isalpha(name)) || (isspace(name))) {
			validName=false;
			break;
		}
		else {
		cout<<"Your name can only have alphabets or spaces. Please enter again."<<endl;
		cout<<"Enter new name: "; getline(cin,acc_name);
		}
		} 
		while (validName);
	}

	// end account name validity checking

	//input account number
	cout<<"Enter account number: ";cin>>acc_num;

	bool validNum=true;
	char num;


	//checking account number validity
	for (i=0; i<acc_num.size(); ++i) {
		num=acc_num.at(i);

		// to check alphanumeric & length
		do {
		    if ((isalnum(num)) && (acc_num.size()==ACCOUNT_LENGTH)) {
			validNum=false;
			}
			
			else if (!isalnum(num) || (acc_num.size()!=ACCOUNT_LENGTH)) {
					cout<<"Your account number can only have alphabets or digits and must contain 6 characters. Please try again."<<endl;
					validName=true;
					cout<<"Enter new number: "; cin>>acc_num;
			}
			
		} 
		while (validNum);

	}
		
	// end account number output


	// taxes operating start

		int type_prop=0;
		int val_prop;
		double tax;
		double tax_ex; //for tax exempt
		srand(time(NULL));
		double number = (rand()% 1001 + 1000); //for random single property tax exemption
		bool flag = false; // to generate right choice


	cout<<"How many properties you want to process? "; cin>>num_prop;
		do {
			if(num_prop<0) {
			cout<<"Value cannot be negative. Please enter again."<<endl;
			cout<<"How many properties you want to process? ";cin>>num_prop;
		}
	}
		while (num_prop<0);

	int x; // for loop of number of properties
	double totalTax;

	
	for (x=1;x<=num_prop;++x) {
		
		cout<<"Processing Property #"<<x<<endl;
		cout<<"1. Commercial"<<endl;
		cout<<"2. Residential"<<endl;

		do {
		cout<<"What property you want to choose? "; cin>>type_prop;
		Type my_type=static_cast<Type>(type_prop); //cast to type_prop

			switch(my_type) {
			
			case Commercial: 
				cout<<"Enter property value: "; cin>>val_prop;
				if (val_prop<pow(10,6)) {
					tax=val_prop*3.5/100;
				}
				if (val_prop>=pow(10,6)) {
					tax=(((val_prop)-pow(10,6))*5/100) + (val_prop*3.5/100);
				}
				cout<<"Tax owed for property #"<<x<<": $";
				cout<<fixed<<setprecision(2)<<tax<<endl;
				flag=false; // to exit the loop

			break;

			case Residential: 

				cout<<"Enter property value: "; cin>>val_prop;
				if (val_prop<pow(10,5)) {
					tax=0;
					cout<<"No tax."<<endl;
					
				}
				if (val_prop>=pow(10,5)) {
					tax=((val_prop)-pow(10,5))*3.5/100;
				}
				// condition for single property tax exemption
				if ((num_prop==1) && (type_prop==2)) {
					if(tax<number) {
						tax_ex=0;
					}
					else if (tax>=number) {
						tax_ex=tax-number;
					}
				
				cout<<"Single property tax exemption: $"<<fixed<<setprecision(2)<<number<<endl;
				tax=tax_ex; //compute value of reduced tax
				}
			
				cout<<"Tax owed for property #"<<x<<": $";
				cout<<fixed<<setprecision(2)<<tax<<endl; 
				flag=false; //to exit the loop

			break;
		
			default: 
				cout<<"Not a valid value. Please choose again."<<endl;
				flag=true;

			}
		}
		while (flag);
			totalTax += tax; //sum of taxes, has to be inside for-loop to generate
		}

	// end of tax operating


	// output all the results
		// uppercase each initial of the name
		for (i=0;i<acc_name.size();++i) {
		if (i==0) {
			acc_name.at(i)=toupper(acc_name.at(i));
		}
		else if (acc_name.at(i-1) == ' ') {
			acc_name.at(i)=toupper(acc_name.at(i));

		}
		}
	cout<<"Name: "<<acc_name<<endl;
	cout<<"Account Number: "<<acc_num<<endl;;
	cout<<"Your total taxes are: $"<<totalTax<<endl;
		

	return 0;
}