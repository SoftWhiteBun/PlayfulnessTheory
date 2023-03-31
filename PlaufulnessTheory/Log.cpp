#include "Log.h"



std::ostream& operator<<(std::ostream& os, LogType type) {
    switch (type) {
    case LogType::WW:
        os << "WW";
        break;
    case LogType::II:
        os << "II";
        break;
    case LogType::DD:
        os << "DD";
        break;
    case LogType::EE:
        os << "EE";
        break;
    }
    return os;
}

    
std::string Logger::get_time() {
    std::time_t now = std::time(nullptr);
    char time_str[100];
    std::strftime(time_str, sizeof(time_str), "%c", std::localtime(&now));
    return time_str;
}


void Logger::log(LogType type, const std::string& message) {
    std::ofstream log_file(log_file_, std::ios_base::app);
    log_file << type << " [" << get_time() << "] --- \"" << message << "\"\n";
}
