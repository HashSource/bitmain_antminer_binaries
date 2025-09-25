
int DSO_pathbyaddr(void *addr,char *path,int sz)

{
  int iVar1;
  DSO_METHOD *pDVar2;
  
  pDVar2 = default_DSO_meth;
  if (default_DSO_meth == (DSO_METHOD *)0x0) {
    pDVar2 = DSO_METHOD_openssl();
  }
  if (pDVar2->finish != (_func_3880 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00115992. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*pDVar2->finish)((DSO *)addr);
    return iVar1;
  }
  ERR_put_error(0x25,0x69,0x6c,"crypto/dso/dso_lib.c",0x13c);
  return -1;
}

