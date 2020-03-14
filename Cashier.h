#include <iostream>
#include <string>
#include <iomanip>

class Cashier
{
    private:
    std::string isbn;
    std::string title;
    std::string author;
    std::string publisher;
    std::string dateAdded;
    std::string quantity;
    std::string wholeSale;
    std::string retailSale;
    
    const double tax = 0.10;
    double subTotal;
    double finalTotal;
  
    public:
    Cashier();
    Cashier(const Cashier &c);
    double getPrice();
    int getPurchaseQuantity();
    
    ~Cashier();
    
    void setTitle(std::string s);
    void setISBN(std::string s);
    void setAuthor(std::string s);
    void setPublisher(std::string s);
    void setDate(std::string s);
    void setQuantity(std::string s);
    void setWholeSale(std::string s);
    void setRetailSale(std::string s);
    
    std::string getTitle();
    std::string getISBN();
    std::string getAuthor();
    std::string getPublisher();
    std::string getDate();
    std::string getQuantity();
    std::string getWholeSale();
    std::string getRetailSale();
    
    double calcSubTotal();
    double calcFinalTotal(double d);
    void displayTableTop();
    void displayTableBottom(double d);
    void displayPurchase();
    
    friend std::ostream& operator<<(std::ostream& out, const Cashier &c);
	friend std::istream& operator>>(std::istream& in, Cashier &c);
	void operator=(const Cashier &c);
	
// 	friend Cashier operator+(const Cashier &c);
// 	friend Cashier operator-(const Cashier &c);
};