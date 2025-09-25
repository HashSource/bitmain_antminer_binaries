
int BIO_vprintf(BIO *bio,char *format,va_list args)

{
  int iVar1;
  int local_82c;
  undefined1 *local_828;
  undefined4 local_824;
  void *local_820;
  undefined1 auStack_81c [4];
  undefined1 auStack_818 [2048];
  
  local_820 = (void *)0x0;
  local_824 = 0x800;
  local_828 = auStack_818;
  iVar1 = _dopr(&local_828,&local_820,&local_824,&local_82c,auStack_81c,format,args);
  if (iVar1 == 0) {
    CRYPTO_free(local_820);
    iVar1 = -1;
  }
  else {
    if (local_820 == (void *)0x0) {
      iVar1 = BIO_write(bio,auStack_818,local_82c);
      return iVar1;
    }
    iVar1 = BIO_write(bio,local_820,local_82c);
    CRYPTO_free(local_820);
  }
  return iVar1;
}

