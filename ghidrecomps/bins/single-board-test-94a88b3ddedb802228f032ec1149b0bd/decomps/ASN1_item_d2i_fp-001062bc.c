
void * ASN1_item_d2i_fp(ASN1_ITEM *it,FILE *in,void *x)

{
  BIO_METHOD *type;
  BIO *bp;
  int len;
  ASN1_VALUE *pAVar1;
  BUF_MEM *local_20;
  uchar *local_1c [2];
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xd,0xce,7,DAT_0010632c,0x85);
    pAVar1 = (ASN1_VALUE *)0x0;
  }
  else {
    pAVar1 = (ASN1_VALUE *)0x0;
    BIO_ctrl(bp,0x6a,0,in);
    local_20 = (BUF_MEM *)0x0;
    len = asn1_d2i_read_bio(bp,&local_20);
    if (-1 < len) {
      local_1c[0] = (uchar *)local_20->data;
      pAVar1 = ASN1_item_d2i((ASN1_VALUE **)x,local_1c,len,it);
    }
    if (local_20 != (BUF_MEM *)0x0) {
      BUF_MEM_free(local_20);
    }
    BIO_free(bp);
  }
  return pAVar1;
}

