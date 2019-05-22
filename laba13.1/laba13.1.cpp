#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib> 
using namespace std;

struct list{
	int info;
	list *prev, *next;
};

void init(list ** b, list** e, int in)
{
	list *t = new list;
	t->info = in;
	t->next = NULL;
	if (*b == NULL)
	{
		*b = *e = t;
	}
	else
	{
		(*e)->next = t;
		*e = t;
	}
}

list* add_beg(list* &v, int in)
{
	list *t = new list;
	t->info = in;
	t->next = v;
	t->prev = NULL;
	v->prev = t;
	return t;
}
list* add_end(list* &v, int in)
{
	list *t = new list;
	t->info = in;
	t->next = NULL;
	t->prev = v;
	v->next = t;
	return t;
}
void view_beg(list* p)
{
	list* t = p;
	while (t != NULL)
	{
		cout << t->info << endl;
		t = t->next;
	}
}
void view_end(list* p)
{
	list* t = p;
	while (t != NULL)
	{
		cout << t->info << endl;
		t = t->prev;
	}
}
list* task(list* b, list* &e)
{
	list* t1 = b;
	list* t2 = b->next;

	while (t2->next != NULL)
	{
		t1->next = t2->next;
		t2->next->prev = t1;
		t1 = t2->next;
		delete t2;
		if (t1->next != NULL)
		{
			t2 = t1->next;
		}
		else
		{
			e = t1;
			return b;
		}
		if (t2->next == NULL)
		{
			t1->next = t2->next;
			delete t2;
			e = t1;
			return b;
		}
	}
	return t2;
}


void dellist(list **b, list **e) {
	list *t = new list;
	while (b != NULL) {
		*b = t;
		*b = (*b)->next;
		delete t;
	}
}


int main()
{
	srand(time(0));
	list* begin_ = NULL;
	list* end_ = NULL;
	int opt;
	int opt_view = 1;
	while (true)
	{
		if (opt_view == 1)
		{
			view_beg(begin_);
		}
		else if (opt_view == 0)
		{
			view_end(end_);
		}
		cout << endl << "Enter 1 to fill up the list with random numbers" << endl <<
			"Enter 2 to delete every 2nd element from the list" << endl <<
			"Enter 3 to change view mode. Now is ";
		if (opt_view == 1)
		{
			cout << "from the begining" << endl;
		}
		else
		{
			cout << "from the end" << endl;
		}
		cout << "Enter 4 to exit" << endl << endl;
		cin >> opt;
		cout << endl;
		switch (opt)
		{
		case 1:
		{
			int size;
			cout << "Enter the list size" << endl;
			cin >> size;
			init(&begin_, &end_, rand());
			for (int i = 0; i < size - 1; i++)
			{
				begin_ = add_beg(begin_, rand());
			}
			break;
		}
		case 2:
		{
			system("cls");
			cout << "Old list" << endl;
			if (opt_view == 1)
			{
				view_beg(begin_);
			}
			else if (opt_view == 0)
			{
				view_end(end_);
			}
			cout << endl << "New list" << endl;
			begin_ = task(begin_, end_);
			if (opt_view == 1)
			{
				view_beg(begin_);
			}
			else if (opt_view == 0)
			{
				view_end(end_);
			}
			system("pause");
			break;
		}
		case 3:
		{
			if (opt_view == 1)
			{
				opt_view = 0;
			}
			else
			{
				opt_view = 1;
			}
			break;
		}
		case 4:
		{
			return 0;
		}
		}
		system("cls");
	}
	system("pause");
	return 0;
	dellist(&begin_, &end_);
}
