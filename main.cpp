#include "F16.h"
#include "F35.h"
#include "Carrier.h"

using namespace std;

int main() {


  Carrier carrier(5000, 2000);
  carrier.add_aircraft("F35");
  carrier.add_aircraft("F35");
  carrier.add_aircraft("F16");
  cout << carrier.get_status() << endl;

  carrier.refill_all_aircrafts();
  cout << carrier.get_status() << endl;

  Carrier falcon(3000, 1440);
  carrier.fight(falcon);
  cout << falcon.get_status() << endl;

  return 0;
}
