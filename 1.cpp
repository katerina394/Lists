// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "conio.h"
#include "iostream"
using namespace std;

struct list{
		char c;
		list *next;
	};

bool isCorrect(char *string)
{
	list *b;
	list *tmp;
	bool f=false;
	if ((string[0]==')')||(string[0]=='}')||(string[0]==']'))
		return false;
	b=new list;
	b->c=string[0];
	for (int i=1; string[i]!='\0'; i++)
		if ((string[i]=='(')||(string[i]=='{')||(string[i]=='['))
		{ tmp=new list; tmp->c=string[i]; tmp->next=b; b=tmp; }
		else
		{
			f=true;
			if (string[i]==')')
				if (b->c=='(')
				{tmp=b; b=b->next; delete tmp;}
				else
					return false;
			if (string[i]=='}')
                if (b->c=='{')
				{tmp=b; b=b->next; delete tmp;}
				else
					return false;
			if (string[i]==']')
                if (b->c=='[')
				{tmp=b; b=b->next; delete tmp;}
				else
					return false;
		}
	return f;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *s1="(({}))";
	char *s2="{{{)))";
	char *s3=")(){}{";
	char *s4="[](){}";
	char *s5="([]){}";
	char *s6="{{)[]{";
	char *s7="(({{[[";
	bool f;
	f=isCorrect(s1);
	cout<<f<<endl;
	f=isCorrect(s2);
	cout<<f<<endl;
	f=isCorrect(s3);
	cout<<f<<endl;
	f=isCorrect(s4);
	cout<<f<<endl;
	f=isCorrect(s5);
	cout<<f<<endl;
	f=isCorrect(s6);
	cout<<f<<endl;
	f=isCorrect(s7);
	cout<<f<<endl;
	_getch();
	return 0;
}

