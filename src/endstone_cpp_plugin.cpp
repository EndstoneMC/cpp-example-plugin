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

#include "endstone_cpp_plugin.h"

#include "endstone/command/plugin_command.h"
#include "fibonacci_command.h"

void EndstoneCppPlugin::onLoad()
{
    getLogger().info("onLoad is called");
}

void EndstoneCppPlugin::onEnable()
{
    getLogger().info("onEnable is called");
    endstone::PluginCommand *command = registerCommand<FibonacciCommand>();
    command->setExecutor(std::make_unique<FibonacciCommandExecutor>());
}

void EndstoneCppPlugin::onDisable()
{
    getLogger().info("onDisable is called");
}

const endstone::PluginDescription &EndstoneCppPlugin::getDescription() const
{
    return description_;
}
