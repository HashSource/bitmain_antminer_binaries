
int ENGINE_set_default_DH(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x10) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(&dh_table,0x149569,e,&dummy_nid,1,1);
  }
  return iVar1;
}

