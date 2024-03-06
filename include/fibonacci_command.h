// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.

#pragma once

#include "endstone/command/command.h"
#include "endstone/command/command_executor.h"

#include <sstream> // for std::ostringstream

class FibonacciCommand : public endstone::Command {
public:
    FibonacciCommand() : Command("fibonacci")
    {
        setDescription("A simple command that prints out the fibonacci series for n <= 20");
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
        if (n > 0 && n <= 20) {
            int t1 = 1, t2 = 1, next;
            std::ostringstream ss;
            for (int i = 1; i <= n; ++i) {
                if (i > 1) {
                    ss << ", ";
                }
                ss << t1;
                next = t1 + t2;
                t1 = t2;
                t2 = next;
            }
            sender.sendMessage("Fibonacci Series (n = {}): {}", n, ss.str());
            return true;
        }
        else {
            sender.sendErrorMessage("'n' must be greater than 0 and less than or equal to 20.");
            return false;
        }
    }
};
