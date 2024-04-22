
int DSO_pathbyaddr(void *addr,char *path,int sz)

{
  DSO_METHOD *pDVar1;
  int iVar2;
  
  pDVar1 = *DAT_00101988;
  if (pDVar1 == (DSO_METHOD *)0x0) {
    pDVar1 = DSO_METHOD_openssl();
  }
  if (pDVar1->pathbyaddr == (_func_3881 *)0x0) {
    ERR_put_error(0x25,0x8c,0x6c,DAT_0010198c,0x1af);
    iVar2 = -1;
  }
  else {
    iVar2 = (*pDVar1->pathbyaddr)(addr,path,sz);
  }
  return iVar2;
}

