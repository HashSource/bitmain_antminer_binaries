
undefined4 ndef_suffix(undefined4 param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  uchar *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  if (param_4 != (undefined4 *)0x0) {
    param_4 = (undefined4 *)*param_4;
    local_28 = param_4[2];
    local_24 = param_4[4];
    local_2c = param_4[3];
    iVar1 = (**(code **)(*(int *)(param_4[1] + 0x10) + 0x10))(0xb,param_4,param_4[1],&local_2c);
    if (0 < iVar1) {
      iVar1 = ASN1_item_ndef_i2d((ASN1_VALUE *)*param_4,(uchar **)0x0,(ASN1_ITEM *)param_4[1]);
      local_30 = (uchar *)CRYPTO_malloc(iVar1,"bio_ndef.c",0xea);
      if (local_30 != (uchar *)0x0) {
        param_4[5] = local_30;
        *param_2 = (int)local_30;
        iVar1 = ASN1_item_ndef_i2d((ASN1_VALUE *)*param_4,&local_30,(ASN1_ITEM *)param_4[1]);
        if (*(int *)param_4[4] != 0) {
          *param_2 = *(int *)param_4[4];
          *param_3 = (param_4[5] - *(int *)param_4[4]) + iVar1;
          return 1;
        }
      }
    }
  }
  return 0;
}

