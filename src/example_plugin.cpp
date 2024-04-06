// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.

#include "example_plugin.h"

// The ENDSTONE_PLUGIN macro defines the metadata for the plugin.
ENDSTONE_PLUGIN(/*name=*/"CppExamplePlugin", /*version=*/"0.4.0", /*main_class=*/ExamplePlugin)
{
    description = "C++ example plugin for Endstone servers";
    website = "https://github.com/EndstoneMC/cpp-example-plugin";
    authors = {"Endstone Developers <hello@endstone.dev>"};

    command("debug") //
        .description("Print debug information.")
        .usages("/debug")
        .permissions("cpp_example.command.debug");

    command("fibonacci")
        .description("A simple command that writes the Fibonacci series up to n.")
        .usages("/fibonacci <n: int>")
        .aliases("fib")
        .permissions("cpp_example.command.fibonacci", "cpp_example.command.fibonacci.large_n");

    permission("cpp_example.command")
        .description("Allow users to use all commands provided by this example plugin")
        .children("cpp_example.command.debug", true)
        .children("cpp_example.command.fibonacci", true);

    permission("cpp_example.command.debug")
        .description("Allow users to use the debug command")
        .default_(endstone::PermissionDefault::Operator);

    permission("cpp_example.command.fibonacci")
        .description("Allow users to use the fibonacci command")
        .default_(endstone::PermissionDefault::True)
        .children("cpp_example.command.fibonacci.large_n", true);

    permission("cpp_example.command.fibonacci.large_n")
        .description("Allow users to use the fibonacci command with n >= 1000")
        .default_(endstone::PermissionDefault::Operator);
}
