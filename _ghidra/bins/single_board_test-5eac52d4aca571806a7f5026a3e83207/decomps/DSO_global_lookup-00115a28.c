
void * DSO_global_lookup(char *name)

{
  void *pvVar1;
  DSO_METHOD *pDVar2;
  char *in_r1;
  char *extraout_r1;
  int in_r2;
  int extraout_r2;
  
  pDVar2 = default_DSO_meth;
  if (default_DSO_meth == (DSO_METHOD *)0x0) {
    pDVar2 = DSO_METHOD_openssl();
    in_r1 = extraout_r1;
    in_r2 = extraout_r2;
  }
  if (pDVar2->pathbyaddr != (_func_3881 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00115a44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pvVar1 = (void *)(*pDVar2->pathbyaddr)(name,in_r1,in_r2);
    return pvVar1;
  }
  ERR_put_error(0x25,0x8b,0x6c,"crypto/dso/dso_lib.c",0x15a);
  return (void *)0x0;
}

