
int ENGINE_register_RSA(ENGINE *e)

{
  int iVar1;
  
  if (*(int *)(e + 8) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(&rsa_table,0x149491,e,&dummy_nid,1,0);
  }
  return iVar1;
}

