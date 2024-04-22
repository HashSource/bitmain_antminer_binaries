
undefined4 ndef_prefix(undefined4 param_1,ASN1_VALUE **param_2,int *param_3,undefined4 *param_4)

{
  int num;
  ASN1_VALUE **ppAVar1;
  ASN1_VALUE *local_14;
  
  if (param_4 != (undefined4 *)0x0) {
    ppAVar1 = (ASN1_VALUE **)*param_4;
    num = ASN1_item_ndef_i2d(*ppAVar1,(uchar **)0x0,(ASN1_ITEM *)ppAVar1[1]);
    local_14 = (ASN1_VALUE *)CRYPTO_malloc(num,DAT_00126f04,0xa4);
    if (local_14 != (ASN1_VALUE *)0x0) {
      ppAVar1[5] = local_14;
      *param_2 = local_14;
      ASN1_item_ndef_i2d(*ppAVar1,(uchar **)&local_14,(ASN1_ITEM *)ppAVar1[1]);
      if (*(int *)ppAVar1[4] != 0) {
        *param_3 = *(int *)ppAVar1[4] - (int)*param_2;
        return 1;
      }
    }
  }
  return 0;
}

