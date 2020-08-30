/*
 * queue.h
 *
 *  Created on: May 5, 2020
 *      Author: ibrahim el sawy
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include<iostream>
#include<cmath>
#include<string.h>
#include <cstring>
#include<cstdlib>
#include<stdio.h>

using namespace std;
template <class queueElementType>
class queue{
public:
	queue();
	bool enqueue(const queueElementType &item);
	bool dequeue(queueElementType &item);
	bool search(queueElementType &item);
	int count_all();
	bool frontItem(queueElementType &item);
	bool isEmpty();
	bool algrothim_1();
	bool algrothim_2();
	void display();
	bool fill_pr(const queueElementType &item,int);
	bool search_arr(queueElementType &item);
	bool search_arr_D(queueElementType &item);
	int my_pow(int x,int & y);
	void which(int & ,int &);
	bool search_w(queueElementType &item);
	~queue();
private:
	struct Node;
	typedef Node * Link;
	struct Node {
		queueElementType data;
		Link next;
	};
	Link front;
	Link rear;
	int ex;
	int ex_2;
	int w[100];
	int D[100];
	int A[100];
	int index_A,index_D,index_W,window_size,max_no,intial;
};

template <class queueElementType>
queue<queueElementType>::queue(){
	front = NULL;
	rear  = NULL;
	ex = 0;
	ex_2=0;
	index_A =0;
	index_D =0;
	index_W =0;
	window_size=0;
	max_no=0;
	intial=0;
}

template <class queueElementType>
bool queue<queueElementType>::enqueue(const queueElementType &item){
	Link pred;
	Link addedNode = new Node;
	if(!addedNode){
		return false; // Heap is full
	}
	else{
		addedNode -> data = item;

		if (!front) {
			addedNode->next = front;
			front = addedNode;
			//cout<<front->data;
			return true;
		}

            pred = front;
            while (pred->next != 0) {
                pred = pred->next;
            }
            addedNode->next = pred->next;
            pred->next = addedNode;
           // cout<<front->data<<endl;
            return true;
        }

}

/*
 * 	else{
		addedNode -> data = item;

		if (!front||item<=front->data) {
			addedNode->next = front;
			front = addedNode;
			//cout<<front->data;
			return true;
		}
		else {
            pred = front;
            while (pred->next != 0 && pred->next->data < item) {
                pred = pred->next;
            }
            addedNode->next = pred->next;
            pred->next = addedNode;
           // cout<<front->data<<endl;
            return true;
        }
	}
 */

template <class queueElementType>
bool queue<queueElementType>::dequeue(queueElementType &item){
	if(!front){
		return false; // NO items in queue;
	}
	else{
		Link ptr = front;
		if (item==ptr->data){
		 //item = front -> data;
		front = front ->next;
		//cout<<item<<" ";
		delete ptr;
		if(!front){
			rear = 0;
		}
		return true;}
		else
		{
			return false;
		}
	}

}
template <class queueElementType>
bool queue<queueElementType>::frontItem(queueElementType &item){
	if(!front){
		return false; // NO items in queue;
	}
	else{
		item = front ->data;
		return true;
	}
}

template <class queueElementType>
bool queue<queueElementType>::isEmpty()
{
	return bool(front == 0);
}

template <class queueElementType>
queue<queueElementType>::~queue()
{
	queueElementType dummy;
	while(dequeue(dummy));
}

template <class queueElementType>
bool queue<queueElementType>::search(queueElementType &item)
{
	Link te;
	te=front;
	while (te!=0)
	{
		if (te->data==item)
		{
			return true;
		}
		te=te->next;
	}
	return false;
}



template <class queueElementType>
int queue<queueElementType>::count_all()
{
	Link te;
	int time=0;
	te=front;
	while (te!=0)
	{
		time++;
		te=te->next;
	}
	return time++;
}

