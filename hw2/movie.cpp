#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price,
             int qty, string genre, string rating) :
  Product(category,name,price,qty),
  genre_(genre),
  rating_(rating)
  {
    
}
Movie::~Movie(){

}
bool Movie::isMatch(std::vector<std::string>& searchTerms) const{
  return false;
}
string Movie::displayString() const{
  string out = name_ + "\nGenre: "+ genre_ + " Rating: "+ rating_ +
      "\n"+ to_string((int)price_)+ "."+to_string(int(price_*10)%100)+" "+ to_string(qty_) + " left.";
  return out;
}

set<string> Movie::keywords() const{
  set<string> kw;
  set<string> kwGenre = parseStringToWords(genre_);
  set<string> kwName = parseStringToWords(name_);
  kw = setUnion(kwGenre,kwName);
  return kw;
}

void Movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" <<setprecision(2) << fixed << price_ << "\n" << qty_ <<
      "\n" << genre_ <<"\n" << rating_ << endl;
}