// CppClassProject3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//Eduardo Antonio Fernandez Diaz

void ShowInventory(int *p, bool ShowTotal = false);
void AddProduct(int *p, int warehouse, int product, int quantity);
bool CheckForWrongValues(int *p, int warehouse, int product, int quantity);

int main()
{
	int inventory[4][5], *ptr, sentinel;

	for (int i = 0; i<4; ++i) {
		for (int j = 0; j<5; ++j) {
			//inventory[i][j] = (i * 5) + j + 1;//For testing/debuggin purposes
            inventory[i][j]=0;
		}
	}

	ptr = inventory[0];//point ptr to the first int of inventory

	do {
		ShowInventory(ptr);//Display the Inventory every time is updated
		int warehouse, product, quantity;//vars that store the input of the program
		
		cout << "Type the warehouse, product and quantity as space separated integers\n"
			<< "To add 25 units of the fifth product to the fourth warehouse type: 4 5 25" << endl
			<< "To subtract, just add the minus sign before, following the example: 4 5 -25" << endl;
		cin >> warehouse >> product >> quantity;
		
		if (CheckForWrongValues(ptr, warehouse - 1, product - 1, quantity)) {
			AddProduct(ptr, warehouse - 1, product - 1, quantity);
			ShowInventory(ptr);
		}
		
		cout << "Enter -1 to finish, anything else to continue" << endl;
		cin >> sentinel;
		system("CLS");//Comment to see the inventory in time
	} while (sentinel != -1);
	ShowInventory(ptr, true);//Finally we show the totals passing a second bool parameter to the function
	return 0;
}

void ShowInventory(int *p, bool showTotals) {
	//This function displays the actual inventory
	//Shows the totals only when second parameter
	//is true (by default false)
	cout << "\t      Product" << endl;
	cout << setw(2) << "Warehouse  1  2  3  4  5";
	if (showTotals == true)
		cout << "   Total"; cout << endl;
	cout << setw(2) << "---------  -------------" << endl;
	int pTotal[5] = { 0 };//will store the total of each product
	//We use a double for loop to iterate through the array
	for (int i = 0; i<4; ++i) {
		cout << setw(5) << i + 1 << "\t  ";
		int wTotal = 0;//will store the total of products for each warehouse
		for (int j = 0; j<5; ++j) {
			cout << setw(2) << *(p + i * 5 + j) << ' ';
			wTotal += *(p + i * 5 + j);
			pTotal[j] += *(p + i * 5 + j);
		}
		if (showTotals == true)
			cout << "   " << wTotal;
		cout << endl;
	}
	if (showTotals == true) {
		cout << endl << "  Total   ";
		for (int j = 0; j<5; ++j) {
			cout << setw(2) << pTotal[j] << ' ';
		}
	}
	cout << endl;
}

void AddProduct(int *p, int warehouse, int product, int quantity) {
	//This function add or ship product according to the sign of the var quantity
	*(p + warehouse * 5 + product) += quantity;
}

bool CheckForWrongValues(int *p, int warehouse, int product, int quantity) {
	//THis function handles all the errors, return true only if no error is committed
	//displays an error message as a feedback to the user according to the error commited 
	int check = 999; //just a random value for the sentinel var
	if (warehouse<0 || warehouse > 3)//Check for the range of our warehouses
		check = 1;
	if (product<0 || product > 4)//Check for the range of our products
		check = 2;
	if ((warehouse >= 0 && warehouse <= 3)
		&& ((product >= 0 && product <= 4))
		&& (*(p + warehouse * 5 + product) + quantity) < 0
		)//Finally check for an attempt to make some product negative
		check = 3;

	switch (check) {//This switch display an error for every exception
	case 1: cout << "The value " << warehouse + 1 << " is out of range for a warehouse, try a value between 1 and 4" << endl; return false;
	case 2: cout << "The value " << product + 1 << " is out of range for a product, try a value between 1 and 5" << endl; return false;
	case 3: cout << "Cannot ship " << -quantity << " units of this product, only " << *(p + warehouse * 5 + product) 
		         << " units are stored there" << endl
		         << "!Product number " << product + 1 
		         << " from warehouse number " << warehouse + 1 
		         << " is set to zero now" << endl;
		         *(p + warehouse * 5 + product) = 0;//Set the product to zero
				 return false;
	default: return true;
	}
}