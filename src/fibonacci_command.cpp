// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "fibonacci_command.h"

#include <sstream>
#include <string>

FibonacciCommand::FibonacciCommand() : Command("fibonacci")
{
    setDescription("A simple command that prints out the fibonacci series for n <= 20");
    setAliases("fib");
    setUsages("/fibonacci <n: int>");
}

bool FibonacciCommandExecutor::onCommand(const endstone::CommandSender &sender, const endstone::Command &command,
                                         const std::vector<std::string> &args)
{
    int n = std::stoi(args[0]);
    if (n > 0 && n <= 20) {
        int t1 = 1, t2 = 1, next;
        std::stringstream ss;
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
