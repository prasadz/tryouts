#include<iostream>
#include<lookup_table.hh>
int main() {
        lookup_table lt;
        lt.set(1, 10);
        lt.set(2, 20);
        lt.set(3, 30);
        lt.set(4, 40);
        lt.set(5, 50);
        lt.set(6, 60);
        lt.set(7, 70);
        lt.set(8, 80);

        lt.print_index();
        lt.print_table();

        lt.delete_node(6);
        lt.print_table();
}
