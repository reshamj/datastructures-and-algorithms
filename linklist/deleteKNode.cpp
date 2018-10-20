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
    int deleteNode(int input); //delete any node within list with access to head
    void deleteKNode(Node* node); //delete node with access to only particular node
    Node* returnNode(int input);
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
    Node* temp;
    temp = head;
    head = head->next;
    while(head->next != NULL)
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
            while(temp->next != NULL)
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
    while(temp->next != NULL){
        std::cout << temp->data << " --> ";
        temp = temp->next;
        i++;
    }
    std::cout << temp->data;
}

int LinkedList::deleteNode(int input)
{
    Node* temp;
    Node* q;
    temp = head;
    while(temp->data!= input)
    {
        q = temp;
        temp= temp->next;
    }
    q->next = temp->next;
    return temp-> data;
    delete temp;
}


Node* LinkedList::returnNode(int input)
{
    Node* temp =head;
    while(temp != nullptr)
    {
        if(temp->data == input)
            return temp;
        temp=temp->next;
    }
}

void LinkedList::deleteKNode(Node* node)
{
    //Give access to only Kth node delete that Kth node. Have access to the forward node but not the previous
    
    if(node->next == NULL)
        return;
    
    Node* newnode = node->next;
    node->data = newnode->data;
    node->next = newnode->next;
    delete newnode;
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
    cout<<endl<<"Delete node with data =3 without access to previous node"<<endl;
    Node* node = list->returnNode(3);
    list->deleteKNode(node);
    list->print();
    
    return 0;
}
