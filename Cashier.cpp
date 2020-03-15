#include "Cashier.h"

Cashier::Cashier()
{
    ISBN = ""; 
    title = "";
    author = "";
    publisher = "";
    year = 0;
    month = 0;
    day = 0; 
    quantity = 0;
    wholesale = 0.0;
    retail = 0.0;
    subTotal = 0.0;
    finalTotal = 0.0;
}

Cashier::Cashier(const Cashier& c)
{
    this->ISBN = c.ISBN;
    this->title = c.title;
    this->author = c.author;
    this->publisher = c.publisher;
    this->year = c.year;
    this->month = c.month;
    this->day = c.day; 
    this->quantity = c.quantity;
    this->wholesale = c.wholesale;
    this->retail = c.retail;
    this->subTotal = Cashier::calcSubTotal();
    this->finalTotal += subTotal;
}

double Cashier::getPrice()
{
    return retail; 
}

int Cashier::getPurchaseQuantity()
{
    return quantity; 
}

Cashier::~Cashier() {}

double Cashier::calcSubTotal()
{
    subTotal = Cashier::getPurchaseQuantity() * Cashier::getPrice();
    return subTotal;
}

double Cashier::calcFinalTotal(double d)
{
    finalTotal = d * (1 + tax);
    return finalTotal;
}

void Cashier::displayTableTop()
{
    std::cout << std::endl << "Serendipity Book Sellers" << std::endl << std::endl;
    std::cout << "Date:" << std::endl << std::endl;
    std::cout << std::left << std::setw(4) << "Qty" << std::setw(15) << "ISBN" << std::setw(30) << "Title" << std::setw(8) << "Price" << std::setw(8) << "Total" << std::endl;
    for (int i = 0; i < 65; i++)
        std::cout << "-";
    std::cout << std::endl;
}

void Cashier::displayTableBottom(double d)
{
    std::cout << "Subtotal: " << std::fixed << std::setprecision(2) << d << std::endl;
    std::cout << "Tax: " << Cashier::tax << std::endl;
    std::cout << "Total: " << Cashier::calcFinalTotal(d) << std::endl;
    std::cout << "Thank You For Shopping at Serendipity!" << std::endl;
}

void Cashier::displayPurchase()
{
    std::cout << std::setw(4) << quantity << std::setw(15) << ISBN << std::setw(30) 
        << title << std::setw(8) << retail << std::setw(8) 
        << Cashier::calcSubTotal() << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Cashier& c)
{
    out << std::setw(4) << c.quantity << std::setw(15) << c.ISBN << std::setw(30) 
        << c.title << std::setw(8) << c.retail << std::setw(8) 
        << c.subTotal << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Cashier& c)
{
    in >> c.title >> c.ISBN >> c.author >> c.publisher >> c.year >> c.month >> c.day >> c.quantity >> c.wholesale >> c.retail;
    return in;
}

void Cashier::operator=(const Cashier& c)
{
    this->ISBN = c.ISBN;
    this->title = c.title;
    this->author = c.author;
    this->publisher = c.publisher;
    this->year = c.year;
    this->month = c.month; 
    this->day = c.day; 
    this->quantity = c.quantity;
    this->wholesale = c.wholesale;
    this->retail = c.retail;
    this->subTotal = Cashier::calcSubTotal();
    this->finalTotal += subTotal;
}





#include "Cashier.h"

Cashier::Cashier()
{
    isbn = "";
    title = "";
    author = "";
    publisher = "";
    dateAdded = "";
    quantity = "";
    wholeSale = "";
    retailSale = "";
    subTotal = 0.0;
    finalTotal = 0.0;
}

Cashier::Cashier(const Cashier &c)
{
    this->isbn = c.isbn;
    this->title = c.title;
    this->author = c.author;
    this->publisher = c.publisher;
    this->dateAdded = c.dateAdded;
    this->quantity = c.quantity;
    this->wholeSale = c.wholeSale;
    this->retailSale = c.retailSale;
    this->subTotal = Cashier::calcSubTotal();
    this->finalTotal += subTotal;
}

