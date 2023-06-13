#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Character.hpp"
#include "Team.hpp"
#include <vector>

namespace ariel {

class Team2 : public Team {
private:
  std::vector<Character *> fighters;

public:
  Team2();
  Team2(Character *leader);
  Team2(const Team2 &other);
  ~Team2();

  void add(Character *fighter);
  void attack(Team *enemy);
  int stillAlive() const;
  string print() override;
  Character *findClosestLivingCharacter(const Character *attacker) const;
};

} // namespace ariel

#endif // TEAM2_HPP
