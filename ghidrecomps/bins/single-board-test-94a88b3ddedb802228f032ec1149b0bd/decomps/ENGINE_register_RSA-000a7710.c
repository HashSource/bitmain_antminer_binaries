
int ENGINE_register_RSA(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 8) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a7738,DAT_000a7734,e,DAT_000a773c,1,0);
  }
  return iVar1;
}

