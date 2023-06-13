#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/Team.hpp"
#include <cmath>
#include <iostream>

using namespace ariel;
using namespace std;
TEST_CASE(" characters"){
    Point a(33, 14), b(66, 76);
    CHECK_NOTHROW(new Cowboy("aa", a));
    CHECK_NOTHROW(new OldNinja("bb", b));
    CHECK_NOTHROW(new YoungNinja("cc", Point(1, 1)));
    CHECK_NOTHROW(new TrainedNinja("dd", Point(2, 2)));
}

TEST_CASE("Test Character") {
  Point loc(13, 10);
  Character *character1 = new YoungNinja("BB", loc);
  CHECK(character1->isAlive() == true);
  character1->hit(150);
  CHECK(character1->isAlive() == false);
  delete character1;
  Character *character2 = new Cowboy("TIBI", loc);
  CHECK(character2->isAlive() == true);
  character2->hit(110);
  CHECK(character2->isAlive() == false);
  delete character2;
}

TEST_CASE("Test Point") {
  Point a(1, 1);
  Point b(3, 4);
  CHECK(a.distance(b) == doctest::Approx(4.0));
  CHECK(b.distance(a) == doctest::Approx(4.0));
}
TEST_CASE("Ninja") {
  Point loc(1, 1);
  Ninja *ninja = new YoungNinja("Ninja", loc);
  CHECK(ninja->isAlive() == true);
  ninja->hit(100);
  CHECK(ninja->isAlive() == false);
  delete ninja;
}
TEST_CASE(" Cowboy") {
  Point loc(1, 1);
  Cowboy *cowboy = new Cowboy("BB", loc);
  Ninja *ninja = new OldNinja("TIBI", Point(1, 1));
  CHECK(cowboy->hasboolets() == true);
  cowboy->shoot(ninja);
  CHECK(cowboy->hasboolets() == true);
  delete cowboy;
}
TEST_CASE("reloading") {
  Point loc(1, 1);
  Cowboy *cowboy = new Cowboy("jon", loc);
  for (int i = 0; i < 6; i++) {
    CHECK(cowboy->hasboolets() == true);
    cowboy->shoot(new OldNinja("samu", Point(5, 5)));
  }
  CHECK(cowboy->hasboolets() == false);
  cowboy->reload();
  CHECK(cowboy->hasboolets() == true);
  delete cowboy;
}

TEST_CASE("Team") {
  Point loc(1, 1);
  Character *leader = new Cowboy("jack", loc);
  Team team(leader);
  CHECK(team.stillAlive() == 1);
  team.add(new TrainedNinja("grilish", Point(2, 2)));
  CHECK(team.stillAlive() == 2);
}

TEST_CASE(" Old ninja") {
  OldNinja ninja{"ON", Point{1, 5}};

  CHECK_EQ(ninja.getName(), "ON");
  CHECK_EQ(ninja.getLocation().distance(Point{2, 8}), 0);
  CHECK(ninja.getLocation().print() == "4 , 5.00");
  CHECK_NE(ninja.getLocation().distance(Point{3, 2}), 0);

  CHECK(ninja.isAlive());
}

TEST_CASE("Ninja slas") {
  Point loc1(1, 1);
  Point loc2(2, 2);
  Cowboy *cowboy = new Cowboy("sami", loc1);
  Ninja *ninja = new YoungNinja("Hacabai", loc2);
  CHECK(cowboy->isAlive() == true);
  ninja->slash(cowboy);
  CHECK(cowboy->isAlive() == false);
  delete cowboy;
  delete ninja;
}

TEST_CASE("print") {
  Point loc(0, 1);
  Character *leader = new Cowboy("mami", loc);
  Team team(leader);
  team.print();
}