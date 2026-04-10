#ifndef GENOME_H
#define GENOME_H

// Simple Pixel structure
struct Pixel {
    int red;
    int green;
    int blue;
};

class genome {
public:
    genome();                 // constructor
    ~genome();                // destructor

    void allocate(int numGenes);
    void deallocate();
    void randomize();

    void set_red(int index, int value);
    void set_green(int index, int value);
    void set_blue(int index, int value);

    int get_red(int index);
    int get_green(int index);
    int get_blue(int index);

    void print();

      // NEW FUNCTIONS FOR GA2
    void set_mRate(double val);
    double get_mRate();

    void mutate_gene(int index);
    void mutate();

    double calculate_gene_fitness(int index, Pixel targetPixel);
    double calculate_overall_fitness(Pixel* target, int nPixels);

    void set_pixel(int index, Pixel newPixel);
    Pixel get_pixel(int index);

private:
    Pixel* genes;   // dynamic array of Pixels
    int nGenes;     // number of Pixels
};

#endif