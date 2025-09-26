
undefined4 ndef_suffix(undefined4 param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uchar *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_4 == (undefined4 *)0x0) {
    return 0;
  }
  param_4 = (undefined4 *)*param_4;
  local_24 = param_4[3];
  local_20 = param_4[2];
  local_1c = param_4[4];
  iVar1 = (**(code **)(*(int *)(param_4[1] + 0x10) + 0x10))(0xb,param_4,param_4[1],&local_24);
  if (iVar1 < 1) {
    return 0;
  }
  iVar1 = ASN1_item_ndef_i2d((ASN1_VALUE *)*param_4,(uchar **)0x0,(ASN1_ITEM *)param_4[1]);
  local_28 = (uchar *)CRYPTO_malloc(iVar1,"crypto/asn1/bio_ndef.c",0xbf);
  if (local_28 == (uchar *)0x0) {
    ERR_put_error(0xd,0x88,0x41,"crypto/asn1/bio_ndef.c",0xc0);
    uVar2 = 0;
  }
  else {
    param_4[5] = local_28;
    *param_2 = (int)local_28;
    iVar1 = ASN1_item_ndef_i2d((ASN1_VALUE *)*param_4,&local_28,(ASN1_ITEM *)param_4[1]);
    if (*(int *)param_4[4] == 0) {
      return 0;
    }
    *param_2 = *(int *)param_4[4];
    uVar2 = 1;
    *param_3 = iVar1 - (*(int *)param_4[4] - param_4[5]);
  }
  return uVar2;
}

