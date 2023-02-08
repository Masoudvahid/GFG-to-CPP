//
// Created by masoud.
//

#ifndef GFG_OPERATION_H
#define GFG_OPERATION_H

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

class GFG_operations {
public:
    GFG_operations();

    ~GFG_operations();

private:
    void RenameFiles();

    void GetLanguages();

    void ReloadLinks();

    void NewSearch();

    std::vector <std::string> available_languages;
    std::string languages[7] = {"C++", "C#",  "Java",  "Python",
                                "C",   "php", "script"};
    std::string path_to_python_file = "src/sites_scraping_python/site_scraping.py";
public:
    std::string path_to_codes = "search_results/Codes";
    std::string path_to_links = "search_results/Links.txt";
};

class RunGFG : public GFG_operations {
public:
    RunGFG();

    void remove_codes_files();

};

#endif//GFG_OPERATION_H
