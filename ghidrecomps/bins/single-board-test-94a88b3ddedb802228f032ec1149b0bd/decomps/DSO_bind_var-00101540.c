
void * DSO_bind_var(DSO *dso,char *symname)

{
  void *pvVar1;
  _func_3876 *p_Var2;
  
  if (dso == (DSO *)0x0 || symname == (char *)0x0) {
    ERR_put_error(0x25,0x6d,0x43,DAT_00101598,0xf8);
    pvVar1 = (void *)0x0;
  }
  else {
    p_Var2 = dso->meth->dso_bind_var;
    if (p_Var2 == (_func_3876 *)0x0) {
      ERR_put_error(0x25,0x6d,0x6c,DAT_00101598,0xfc);
      pvVar1 = (void *)0x0;
    }
    else {
      pvVar1 = (*p_Var2)(dso,symname);
      if (pvVar1 == (void *)0x0) {
        ERR_put_error(0x25,0x6d,0x6a,DAT_00101598,0x100);
      }
    }
  }
  return pvVar1;
}

