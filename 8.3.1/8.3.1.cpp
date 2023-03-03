#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class PrintCommandConsole : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class PrintCommandFile : public LogCommand {
public:
    void print(const std::string& message) override {
        std::ofstream fout("Command.txt"); 
        fout << message << std::endl;
        fout.close();
    }
};

void print(LogCommand& logcom) {
    logcom.print("Hello world!");
}

int main()
{
    PrintCommandConsole cons;
    PrintCommandFile file;

    print(cons);
    print(file);

    return 0;
}