#include "pch.h"
#include "Order.h"

Order::Order() : discount(0.0) {}

void Order::addProduct(double price) {
    if (price > 0.0) {
        products.push_back(price);
    }
}

void Order::addProduct(const Product& product) {
    if (product.getPrice() > 0.0) {
        products.push_back(product.getPrice());
    }
}

double Order::getSubtotal() const {
    double subtotal = 0.0;

    for (double price : products) {
        subtotal += price;
    }

    return subtotal;
}

bool Order::applyPromoCode(const std::string& code) {
    if (code == "LAVKA10" && getSubtotal() > 0.0) {
        discount = getSubtotal() * 0.10;
        return true;
    }

    discount = 0.0;
    return false;
}

double Order::getDiscount() const {
    return discount;
}

double Order::getTotal() const {
    return getSubtotal() - discount;
}

bool Order::canPlaceOrder() const {
    return getSubtotal() >= MINIMUM_SUBTOTAL;
}