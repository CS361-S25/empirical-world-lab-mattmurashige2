#include "Org.h"
#include "emp/math/Random.hpp"
#include "emp/tools/string_utils.hpp"
#include <string>
#include "World.h"

#ifndef COW_H
#define COW_H


class Cow : public Organism {

    public:
    Cow(emp::Ptr<emp::Random> _random, double _points=0.0, std::string _color="green") :
        Organism(_random, _points, _color) {;}

    emp::Ptr<Organism> Clone() const {
        return emp::NewPtr<Cow>(*this);
    }

    std::string GetType() {
        return "Cow";
    }

    emp::Ptr<Organism> CheckReproduction() {
        if (GetPoints() >= 400) {
            emp::Ptr<Cow> offspring = new Cow(*this);
            offspring->SetPoints(0);
            AddPoints(-400);
            return offspring;
        } else {
            return nullptr;
        }
    }

};

#endif