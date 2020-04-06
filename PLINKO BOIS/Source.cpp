/* PLINKO LAB
Nathan Tietjen and Trevor Schmidt
nathan.c.tietjen@gmail.com and trevorjschmidt97@gmail.com
CS 142 Section 06
9-27-2018*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {

	// Variables
	int userSelection = 0;
	int userSlot = 0;
	const int RANDOM_SEED = 42;
	srand(RANDOM_SEED);
	double chipPosition = 0.0;
	int random = 0;
	int numChips = 0;
	double totalWinnings = 0.0;
	double averageWinnings = 0.0;

	// Intro
	cout << "Welcome to the Plinko simulator! Enter 3 to see options." << endl << endl;
	cout << "Enter your selection now: " << endl;
	cin >> userSelection;

	// Sets up entire program loop
	while (userSelection != 4) {
		totalWinnings = 0.0;

		//Single Chip
		if (userSelection == 1) {
			cout << "*** Drop a single chip ***" << endl << endl;
			//Slot position
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> userSlot;
			cout << endl;
			//Valid slot position
			if (userSlot >= 0 && userSlot <= 8) {
				cout << "*** Dropping chip into slot " << userSlot << " ***" << endl;
				chipPosition = userSlot;
				cout << "Path: [";
				for (int i = 0; i < 12; ++i) {
					cout << fixed << setprecision(1) << chipPosition;
					cout << ", ";
					if (chipPosition == 0.0) {
						chipPosition = chipPosition + 0.5;
					}
					else if (chipPosition == 8.0) {
						chipPosition = chipPosition - 0.5;
					}
					else {
						random = rand() % 2;
						if (random == 0) {
							chipPosition = chipPosition - 0.5;
						}
						else {
							chipPosition = chipPosition + 0.5;
						}
					}
				}
				//Finding Winnings Single
				cout << fixed << setprecision(1) << chipPosition << "]" << endl;
				switch (static_cast<int>(chipPosition)) {
				case 0:
					totalWinnings = totalWinnings + 100.00;
					break;
				case 1:
					totalWinnings = totalWinnings + 500.00;
					break;
				case 2:
					totalWinnings = totalWinnings + 1000.00;
					break;
				case 3:
					totalWinnings = totalWinnings + 0.00;
					break;
				case 4:
					totalWinnings = totalWinnings + 10000.00;
					break;
				case 5:
					totalWinnings = totalWinnings + 0.00;
					break;
				case 6:
					totalWinnings = totalWinnings + 1000.00;
					break;
				case 7:
					totalWinnings = totalWinnings + 500.00;
					break;
				case 8:
					totalWinnings = totalWinnings + 100.00;
					break;
				}
				cout << "Winnings: $" << fixed << setprecision(2) << totalWinnings << endl;;
			}
			//Invalid slot position single
			else {
				cout << "Invalid slot." << endl;
			}
		}

		// Multiple Chips	
		else if (userSelection == 2) {
			cout << "*** Drop multiple chips ***" << endl << endl;
			cout << "How many chips do you want to drop (>0)? ";
			cin >> numChips;
			cout << endl << endl;
			// Valid number of chips for multiple
			if (numChips > 0) {
				cout << "Which slot do you want to drop the chip in (0-8)? " << endl;
				cin >> userSlot;
				// If valid slot position for multiple
				if (userSlot >= 0 && userSlot <= 8) {
					for (int j = 0; j < numChips; ++j) {
						chipPosition = userSlot;
						for (int i = 0; i < 12; ++i) {
							if (chipPosition == 0.0) {
								chipPosition = chipPosition + 0.5;
							}
							else if (chipPosition == 8.0) {
								chipPosition = chipPosition - 0.5;
							}
							else {
								random = rand() % 2;
								if (random == 0) {
									chipPosition = chipPosition - 0.5;
								}
								else {
									chipPosition = chipPosition + 0.5;
								}
							}
						}
						// Finding Winnings Multiple
						switch (static_cast<int>(chipPosition)) {
						case 0:
							totalWinnings = totalWinnings + 100.00;
							break;
						case 1:
							totalWinnings = totalWinnings + 500.00;
							break;
						case 2:
							totalWinnings = totalWinnings + 1000.00;
							break;
						case 3:
							totalWinnings = totalWinnings + 0.00;
							break;
						case 4:
							totalWinnings = totalWinnings + 10000.00;
							break;
						case 5:
							totalWinnings = totalWinnings + 0.00;
							break;
						case 6:
							totalWinnings = totalWinnings + 1000.00;
							break;
						case 7:
							totalWinnings = totalWinnings + 500.00;
							break;
						case 8:
							totalWinnings = totalWinnings + 100.00;
							break;
						}
					}
					averageWinnings = static_cast<int>(((totalWinnings / numChips) + .005) * 100) / 100.00;
					cout << "Total winnings on " << numChips << " chips: $" << fixed << setprecision(2) << totalWinnings << endl;
					cout << "Average winnings per chip: $" << averageWinnings << endl;
				}
				// For invalid slot multiple
				else {
					cout << "Invalid slot." << endl;
				}
			}
			// For invalid number of chips multiple
			else {
				cout << "Invalid number of chips." << endl;
			}
		}

		// Option Menu	
		else if (userSelection == 3) {
			cout << "Menu: Please select one of the following options:" << endl << endl;
			cout << "1 - Drop a single chip into one slot" << endl;
			cout << "2 - Drop multiple chips into one slot" << endl;
			cout << "3 - Show the options menu" << endl;
			cout << "4 - Quit the program" << endl;
		}
		else if (userSelection <= 0 || userSelection >= 5) {
			cout << "Invalid selection. Enter 3 to see options." << endl;
		}
		cout << "Enter your selection now: " << endl;
		cin >> userSelection;
	}

	// End Game
	cout << "Goodbye!" << endl;

	return 0;
}