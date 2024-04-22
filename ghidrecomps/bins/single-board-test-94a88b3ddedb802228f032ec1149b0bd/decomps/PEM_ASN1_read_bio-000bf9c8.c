
void * PEM_ASN1_read_bio(undefined1 *d2i,char *name,BIO *bp,void **x,undefined1 *cb,void *u)

{
  void *pvVar1;
  uchar *local_24;
  uchar *local_20;
  long local_1c;
  
  local_20 = (uchar *)0x0;
  local_24 = (uchar *)0x0;
  pvVar1 = (void *)PEM_bytes_read_bio(&local_20,&local_1c,(char **)0x0,name,bp,cb,u);
  if (pvVar1 != (void *)0x0) {
    local_24 = local_20;
    pvVar1 = (void *)(*(code *)d2i)(x,&local_24,local_1c);
    if (pvVar1 == (void *)0x0) {
      ERR_put_error(9,0x67,0xd,DAT_000bfa28,0x53);
    }
    CRYPTO_free(local_20);
  }
  return pvVar1;
}

