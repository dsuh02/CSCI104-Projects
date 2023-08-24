#include <string>
#include <set>
#include <vector>
#include <fstream>

#include "mydatastore.h"
#include "datastore.h"
#include "util.h"

using namespace std;

MyDataStore::~MyDataStore(){
  for(unsigned int i = 0; i < products.size(); i++)
    {
        delete products[i];
    }
    for(unsigned int i = 0; i < users.size(); i++)
    {
        delete users[i];
    }
}
void MyDataStore::addProduct(Product* p){
  products.push_back(p);
}
void MyDataStore::addUser(User* u){
  users.push_back(u);
}
vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
  vector<Product*> results;
  set<Product*> setResults;

  set<string> setTerms;
  copy(terms.begin(),terms.end(),inserter(setTerms,setTerms.end()));

  if(type==0){//AND search
    for(unsigned int i=0; i<terms.size(); i++){
      set<Product*> nextResult;
      for(unsigned int h=0; h<products.size();h++){
        set<string> kw = products[h]->keywords();
        kw=setIntersection(kw,setTerms);
        if(kw.size()>0){
          if(i==0){
            setResults.insert(products[h]);
          }
            nextResult.insert(products[h]);
        }
      }
      setResults=setIntersection(setResults,nextResult);
    }
  }
  else{//OR search
    //cout<<"OR SEARCH"<<endl;//MATEST
    for(unsigned int i=0; i<terms.size(); i++){
      set<Product*> nextResult;
      
      for(unsigned int h=0; h<products.size();h++){
        set<string> kw = products[h]->keywords();
        //cout<<"kw size "<<kw.size()<<endl;//MATEST
        kw=setIntersection(kw,setTerms);
        //cout<<"kw size after intersection "<<kw.size()<<endl;//MATEST
        if(kw.size()>0){
          if(i==0){
           // cout<<"was first prod added to setResults"<<endl;//MATEST
            setResults.insert(products[h]);
          }
            //cout<<"prod added to nextResult"<<endl;//MATEST
            nextResult.insert(products[h]);
        }
      }
      setResults=setUnion(setResults,nextResult);
    }
  }
  copy(setResults.begin(), setResults.end(), std::back_inserter(results));
  return results;
}
void MyDataStore::dump(std::ostream& ofile){
  ofile<<"<products>"<<endl;
  for(unsigned int i = 0; i < products.size(); i++)
  {
    products[i]->dump(ofile);
  }
  ofile<<"</products>"<<endl;
  ofile<<"<users>"<<endl;
  for(unsigned int i = 0; i < users.size(); i++)
  {
    users[i]->dump(ofile);
  }
  ofile<<"</users>"<<endl;
}