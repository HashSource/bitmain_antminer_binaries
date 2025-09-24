
DSO_FUNC_TYPE DSO_bind_func(DSO *dso,char *symname)

{
  DSO_FUNC_TYPE pDVar1;
  _func_3876 *p_Var2;
  
  if (symname == (char *)0x0 || dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x6c,0x43,"crypto/dso/dso_lib.c",0xb2);
    pDVar1 = (DSO_FUNC_TYPE)0x0;
  }
  else {
    p_Var2 = dso->meth->dso_bind_var;
    if (p_Var2 == (_func_3876 *)0x0) {
      ERR_put_error(0x25,0x6c,0x6c,"crypto/dso/dso_lib.c",0xb6);
      pDVar1 = (DSO_FUNC_TYPE)0x0;
    }
    else {
      pDVar1 = (DSO_FUNC_TYPE)(*p_Var2)(dso,symname);
      if (pDVar1 == (DSO_FUNC_TYPE)0x0) {
        ERR_put_error(0x25,0x6c,0x6a,"crypto/dso/dso_lib.c",0xba);
      }
    }
  }
  return pDVar1;
}

