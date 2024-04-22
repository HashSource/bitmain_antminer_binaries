
int ENGINE_set_default_ECDSA(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x18) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a7954,DAT_000a7958,e,DAT_000a795c,1,1);
  }
  return iVar1;
}

