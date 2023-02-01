#include "../include/GFG_operation.h"

GFG_operations::GFG_operations() {
        NewSearch();
        RenameFiles();
        while (true) {
            std::cout << "\n1) List of programming languages of the search result.\n"
                      << "2) Reload the list of the links.\n"
                      << "3) New search.\n"
                      << "4) Exit.\n";
            int condition;
            std::cin >> condition;
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
                    std::cout << "Invalid input!!!\n";
                    break;
            }
        }
    }

void GFG_operations::RenameFiles() {
    int counter = 0;
    for (const auto &entry : std::filesystem::directory_iterator(path_to_codes)) {
        std::ifstream code_file(entry.path());
        std::string line_of_language_name;
        const int number_of_lines_to_read = 4;
        for (int rename_iter = 0; rename_iter < number_of_lines_to_read; ++rename_iter) {
            getline(code_file, line_of_language_name);
            for (auto &language : languages) {
                if (line_of_language_name.find(language) != std::string::npos) {
                    std::string old_name = entry.path();
                    std::string new_name = path_to_codes + "/" += std::to_string(counter) += "_" + language += ".txt";
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
    std::cout << "\nList of available languages: \n";
    for (int get_language_iter = 0; get_language_iter < available_languages.size(); ++get_language_iter)
        std::cout << get_language_iter + 1 << ") " << available_languages[get_language_iter] << std::endl;
    std::cout << "\nEnter the index for desired language: \n";
    int index_of_language;
    std::cin >> index_of_language;
    system(("gedit " + path_to_codes + "/" + std::to_string(index_of_language - 1) + "_" +
            available_languages[index_of_language - 1] + ".txt")
                   .c_str());
}

void GFG_operations::ReloadLinks() {
    std::ifstream links_list(path_to_links);
    std::string line;
    while (getline(links_list, line))
        std::cout << line << std::endl;
    links_list.close();
}

void GFG_operations::NewSearch() {
    pid_t pid;
    if ((pid = fork()) == 0)
        execlp("python3", "python3", path_to_python_file.c_str(), nullptr);
    waitpid(pid, nullptr, 0);
}

GFG_operations::~GFG_operations() {
        std::cout << "\nThank you for using GFG_operations!!!\n"
                  << "For any comments, contact: masoud.vahid10@gmail.com\n";
    }

void RunGFG::remove_codes_files() {
  for (const auto &entry :
       std::filesystem::directory_iterator("./" + path_to_codes)) {
    remove(entry.path());
  }
}

RunGFG::RunGFG() {
        remove_codes_files();
    }

