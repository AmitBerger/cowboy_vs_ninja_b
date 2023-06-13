#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP


#include "Character.hpp"

namespace ariel {

    class YoungNinja : public Ninja {
    public:
        YoungNinja( const std::string& name,const Point& location);
        virtual ~YoungNinja() {}

        
    };

} // namespace ariel

#endif // YOUNGNINJA_HPP
