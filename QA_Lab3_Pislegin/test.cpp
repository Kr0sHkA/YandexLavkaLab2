#include "pch.h"
#include "Order.h"


TEST(OrderTests, EmptyOrderHasZeroSubtotal) {
    Order order;

    EXPECT_DOUBLE_EQ(order.getSubtotal(), 0.0);
}

TEST(OrderTests, AddProductIncreasesSubtotal) {
    Order order;
    order.addProduct(250.0);

    EXPECT_DOUBLE_EQ(order.getSubtotal(), 250.0);
}

TEST(OrderTests, MultipleProductsAreSummed) {
    Order order;
    order.addProduct(100.0);
    order.addProduct(200.0);
    order.addProduct(50.0);

    EXPECT_DOUBLE_EQ(order.getSubtotal(), 350.0);
}

TEST(OrderTests, NonPositivePricesAreIgnored) {
    Order order;
    order.addProduct(-50.0);
    order.addProduct(0.0);

    EXPECT_DOUBLE_EQ(order.getSubtotal(), 0.0);
}

TEST(OrderTests, ValidPromoCodeIsAccepted) {
    Order order;
    order.addProduct(1000.0);

    EXPECT_TRUE(order.applyPromoCode("LAVKA10"));
}

TEST(OrderTests, InvalidPromoCodeIsRejected) {
    Order order;
    order.addProduct(1000.0);

    EXPECT_FALSE(order.applyPromoCode("INVALID"));
    EXPECT_DOUBLE_EQ(order.getDiscount(), 0.0);
}

TEST(OrderTests, PromoCodeGivesTenPercentDiscount) {
    Order order;
    order.addProduct(1000.0);

    order.applyPromoCode("LAVKA10");

    EXPECT_DOUBLE_EQ(order.getDiscount(), 100.0);
    EXPECT_DOUBLE_EQ(order.getTotal(), 900.0);
}

TEST(OrderTests, TotalWithoutDiscountEqualsSubtotal) {
    Order order;
    order.addProduct(400.0);
    order.addProduct(100.0);

    EXPECT_DOUBLE_EQ(order.getTotal(), 500.0);
}

TEST(OrderTests, OrderRequiresMinimumSubtotal) {
    Order order;
    order.addProduct(299.0);

    EXPECT_FALSE(order.canPlaceOrder());

    order.addProduct(1.0);

    EXPECT_TRUE(order.canPlaceOrder());
}

TEST(OrderTests, DiscountDoesNotChangeSubtotal) {
    Order order;
    order.addProduct(1000.0);

    order.applyPromoCode("LAVKA10");

    EXPECT_DOUBLE_EQ(order.getSubtotal(), 1000.0);
    EXPECT_DOUBLE_EQ(order.getTotal(), 900.0);
}
TEST(OrderTests, InvalidPromoCodeResetsPreviousDiscount) {
    Order order;
    order.addProduct(1000.0);

    EXPECT_TRUE(order.applyPromoCode("LAVKA10"));
    EXPECT_DOUBLE_EQ(order.getDiscount(), 100.0);

    EXPECT_FALSE(order.applyPromoCode("INVALID"));
    EXPECT_DOUBLE_EQ(order.getDiscount(), 0.0);
    EXPECT_DOUBLE_EQ(order.getTotal(), 1000.0);
}