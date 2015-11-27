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

struct node* deque(struct node** current,int trigger, int widgets,double promo){
	int totalPrice;
	if(trigger > 0){
		 int promo  = (((*current)->widgets * (*current)->price * promo) / 100);	
		} else {
			promo = 1;
		
		}	

if((*current)->widgets == 0){
	*current = (*current)->back;
}	
	while(widgets > (*current)->widgets){	
	
		if(trigger > 0){
                promo = (((*current)->widgets * (*current)->price * promo) / 100);
        		} else {
                		promo = 1;
        		}

			totalPrice = ((*current)->widgets * (*current)->price * 1.3) - promo;

			cout << (*current)->widgets << " sold at $" << (*current)->price << " per widget Sales: $" << totalPrice << endl; 

			widgets = widgets - (*current)->widgets;
			
			if((*current)->back == NULL){
				cout << "Not enough widgets cancel order" << endl;
				(*current)->widgets = 0;
				return *current;
			}

			*current = (*current)->back;
			trigger--;			
		}
	
		(*current)->widgets = (*current)->widgets - widgets;
		cout << widgets << " at $" << (*current)->price << " each Sales $" << ((*current)->price * widgets * 1.3) - promo << endl;
		trigger--;	
		return *current;
}

int main() {
       ifstream input;
        input.open("data.txt");
	int size = 0;
	struct node *head = buildList();
	struct node *current = head;	
	char n;
	int i;
	input >> n;
	int trigger = 0;
	int widgets;
	double price;
	int promo;
	while(!input.fail()) {
		if(n == 'r'){
			input >> widgets;
			input >> price;
//			cout << "The price of these widgets is $" << price << endl;
			current = enque(&current,widgets,price);
			
		}		
		else if (n == 's'){
			input >> widgets;
			head = deque(&head,trigger,widgets,promo);
			if(trigger == 2 || trigger == 1){trigger--;}
			
		}
		else if (n == 'p'){

			input >> i;
			promo = i;
			trigger = 2;
			cout << "There is a " << i << "%" << " discount on the next two items." << endl;
		}
		input >> n;
	}

//	length(head);
}
