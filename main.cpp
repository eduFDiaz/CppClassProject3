#include <ctime> 
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//Eduardo Antonio Fernandez Diaz

void ShowInventory(int *p);
void AddProduct(int *p, int wharehouse, int product, int quantity);
void SubstractProduct(int *p, int wharehouse, int product, int quantity);
bool CheckForWrongValues(int *p, int wharehouse, int product, int quantity);

int main()
{
    int wharehouses=3, products=4;
    int inventory[4][5];
    
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            inventory[i][j]=(i*5)+j+1;
            //inventory[i][j]=0;
            cout << inventory[i][j] << ' ';
        }
        cout << endl;
    }
    int *ptr;
    ptr = inventory[0];
    
    int sentinel;
    //do{
        //cout<<"Enter 1 to update your inventory or -1 to finish" << endl;
        //cin >> sentinel;
        ShowInventory(ptr);
        
    //}while(sentinel!=-1);
	
	
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
    cout << "Showing whole array after adding" << endl;
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            cout << *(p+i*5+j) << ' ';
        }
        cout << endl;
    }
}

void AddProduct(int *p, int wharehouse, int product, int quantity){
    cout << "Showing whole array after adding" << endl;
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            cout << *(p+i*5+j) << ' ';
        }
        cout << endl;
    }
}

void SubstractProduct(int *p, int wharehouse, int product, int quantity){
    cout << "Showing whole array after adding" << endl;
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            cout << *(p+i*5+j) << ' ';
        }
        cout << endl;
    }
}

bool CheckForWrongValues(int *p, int wharehouse, int product, int quantity){
    int check;
    switch(case){
    }
    cout << "Showing whole array after adding" << endl;
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            cout << *(p+i*5+j) << ' ';
        }
        cout << endl;
    }
}