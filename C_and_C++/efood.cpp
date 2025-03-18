//Na ginei programma sto opoio o xrhsths mporei na paraggeilei
//apo to menu enos delivery food ta parakatw proionta:
//1. pizza-->atomikh 5€, oikogeneiakh 12€, gigas 20€
//2. salata-->atomikh 4€, oikogeneiakh 6.5€, gigas 10€
//3. poto-->anapsuktiko 3€, mpura 4€, krasi 12€.
//Na epilegei o xrhsths  apo ta menu proion,
//na epilegei posothta kai
//na upologizetai to sunoliko kostos ths paraggelias.

#include <iostream>
using namespace std;

int main(){
	int choice1,choice2;
	double pieces,price;
	
	cout<<"What would you like to order?"<<endl;
	cout<<"---------------------"<<endl;
	cout<<"1) Pizza."<<endl;
	cout<<"2) Salad."<<endl;
	cout<<"3) Drink."<<endl;
	cout<<"---------------------"<<endl;
	cin>>choice1;
	
	switch (choice1){
		case 1:
			cout<<"You chose pizza! What size would you like?"<<endl;
			cout<<"---------------------"<<endl;
			cout<<"1) Small (5€)."<<endl;
			cout<<"2) Medium (12€)."<<endl;
			cout<<"3) Large (20€)."<<endl;
			cout<<"---------------------"<<endl;
			cin>>choice2;
			
			switch (choice2){
				case 1:
					cout<<"You chose the small size. How many would you like?"<<endl;
					cin>>pieces;
					price=pieces*5;
					cout<<"The price is : "<<price;
					break;
				case 2:
					cout<<"You chose the medium size. How many would you like?"<<endl;
					cin>>pieces;
					price=pieces*12;
					cout<<"The price is : "<<price;
					break;
				case 3:
					cout<<"You chose the large size. How many would you like?"<<endl;
					cin>>pieces;
					price=pieces*20;
					cout<<"The price is : "<<price;
					break;
				break;
				default:
					cout<<"Wrong choice."<<endl;
			}
			break;
			
		case 2:
			cout<<"You chose salad! What size would you like?"<<endl;
			cout<<"---------------------"<<endl;
			cout<<"1) Small (4€)."<<endl;
			cout<<"2) Medium (6.5€)."<<endl;
			cout<<"3) Large (10€)."<<endl;
			cout<<"---------------------"<<endl;
			cin>>choice2;
			
			switch (choice2){
				case 1:
					cout<<"You chose the small size. How many would you like?"<<endl;
					cin>>pieces;
					price=pieces*4;
					cout<<"The price is : "<<price;
					break;
				case 2:
					cout<<"You chose the medium size. How many would you like?"<<endl;
					cin>>pieces;
					price=pieces*6.5;
					cout<<"The price is : "<<price;
					break;
				case 3:
					cout<<"You chose the large size. How many would you like?"<<endl;
					cin>>pieces;
					price=pieces*12;
					cout<<"The price is : "<<price;
					break;
				break;
				default:
					cout<<"Wrong choice."<<endl;
			}
			break;
		case 3:
			cout<<"You chose drink! What would you like?"<<endl;
			cout<<"---------------------"<<endl;
			cout<<"1) Soft drink (3€)."<<endl;
			cout<<"2) Beer (4€)."<<endl;
			cout<<"3) Wine 750ml (12€)."<<endl;
			cout<<"---------------------"<<endl;
			cin>>choice2;
			
			switch (choice2){
				case 1:
					cout<<"You chose soft drink. How many would you like?"<<endl;
					cin>>pieces;
					price=pieces*3;
					cout<<"The price is : "<<price;
					break;
				case 2:
					cout<<"You chose beer. How many would you like?"<<endl;
					cin>>pieces;
					price=pieces*4;
					cout<<"The price is : "<<price;
					break;
				case 3:
					cout<<"You chose wine 750ml. How many would you like?"<<endl;
					cin>>pieces;
					price=pieces*12;
					cout<<"The price is : "<<price;
					break;
				break;
				default:
					cout<<"Wrong choice."<<endl;
			}
	}
}
