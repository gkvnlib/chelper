// THU VIEN HO TRO C++
using namespace std;

#ifndef HELPER_H
#define HELPER_H

// viet tat cho nhanh
#define ll long long
#define sc static_cast
#define ret return

#define cont continue
#define strg string
#define dbl double
#define flt float
#define brk break
#define var auto

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <type_traits>
#include <algorithm>
#include <random>
#include <math.h>

template <typename T>
class List {
private:
    std::vector<T> elements;
    // quicksort implementation O(n*log n)
    void quicksort(std::vector<T>& arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quicksort(arr, low, pivotIndex - 1);
            quicksort(arr, pivotIndex + 1, high);
        }
    }

    int partition(std::vector<T>& arr, int low, int high) {
        T pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }

public:
    // ensures optional
    List() {}
    // init list in
    List(std::initializer_list<T> initList) : elements(initList) {}
    // vector in
    List(const std::vector<T>& inputVector) : elements(inputVector) {}

    void add(const T& element) {
        elements.push_back(element);
    }

    void remove(const T& element) {
        auto it = std::find(elements.begin(), elements.end(), element);
        if (it != elements.end()) {
            elements.erase(it);
        }
    }

    T get(int index) const {
        return elements.at(index);
    }

    int size() const {
        return elements.size();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    auto begin() const {
        return elements.begin();
    }

    auto end() const {
        return elements.end();
    }

    template <typename Function>
    void forEach(Function func) {
        for (const auto& element : elements) {
            func(element);
        }
    }

    template <typename Predicate>
    void removeIf(Predicate pred) {
        elements.erase(std::remove_if(elements.begin(), elements.end(), pred), elements.end());
    }

    void quickSort() {
        quicksort(elements, 0, elements.size() - 1);
    }

    bool contains(const T& element) const {
        return std::find(elements.begin(), elements.end(), element) != elements.end();
    }

    bool isNumericList() {
        return std::is_arithmetic<T>::value;
    }

    void shuffle() {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::shuffle(elements.begin(), elements.end(), generator);
    }

    template<typename U = T>
    typename std::enable_if<std::is_arithmetic<U>::value, U>::type min() {
        return *std::min_element(elements.begin(), elements.end());
    }

    template<typename U = T>
    typename std::enable_if<std::is_arithmetic<U>::value, U>::type max() {
        return *std::max_element(elements.begin(), elements.end());
    }

    template<typename U = T>
    typename std::enable_if<std::is_arithmetic<U>::value, U>::type sum() {
        return std::accumulate(elements.begin(), elements.end(), U{});
    }

    T* toArray() {
        T* arr = new T[elements.size()];
        for (size_t i = 0; i < elements.size(); i++) {
            arr[i] = elements[i];
        }
        return arr;
    }

    std::vector<T> toVector() {
        return elements;
    }

    using ElementType = T;
    ElementType getElementType() const {
        return ElementType{};
    }
};

template <typename T>
std::string toString(const T& input) {
    if constexpr (std::is_arithmetic_v<T>) {
        return std::to_string(input);
    } else {
        return input;
    }
}

List<std::string> readf(const std::string& filePath) {
    List<std::string> myList;
    std::ifstream inputFile(filePath);

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            myList.add(line);
        }
        inputFile.close();
    } else {
        std::cout << "Error occured while reading " << filePath;
    }

    return myList;
}

void appendf(const std::string& filePath, const std::string& content) {
    std::ofstream outputFile(filePath, std::ios_base::app);

    if (outputFile.is_open()) {
        outputFile << content;
        outputFile.close();
    } else {
        std::cout << "Error occured while writing " << content << " to " << filePath;
    }
}

double sigma(int start, int end, std::function<double(int)> term) {
    double sum = 0.0;
    for (int i = start; i <= end; i++) {
        sum += term(i);
    }
    return sum;
}

template<typename... Args>
void cprint(const bool linebreak = true, Args&&... args) {
    (std::cout << ... << (args)) << (linebreak ? '\n' : '\0');
}

template<typename... Args>
void print(Args&&... args) {
    const bool linebreak = true;
    (std::cout << ... << (args)) << (linebreak ? '\n' : '\0');
}

// chuyen tu T[] thanh List<T>
template <typename T, size_t N>
List<T> fromArray(T (&arr)[N]) {
    List<T> newList;
    for (size_t i = 0; i < N; i++) {
        newList.add(arr[i]);
    }
    return newList;
}

template <typename T>
List<T> merge(const List<T>& list1, const List<T>& list2) {
    List<T> mergedList = list1;
    for (const auto& element : list2) {
        mergedList.add(element);
    }
    return mergedList;
}

template<typename T>
bool hasIntersection(const List<int>& list1, const List<T>& list2) {
    if (typeid(T) != typeid(list1.getElementType()) || typeid(T) != typeid(list2.getElementType())) {
        throw std::runtime_error("Type mismatch!");
    }

    for (const auto& element : list1) {
        if (list2.contains(element)) {
            return true;
        }
    }
    return false;
}

void enableboolprint() {
    std::cout << std::boolalpha;
}

#endif
