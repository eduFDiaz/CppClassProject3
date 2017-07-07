#include <ctime> 
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//Eduardo Antonio Fernandez Diaz
void ShowInventory(int *p);

int main()
{
    int wharehouses=3, products=4;
    int inventory[wharehouses][products]={0};
    
    int sentinel;
    do{
        cout<<"Enter 1 to update your inventory or -1 to finish" << endl;
        cin >> sentinel;
        
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
    
}