#include <iostream>
#include "Expense.h"
#include "CSVHandler.h"
#include "ExpenseManager.h"

void printMenu() {
    std::cout << "1. Add Expense\n";
    std::cout << "2. View Expenses\n";
    std::cout << "3. Delete Expense\n";
    std::cout << "4. View Total Expenses\n";
    std::cout << "5. Get expense by category\n";
    std::cout << "6. Save and Exit\n";
}

int main() {
    ExpenseManager manager;
    manager.loadExpenses("expenses.csv");

    int choice;
    do {
        printMenu();
        std::cin >> choice;

        if (choice == 1) {
            std::string date, category, description;
            double amount;
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::cin >> date;
            std::cout << "Enter amount: ";
            std::cin >> amount;
            std::cout << "Enter category: ";
            std::cin >> category;
            std::cout << "Enter description: ";
            std::cin.ignore();
            std::getline(std::cin, description);

            manager.addExpense(Expense(date, amount, category, description));
        } else if (choice == 2) {
            const auto& expenses = manager.getExpenses();
            for (size_t i = 0; i < expenses.size(); ++i) {
                std::cout << i + 1 << ". " << expenses[i].getDate() << ", "
                          << expenses[i].getAmount() << ", "
                          << expenses[i].getCategory() << ", "
                          << expenses[i].getDescription() << "\n";
                
            }
        } else if (choice == 3) {
            int index;
            std::cout << "Enter expense number to delete: ";
            std::cin >> index;
            manager.deleteExpense(index - 1);
        } else if (choice == 4) {
            std::cout << "Total expenses: " << manager.getTotalExpenses() << "\n";
        }
        else if (choice == 5)
        {
            std::string cat;
            std::cout << "Tell us the category: ";
            std::cin >> cat;
            std::vector<Expense> filtered = manager.getExpensesByCategory(cat);
            
            for (size_t i = 0; i < filtered.size(); ++i) {
                std::cout << i + 1 << ". " << filtered[i].getDate() << ", "
                          << filtered[i].getAmount() << ", "
                          << filtered[i].getCategory() << ", "
                          << filtered[i].getDescription() << "\n";
                
            }
            
            
            
        }
    } while (choice != 6);

    manager.saveExpenses("expenses.csv");
    return 0;
}
