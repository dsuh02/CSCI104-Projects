#include <iostream>
#include <string>
#include <iomanip>
#include <set>
#include <vector>
#include <algorithm>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price,
             int qty, string size, string brand) :
  Product(category,name,price,qty),
  size_(size),
  brand_(brand)
  {
    
}
Clothing::~Clothing(){

}
bool Clothing::isMatch(std::vector<std::string>& searchTerms) const{
  return false;
}
string Clothing::displayString() const{
  string out = name_ + "\nSize: "+ size_ + " Brand: "+ brand_ +
      "\n"+ to_string((int)price_)+ "."+to_string(int(price_*10)%100) +" "+ to_string(qty_) + " left.";
  return out;
}

set<string> Clothing::keywords() const{
  set<string> kw;
  set<string> kwSize = parseStringToWords(size_);
  set<string> kwName = parseStringToWords(name_);
  set<string> kwBrand = parseStringToWords(brand_);
  kw = setUnion(kwSize,kwName);
  kw = setUnion(kw,kwBrand);
  return kw;
}

void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" <<setprecision(2) << fixed << price_ << "\n" << qty_ <<
      "\n" << size_ <<"\n" << brand_ << endl;
}