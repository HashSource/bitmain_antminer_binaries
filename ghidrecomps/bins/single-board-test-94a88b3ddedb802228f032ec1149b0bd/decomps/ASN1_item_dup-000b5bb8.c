
void * ASN1_item_dup(ASN1_ITEM *it,void *x)

{
  int len;
  ASN1_VALUE *pAVar1;
  uchar *local_18;
  uchar *local_14;
  
  local_18 = (uchar *)0x0;
  if (x == (void *)0x0) {
    pAVar1 = (ASN1_VALUE *)0x0;
  }
  else {
    len = ASN1_item_i2d((ASN1_VALUE *)x,&local_18,it);
    if (local_18 == (uchar *)0x0) {
      ERR_put_error(0xd,0xbf,0x41,DAT_000b5c08,0x6e);
      pAVar1 = (ASN1_VALUE *)0x0;
    }
    else {
      local_14 = local_18;
      pAVar1 = ASN1_item_d2i((ASN1_VALUE **)0x0,&local_14,len,it);
      CRYPTO_free(local_18);
    }
  }
  return pAVar1;
}

