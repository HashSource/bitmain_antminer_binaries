
X509_LOOKUP * X509_STORE_add_lookup(X509_STORE *v,X509_LOOKUP_METHOD *m)

{
  int iVar1;
  X509_LOOKUP *pXVar2;
  int iVar3;
  _func_1976 *p_Var4;
  _func_1977 *p_Var5;
  _STACK *p_Var6;
  
  p_Var6 = &v->get_cert_methods->stack;
  iVar3 = 0;
  while( true ) {
    iVar1 = sk_num(p_Var6);
    if (iVar1 <= iVar3) break;
    pXVar2 = (X509_LOOKUP *)sk_value(p_Var6,iVar3);
    iVar3 = iVar3 + 1;
    if (pXVar2->method == m) {
      return pXVar2;
    }
  }
  pXVar2 = (X509_LOOKUP *)CRYPTO_malloc(0x14,DAT_000c3b9c,0x45);
  if (pXVar2 != (X509_LOOKUP *)0x0) {
    p_Var4 = m->new_item;
    pXVar2->method = m;
    pXVar2->init = 0;
    pXVar2->skip = 0;
    pXVar2->method_data = (char *)0x0;
    pXVar2->store_ctx = (X509_STORE *)0x0;
    if ((p_Var4 == (_func_1976 *)0x0) || (iVar3 = (*p_Var4)(pXVar2), iVar3 != 0)) {
      pXVar2->store_ctx = v;
      iVar3 = sk_push(&v->get_cert_methods->stack,pXVar2);
      if (iVar3 != 0) {
        return pXVar2;
      }
      if ((pXVar2->method != (X509_LOOKUP_METHOD *)0x0) &&
         (p_Var5 = pXVar2->method->free, p_Var5 != (_func_1977 *)0x0)) {
        (*p_Var5)(pXVar2);
      }
      CRYPTO_free(pXVar2);
      return (X509_LOOKUP *)0x0;
    }
    CRYPTO_free(pXVar2);
  }
  return (X509_LOOKUP *)0x0;
}

