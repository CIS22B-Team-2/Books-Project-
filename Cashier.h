#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "books.h"

class Cashier : public Book
{
private:
    const double tax = 0.10;
    double subTotal = 0;
    double finalTotal = 0;

public:
    // Constructor
    Cashier();
    Cashier(const Cashier& c);
    double getPrice();
    int getPurchaseQuantity();

    ~Cashier();
    double calcSubTotal();
    double calcFinalTotal(double d);
    void displayTableTop();
    void displayTableBottom(double d);
    void displayPurchase();

    friend std::ostream& operator<<(std::ostream& out, const Cashier& c);
    friend std::istream& operator>>(std::istream& in, Cashier& c);
    void operator=(const Cashier& c);
};
