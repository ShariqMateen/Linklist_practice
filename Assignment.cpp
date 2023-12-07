#include<iostream>
using namespace std;
class Node{
//	private:
//		Node *head;
	public:	
	int val;
	Node *next;
	
	Node(int value){
		val=value;
		next=NULL;
	}
};
void create_node(Node* &head,int value){
	Node* newnode=new Node(value);
	if(head==NULL){
		head=newnode;
	}
	else{
		Node *current=head;
		while(current->next!=NULL){
			current=current->next;
		}
		current->next=newnode;
	}
}
void display(Node *head){
	Node *current=head;
	cout<<"Final list is :"<<endl<<endl;
	while(current!=NULL){
		cout<<current->val<<"-->";
		current=current->next;
	}
	cout<<"NULL"<<endl;
	cout<<endl<<endl;
	
}
void Traversing(Node* &head,int find){
	
	while(head->val!=find){
		head=head->next;
		
	}
	if(head->val==find){
	
	cout<<"value found "<<endl;}
	else{
		cout<<"The value you want to find is not available in the list"<<endl;
	}
	
}
 Node* insertAtBeginning(Node* head,int data){
	Node *newnode = new Node(data);
	newnode->next=head;
	head=newnode;
	return head;
}
Node* delete_first_node(Node* head){
	Node  *temp;
	temp=head;
	head=head->next;
	delete temp;
	return head;
}
void insertNode(Node* head,int after_data,int data){
	Node *current = head;
	while(current->val!=after_data){
		current=current->next;
	}
	Node* temp=new Node(data);
	temp->next=current->next;
	current->next=temp;
}
//void insert_sorted(Node* head){
//	Node *current=head;
//	for(int i=0)
//}
void delete_after_given_node(Node* &head,int given){
	Node *temp=head;
	while(temp->val!=given){
		temp=temp->next;
	}
	Node *current;
	current=temp->next;
	temp->next=current->next;
	delete current;
	
	
}

Node* search_from_unsorted(Node* &head,int find){
	Node* temp=head;
	while(temp->val!=find){
		temp=temp->next;
	}
	return temp;
}
void delete_with_info(Node* head,int info){
	Node *current=head;
	while(current->next->val!=info){
		current=current->next;
	}
	Node* temp;
	temp=current->next;
	current->next=temp->next;
	delete temp;
}
int main(){
    Node *head=NULL;
int choice;
    do{
    	
    	cout << "MAIN MENU\n";
	    cout << "PRESS 1 FOR CREATING A LINKED LIST\n";
	    cout << "PRESS 2 FOR TRAVERSING THE LINKED LIST\n";
	    cout << "PRESS 3 FOR INSERTING DATA AT THE BEGINNING INTO THE LINKED LIST\n";
	    cout << "PRESS 4 FOR INSERTING DATA AFTER A GIVEN NODE INTO LINKED LIST\n";
	    cout << "PRESS 5 FOR INSERTING DATA INTO A SORTED LINKED LIST\n";
	    cout << "PRESS 6 FOR DELETING THE FIRST NODE FROM A LINKED LIST\n";
	    cout << "PRESS 7 FOR DELETING THE NODE AFTER A GIVEN NODE FROM A LINKED LIST\n";
	    cout << "PRESS 8 FOR DELETING THE NODE WITH THE GIVEN ITEM OF INFORMATION\n";
	    cout << "PRESS 9 FOR SEARCHING THROUGH AN UNSORTED LINKED LIST\n";
	    cout << "PRESS 10 FOR SEARCHING THROUGH A SORTED LINKED LIST\n";
	    cout << "PRESS 0 TO EXIT\n";
	    cout << "PLEASE ENTER YOUR CHOICE: ";
        cin >> choice;
        
        

  switch (choice) {
            case 1:{
            	system("cls");
            	int val;
				cout<<"Enter value :";
				cin>>val;
                create_node(head,val);
                display(head);
                break;}
            case 2:
            	system("cls");
            	int find;
            	cout<<"Enter value that you wantto find :";
            	cin>>find;
                Traversing(head,find);
                break;
            case 3: {
            	system("cls");
                int data;
                cout << "Enter data to insert: ";
                cin >> data;
                head=insertAtBeginning(head,data);
                display(head);
				break;
            }
            case 4: {
            	            	system("cls");
                int data,after_data;
                cout<<"Enter node after that you want to enter new node :";
                cin>>after_data;
                cout << "Enter data to insert: ";
                cin >> data;
                insertNode(head,after_data,data);
                display(head);
				break;
            }
            case 5: {
            	system("cls");
//            	insert_sorted(head);
                break;
            }
            case 6:{
            	system("cls");
            	head=delete_first_node(head);
            	display(head);
            	
				break;
			}
              
            case 7: {
            	system("cls");
            	int given;
            	cout<<"Enter the value of node, after that node you want to delete the node :";
            	cin>>given;
            	delete_after_given_node(head,given);
            	display(head);
                break;
            }
            case 8: {
            	system("cls");
            	int info;
            	cout<<"enter information of node which you want to delete :";
            	cin>>info;
            	delete_with_info(head,info);
            	display(head);
                break;
            }
            case 9: {
            	system("cls");
            	int find;
            	cout<<"enter value that you want to find:";
            	cin>>find;
            	Node *ptr;
            	ptr=search_from_unsorted(head,find);
            	cout<<ptr->val;
                break;
            }
            case 10: {
              }
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
}
	}while(choice != 0);
cout<<endl;
    return 0;
	}
