cmake_minimum_required(VERSION 3.25)
project(book_shop)

set(CMAKE_CXX_STANDARD 17)

add_executable(book_shop main.cpp model/People/Customer.cpp model/People/Customer.h model/People/Manager.cpp model/People/Manager.h model/People/Human.cpp model/People/Human.h model/People/Rights.h model/Order/Order.cpp model/Order/Order.h model/Book.cpp model/Book.h apps/customer_app.cpp model/Order/OrderStatus.cpp model/Order/OrderStatus.h apps/customer_app.h apps/manager_app.cpp apps/manager_app.h apps/utils.cpp apps/utils.h repositories/BooksRepo.cpp repositories/BooksRepo.h repositories/CustomersRepo.cpp repositories/CustomersRepo.h repositories/ManagersRepo.cpp repositories/ManagersRepo.h)
