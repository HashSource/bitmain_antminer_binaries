
undefined4 WPACKET_init_static_len(int *param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int local_1c;
  
  if (param_4 - 1 < 3) {
    uVar2 = (1 << ((param_4 & 0x1f) << 3)) + (param_4 - 1);
  }
  else {
    uVar2 = 0xffffffff;
  }
  if (param_2 != 0 && param_3 != 0) {
    if (uVar2 <= param_3) {
      param_3 = uVar2;
    }
    param_1[4] = param_3;
    param_1[1] = param_2;
    *param_1 = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    iVar1 = CRYPTO_zalloc(0x14,"ssl/packet.c",0x61);
    param_1[5] = iVar1;
    if (iVar1 == 0) {
      ERR_put_error(0x14,0x279,0x41,"ssl/packet.c",0x62);
    }
    else {
      if (param_4 == 0) {
        return 1;
      }
      *(uint *)(iVar1 + 0xc) = param_4;
      *(uint *)(iVar1 + 8) = param_4;
      iVar1 = WPACKET_allocate_bytes(param_1,param_4,&local_1c);
      if (iVar1 != 0) {
        iVar1 = param_1[1];
        if (iVar1 == 0) {
          iVar1 = *(int *)(*param_1 + 4);
        }
        *(int *)(param_1[5] + 4) = local_1c - iVar1;
        return 1;
      }
      CRYPTO_free((void *)param_1[5]);
      param_1[5] = 0;
    }
  }
  return 0;
}

