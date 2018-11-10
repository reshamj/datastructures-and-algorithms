 // Queue Data structure in C++
#include<iostream.h>

//Defining queue as a class

class MyQueue {
//define non-editable elements in private

	private : vector <int> queue_data;
		  int pointer;

//define functionality in public
	public: //Default constructor
		MyQueue()
		{	//data will always be enqueued the only way initialize this class is by assigining pointer =0
			pointer = 0;			
		}

		bool enQueue(int input)
		{
		     queue_data.push_back(input);
		     return true; //on success	
		}

		bool deQueue()
		{
		    if (isQueueEmpty ())
			{
				return false;			
			}		
		    pointer ++;
			return true;
		}
		
		bool isQueueEmpty()
		{
			return (pointer >= queue_data.size());
		}
};

int main()
{
//create object of class myqueue

MyQueue q;
q.enQueue(5);
q.enQueue(10);
q.enQueue(15);
q.deQueue();

if (!q.isQueueEmpty()){
cout<<q.front()<<endl;
}

return 0;
}
