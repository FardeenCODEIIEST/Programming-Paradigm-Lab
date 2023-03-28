package Details;

import java.util.Scanner;

class Details {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number of students");
    int n = sc.nextInt();
    String[] name;
    name = new String[n];
    String[] roll;
    roll = new String[n];
    System.out.println("Enter the student details");
    for (int i = 0; i < n; i++) {
      System.out.println("Enter the name of the student");
      name[i] = sc.next();
      System.out.println("Enter the roll no. of the student");
      roll[i] = sc.next();
    }
    System.out.println("The student details are:");
    for (int i = 0; i < n; i++) {
      System.out.print("Name: ");
      System.out.print(name[i] + " | ");
      System.out.print("Rollno: ");
      System.out.println(roll[i]);
    }
    sc.close();
  }
}
