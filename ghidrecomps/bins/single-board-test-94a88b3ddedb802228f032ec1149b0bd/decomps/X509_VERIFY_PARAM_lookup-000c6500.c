
X509_VERIFY_PARAM * X509_VERIFY_PARAM_lookup(char *name)

{
  _STACK **pp_Var1;
  int iVar2;
  X509_VERIFY_PARAM *pXVar3;
  char *local_34 [10];
  
  pp_Var1 = DAT_000c6538;
  local_34[0] = name;
  if ((*DAT_000c6538 == (_STACK *)0x0) || (iVar2 = sk_find(*DAT_000c6538,local_34), iVar2 == -1)) {
    pXVar3 = (X509_VERIFY_PARAM *)OBJ_bsearch_(local_34,DAT_000c6540,5,0x24,DAT_000c653c);
  }
  else {
    pXVar3 = (X509_VERIFY_PARAM *)sk_value(*pp_Var1,iVar2);
  }
  return pXVar3;
}

