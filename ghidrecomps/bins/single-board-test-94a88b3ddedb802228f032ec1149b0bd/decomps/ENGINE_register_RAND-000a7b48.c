
int ENGINE_register_RAND(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x1c) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a7b70,DAT_000a7b6c,e,DAT_000a7b74,1,0);
  }
  return iVar1;
}

