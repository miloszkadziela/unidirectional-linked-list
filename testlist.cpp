#include <iostream>
using namespace std;
#include "list.h"


void Printlist (list toPrint, ostream & Out) {
  int nextValue;
  Out << "Printing list contents: " << endl;
  toPrint.goToHead ();
  if (!toPrint.moreData ()) {
      Out << "list is empty" << endl;
      return;
    }
  while (toPrint.moreData ()) {
      nextValue = toPrint.getCurrentData ();
      Out << nextValue << " ";
      toPrint.advance ();
    }
  Out << endl;
}

int main ()
{	
	
	cout<< "Program Initialization\n";
	list l, l1, l2;

    l.insert(0);
    l.insert(1);
    l.insert(2);
	
	cout<< "Initial 3 element ";
	l.printList(cout);

    l1.insert(0);
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
	
	cout<< "Initial 4 element ";
	l1.printList(cout);

    l2.insert(0);
    l2.insert(1);
    l2.insert(2);
    l2.insert(3);
    l2.insert(4);
	
	cout<< "Initial 5 element ";
	l2.printList(cout);

	cout<< "Using the assignment function!\n";
	
	cout << "CHANGING THE CURRENT POINTER OF l\n";
	
	l1.goToHead();
	l1.advance();
	l1.printCurrent(cout);
    l = l1;
	l.printCurrent(cout);

    l2 = l;

	cout<< "New lists: \n";
	
    l.printList(cout);
    l1.printList(cout);
    l2.printList(cout);
	
	cout<<"\nTerminating Program\n";
  
  
}
