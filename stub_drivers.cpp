#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

const int ROW = 3,  COL = 3;
string userName;
void displayMenu();
void displayFoodMenu();
void displayDrinkMenu();
void displayGiftCard();
void displayMenueOrder(const string[][COL], const double[][COL], int);
void ClearScreen();
int inputValidate(int);
int inputQuantityValidate(int);
void displayReceipt();
void createRecipt(const string[][COL], const double[][COL], const int[][COL]);
void timeStamp();
void saveDataInFile();
void identifyUser();
int DriverFunctionTestResetVaule(int );

////////////////////////////////////////////
///////////////ARRAY FOR ITEM///////////////
//////////////ARRAY FOR PRICE///////////////
/////////////For          MENU//////////////
///////////////////////////////////////////
////////Use 2-D to truck number of user oder
////////numberOfOrder[1][] is for Food
///////numberOfOrder[2][] is Drink
///////numberOfOrder[3][] is gift card
///////Base on 3 x 3
string itemName[ROW][COL]={{ "Bacon Sandwich","OMG-3 Bistro Box","Turkey Burger" },
                            { "Americano Caffe", "Carmel Macchiato", "Espresso Con Panna" },
                            { "5 dollar gift card", "10 dollar gift card","15 dollar gift card" }
                            };
 double itemPrice[ROW][COL]={{ 4.5, 5.5, 4.5 },
                            { 3.5, 4.5, 5.0 },
                            { 5.0, 10.0, 15.0 }
                            }     ;
int numberOfOrder[ROW][COL];
double commulateTotal = 0;
static int itemCounter = 0;
////////////////////////////////////
////////  TAX = 8.5%  ////////////
//////////////////////////////////
const double TAX = 0.085;
void identifyUser()
{
  cout << "Please Enter User Name:";
  cin >> userName;
}

int main()
{
  identifyUser();
	//variable that User enter
	//test driver, testing menu options
    int testDriver = 1;
    //test data

	double Total = 0.0;
	//test driver, testing menu options
	int numberWantedDriver = 1;
	/////////////////////////////////////////////////
	////////////Program start Here//////////////////
	////////////////////////////////////////////////
	cout << fixed << setprecision(2) << showpoint;
	do
	{

		//////////////////Main menu//////////////////
		displayMenu();



		while (testDriver < 0 || testDriver > 4)
		{
		    cout << testDriver;
			cout << "Sorry choice, please enter option 1~4: ";
			testDriver++;
			if (testDriver >  4)
		{
			displayReceipt();
			return 0;
		}
		}

		if (testDriver == 4)
		{
			displayReceipt();
			return 0;
		}
		/////////////////////////////////////////
		//////////Go into Menu 1, 2, or 3///////
		else
		{
			switch (testDriver)
			{
				/////////////////////Process In the food menu///////////////
			case 1:

					displayFoodMenu();


					switch (testDriver)
					{
					case 1:
						cout << "How many you want: ";

						numberWantedDriver = inputQuantityValidate(numberWantedDriver);
						numberOfOrder[0][0] += numberWantedDriver;
						commulateTotal += numberWantedDriver * itemPrice[0][0];
						break;
					case 2:
						cout << "How many you want: ";

						numberWantedDriver = inputQuantityValidate(numberWantedDriver);
						numberOfOrder[0][1] += numberWantedDriver;
						commulateTotal += numberWantedDriver * itemPrice[0][1];
						break;
					case 3:
						cout << "How many you want: ";

						numberWantedDriver = inputQuantityValidate(numberWantedDriver);
						numberOfOrder[0][2] += numberWantedDriver;
						commulateTotal += numberWantedDriver * itemPrice[0][3];
						break;
					case 4:
					    testDriver = DriverFunctionTestResetVaule(testDriver);
						break;
					case 5:
						displayReceipt();
						return 0;
					}
					testDriver++;//contuniens driver test


				break;
				/////////////////////Process In the Drink menu///////////////
			case 2:
				do
				{

					displayDrinkMenu();


					switch (testDriver)
					{
					case 1:
						cout << "How many you want: ";

						numberWantedDriver = inputQuantityValidate(numberWantedDriver);
						numberOfOrder[1][0] += numberWantedDriver;
						commulateTotal += numberWantedDriver * itemPrice[1][0];
						break;
					case 2:
						cout << "How many you want: ";

						numberWantedDriver = inputQuantityValidate(numberWantedDriver);
						numberOfOrder[1][1] += numberWantedDriver;
						commulateTotal += numberWantedDriver * itemPrice[1][1];
						break;
					case 3:
						cout << "How many you want: ";

						numberWantedDriver = inputQuantityValidate(numberWantedDriver);
						numberOfOrder[1][2] += numberWantedDriver;
						commulateTotal += numberWantedDriver * itemPrice[1][2];
						break;
					case 4:
					    testDriver = DriverFunctionTestResetVaule(testDriver);
						break;
					case 5:
						displayReceipt();
						return 0;
					}
					testDriver++;
				} while (testDriver < 4);

				break;
				/////////////////////Process In the GiftCard menu///////////////
			case 3:
				do
				{
					displayGiftCard();


					switch (testDriver)
					{
					case 1:
						cout << "How many you want: ";

						numberWantedDriver = inputQuantityValidate(numberWantedDriver);
						numberOfOrder[2][0] += numberWantedDriver;
						commulateTotal += numberWantedDriver * itemPrice[2][0];

						break;
					case 2:
						cout << "How many you want: ";

						numberWantedDriver = inputQuantityValidate(numberWantedDriver);
						numberOfOrder[2][1] += numberWantedDriver;
						commulateTotal += numberWantedDriver * itemPrice[2][1];

						break;
					case 3:
						cout << "How many you want: ";

						numberWantedDriver = inputQuantityValidate(numberWantedDriver);
						numberOfOrder[2][2] += numberWantedDriver;
						commulateTotal += numberWantedDriver * itemPrice[2][2];
						break;
					case 4:
					    testDriver = DriverFunctionTestResetVaule(testDriver);
						break;
					case 5:
						displayReceipt();
						return 0;
					}
					testDriver++;//contuniens driver test
				} while (testDriver < 4);

				break;
			default:
				displayReceipt();


			}
		}
    testDriver++;
	} while (testDriver != 0);

	return 0;
}


