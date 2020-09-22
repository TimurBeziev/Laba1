#include "person.h"

Person::Person(POINT persons_location) : persons_location_(persons_location) {
}
POINT Person::GetCoordinates() {
  return persons_location_;
}
