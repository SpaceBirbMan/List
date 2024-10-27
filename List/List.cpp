#include <iostream>
#include "Chain.h"
#include <algorithm>
#include <cassert>
#include <vector>


void test() {
    Chain2<int> chain;
    chain.adder.back(1);
    chain.adder.back(2);
    chain.adder.back(3);
    chain.adder.back(4);

    Chain2<int>::Iterator it = chain.begin();

    // Проверка значений через итератор
    assert(*it == 1); ++it;
    assert(*it == 2); ++it;
    assert(*it == 3); ++it;
    assert(*it == 4);
    assert(it == chain.end());

    // Проверка обратной итерации
    assert(*it == 4); --it;
    assert(*it == 3); --it;
    assert(*it == 2); --it;
    assert(*it == 1);

    // Проверка что нельзя декрементировать из начала
    Chain2<int>::Iterator beginIt = chain.begin();
    assert(*beginIt == 1);
    if (beginIt != chain.begin()) --beginIt;  // Предотвращаем декремент в начале
    assert(beginIt == chain.begin());

    // Проверка инкрементации итератора после конца
    Chain2<int>::Iterator endIt = chain.end();
    if (endIt != chain.end()) ++endIt;  // Предотвращаем инкремент за пределами end
    assert(endIt == chain.end());

    // Проверка на пустую цепь
    Chain2<int> emptyChain;
    assert(emptyChain.begin() == emptyChain.end());

    std::cout << "All tests passed!" << std::endl;
}


    int main() {
        std::vector<int> vec = { 10, 20, 30, 40, 50 };

        // Пример использования for_each для обхода всех элементов
        // for_each применяет переданную лямбда-функцию к каждому элементу контейнера
        std::for_each(vec.begin(), vec.end(), [](int& value) {
            std::cout << value << " ";
            });
        std::cout << std::endl;

        // Пример использования any_of (true, если хотя бы один элемент больше 25)
        // any_of возвращает true, если хотя бы один элемент удовлетворяет условию
        bool hasGreaterThan25 = std::any_of(vec.begin(), vec.end(), [](int value) {
            return value > 25;
            });
        std::cout << "Any greater than 25: " << hasGreaterThan25 << std::endl;

        // Пример использования all_of (true, если все элементы больше 5)
        // all_of возвращает true, если все элементы удовлетворяют условию
        bool allGreaterThan5 = std::all_of(vec.begin(), vec.end(), [](int value) {
            return value > 5;
            });
        std::cout << "All greater than 5: " << allGreaterThan5 << std::endl;

        // Пример использования none_of (true, если ни один элемент не меньше 5)
        // none_of возвращает true, если ни один элемент не удовлетворяет условию
        bool noneLessThan5 = std::none_of(vec.begin(), vec.end(), [](int value) {
            return value < 5;
            });
        std::cout << "None less than 5: " << noneLessThan5 << std::endl;

        // Пример использования transform для изменения каждого элемента
        // transform применяет лямбду к каждому элементу vec и записывает результат в transformedVec
        std::vector<int> transformedVec;
        std::transform(vec.begin(), vec.end(), std::back_inserter(transformedVec), [](int value) {
            return value * 2;
            });
        std::for_each(transformedVec.begin(), transformedVec.end(), [](int& value) {
            std::cout << value << " ";
            });
        std::cout << std::endl;

        // Пример использования copy_if для копирования элементов, удовлетворяющих условию
        // copy_if копирует элементы vec, соответствующие условию, в filteredVec
        std::vector<int> filteredVec;
        std::copy_if(vec.begin(), vec.end(), std::back_inserter(filteredVec), [](int value) {
            return value > 15;
            });
        std::for_each(filteredVec.begin(), filteredVec.end(), [](int& value) {
            std::cout << value << " ";
            });
        std::cout << std::endl;

        test();

        return 0;
    }

