#include "HSubject.h"




void HSubject::printS(string subject)
{
	

	int indexToPrint  = this->search(subject);
	if (indexToPrint == -1)
	{
		cout << "ERROR" << endl;
		return;
	}
	typename list<Item<string,list<string> > >::iterator it = this->table->begin();
	advance(it, indexToPrint);
	typename list<string >::iterator iteratorData = (*it).data.begin();
	while (iteratorData != (*it).data.end())
	{
		cout << (*iteratorData) << " ";
		iteratorData++;
	}
	cout << endl;

}

void HSubject::addSubjectAndTitle(string subject, string title)
{
	int indexToPrint = this->search(subject);
	if (indexToPrint != -1)
	{
		typename list<Item<string,list<string> > >::iterator  it = this->table->begin();
		advance(it, indexToPrint);
		(*it).data.push_front(title);
		return;
	}
	list<string> newList;
	newList.push_front(title);
	this->insert(subject, newList);
}

void HSubject::printN(string subject, int n)
{
	int indexToPrint = this->search(subject);
	if (indexToPrint != -1)
	{

		typename list<Item<string,list<string> > >::iterator it = this->table->begin();
		advance(it, indexToPrint);
		typename list<string >::iterator  iteratorData = (*it).data.begin();
		int count = 0;
		while (((iteratorData) != (*it).data.end()) && (count < n))
		{
			cout << (*iteratorData) << "  ";
			count++;
			iteratorData++;
		}
		cout << endl;


	}
	else
		cout << "ERROR" << endl;



}

void HSubject::startNewTable()
{
	typename list<Item<string,list<string> > >::iterator it = this->table->begin();
	while ((it) != this->table->end())
	{
		Item<string, list<string> >* newItem = new Item<string, list<string> >();
		(*it) = *newItem;
		it++;
	}
	

		
}

void HSubject::print()
{
	
	typename list<Item<string,list<string> > >::iterator it = this->table->begin();
	while ((it) != this->table->end())
	{
		if ((*it).flag == full)
		{
			cout << (*it).key << ": ";
				typename list<string >::iterator iteratorData = (*it).data.begin();
			while (iteratorData != (*it).data.end())
			{
				cout << (*iteratorData) << " ";
				iteratorData++;
			}
		}
		it++;
	}
	cout << endl;
}

int HSubject::h1(string title)
{
	int key = 0;
	for (int i = 0; i < title.length(); i++)
	{
		key += (int)title.at(i);
	}
	return (key % this->size);
}

int HSubject::h2(string title)
{
	double a = 0.6;
	int key = 0;
	for (int i = 0; i < title.length(); i++)
	{
		key += (int)title.at(i);
	}
	return (int)(this->size * (key * a));
}
