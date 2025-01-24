#include "FCAI-Tools.h"
class Program
{
private:
    //------------------------------------------------
    static void header()
    {
        system("cls");
        cout << "---------------------------" << endl;
        cout << "FCAI PROGRAM BY GEORGE EZAT" << endl;
        cout << "---------------------------" << endl;
    }
    //------------------------------------------------
    void MainMenu()
    {
        header();
        cout << "Choose what you want to do: " << endl;
        cout << "---------------------------" << endl;
        cout << "1. Calculate GPA" << endl;
        cout << "0. exit" << endl;
        cout << "---------------------------" << endl;
    }
    //------------------------------------------------
    bool digitInput(string &temp)
    {
        getline(cin >> ws, temp);
        for (auto &c : temp)
        {
            if (!isdigit(c))
                return false;
        }
        return true;
    }
    //------------------------------------------------
    void cin_numbers(short &n)
    {
        string temp = "";
        while (!digitInput(temp))
        {
            cout << "\nPlease enter a valid number: ";
        }
        n = stoi(temp);
    }
    //------------------------------------------------
    void ProgramRun()
    {
        short choice;
        MainMenu();
        cin_numbers(choice);
        while (true)
        {
            if (choice == 1)
            {
                header();
                Tools::GPA();
                system("pause");
            }
            else if (choice == 0)
                break;
            else
            {
                while (choice > 1 || choice < 0)
                {
                    cout << "\nWrong choice my dear 0_0! , enter a valid one: ";
                    cin_numbers(choice);
                }
                continue;
            }
            MainMenu();
            cin_numbers(choice);
        }
    }
    //------------------------------------------------
public:
    //------------------------------------------------
    Program() { ProgramRun(); }
    //------------------------------------------------
};