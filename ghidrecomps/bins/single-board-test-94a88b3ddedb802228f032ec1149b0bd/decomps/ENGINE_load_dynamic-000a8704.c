
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_load_dynamic(void)

{
  ENGINE *e;
  int iVar1;
  
  e = ENGINE_new();
  if (e == (ENGINE *)0x0) {
    return;
  }
  iVar1 = ENGINE_set_id(e,DAT_000a8778);
  if ((((iVar1 != 0) && (iVar1 = ENGINE_set_name(e,DAT_000a877c), iVar1 != 0)) &&
      (iVar1 = ENGINE_set_init_function(e,DAT_000a8780), iVar1 != 0)) &&
     (((iVar1 = ENGINE_set_finish_function(e,DAT_000a8784), iVar1 != 0 &&
       (iVar1 = ENGINE_set_ctrl_function(e,DAT_000a8788), iVar1 != 0)) &&
      ((iVar1 = ENGINE_set_flags(e,4), iVar1 != 0 &&
       (iVar1 = ENGINE_set_cmd_defns(e,DAT_000a878c), iVar1 != 0)))))) {
    ENGINE_add(e);
    ENGINE_free(e);
    ERR_clear_error();
    return;
  }
  ENGINE_free(e);
  return;
}

