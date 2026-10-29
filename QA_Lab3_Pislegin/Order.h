#pragma once

#include <string>
#include <vector>
#include "Product.h"

/**
 * @page order_process Схема оформления заказа
 *
 * На рисунке представлена схема оформления заказа в сервисе «Яндекс Лавка».
 *
 * @image html order_process.png "Схема оформления заказа в Яндекс Лавке" width=800px
 */

 /**
  * @page order_graph График расчета стоимости заказа
  *
  * График показывает зависимость итоговой стоимости заказа от суммы товаров
  * при применении промокода LAVKA10, предоставляющего скидку 10%.
  *
  * @dot
  * digraph OrderPrice {
  *     rankdir=LR;
  *     node [shape=box, style=rounded];
  *
  *     A [label="Сумма товаров"];
  *     B [label="Проверка промокода LAVKA10"];
  *     C [label="Расчет скидки 10%"];
  *     D [label="Вычисление итоговой стоимости"];
  *     E [label="Итоговая стоимость заказа"];
  *
  *     A -> B -> C -> D -> E;
  * }
  * @enddot
  */

/**
 * @brief Класс заказа в сервисе Яндекс Лавка.
 *
 * Хранит товары, рассчитывает стоимость заказа,
 * применяет промокоды и проверяет минимальную сумму.
 */
class Order {
private:
    std::vector<double> products;
    double discount;
    static constexpr double MINIMUM_SUBTOTAL = 300.0;

public:
    /**
     * @brief Создаёт пустой заказ.
     */
    Order();

    /**
     * @brief Добавляет товар по его цене.
     * @param price Цена товара в рублях.
     */
    void addProduct(double price);

    /**
     * @brief Добавляет товар из каталога.
     * @param product Товар, добавляемый в заказ.
     */
    void addProduct(const Product& product);

    /**
     * @brief Рассчитывает сумму товаров без скидки.
     * @return Общая стоимость товаров в рублях.
     */
    double getSubtotal() const;

    /**
     * @brief Применяет промокод к заказу.
     * @param code Введённый промокод.
     * @return true, если промокод применён; иначе false.
     */
    bool applyPromoCode(const std::string& code);

    /**
     * @brief Возвращает размер скидки.
     * @return Сумма скидки в рублях.
     */
    double getDiscount() const;

    /**
     * @brief Вычисляет итоговую стоимость заказа с учетом скидки.
     *
     * Формула расчета:
     * @code
     * Итоговая стоимость = Стоимость товаров - Скидка
     * @endcode
     *
     * @return Итоговая стоимость заказа в рублях.
     */
    double getTotal() const;

    /**
     * @brief Проверяет возможность оформления заказа.
     * @return true, если сумма товаров не меньше 300 рублей.
     */
    bool canPlaceOrder() const;
};