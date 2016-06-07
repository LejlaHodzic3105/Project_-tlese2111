#include "film.h"

bool Film::operator==(const Film &film){
  if(_key==film._key) return true;
  else return false;
}
