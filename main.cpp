#include <iostream>
#include "doublesidequeue.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    DoubleSideQueue<char> queue_1;
    queue_1.print();
    cout<<"\n\n";
    queue_1.pushBack('A');
    queue_1.pushBack('B');
    queue_1.pushFront('C');
    queue_1.print();
    cout<<"\n\nFront: " << queue_1.topFront()<< "\tBack: "<<queue_1.topBack()<<"\n\n";
    queue_1.popBack();
    queue_1.print();
    cout<<"\n\n";
    queue_1.popFront();
    queue_1.print();
    cout<<"\n\n";

    DoubleSideQueue<char> queue_2(queue_1);
    queue_2.print();
    cout<<"\n\n";
    queue_2.clear();
    queue_2.print();
    cout<<"\n\n";
    queue_2 = queue_1;
    queue_2.print();
    return 0;
}
