#include <iostream>
using namespace std;
#define SIZE 3
class QUEUE
{
    public:
        int q[SIZE];
        int front;
        int rear;
        void insertQ();
        void deleteQ();
        void displayQ();
        QUEUE()
        {
          front=-1;
          rear=-1;
        }
};

void QUEUE :: insertQ(){
    if ((front == 0 && rear==SIZE-1)||(front==rear+1))
    {
     cout << "Queue Overflow\n";
     return;
    }
    int elem;
    cout << "Enter the value to be inserted : ";
    cin >> elem;
    if (rear == -1)
        front = 0;
    if(rear==SIZE-1)
        rear=0;
    else
        rear = rear + 1;
    q[rear] = elem;
    cout<< "Element inserted\n";
    displayQ();
}

void QUEUE::deleteQ(){

    if(front == -1)
    {
     cout << "Queue Underflow\n";
     return;
    }
    cout << "Element deleted from queue is " << q[front] << endl;
    if (front == rear)
    {
      front = -1;
      rear = -1;
    }
    else if(front==SIZE-1)
        front=0;
    else
        front = front + 1;
    displayQ();
}

void QUEUE :: displayQ(){
    int f = front;
    int r = rear;
    cout<<"Queue: ";
    if(f==-1)
        cout<<"EMPTY";
    else
    {
      int i;
      for(i=f;i!=r;i=(i+1)%SIZE)
        cout<<q[i]<<" ";
      cout<<q[i];
      cout << endl;
    }
}

int main(){

    int choice;
    QUEUE q;
    cout << "1 > Insert in Queue\n";
    cout << "2 > Delete from Queue\n";
    cout << "3 > Exit\n";

    do{
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch(choice){

            case 1:
                q.insertQ();
                break;

            case 2:
                q.deleteQ();
                break;

            case 3:
                return 0;

            default:
                cout<<"Wrong input\n";
                break;
        }
    }while(choice != 3);
}
