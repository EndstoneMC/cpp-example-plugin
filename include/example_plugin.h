// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.

#include "endstone/command/plugin_command.h"
#include "endstone/plugin/plugin.h"
#include "endstone/util/color_format.h"
#include "fibonacci_command.h"

class ExamplePlugin : public endstone::Plugin {
public:
    void onLoad() override
    {
        getLogger().info("onLoad is called");
    }

    void onEnable() override
    {
        getLogger().info("onEnable is called");
        if (auto *command = getCommand("fibonacci")) {
            command->setExecutor(std::make_unique<FibonacciCommandExecutor>());
        }
    }

    void onDisable() override
    {
        getLogger().info("onDisable is called");
    }

    bool onCommand(endstone::CommandSender &sender, const endstone::Command &command,
                   const std::vector<std::string> &args) override
    {
        // You can also handle commands here instead of setting an executor in onEnable if you prefer
        if (command.getName() == "debug") {
            if (sender.isOp()) {
                sender.sendMessage(endstone::ColorFormat::DARK_GREEN + "You are seeing this because you are the OP!");
            }
            else {
                sender.sendErrorMessage("You should never see this!");
            }
            return true;
        }

        sender.sendErrorMessage("Unknown command: /{}", command.getName());
        return false;
    }
};
