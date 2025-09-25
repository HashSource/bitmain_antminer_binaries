
int ENGINE_register_DH(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x10) != 0) {
    iVar1 = engine_table_register(&dh_table,0x122bb5,e,&dummy_nid,1,0);
    return iVar1;
  }
  return 1;
}

