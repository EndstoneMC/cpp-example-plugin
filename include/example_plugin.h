// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.

#include "endstone/plugin/plugin.h"
#include "fibonacci_command.h"

class ExamplePlugin : public endstone::Plugin {
public:
    ExamplePlugin() = default;

    void onLoad() override
    {
        getLogger().info("onLoad is called");
    }

    void onEnable() override
    {
        getLogger().info("onEnable is called");

        auto *root = registerPermission(                                        // root permission
            "cpp_example.command",                                              // name
            "Allow users to use all commands provided by this example plugin"); // description

        auto *fibonacci = registerPermission(root,                                       // parent
                                             "cpp_example.command.fibonacci",            // name
                                             "Allow users to use the fibonacci command", // description
                                             endstone::PermissionDefault::True);         // default

        registerPermission(fibonacci,                                                 // parent
                           "cpp_example.command.fibonacci.large_n",                   // name
                           "Allow users to use the fibonacci command with n >= 1000", // description
                           endstone::PermissionDefault::Operator);                    // default

        registerCommand("fibonacci",                                                                // name
                        "A simple command that writes the Fibonacci series up to n.",               // description
                        {"/fibonacci <n: int>"},                                                    // usages
                        {"fib"},                                                                    // aliases
                        {"cpp_example.command.fibonacci", "cpp_example.command.fibonacci.large_n"}) // permissions
            ->setExecutor(std::make_unique<FibonacciCommandExecutor>());
    }

    void onDisable() override
    {
        getLogger().info("onDisable is called");
    }

    [[nodiscard]] const endstone::PluginDescription &getDescription() const override
    {
        return description_;
    }

    bool onCommand(endstone::CommandSender &sender, const endstone::Command &command,
                   const std::vector<std::string> &args) override
    {
        // You can also handle commands here instead of setting an executor in onEnable if you prefer
        return false;
    }

private:
    endstone::PluginDescription description_{
        "CppExamplePlugin",                          // name
        "0.2.0",                                     // version
        "C++ example plugin for Endstone servers",   // description
        {"Endstone Developers <hello@endstone.dev>"} // authors
    };
};
