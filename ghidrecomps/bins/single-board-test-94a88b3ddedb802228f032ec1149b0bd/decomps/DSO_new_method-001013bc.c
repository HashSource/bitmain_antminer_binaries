
DSO * DSO_new_method(DSO_METHOD *method)

{
  DSO *dso;
  _STACK *p_Var1;
  int iVar2;
  _func_3879 *p_Var3;
  
  if (default_DSO_meth == (DSO_METHOD *)0x0) {
    default_DSO_meth = DSO_METHOD_openssl();
  }
  dso = (DSO *)CRYPTO_malloc(0x28,"dso_lib.c",0x6a);
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x71,0x41,"dso_lib.c",0x6c);
  }
  else {
    memset(dso,0,0x28);
    p_Var1 = sk_new_null();
    dso->meth_data = (stack_st_void *)p_Var1;
    if (p_Var1 == (_STACK *)0x0) {
      ERR_put_error(0x25,0x71,0x41,"dso_lib.c",0x73);
      CRYPTO_free(dso);
      dso = (DSO *)0x0;
    }
    else {
      if (method == (DSO_METHOD *)0x0) {
        method = default_DSO_meth;
      }
      p_Var3 = method->init;
      dso->meth = method;
      dso->references = 1;
      if ((p_Var3 != (_func_3879 *)0x0) && (iVar2 = (*p_Var3)(dso), iVar2 == 0)) {
        CRYPTO_free(dso);
        dso = (DSO *)0x0;
      }
    }
  }
  return dso;
}

