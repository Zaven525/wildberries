#pragma once
#include "libs.hpp"
#include "other.hpp"
#include "products.hpp"


class Basket;
class Wish_list;
class History;

inline static size_t user_id = 0;
enum class Gender { Male, Female, Helicopter, Crouasant, Other };

class User
{
    size_t _uid{user_id++};
    std::string _name;
    Gender _gender{};
    short _age{};

    std::unique_ptr<Bank_card> _bank_card;
    std::unique_ptr<Basket> _basket;
    std::unique_ptr<Wish_list> _wish_list;
    std::unique_ptr<History> _history;
    std::shared_ptr<Address> _address;

public:
    User(std::string name, Gender g, short age)
        : _name{std::move(name)}, _gender{g}, _age{age} {}

    const std::string& get_name() const { return _name; }
};
