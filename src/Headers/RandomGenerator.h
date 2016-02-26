#pragma once
#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <random>
#include <iostream>
#include <chrono>

class CRandomGenerator
{
    private:
        std::mt19937 random;
    public:
        CRandomGenerator();
        ~CRandomGenerator();
        unsigned int GetRandomNumber();
        unsigned int GetRandomBetween(unsigned int min, unsigned int max);
        
};


#endif