
int ENGINE_register_DH(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x10) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a79c0,DAT_000a79bc,e,DAT_000a79c4,1,0);
  }
  return iVar1;
}

