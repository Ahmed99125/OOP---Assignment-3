#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
// File name: A3_SheetPb05_20220309
// Purpose: make task manager
// Author(s): mohamed mostafa ali
// ID(s): 20220309
// Section: s23
// Date: 9/12/2023
string removeSpaces(string s){
    int start =0 , end = 0;

    for(int i =0 ; i< s.size(); i++){
        if(s[i] != ' '){
            start= i;
            break;
        }
    }
    for(int i = s.size()-1; i>=0 ; i--){
        if(s[i] != ' '){
            end = i;
            break;
        }
    }
    return s.substr(start, end-start+1);
}
enum SortingCriteria {
    NAME,
    ID,
    MEMORY_USAGE
};

class Process {
public:
    Process(string name, int PID, int memoryUsage , string memoryUsageUnit,string sessionName,string sessionNumber)
            : name(name), PID(PID), memoryUsage(memoryUsage), memoryUsageUnit(memoryUsageUnit)
            , sessionNumber(sessionNumber),sessionName(sessionName){}

    bool operator<(const Process& other) const {
        switch (sortingCriteria) {
            case NAME:
                return name < other.name;
            case ID:
                return PID < other.PID;
            case MEMORY_USAGE:
                return memoryUsage < other.memoryUsage;
            default:
                return false;
        }
    }

    void printInfo() const {
        cout << "Name: " << name << ", PID: " << PID << ", Memory Usage: " << memoryUsage << memoryUsageUnit << " "<<
        ", session Name: "<< sessionName<< ", session Number: "<< sessionNumber << endl ;
    }

    static SortingCriteria getSortingCriteria() {
        return sortingCriteria;
    }

    static void setSortingCriteria(SortingCriteria criteria) {
        sortingCriteria = criteria;
    }

private:
    string name;
    int PID;
    int memoryUsage;
    string memoryUsageUnit;
    string sessionName;
    string sessionNumber;

    static SortingCriteria sortingCriteria;
};

SortingCriteria Process::sortingCriteria = NAME;

class ListOfProcesses {
public:
    void addProcess(const Process& process) {
        processes.push_back(process);
    }

    void printSorted()  {
        vector<Process> sortedProcesses = processes;
        sort(sortedProcesses.begin(), sortedProcesses.end());
        for (const auto& process : sortedProcesses) {
            process.printInfo();
        }
    }

    void loadOSList(){
        system("tasklist > tasks.txt");
        fstream f1("tasks.txt");
        // skip first three lines
        for(int i = 0 ; i< 3; i++){
            string dummy;
            getline(f1,dummy);
        }
        while(true){
            string name;
            string PID;
            string memoryUsage;
            string memoryUsageUnit;
            string sessionName;
            string sessionNumber;

            // load name
           for(int i = 0 ; i < 26; i++){
               char c;
               f1.get(c);
               name += c;
           }
            name = removeSpaces(name);
            //load PID
           for(int i = 0 ; i < 9; i++){
               char c;
               f1.get(c);
               PID += c;
           }
            PID = removeSpaces(PID);
            //load sessionName
           for(int i = 0 ; i < 17; i++){
               char c;
               f1.get(c);
               sessionName += c;
           }
            sessionName = removeSpaces(sessionName);
            // load sessionNumber
           for(int i = 0 ; i < 12; i++){
               char c;
               f1.get(c);
               sessionNumber += c;
           }
            sessionNumber = removeSpaces(sessionNumber);
            // load memoryUsage
           for(int i = 0 ; i < 11; i++){
               char c;
               f1.get(c);
               if(c == ',')continue;
               memoryUsage += c;
            }
            memoryUsage = removeSpaces(memoryUsage);
            // load memoryUsageUnit
            for(int i = 0 ; i < 2; i++){
                char c;
                f1.get(c);
                if(c == '\n')continue;
                memoryUsageUnit += c;
            }
            memoryUsageUnit = removeSpaces(memoryUsageUnit);
            if(f1.fail()){
                break;
            }
            //cout << name << endl << PID << endl << memoryUsage <<endl;
            addProcess(Process(name, stoi(PID),stoi(memoryUsage),memoryUsageUnit,sessionName,sessionNumber));

        }
    }
private:
    vector<Process> processes;


};
ListOfProcesses listOfProcesses;
bool display(){


    cout << "Choose sorting criteria:\n"
         << "1. Name\n"
         << "2. ID\n"
         << "3. Memory Usage\n"
         << "4. load list of process from OS \n"
         << "5. exit\n";


    int choice;
    cin >> choice;

    SortingCriteria sortingCriteria;
    switch (choice) {
        case 1:
            sortingCriteria = NAME;
            break;
        case 2:
            sortingCriteria = ID;
            break;
        case 3:
            sortingCriteria = MEMORY_USAGE;
            break;
        case 4:
            listOfProcesses.loadOSList();
            break;
        case 5:
            return false;
        default:
            std::cerr << "Invalid choice\n";
            return true;
    }
    Process::setSortingCriteria(sortingCriteria);
    if(choice != 4) listOfProcesses.printSorted();
    return true;
}

int main() {

while(display()){

}

    return 0;
}
