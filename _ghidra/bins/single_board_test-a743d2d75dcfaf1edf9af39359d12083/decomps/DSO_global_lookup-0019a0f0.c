
void * DSO_global_lookup(char *name)

{
  void *pvVar1;
  DSO_METHOD *pDVar2;
  
  pDVar2 = default_DSO_meth;
  if (default_DSO_meth == (DSO_METHOD *)0x0) {
    pDVar2 = DSO_METHOD_openssl();
  }
  if (pDVar2->globallookup == (_func_3882 *)0x0) {
    ERR_put_error(0x25,0x8b,0x6c,"dso_lib.c",0x1bb);
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = (*pDVar2->globallookup)(name);
  }
  return pvVar1;
}

