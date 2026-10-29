#pragma once
#ifndef PREPAREDMEAL_H
#define PREPAREDMEAL_H

#include "Product.h"

/**
 * @brief Класс готового блюда в сервисе Яндекс Лавка.
 *
 * Наследуется от Product и представляет готовую еду.
 */
class PreparedMeal : public Product {
public:
    /**
     * @brief Создаёт готовое блюдо.
     * @param name Название блюда.
     * @param price Цена блюда в рублях.
     */
    PreparedMeal(const std::string& name, double price)
        : Product(name, price) {
    }

    /**
     * @brief Возвращает цену готового блюда.
     * @return Цена блюда в рублях.
     */
    double getPrice() const override {
        return price;
    }
};

#endif