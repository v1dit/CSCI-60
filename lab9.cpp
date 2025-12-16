#include <iostream>

#include "node.h"

using namespace std;

int main()

{
1.  node *head = new node(4, nullptr);
2.  node *tail(head);
3.  node *temp
4.  temp = new node(1, nullptr);
5.  tail->set_link(temp);
6.  tail = temp;
7.  head = new node(1, head);
8.  head = new node(3, head);
9.  temp = new node(5, nullptr);
10. tail->set_link(temp);
11. tail = temp;

12. for (const node *p = head; p != nullptr; p = p->link())
13.      cout << p->data() << " ";
14. cout << endl;
15. return 0;
}