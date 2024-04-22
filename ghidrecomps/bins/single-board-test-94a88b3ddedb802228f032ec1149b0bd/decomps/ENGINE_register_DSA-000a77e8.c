
int ENGINE_register_DSA(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0xc) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a7810,DAT_000a780c,e,DAT_000a7814,1,0);
  }
  return iVar1;
}

