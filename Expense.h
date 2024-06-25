//
//  Expense.h
//  personal_expenses_tracker
//
//  Created by Kamil Fedorowicz on 24/06/2024.
//

#ifndef Expense_h
#define Expense_h
#include <string>
class Expense
{
public:
    
    Expense(const std::string& date, double amount, const std::string& category, const std::string& description)
            : date(date), amount(amount), category(category), description(description) {}
    
    std::string getDate() const
    {
        return date;
    }
    
    double getAmount() const
    {
        return amount;
    }
    
    std::string getCategory() const
    {
        return category;
    }
    
    std::string getDescription() const
    {
        return description;
    }
    
    
    
private:
    std::string date;
    double amount;
    std::string category;
    std::string description;
    
};

#endif /* Expense_h */