//////////////////////////////////////////////////////////////
/////////////////////Display Menu Function///////////////////
////////////////////////////////////////////////////////////

int DriverFunctionTestResetVaule(int value)
{
     value = 0;
    return value;

}

void displayMenu()
{
	ClearScreen();
	cout << "/////////////////////////////////////////////////////////////" << endl;
	cout << "/" << "                 Odin-----Menu                       /" << endl;
	cout << "/////////////////////////////////////////////////////////////" << endl;
	cout << "Select from Menu using the number associated with that item." << endl;
	cout << "1.Food" << endl;
	cout << "2 Drink" << endl;
	cout << "3.Gift Card" << endl;
	cout << "4.Done Ordering" << endl;
	cout << "0. Exit" << endl;
	cout << "choice:";
}
void displayFoodMenu()
{
	ClearScreen();
	cout << "/////////////////////////////////////////////////////////////" << endl;
	cout << "/                  Odin-----Food                            /" << endl;
	cout << "/////////////////////////////////////////////////////////////" << endl;
	displayMenueOrder(itemName, itemPrice, 0);
}
void displayDrinkMenu()
{
	ClearScreen();
	cout << "/////////////////////////////////////////////////////////////" << endl;
	cout << "/                  Odin-----Drink                           /" << endl;
	cout << "/////////////////////////////////////////////////////////////" << endl;
	displayMenueOrder(itemName, itemPrice, 1);
}
void displayGiftCard()
{
	ClearScreen();
	cout << "/////////////////////////////////////////////////////////////" << endl;
	cout << "/                Odin-----Gift Card                         /" << endl;
	cout << "/////////////////////////////////////////////////////////////" << endl;
	displayMenueOrder(itemName, itemPrice, 2);
}


