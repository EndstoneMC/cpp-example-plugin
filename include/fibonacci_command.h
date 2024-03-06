// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.

#pragma once

#include "endstone/command/command.h"
#include "endstone/command/command_executor.h"

#include <string>

class FibonacciCommand : public endstone::Command {
public:
    FibonacciCommand() : Command("fibonacci")
    {
        setDescription("A simple command that writes the Fibonacci series up to n.");
        setAliases("fib");
        setUsages("/fibonacci <n: int>");
    }
};

class FibonacciCommandExecutor : public endstone::CommandExecutor {
public:
    bool onCommand(const endstone::CommandSender &sender, const endstone::Command &command,
                   const std::vector<std::string> &args) override
    {
        int n = std::stoi(args[0]);
        if (n > 0) {
            int a = 0, b = 1;
            std::string result;
            while (a < n) {
                if (!result.empty()) {
                    result += ", ";
                }

                result += std::to_string(a);
                int temp = b;
                b = a + b;
                a = temp;
            }
            sender.sendMessage("Fibonacci series up to {}: {}", n, result);
            return true;
        }
        else {
            sender.sendErrorMessage("'n' must be an integer greater than 0.");
            return false;
        }
    }
};
