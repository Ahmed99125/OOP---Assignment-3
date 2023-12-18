#include "string"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;
// File name: A3_SheetPb02_20220309
// Purpose: make string set
// Author(s): mohamed mostafa ali
// ID(s): 20220309
// Section: s23
// Date: 9/12/2023
// header
//
//
class StringSet {
private:
    vector<string> set;
public:
    StringSet(string content);
    StringSet(string fileName,int i);
    StringSet();
    void AddString(string content);
    void RemoveString(string s);
    void ClearSet();
    int Size();
    string GetAllStrings();
    bool IsWordExist(string word);
    float CumputeSimilarity(StringSet other) ;
    StringSet operator + ( StringSet  other) ;
    StringSet operator * ( StringSet  other) ;

};

// implementation
//
//
//

StringSet::StringSet(string content) {
    string s1;
    for(int i = 0 ; i< content.size(); i++){
        content[i] = tolower(content[i]);
        if((content[i] >= 'a' && content[i] <= 'z') || content[i] == ' ' || content[i]== '\n') {
            s1 += content[i];
        }
    }
    int pos =0, pos1 = 0;
    while (!s1.empty()){
        pos =s1.find(' ') ;
        pos1 =s1.find('\n') ;
        if(pos == -1){
            pos = s1.size();
        }
        if(pos1 == -1 ){
            pos1 = s1.size();
        }
        pos = min(pos , pos1);
        string word =s1.substr(0,pos) ;

        if(!IsWordExist(word)){
            set.push_back(word);
        }
        s1.erase(0,pos+1);
    }

}

void StringSet::AddString(string content) {
    string s1;
    for(int i = 0 ; i< content.size(); i++){
        content[i] = tolower(content[i]);
        if((content[i] >= 'a' && content[i] <= 'z') || content[i] == ' '  || content[i]== '\n' ) {
            s1 += content[i];
        }
    }
    int pos =0, pos1 = 0;
    while (!s1.empty()){
        pos =s1.find(' ') ;
        pos1 =s1.find('\n') ;
        if(pos == -1){
            pos = s1.size();
        }
        if(pos1 == -1 ){
            pos1 = s1.size();
        }
        pos = min(pos , pos1);
        string word =s1.substr(0,pos) ;

        if(!IsWordExist(word)){
            set.push_back(word);
        }
        s1.erase(0,pos+1);
    }
}

void StringSet::RemoveString(string s) {
    for(int i = 0 ; i< s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    //Erase–remove idiom
    set.erase(std::remove(set.begin(), set.end(),s),set.end());
}

void StringSet::ClearSet() {
    set.clear();
}

int StringSet::Size() {
    return set.size();
}

string StringSet::GetAllStrings() {
    string res;
    for(int i =0 ; i< set.size(); i++){
        res += set[i] + "\n";
    }
    return res;
}

StringSet::StringSet(string fileName , int i ) {
    ifstream f1(fileName);
    if(!f1){
        cout << "Can't find this file";
        return;
    }
    while(true){
        string word,word1;
        f1 >> word;

        if(f1.fail()){
            break;
        }
        for(int i = 0 ; i< word.size(); i++){
            word[i] = tolower(word[i]);
            if((word[i] >= 'a' && word[i] <= 'z') || word[i] == ' ' ) {
                word1 += word[i];
            }
        }
        if(!IsWordExist(word)){
            set.push_back(word1);
        }

    }
}

StringSet StringSet::operator + ( StringSet  other){
    StringSet temp("");
    temp.AddString(this->GetAllStrings() + other.GetAllStrings());

    return temp ;
}

StringSet::StringSet() {
    set ={};
}

bool StringSet::IsWordExist(string word) {
    for (int i =0 ; i< set.size() ; i++){
        if(set[i] == word){
            return true;
        }
    }
    return false;
}

StringSet StringSet::operator*(StringSet other) {
    StringSet res;
    for(int i=0 ; i<this->Size(); i++ ){
        if(other.IsWordExist(this->set[i])){
            res.set.push_back(this->set[i]);
        }
    }
    return res;
}

float StringSet::CumputeSimilarity(StringSet other) {
    float res= ((*this * other).Size())/ (sqrt(this->Size())* sqrt(other.Size()));
    return res;
}


int main() {
    StringSet set1("hi my NAME is: Mohamed1");
    cout << "first set:\n"<< "size: " << set1.Size()<< endl <<"content:\n" << set1.GetAllStrings();
    set1.RemoveString("mohamed");
    cout << "first set:\n"<< "size: " << set1.Size()<< endl <<"content:\n" << set1.GetAllStrings();


    StringSet set2("test.txt",0);
    cout <<"second set:\n" << "size: " << set2.Size()<< endl <<"content:\n" <<set2.GetAllStrings();

    StringSet intersectoin = set1* set2;
    cout<< "the intersection of set1 and set2:\n" << "size: " <<  intersectoin.Size()<< endl <<"content:\n" << intersectoin.GetAllStrings();

    cout<< "similarity of set1 and set2: " << set1.CumputeSimilarity(set2)<< endl;

    StringSet sum;
    sum = set1 + set2;
    cout<< "sum set:\n"<< "size: " << sum.Size()<< endl <<"content:\n" <<sum.GetAllStrings();
    sum.ClearSet();
    cout<< "cleared set:\n"<< "size: " << sum.Size()<< endl <<"content:\n" <<sum.GetAllStrings();

    return 0;
}
