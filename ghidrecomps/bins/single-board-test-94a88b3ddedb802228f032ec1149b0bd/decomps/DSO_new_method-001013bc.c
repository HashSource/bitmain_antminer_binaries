
DSO * DSO_new_method(DSO_METHOD *method)

{
  DSO_METHOD **ppDVar1;
  DSO *dso;
  _STACK *p_Var2;
  int iVar3;
  DSO_METHOD *pDVar4;
  _func_3879 *p_Var5;
  
  ppDVar1 = DAT_0010144c;
  if (*DAT_0010144c == (DSO_METHOD *)0x0) {
    pDVar4 = DSO_METHOD_openssl();
    *ppDVar1 = pDVar4;
  }
  dso = (DSO *)CRYPTO_malloc(0x28,DAT_00101450,0x6a);
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x71,0x41,DAT_00101450,0x6c);
  }
  else {
    memset(dso,0,0x28);
    p_Var2 = sk_new_null();
    dso->meth_data = (stack_st_void *)p_Var2;
    if (p_Var2 == (_STACK *)0x0) {
      ERR_put_error(0x25,0x71,0x41,DAT_00101450,0x73);
      CRYPTO_free(dso);
      dso = (DSO *)0x0;
    }
    else {
      if (method == (DSO_METHOD *)0x0) {
        method = *ppDVar1;
      }
      p_Var5 = method->init;
      dso->meth = method;
      dso->references = 1;
      if ((p_Var5 != (_func_3879 *)0x0) && (iVar3 = (*p_Var5)(dso), iVar3 == 0)) {
        CRYPTO_free(dso);
        dso = (DSO *)0x0;
      }
    }
  }
  return dso;
}

