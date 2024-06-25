#ifndef CSVHandler_h
#define CSVHandler_h

#include <vector>
#include <string>
#include <fstream>
#include <sstream>


class CSVHandler
{
    
    
public:
    // we use static, so that no need to initialise a particular object
    static std::vector<Expense> load(const std::string& filename)
    {
        std::vector<Expense> expenses;
        std::ifstream file(filename);
        if (!file.is_open()) return expenses;

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string date, amountStr, category, description;
            std::getline(ss, date, ',');
            std::getline(ss, amountStr, ',');
            std::getline(ss, category, ',');
            std::getline(ss, description, ',');

            double amount = std::stod(amountStr);
            expenses.emplace_back(date, amount, category, description);
        }
        return expenses;
    }
    
    static void save(const std::string& filename, const std::vector<Expense>& expenses) {
        std::ofstream file(filename);
        for (const auto& expense : expenses) {
            file << expense.getDate() << ","
                 << expense.getAmount() << ","
                 << expense.getCategory() << ","
                 << expense.getDescription() << "\n";
        }
    }
    
};

#endif /* CSVHandler_h */
