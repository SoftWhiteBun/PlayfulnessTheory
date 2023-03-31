#include <iostream>
#include <fstream>
#include <ctime>

enum class LogType { WW, II, DD, EE };

std::ostream& operator<<(std::ostream& os, LogType type);

class Logger {
public:
    Logger() : log_file_("log.txt") {}
    void log(LogType type, const std::string& message);

private:
    std::string get_time();
    const std::string log_file_;
};


#define LOG(type) Logger().log(type, "")