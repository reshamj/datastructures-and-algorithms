#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    Node* next;
    int data;
};


class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    void add(int data);
    void print();
    int deleteNode(int input);
    void removeDups();
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

void LinkedList::removeDups()
{
//to remove duplicate we make use of 2 hints.
//1. use the concept of hash map
//2. use two pointers to iterate over the link list while logining in key = (input) and value=  a trigger (1) to indicate already present 

if (head == nullptr || (head && (head->next == nullptr)))
	{
		return; //there is just one element in the list 
	}
//declare hash map structure
std::unordered_map<int, int> node_hash_map;

//use 2 pointers
Node* prev= head; 
Node* current= head->next;
    
//indicating tracked head node
node_hash_map[head->data]=1;
   
//now iterate 
while(current != nullptr)
    {
            while(current && node_hash_map.find(current->data)!= node_hash_map.end())
        {
            current = current->next;
        }
    prev->next = current;
    prev = current;
    if (current)
        {
            node_hash_map[current->data] =1;
            current = current->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    cout<<"Link list in c++" << endl;
    LinkedList* list = new LinkedList();
    for (int i = 0; i < 5; ++i)
    {
        list->add(i);
    }
    list->add(4);
    list->add(1);
    cout<<"link list :"<<endl;
    list->print();  
    cout<<endl<<"Removing duplicates"<<endl;
    list->removeDups();
    cout<<endl;
    list->print();
    
return 0;
}

