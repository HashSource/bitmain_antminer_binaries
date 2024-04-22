
int ENGINE_set_default_RAND(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x1c) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a7bdc,DAT_000a7be0,e,DAT_000a7be4,1,1);
  }
  return iVar1;
}

