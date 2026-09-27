#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>

// Supprime les espaces au début et à la fin d'une chaîne
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

// Validation stricte de la date (validité des mois, jours et années bissextiles)
bool validate_date(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7 && !std::isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2000 || year > 2026 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    // Gestion de l'année bissextile
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonths[1] = 29;

    if (day > daysInMonths[month - 1])
        return false;

    return true;
}

// Charge la base de données interne "data.csv"
bool load_database(std::map<std::string, double>& db) {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: could not open data.csv database file." << std::endl;
        return false;
    }

    std::string line;
    if (!std::getline(file, line) || line != "date,exchange_rate") {
        std::cerr << "Error: invalid database header." << std::endl;
        file.close();
        return false;
    }

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        size_t comma = line.find(',');
        if (comma == std::string::npos) continue;

        std::string date = line.substr(0, comma);
        std::string rate_str = line.substr(comma + 1);
        double rate = std::strtod(rate_str.c_str(), NULL);
        db[date] = rate;
    }
    file.close();
    return true;
}

// Trouve le taux de change exact ou la valeur inférieure la plus proche
double get_exchange_rate(const std::map<std::string, double>& db, const std::string& date) {
    std::map<std::string, double>::const_iterator it = db.find(date);
    if (it != db.end())
        return it->second;

    // Récupère le premier élément strictement supérieur
    it = db.upper_bound(date);
    if (it == db.begin())
        return 0.0; // Aucune date antérieure disponible
    
    --it; // On recule d'un cran pour avoir la date inférieure la plus proche
    return it->second;
}

// Parse et traite le fichier d'entrée passé en argument (ex: input.txt)
void process_input_file(const char* filename, const std::map<std::string, double>& db) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    if (!std::getline(file, line)) {
        std::cerr << "Error: empty input file." << std::endl;
        file.close();
        return;
    }
    
    // Le sujet tolère ou demande "date | value" comme header
    if (trim(line) != "date | value") {
        std::cerr << "Error: invalid input header." << std::endl;
        file.close();
        return;
    }

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        size_t pipe_pos = line.find('|');
        if (pipe_pos == std::string::npos) {
            std::cout << "Error: bad input => " << trim(line) << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipe_pos));
        std::string val_str = trim(line.substr(pipe_pos + 1));

        if (!validate_date(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        if (val_str.empty()) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        char* end_ptr;
        double value = std::strtod(val_str.c_str(), &end_ptr);
        if (*end_ptr != '\0') {
            std::cout << "Error: bad input => " << val_str << std::endl;
            continue;
        }

        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        double rate = get_exchange_rate(db, date);
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
    file.close();
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::map<std::string, double> bitcoin_db;
    if (!load_database(bitcoin_db)) {
        return 1;
    }

    process_input_file(argv[1], bitcoin_db);
    return 0;
}
