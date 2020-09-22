#ifndef PERSON_H
#define PERSON_H

#include "visitor.h"
#include <windef.h>

class Person {
 public:
  explicit Person(POINT persons_location);
  virtual void Accept(Visitor* visitor) = 0;
  POINT GetCoordinates();
 private:
  POINT persons_location_;
};

#endif //PERSON_H
