#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price,
             int qty, string isbn, string author) :
  Product(category,name,price,qty),
  isbn_(isbn),
  author_(author)
  {
}
Book::~Book(){

}
bool Book::isMatch(std::vector<std::string>& searchTerms) const{
  return false;
}
string Book::displayString() const{
  string out = name_ + "\nAuthor: "+ author_ + " ISBN: "+ isbn_ +
      "\n"+ to_string((int)price_)+ "."+to_string(int(price_*10)%100) +" "+ to_string(qty_)+ " left.";
  return out;
}

set<string> Book::keywords() const{
  set<string> kw;
  set<string> kwName = parseStringToWords(name_);
  set<string> kwAuthor = parseStringToWords(author_);
  kw = setUnion(kwName,kwAuthor);
  kw.insert(isbn_);
  return kw;
}

void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" <<setprecision(2) << fixed << price_ << "\n" << qty_ <<
      "\n" << isbn_ <<"\n" << author_ << endl;
}