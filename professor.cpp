#include "professor.h"
void Professor::Accept(Visitor* visitor) {
  visitor->Visit(this);
}
Professor::Professor(POINT persons_location) : Person(persons_location) {
}
