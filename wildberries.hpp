#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Product;
class Magazine; 

// HUBS
class Hub 
{
private:
    std::vector<std::shared_ptr<Product>> _products;
    double _total_price;
public:
    Hub() : _total_price{0} {}
    virtual void remove_product(Product* product);
    virtual void remove_product(std::string id);
    virtual void add_product(Product* product);
};
class Basket : public Hub {};
class Wish_list : public Hub {}; 
class History : public Hub {}; 

// Banking
inline static size_t initial_card_number = 1110345618584847;
class Bank_card 
{
private:
    size_t _card_number;
    double _card_balance;
public:
    // getters setters
    size_t get_card_number() const{ return _card_number; }
    double get_card_balance() const{ return _card_balance; }
    void set_card_balance(const double& card_balance) { _card_balance = card_balance; }

    // Constructors
    Bank_card(double balance = 0) 
        : _card_number{initial_card_number++}, _card_balance{balance} {}
};

// Address
enum class Country {Amerika, Rusastan, Dzorap};

class Address 
{
private:
    Country _country;
    std::string _region;
    std::string _street;
    std::string _house;
public:
const    //getters, setters
    Country get_country() const{ return _country; }
    std::string get_region() const{ return _region; }
    std::string get_street() const{ return _street; }
    std::string get_house() const{ return _house; }
    void set_country(const Country& country) {  _country = country; }
    void set_region(const std::string& region) {  _region = region; }
    void set_street(const std::string& street) {  _street = street ; }
    void set_house(const std::string& house) {  _house = house ; }

    //Constructors
    Address(Country country, std::string region, std::string street, std::string house) 
        : _country{country}, _region{region}, _street{street}, _house{house} {}

};

// Rating
enum class RatingStar : short
{
    Zero = 0,
    One,
    Two,
    Three,
    Five
};

class Rating
{
private:
    std::shared_ptr<User> user;
    RatingStar rs;
    std::string review;
};

// User
inline static size_t user_id = 0;
enum class Gender {Male, Female, Helicopter, Crouasant, other};
class User 
{
private:
    size_t _uid;
    std::string _name;
    Gender _gender;
    short _age;
    std::unique_ptr<Bank_card> _user_bank_card;
    std::unique_ptr<Basket> _basket;
    std::unique_ptr<Wish_list> _wish_list;
    std::unique_ptr<History> _history;
    std::shared_ptr<Address> _address;
public:
    // getters
    size_t get_uid() const{ return _uid; }
    const std::string& get_name() const{ return _name; }
    Gender get_gender() const { return _gender; }
    short get_age() const{ return _age; }
    
    Bank_card* get_bank_card() const { return _user_bank_card.get(); }
    Basket* get_basket() const { return _basket.get(); }
    Wish_list* get_wish_list() const { return _wish_list.get(); }
    History* get_history() const { return _history.get(); }

    std::shared_ptr<Address> get_address() const const{ return _address; }

    // setters
    void set_uid(size_t uid) { _uid = uid; }
    void set_name(const std::string& name) { _name = name; }
    void set_gender(Gender gender) { _gender = gender; }
    void set_age(short age) { _age = age; }
    void set_bank_card(std::unique_ptr<Bank_card> other) { _user_bank_card = std::move(other); }
    void set_address(std::shared_ptr<Address> address) { _address = std::move(address); }
    
    // Ctors
    User(const std::string& name, const Gender gender, const short age) : _uid{user_id++}, _name{name}, _gender{gender}, _age{age} {} 
    
    //Methods
    void user_order(const Product& product, size_t quantity);
    void cancel_order(const Product& product);
    void cancel_order(const std::string& articul);

    void add_to_card(const Product& product, size_t quantity);
    void remove_from_card(const Product& product);
    void remove_from_card(const std::string& articul);

    void add_to_basket(const Product& product, size_t quantity);
    void remove_from_basket(const Product& product);
    void remove_from_basket(const std::string& articul);

    void add_to_wishlist(const Product& product, size_t quantity);
    void remove_from_wishlist(const Product& product);
    void remove_from_wishlist(const std::string& articul);

    
};


// Product
inline static size_t articul_id = 0;

class Product
{
protected:
    size_t _articul;
    double _price;
    std::shared_ptr<Magazine> _magazine;
    size_t _quantity;
    std::string _name;
    std::vector<Rating> _product_ratings;
    double _total_rate;
public:

    // getters
    size_t get_articul() const{ return _articul; }
    double get_price() const{ return _price; }
    Magazine* get_magazine() const{ return _magazine.get(); }
    size_t get_qunatity() const{ return _quantity; }
    std::string get_name() const{ return _name; }
    double get_total_rate() const{ return _total_rate; }
    virtual void product_info() = 0;

    // setters
    void set_articul(const size_t articul) { _articul = articul; }
    void set_price(const double price) { _price = price; }
    void set_magazine(std::shared_ptr<Magazine> magazine) { _magazine = std::move(magazine); }
    void set_qunatity(const size_t quantity) { _quantity = quantity; }
    void set_name(const std::string name) { _name = name; }
    void set_total_rate(const double total_rate) { _total_rate = total_rate; }
};


class Magazine
{
protected:
    std::string _name;
    std::vector<std::shared_ptr<Product>> _products;
    std::vector<std::shared_ptr<Address>> _addresses;
public:
const    // getters, setters
    std::string get_name() const const{ return _name; }
    void set_name(const std::string& name) { _name = name; }

    void add_product(const Product& product);
    void del_product(const Product& product);
};
