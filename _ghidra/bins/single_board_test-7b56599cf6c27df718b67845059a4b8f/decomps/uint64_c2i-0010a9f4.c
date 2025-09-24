
undefined4
uint64_c2i(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
          int param_6)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  undefined4 local_2c [2];
  int local_24;
  int local_20;
  int iStack_1c;
  
  piVar2 = (int *)*param_1;
  local_20 = 0;
  iStack_1c = 0;
  local_24 = 0;
  local_2c[0] = param_2;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)CRYPTO_zalloc(8,"crypto/asn1/x_int64.c",0x1f);
    *param_1 = piVar2;
    if (piVar2 == (int *)0x0) {
      ERR_put_error(0xd,0x8d,0x41,"crypto/asn1/x_int64.c",0x20);
      return 0;
    }
  }
  if (param_3 != 0) {
    iVar1 = c2i_uint64_int(&local_20,&local_24,local_2c);
    if (iVar1 == 0) {
      return 0;
    }
    if ((*(uint *)(param_6 + 0x14) & 2) == 0) {
      if (local_24 != 0) {
        ERR_put_error(0xd,0x70,0xe2,"crypto/asn1/x_int64.c",0x61);
        return 0;
      }
    }
    else if (local_24 == 0) {
      if (iStack_1c < 0) {
        ERR_put_error(0xd,0x70,0xdf,"crypto/asn1/x_int64.c",0x66);
        return 0;
      }
    }
    else {
      bVar3 = local_20 != 0;
      local_20 = -local_20;
      iStack_1c = -iStack_1c - (uint)bVar3;
    }
  }
  *piVar2 = local_20;
  piVar2[1] = iStack_1c;
  return 1;
}

