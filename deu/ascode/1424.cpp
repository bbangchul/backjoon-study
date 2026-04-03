#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int id;
    vector<int> score;

    Student(string name, int id, vector<int> score)
    {
        this->name = name;
        this->id = id;
        this->score = score;
    }

    int getMax()
    {
        return *max_element(score.begin(), score.end());
    }

    double getAvg()
    {
        double sum = 0;
        for (int s : score)
            sum += s;
        return sum / 5.0;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<Student> students;

        for (int i = 0; i < N; i++)
        {
            string name;
            int id;
            cin >> name >> id;

            vector<int> scores(5);
            for (int j = 0; j < 5; j++)
            {
                cin >> scores[j];
            }

            students.push_back(Student(name, id, scores));
        }

        for (auto &s : students)
        {
            cout << s.name << " ";
            cout << s.getMax() << " ";
            cout << fixed << setprecision(2) << s.getAvg() << "\n";
        }

        if (T > 0)
            cout << "\n";
    }

    return 0;
}