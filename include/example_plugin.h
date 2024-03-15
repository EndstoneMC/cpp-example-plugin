// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.

#include "endstone/plugin/plugin.h"
#include "endstone/util/color_format.h"
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

        // Register permissions
        auto *root = registerPermission("cpp_example.command",
                                        "Allow users to use all commands provided by this example plugin");
        registerPermission(root, "cpp_example.command.debug", "Allow users to use the debug command",
                           endstone::PermissionDefault::Operator);
        auto *fib = registerPermission(root, "cpp_example.command.fibonacci",
                                       "Allow users to use the fibonacci command", endstone::PermissionDefault::True);
        registerPermission(fib, "cpp_example.command.fibonacci.large_n",
                           "Allow users to use the fibonacci command with n >= 1000",
                           endstone::PermissionDefault::Operator);

        // Register commands
        registerCommand("debug", "Print debug information of this plugin.", {"/debug"}, {},
                        {"cpp_example.command.debug"});
        registerCommand("fibonacci", "A simple command that writes the Fibonacci series up to n.",
                        {"/fibonacci <n: int>"}, {"fib"},
                        {"cpp_example.command.fibonacci", "cpp_example.command.fibonacci.large_n"})
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
        if (command.getName() == "debug") {
            if (sender.isOp()) {
                sender.sendMessage(endstone::ColorFormat::DARK_GREEN + "You are seeing this because you are OP!");
            }
            else {
                sender.sendErrorMessage("You should never see this!");
            }
            return true;
        }

        sender.sendErrorMessage("Unknown command: /{}", command.getName());
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
