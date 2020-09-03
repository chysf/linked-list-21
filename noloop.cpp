#include "mall.h"

Node* Mall::duplicateShopLinkedList(Node* req_node){
	if(req_node == nullptr) return nullptr;
	Shop* temp = new Shop(*(req_node->getShop()));
	Node* temp2 = new Node(temp, duplicateShopLinkedList(req_node->getNext()));
	return temp2;
}
