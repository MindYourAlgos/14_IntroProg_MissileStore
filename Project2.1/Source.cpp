/*************************
Nicholas Heredia, 9-29-14
Project2: Store
M. Canniff, Cuban Rocket Supplies
**************************/

#include <iostream>
#include <string>
using namespace std;

int main(){
	//come up with variables
	//string name, address, city;

	char choice;
	int catalogueItem, numberOfItems, day, dayArriving;
	int fuselages = 0, fuel = 0, payload = 0, launchPads = 0, switches = 0;
	double sum = 0;

	/*Figure out why the program keeps jumping to the next line before
	input can be set: done*/
	cout << "Welcome to Cuban Rocket Supplies!\n";
	cout << "Generously supplied by the same providers \n";
	cout << "who brought you the Frigid War.\n";
	//cout << "Please create an account before proceeding: \n" << endl;
	string name;
	cout << "First and last name: ";
	getline(cin, name);// allow for a 256 char name

	string address;
	cout << endl << "Address: ";
	cin.clear();
	getline(cin, address);

	string city;
	cout << endl << "City: ";
	cin >> city;
	cout << endl;

	cout << "Welcome " << name << " to Cuban Rocket Supplies.\n";
	cout << "Please take a look at our products: \n";
	do {
		cout << "(1) Rocket bodies                      $ 1500.00\n";
		cout << "(2) Fuel Cannisters                    $  740.00\n";
		cout << "(3) Slightly Radioactive Payload       $  900.00\n";
		cout << "(4) Launch pads                        $30000.00\n";
		cout << "(5) Launch switches                    $  100.00\n";
		cout << "Please select an item: ";
		cin >> catalogueItem;

		while (catalogueItem > 5 || catalogueItem < 1) {
			cout << "Please enter a vaild number for the\n";
			cout << "item(s) you want.\n";
			cin >> catalogueItem;
		}

		switch (catalogueItem)
		{
		case 1:
			cout << "How much of this item do you want? ";
			cin >> numberOfItems;
			fuselages += numberOfItems;
			sum = (numberOfItems * 1500) + sum;
			cout << "Your total so far is $" << sum << endl;
			break;
		case 2:
			cout << "How much of this item do you want? ";
			cin >> numberOfItems;
			fuel += numberOfItems;
			sum = (numberOfItems * 740) + sum;
			cout << "Your total so far is $" << sum << endl;
			break;
		case 3:
			cout << "How much of this item do you want? ";
			cin >> numberOfItems;
			payload += numberOfItems;
			sum = (numberOfItems * 900) + sum;
			cout << "Your total so far is $" << sum << endl;
			break;
		case 4:
			cout << "How much of this item do you want? ";
			cin >> numberOfItems;
			launchPads += numberOfItems;
			sum = (numberOfItems * 30000) + sum;
			cout << "Your total so far is $" << sum << endl;
			break;
		case 5:
			cout << "How much of this item do you want? ";
			cin >> numberOfItems;
			switches += numberOfItems;
			sum = (numberOfItems * 100) + sum;
			cout << "Your total so far is $" << sum << endl;
			break;
		}
		cout << "Would you like to continue purchase (P) or move on to checkout (C) ?\n";
			cin >> choice;
			if ((choice == 'C' || choice == 'c') && (sum == 0))
				cout << "You haven't bought anything! Please browse our store!";
		//} while (choice != 'C' || choice != 'c' || choice != 'P' || choice != 'p');

	} while ((choice == 'C' || choice == 'c') && (sum == 0) || (choice == 'P' || choice == 'p'));

	//add new variables here
	double shipping, totalAfterShipping = 0, finalTotal;

	cout << "Please type in today's day\n";
	cout << "and please select a shipping option, comrade!\n";
	cout << "(1) Standard shipping           free\n";
	cout << "(2) Two day shipping           $9.99\n";
	cout << "(3) Overnight shipping        $19.99\n";
	cout << "Shipping choice: ";
	cin >> shipping;
	cout << "Today\'s day: ";
	cin >> day;

	if (shipping == 1) {
		totalAfterShipping = sum;

		if (day > 26)
		dayArriving = (day + 5) + 30;
		else dayArriving = day + 5;
		cout << "$" << totalAfterShipping << endl;
		
	}
	else if (shipping == 2) {
		totalAfterShipping = sum + 9.99;

		if (day > 29)
		dayArriving = (day + 2) - 30;
		else dayArriving = day + 2;
		cout << "$" << totalAfterShipping << endl;
	}
	else if (shipping == 3) {
		totalAfterShipping = sum + 19.99;

		if (day == 30)
		dayArriving = 1;
		else dayArriving = day + 1;
		cout << "$" << totalAfterShipping << endl;
	}
	else if (shipping < 4 || shipping > 0) {
		totalAfterShipping = sum;
		cout << totalAfterShipping;
	}
	cout << "$" << totalAfterShipping << endl;
	finalTotal = totalAfterShipping + totalAfterShipping*0.0875;
	cout << "The total cost is $" << finalTotal << ".\n";
		cout << "Here are your items you purchased:\n";

		string shoppingCartItems = "";
		if (fuselages > 0)
			cout << "(" << fuselages << ") rocket bodies                       $" << fuselages * 1500 << endl;
		if (fuel > 0)
			cout << "(" << fuel << ") fuel cannisters                 $" << fuel * 740 << endl;
		if (payload > 0)
			cout << "(" << payload << ") slightly radioactive payloads      $" << payload * 900 << endl;
		if (launchPads > 0)
			cout << "(" << launchPads << ") launch pads                           $" << launchPads * 30000 << endl;
		if (switches > 0)
			cout << "(" << switches << ") launches switches                $" << switches * 100 << endl;

		cout << "Total:                                    $" << sum << endl;
		cout << "Total after shipping:                     $" << totalAfterShipping << endl;
		cout << "Overall total charged to your account:    $" << finalTotal << endl;
		cout << "Thank you " << name << ".\n\n";
		cout << "Your order will be shipped to " << address << " \n";
		cout << "on the " << dayArriving << "th.\n\n";
		cout << "Thank you for shopping with us. You have helped your worker\'s party greatly!\n";
	system("pause");
}