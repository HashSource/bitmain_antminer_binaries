
DSO * DSO_load(DSO *dso,char *filename,DSO_METHOD *meth,int flags)

{
  int iVar1;
  _func_3874 *p_Var2;
  bool bVar3;
  
  if (dso == (DSO *)0x0) {
    dso = DSO_new_method(meth);
    if (dso == (DSO *)0x0) {
      ERR_put_error(0x25,0x70,0x41,"dso_lib.c",0xc5);
      return (DSO *)0x0;
    }
    dso->flags = flags;
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (dso->filename != (char *)0x0) {
    ERR_put_error(0x25,0x70,0x6e,"dso_lib.c",0xd2);
    goto joined_r0x001017bc;
  }
  if (filename != (char *)0x0) {
    iVar1 = DSO_set_filename(dso,filename);
    if (iVar1 == 0) {
      ERR_put_error(0x25,0x70,0x70,"dso_lib.c",0xdb);
      goto joined_r0x001017bc;
    }
    if (dso->filename != (char *)0x0) {
      p_Var2 = dso->meth->dso_load;
      if (p_Var2 == (_func_3874 *)0x0) {
        ERR_put_error(0x25,0x70,0x6c,"dso_lib.c",0xe4);
      }
      else {
        iVar1 = (*p_Var2)(dso);
        if (iVar1 != 0) {
          return dso;
        }
        ERR_put_error(0x25,0x70,0x67,"dso_lib.c",0xe8);
      }
      goto joined_r0x001017bc;
    }
  }
  ERR_put_error(0x25,0x70,0x6f,"dso_lib.c",0xe0);
joined_r0x001017bc:
  if (bVar3) {
    DSO_free(dso);
  }
  return (DSO *)0x0;
}

