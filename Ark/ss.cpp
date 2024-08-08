#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers;
    
    do {
        int num = rand() % 100000;
        std::string num_str = std::to_string(num);
        if(num_str.length() == 5 && num_str[1] == '6'){
            numbers.push_back(num);
        }
    } while(numbers.size() < 10); // Генерируем 10 чисел
    
    std::sort(numbers.begin(), numbers.end(), std::greater<int>()); // Сортируем по убыванию
    
    if(numbers.size() >= 5){
        std::cout << "Пятый по величине элемент последовательности: " << numbers[4] << std::endl;
    } else {
        std::cout << "Недостаточно элементов." << std::endl;
    }

    return 0;
}