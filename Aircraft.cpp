#include "Aircraft.h"


Aircraft::Aircraft() {
  this->ammo_count = 0;
  this->aircraft_firepower = ammo_count * base_damage;
}

void Aircraft::refill_aircraft(int& ammo_storage) {
  int used_ammo = max_ammo - ammo_count;
  this->ammo_count = max_ammo;
  ammo_storage -= used_ammo;
}

int Aircraft::fight() {
  int damage = ammo_count * base_damage;
  ammo_count = 0;
  return damage;
}

int Aircraft::set_ammo_to_max() {
  int loss_of_ammo = max_ammo - ammo_count;
  this->ammo_count = max_ammo;
  this->aircraft_firepower = ammo_count * base_damage;
  return loss_of_ammo;
}

void Aircraft::set_aircraft_firepower_to_zero() {
  this->aircraft_firepower = 0;
}

std::string Aircraft::get_aircraft_type() {
  return aircraft_type;
}

int Aircraft::get_aircraft_firepower() {
  return aircraft_firepower;
}

std::string Aircraft::get_status() {
  return "Type: " + aircraft_type + ", Ammo: " + to_string(ammo_count) + ", Base Damage: " + to_string(base_damage) + ", Firepower: " + to_string(ammo_count * base_damage);
}

Aircraft::~Aircraft() {

}

