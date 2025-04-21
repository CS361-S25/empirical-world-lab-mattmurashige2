#ifndef ORG_H
#define ORG_H

#include "emp/math/Random.hpp"
#include "emp/tools/string_utils.hpp"
#include <string>

class Organism {
    private:
        double points;
        emp::Ptr<emp::Random> random;
        std::string color;

    public:
    Organism(emp::Ptr<emp::Random> _random, double _points=0.0, std::string _color="black") :
        points(_points), random(_random), color(_color) {;}

    int GetPoints() {return points;}
    void SetPoints(double _in) {points = _in;}
    void AddPoints(double _in) {points += _in;}
    std::string GetColor() {return color;}

    void Process(int points) {
        this->points += points;
    }

    virtual emp::Ptr<Organism> Clone() const {
        return emp::NewPtr<Organism>(*this);
    }

    virtual std::string getColor() {return color;}

    virtual emp::Ptr<Organism> CheckReproduction() {
        return nullptr;
    }

    virtual std::string GetType() {
        return "Organism";
    }

};
#endif