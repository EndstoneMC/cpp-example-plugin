// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.

#pragma once

#include <endstone/event/server/server_load_event.h>
#include <endstone/plugin/plugin.h>

class ExampleListener {
public:
    explicit ExampleListener(endstone::Plugin &plugin) : plugin_(plugin) {}

    void onServerLoad(endstone::ServerLoadEvent &event)
    {
        plugin_.getLogger().info("ServerLoadEvent is passed to ExampleListener::onServerLoad");
    }

private:
    endstone::Plugin &plugin_;
};
