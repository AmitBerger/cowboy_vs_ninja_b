#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP


#include "Character.hpp"

namespace ariel {

    class TrainedNinja : public Ninja {
    public:
        TrainedNinja( const std::string& name,const Point& location);
        virtual ~TrainedNinja() {}

        
    };

} // namespace ariel

#endif // TRAINEDNINJA_HPP
