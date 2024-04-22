
stack_st_X509_NAME * SSL_dup_CA_list(stack_st_X509_NAME *sk)

{
  _STACK *st;
  X509_NAME *pXVar1;
  int iVar2;
  int iVar3;
  
  st = sk_new_null();
  iVar3 = 0;
  do {
    iVar2 = sk_num(&sk->stack);
    if (iVar2 <= iVar3) {
      return (stack_st_X509_NAME *)st;
    }
    pXVar1 = (X509_NAME *)sk_value(&sk->stack,iVar3);
    pXVar1 = X509_NAME_dup(pXVar1);
  } while ((pXVar1 != (X509_NAME *)0x0) &&
          (iVar2 = sk_push(st,pXVar1), iVar3 = iVar3 + 1, iVar2 != 0));
  sk_pop_free(st,DAT_0007de78);
  return (stack_st_X509_NAME *)0x0;
}

