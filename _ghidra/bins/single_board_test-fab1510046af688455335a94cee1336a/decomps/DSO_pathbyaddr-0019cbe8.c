
int DSO_pathbyaddr(void *addr,char *path,int sz)

{
  int iVar1;
  DSO_METHOD *pDVar2;
  
  pDVar2 = default_DSO_meth;
  if (default_DSO_meth == (DSO_METHOD *)0x0) {
    pDVar2 = DSO_METHOD_openssl();
  }
  if (pDVar2->pathbyaddr == (_func_3881 *)0x0) {
    ERR_put_error(0x25,0x8c,0x6c,"dso_lib.c",0x1af);
    iVar1 = -1;
  }
  else {
    iVar1 = (*pDVar2->pathbyaddr)(addr,path,sz);
  }
  return iVar1;
}

