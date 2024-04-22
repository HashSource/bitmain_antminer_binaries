
undefined4 OCSP_REQ_CTX_i2d(undefined4 *param_1,ASN1_ITEM *param_2,ASN1_VALUE *param_3)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d(param_3,(uchar **)0x0,param_2);
  iVar1 = BIO_printf((BIO *)param_1[4],DAT_000d29c8,iVar1);
  if ((0 < iVar1) && (iVar1 = ASN1_item_i2d_bio(param_2,(BIO *)param_1[4],param_3), 0 < iVar1)) {
    *param_1 = 0x1005;
    return 1;
  }
  return 0;
}

