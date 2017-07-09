#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//Eduardo Antonio Fernandez Diaz

void ShowInventory(int *p,bool ShowTotal=false);
void AddProduct(int *p, int warehouse, int product, int quantity);
bool CheckForWrongValues(int *p, int warehouse, int product, int quantity);
void ShowStats(int *p);

int main()
{
    int inventory[4][5], *ptr, sentinel;
    
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            inventory[i][j]=(i*5)+j+1;//For testing purposes
            //inventory[i][j]=0;
        }
    }
    
    ptr = inventory[0];
    
    do{
        ShowInventory(ptr);
        int warehouse, product, quantity;
        cout << "Type the warehouse, product and quantity as space separated integers\n"
             << "To add 25 units of the fifth product to the fourth warehouse type: 4 5 25" << endl
             << "To subtract, just add the minus sign before, following the example: 4 5 -25" << endl;
        cin >> warehouse >> product >> quantity;
        if (CheckForWrongValues(ptr,warehouse-1,product-1,quantity)){
                     AddProduct(ptr,warehouse-1,product-1,quantity);
                  ShowInventory(ptr);
        }
        cout<<"Enter -1 to finish, anything else to continue" << endl;
        cin >> sentinel;
        system("clear");
    }while(sentinel!=-1);
    ShowInventory(ptr,true);
    return 0;
}

void ShowInventory(int *p, bool showTotals){
    //This function displays the actual inventory    
    cout << "\t      Product" << endl;
    cout << setw(2) << "Warehouse  1  2  3  4  5";
    if (showTotals==true) 
        cout << "   Total"; cout << endl;
    cout << setw(2) << "---------  -------------" << endl;
    int pTotal[5]={0};//will store the total of each product
    for(int i=0;i<4;++i){
        cout << setw(5) << i + 1 << "\t  ";
        int wTotal=0;//will store the total of products for each warehouse
        for(int j=0;j<5;++j){
            cout << setw(2) << *(p+i*5+j) << ' ';
            wTotal+=*(p+i*5+j);
            pTotal[j]+=*(p+i*5+j);
        }
        if (showTotals==true) 
            cout << "   " << wTotal;
        cout << endl;
    }
    if (showTotals==true){
            cout << endl << "  Total   ";
            for(int j=0;j<5;++j){
                cout << setw(2) << pTotal[j] << ' ';
            }
    }
    cout << endl;
}

void AddProduct(int *p, int warehouse, int product, int quantity){
    //This function add or subtract product according to the sign of quantity
    *(p+warehouse*5+product) += quantity;
}

bool CheckForWrongValues(int *p, int warehouse, int product, int quantity){
    //THis function handles all the errors, return true only if no error is committed
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
        case 1: cout << "Invalid value for warehouse: "<< warehouse + 1 << endl; return false;
        case 2: cout << "Invalid value for product: "<< product + 1 << endl; return false;
        case 3: cout << "Cannot subtract "<< -quantity << " from " << *(p+warehouse*5+product ) << endl; 
                cout << "product number " << product+1 << " from warehouse number " << warehouse+1 << " is set to zero now" << endl;
                *(p+warehouse*5+product)=0; return false;
        default: return true;
    }
}