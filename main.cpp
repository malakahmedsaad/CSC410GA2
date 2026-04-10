#include "genome.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));

    genome g;

    g.allocate(5);

    g.randomize();
    g.print();

    g.set_mRate(0.5);
    cout << "Mutation rate: " << g.get_mRate() << endl;

    cout << "\nBefore mutation:\n";
    g.print();

    g.mutate();

    cout << "\nAfter mutation:\n";
    g.print();

    Pixel p = {100, 150, 200};
    g.set_pixel(0, p);

    Pixel retrieved = g.get_pixel(0);
    cout << "Pixel 0: "
         << retrieved.red << ", "
         << retrieved.green << ", "
         << retrieved.blue << endl;

    Pixel target[5];
    for (int i = 0; i < 5; i++) {
        target[i].red = 0;
        target[i].green = 0;
        target[i].blue = 0;
    }

    double fitness = g.calculate_overall_fitness(target, 5);
    cout << "Overall fitness: " << fitness << endl;

    g.deallocate();

    return 0;
}