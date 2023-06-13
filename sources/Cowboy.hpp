#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

namespace ariel {

    class Cowboy : public Character {
    private:
        int bullets;

    public:
        Cowboy( const std::string& name,const Point& location);
        virtual ~Cowboy() {}

        bool hasboolets() const;
        void reload();
        void shoot(Character* enemy);

         string print() const override;
    };

} // namespace ariel

#endif // COWBOY_HPP
