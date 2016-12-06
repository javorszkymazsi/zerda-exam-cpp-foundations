#include "Carrier.h"


Carrier::Carrier(int initial_ammo, int initial_health_point) {
  this->aircraft_pointers = NULL;
  this->aircraft_count = 0;
  this->ammo_storage = initial_ammo;
  this->health_point = initial_health_point;
}

void Carrier::add_aircraft(std::string aircraft_name) {
  ++aircraft_count;
  if (aircraft_name == "F16") {
    F16 aircraft;
    aircrafts.push_back(aircraft);
    add_to_aircraft_pointer(aircraft);
  } else if (aircraft_name == "F35") {
    F35 aircraft;
    aircrafts.push_back(aircraft);
    add_to_aircraft_pointer(aircraft);
  }
}

void Carrier::add_to_aircraft_pointer(Aircraft& aircraft) {
  Aircraft** temp = new Aircraft*[aircraft_count + 1];
  if (aircraft_pointers != NULL) {
    for (int i = 0; i < aircraft_count; ++i) {
      temp[i] = aircraft_pointers[i];
    }
  }
  temp[aircraft_count - 1] = &aircraft;
  delete[] aircraft_pointers;
  aircraft_pointers = temp;
}

int Carrier::fight(Carrier& fired_upon_carrier) {
  int caused_damage = 0;
  for (unsigned int i = 0; i < aircrafts.size(); ++i) {
    caused_damage += aircrafts[i].get_aircraft_firepower();
    aircrafts[i].set_aircraft_firepower_to_zero();
  }
  fired_upon_carrier.subtract_health_point(caused_damage);
  return caused_damage;
}

void Carrier::subtract_health_point(int amount) {
  this->health_point -= amount;
}

void Carrier::refill_all_aircrafts() throw (const char*) {
  if (ammo_storage == 0) {
    throw "There's no ammo to fill the aircrafts";
  }
  int needed_ammo = 0;
  for (int i = 0; i < aircraft_count; ++i) {
    ++needed_ammo;
  }
  if (needed_ammo > ammo_storage) {
    for (int i = 0; i < aircraft_count; ++i) {
      if (aircrafts[i].get_aircraft_type() == "F35") {
        ammo_storage -= aircrafts[i].set_ammo_to_max();
      }
      if (ammo_storage == 0) {
        return;
      }
    }
    for (int i = 0; i < aircraft_count; ++i) {
      if (aircrafts[i].get_aircraft_type() == "F16") {
        ammo_storage -= aircrafts[i].set_ammo_to_max();
      }
      if (ammo_storage == 0) {
        return;
      }
    }
  } else {
    for (int i = 0; i < aircraft_count; ++i) {
      ammo_storage -= aircrafts[i].set_ammo_to_max();
    }
  }
}

int Carrier::get_ammo_storage() {
  return ammo_storage;
}

std::string Carrier::get_all_aircraft_stats() {
  std::string output = "";
  for (int i = 0; i < aircraft_count; ++i) {
    output += aircrafts[i].get_status() + "\n";
  }
  if (output == "") {
    return "There's no aircraft on this carrier.";
  }
  return output;
}

bool Carrier::is_health_point_zero() {
  if (health_point == 0) {
    return true;
  }
  return false;
}

int Carrier::get_all_aircraft_firepower() {
  int carrier_firepower;
  for (int i = 0; i < aircraft_count; ++i) {
    carrier_firepower += aircrafts[i].get_aircraft_firepower();
  }
  return carrier_firepower;
}

std::string Carrier::get_status() {
  if (is_health_point_zero()) {
    return "It's dead Jim :(";
  }
  return "Aircraft count: " + to_string(aircraft_count) + ", Ammo Storage: " + to_string(ammo_storage) + ", Firepower: " + to_string(get_all_aircraft_firepower()) + ", Health Points: " + to_string(health_point) + "\n" +
      "Aircrafts: \n" +
      get_all_aircraft_stats();
}

Carrier::~Carrier() {

}

