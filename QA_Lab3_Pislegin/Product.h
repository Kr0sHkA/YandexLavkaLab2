#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

/**
 * @brief Базовый класс товара в сервисе Яндекс Лавка.
 *
 * Хранит название и цену товара.
 */
class Product {
protected:
    std::string name;
    double price;

public:
    /**
     * @brief Создаёт товар с заданным названием и ценой.
     * @param name Название товара.
     * @param price Цена товара в рублях.
     */
    Product(const std::string& name, double price)
        : name(name), price(price) {
    }

    /**
     * @brief Возвращает название товара.
     * @return Название товара.
     */
    std::string getName() const {
        return name;
    }

    /**
     * @brief Возвращает цену товара.
     * @return Цена товара в рублях.
     */
    virtual double getPrice() const {
        return price;
    }

    /**
     * @brief Виртуальный деструктор класса.
     */
    virtual ~Product() = default;
};

#endif