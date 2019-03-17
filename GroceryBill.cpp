#include "GroceryBill.h"
#include <iostream>

using namespace std;

GroceryBill::GroceryBill(const PriceList *priceList, double taxRate) {
	// To be completed
	list = priceList;
        taxes = taxRate;
        itemCheck=0;
        total=0;
}


void GroceryBill::scanItem(string scanCode, double quantity) {
	// To be completed
	scanCodeArray[itemCheck]=scanCode;
        scanQuantityArray[itemCheck]= quantity;
        itemCheck++;
}

// Scan multiple codes and quantities from the given text file
// Each line contains two numbers separated by space: the first is the code (an integer), the second the quantity (a float/double)
// Example line from text file:
// 15000000 1.5
void GroceryBill::scanItemsFromFile(string filename) {
	// To be completed
	// HINT: Look at code in PriceList::createPriceListFromDatafile(string filename)
	int code;
        double quantity;
        ifstream file(filename);
        if (file.is_open()) 
	{
          while (file >> code >> quantity)
         {
            scanItem(code, quantity);
         }
	 file.close();
       }
        else
            throw invalid_argument("Could not open file " + filename);
     }

// return the total cost of all items scanned
double GroceryBill::getTotal() {
	// To be completed
	for(int i=0; i< scanCode; i++)
        {
          for(int j=0; j<quantity;j++)
          {
              if (pricelist->getItem(code)->isTaxable())
             {
                 total += list->getItem(code[i])->getPrice();
             }
          }
        }
        return total;
}

// Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded. 
// The last line shows the total.
// An example:
//Plastic_Wrap	1.60547 T
//Sugar_white	5.475
//Waffles_frozen	5.16
//Oil_Canola_100%_pure	2.69
//Potatoes_red	13.446
//TOTAL 	28.3765
void GroceryBill::printBill() {
	// To be completed
	for (int i = 0; i < scanCode; i++)
	{
           for(int j=0; j< quantity; j++)
           {
                cout << list->getItem(code).getItemName() << list->getItem().getPrice()<<list->getItem().isTaxable() "T" : "") << endl;
           }
        }
         cout << "Total: " << getTotal() <<endl;

}

