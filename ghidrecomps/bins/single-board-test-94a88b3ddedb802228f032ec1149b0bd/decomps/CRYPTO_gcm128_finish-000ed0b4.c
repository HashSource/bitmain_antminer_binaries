
int CRYPTO_gcm128_finish(int param_1,void *param_2,uint param_3)

{
  int extraout_r1;
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  void *a;
  int local_2c;
  
  a = (void *)(param_1 + 0x40);
  uVar2 = *(uint *)(param_1 + 0x30);
  uVar7 = *(uint *)(param_1 + 0x38);
  uVar5 = *(int *)(param_1 + 0x34) << 3;
  uVar3 = *(int *)(param_1 + 0x3c) << 3;
  uVar6 = uVar5 | uVar2 >> 0x1d;
  uVar4 = uVar3 | uVar7 >> 0x1d;
  if ((*(int *)(param_1 + 0x168) != 0) || (*(int *)(param_1 + 0x16c) != 0)) {
    gcm_gmult_4bit(a,param_1 + 0x60);
  }
  local_2c = param_1 + 0x60;
  *(uint *)(param_1 + 0x30) = uVar2 << 3;
  *(uint *)(param_1 + 0x34) = uVar6;
  *(uint *)(param_1 + 0x3c) = uVar4;
  *(uint *)(param_1 + 0x38) = uVar7 << 3;
  *(uint *)(param_1 + 0x40) =
       (((uVar6 << 0x10) >> 0x18) << 0x10 | uVar6 << 0x18 | uVar5 >> 0x18 |
       ((uVar6 << 8) >> 0x18) << 8) ^ *(uint *)(param_1 + 0x40);
  *(uint *)(param_1 + 0x44) =
       (((uVar2 << 0x13) >> 0x18) << 0x10 | uVar2 << 0x1b | (uVar2 << 3) >> 0x18 |
       ((uVar2 << 0xb) >> 0x18) << 8) ^ *(uint *)(param_1 + 0x44);
  *(uint *)(param_1 + 0x48) =
       (((uVar4 << 0x10) >> 0x18) << 0x10 | uVar4 << 0x18 | uVar3 >> 0x18 |
       ((uVar4 << 8) >> 0x18) << 8) ^ *(uint *)(param_1 + 0x48);
  *(uint *)(param_1 + 0x4c) =
       (((uVar7 << 0x13) >> 0x18) << 0x10 | uVar7 << 0x1b | (uVar7 << 3) >> 0x18 |
       ((uVar7 << 0xb) >> 0x18) << 8) ^ *(uint *)(param_1 + 0x4c);
  gcm_gmult_4bit(a,local_2c);
  iVar1 = extraout_r1;
  if (0x10 < param_3) {
    iVar1 = 0;
  }
  if (param_3 < 0x11) {
    iVar1 = 1;
  }
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x20) ^ *(uint *)(param_1 + 0x40);
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x24) ^ *(uint *)(param_1 + 0x44);
  if (param_2 == (void *)0x0) {
    iVar1 = 0;
  }
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) ^ *(uint *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) ^ *(uint *)(param_1 + 0x2c);
  if (iVar1 == 0) {
    return -1;
  }
  iVar1 = CRYPTO_memcmp(a,param_2,param_3);
  return iVar1;
}

