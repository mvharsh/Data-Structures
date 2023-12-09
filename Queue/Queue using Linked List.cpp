#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void Display(Node* n){
    if (n == NULL){
        cout << "Queue is Empty\n";
        return;
    }
    cout<<"Queue: ";
    while (n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

Node* EnQueue(Node* front, int new_data){

    Node* new_node = new Node();
    Node *rear = front;
    new_node->data = new_data;
    new_node->next = NULL;
    if (front == NULL){
        front = new_node;
        cout<<"Element inserted\n";
        Display(front);
        return front;
    }
    while (rear->next != NULL)
        rear = rear->next;
    rear->next = new_node;
    cout<<"Element inserted\n";
    Display(front);
    return front;
}

Node* DeQueue(Node* front){

    Node* temp = front;
    if (temp == NULL){
        cout << "Queue is Empty\n";
        return front;
    }
    front = temp->next;
    delete temp;
    cout<<"Element deleted\n";
    Display(front);
    return front;
}

int main(){
    Node *front = NULL;
    int ch, a;
    cout << "1.Insert \n";
    cout << "2.Delete \n";
    cout << "3.Exit\n";

    do{
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch(ch){

            case (1):
                cout << "Enter the value to be insert to the Queue : ";
                cin >> a;
                front = EnQueue(front, a);
                break;

            case (2):
                front = DeQueue(front);
                break;

            case (3):
                break;

            default:
                cout << "Enter a value between 1 and 4";
        }
    }while(ch != 3);
    return 0;
}
