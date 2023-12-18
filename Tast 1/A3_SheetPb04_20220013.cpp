#include <iostream>

using namespace std;

template <typename T>
class Set {
private:
    int sz = 0;
    T *setArr;
public:
    Set() {
        setArr = new T[sz];
    }
    bool isExist(T x) {
        for (int i = 0; i < sz; i++) {
            if (setArr[i] == x)
                return true;
        }
        return false;
    }
    void add(T x) {
        if (!isExist(x)) {
            sz += 1;
            T *newArr = new T[sz];
            newArr[sz-1] = x;
            for (int i = 0; i < sz-1; i++) {
                newArr[i] = setArr[i];
            }
            for (int i = 0; i < sz; i++) {
                for (int j = i; j < sz; j++) {
                    if (newArr[i] > newArr[j])
                        swap(newArr[i], newArr[j]);
                }
            }
            delete []setArr;
            setArr = newArr;
            newArr = nullptr;
        }
    }
    void remove(T x) {
        if (isExist(x)) {
            sz -= 1;
            T *newArr = new T[sz];
            int cnt = 0;
            for (int i = 0; i < sz+1; i++) {
                if (setArr[i] != x)
                    newArr[cnt++] = setArr[i];
            }
            delete []setArr;
            setArr = newArr;
            newArr = nullptr;
        }
    }
    int size() {
        return sz;
    }
    T *getPtr() {
        return setArr;
    }
    ~Set() {
        delete []setArr;
    }
};

int main() {
    Set <int> st;
    st.add(5);
    st.add(2);
    st.add(2);
    st.add(3);
    st.remove(5);
    cout << boolalpha;
    cout << st.isExist(2) << endl;
    cout << st.isExist(5) << endl;
    int *ptr = st.getPtr();
    for (int i = 0; i < 2; i++)
        cout << ptr[i] << ' ';

    return 0;
}