#include<iostream>
#include<vector>
using namespace std;

struct node
{
	int data;
	node *next;
};

node* creatList(vector<int> v) {
	int n = v.size();
	node* head = NULL;
	node* tail = NULL;
	for (int i = 0; i < n; i++) {
		node* temp = new node;
		temp->data = v[i];
		temp->next = NULL;
		if (!head) head = temp;
		if (tail) tail->next = temp;
		tail = temp;
		temp = temp->next;
		
	}
	return head;
}

void insert_atTail(node* head, node* newNode)
{ 
	node* ptr = head;
	node* ptr2 = ptr->next;
	while (ptr2 != NULL) {
		ptr = ptr->next;
		ptr2 = ptr->next;
	}
	ptr->next = newNode; //get the tail node
	newNode->next = NULL; //make sure only one single node is being added at the end
}

void display(node* ptr) {
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

static int get_length(node* head) {
	int list_length = 0;
	while (head != nullptr) {
		head = head->next;
		list_length++;
	}
	return list_length;
}

node* intersect(
	node* head1,
	node* head2) {

	node* list1node = nullptr;
	int list1length = get_length(head1);
	node* list2node = nullptr;
	int list2length = get_length(head2);

	int length_difference = 0;
	if (list1length >= list2length) {
		length_difference = list1length - list2length;
		list1node = head1;
		list2node = head2;
	}
	else {
		length_difference = list2length - list1length;
		list1node = head2;
		list2node = head1;
	}

	while (length_difference > 0) {
		list1node = list1node->next;
		length_difference--;
	}

	while (list1node != nullptr) {
		if (list1node == list2node) {
			return list1node;
		}
		list1node = list1node->next;
		list2node = list2node->next;
	}
	return nullptr;
}



int main() {
	vector<int> v1 = { 1, 2, 3, 4 };
	node* list_head_1 = creatList(v1);

	vector<int> v2 = { 4, 3, 2, 1 };
	node* list_head_2 = creatList(v2);

	node* newNode = new node;
	newNode->data = 8;
	newNode->next = NULL;

	node* newNode2 = new node;
	newNode2->data = 9;
	newNode2->next = NULL;

	insert_atTail(list_head_1, newNode);
	insert_atTail(list_head_1, newNode2);
	display(list_head_1);
	cout << "-----------------------------" << endl;

	insert_atTail(list_head_2, newNode);
	display(list_head_2);
	cout << "-----------------------------" << endl;

	node* intersect_node = intersect(list_head_1, list_head_2);
	display(intersect_node);

	system("pause");
	return 0;
}
