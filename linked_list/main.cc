#include "linked_list.hh"

int main() {
        list l;
        l.push_back(20);
        l.push_back(30);
        l.push_back(40);
        l.push_back(50);
        l.push_back(60);
        l.push_back(70);

        l.push_front(10);
        l.push_back(80);

        l.print();

        cout << endl;
        l.revert();
        l.print();

        cout << endl;
        l.pop_front();
        l.pop_back();
        l.pop_back();
        l.print();

        cout << endl;
        l.insert(6, 20);
        l.insert(7, 15);
        l.insert(8, 10);
        l.insert(9, 0);
        l.insert(3, 55);
        l.insert(1, 80);
        l.pop_back();
        l.print();
        return 0;
}
