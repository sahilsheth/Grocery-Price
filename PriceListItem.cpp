#include "PriceListItem.h"
#include<iostream>
#include<string>

PriceListItem::PriceListItem(const string &itemName, const string &code, double price, bool taxable) {
	// TO BE COMPLETED
	//get the private variables
        this->itemName = itemName;
        this->code = code;
        this->price = price;
        this->taxable = taxable;
}

//default constructor
PriceListItem::PriceListItem() {
	// TO BE COMPLETED
	itemName = " ";
        code = "";
        price = 0;
        taxable = false;

}

string PriceListItem::getItemName() {
	// TO BE COMPLETED
	return itemName;
}

string PriceListItem::getCode() {
	// TO BE COMPLETED
	return code;
}

double PriceListItem::getPrice() {
	// TO BE COMPLETED
	return price;
}

bool PriceListItem::isTaxable() {
	// TO BE COMPLETED
	return taxable;
}

