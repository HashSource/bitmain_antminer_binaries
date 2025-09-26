
X509_VERIFY_PARAM * X509_VERIFY_PARAM_lookup(char *name)

{
  int iVar1;
  X509_VERIFY_PARAM *pXVar2;
  char *local_34 [10];
  
  local_34[0] = name;
  if ((param_table == (_STACK *)0x0) || (iVar1 = sk_find(param_table,local_34), iVar1 == -1)) {
    pXVar2 = (X509_VERIFY_PARAM *)OBJ_bsearch_(local_34,&default_table,5,0x24,(cmp *)0x166915);
  }
  else {
    pXVar2 = (X509_VERIFY_PARAM *)sk_value(param_table,iVar1);
  }
  return pXVar2;
}

