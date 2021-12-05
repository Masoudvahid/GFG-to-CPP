#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <algorithm>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std::filesystem;
//namespace fs = std::filesystem;

class GFG {
public:
    GFG() {
    	NewSearch();
    	RenameFiles();
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

	void RenameFiles() {
		string path = "search_results/Codes";
		int counter = 0;
		for (const auto &entry : /*fs::*/directory_iterator(path)) {
		    ifstream code_file(entry.path());
		    string line_of_language_name;
		    for (int i = 0; i < 4; ++i) {
		        getline(code_file, line_of_language_name);
		        string languages[] = {"C++", "C#", "Java", "Python", "C", "php", "script"};
		        for (auto &language : languages) {
		            if (line_of_language_name.find(language) != std::string::npos) {
		                string old_name = entry.path();
		                string new_name = path + "/" += to_string(counter) += "_" + language += ".txt";
		                rename(old_name.c_str(), new_name.c_str());
		                available_languages.push_back(language);
		                counter++;
		                break;
		            }
		        }
		    }
		}
	}

    void GetLanguages() {
        cout << "\nList of available languages: \n";
        for (int i = 0; i < available_languages.size(); ++i)
            cout << i + 1 << ") " << available_languages[i] << endl;
        cout << "\nEnter the index for desired language: \n";
        int index_of_language;
        cin >> index_of_language;
        system(("gedit " + path + "/" + to_string(index_of_language - 1) + "_" + available_languages[index_of_language - 1] + ".txt").c_str());
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
        pid_t pid;
    	if ((pid = fork()) == 0)
    	    execlp("python3", "python3", "src/main.py", nullptr);
    	waitpid(pid, NULL, 0);
    }
    
	vector<string> available_languages;
	string path = "search_results/Codes";
};

int main() {    
    GFG gfg;
    
    return 0;
}
