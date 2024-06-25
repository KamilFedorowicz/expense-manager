#ifndef ExpenseManager_h
#define ExpenseManager_h

#include <vector>
#include <string>
#include <algorithm>

class ExpenseManager
{
public:
    void addExpense(const Expense& expense)
    {
        expenses.push_back(expense);
    }
    
    void deleteExpense(int index)
    {
        if(index>=0 && index<expenses.size())
        {
            expenses.erase(expenses.begin()+index);
        }
    }
    
    std::vector<Expense> getExpensesByCategory(const std::string& category) const 
    {
        std::vector<Expense> filtered;
        for (const auto& expense : expenses) {
            if (expense.getCategory() == category) {
                filtered.push_back(expense);
            }
        }
        return filtered;
    }
    
    std::vector<Expense> getExpenses() const {
            return expenses;
        }
    
    
    double getTotalExpenses() const {
        double total = 0;
        for (const auto& expense : expenses) {
            total += expense.getAmount();
        }
        return total;
    }

    void loadExpenses(const std::string& filename) {
        // this function is basically defining what expenses are
        expenses = CSVHandler::load(filename);
    }

    void saveExpenses(const std::string& filename) {
        CSVHandler::save(filename, expenses);
    }
    
    private:
    std::vector<Expense> expenses;
};


#endif /* ExpenseManager_h */
