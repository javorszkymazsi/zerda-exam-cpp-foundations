#include "Aircraft.h"

Aircraft::Aircraft() {
  this->ammo_count = 0;
  this->max_ammo = 0;
  this->aircraft_type = "valami";
  this->base_damage = 23;
}

std::string Aircraft::get_aircraft_type() {
  return aircraft_type;
}

//TODO All damage
std::string Aircraft::get_status() {
  return "Type: " + aircraft_type + ", Ammo: " + to_string(ammo_count) + ", Base Damage: " + to_string(base_damage) + ", All Damage: \n";
}

std::string Aircraft::to_string(int number) {
  std::stringstream ss;
  ss << number;
  std::string str;
  ss >> str;
  return str;
}

Aircraft::~Aircraft() {
  // TODO Auto-generated destructor stub
}
