
int ENGINE_register_ECDSA(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x18) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a78e8,DAT_000a78e4,e,DAT_000a78ec,1,0);
  }
  return iVar1;
}

