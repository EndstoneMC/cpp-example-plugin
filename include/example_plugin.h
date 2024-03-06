// Copyright (c) 2023, The Endstone Project. (https://endstone.dev) All Rights Reserved.
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

#include "endstone/command/plugin_command.h"
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
        registerCommand<FibonacciCommand>()->setExecutor(std::make_unique<FibonacciCommandExecutor>());
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
        "CppExamplePlugin",                                 // name
        "0.2.0",                                            // version
        "Official C++ example plugin for Endstone servers", // description
        {"Endstone Developers <hello@endstone.dev>"}        // authors
    };
};
