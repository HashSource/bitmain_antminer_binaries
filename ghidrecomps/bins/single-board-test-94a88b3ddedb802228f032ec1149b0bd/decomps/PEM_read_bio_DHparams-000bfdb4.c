
DH * PEM_read_bio_DHparams(BIO *bp,DH **x,undefined1 *cb,void *u)

{
  int iVar1;
  DH *pDVar2;
  char *local_20;
  uchar *local_1c;
  uchar *local_18;
  long local_14;
  
  local_18 = (uchar *)0x0;
  local_20 = (char *)0x0;
  local_1c = (uchar *)0x0;
  iVar1 = PEM_bytes_read_bio(&local_18,&local_14,&local_20,DAT_000bfe30,bp,cb,u);
  if (iVar1 == 0) {
    pDVar2 = (DH *)0x0;
  }
  else {
    local_1c = local_18;
    iVar1 = strcmp(local_20,DAT_000bfe34);
    if (iVar1 == 0) {
      pDVar2 = (DH *)d2i_DHxparams(x,&local_1c,local_14);
    }
    else {
      pDVar2 = d2i_DHparams(x,&local_1c,local_14);
    }
    if (pDVar2 == (DH *)0x0) {
      ERR_put_error(9,0x8d,0xd,DAT_000bfe38,0x10e);
    }
    CRYPTO_free(local_20);
    CRYPTO_free(local_18);
  }
  return pDVar2;
}

