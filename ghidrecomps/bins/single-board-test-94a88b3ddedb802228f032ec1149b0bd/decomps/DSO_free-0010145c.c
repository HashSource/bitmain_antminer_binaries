
int DSO_free(DSO *dso)

{
  int iVar1;
  DSO_METHOD *pDVar2;
  
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x6f,0x43,DAT_001014fc,0x88);
    iVar1 = 0;
  }
  else {
    iVar1 = CRYPTO_add_lock(&dso->references,-1,0x1c,DAT_001014fc,0x8c);
    if (iVar1 < 1) {
      pDVar2 = dso->meth;
      if (pDVar2->dso_unload != (_func_3875 *)0x0) {
        iVar1 = (*pDVar2->dso_unload)(dso);
        if (iVar1 == 0) {
          ERR_put_error(0x25,0x6f,0x6b,DAT_001014fc,0x9a);
          return 0;
        }
        pDVar2 = dso->meth;
      }
      if ((pDVar2->finish == (_func_3880 *)0x0) || (iVar1 = (*pDVar2->finish)(dso), iVar1 != 0)) {
        sk_free(&dso->meth_data->stack);
        if (dso->filename != (char *)0x0) {
          CRYPTO_free(dso->filename);
        }
        if (dso->loaded_filename != (char *)0x0) {
          CRYPTO_free(dso->loaded_filename);
        }
        CRYPTO_free(dso);
        iVar1 = 1;
      }
      else {
        ERR_put_error(0x25,0x6f,0x66,DAT_001014fc,0x9f);
        iVar1 = 0;
      }
    }
    else {
      iVar1 = 1;
    }
  }
  return iVar1;
}

