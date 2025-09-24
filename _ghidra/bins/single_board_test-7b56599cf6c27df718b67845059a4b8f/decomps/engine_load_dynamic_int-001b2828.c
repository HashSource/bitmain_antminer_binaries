
void engine_load_dynamic_int(void)

{
  ENGINE *e;
  int iVar1;
  
  e = ENGINE_new();
  if (e == (ENGINE *)0x0) {
    return;
  }
  iVar1 = ENGINE_set_id(e,"dynamic");
  if ((((iVar1 != 0) && (iVar1 = ENGINE_set_name(e,"Dynamic engine loading support"), iVar1 != 0))
      && (iVar1 = ENGINE_set_init_function(e,(ENGINE_GEN_INT_FUNC_PTR)0x1b2825), iVar1 != 0)) &&
     (((iVar1 = ENGINE_set_finish_function(e,(ENGINE_GEN_INT_FUNC_PTR)0x1b2205), iVar1 != 0 &&
       (iVar1 = ENGINE_set_ctrl_function(e,(ENGINE_CTRL_FUNC_PTR)0x1b2261), iVar1 != 0)) &&
      ((iVar1 = ENGINE_set_flags(e,4), iVar1 != 0 &&
       (iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)&dynamic_cmd_defns), iVar1 != 0)))))) {
    ENGINE_add(e);
    ENGINE_free(e);
    ERR_clear_error();
    return;
  }
  ENGINE_free(e);
  return;
}

