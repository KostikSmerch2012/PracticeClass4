#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>

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
    const int width = 160;
    const int height = 40;
    
    char graph[height][width];
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            graph[i][j] = ' ';
        }
    }
    
    for (int i = 0; i < width; i++) {
        graph[height/2][i] = '-';
    }
    for (int i = 0; i < height; i++) {
        graph[i][width/2] = '|';
    }
    graph[height/2][width/2] = '+';
    
    for (int x = 0; x < width; x++) {
        double x_val = (x - width/2) * 4.0 * M_PI / width;
        double y_val = sin(x_val);
        int y = height/2 - (y_val * (height/2 - 1));
        
        if (y >= 0 && y < height) {
            graph[y][x] = '*';
        }
    }
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
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
void task4_6(){
    int n = 3;
    
    int** C = new int*[n];
    for(int i = 0; i < n; i++) {
        C[i] = new int[2];
    }
    
    C[0][0] = 1; C[0][1] = 2;
    C[1][0] = 3; C[1][1] = 4;
    C[2][0] = 5; C[2][1] = 6;
    
    int maxMoneyIdx = 0, minMoneyIdx = 0;
    int maxComIdx = 0, minComIdx = 0;
    int totalMoney = 0, totalCom = 0;
    
    for(int i = 0; i < n; i++) {
        if(C[i][0] > C[maxMoneyIdx][0]) maxMoneyIdx = i;
        if(C[i][0] < C[minMoneyIdx][0]) minMoneyIdx = i;
        if(C[i][1] > C[maxComIdx][1]) maxComIdx = i;
        if(C[i][1] < C[minComIdx][1]) minComIdx = i;
        totalMoney += C[i][0];
        totalCom += C[i][1];
    }
    
    cout << "Матрица C:\n";
    for(int i = 0; i < n; i++) {
        cout << C[i][0] << " " << C[i][1] << endl;
    }
    
    cout << "\n1) Больше всего получил денег " << maxMoneyIdx+1 
         << " продавец, меньше - " << minMoneyIdx+1 << " продавец\n";
    cout << "2) Больше всего получил комиссионных " << maxComIdx+1 
         << " продавец, меньше - " << minComIdx+1 << " продавец\n";
    cout << "3) Общая сумма денег: " << totalMoney << "\n";
    cout << "4) Общая сумма комиссионных: " << totalCom << "\n";
    cout << "5) Всего прошло денег: " << totalMoney + totalCom << "\n";
    
    for(int i = 0; i < n; i++) {
        delete[] C[i];
    }
    delete[] C;
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
    case 6:
      task4_6();
      break;
    default:
      cout << "Нету такой таски" << endl;
      break;
    }
    return 0;
}
