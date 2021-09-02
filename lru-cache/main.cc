#include "lru_cache.hh"

int main() {
        lru_cache cache(5);

        cache.set(1,10);
        cache.set(2,20);
        cache.set(3,30);
        cache.set(4,40);
        cache.set(5,50);
        cache.set(6,60);

        cout << endl;
        cache.print_cache();
        cache.print_queue();

        cache.set(5,500);
        cout << endl;
        cache.print_cache();
        cache.print_queue();

        cout << endl;
        cout << cache.get(5) << endl;
        cout << cache.get(1) << endl;

        return 0;
}
