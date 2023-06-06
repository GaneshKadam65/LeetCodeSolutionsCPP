#include <iostream>
#include <vector>
#include <algorithm>

double averageSalary(std::vector<int>& salary) {
    int n = salary.size();

    if (n <= 2) {
        return 0;  // Not enough elements to calculate average excluding min and max
    }

    // Sort the salaries in ascending order
    std::sort(salary.begin(), salary.end());

    // Calculate the sum of salaries excluding the min and max
    int sum = 0;
    for (int i = 1; i < n - 1; i++) {
        sum += salary[i];
    }

    // Calculate the average
    double average = static_cast<double>(sum) / (n - 2);
    return average;
}

int main() {
    std::vector<int> salary = {1000, 2000, 3000, 4000, 5000};  // Example input

    double avg = averageSalary(salary);
    std::cout << "Average salary excluding the minimum and maximum salaries: " << avg << std::endl;

    return 0;
}
