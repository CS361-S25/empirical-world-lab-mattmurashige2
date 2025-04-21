#include <iostream>
#include "Org.h"
#include "emp/base/vector.hpp"
#include "emp/math/random_utils.hpp"
#include "emp/math/Random.hpp"
#include "World.h"
#include "Cow.h"
#include "Horse.h"

// This is the main function for the NATIVE version of this project.

int main(int argc, char* argv[])
{
  emp::Random random(2);
  OrgWorld world(random);
  Cow* my_cow = new Cow(&random, 0);
  Horse* my_horse = new Horse(&random, 0);

  world.AddOrgAt(my_cow, 0);
  world.AddOrgAt(my_horse, 1);

  world.Resize(10, 10);

  for (int i = 0; i < 25; i++) {
    world.Update();
  }

  std::cout << world.GetNumOrgs() << std::endl;
 
}
