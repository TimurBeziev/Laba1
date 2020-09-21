#include "student.h"

void Student::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
Student::Student(POINT persons_location) : Person(persons_location) {
}
