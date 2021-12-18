  

class GFG_operations {
public:
    GFG_operations() {
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

    ~GFG_operations() {
        cout << "\nThank you for using GFG_operations!!!\n"
             << "For any comments, contact: masoud.vahid10@gmail.com\n";
    }

private:
    void RenameFiles();

    void GetLanguages();

    void ReloadLinks();

    void NewSearch();

    vector<string> available_languages;
    string languages[7] = {"C++", "C#", "Java", "Python", "C", "php", "script"};
    string path_to_codes = "search_results/Codes";
    string path_to_links = "search_results/Links.txt";
    string path_to_python_file = "sites_scraping_python/site_scraping.py";
};

void GFG_operations::RenameFiles() {
    int counter = 0;
    for (const auto &entry : fs::directory_iterator(path_to_codes)) {
        ifstream code_file(entry.path());
        string line_of_language_name;
        for (int rename_iter = 0; rename_iter < 4; ++rename_iter) {
            getline(code_file, line_of_language_name);
            for (auto &language : languages) {
                if (line_of_language_name.find(language) != std::string::npos) {
                    string old_name = entry.path();
                    string new_name = path_to_codes + "/" += to_string(counter) += "_" + language += ".txt";
                    rename(old_name.c_str(), new_name.c_str());
                    available_languages.push_back(language);
                    counter++;
                    break;
                }
            }
        }
    }
}

void GFG_operations::GetLanguages() {
    cout << "\nList of available languages: \n";
    for (int get_language_iter = 0; get_language_iter < available_languages.size(); ++get_language_iter)
        cout << get_language_iter + 1 << ") " << available_languages[get_language_iter] << endl;
    cout << "\nEnter the index for desired language: \n";
    int index_of_language;
    cin >> index_of_language;
    system(("gedit " + path_to_codes + "/" + to_string(index_of_language - 1) + "_" +
            available_languages[index_of_language - 1] + ".txt")
                   .c_str());
}

void GFG_operations::ReloadLinks() {
    string path = "search_results/Links.txt";
    ifstream links_list(path);
    string line;
    while (getline(links_list, line))
        cout << line << endl;
    links_list.close();
}

void GFG_operations::NewSearch() {
    pid_t pid;
    if ((pid = fork()) == 0)
        execlp("python3", "python3", path_to_python_file.c_str(), nullptr);
    waitpid(pid, nullptr, 0);
}
