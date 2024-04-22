
int PKCS7_set_attributes(PKCS7_SIGNER_INFO *p7si,stack_st_X509_ATTRIBUTE *sk)

{
  _STACK *p_Var1;
  X509_ATTRIBUTE *pXVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  
  if (&p7si->unauth_attr->stack != (_STACK *)0x0) {
    sk_pop_free(&p7si->unauth_attr->stack,DAT_000d10ac);
  }
  p_Var1 = sk_dup(&sk->stack);
  p7si->unauth_attr = (stack_st_X509_ATTRIBUTE *)p_Var1;
  if (p_Var1 != (_STACK *)0x0) {
    iVar5 = 0;
    while( true ) {
      iVar4 = sk_num(&sk->stack);
      if (iVar4 <= iVar5) {
        return 1;
      }
      p_Var1 = &p7si->unauth_attr->stack;
      pXVar2 = (X509_ATTRIBUTE *)sk_value(&sk->stack,iVar5);
      pXVar2 = X509_ATTRIBUTE_dup(pXVar2);
      pvVar3 = sk_set(p_Var1,iVar5,pXVar2);
      if (pvVar3 == (void *)0x0) break;
      iVar5 = iVar5 + 1;
    }
  }
  return 0;
}

