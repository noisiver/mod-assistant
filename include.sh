#!/usr/bin/env bash
MOD_ASSISTANT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/" && pwd )"

source $MOD_ASSISTANT_ROOT"/conf/conf.sh.dist"

if [ -f $MOD_ASSISTANT_ROOT"/conf/conf.sh" ]; then
    source $MOD_ASSISTANT_ROOT"/conf/conf.sh"
fi
