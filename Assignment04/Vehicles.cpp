#include <iostream>
#include <iomanip>
using namespace std;

class Vehicle
{
private:
  double price;
  string manufacturer;

public:
  Vehicle();
  Vehicle(const float, const string);
  Vehicle(const Vehicle &);
  Vehicle operator=(const Vehicle &);
  void read();
  void display();
  ~Vehicle();
};

Vehicle::Vehicle()
{
  price = 0;
  manufacturer = "";
}

Vehicle::Vehicle(const float pr, const string s)
{
  price = pr;
  manufacturer = s;
}

Vehicle::Vehicle(const Vehicle &V)
{
  price = V.price;
  manufacturer = V.manufacturer;
}

Vehicle Vehicle::operator=(const Vehicle &V)
{
  Vehicle ans;
  ans.price = V.price;
  ans.manufacturer = V.manufacturer;
  return ans;
}

void Vehicle::read()
{
  if (manufacturer != "")
  {
    manufacturer = "";
  }
  cout << "Enter the Price of the Vehicle\n";
  cin >> price;
  cout << "Enter the name of the Manufacturer\n";
  cin >> manufacturer;
}

void Vehicle::display()
{
  cout << "Price of the vehicle is:\n"
       << price << "\n";
  cout << "Manufacturer of the vehicle is:\n"
       << manufacturer << "\n";
}

Vehicle::~Vehicle()
{
  if (manufacturer != "")
  {
    manufacturer = "";
  }
}

class Car : public Vehicle
{
private:
  string Color;
  int NumberOfSeats;
  string Model;

public:
  Car();
  Car(const float, const string, const string, const int, const string);
  Car(const Car &);
  Car operator=(const Car &);
  void read();
  void display();
  ~Car();
};

Car::Car()
{
  Color = "";
  NumberOfSeats = 0;
  Model = "";
}

Car::Car(const float p, const string n1, const string c, const int n, const string m) : Vehicle(p, n1)
{
  Color = c;
  NumberOfSeats = n;
  Model = m;
}

Car::Car(const Car &C) : Vehicle(C)
{
  Color = C.Color;
  NumberOfSeats = C.NumberOfSeats;
  Model = C.Model;
}

Car Car::operator=(const Car &C)
{
  Car res;
  (Vehicle &)res = C;
  res.Color = C.Color;
  res.Model = C.Model;
  res.NumberOfSeats = C.NumberOfSeats;
  return res;
}

void Car::read()
{
  Vehicle::read(); // reading the price and manufacturer
  cout << "Enter the color:\n";
  cin >> Color;
  cout << "Enter the number of seats:\n";
  cin >> NumberOfSeats;
  cout << "Enter the Model:\n";
  cin >> Model;
}

void Car::display()
{
  Vehicle::display();
  cout << "The color of the car is:\n"
       << Color << "\n";
  cout << "The number of seats in the car is:\n"
       << NumberOfSeats << "\n";
  cout << "The Model of the car is:\n"
       << Model << "\n";
}

Car::~Car()
{
  NumberOfSeats = 0;
  Model = "";
  Color = "";
}

int main()
{
  cout << fixed << setprecision(4);
  cout << "\t\t Vehicle and Car Simulation in C++\n";
  Vehicle v1;
  v1.read();
  cout << "Vehicle 1 is:\n";
  v1.display();
  Vehicle v2(v1);
  cout << "Vehicle 2 is:\n";
  v2.display();
  Vehicle v3(9999998.98, "Ford");
  cout << "Vehicle 3 is:\n";
  v3.display();
  Vehicle v4 = v3;
  cout << "Vehicle 4 same as 3:\n";
  v4.display();
  Car c1;
  c1.read();
  cout << "Car C1 is:\n";
  c1.display();
  Car c2(c1);
  cout << "Car C2 is:\n";
  c2.display();
  Car c3(10000900.98, "Pagani", "Navy-Blue", 2, "FX-67");
  cout << "Car C3 is:\n";
  c3.display();
  Car c4 = c3;
  cout << "Car 4 is:\n";
  c4.display();
  return 0;
}
