#include <bits/stdc++.h>
using namespace std;
class Tools
{
private:
    //************************************************
    static double Grade_Weight(const string &Grade)
    {
        if (Grade == "A+")
            return 4;
        else if (Grade == "A")
            return 3.7;
        else if (Grade == "A-")
            return 3.4;
        else if (Grade == "B+")
            return 3.2;
        else if (Grade == "B")
            return 3;
        else if (Grade == "B-")
            return 2.8;
        else if (Grade == "C+")
            return 2.6;
        else if (Grade == "C")
            return 2.4;
        else if (Grade == "C-")
            return 2.2;
        else if (Grade == "D+")
            return 2;
        else if (Grade == "D")
            return 1.5;
        else if (Grade == "D-")
            return 1;
        else if (Grade == "F")
            return 0;
        else
            return -1;
    }
    //------------------------------------------------
    static void GPA_Uploading(const double &Total_Score, const int &Total_hrs)
    {
        ofstream Result("Result-File.txt", ios::app);
        string sentence = "Your GPA is ";
        double GPA = Total_Score / Total_hrs;
        sentence += to_string(GPA);
        Result << sentence << endl;
    }
    //------------------------------------------------
    static void lineToData(const string &line, string &grade, int &hrs, bool checker)
    {
        auto it = find(line.begin(), line.end(), '/');
        string hours = "";
        for (auto i = line.begin(); i != line.end(); i++)
        {
            if (i < it)
                grade.push_back(*i);
            else if (i > it)
                hours.push_back(*i);
        }
        try
        {
            hrs = stod(hours);
        }
        catch(const std::exception& e)
        {
            checker = false;
            return;
        }
    }
    //------------------------------------------------
    static void GPA_Calculator(const vector<string> &Grades, bool &checker)
    {
        int Total_hrs = 0;
        double Total_Score = 0;
        for (const auto &e : Grades)
        {
            int hrs;
            string grade = "";
            lineToData(e, grade, hrs, checker);
            double weight = Grade_Weight(grade);
            if (weight == -1 || !checker)
            {
                checker = false;
                return;
            }
            Total_Score += weight * hrs;
            Total_hrs += hrs;
        }
        GPA_Uploading(Total_Score, Total_hrs);
    }
    //------------------------------------------------
    static void GPA_Run()
    {
        bool checker = true;
        string fileName, line;
        vector<string> Grades;
        cout << "-Welcome to GPA Calculator-" << endl;
        cout << "Enter File name(with .txt): ";
        getline(cin >> ws, fileName);
        ifstream File(fileName);
        if (!File)
        {
            cout << "There is a mistake in your input file!" << endl;
            return;
        }
        while (getline(File, line))
        {
            Grades.push_back(line);
        }
        File.close();
        GPA_Calculator(Grades, checker);
        if (checker)
            cout << "Check your GPA in the Result file ;)" << endl;
        else
            cout << "There is a mistake in your input file!" << endl;
    }
    //************************************************
public:
    //------------------------------------------------
    static void GPA() { GPA_Run(); }
    //------------------------------------------------
};