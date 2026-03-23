/// @file listener.h
/// Event listener demonstrating how to respond to player events.
///
/// Listeners are separate classes (not the Plugin itself) that hold event handler
/// methods. Register them in onEnable with registerEvent(). This keeps event
/// handling logic organized and out of the main plugin class.

#pragma once

#include <endstone/endstone.hpp>

class ExampleListener {
public:
    explicit ExampleListener(endstone::Plugin &plugin) : plugin_(plugin) {}

    /// Called when a player joins the server.
    ///
    /// Registered with EventPriority::High, meaning this handler runs after
    /// Normal-priority handlers. Useful when you want to override or finalize
    /// values set by other plugins.
    /// Priorities (lowest runs first): Lowest, Low, Normal, High, Highest, Monitor.
    void onPlayerJoin(endstone::PlayerJoinEvent &event)
    {
        auto &player = event.getPlayer();

        // Modify the join message broadcast to all players.
        // ColorFormat constants add Minecraft formatting codes.
        event.setJoinMessage(endstone::ColorFormat::Yellow + player.getName() + " joined the game");

        // Log the player's network address (useful for debugging, not shown to players)
        auto addr = player.getAddress();
        plugin_.getLogger().info("{} joined from {}:{}", player.getName(), addr.getHostname(), addr.getPort());
    }

    /// Called when a player leaves the server.
    void onPlayerQuit(endstone::PlayerQuitEvent &event)
    {
        event.setQuitMessage(endstone::ColorFormat::Yellow + event.getPlayer().getName() + " left the game");
    }

private:
    endstone::Plugin &plugin_;
};
