//
// Created by Vincent on 21/08/2023.
//

#include "sample_plugin.h"

const PluginDescription &SamplePlugin::getDescription() const {
    return description_;
}

void SamplePlugin::onLoad() {
    getLogger()->info("onLoad is called");
}

void SamplePlugin::onEnable() {
    getLogger()->info("onEnable is called");
}

void SamplePlugin::onDisable() {
    getLogger()->info("onDisable is called");
}

ENDSTONE_PLUGIN_CLASS(SamplePlugin)