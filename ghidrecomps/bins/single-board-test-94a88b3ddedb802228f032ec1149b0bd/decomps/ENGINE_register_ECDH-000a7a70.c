
int ENGINE_register_ECDH(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x14) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a7a98,DAT_000a7a94,e,DAT_000a7a9c,1,0);
  }
  return iVar1;
}

