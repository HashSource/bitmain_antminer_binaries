
int ENGINE_register_RAND(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x1c) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(&rand_table,0xa7b2d,e,&dummy_nid,1,0);
  }
  return iVar1;
}

