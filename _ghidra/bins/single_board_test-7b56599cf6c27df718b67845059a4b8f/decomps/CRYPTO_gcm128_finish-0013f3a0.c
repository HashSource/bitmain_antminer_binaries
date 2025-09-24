
int CRYPTO_gcm128_finish(int param_1,void *param_2,uint param_3)

{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 local_50;
  undefined4 local_40;
  undefined4 local_3c;
  
  uVar6 = *(uint *)(param_1 + 0x30);
  uVar4 = *(int *)(param_1 + 0x34) << 3;
  uVar2 = *(uint *)(param_1 + 0x38);
  iVar9 = *(int *)(param_1 + 0x168);
  uVar7 = *(int *)(param_1 + 0x3c) << 3;
  uVar5 = uVar4 | uVar6 >> 0x1d;
  uVar8 = uVar7 | uVar2 >> 0x1d;
  if (iVar9 == 0) {
    uVar3 = 0;
    if (*(int *)(param_1 + 0x16c) == 0) {
      local_3c = 0x10;
    }
    else {
      gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
      local_3c = 0x10;
    }
  }
  else {
    uVar3 = iVar9 + 0xfU & 0xfffffff0;
    memset((void *)(param_1 + 0x178 + iVar9),0,uVar3 - iVar9);
    if (uVar3 == 0x30) {
      uVar3 = 0;
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_1 + 0x178);
      local_3c = 0x10;
    }
    else {
      local_3c = uVar3 + 0x10;
    }
  }
  local_40 = param_1 + 0x60;
  local_50 = (void *)(param_1 + 0x40);
  iVar10 = param_1 + 0x178;
  *(uint *)(param_1 + 0x30) = uVar6 << 3;
  *(uint *)(param_1 + 0x34) = uVar5;
  *(uint *)(param_1 + 0x38) = uVar2 << 3;
  *(uint *)(param_1 + 0x3c) = uVar8;
  iVar9 = iVar10 + uVar3;
  *(uint *)(iVar10 + uVar3) =
       ((uVar5 << 0x10) >> 0x18) << 0x10 | uVar5 << 0x18 | uVar4 >> 0x18 |
       ((uVar5 << 8) >> 0x18) << 8;
  *(uint *)(iVar9 + 4) =
       ((uVar6 << 0x13) >> 0x18) << 0x10 | uVar6 << 0x1b | (uVar6 << 3) >> 0x18 |
       ((uVar6 << 0xb) >> 0x18) << 8;
  *(uint *)(iVar9 + 8) =
       ((uVar8 << 0x10) >> 0x18) << 0x10 | uVar8 << 0x18 | uVar7 >> 0x18 |
       ((uVar8 << 8) >> 0x18) << 8;
  *(uint *)(iVar9 + 0xc) =
       ((uVar2 << 0x13) >> 0x18) << 0x10 | uVar2 << 0x1b | (uVar2 << 3) >> 0x18 |
       ((uVar2 << 0xb) >> 0x18) << 8;
  gcm_ghash_4bit(local_50,local_40,iVar10,local_3c);
  pvVar1 = param_2;
  if (param_2 != (void *)0x0) {
    pvVar1 = (void *)0x1;
  }
  if (0x10 < param_3) {
    pvVar1 = (void *)0x0;
  }
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ *(uint *)(param_1 + 0x20);
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ *(uint *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ *(uint *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ *(uint *)(param_1 + 0x2c);
  if (pvVar1 != (void *)0x0) {
    iVar9 = CRYPTO_memcmp(local_50,param_2,param_3);
    return iVar9;
  }
  return -1;
}

