#include <iostream>
#include <string.h>

using namespace std;

class Customer;

class Good
{
    friend class Customer;

private:
    int id = rand();
    string name;
    double cost = 0;
public:
    Good();
    Good(int id, string name);
    void setName(string name);
    int getPrice();
    void showInfo();
    ~Good();
};

Good::Good()
{

}

Good::Good(int id, string name)
{
    this->id = id;
    this->name = name;
}

void Good::setName(string name)
{
    this->name = name;
}

int Good::getPrice()
{
    return this->cost;
}
void Good::showInfo()
{
    cout << "Id: " << this->id << endl;
    cout << "Name: " << this->name << endl;
    cout << "Cost: " << this->cost << endl;
}

Good::~Good()
{

}


class Customer
{
private:
    int id;
public:
    Customer(int id);
    void setPrice(Good& good, double price);
    ~Customer();
};

Customer::Customer(int id)
{
    this->id = id;
}

void Customer::setPrice(Good& good, double price)
{
    good.cost = price;
}
Customer::~Customer()
{

}



int main()
{
    
    int n = 0;
    cin >> n;

    Good* goods = new Good[n];
    Customer customer = Customer(0);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter good " << i + 1 << " name: ";
        string name;
        cin >> name;
        goods[i].setName(name);
    }

    for (int i = 0; i < n; i++)
    {
        goods[i].showInfo();
    }
    for (int i = 0; i < n; i++)
    {
        int price = 0;
        cout << "Enter "<<i + 1<<" good price: ";
        cin >> price;
        customer.setPrice(goods[i], price);
    }
    for (int i = 0; i < n; i++)
    {
        goods[i].showInfo();
    }
    delete[] goods;
    return 0;
}