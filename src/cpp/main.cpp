#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <stdio.h>
#include <stdbool.h>
#include<algorithm>
#include <cstring>


#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

using namespace std;
using namespace std::filesystem;
//namespace fs = std::filesystem;

class GFG {
public:
    GFG() {
        while (true) {
            cout << "\n1) List of programming languages of the search result.\n"
                 << "2) Reload the list of the links.\n"
                 << "3) New search.\n"
                 << "4) Exit.\n";
            int condition;
            cin >> condition;
            switch (condition) {
                case 1: {
                    GetLanguages();
                    break;
                }
                case 2: {
                    ReloadLinks();
                    break;
                }
                case 3: {
                    NewSearch();
                    return;
                }
                case 4:
                    return;
                default:
                    cout << "Invalid input!!!\n";
                    break;
            }
        }

    }

    ~GFG() {
        cout << "\nThank you for using GFG!!!\n"
             << "For any comments, contact: masoud.vahid10@gmail.com\n";
    }

private:
    static void GetLanguages() {
        vector<string> available_languages;
        string path = "search_results/Codes";
        for (const auto &entry : /*fs::*/directory_iterator(path)) {
            ifstream code_file(entry.path());
            string line_of_language_name;
            for (int i = 0; i < 4; ++i) {
                getline(code_file, line_of_language_name);
                string languages[] = {"C++", "C#", "Java", "Python", "C", "php", "script"};
                for (auto &language : languages) {
                    if (line_of_language_name.find(language) != std::string::npos) {
                        string old_name = entry.path();
                        string new_name = path + "/" += language += ".txt";
                        rename(old_name.c_str(), new_name.c_str());
                        available_languages.push_back(language);
                        break;
                    }
                }
            }
        }
        cout << "\nList of available languages: \n";
        for (int i = 0; i < available_languages.size(); ++i)
            cout << i + 1 << ") " << available_languages[i] << endl;
        cout << "\nEnter the index for desired language: \n";
        int index_of_language;
        cin >> index_of_language;
        system(("gedit " + path + "/" + available_languages[index_of_language - 1] + "").c_str());
    }

    static void ReloadLinks() {
        string path = "search_results/Links.txt";
        ifstream links_list(path);
        string line;
        while (getline(links_list, line))
            cout << line << endl;
        links_list.close();
    }

    static void NewSearch() {
        if (fork())
            execlp("python3", "python3", "src/Python/main.py", NULL);
    }

};

int main() {
    GFG gfg;

    return 0;
}
