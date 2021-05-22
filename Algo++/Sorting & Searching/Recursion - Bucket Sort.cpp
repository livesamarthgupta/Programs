#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    int marks;
    string name;
};

void bucket_sort(Student *s, int n) {
    //assuming 100
    vector<Student> v[101];

    for(int i = 0; i < n; i++) {
        int m = s[i].marks;
        v[m].push_back(s[i]);
    }

    for(int i = 100; i >= 0; i--) {
        for(auto stud : v[i]) {
            cout<<stud.name<<" "<<stud.marks<<endl;
        }
    }
}


int main() {
    int n;
    cin>>n;
    Student s[n];
    for(int i = 0; i < n; i++) {
        cin>>s[i].name>>s[i].marks;
    }

    bucket_sort(s, n);

}
