#pragma once
#ifndef GROCERYPRODUCT_H
#define GROCERYPRODUCT_H

#include "Product.h"

/**
 * @brief Класс обычного продукта из продуктового магазина.
 *
 * Наследуется от Product и представляет продукты,
 * например молоко, хлеб или фрукты.
 */
class GroceryProduct : public Product {
public:
    /**
     * @brief Создаёт продуктовый товар.
     * @param name Название продукта.
     * @param price Цена продукта в рублях.
     */
    GroceryProduct(const std::string& name, double price)
        : Product(name, price) {
    }

    /**
     * @brief Возвращает цену продуктового товара.
     * @return Цена товара в рублях.
     */
    double getPrice() const override {
        return price;
    }
};

#endif