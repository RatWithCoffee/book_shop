

#include "OrderStatus.h"

std::ostream &operator<<(std::ostream &os, OrderStatus status) {
    switch (status) {
        case OrderStatus::PROCESSING:
            os << "Собирается на складе";
            break;
        case OrderStatus::IN_DELIVER:
            os << "В обработке";
            break;
        case OrderStatus::DELIVERED:
            os << "Доставлен";
            break;
    }
    return os;
}
