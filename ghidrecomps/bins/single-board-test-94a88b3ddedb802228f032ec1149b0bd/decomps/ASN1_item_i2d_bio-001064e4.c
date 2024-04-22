
int ASN1_item_i2d_bio(ASN1_ITEM *it,BIO *out,void *x)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  uchar *local_1c [2];
  
  iVar3 = 0;
  local_1c[0] = (uchar *)0x0;
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)x,local_1c,it);
  if (local_1c[0] == (uchar *)0x0) {
    ERR_put_error(0xd,0xc0,0x41,DAT_00106544,0x8c);
    iVar1 = 0;
  }
  else {
    do {
      iVar2 = BIO_write(out,local_1c[0] + iVar3,iVar1);
      bVar4 = iVar2 == iVar1;
      iVar3 = iVar3 + iVar2;
      iVar1 = iVar1 - iVar2;
      if (bVar4) {
        iVar1 = 1;
        goto LAB_00106522;
      }
    } while (0 < iVar2);
    iVar1 = 0;
LAB_00106522:
    CRYPTO_free(local_1c[0]);
  }
  return iVar1;
}

