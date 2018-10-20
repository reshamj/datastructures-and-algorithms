#include <iostream>
#include <cstdlib>
class Node
{
public:
    Node* next;
    int data;
};

using namespace std;

class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    void add(int data);
    void print();
    Node* findKtoLast(int kValue);
    Node* getValueKtoLast(Node* head, int count, int kValue);
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = nullptr;
}

LinkedList::~LinkedList(){
    Node* temp;
    temp = head;
    head = head->next;
    while(head->next != nullptr)
        {   
            std::cout<<"temp = "<<temp->data;
            std::cout<<"  head="<<head->data<<endl;
            delete temp;
            temp = head;
            head =head -> next;
        }
        delete head;
    std::cout << "LIST DELETED";
}

void LinkedList::add(int data){
    
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    //Add the first node
    if (length == 0)
    {   
        head = node;
    }//Add at the end
    else {
            Node* temp;
            temp = head;
            while(temp->next != nullptr)
            {
                temp =temp ->next; 
            }
            temp->next= node;
    }
    length++;
    std::cout<<"Node = "<<node->data;
    std::cout<<"length:"<<length<<endl;
}

void LinkedList::print(){
    Node* temp = head;
    int i = 1;
    while(temp->next != nullptr){
        std::cout << temp->data << " --> ";
        temp = temp->next;
        i++;
    }
    std::cout << temp->data;
}

Node* LinkedList::findKtoLast(int kValue)
{
    Node* temp = head;
    int count=0;
    if(head->next == nullptr)
        return head;
  
    if(kValue == 0)
    {
        while(temp != nullptr)
        {
          return temp;
          temp = temp->next;
        }
    }
    else{
        while(temp != nullptr )
            {
                count++;
                temp = temp->next;
            }
        cout<<endl<<"Count = "<<count;
        if(kValue > count)
            return nullptr;
        else
        {
            //cout<<"in else"<<endl;
            Node* temp;
            temp = getValueKtoLast(head, count, kValue);
            
            while(temp != nullptr )
            {
                cout<<temp->data<<"-->";
                temp = temp->next;
            }
            cout<<"null";
            return temp;
        }
    }
}

Node* LinkedList::getValueKtoLast(Node* head, int count, int kValue)
{
    //cout<<"in getvalue"<<endl;
    Node* temp =head;
    int i=0;
    while(temp != nullptr)
    {
        i++;
        if(i == kValue)
        {
            cout<<"k found"<<endl;
            return temp;
        }
         temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    LinkedList* list = new LinkedList();
    for (int i = 0; i < 5; ++i)
    {
        list->add(i);
    }
    list->add(4);
    list->add(1);
    list->print();
    Node* node;
    node=list->findKtoLast(3);

return 0;
}

    

