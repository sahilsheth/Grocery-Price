#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PriceList.h"
#include "PriceListItem.h"

using namespace std;

//default constructor
PriceList::PriceList()
{
	addItem = 0;
	items= new PriceListItem [1000000];
}

//copy constructor
PriceList::PriceList(PriceList & a)
{
	addItem = a.addItem;
	items = new PriceListItem[addItem];
	for (int i = 0; i < addItem; i++)
	{
		items[i] = a.items[i];
	}
}

//assignment operator
PriceList & PriceList::operator=(const PriceList & a)
{
   if (this != &a)
	 {
      delete [ ] items; //delete old array
      addItem = a.addItem; // set new size
      items = new PriceListItem[addItem]; // allocate new array
      for (int i=0; i < addItem; i++)
			{
          items[i] = a.items[i];
      }
    }
return *this;
}


// Load information from a text file with the given filename.
void PriceList::createPriceListFromDatafile(string filename) {
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string name;
		string code;
		double price;
		bool taxable;
		while (myfile >> name >> code >> price >> taxable) {
			// cout << code << " " << taxable << endl;
			addEntry(name, code, price, taxable);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return true only if the code is valid
bool PriceList::isValid(string code) const {
	// TO BE COMPLETED
	int i=0;
  	for (i=0; i<1000000; i++)
	{
		if(items[i].getCode()== code);
		{
			return true;
		}
	}
	return false;
    }


// return price, item name, taxable? as an ItemPrice object; throw exception if code is not found
PriceListItem PriceList::getItem(string code) const {
	// TO BE COMPLETED
	int i;
        for (i=0; i<1000000; i++)
        {
	    if(items[i].getCode()== code)
	    {
		return items[i];
	    }
	    else
	    {
	        throw invalid_argument("Code not found");
	    }
        }
}

// add to the price list information about a new item
void PriceList::addEntry(string itemName, string code, double price, bool taxable) {
	// TO BE COMPLETED
	//Create a new PriceListItem to get its information
	PriceListItem s(itemName, code, price, taxable);
	items[addItem]= s;
	addItem ++;
}
