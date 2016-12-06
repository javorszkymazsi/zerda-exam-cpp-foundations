#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_

#include <iostream>
#include "util.h"

class Aircraft {
public:
  Aircraft();
  void refill_aircraft(int& ammo_storage);
  int fight();
  int set_ammo_to_max();
  std::string get_aircraft_type();
  std::string get_status();
  void set_aircraft_firepower_to_zero();
  int get_aircraft_firepower();
  ~Aircraft();
protected:
  std::string aircraft_type;
  int max_ammo;
  int base_damage;
  int aircraft_firepower;
private:
  int ammo_count;
};

#endif /* AIRCRAFT_H_ */
