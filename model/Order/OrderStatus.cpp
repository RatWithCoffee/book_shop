

#include "OrderStatus.h"

std::ostream &operator<<(std::ostream &os, OrderStatus status) {
    switch (status) {
        case OrderStatus::PROCESSING:
            os << "���������� �� ������";
            break;
        case OrderStatus::IN_DELIVER:
            os << "� ���������";
            break;
        case OrderStatus::DELIVERED:
            os << "���������";
            break;
    }
    return os;
}
