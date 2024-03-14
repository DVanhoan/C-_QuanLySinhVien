#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Date {
    int day, month, year;
};

struct Student {
    string name;
    Date dob;
    float mathMark, physicMark, languageMark;
    Student* next;
};

class StudentList {
private:
    Student* head;

public:
    StudentList() {
        head = nullptr;
    }

    ~StudentList() {
        // Hủy danh sách sinh viên, giải phóng bộ nhớ
        while (head != nullptr) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addStudent(string name, int day, int month, int year,
        float mathMark, float physicMark, float languageMark) {

        Student* newStudent = new Student;
        newStudent->name = name;
        newStudent->dob.day = day;
        newStudent->dob.month = month;
        newStudent->dob.year = year;
        newStudent->mathMark = mathMark;
        newStudent->physicMark = physicMark;
        newStudent->languageMark = languageMark;
        newStudent->next = nullptr;

        if (head == nullptr) {
            head = newStudent;
        }
        else {
            Student* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
    }

    void addStudentFromInput() {
        string name;
        int day, month, year;
        float mathMark, physicMark, languageMark;

        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter student's date of birth (day month year): ";
        cin >> day >> month >> year;
        cout << "Enter math mark: ";
        cin >> mathMark;
        cout << "Enter physics mark: ";
        cin >> physicMark;
        cout << "Enter language mark: ";
        cin >> languageMark;

        addStudent(name, day, month, year, mathMark, physicMark, languageMark);
    }

    void printList() {
        if (head == nullptr) {
            cout << "Student list is empty." << endl;
            return;
        }
        Student* temp = head;
        while (temp != nullptr) {
            cout << "Name: " << temp->name
                << ", DOB: " << temp->dob.day << "/" << temp->dob.month << "/" << temp->dob.year
                << ", Math: " << temp->mathMark
                << ", Physics: " << temp->physicMark
                << ", Language: " << temp->languageMark << endl;
            temp = temp->next;
        }
    }

    int countStudentsInYear(int year) {
        int count = 0;
        Student* temp = head;
        while (temp != nullptr) {
            if (temp->dob.year == year) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }

    bool checkStudentExists(string name) {
        Student* temp = head;
        while (temp != nullptr) {
            if (temp->name == name) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void deleteStudentByName(string name) {
        if (head == nullptr) {
            cout << "Student list is empty." << endl;
            return;
        }

        if (head->name == name) {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Student " << name << " has been deleted from the list." << endl;
            return;
        }

        Student* prev = head;
        Student* curr = head->next;
        while (curr != nullptr) {
            if (curr->name == name) {
                prev->next = curr->next;
                delete curr;
                cout << "Student " << name << " has been deleted from the list." << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Student " << name << " not found in the list." << endl;
    }

    void findHighestAverage() {
        if (head == nullptr) {
            cout << "Student list is empty." << endl;
            return;
        }

        float maxAvg = -1;
        Student* maxStudent = nullptr;

        Student* temp = head;
        while (temp != nullptr) {
            float avg = (temp->mathMark + temp->physicMark + temp->languageMark) / 3.0;
            if (avg > maxAvg) {
                maxAvg = avg;
                maxStudent = temp;
            }
            temp = temp->next;
        }

        cout << "Student(s) with highest average marks: " << endl;
        cout << "Name: " << maxStudent->name << ", Math: " << maxStudent->mathMark
            << ", Physics: " << maxStudent->physicMark << ", Language: " << maxStudent->languageMark << endl;
    }

    void printMathLessThan5() {
        if (head == nullptr) {
            cout << "Student list is empty." << endl;
            return;
        }
        Student* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->mathMark < 5) {
                cout << "Name: " << temp->name << ", Math: " << temp->mathMark << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No student has a math mark less than 5." << endl;
        }
    }

    void writeToFile(string filename) {
        ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            cout << "Unable to open file for writing." << endl;
            return;
        }

        if (head == nullptr) {
            cout << "Student list is empty." << endl;
            outputFile.close();
            return;
        }

        Student* temp = head;
        while (temp != nullptr) {
            outputFile << "Name: " << temp->name << ", DOB: " << temp->dob.day << "/" << temp->dob.month << "/" << temp->dob.year
                << ", Math: " << temp->mathMark << ", Physics: " << temp->physicMark << ", Language: " << temp->languageMark << endl;
            temp = temp->next;
        }

        cout << "Student list has been written to the file: " << filename << endl;
        outputFile.close();
    }
};

int main() {
    StudentList studentList;
    int choice;
    while (true) {
        cout << "\n1. Input student information.\n"
            << "2. Print out the student list.\n"
            << "3. Add a new student to the list.\n"
            << "4. Count the number of students in a given year of birth.\n"
            << "5. Check if a student name exists in the list or not.\n"
            << "6. Delete a student from the list by a given name.\n"
            << "7. Find the student(s) having the biggest average of math, physics, and language marks.\n"
            << "8. Print the list of students whose math mark is less than 5.\n"
            << "9. Write the student list to a file named StudentList.txt.\n"
            << "10. Exit\n"
            << "Choose: ";
        cin >> choice;

        
        if(choice==1){
        	studentList.addStudentFromInput();
		}
        else if(choice==2){
        	studentList.printList();
		}    
        else if(choice==3){
        	studentList.addStudentFromInput();
		}
        else if(choice==4){
        	int year;
            cout << "Enter year: ";
            cin >> year;
            cout << "Number of students born in " << year << " is: " << studentList.countStudentsInYear(year) << " student(s)." << endl;
		}
        else if(choice==5){
        	string name;
            cout << "Enter student name: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, name);
            if (studentList.checkStudentExists(name)) {
                cout << "Student " << name << " exists in the list." << endl;
            }
            else {
                cout << "Student " << name << " does not exist in the list." << endl;
            }
		}
        else if(choice==6){
        	string name;
        	cout << "Enter student name to delete: ";
            cin.ignore();
            getline(cin, name);
            studentList.deleteStudentByName(name);
		}
        else if(choice==7){
        	studentList.findHighestAverage();
		}
        else if(choice==8){
        	studentList.printMathLessThan5();
		}
        else if(choice==9){
        	studentList.writeToFile("StudentList.txt");
		}
        else if(choice==10){
        	return 0;
		}
        
        else{
        	cout << "Invalid choice. Please choose again." << endl;
		}
    }
    return 0;
}
