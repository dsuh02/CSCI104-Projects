#ifndef CLOTHING_H
#define CLOTHING_H

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Clothing: public Product{
  public:
  Clothing(const std::string category, const std::string name, double price,
      int qty, std::string size, std::string brand);
  ~Clothing();
  std::string displayString() const ;
  bool isMatch(std::vector<std::string>& searchTerms) const;
  std::set<std::string> keywords() const ;
  void dump(std::ostream& os) const;
  private:
    //std::string getSize() const;
    //std::string getAuthor() const;
    std::string size_;
    std::string brand_;
};

#endif