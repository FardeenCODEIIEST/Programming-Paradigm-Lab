package Shapes;

import java.util.Scanner;

public abstract class Plots {
  public abstract void readInfo();

  public abstract double calcArea();

  public static void main(String[] args) {
    System.out.println("Enter the total number of components of the plot");
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    double totarea = 0;
    for (int i = 0; i < n; i++) {
      System.out.println("Enter \n1. Triangle\n2. Circle\n3.Rectangle");
      int ch = sc.nextInt();
      if (ch == 1) {
        Plots triangle = new Triangle();
        triangle.readInfo();
        totarea += triangle.calcArea();
      }

      else if (ch == 2) {
        Plots circle = new Circle();
        circle.readInfo();
        totarea += circle.calcArea();
      }

      else if (ch == 3) {
        Plots rect = new Rectangle();
        rect.readInfo();
        ;
        totarea += rect.calcArea();
      } else {
        System.out.println("Wrong input");
        i--;
      }
    }
    System.out.println("The total area is: " + totarea);
    sc.close();
  }
}

class Triangle extends Plots {
  double base;
  double height;

  Scanner sc = new Scanner(System.in);

  public void readInfo() {
    System.out.println("Enter the height of the triangle");
    double h = sc.nextDouble();
    System.out.println("Enter the base of the triangle");
    double b = sc.nextDouble();
    this.base = b;
    this.height = h;
  }

  public double calcArea() {
    return 0.5 * base * height;
  }
}

class Rectangle extends Plots {
  double length;
  double width;

  Scanner sc = new Scanner(System.in);

  public void readInfo() {
    System.out.println("Enter the length of the Rectangle");
    double l = sc.nextDouble();
    System.out.println("Enter the width of the Rectangle");
    double w = sc.nextDouble();
    this.length = l;
    this.width = w;
  }

  public double calcArea() {
    return length * width;
  }

}

class Circle extends Plots {
  double radius;

  final double pi = Math.PI;
  Scanner sc = new Scanner(System.in);

  public void readInfo() {
    System.out.println("Enter the radius of the circle");
    double rad = sc.nextDouble();
    this.radius = rad;
  }

  public double calcArea() {
    return pi * radius * radius;
  }

}