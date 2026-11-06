#include "mod_assistant.h"

// Owns the configuration; Assistant_WorldScript forwards the config-load hook to it.
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
