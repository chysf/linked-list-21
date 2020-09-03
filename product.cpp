#include "product.h"

Product::Product(string req_name, ProductType req_type, float req_price){
	name = req_name;
	type = req_type;
	price = req_price;
	quantity = 0;
}

string Product::getName(){
	return name;
}

ProductType Product::getType(){
	return type;
}

float Product::getPrice(){
	return price;
}

int Product::getQuantity(){
	return quantity;
}

bool Product::setPrice(float req_price){
	if(req_price > 0){
		price = req_price;
		return true;
	}
	return false;
}

bool Product::setQuantity(int req_quantity){
	if(req_quantity >= 0){
		quantity = req_quantity;
		return true;
	}
	return false;
}

int Product::compare(Product* other){
	if(this->getPrice() > other->getPrice()){
		return 1;
	}else if(this->getPrice() < other->getPrice()){
		return -1;
	}else{
		if(this->getName() > other->getName()){
			return 1;
		}else if(this->getName() < other->getName()){
			return -1;
		}else{
			return 0;
		}
	}
}


