package CollegeRecords;

import java.util.*;

public class CollegeRecords {
  public static void main(String[] args) {
    System.out.println("Enter the student details");
    Scanner sc = new Scanner(System.in);
    Student st = new Student();
    st.readData();
    System.out.println("Enter the Professor details");
    Professor pf = new Professor();
    pf.readData();
    System.out.println("Student details are:");
    st.printData();
    System.out.println("Professor details are");
    pf.printData();
    sc.close();
  }
}

class Academic {
  String name;
  int age;
  char gender;
  String dept;

  Scanner sc = new Scanner(System.in);

  public void readData() {
    System.out.println("Enter the name of the student");
    String name1 = sc.next();
    System.out.println("Enter the age of the student");
    int age1 = sc.nextInt();
    System.out.println("Enter the gender");
    char gender1 = sc.next().charAt(0);
    System.out.println("Enter the department");
    String dept1 = sc.next();
    this.name = name1;
    this.age = age1;
    this.dept = dept1;
    this.gender = gender1;
  }

  public void printData() {
    System.out
        .print("Name is: " + name + "|" + " Age is: " + age + "|" + " Gender is: " + gender + "|" + " Department is: "
            + dept + "| ");
  }

}

class Student extends Academic {
  int year;

  public void readData() {
    super.readData();
    System.out.println("Enter the year");
    int year1 = sc.nextInt();
    this.year = year1;
  }

  public void printData() {
    super.printData();
    System.out.println("Year is: " + year);
  }

}

class Professor extends Academic {
  String courseload;
  double salary;

  public void readData() {
    super.readData();
    System.out.println("Enter the Courseload");
    String courseload1 = sc.next();
    System.out.println("Enter the salary");
    double salary1 = sc.nextDouble();
    this.courseload = courseload1;
    this.salary = salary1;
  }

  public void printData() {
    super.printData();
    System.out.println("CourseLoad is: " + courseload + "|" + " Salary is: " + salary);
  }

}
