#include "shop.h"

Shop::Shop(string req_name, int req_shopNumber){
	name = req_name;
	shopNumber = req_shopNumber;
	products = nullptr;
	productCount = 0;
}

Shop::Shop(Shop& another){
	name = another.getName();
	shopNumber = another.getShopNumber();
	productCount = another.productCount;
	Product** temp = new Product*[productCount];
	for(int i = 0 ; i < productCount; i++){
		temp[i] = new Product(another.products[i]->getName(),
				another.products[i]->getType(), another.products[i]->getPrice());
		temp[i]->setQuantity(another.products[i]->getQuantity());
	}
	products = temp;
}

Shop::~Shop(){
	if(products != nullptr){
		for(int i = 0; i < productCount; i++){
			if(products[i] != nullptr){
				delete products[i];
				products[i] = nullptr;
			}
		}
		delete []products;
		products = nullptr;
	}
}

string Shop::getName(){
	return name;
}

int Shop::getShopNumber(){
	return shopNumber;
}

void Shop::setName(string req_name){
	name = req_name;
}

void Shop::setShopNumber(int req_shopNumber){
	shopNumber = req_shopNumber;
}

void Shop::addProduct(string req_name, ProductType req_type, float req_price, int quantityToAdd){
	for(int i = 0; i < productCount; i++){
		if(products[i]->getName() == req_name){
			products[i]->setQuantity(products[i]->getQuantity()+quantityToAdd);
			return;
		}
	}

	Product** temp = new Product*[++productCount];
	Product* temp2 = new Product(req_name, req_type, req_price);
	temp2->setQuantity(quantityToAdd);

	if(products == nullptr){
		temp[0] = temp2;
	}else{
		for(int i = 0, j = 0; i < productCount; i++){
			if(i == 0){
				if(products[i]->compare(temp2) == 1){
					temp[i] = temp2;
					j++;
				}else{
					temp[i] = products[i];
				}
			}else if(i == productCount - 1 && j == 0){
					temp[i] = temp2;
			}else if(products[i-1]->compare(temp2) == -1 && products[i]->compare(temp2) == 1){
				temp[i] = temp2;
				j++;
			}
			else{
				temp[i] = products[i-j];
			}
		}
	}
	if(products != nullptr){
		delete []products;
	}
	products = temp;
}

bool Shop::removeProduct(string req_name, int quantityToRemove){
	Product* temp = findProduct(req_name);
	if(temp == nullptr || quantityToRemove <= 0){
		return false;
	}
	int quantity = temp->getQuantity();
	if(quantity < quantityToRemove){
		return false;
	}
	if(quantity > quantityToRemove){
		if(temp->setQuantity(quantity-quantityToRemove)){
			return true;
		}
	}
	if(quantity == quantityToRemove){
		Product** temp2 = new Product*[productCount - 1];
		for(int i = 0, j = 0; i < productCount; i++){
			if(products[i]->getName() == req_name){
				delete products[i];
				products[i] = nullptr;
				j++;
			}else{
				temp2[i-j] = products[i];
			}
		}
		if(products != nullptr){
			delete []products;
		}
		products = temp2;
		productCount--;
		return true;
	}
	return false;
}

Product* Shop::findProduct(string req_name){
	for(int i = 0; i < productCount; i++){
		if(products[i]->getName() == req_name){
			return products[i];
		}
	}
	return nullptr;
}

bool Shop::updatePrice(string req_name, float req_price){
	Product* req_product = findProduct(req_name);
	if(req_product == nullptr || req_price <= 0){
		return false;
	}
	Product** tempForDel = new Product*[--productCount];
	string a = req_name; ProductType b = req_product->getType();
	float c = req_price; int d = req_product->getQuantity();
	for(int i = 0, j = 0; i < productCount + 1; i++){
		if(products[i]->getName() == req_name){
			delete products[i];
			products[i] = nullptr;
			j++;
		}
		tempForDel[i] = products[i+j];
	}
	if(products != nullptr){
		delete []products;
	}
	products = tempForDel;
	addProduct(a,b,c,d);
	return true;
}













