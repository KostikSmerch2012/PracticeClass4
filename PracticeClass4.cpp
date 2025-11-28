#include <iostream>
#include <math.h>
#include <cmath>


using namespace std;

void rectangle (){
  double a, b;
  cout << "Введите ширину и длинну прямоугольника" << endl;
  cin >> a;
  cin >> b;
  if (a > 0 && b > 0) {
      cout << "Площадь прямоугольника: " << a * b << endl;
  }
  else{
    cout << "Прямоугольник не существует" << endl;
    return;
  }

}

void triangle (){
  cout << "Введите стороны треугольника" << endl;
  double a, b, c;
  
  cin >> a;
  cin >> b;
  cin >> c;

  if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a) {
    double p = (a + b + c) / 2.0;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << "Площадь равна " << area << endl;
    return;
  }
  else{
    cout << "Треугольник не существует" << endl;
    return;
  }
}

void circle (){
  cout << "Введите радиус круга" << endl;
  double a;
  cin >> a;
  if (a > 0) {
    cout << "Площадь круга: " << 3.1415 * a << endl;
  }
  else{
    cout << "Круг не существует" << endl;
    return;
  }
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
    default:
    cout << "нету такого" << endl;
  }
}

void task4_2 (){
  cout << "\n🇷🇺 Russian Imperial Flag:\n";
  string whiteBlock = "████";
        
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 15; j++) {
      switch (i) {
        case 0: cout << "\033[30m" << whiteBlock; break;
        case 1: cout << "\033[30m" << whiteBlock; break;
        case 2: cout << "\033[38;5;130m" << whiteBlock; break;
        case 3: cout << "\033[38;5;130m" << whiteBlock; break;
        case 4: cout << "\033[0m" << whiteBlock; break;
        case 5: cout << "\033[0m" << whiteBlock; break;
      }
    }
    std::cout << "\033[0m\n";
  }
  std::cout << "\033[0m";
}

void task4_3(){
  cout << "a";
  return;
}

void psevdogen_1(int *count){
  int m, S, i, c;
  S = 0; m = 37; i = 3; c = 64;
  cout << S << " ";
  for(int j = 0; j < *count - 1; j++){
  S = (m * S + i) % c;
  cout << S << " ";
  }
}

void psevdogen_2(int *count){
  int m, S, i, c;
  S = 0; m = 25173; i = 13849; c = 65537;
  cout << S << " ";
  for(int j = 0; j < *count - 1; j++){
    S = (m * S + i) % c;
    cout << S << " ";
  }
}

void task4_4 (int* count){
  int i;
  cout << "Введите вариант: " << endl;
  cin >> i;
  cout << "Введите количество случайных чисел" << endl;
  cin >> *count;
  switch (i) {
    case 1:
      psevdogen_1(count);
      break;
    case 2:
      psevdogen_2(count);
      break;
  default:
      cout << "На выбор только 2 варианта есть";
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
    case 2:
        task4_2();
        break;
    case 3:
        task4_3();
        break;
    case 4:
      {
        int count;
        task4_4(&count);
        break;
      }
    default:
      cout << "Нету такой таски" << endl;
      break;
    }
    return 0;
}
