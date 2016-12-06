#ifndef CARRIER_H_
#define CARRIER_H_

#include <vector>
#include "F16.h"
#include "F35.h"
#include "util.h"

class Carrier {
public:
  Carrier(int initial_ammo, int initial_health_point);
  void add_aircraft(std::string aircraft_name);
  void refill_all_aircrafts() throw (const char*);
  int fight(Carrier& fired_upon_carrier);
  void subtract_health_point(int amount);
  int get_ammo_storage();
  bool is_health_point_zero();
  void add_to_aircraft_pointer(Aircraft& aircraft);
  int get_all_aircraft_firepower();
  std::string get_all_aircraft_stats();
  std::string get_status();
  ~Carrier();
private:
  std::vector<Aircraft> aircrafts;
  Aircraft** aircraft_pointers;
  int aircraft_count;
  int ammo_storage;
  int health_point;
};

#endif /* CARRIER_H_ */
