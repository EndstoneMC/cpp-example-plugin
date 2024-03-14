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

        auto *root = registerPermission("cpp_example.command",
                                        "Allow users to use all commands provided by this example plugin");
        registerPermission(root, "cpp_example.command.fibonacci", "Allow users to use the fibonacci command",
                           endstone::PermissionDefault::Operator);

        registerCommand("fibonacci",                                                  // name
                        "A simple command that writes the Fibonacci series up to n.", // description
                        {"/fibonacci <n: int>"},                                      // usages
                        {"fib"},                                                      // aliases
                        {"cpp_example.command.fibonacci"})                            // permissions
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

    bool onCommand(const endstone::CommandSender &sender, const endstone::Command &command,
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
