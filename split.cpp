#include "split.h"



std::vector<std::string> split(const std::string &s, char delim) {
  std::stringstream ss(s);
  std::string item;
  std::vector<std::string> elems; // vektor se puni rijecima koje se odvajaju iz cjeloukupnog stringa na osnovu ','
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);

  }
  return elems;

}
