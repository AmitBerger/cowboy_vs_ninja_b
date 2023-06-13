#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>

namespace ariel {

class Character {
protected:
  Point location;
  int hitPoints;
  std::string name;

public:
  Character(const Point &location, int hitPoints, const std::string &name);
  virtual ~Character() {}

  bool isAlive() const;
  double distance(const Character *other) const;
  void hit(int amount);
  const std::string &getName() const;
  const Point &getLocation() const;
  virtual string print() const = 0;
};
class Ninja : public Character {
protected:
  int speed;

public:
  Ninja(const Point &location, int hitPoints, const std::string &name,
        int speed);

  void move(Character *enemy);
  string print() const override;

  void slash(Character *enemy);
};

} // namespace ariel

#endif // CHARACTER_HPP
