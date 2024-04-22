
undefined4
ndef_suffix(undefined4 param_1,ASN1_VALUE **param_2,ASN1_VALUE **param_3,undefined4 *param_4)

{
  int iVar1;
  ASN1_VALUE **ppAVar2;
  ASN1_VALUE *local_30;
  ASN1_VALUE *local_2c;
  ASN1_VALUE *local_28;
  ASN1_VALUE *local_24;
  
  if (param_4 != (undefined4 *)0x0) {
    ppAVar2 = (ASN1_VALUE **)*param_4;
    local_28 = ppAVar2[2];
    local_24 = ppAVar2[4];
    local_2c = ppAVar2[3];
    iVar1 = (**(code **)(*(int *)(ppAVar2[1] + 0x10) + 0x10))(0xb,ppAVar2,ppAVar2[1],&local_2c);
    if (0 < iVar1) {
      iVar1 = ASN1_item_ndef_i2d(*ppAVar2,(uchar **)0x0,(ASN1_ITEM *)ppAVar2[1]);
      local_30 = (ASN1_VALUE *)CRYPTO_malloc(iVar1,DAT_00126eb8,0xea);
      if (local_30 != (ASN1_VALUE *)0x0) {
        ppAVar2[5] = local_30;
        *param_2 = local_30;
        iVar1 = ASN1_item_ndef_i2d(*ppAVar2,(uchar **)&local_30,(ASN1_ITEM *)ppAVar2[1]);
        if (*(ASN1_VALUE **)ppAVar2[4] != (ASN1_VALUE *)0x0) {
          *param_2 = *(ASN1_VALUE **)ppAVar2[4];
          *param_3 = ppAVar2[5] + (iVar1 - *(int *)ppAVar2[4]);
          return 1;
        }
      }
    }
  }
  return 0;
}

