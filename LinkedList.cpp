#include <iostream>
#include "simpio.h"
using namespace std;

struct Entry {
	string name;
	Entry * next;
};

Entry * GetNewEntry() {
	string str = getLine("Name: ");
	if (str == "")
		return NULL;
	Entry * node = new Entry;
	node->name = str;
	node->next = NULL;
	return node;
}

Entry * BuildEntryList() {
	Entry * head = NULL;
	while (true) {
		Entry * node = GetNewEntry();
		if (node == NULL) break;
		node->next = head;
		head = node;
	}
	return head;
}

void DeallocateList(Entry * list) {
	while (list != NULL) {
		Entry * head = list->next;
		delete list;
		list = head;
	}
}

void RecPrintList(Entry * list) {
	if (list != NULL) {
		cout << list->name << endl;
		RecPrintList(list->next);
	}
}

void InsertSorted(Entry * & list, Entry * node) {
	if (list == NULL || node->name > list->name) {
		node->next = list;
		list = node;
	} else
		InsertSorted(list->next, node);
}

void DeleteFromList(Entry * & list, string name) {
	if (list->name == name) {
		Entry * todelete = list;
		list = list->next;
		delete todelete;
	}
	else
		DeleteFromList(list->next, name);
}

int main() {
	Entry * list = BuildEntryList();
	DeleteFromList(list, "b");
	RecPrintList(list);
	return 0;
};