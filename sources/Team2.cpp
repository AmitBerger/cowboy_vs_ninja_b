#include "Team2.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"

#include <limits>

namespace ariel {

Team2::Team2(Character *leader) : Team(leader) { fighters.push_back(leader); }

Team2::~Team2() {
  for (Character *fighter : fighters) {
    delete fighter;
  }
}

void Team2::add(Character *fighter) {
  if (fighters.size() >= 10) {
    throw std::runtime_error("Error- cannot add another warrior, the team "
                             "reached its maximum capacity");
  }
  if (fighter == nullptr) {
    throw std::invalid_argument("Error- got null warrior");
  }

  fighters.push_back(fighter);
}

void Team2::attack(Team *enemy) {
  Character *leader = findClosestLivingCharacter(nullptr);
  Character *victim = enemy->findClosestLivingCharacter(leader);
  while (leader && victim) {
    for (Character *fighter : fighters) {
      if (fighter->isAlive()) {
        Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
        if (cowboy) {
          if (cowboy->hasboolets()) {
            cowboy->shoot(victim);
          } else {
            cowboy->reload();
          }
        } else {
          Ninja *ninja = dynamic_cast<Ninja *>(fighter);
          if (ninja) {
            if (ninja->distance(victim) <= 1) {
              ninja->slash(victim);
            } else {
              ninja->move(victim);
            }
          }
        }
      }
    }

    leader = findClosestLivingCharacter(nullptr);
    if (!victim->isAlive()) {
      victim = enemy->findClosestLivingCharacter(leader);
    } else {
      break;
    }
  }
}

int Team2::stillAlive() const {
  int count = 0;
  for (Character *fighter : fighters) {
    if (fighter != nullptr && fighter->isAlive()) {
      count++;
    }
  }
  return count;
}

string Team2::print() {
  string str = "Team warriors:";
  cout << str << endl;
  for (Character *warrior : this->fighters) {
    if (dynamic_cast<Ninja *>(warrior) != nullptr) {
      str += "\n" + warrior->print();
    }
    if (dynamic_cast<Cowboy *>(warrior) != nullptr) {
      str += "\n" + warrior->print();
    }
  }
  return str;
}

Character *Team2::findClosestLivingCharacter(const Character *attacker) const {
  Character *closest = nullptr;
  double minDistance = std::numeric_limits<double>::max();

  for (Character *fighter : fighters) {
    if (fighter->isAlive()) {
      double distance = attacker ? attacker->distance(fighter) : 0;
      if (distance < minDistance) {
        closest = fighter;
        minDistance = distance;
      }
    }
  }

  return closest;
}

} // namespace ariel
