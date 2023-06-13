#include "Cowboy.hpp"

namespace ariel {

    Cowboy::Cowboy( const std::string& name,const Point& location)
        : Character(location, 110, name), bullets(6) {}

    bool Cowboy::hasboolets() const {
        return bullets > 0;
    }

    void Cowboy::reload() {
        bullets = 6;
    }

    void Cowboy::shoot(Character* enemy) {
        if (isAlive() && enemy && enemy->isAlive() && bullets > 0) {
            enemy->hit(10);
            bullets--;
        }
    }

    string Cowboy::print() const{
    string str = "C Name: ";
    if (isAlive()){
       str += this->getName() + "\nHit Points: " + to_string(this->hitPoints);
    }
    else{
        str += "(" + this->getName() + ")";
    }
    str += "\n"+getLocation().print();
    cout<<str<<endl;
    return str;
}

} // namespace ariel
