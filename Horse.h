#include "Org.h"
#include "emp/math/Random.hpp"
#include "emp/tools/string_utils.hpp"

#ifndef HORSE_H
#define HORSE_H

class Horse : public Organism {

    public:
    Horse(emp::Ptr<emp::Random> _random, double _points=0.0, std::string _color="red") :
        Organism(_random, _points, _color) {;}

    emp::Ptr<Organism> Clone() const {
        return emp::NewPtr<Horse>(*this);
    }

    std::string GetType() {
        return "Horse";
    }

    emp::Ptr<Organism> CheckReproduction() {
        if (GetPoints() >= 400) {
            emp::Ptr<Horse> offspring = new Horse(*this);
            offspring->SetPoints(0);
            AddPoints(-400);
            return offspring;
        } else {
            return nullptr;
        }
    }
};

#endif