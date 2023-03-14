package Assignment05;

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
      System.out.println("Enter the roll no.");
      int n1 = sc.nextInt();
      System.out.println("Enter the id");
      String id1 = sc.next();
      System.out.println("Enter the Department");
      String dep = sc.next();
      arr[i].setData(sname, n1, id1, dep);
    }
    System.out.println("The records are:");
    for (int i = 0; i < size; i++) {// Displaying objects
      arr[i].display();
    }
    sc.close();
  }
}

class Student {
  int roll;
  String name;
  String id;
  String dept;

  public void setData(String name, int roll, String id, String dept) {
    this.name = name;
    this.roll = roll;
    this.id = id;
    this.dept = dept;
  }

  public void display() {
    System.out
        .println(" Name is :" + name + " Roll is :" + roll + " ID is:" + id + " Department is:" + dept);
  }
}