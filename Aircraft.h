#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_

#include <iostream>
#include <sstream>

class Aircraft {
public:
  Aircraft();
  std::string get_aircraft_type();
  std::string get_status();
  std::string to_string(int number);
  ~Aircraft();
private:
  std::string aircraft_type;
  int ammo_count;
  int max_ammo;
  int base_damage;
};

#endif /* AIRCRAFT_H_ */
