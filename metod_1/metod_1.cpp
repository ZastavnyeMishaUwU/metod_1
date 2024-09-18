#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Filehandler {
private:
    ofstream file;
    string filename;

public:
    Filehandler(string filename) {
        this->filename = filename;
        file.open(filename);

        if (file.is_open()) {
            cout << "File is open!!!" << endl;
        }
        else {
            cout << "Error" << endl;
        }
    }

    void writeData(string data) {
        if (file.is_open()) {
            file << data << endl;
            cout << "Data is written!" << endl;
        }
        else {
            cout << "Data is NOT written!" << endl;
        }
    }

    void writeArray(const vector<string>& dataArray) {
        if (file.is_open()) {
            for (const string& data : dataArray) {
                file << data << endl;
            }
            cout << "Array is written!" << endl;
        }
        else {
            cout << "Array is NOT written!" << endl;
        }
    }

    ~Filehandler() {
        if (file.is_open()) {
            file.close();
        }
        cout << "Destructor. File is closed!" << endl;
    }
};

int main() {
    Filehandler filehandler("C:\\Users\\tutor\\Documents\\моя папка\\exemple.txt");

    filehandler.writeData("First record");
    filehandler.writeData("Second record");

    vector<string> dataArray = { "Array record 1", "Array record 2", "Array record 3" };
    filehandler.writeArray(dataArray);

    cout << "End!" << endl;
}