double Cashier::getPrice()
{
    double price = std::stod(retailSale);
    return price;
}

int Cashier::getPurchaseQuantity()
{
    int number = std::stoi(quantity);
    return number;
}

void Cashier::setTitle(std::string s)
{
    title = s;
}
void Cashier::setISBN(std::string s)
{
    isbn = s;
}
void Cashier::setAuthor(std::string s)
{
    author = s;
}
void Cashier::setPublisher(std::string s)
{
    publisher = s;
}
void Cashier::setDate(std::string s)
{
    dateAdded = s;
}
void Cashier::setQuantity(std::string s)
{
    quantity = s;
}
void Cashier::setWholeSale(std::string s)
{
    wholeSale = s;
}
void Cashier::setRetailSale(std::string s)
{
    retailSale = s;
}

std::string Cashier::getTitle()
{
    return title;
}
std::string Cashier::getISBN()
{
    return isbn;
}
std::string Cashier::getAuthor()
{
    return author;
}
std::string Cashier::getPublisher()
{
    return publisher;
}
std::string Cashier::getDate()
{
    return dateAdded;
}
std::string Cashier::getQuantity()
{
    return quantity;
}
std::string Cashier::getWholeSale()
{
    return wholeSale;
}
std::string Cashier::getRetailSale()
{
    return retailSale;
}



Cashier::~Cashier()
{
    
}

double Cashier::calcSubTotal()
{
    subTotal = Cashier::getPurchaseQuantity() * Cashier::getPrice();
    return subTotal;
}

double Cashier::calcFinalTotal(double d)
{
    finalTotal = d * (1 + tax);
    return finalTotal;
}

void Cashier::displayTableTop()
{
    std::cout << std::endl << "Serendipity Book Sellers" << std::endl << std::endl;
    std::cout << "Date:" << std::endl << std::endl;
    std::cout << std::left << std::setw(4) << "Qty" << std::setw(15) << "ISBN" << std::setw(30) << "Title" << std::setw(8) << "Price" << std::setw(8) << "Total" << std::endl;
    for (int i = 0; i < 65; i++) 
        std::cout << "-";
    std::cout << std::endl;
}

void Cashier::displayTableBottom(double d)
{
    std::cout << "Subtotal: " << std::fixed << std::setprecision(2) << d << std::endl;
    std::cout << "Tax: " << Cashier::tax << std::endl;
    std::cout << "Total: " << Cashier::calcFinalTotal(d) << std::endl;
    std::cout << "Thank You For Shopping at Serendipity!" << std::endl;
}

void Cashier::displayPurchase()
{
    std::cout << std::setw(4) << quantity << std::setw(15) << isbn << std::setw(30) << title << std::setw(8) << retailSale << std::setw(8) << Cashier::calcSubTotal() << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Cashier &c)
{
    out << std::setw(4) << c.quantity << std::setw(15) << c.isbn << std::setw(30) << c.title << std::setw(8) << c.retailSale << std::setw(8) << c.subTotal << std::endl;
    return out;
}
	
std::istream& operator>>(std::istream& in, Cashier &c)
{
    in >> c.title >> c.isbn >> c.author >> c.publisher >> c.dateAdded >> c.quantity >> c.wholeSale >> c.retailSale;
    return in;
}

void Cashier::operator=(const Cashier &c)
{
    this->isbn = c.isbn;
    this->title = c.title;
    this->author = c.author;
    this->publisher = c.publisher;
    this->dateAdded = c.dateAdded;
    this->quantity = c.quantity;
    this->wholeSale = c.wholeSale;
    this->retailSale = c.retailSale;
    this->subTotal = Cashier::calcSubTotal();
    this->finalTotal += subTotal;
}

// Cashier::Cashier operator+(const Cashier &c)
// {
    
// }

// Cashier::Cashier operator-(const Cashier &c)
// {
//     c.quantity -= quantity;
//     return c;
// }
