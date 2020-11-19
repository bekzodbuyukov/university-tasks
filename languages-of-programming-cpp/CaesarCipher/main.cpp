#include <iostream>
#include <string>
using namespace std;

// функция чтобы получить исходный текст от пользователя
string getText() {
    string text;

    cout <<  "Enter your name: ";
    cin >> text;

    return text;
}

// функция чтобы вычислить длину текста
int getStringLength(const string& text) {
    return text.length();
}

// функция чтобы получить ключ от пользователя
int geyKey() {
    int keyValue;

    cout << "Enter the key: ";
    cin >> keyValue;

    return keyValue;
}

// функция сделает все буквы полученного от пользователя текста заглавными, чтобы было легче работать
string makeLettersUpperCase(string text) {
    for_each(text.begin(), text.end(), [](char & c){
        c = ::toupper(c);
    });

    return text;
}

// функция чтобы заполнить массив чисел (каждый элемент массива, это каждая буква текста, приведенного к типу int)
int * fillIntArray(string text, int * array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        array[i] = (int)text[i];
    }
    return array;
}

// функция для шифрования
int * cipherArray(int * array, int arraySize, int key) {
    for (int i = 0; i < arraySize; ++i) {
        array[i] = (array[i] + key) % 255;
    }

    return array;
}

// функция для дешифрования
int * unCipherArray(int * array, int arraySize, int key) {
    for (int i = 0; i < arraySize; ++i) {
        array[i] = (array[i] - key + 255) % 255;
    }

    return array;
}

// функция для вывода элементов массива на консоль
void printArray(int * array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        cout << (char)array[i] << "";
    }
}

// главная функция
int main() {
    // необходимые объявления
    string text;
    int stringSize, key;

    // получаем данные
    text = makeLettersUpperCase(getText());
    stringSize = getStringLength(text);
    key = geyKey();

    // объявляем массив чисел
    int * array = new int[stringSize];

    // заполняем и шифруем массив чисел
    array = fillIntArray(text, array, stringSize);
    array = cipherArray(array, stringSize, key);

    // вывод отшифрованного массива чисел в виде текста
    cout << "Your ciphered text: ";
    printArray(array, stringSize);

    // дешифруем массив чисел
    array = unCipherArray(array, stringSize, key);

    // вывод дешированного массива чисел в виде текста
    cout << "\nYour unciphered text: ";
    printArray(array, stringSize);

    return 0;
}