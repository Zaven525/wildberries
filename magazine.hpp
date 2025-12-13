#pragma once
#include "libs.hpp"
#include "products.hpp"
#include "other.hpp"


class Magazine
{
    std::string _name;
    std::vector<std::shared_ptr<Product>> _products;
    std::vector<std::shared_ptr<Address>> _addresses;

public:
    const std::string& get_name() const { return _name; }
    void set_name(const std::string& name) { _name = name; }

    void add_product(std::shared_ptr<Product> product);
    void del_product(size_t articul);
};
