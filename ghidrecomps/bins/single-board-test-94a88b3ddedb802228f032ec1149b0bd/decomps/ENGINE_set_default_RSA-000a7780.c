
int ENGINE_set_default_RSA(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 8) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a77a4,DAT_000a77a8,e,DAT_000a77ac,1,1);
  }
  return iVar1;
}

