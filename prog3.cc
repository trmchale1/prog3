#include <iostream>
#include <fstream>
using namespace std;

struct node {
	int widgets;
	double price;
	struct node* next;
	struct node* back;
};

/* Build list 1,2,3*/
 

struct node* buildList() {
	struct node* head = NULL;
	head = new node;
	head->widgets = 0;
	head->price = 0;
	head->next = NULL;
	head->back = NULL;
	return head;
}

struct node* enque(struct node** current, int widgets, double price){
	struct node* newBackNode = new node;
	newBackNode->widgets = widgets;
	newBackNode->price = price;
	(*current)->back = newBackNode;
	newBackNode->next = *current;
	*current = newBackNode;
	return *current;
}

int length(struct node* current){
	int count = 0;
	while (current != NULL) {
		cout << current->widgets << " " << current->price << endl;
		current = current->back;
	}	

}

struct node* deque(struct node** current,int trigger, int widgets){
	int totalPrice;
	if((*current)->widgets == 0){
		*current = (*current)->back;
	}	
		while(widgets > (*current)->widgets){	
			totalPrice = (*current)->widgets * (*current)->price * 1.3;

			cout << (*current)->widgets << " sold at $" << (*current)->price << " per widget Sales: $" << totalPrice << endl; 

			widgets = widgets - (*current)->widgets;
			
			if((*current)->back == NULL){
				cout << "Not enough widgets cancel order" << endl;
				(*current)->widgets = 0;
				return *current;
			}

			*current = (*current)->back;
			
		}
	
		(*current)->widgets = (*current)->widgets - widgets;
		cout << widgets << " at $" << (*current)->price << " each Sales $" << (*current)->price * widgets * 1.3 << endl;
	
	return *current;
	
}

int main() {
       ifstream input;
        input.open("data.txt");
	int size = 0;
	struct node *head = buildList();
	struct node *current = head;	
	char n;
	input >> n;
	int trigger = 0;
	int widgets;
	double price;
	while(!input.fail()) {
		if(n == 'r'){
			input >> widgets;
			input >> price;
//			cout << "The price of these widgets is $" << price << endl;
			current = enque(&current,widgets,price);
			
		}		
		else if (n == 's'){
			input >> widgets;
			head = deque(&head,trigger,widgets);
			if(trigger == 2 || trigger == 1){trigger--;}
			
		}
		else if (n == 'p'){
//cout << "There is a " << n << "%" << " discount on the next two items." << endl;
			input >> n;
//			trigger = 2;
		}
		input >> n;
	}

//	length(head);
}
