#pragma once
#include "libs.hpp"

class Magazine; 
class Rating;   


inline static size_t articul_id = 0;

class Product
{
protected:
    size_t _articul{articul_id++};
    double _price{};
    std::shared_ptr<Magazine> _magazine;
    size_t _quantity{};
    std::string _name;
    std::vector<Rating> _product_ratings;
    double _total_rate{};

public:
    virtual ~Product() = default;

    size_t get_articul() const { return _articul; }
    double get_price() const { return _price; }
    size_t get_quantity() const { return _quantity; }
    const std::string& get_name() const { return _name; }

    virtual void product_info() const = 0;
};
