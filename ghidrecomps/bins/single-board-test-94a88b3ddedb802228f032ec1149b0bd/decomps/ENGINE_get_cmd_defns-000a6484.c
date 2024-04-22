
ENGINE_CMD_DEFN * ENGINE_get_cmd_defns(ENGINE *e)

{
  return *(ENGINE_CMD_DEFN **)(e + 0x50);
}

