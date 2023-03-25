#pragma ones

#include <string>
#include <functional>

class labeledFunction {
private:
    const std::string& label;
    const std::function<void()>& procedure;

public:
    labeledFunction(const std::string& label, const std::function<void()>& procedure): label(label), procedure(procedure) { }

    void invoke() const;

    static void printFunctions(const std::vector<labeledFunction>& functions, int lineWidth = 40);
    static void runLoop(const std::vector<labeledFunction>& functions, int exit = 0);
};
