#ifndef WORLD_H
#define WORLD_H

#include "emp/Evolve/World.hpp"
#include "emp/math/random_utils.hpp"
#include "emp/math/Random.hpp"
#include <typeinfo>

#include "Org.h"
#include "Cow.h"
#include "Horse.h"

class OrgWorld : public emp::World<Organism> {

    emp::Random &random;
    emp::Ptr<emp::Random> random_ptr;
    int numCows = 0;
    int numHorses = 0;

    public:

    OrgWorld(emp::Random &_random) : emp::World<Organism>(_random), random(_random) {
        random_ptr.New(_random);
    }

    ~OrgWorld() {
    }

    int GetNumCows() {
        return numCows;
    }

    void addNumCows(int num) {
        numCows += num;
    }

    int GetNumHorses() {
        return numHorses;
    }

    void addNumHorses(int num) {
        numHorses += num;
    }

    emp::vector<emp::Ptr<Organism>> getPop() {
        return pop;
    }

    emp::Ptr<Organism> ExtractOrganism(int i) {
        emp::Ptr<Organism> extOrg = pop[i];
        pop[i] = nullptr;
        return extOrg;
    }

  void Update() {
      emp::World<Organism>::Update();

      emp::vector<size_t> schedule = emp::GetPermutation(random, GetSize());
      for (int i : schedule) {
          if (!IsOccupied(i)) {continue;}
            else {
                pop[i]->Process(100);
            }
      }

      emp::vector<size_t> schedule_rep = emp::GetPermutation(random, GetSize());
      for (int i : schedule_rep) {
        if (!IsOccupied(i)) {continue;}
        else {
            emp::Ptr<Organism> offspring = pop[i]->CheckReproduction();
            if (offspring != nullptr) {
                AddOrgAt(offspring, GetRandomNeighborPos(i));
            }
        }
      }

      emp::vector<size_t> schedule_move = emp::GetPermutation(random, GetSize());
      for (int i : schedule_move) {
        if (!IsOccupied(i)) {
            continue;
        }
        else {
            emp::Ptr<Organism> extOrg = ExtractOrganism(i);
            if (extOrg == nullptr) {
                std::cerr << "Error: ExtractOrganism returned nullptr at index " << i << std::endl;
                continue;
            }
            AddOrgAt(extOrg, GetRandomNeighborPos(i));
        }
      }
    }
};

#endif