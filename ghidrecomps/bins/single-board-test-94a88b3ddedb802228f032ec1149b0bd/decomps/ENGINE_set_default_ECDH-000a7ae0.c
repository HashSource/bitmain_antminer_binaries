
int ENGINE_set_default_ECDH(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x14) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a7b04,DAT_000a7b08,e,DAT_000a7b0c,1,1);
  }
  return iVar1;
}

