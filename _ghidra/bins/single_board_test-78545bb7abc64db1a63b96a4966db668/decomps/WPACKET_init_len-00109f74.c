
undefined4 WPACKET_init_len(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int local_1c [2];
  
  if (param_2 == 0) {
    return 0;
  }
  uVar2 = param_3 - 1;
  *param_1 = param_2;
  param_1[1] = 0;
  if (uVar2 < 3) {
    param_2 = 1 << ((param_3 & 0x1f) << 3);
    uVar3 = uVar2;
  }
  else {
    uVar3 = 0xffffffff;
  }
  param_1[2] = 0;
  if (uVar2 < 3) {
    uVar3 = uVar3 + param_2;
  }
  param_1[4] = uVar3;
  param_1[3] = 0;
  iVar1 = CRYPTO_zalloc(0x14,"ssl/packet.c",0x61);
  param_1[5] = iVar1;
  if (iVar1 == 0) {
    ERR_put_error(0x14,0x279,0x41,"ssl/packet.c",0x62);
    uVar4 = 0;
  }
  else if (param_3 == 0) {
    uVar4 = 1;
  }
  else {
    *(uint *)(iVar1 + 0xc) = param_3;
    *(uint *)(iVar1 + 8) = param_3;
    iVar1 = WPACKET_allocate_bytes(param_1,param_3,local_1c);
    if (iVar1 != 0) {
      iVar1 = param_1[1];
      if (iVar1 == 0) {
        iVar1 = *(int *)(*param_1 + 4);
      }
      *(int *)(param_1[5] + 4) = local_1c[0] - iVar1;
      return 1;
    }
    CRYPTO_free((void *)param_1[5]);
    param_1[5] = 0;
    uVar4 = 0;
  }
  return uVar4;
}

