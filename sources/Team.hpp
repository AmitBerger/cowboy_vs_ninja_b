#ifndef TEAM_HPP
#define TEAM_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>

namespace ariel {

class Team {
private:
  Character *leader;
  std::vector<Character *> fighters;

public:
  Team(Character *leader);
  ~Team();

  void add(Character *fighter);
  void attack(Team *enemy);
  int stillAlive() const;
  virtual string print();
  Character *findClosestLivingCharacter(const Character *attacker) const;
};

} // namespace ariel

#endif // TEAM_HPP
