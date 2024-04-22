
int ENGINE_set_default_DSA(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0xc) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a787c,DAT_000a7880,e,DAT_000a7884,1,1);
  }
  return iVar1;
}

