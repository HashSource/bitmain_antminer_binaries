
undefined4
uint32_c2i(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
          int param_6)

{
  int iVar1;
  uint *puVar2;
  bool bVar3;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  uint local_20;
  int iStack_1c;
  
  puVar2 = (uint *)*param_1;
  local_20 = 0;
  iStack_1c = 0;
  local_28 = 0;
  local_24 = 0;
  local_2c = param_2;
  if (puVar2 == (uint *)0x0) {
    puVar2 = (uint *)CRYPTO_zalloc(8,"crypto/asn1/x_int64.c",0x1f);
    *param_1 = puVar2;
    if (puVar2 == (uint *)0x0) {
      ERR_put_error(0xd,0x8d,0x41,"crypto/asn1/x_int64.c",0x20);
      return 0;
    }
  }
  if (param_3 != 0) {
    iVar1 = c2i_uint64_int(&local_20,&local_24,&local_2c);
    if (iVar1 == 0) {
      return 0;
    }
    if ((*(uint *)(param_6 + 0x14) & 2) == 0) {
      if (local_24 != 0) {
        ERR_put_error(0xd,0x69,0xe2,"crypto/asn1/x_int64.c",200);
        return 0;
      }
      if (iStack_1c != 0) {
LAB_001068f0:
        ERR_put_error(0xd,0x69,0xdf,"crypto/asn1/x_int64.c",0xd4);
        return 0;
      }
    }
    else if (local_24 == 0) {
      if (iStack_1c != 0 || 0x7fffffff < local_20) goto LAB_001068f0;
    }
    else {
      bVar3 = iStack_1c == 0;
      if (iStack_1c == 0) {
        bVar3 = local_20 < 0x80000001;
      }
      if (!bVar3) {
        ERR_put_error(0xd,0x69,0xe0,"crypto/asn1/x_int64.c",0xcd);
        return 0;
      }
      local_20 = -local_20;
    }
  }
  *puVar2 = local_20;
  return 1;
}

