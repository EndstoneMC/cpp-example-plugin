#include "plugin.h"
#include "version.h"

// The ENDSTONE_PLUGIN macro defines the metadata for the plugin.
// This is where you set the plugin name, version, and main class,
// and declare commands and permissions.
ENDSTONE_PLUGIN(/*name=*/"cpp_example", /*version=*/CPP_EXAMPLE_VERSION, /*main_class=*/ExamplePlugin)
{
    prefix = "ExamplePlugin";
    description = "C++ example plugin for Endstone servers";
    website = "https://github.com/EndstoneMC/cpp-example-plugin";
    authors = {"Endstone Developers <hello@endstone.dev>"};

    // Commands are declared with a fluent builder API.
    // The "permissions" field controls who can use the command.
    command("hello")
        .description("Send a greeting")
        .usages("/hello")
        .permissions("example.command.hello");

    command("broadcast")
        .description("Broadcast a message to all players")
        .usages("/broadcast <message: message>")
        .permissions("example.command.broadcast");

    // Permissions are declared separately from commands. The default_ field controls
    // who gets the permission automatically: True = everyone, Operator = ops only,
    // False = no one (must be explicitly granted).
    permission("example.command.hello")
        .description("Allow users to use the /hello command.")
        .default_(endstone::PermissionDefault::True);

    permission("example.command.broadcast")
        .description("Allow users to use the /broadcast command.")
        .default_(endstone::PermissionDefault::Operator);
}
