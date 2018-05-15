#include <iostream>
using namespace std;
#include "list.h"

list::list ()
{
  head = NULL;
  current = NULL;
}

list::~list ()
{
  while (head)
    {
      node *t = head->next;
      delete head;
      head = t;
    };
}

void
list::insert (int a)
{
  node *t = new node;
  t->next = head;
  head = t;
  head->val = a;
}

void
list::goToHead ()
{
  current = head;
}

int
list::getCurrentData ()
{
  return current->val;
}

void
list::advance ()
{
  current = current->next;
}

bool
list::moreData ()
{
  if (current)
    return true;
  else
    return false;
}

list::list (const list & l)
{
  current=NULL;
  node *src, **dst;
  head = NULL;
  src = l.head;
  dst = &head;
  while (src)
    {
      *dst = new node;
      (*dst)->val = src->val;
      (*dst)->next = NULL;
      if(src==l.current)
        current=*dst;
      src = src->next;
      dst = &((*dst)->next);
    }
}

list & list::operator= (const list & l)
{	
	if (&l == this) {
        return *this;
    }
    
	current = nullptr;
	node* source = l.head;
	node** target = &head;


	while(source && (*target))
	{
		(*target) -> val = source -> val;
		if(source == l.current)
		{
			current = *target;
		}
		source = source -> next;
		target = &((*target) -> next);
	}

	while(*target)
	{
		node* temp = (*target) -> next;
		delete *target;
		*target = temp;
	}
	
	while(source)
	{
		*target = new node;
		(*target)->next = nullptr;
		
		(*target)->val = source -> val;
		
		if(source == l.current)
		{
			current = *target;
		}
		
		source = source->next;
		target = &((*target) -> next);
	}
	
	return *this;
}

void list::printCurrent(ostream & Out) {
    Out << "Current pointer: " << this -> current  << endl;
}

void list::printList(ostream & Out) 
{
    node* original = this->current;
    this->goToHead();
    Out << "list at address: " << this << " contains: ";
	Out << "list contains: ";
    while(this->current != nullptr) 
	{
        Out << this->current->val << " at address: " << this->current;
		Out << this->current->val<< "  ";
        if (this->moreData()) 
		{
            Out << ", ";
        }
        this->advance();
    }
    Out << "And current node is: " << original << endl;
    this->current = original;
}
