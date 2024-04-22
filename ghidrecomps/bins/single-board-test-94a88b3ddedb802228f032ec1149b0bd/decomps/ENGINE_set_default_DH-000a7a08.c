
int ENGINE_set_default_DH(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x10) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a7a2c,DAT_000a7a30,e,DAT_000a7a34,1,1);
  }
  return iVar1;
}

