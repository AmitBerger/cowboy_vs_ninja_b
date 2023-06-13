#include "Character.hpp"
using namespace ariel;

Ninja::Ninja(const Point &location, int hitPoints, const std::string &name,
             int speed)
    : Character(location, hitPoints, name), speed(speed) {}

void Ninja::move(Character *enemy) {
  if (isAlive()) {
    Point destination = enemy->getLocation();
    location = location.moveTowards(location, destination, speed);
  }
}

void Ninja::slash(Character *enemy) {
  if (isAlive() && distance(enemy) <= 1) {
    enemy->hit(40);
  }
}

string Ninja::print() const{
    string str = "N Name: ";
    if (isAlive()){
       str += this->getName() + "\nHit Points: " + to_string(this->hitPoints);
    }
    else{
        str += "(" + this->getName() + ")";
    }
    str += "\n" + getLocation().print() +"\n";
    cout<<str<<endl;
    return str;
}