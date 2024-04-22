
int ASN1_item_i2d_fp(ASN1_ITEM *it,FILE *out,void *x)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  uchar *local_1c [2];
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xd,0xc1,7,DAT_001064e0,0x7b);
    iVar1 = 0;
  }
  else {
    iVar3 = 0;
    BIO_ctrl(bp,0x6a,0,out);
    local_1c[0] = (uchar *)0x0;
    iVar1 = ASN1_item_i2d((ASN1_VALUE *)x,local_1c,it);
    if (local_1c[0] == (uchar *)0x0) {
      ERR_put_error(0xd,0xc0,0x41,DAT_001064e0,0x8c);
      iVar1 = 0;
    }
    else {
      do {
        iVar2 = BIO_write(bp,local_1c[0] + iVar3,iVar1);
        bVar4 = iVar1 == iVar2;
        iVar3 = iVar3 + iVar2;
        iVar1 = iVar1 - iVar2;
        if (bVar4) {
          iVar1 = 1;
          goto LAB_001064a2;
        }
      } while (0 < iVar2);
      iVar1 = 0;
LAB_001064a2:
      CRYPTO_free(local_1c[0]);
    }
    BIO_free(bp);
  }
  return iVar1;
}

