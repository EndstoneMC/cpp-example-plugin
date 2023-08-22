//
// Created by Vincent on 21/08/2023.
//

#ifndef CPP_SAMPLE_PLUGIN_H
#define CPP_SAMPLE_PLUGIN_H

#include "endstone/plugin/cpp/cpp_plugin.h"

class SamplePlugin : public CppPlugin {
public:
    SamplePlugin() = default;
    const PluginDescription &getDescription() const override;
    void onLoad() override;
    void onEnable() override;
    void onDisable() override;

private:
    CppPluginDescription description_{"CppSamplePlugin", "1.0.0"};
};

#endif // CPP_SAMPLE_PLUGIN_H
