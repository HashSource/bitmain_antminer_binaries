
DH * PEM_read_bio_DHparams(BIO *bp,DH **x,undefined1 *cb,void *u)

{
  DH *pDVar1;
  int iVar2;
  char *local_20;
  uchar *local_1c;
  uchar *local_18;
  long local_14 [2];
  
  local_20 = (char *)0x0;
  local_1c = (uchar *)0x0;
  local_18 = (uchar *)0x0;
  pDVar1 = (DH *)PEM_bytes_read_bio(&local_18,local_14,&local_20,"DH PARAMETERS",bp,cb,u);
  if (pDVar1 != (DH *)0x0) {
    local_1c = local_18;
    iVar2 = strcmp(local_20,"X9.42 DH PARAMETERS");
    if (iVar2 == 0) {
      pDVar1 = (DH *)d2i_DHxparams(x,&local_1c,local_14[0]);
    }
    else {
      pDVar1 = d2i_DHparams(x,&local_1c,local_14[0]);
    }
    if (pDVar1 == (DH *)0x0) {
      ERR_put_error(9,0x8d,0xd,"crypto/pem/pem_pkey.c",0xe4);
    }
    CRYPTO_free(local_20);
    CRYPTO_free(local_18);
  }
  return pDVar1;
}

