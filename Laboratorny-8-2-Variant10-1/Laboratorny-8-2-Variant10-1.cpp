#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "ukr"); // дозволити використання української мови
    const int n = 5; // Задаємо розмір масиву
    int arr[n];
    // Змінні для збереження результатів
    int negativeCount = 0;
    int negativeProduct = 1;
    int firstPositiveIndex = -1;
    int lastPositiveIndex = -1;
    bool firstPositiveFound = false;
    int sumBetweenPositives = 0;
    // Заповнюємо масив та виконуємо обчислення критеріїв
    cout << "Введiть " << n << " цiлих чисел:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] < 0) {
            negativeCount++;
            negativeProduct *= arr[i];
        }
        else if (arr[i] > 0) {
            if (!firstPositiveFound) {
                firstPositiveIndex = i;
                firstPositiveFound = true;
            }
            lastPositiveIndex = i;
        }
    }
    // Обчислюємо суму між першим і останнім додатними елементами
    if (firstPositiveIndex != -1 && lastPositiveIndex != -1) {
        for (int i = firstPositiveIndex + 1; i < lastPositiveIndex; ++i) {
            sumBetweenPositives += arr[i];
        }
    }
    // Виводимо результати
    cout << "a) Кiлькiсть вiд'ємних елементiв: " << negativeCount << endl;
    cout << "   Добуток вiд'ємних елементiв: " << negativeProduct << endl;
    if (firstPositiveIndex != -1 && lastPositiveIndex != -1) {
        cout << "b) Сума елементiв мiж першим i останнiм додатнiми елементами: " << sumBetweenPositives << endl;
    }
    else {
        cout << "b) В масивi відсутнi додатнi елементи або всi елементи є додатнiми." << endl;
    }
    return 0;
}