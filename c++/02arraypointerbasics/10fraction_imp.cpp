#include "fraction.hh"

fraction operator +(fraction f1, fraction f2) {
  fraction ans(f1.num*f2.den + f1.den*f2.num, f1.den*f2.den);
  return ans;
}
