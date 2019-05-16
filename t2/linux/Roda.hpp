#ifndef RODA_H
#define RODA_H

#include "Point.hpp"
#include <vector>

#pragma once

class Roda{
    private:
        Point * org;
        std::vector<Point *> raios; 
        
    public:
        Roda(Point * origem);
        void render();
        ~Roda();
};

#endif