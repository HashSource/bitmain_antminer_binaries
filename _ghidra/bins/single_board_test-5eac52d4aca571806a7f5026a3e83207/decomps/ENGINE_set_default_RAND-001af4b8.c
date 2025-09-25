
int ENGINE_set_default_RAND(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x18) != 0) {
    iVar1 = engine_table_register(&rand_table,0x1af445,e,&dummy_nid,1,1);
    return iVar1;
  }
  return 1;
}

