
void * ASN1_d2i_fp(xnew *xnew,undefined1 *d2i,FILE *in,void **x)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  void *pvVar2;
  BUF_MEM *local_20;
  char *local_1c [2];
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xd,0x6d,7,DAT_0010623c,0x4c);
    pvVar2 = (void *)0x0;
  }
  else {
    pvVar2 = (void *)0x0;
    BIO_ctrl(bp,0x6a,0,in);
    local_20 = (BUF_MEM *)0x0;
    iVar1 = asn1_d2i_read_bio(bp,&local_20);
    if (-1 < iVar1) {
      local_1c[0] = local_20->data;
      pvVar2 = (void *)(*(code *)d2i)(x,local_1c);
    }
    if (local_20 != (BUF_MEM *)0x0) {
      BUF_MEM_free(local_20);
    }
    BIO_free(bp);
  }
  return pvVar2;
}

