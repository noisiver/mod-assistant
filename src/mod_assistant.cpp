#include "mod_assistant.h"

// The single Assistant instance. Assistant_WorldScript holds no configuration
// of its own; it forwards the config-load hook to this object, which is the
// only owner of that state.
static Assistant* g_assistant = nullptr;

Assistant::Assistant() : CreatureScript("npc_assistant")
{
    g_assistant = this;
}

Assistant_WorldScript::Assistant_WorldScript() : WorldScript("AssistantWorldScript") {}

void Assistant_WorldScript::OnAfterConfigLoad(bool /*reload*/)
{
    if (g_assistant)
        g_assistant->LoadConfig();
}

void Addmod_assistantScripts()
{
    new Assistant();
    new Assistant_WorldScript();
}
