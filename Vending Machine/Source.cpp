/*This is a test program for a vending machine*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//User inserts gold
	int gold, choice;
	int cost[6] = { 0, 300, 500, 200, 150, 250 };
	string item[6] = { "blank", "Potion", "Ether", "Antidote", "Eye Drops", "Echo Drops" };
	char again = 'y';
	cout << "Please insert gold." << endl;
	cin >> gold;

	
	//Start vend loop
	do {
		//Vending list
		cout << "\nChoose an item" << endl;
		cout << "\nItem" << setw(25) << "Cost" << endl;
		cout << "====" << setw(25) << "====" << endl;
		cout << "1. Potion" << setw(24) << "300 gold" << endl;
		cout << "2. Ether" << setw(25) << "500 gold" << endl;
		cout << "3. Antidote" << setw(22) << "200 gold" << endl;
		cout << "4. Eye Drops" << setw(21) << "150 gold" << endl;
		cout << "5. Echo Drops" << setw(20) << "250 gold" << endl;
		cout << "6. Cancel" << endl;
		cin >> choice; //User's choice

		if (choice == 6) { //User selects cancel
			goto OUT;
		}
		else if (gold >= cost[choice]) //User chooses item
		{
			cout << "\nNow dispensing " << item[choice] << endl;
			cout << "You have " << gold - cost[choice] << " gold remaining." << endl;
			gold = gold - cost[choice];
		}
		else { cout << "\ninsufficient gold." << endl; } //Not enough gold

		
		cout << "Choose another item? (Y/N)" << endl; //User selects to continue
		cin >> again;
	} while (again == 'Y' || again == 'y');

	OUT:cout << "Thank you! " << gold << " gold will be returned." << endl;

	//Test
	return 0;
}