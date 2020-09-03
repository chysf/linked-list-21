#include "node.h"

Node::Node(Shop* req_shop, Node* req_next){
	shop = req_shop;
	next = req_next;
}
Node::~Node(){
	if(shop != nullptr){
		delete shop;
		shop = nullptr;
	}
}

Shop* Node::getShop(){
	return shop;
}

Node* Node::getNext(){
	return next;
}

void Node::setShop(Shop* req_shop){
	shop = req_shop;
}

void Node::setNext(Node* req_node){
	next = req_node;
}
