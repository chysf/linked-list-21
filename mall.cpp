#include "mall.h"

Mall::Mall(string req_name, string req_address){
	name = req_name;
	address = req_address;
	shopHead = nullptr;
}

Mall::Mall(Mall& another){
	name = another.name;
	address = another.address;
	shopHead = duplicateShopLinkedList(another.shopHead);
}

Mall::~Mall(){
	for(Node *prev = nullptr, *curr = shopHead; curr != nullptr;){
		prev = curr;
		curr = curr->getNext();
		if(prev != nullptr){
			delete prev;
		}
	}
}

void Mall::setName(string req_name){
	name = req_name;
}

void Mall::setAddress(string req_address){
	address = req_address;
}

string Mall::getName(){
	return name;
}

string Mall::getAddress(){
	return address;
}

bool Mall::addShop(string req_name, int req_shopNumber){
	for(Node* temp = shopHead; temp != nullptr; temp = temp->getNext()){ //searching number
		if(temp->getShop()->getShopNumber() == req_shopNumber){
			return false;
		}
	}
	if(shopHead == nullptr){
		shopHead = new Node(new Shop(req_name, req_shopNumber), nullptr);
		return true;
	}
	Node* temp2 = shopHead;
	for(; temp2->getNext() != nullptr; temp2 = temp2->getNext()); //shift to the last node
	temp2->setNext(new Node(new Shop(req_name, req_shopNumber), nullptr));// next is shop of req name and no., next of next is nullptr
	return true;
}

bool Mall::removeShop(int req_shopNumber){
	Node* past = nullptr;
	Node* curr = shopHead;
	if(curr->getShop()->getShopNumber() == req_shopNumber){
		shopHead = shopHead->getNext();
		delete curr;
		curr = nullptr;
		return true;
	}
	for(; curr != nullptr; past = curr, curr = curr->getNext()){
		if(curr->getShop()->getShopNumber() == req_shopNumber){
			past->setNext(curr->getNext());
			curr->setNext(nullptr);
			delete curr;
			return true;
		}
	}
	return false;
}

Shop* Mall::getShop(int req_shopNumber){
	for(Node* temp = shopHead; temp != nullptr; temp = temp->getNext()){
		if(temp->getShop()->getShopNumber() == req_shopNumber){
			return temp->getShop();
		}
	}
	return nullptr;
}






