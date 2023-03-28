package Records;

import java.util.Scanner;

class Records {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number of students");
    int size = sc.nextInt();
    Student[] arr;
    arr = new Student[size];
    for (int i = 0; i < size; i++) {// Creating objects
      arr[i] = new Student();
    }
    System.out.println("Enter the details");
    for (int i = 0; i < size; i++) {// Declaring objects
      System.out.println("Enter the name");
      String sname = sc.next();
      System.out.println("Enter the age");
      int age = sc.nextInt();
      System.out.println("Enter the Department");
      String dep = sc.next();
      System.out.println("Enter the year");
      int year = sc.nextInt();
      arr[i].readData(sname, age, year, dep);
    }
    System.out.println("The records are:");
    for (int i = 0; i < size; i++) {// Displaying objects
      arr[i].printData();
    }
    sc.close();
  }
}

class Student {
  int age;
  String name;
  int year;
  String dept;

  public void readData(String name, int age, int year, String dept) {
    this.name = name;
    this.year = year;
    this.age = age;
    this.dept = dept;
  }

  public void printData() {
    System.out
        .println(" Name is :" + name + " Age is : " + age + " Year is:" + year + " Department is:" + dept);
  }
}