#pragma once
#include "libs.hpp"

class User; 
// Banking
inline static size_t initial_card_number = 1110345618584847;

class Bank_card
{
    size_t _card_number;
    double _card_balance;
public:
    size_t get_card_number() const { return _card_number; }
    double get_card_balance() const { return _card_balance; }
    void set_card_balance(double card_balance) { _card_balance = card_balance; }

    explicit Bank_card(double balance = 0)
        : _card_number{initial_card_number++}, _card_balance{balance} {}
};

// Address
enum class Country { Amerika, Rusastan, Dzorap };

class Address
{
    Country _country;
    std::string _region;
    std::string _street;
    std::string _house;
public:
    Address(Country c, std::string r, std::string s, std::string h)
        : _country{c}, _region{std::move(r)}, _street{std::move(s)}, _house{std::move(h)} {}
};

// Rating
enum class RatingStar : short { Zero, One, Two, Three, Four, Five };

class Rating
{
    std::shared_ptr<User> user; // forward-declared
    RatingStar rs{};
    std::string review;
};