//////////////////Function that pass item name and and price to display item information
void displayMenueOrder(const string item[][COL], const double price[][COL], int row)
{

	cout << setw(20) << left << "ITEM" << "\t\t\t\t\t\tPRICE" << endl;
	for (int i = 0; i<3; i++)
	{
		cout << (i + 1) << "." << setw(21) << left << item[row][i] << "\t\t\t\t\t\t$" << price[row][i] << endl;
	}
	cout << "4.Back to menu" << endl;
	cout << "5.End order" << endl;
	cout << "choice:";
}
//////////////////Function that check input form 1~5:
int inputValidate(int input)
{
	while (input <1 || input >5)
	{
	    cout << "Stub" <<input;//stub
		cout << "Sorry, not that option. Please enter 1~5: ";
		cin >> input;

	}
	cout << input;//stub

	return input;
}
//////////////////Function that check input quantity, should greater than0
int inputQuantityValidate(int qt)
{
	while (qt <= 0)
	{
		cout << "Sorry, quantity cannot be negative, please reenter: ";
		cin >> qt;
	}
	return qt;
}

//////////////////Function that creates Receipt
void createRecipt(const string menu[][COL], const double price[][COL], const int quanty[][COL])
{
	//create vector to hold data

	//if the qunty is equal to zero then dont cout

	for (int row=0; row<ROW; row++)
    {
        for(int col=0; col<COL; col++)
        {
            if (quanty[row][col] != 0)
		{
			itemCounter += 1;
			cout << (itemCounter) << "." << setw(21) << left << menu[row][col] << "                 " << quanty[row][col] << "\t\t\t$" << price[row][col] * quanty[row][col] << endl;

		}
        }
    }
}
/////////////////Function that display Receipt
/////////////////Save File in this function.
/////////////////			Because After this function, program end
void displayReceipt()
{
	ClearScreen();
	cout << userName<< "\t\t";
	timeStamp();
	cout << setw(20) << left << "ITEM" << "                 " << "QTY" << "\t\t\tPRICE" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	createRecipt(itemName, itemPrice, numberOfOrder );
	cout << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "                                                   "<< setw(15) << right << "Sub-total: $" << commulateTotal << endl;
	cout << "                                                          "<< setw(15) << right <<" TAX:8.5%" << endl;
	cout << "                                                   "<< setw(15) << right << " + $" << commulateTotal * TAX << endl;
	cout << "You total is $" << commulateTotal * (1 + TAX) << endl;
	cout << "Thank your for your business!" << endl;
	saveDataInFile();
}

//////////////////Function clear the screen when user make choice
void ClearScreen()
{
	system("cls");

}
/////////////////Function display date
void timeStamp()
{
	// current date/time based on current system
	time_t now = time(0);

	// convert now to string form
	char* dt = ctime(&now);

	cout << dt << endl;
}
/////////////////Function Save data in file
////Write item name and it quantity sold and daily earn
////ROW present FOOD, DRINK, AND GIFT-CARD
////COL present different item in FOOD, DRINK, AND GIFT-CARD
void saveDataInFile()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	ofstream outputFile;
	outputFile.open("Data.txt");
	outputFile << userName << "\t\t";
	outputFile << dt << endl;
	outputFile << "ITEM"<< setw(30)<<" \t\t\tquantity" << endl;
	outputFile << "------------------------------------------------------" << endl;
	for (int row = 0; row<ROW; row++)
	{
		for (int col = 0; col<COL; col++)
		{
			if (numberOfOrder[row][col] != 0)
					outputFile << setw(30) << left << itemName[row][col] << "\t\t\t" << numberOfOrder[row][col] << endl;

		}
	}
	outputFile << "------------------------------------------------------" << endl;
	outputFile << "                                   "<< setw(15) << right << "Sub-total: $" << commulateTotal << endl;
	outputFile << "                                      "<< setw(15) << right <<" TAX:8.5%" << endl;
	outputFile << fixed <<setprecision(2) <<   "                                  "<< setw(15) << right << " + $" << commulateTotal * TAX << endl;
	outputFile << fixed <<setprecision(2) << "Today's total sell is $ " << commulateTotal * (1 + TAX)  << endl;
	outputFile.open("Data.txt");

	outputFile.close();
}


