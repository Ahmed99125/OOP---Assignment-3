#include <iostream>
#include <fstream>

using namespace std;

class LabelGenerator {
protected:
    int sequenceNumber;
    string name;
public:
    LabelGenerator(string s = "", int n = 0)
    : name{s}, sequenceNumber{n} {

    }
    virtual string nextLabel() {
        return (name + to_string(sequenceNumber++));
    }
    virtual ~LabelGenerator() {

    }
};

class FileLabelGenerator : public LabelGenerator {
private:
    ifstream file;
public:
    FileLabelGenerator(string s = "", int n = 0, string fileName = "")
    : LabelGenerator(s, n) {
        file.open(fileName);
    }
    virtual string nextLabel() {
        string line;
        getline(file, line);
        return (name + to_string(sequenceNumber++) + " " + line);
    }
    virtual ~FileLabelGenerator() {

    }
};

int main() {
    FileLabelGenerator figureLabels ("Figure ", 1, "labels.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++)
        cout << figureLabels.nextLabel() << endl;

    return 0;
}