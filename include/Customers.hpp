#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

namespace Customers
{
    class Customer
    {
    private:
        int customerId;
        long nationalCode;
        string customerName;
        string customerEmail;
        /* data */
    public:
        //Getters
        int getCustomerId() const;
        long getNationalCode() const;
        string getCustomerName() const;
        string getCustomerEmail() const;
        //Setters
        void setCustomerId(int id);
        void setNationalCode(long code);
        void setCustomerName(string name);
        void setCustomerEmail(string email);
        bool operator==(const Customer customer) const;
        Customer(/* args */);
        ~Customer();
    };
    std::ostream& operator<<(std::ostream &out, const Customer customer);
    Customer::Customer(/* args */)
    {
    }
    
    Customer::~Customer()
    {
    }
    std::ostream& operator<<(std::ostream &out, const Customer customer)
    {
        out << "Id: " <<  customer.getCustomerId() << ", Name: " << customer.getCustomerName() << ", Code: " << customer.getNationalCode() << ", Email: " << customer.getCustomerEmail();
        return out;
    }
    bool Customer::operator==(const Customer customer) const
    {
        return customer.customerId == getCustomerId();
    }
    int Customer::getCustomerId() const
    {
        return customerId;
    }
    void Customer::setCustomerId(int id)
    {
        customerId = id;
    }
    string Customer::getCustomerName() const
    {
        return customerName;
    }
    void Customer::setCustomerName(string name)
    {
        customerName = name;
    }
    long Customer::getNationalCode() const
    {
        return nationalCode;
    }
    void Customer::setNationalCode(long code)
    {
        nationalCode = code;
    }
    string Customer::getCustomerEmail() const
    {
        return customerEmail;
    }
    void Customer::setCustomerEmail(string email)
    {
        customerEmail = email;
    }

    class Repository
    {
    private:
        list<Customer> *customers = NULL;
    public:
        list<Customer> GetAll();
        Customer GetById(int id);
        void Add(const Customer customer);
        void Delete(const Customer customer);
        void Delete(const int id);
        Repository(list<Customer> *list);
        ~Repository();
    };
    
    Repository::Repository(list<Customer> *list)
    {
        customers = list;
    }
    
    Repository::~Repository()
    {
    }
    list<Customer> Repository::GetAll()
    {
        return *customers;
    }
    Customer Repository::GetById(int id)
    {
        if (id <= 0)
        {
            throw invalid_argument("Customer id must be positive and unzero!");
        }
        Customer searcher;
        searcher.setCustomerId(id);
        list<Customer>::iterator it = find(customers->begin(), customers->end(), searcher);
        if(it != customers->end())
        {
            return *it;
        }
        else
        {
            throw invalid_argument("Customer Not Found!");
        }
    }
    void Repository::Add(const Customer customer)
    {
        customers->push_back(customer);
    }
    void Repository::Delete(const Customer customer)
    {
        customers->remove(customer);
    }
    void Repository::Delete(const int id)
    {
        customers->remove(GetById(id));
    }

} // namespace Customers
