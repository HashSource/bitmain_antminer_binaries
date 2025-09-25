
undefined4 ndef_prefix(undefined4 param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int num;
  undefined4 uVar1;
  uchar *local_1c;
  
  if (param_4 == (undefined4 *)0x0) {
    return 0;
  }
  param_4 = (undefined4 *)*param_4;
  num = ASN1_item_ndef_i2d((ASN1_VALUE *)*param_4,(uchar **)0x0,(ASN1_ITEM *)param_4[1]);
  if (num < 0) {
    return 0;
  }
  local_1c = (uchar *)CRYPTO_malloc(num,"crypto/asn1/bio_ndef.c",0x76);
  if (local_1c == (uchar *)0x0) {
    ERR_put_error(0xd,0x7f,0x41,"crypto/asn1/bio_ndef.c",0x77);
    uVar1 = 0;
  }
  else {
    param_4[5] = local_1c;
    *param_2 = (int)local_1c;
    ASN1_item_ndef_i2d((ASN1_VALUE *)*param_4,&local_1c,(ASN1_ITEM *)param_4[1]);
    if (*(int *)param_4[4] == 0) {
      return 0;
    }
    uVar1 = 1;
    *param_3 = *(int *)param_4[4] - *param_2;
  }
  return uVar1;
}

