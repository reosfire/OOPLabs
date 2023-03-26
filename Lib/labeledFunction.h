#pragma ones

#include <string>
#include <functional>
#include <utility>

class labeledFunction {
private:
    const std::string label;
    const std::function<void()>& procedure;

public:
    labeledFunction(std::string  label, const std::function<void()>& procedure): label(std::move(label)), procedure(procedure) { }

    void invoke() const;

    static void printFunctions(const std::vector<labeledFunction>& functions, int lineWidth = 40);
    static void runLoop(const std::vector<labeledFunction>& functions, int exit = 0);
};
