
DSO_FUNC_TYPE DSO_bind_func(DSO *dso,char *symname)

{
  DSO_FUNC_TYPE pDVar1;
  _func_3877 *p_Var2;
  
  if (dso == (DSO *)0x0 || symname == (char *)0x0) {
    ERR_put_error(0x25,0x6c,0x43,DAT_001015f8,0x10c);
    pDVar1 = (DSO_FUNC_TYPE)0x0;
  }
  else {
    p_Var2 = dso->meth->dso_bind_func;
    if (p_Var2 == (_func_3877 *)0x0) {
      ERR_put_error(0x25,0x6c,0x6c,DAT_001015f8,0x110);
      pDVar1 = (DSO_FUNC_TYPE)0x0;
    }
    else {
      pDVar1 = (*p_Var2)(dso,symname);
      if (pDVar1 == (DSO_FUNC_TYPE)0x0) {
        ERR_put_error(0x25,0x6c,0x6a,DAT_001015f8,0x114);
      }
    }
  }
  return pDVar1;
}

