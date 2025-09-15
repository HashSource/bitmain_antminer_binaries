
int ENGINE_register_ECDH(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 0x14) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(&ecdh_table,0xa7a55,e,&dummy_nid,1,0);
  }
  return iVar1;
}

