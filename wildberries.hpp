#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
class product;

class Hub 
{
private:
    std::vector<std::shared_ptr<product>> products;
    double total_price;
public:
    virtual void remove_product(product* product);
    virtual void remove_product(std::string id);
    virtual void add_product(product* product);
};
class Basket : public Hub {};
class Wish_list : public Hub {}; 
class History : public Hub {}; 

inline static size_t initial_card_number = 1110345618584847;
class Bank_card 
{
    size_t id;
    double balance;
};

class Address 
{
private:
    enum class Country {Amerika, Rusastan, Dzorap};
    std::string Region;
    std::string Street;
    std::string House;
};


inline static size_t id = 0;
class User 
{
private:
    std::string _name;
    enum class Gender {Male, Female, Helicopter, Crouasant, other};
    Gender gender;
    short age;
    std::string Uid;
    std::unique_ptr<Bank_card> user_bank_card;
    std::unique_ptr<Basket> basket;
    std::unique_ptr<Wish_list> wish_list;
    std::unique_ptr<History> history;
    std::shared_ptr<Address> address;
};
