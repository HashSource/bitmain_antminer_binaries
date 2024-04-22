
int BIO_vprintf(BIO *bio,char *format,va_list args)

{
  int iVar1;
  int local_82c;
  undefined *local_828;
  undefined4 local_824;
  void *local_820;
  undefined auStack_81c [4];
  undefined auStack_818 [2048];
  
  local_824 = 0x800;
  local_820 = (void *)0x0;
  local_828 = auStack_818;
  CRYPTO_push_info_(DAT_000ab1ec,DAT_000ab1e8,0x302);
  _dopr(&local_828,&local_820,&local_824,&local_82c,auStack_81c,format,args);
  if (local_820 == (void *)0x0) {
    iVar1 = BIO_write(bio,auStack_818,local_82c);
  }
  else {
    iVar1 = BIO_write(bio,local_820,local_82c);
    CRYPTO_free(local_820);
  }
  CRYPTO_pop_info();
  return iVar1;
}

