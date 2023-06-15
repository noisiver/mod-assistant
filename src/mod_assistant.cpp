#include "mod_assistant.h"

Assistant::Assistant() : CreatureScript("npc_assistant"), WorldScript("AssistantWorldScript") {}

void Addmod_assistantScripts()
{
    new Assistant();
}
