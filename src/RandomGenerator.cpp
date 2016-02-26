#include "Headers/RandomGenerator.h"

CRandomGenerator::CRandomGenerator()
{
    this->random.seed(static_cast<int> (std::chrono::system_clock::now().time_since_epoch().count()));
    this->random.discard(1000);
}

CRandomGenerator::~CRandomGenerator()
{
    
}

unsigned int CRandomGenerator::GetRandomNumber()
{
    return this->random();
}

unsigned int CRandomGenerator::GetRandomBetween(unsigned int min, unsigned int max)
{
    std::uniform_int_distribution<int> uni(min,max);
    return uni(this->random);
}