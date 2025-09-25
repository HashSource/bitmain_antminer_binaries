
int ENGINE_set_default_RSA(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 8) != 0) {
    iVar1 = engine_table_register(&rsa_table,0x1af50d,e,&dummy_nid,1,1);
    return iVar1;
  }
  return 1;
}

