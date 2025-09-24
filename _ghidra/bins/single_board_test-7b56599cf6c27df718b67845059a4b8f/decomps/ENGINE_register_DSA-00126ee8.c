
int ENGINE_register_DSA(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0xc) != 0) {
    iVar1 = engine_table_register(&dsa_table,0x126ecd,e,&dummy_nid,1,0);
    return iVar1;
  }
  return 1;
}

