

#ifndef BOOK_SHOP_ORDERSTATUS_H
#define BOOK_SHOP_ORDERSTATUS_H

#include <iostream>


enum class OrderStatus {
    PROCESSING, // собирается на складе
    IN_DELIVER, // в обработке
    DELIVERED // доставлен
};

std::ostream& operator<<(std::ostream& os, OrderStatus status);


#endif //BOOK_SHOP_ORDERSTATUS_H
