#pragma once
#include <vector>
#include <iostream>
#include "Organizm.h"
class Swiat {
private:
    int N;
    int M;
    static int instance;
    
    std::vector<std::vector<Organizm*>> grid;

    Swiat();

    Swiat(const Swiat &other) = delete;
    void operator=(const Swiat &other) = delete;

public:
    ~Swiat();
    static Swiat* createSwiat();

    void setGrid(int n, int m);
    void paintGrid();
    
    int getGridN();
    int getGridM();
};