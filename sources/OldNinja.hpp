#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Character.hpp"

namespace ariel {

class OldNinja : public Ninja {
public:
  OldNinja(const std::string &name, const Point &location);
  virtual ~OldNinja() {}

  
};

} // namespace ariel

#endif // OLDNINJA_HPP
