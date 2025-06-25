// In your src/main.cpp
#include "../external/liquibook/src/book/order_book.h"
#include "../external/liquibook/src/book/order.h"
#include <iostream>

int main() {
    // Use Liquibook classes directly
    liquibook::book::OrderBook<liquibook::book::Order*> book;
    std::cout << "Liquibook working!" << std::endl;
    return 0;
}