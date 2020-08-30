//============================================================================
// Name        : p4.cpp
// Author      : ibrahim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cmath>
#include<math.h>
#include<string.h>
#include <cstring>
#include<cstdlib>
#include<stdio.h>
#include"queue.h"

using namespace std;

int main(int argc , char *argv[])
{
	queue<int> qu;
	int el;
	bool check = true;
	bool e1=false,e2=false,e3=false,e4=false;
	if(argc<=4)
	{
		cout<<"Invalid number of arguments ";
		//return false;
		check=false;
	}
	for(int i=1;i<argc;i++)
	{
		for(unsigned int j=0;j<strlen(argv[i]);j++)
		{
			if((argv[i][j]>=48)&&(argv[i][j]<=57))
			{
				//cout<<argv[i][j];
				if((i==1)&&(e1==false))
				{
					if((argv[i][j]==48))
					{
						cout<<"Invalid seqNumBits ";
						e1=true;
						check=false;
					}
				}
				if((i==2)&&(e4==false))
				{
					int f=atoi(argv[i-1])-1;
					int g=atoi(argv[i]);
					if((argv[i][j]==48))
					{
						cout<<"Invalid winSize ";
						e4=true;
						check=false;
					}
					else if((g>qu.my_pow(2,f))&&(e1==false))
					{
						cout<<"Invalid winSize ";
						e4=true;
					    check=false;
					}
				}
				if((i==3)&&(e2==false))
				{
					int f=atoi(argv[1]);
					int g=atoi(argv[i]);
					if((g>qu.my_pow(2,f)-1)&&(e1==false))
					{
						cout<<"Invalid initSeq ";
						e2=true;
					    check=false;
					}
				}
				if((i>3)&&(e3==false))
				{
					int f=atoi(argv[1]);
					int g=atoi(argv[i]);
					if((g>qu.my_pow(2,f)-1)&&(e1==false))
					{
						cout<<"Invalid packet ID ";
						e3=true;
					    check=false;
					}
				}
				continue;
			}
			//i am using error handling
			else if((i==1)&&(e1==false))//if Invalid seqNumBits
			{
				cout<<"Invalid seqNumBits ";
				e1=true;
				check=false;
				//return 0;
			}
			else if((i==3)&&(e2==false))
			{
				cout<<"Invalid initSeq ";
				e2=true;
				check=false;
				//return 0;
			}
			else if((i==2)&&(e4==false))
			{
				cout<<"Invalid winSize ";
				e4=true;
				check=false;
			}
			else if((e3==false)&&(i>3))
			{
				cout<<"Invalid packet ID ";
				e3=true;
				check=false;
				//return 0;
			}

		}
	}
	if (!check)
	{
		cout<<endl;
		return 0;
	}
	for(int i=1;i<argc;i++)
	{
			el = atoi(argv[i]);
			qu.fill_pr(el,0);
			//cout<<el<<endl;
			//qu.algrothim_1();
			//qu.algrothim_2();
	}
	if(qu.algrothim_1())
	{
		qu.algrothim_2();
	}
	return 0;
}