template <class queueElementType>
bool queue<queueElementType>::fill_pr(const queueElementType &item,int type)//type=0-->>for A[]-----type=1-->>for D[]---type=2-> w]
{
	if(type==0)
	{
		if(index_A<100)
		{
			this->A[index_A]=item;
			index_A++;
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(type==1)
	{
		if(index_D<100)
		{
			this->D[index_D]=item;
			index_D++;
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(type==2)
	{
		if(index_W<100)
		{
			this->w[index_W]=item;
			index_W++;
			return true;
		}
		else
		{
			return false;
		}
	}
	return true;
}
template <class queueElementType>
int queue<queueElementType>::my_pow(int x,int & y)
{
	int ans=1;
    for(int i=0; i<y; i++)
      ans *= x;
    return ans;
}


template <class queueElementType>
bool queue<queueElementType>::algrothim_1()
{
	int i=0;
	int enter=0;
	int x = A[0]-1;
	x = my_pow(2,x);
	int y = my_pow(2,A[0]);
	//this->window_size = x;-------------edit-------------
	x = A[1];
	//this->window_size=my_pow(2,x);
	this->window_size = A[1];
	this->max_no = y-1;
	ex = A[2];
	this->intial=ex;
	i=3;
	/*if(window_size==A[1])--------edit---------
	{
		this->ex=A[2];
		this->intial=ex;
		i=3;
	}
	else
	{
		this->ex=A[1];
		this->intial=ex;
		i=2;
	}*/
	for(;i<index_A;i++)
	{
		if(A[i]>max_no)
		{
			cout<<"Invalid Packet ID"<<endl;
			return false;
		}
		if((A[i]==ex))//||(A[i]==intial-1)*************edit
		{
			this->enqueue(A[i]);
			if(this->search_arr_D(A[i]))
			{
				this->fill_pr(A[i],1);
			}
			ex++;
			if(ex>max_no)
			{
				ex=0;//***************************************edit*******
			}
		}
		else
		{
			this->fill_pr(A[i],1);
			if(enter==0)
			{
				this->ex_2=ex;

			}
			enter=1;
		}
	}
	/*Link k=front;
	cout<<"priority_queue"<<endl;
	while(k!=NULL)
	{
		cout<<k->data<<endl;
		k=k->next;
	}
	cout<<"drop_list"<<endl;
	for(int z =0;z<index_D;z++)
	{
		cout<<D[z]<<endl;
	}*/
	return true;
}

template <class queueElementType>
bool queue<queueElementType>::algrothim_2()
{
	int max,min;
	if(ex>max_no)
	{
		ex=0;
	}
	//int ex_1=this->ex_2;//editt--ex_1=ex***********************
	while((this->search_arr_D(ex)))
	{
			this->enqueue(ex);
			ex++;
			if(ex>max_no)
			{
				ex=0;
			}
	}
	int ex_1=this->ex;
	for(int i=0;i<index_D;i++)
	{
		//if((D[i]==ex))
		/*if((this->search_arr_D(ex)))
		{
			//return some elements to queue
			this->enqueue(ex);
			//cout<<ex<<"   "<<D[i]<<endl;
			//D[i]=max_no + 1;
			ex++;
		}*/
	    /*if((D[i]>ex_1)||(D[i]<intial))
		{*/
			if((D[i]>ex_1)&&(D[i]<=max_no))
			{
				//if((max_no-window_size+ex_1>=D[i])&&(D[i]<=max_no))
				if((D[i]>ex_1)&&(D[i]<ex_1+window_size))
				{
					//waited<----A[i]
					if(!(this->search_w(D[i])))
					{
						this->w[index_W]=D[i];
						D[i]=max_no + 20;
						index_W++;
					}
					//this->w[index_W]=D[i];
					//D[i]=max_no + 20;
					//index_W++;
				}
			}
			else if((D[i]>=0)&&(D[i]<=max_no))
			{
				min=ex_1;
				max=ex_1+window_size;
				//if((ex_1-window_size-1>=D[i])&&(D[i]<=max_no))
				if((D[i]+max_no+1>min)&&(D[i]+max_no+1<max))
				{
					//A[i]--->waited
					if(!(this->search_w(D[i])))
					{
						this->w[index_W]=D[i];
						D[i]=max_no + 20;
						index_W++;
					}

				}
			}
		//}

	}
	this->display();
	return true;
}

template <class queueElementType>
void queue<queueElementType>::display()
{
	cout<<"R ";
	Link temp=front;
	int min;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"E "<<ex<<" ";
	cout<<"W ";
	min=this->ex;
	int k=0;
	//for(int k=0;k<index_W;k++)
	while(k<index_W)
	{
		//cout<<w[k]<<" ";
		if(this->search_w(min))
		{
			cout<<min<<" ";
			k++;
		}
		min++;
		if(min>this->max_no)
		{
			min=0;
		}
	}
	cout<<"D ";
	for(int k=0;k<index_D;k++)
	{
		/*if(this->search_arr(D[k]))
		{
			cout<<D[k]<<" ";
		}
		else
			continue;*/
		if(D[k]<=max_no)
		{
			cout<<D[k]<<" ";
		}
		else
			continue;
	}
	cout<<endl;
}

template <class queueElementType>
bool queue<queueElementType>::search_arr(queueElementType &item)
{
	Link temp = front;
	while(temp!=NULL)
	{
		if(temp->data==item)
		{
			return false;
		}
		temp = temp->next;
	}
	for(int i =0;i<index_W;i++)
	{
		if(w[i]==item)
		{
			return false;
		}
	}
	return true;
}

template <class queueElementType>
bool queue<queueElementType>::search_w(queueElementType &item)
{
	for(int i =0;i<index_W;i++)
		{
			if(w[i]==item)
			{
				return true;
			}
		}
		return false;
}

template <class queueElementType>
bool queue<queueElementType>::search_arr_D(queueElementType &item)
{
	for(int i =0;i<index_D;i++)
	{
		if(D[i]==item)
		{
			D[i] = max_no + 10;
			return true;
		}
	}
	return false;
}
template <class queueElementType>
void queue<queueElementType>::which(int & min,int & max)
{
	int i =0;
	min = this->w[0];
	max=  this->w[0];
	for(;i<index_W;i++)
	{
		if(min>(this->w[i]))
		{
			min=this->w[i];
		}
		if(max<(this->w[i]))
		{
			max=this->w[i];
		}
	}
}

#endif /* QUEUE_H_ */
