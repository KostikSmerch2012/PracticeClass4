#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

void rectangle (){
  double a, b;
  cout << "Введите ширину и длинну прямоугольника" << endl;
  cin >> a;
  cin >> b;
  cout << "Площадь прямоугольника:" << a * b << endl;
}

void triangle (){
  cout << "Введите основание и высоту треугольника" << endl;
  double a, b;
  cin >> a;
  cin >> b;
  cout << "Площадь треугольника: " << a * b / 2 << endl;
}

void circle (){
  cout << "Введите радиус круга" << endl;
  double a;
  cin >> a;
  cout << "Площадь круга: " << 3.1415 * a << endl;
}

void task4_1 (){
  int x;
  cout << "Выберете фигуру: Прямоугольник - 1, Треугольник - 2, Круг - 3" << endl;
  cin >> x;
  switch (x) {
    case 1:
      rectangle();
      break;
    case 2:
      triangle();
      break;
    case 3:
      circle();
      break;
  }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int x;
    cout << "Выберите номер таски" << endl;
    cin >> x;
    cin.ignore();
    switch (x)
    {
    case 1:
        task4_1();
        break;
    }
    return 0;
}
