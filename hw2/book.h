#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Book: public Product{
  public:
  Book(const std::string category, const std::string name, double price,
      int qty, std::string isbn, std::string author);
  ~Book();
  std::string displayString() const;
  std::set<std::string> keywords() const;
  bool isMatch(std::vector<std::string>& searchTerms) const;
  void dump(std::ostream& os) const;
  private:
    //std::string getISBN() const;
   // std::string getAuthor() const;
    std::string isbn_;
    std::string author_;
};

#endif