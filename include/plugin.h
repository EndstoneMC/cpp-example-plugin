/// @file plugin.h
/// Example plugin demonstrating commands, configuration, and lifecycle methods.

#pragma once

#include "listener.h"

#include <endstone/endstone.hpp>
#include <memory>
#include <string>
#include <vector>

class ExamplePlugin : public endstone::Plugin {
public:
    /// Called when the plugin is enabled. Use this for setup.
    void onEnable() override
    {
        // Register event listeners. Endstone scans the object for event handler
        // methods registered via registerEvent().
        listener_ = std::make_unique<ExampleListener>(*this);
        registerEvent(&ExampleListener::onPlayerJoin, *listener_, endstone::EventPriority::High);
        registerEvent(&ExampleListener::onPlayerQuit, *listener_);

        getLogger().info("ExamplePlugin enabled!");
    }

    /// Called when the plugin is disabled. Use this for cleanup.
    void onDisable() override
    {
        getLogger().info("ExamplePlugin disabled!");
    }

    /// Called when a player or the console runs one of this plugin's commands.
    bool onCommand(endstone::CommandSender &sender, const endstone::Command &command,
                   const std::vector<std::string> &args) override
    {
        if (command.getName() == "hello") {
            // Use dynamic_cast to tailor behavior to the sender type.
            // This is a common pattern since players and the console have
            // different capabilities (e.g. players can receive chat messages,
            // but the console can only write to the log).
            if (auto *player = dynamic_cast<endstone::Player *>(&sender)) {
                player->sendMessage("Hello, {}!", player->getName());
            }
            else if (dynamic_cast<endstone::ConsoleCommandSender *>(&sender)) {
                getLogger().info("Hello from the console!");
            }
            else {
                sender.sendMessage("Hello!");
            }
            return true;
        }

        if (command.getName() == "broadcast") {
            // args contains everything after the command name.
            // The "message" parameter type captures the rest of the line as one string.
            if (args.empty()) {
                sender.sendErrorMessage("Usage: /broadcast <message>");
                return false;
            }

            std::string message;
            for (const auto &arg : args) {
                if (!message.empty()) {
                    message += " ";
                }
                message += arg;
            }
            getServer().broadcastMessage("[Broadcast] {}", message);
            return true;
        }

        return false;
    }

private:
    std::unique_ptr<ExampleListener> listener_;
};
