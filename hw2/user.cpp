#include "user.h"
using namespace std;

User::User() : name_("unknown"), balance_(0.0), type_(1)
{

}
User::User(std::string name, double balance, int type) :
    name_(name), balance_(balance), type_(type)
{

}

User::~User()
{

}
void User::addToCart(Product* p){
    cart_.push_back(p);
    //cout<<"~~product pushed back"<<endl; //MATEST
    //-cout<<"~~cart has "<<cart_.size()<<" products"<<endl;//MATEST
}

void User::printCart(){
    if(cart_.size()==0){
        cout<<"Cart is empty!"<<endl;
        return;
    }
    for(unsigned int i=0; i<cart_.size(); i++){
        cout<< "Item "<<i+1<<endl;
        cout<<cart_[i]->displayString()<<endl;
        //cout<<"~~finished displaying"<<endl; //MATEST
        cout<<endl;
    }
}

void User::buyCart(){
    for(unsigned int i=0; i<cart_.size(); i++){
        if(balance_ >= cart_[i]->getPrice() && cart_[i]->getQty()>0){
            cart_[i]->subtractQty(1);
            balance_-=cart_[i]->getPrice();

            vector<Product*>::iterator it;
            it = cart_.begin()+i;
            cart_.erase(it);
            i--;
        }
    }
}

std::string User::getName() const
{
    return name_;
}

double User::getBalance() const
{
    return balance_;
}

void User::deductAmount(double amt)
{
    balance_ -= amt;
}

void User::dump(std::ostream& os)
{
    os << name_ << " "  << balance_ << " " << type_ << endl;
}
