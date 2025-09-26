
undefined4 ndef_prefix(undefined4 param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int num;
  uchar *local_14;
  
  if (param_4 != (undefined4 *)0x0) {
    param_4 = (undefined4 *)*param_4;
    num = ASN1_item_ndef_i2d((ASN1_VALUE *)*param_4,(uchar **)0x0,(ASN1_ITEM *)param_4[1]);
    local_14 = (uchar *)CRYPTO_malloc(num,"bio_ndef.c",0xa4);
    if (local_14 != (uchar *)0x0) {
      param_4[5] = local_14;
      *param_2 = (int)local_14;
      ASN1_item_ndef_i2d((ASN1_VALUE *)*param_4,&local_14,(ASN1_ITEM *)param_4[1]);
      if (*(int *)param_4[4] != 0) {
        *param_3 = *(int *)param_4[4] - *param_2;
        return 1;
      }
    }
  }
  return 0;
}

