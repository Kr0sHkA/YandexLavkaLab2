#pragma once
#pragma once

#include <string>
#include <vector>

class Order {
private:
    std::vector<double> products;
    double discount;
    static constexpr double MINIMUM_SUBTOTAL = 300.0;

public:
    Order();

    void addProduct(double price);
    double getSubtotal() const;

    bool applyPromoCode(const std::string& code);
    double getDiscount() const;
    double getTotal() const;

    bool canPlaceOrder() const;
};