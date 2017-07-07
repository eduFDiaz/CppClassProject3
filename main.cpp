#include <ctime> 
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//Eduardo Antonio Fernandez Diaz

void ShowInventory(int *p);
void AddProduct(int *p, int warehouse, int product, int quantity);
bool CheckForWrongValues(int *p, int warehouse, int product, int quantity);
void ShowStats(int *p);

int main()
{
    int inventory[4][5];
    
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            inventory[i][j]=(i*5)+j+1;
            //inventory[i][j]=0;
            //cout << inventory[i][j] << ' ';
        }
        cout << endl;
    }
    int *ptr;
    ptr = inventory[0];
    
    int sentinel;
    do{
        ShowInventory(ptr);
        int warehouse, product, quantity;
        cout << "Type the warehouse, product and quantity as space separated integers\n"
             << "To add 25 units of the fifth product to the fourth warehouse type: 4 5 25" << endl;
        cin >> warehouse >> product >> quantity;
        if (CheckForWrongValues(ptr,warehouse-1,product-1,quantity)){
            AddProduct(ptr,warehouse-1,product-1,quantity);
            ShowInventory(ptr);
        }
        cout<<"Enter 1 to update your inventory or -1 to finish" << endl;
        cin >> sentinel;
        system("clear");
    }while(sentinel!=-1);
	
	
	/*//Finally we print the visits as a bar chart
	cout << endl<< "Floor" << setw(2) << " Number of visits" << endl;
	cout  << "-----" << setw(2) << " ----------------" << endl;
	for (int i = 24; i >-1 ; i--){
		cout << setw(5) << i + 1;
		for(int j=0; j < floorVisits[i]; j++)
		cout << setw(2) << '*' ;
		cout << endl;
	}*/
	
    return 0;
}

void ShowInventory(int *p){
    cout << "Showing inventory after adding" << endl;
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            cout << *(p+i*5+j) << ' ';
        }
        cout << endl;
    }
}

void AddProduct(int *p, int warehouse, int product, int quantity){
    *(p+warehouse*5+product) += quantity;
}

bool CheckForWrongValues(int *p, int warehouse, int product, int quantity){
    int check = -99; //just a random value to initialize
    if (warehouse<0 || warehouse > 3)
        check=1;
    if (product<0 || product > 4)
        check=2;
    if ( (warehouse>=0 && warehouse <= 3) 
          && ((product>=0 && product <= 4)) 
            && (*(p+warehouse*5+product)+quantity) < 0
            )
        check=3;
    
    switch(check){
        case 1: cout << "Invalid value for warehouse: "<< warehouse; return false;
        case 2: cout << "Invalid value for product: "<< product; return false;
        case 3: cout << "Cannot subtract "<< -quantity << " from " << *(p+warehouse*5+product ) << endl; 
                cout << "product number " << product+1 << " from warehouse number " << warehouse+1 << " is set to zero now" << endl;
                *(p+warehouse*5+product)=0; return false;
        default: return true;
    }
}