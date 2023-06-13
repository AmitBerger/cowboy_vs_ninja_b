#include "Character.hpp"

namespace ariel {

    Character::Character(const Point& location, int hitPoints, const std::string& name)
        : location(location), hitPoints(hitPoints), name(name) {}

    bool Character::isAlive() const {
        return hitPoints > 0;
    }

    double Character::distance(const Character* other) const {
        double dx = location.getX() - other->location.getX();
        double dy = location.getY() - other->location.getY();
        return std::sqrt(dx * dx + dy * dy);
    }

    void Character::hit(int amount) {
        hitPoints -= amount;
        if (hitPoints < 0) {
            hitPoints = 0;
        }
    }

    const std::string& Character::getName() const {
        return name;
    }

    const Point& Character::getLocation() const {
        return location;
    }

} // namespace ariel
