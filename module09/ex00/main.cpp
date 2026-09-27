#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>
#include <utility>
#include <sstream>

void    print_data(const std::pair<std::string, double>& data) {
    std::cout << data.first << " | " << data.second << std::endl;
}

void    print_bitcoin_exchange(const std::map<std::string, double>& data) {
    std::for_each(data.begin(), data.end(), print_data);
}

void    multiply_data_by_rate(std::map<std::string, double>& data, const double rate) {
    for (std::map<std::string, double>::iterator it(data.begin()); it != data.end(); it++) {
        it->second *= rate;
    }
}

struct DataResult {
    std::map<std::string, double> data;
    double rate;
    std::string error_message;
    DataResult() {

    }
};

struct NumberResult {
    double number;
    bool error;
};

NumberResult get_number(const std::string str) {
    NumberResult result;
    char *end_ptr;
    double number(static_cast<double>(std::strtod(str.c_str(), &end_ptr)));
    if (*end_ptr != '\0') {
        result.error = true;
        return result;
    }
    result.number = number;
    result.error = false;
    return result;
}

bool    check_date(const std::string& date) {
    std::stringstream ss(date);
    std::string year;
    if (!std::getline(ss, year, '-'))
        return false;
    NumberResult result(get_number(year));
    if (result.error)
        return false;
    std::string month;
    if (!std::getline(ss, month, '-'))
        return false;
    result = get_number(month);
    if (result.error)
        return false;
    if (result.number > 12 || result.number < 1)
        return false;
    std::string day;
    if (!getline(ss, day))
        return false;
    result = get_number(day);
    if (result.error)
        return false;
    if (result.number < 0)
        return false;
    return true;
}

bool    check_rate(const double rate) {
    if (rate < 0 || rate > 1000)
        return false;
    return true;
}

DataResult parse_data(std::ifstream& target) {
    DataResult result;
    std::string header;

    if (!std::getline(target, header)) {
        result.error_message = "Error: file is empty.";
        return result;
    }
    if (header != "date,exchange_rate") {
        result.error_message = "Error: invalid or missin header.";
        return result;
    }
    std::string data_line;
    while (std::getline(target, data_line)) {
        if (data_line.empty())
            continue;
        std::string date;
        std::string rate;
        std::stringstream ss(data_line);
        if (std::getline(ss, date, ',')) {
            if (std::getline(ss, rate)) {
                char *end_ptr;
                double rate_number(static_cast<double>(std::strtod(rate.c_str(), &end_ptr)));
                if (check_date(date) == false) {
                    result.error_message = "Error: invalid date.";
                    return result;    
                }
                if (check_rate(rate_number) == false) {
                    result.error_message = "Error: invalid rate.";
                    return result;   
                }
                if (*end_ptr == '\0')
                    result.data[date] = rate_number;
            }
        }
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc < 1) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    } else if (argc > 1) {
        std::cerr << "Error: too many arguments." << std::endl;
        return 2;
    }
    std::ifstream target(argv[1]);
    if (!target) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    DataResult result(parse_data(target));
    if (result.error_message.empty() == false) {
        std::cerr << result.error_message << std::endl;
        return 3;
    }
    multiply_data_by_rate(result.data, result.rate);
    print_bitcoin_exchange(result.data);
    return 0;
}