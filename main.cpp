#include <iostream>
#include "linkedList.h"
#include "orderedLinkedList.h"
//#include "unorderedLinkedList.h"
using namespace std;

int main()
{

nodeType <int> newNode;

linkedListIterator <int>itr1;
//   class orderedLinkedList: public linkedListType<int>;
  unorderedLinkedList<int> linkedList;

    linkedList.initializeList();

    linkedList.insertFirst(44);
    linkedList.insertFirst(45);
    linkedList.insertFirst(3);
    linkedList.insertFirst(46);
    linkedList.insertFirst(3);
    linkedList.insertFirst(47);

    linkedList.print();
linkedList.deleteAt(90);
    //cout << "at index: " <<linkedList.deleteAt(3) << endl;
    cout << endl;
     cout << "2nd print:";
     linkedList.print();
    return 0;
}
