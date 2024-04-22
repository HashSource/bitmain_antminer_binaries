
void * DSO_global_lookup(char *name)

{
  DSO_METHOD *pDVar1;
  void *pvVar2;
  
  pDVar1 = *DAT_001019c4;
  if (pDVar1 == (DSO_METHOD *)0x0) {
    pDVar1 = DSO_METHOD_openssl();
  }
  if (pDVar1->globallookup == (_func_3882 *)0x0) {
    ERR_put_error(0x25,0x8b,0x6c,DAT_001019c8,0x1bb);
    pvVar2 = (void *)0x0;
  }
  else {
    pvVar2 = (*pDVar1->globallookup)(name);
  }
  return pvVar2;
}

