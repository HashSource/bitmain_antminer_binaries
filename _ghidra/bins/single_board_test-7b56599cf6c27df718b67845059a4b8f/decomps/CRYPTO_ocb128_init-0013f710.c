
undefined4
CRYPTO_ocb128_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3,code *param_4,
                  undefined4 param_5,undefined4 param_6)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  void *pvVar4;
  byte *pbVar5;
  char *pcVar6;
  int iVar7;
  
  memset(param_1,0,0x98);
  param_1[6] = 5;
  pvVar4 = CRYPTO_malloc(0x50,"crypto/modes/ocb128.c",0x9e);
  param_1[0x10] = pvVar4;
  if (pvVar4 != (void *)0x0) {
    *param_1 = param_4;
    param_1[2] = param_2;
    param_1[1] = param_5;
    param_1[3] = param_3;
    param_1[4] = param_6;
    (*param_4)(param_1 + 8,param_1 + 8,param_2);
    *(byte *)((int)param_1 + 0x31) =
         (byte)((int)(uint)*(byte *)((int)param_1 + 0x22) >> 7) |
         *(byte *)((int)param_1 + 0x21) << 1;
    *(byte *)((int)param_1 + 0x32) =
         (byte)((int)(uint)*(byte *)((int)param_1 + 0x23) >> 7) |
         *(byte *)((int)param_1 + 0x22) << 1;
    bVar2 = *(byte *)((int)param_1 + 0x2f) << 1 ^ *(char *)(param_1 + 8) >> 7 & 0x87U;
    bVar3 = (byte)((int)(uint)*(byte *)((int)param_1 + 0x21) >> 7) | *(char *)(param_1 + 8) << 1;
    *(byte *)((int)param_1 + 0x33) =
         (byte)((int)(uint)*(byte *)(param_1 + 9) >> 7) | *(byte *)((int)param_1 + 0x23) << 1;
    *(byte *)(param_1 + 0xc) = bVar3;
    *(byte *)(param_1 + 0xd) =
         (byte)((int)(uint)*(byte *)((int)param_1 + 0x25) >> 7) | *(byte *)(param_1 + 9) << 1;
    *(byte *)((int)param_1 + 0x3e) =
         (byte)((int)(uint)*(byte *)((int)param_1 + 0x2f) >> 7) |
         *(byte *)((int)param_1 + 0x2e) << 1;
    *(byte *)((int)param_1 + 0x35) =
         (byte)((int)(uint)*(byte *)((int)param_1 + 0x26) >> 7) |
         *(byte *)((int)param_1 + 0x25) << 1;
    *(byte *)((int)param_1 + 0x3f) = bVar2;
    *(byte *)((int)param_1 + 0x3b) =
         (byte)((int)(uint)*(byte *)(param_1 + 0xb) >> 7) | *(byte *)((int)param_1 + 0x2b) << 1;
    *(byte *)((int)param_1 + 0x36) =
         (byte)((int)(uint)*(byte *)((int)param_1 + 0x27) >> 7) |
         *(byte *)((int)param_1 + 0x26) << 1;
    *(byte *)((int)param_1 + 0x37) =
         (byte)((int)(uint)*(byte *)(param_1 + 10) >> 7) | *(byte *)((int)param_1 + 0x27) << 1;
    *(byte *)((int)param_1 + 0x39) =
         (byte)((int)(uint)*(byte *)((int)param_1 + 0x2a) >> 7) |
         *(byte *)((int)param_1 + 0x29) << 1;
    *(byte *)((int)param_1 + 0x3a) =
         (byte)((int)(uint)*(byte *)((int)param_1 + 0x2b) >> 7) |
         *(byte *)((int)param_1 + 0x2a) << 1;
    *(byte *)(param_1 + 0xe) =
         (byte)((int)(uint)*(byte *)((int)param_1 + 0x29) >> 7) | *(byte *)(param_1 + 10) << 1;
    *(byte *)(param_1 + 0xf) =
         (byte)((int)(uint)*(byte *)((int)param_1 + 0x2d) >> 7) | *(byte *)(param_1 + 0xb) << 1;
    *(byte *)((int)param_1 + 0x3d) =
         (byte)((int)(uint)*(byte *)((int)param_1 + 0x2e) >> 7) |
         *(byte *)((int)param_1 + 0x2d) << 1;
    pbVar5 = (byte *)param_1[0x10];
    pbVar5[0xf] = bVar2 << 1;
    bVar1 = *(byte *)((int)param_1 + 0x3e);
    pbVar5[0xe] = (byte)((int)(uint)bVar2 >> 7) | bVar1 << 1;
    bVar2 = *(byte *)((int)param_1 + 0x3d);
    pbVar5[0xd] = (byte)((int)(uint)bVar1 >> 7) | bVar2 << 1;
    bVar1 = *(byte *)(param_1 + 0xf);
    pbVar5[0xc] = (byte)((int)(uint)bVar2 >> 7) | bVar1 << 1;
    bVar2 = *(byte *)((int)param_1 + 0x3b);
    pbVar5[0xb] = (byte)((int)(uint)bVar1 >> 7) | bVar2 << 1;
    bVar1 = *(byte *)((int)param_1 + 0x3a);
    pbVar5[10] = (byte)((int)(uint)bVar2 >> 7) | bVar1 << 1;
    bVar2 = *(byte *)((int)param_1 + 0x39);
    pbVar5[9] = (byte)((int)(uint)bVar1 >> 7) | bVar2 << 1;
    bVar1 = *(byte *)(param_1 + 0xe);
    pbVar5[8] = (byte)((int)(uint)bVar2 >> 7) | bVar1 << 1;
    bVar2 = *(byte *)((int)param_1 + 0x37);
    pbVar5[7] = (byte)((int)(uint)bVar1 >> 7) | bVar2 << 1;
    bVar1 = *(byte *)((int)param_1 + 0x36);
    pbVar5[6] = (byte)((int)(uint)bVar2 >> 7) | bVar1 << 1;
    bVar2 = *(byte *)((int)param_1 + 0x35);
    pbVar5[5] = (byte)((int)(uint)bVar1 >> 7) | bVar2 << 1;
    bVar1 = *(byte *)(param_1 + 0xd);
    pbVar5[4] = (byte)((int)(uint)bVar2 >> 7) | bVar1 << 1;
    bVar2 = *(byte *)((int)param_1 + 0x33);
    pbVar5[3] = (byte)((int)(uint)bVar1 >> 7) | bVar2 << 1;
    bVar1 = *(byte *)((int)param_1 + 0x32);
    pbVar5[2] = (byte)((int)(uint)bVar2 >> 7) | bVar1 << 1;
    bVar2 = *(byte *)((int)param_1 + 0x31);
    pbVar5[1] = (byte)((int)(uint)bVar1 >> 7) | bVar2 << 1;
    *pbVar5 = (byte)((int)(uint)bVar2 >> 7) | *(char *)(param_1 + 0xc) << 1;
    pbVar5[0xf] = pbVar5[0xf] ^ (char)bVar3 >> 7 & 0x87U;
    pcVar6 = (char *)param_1[0x10];
    pcVar6[0x1e] = (byte)((int)(uint)(byte)pcVar6[0xf] >> 7) | pcVar6[0xe] << 1;
    pcVar6[0x1d] = (byte)((int)(uint)(byte)pcVar6[0xe] >> 7) | pcVar6[0xd] << 1;
    pcVar6[0x1c] = (byte)((int)(uint)(byte)pcVar6[0xd] >> 7) | pcVar6[0xc] << 1;
    pcVar6[0x1b] = (byte)((int)(uint)(byte)pcVar6[0xc] >> 7) | pcVar6[0xb] << 1;
    pcVar6[0x1a] = (byte)((int)(uint)(byte)pcVar6[0xb] >> 7) | pcVar6[10] << 1;
    pcVar6[0x19] = (byte)((int)(uint)(byte)pcVar6[10] >> 7) | pcVar6[9] << 1;
    pcVar6[0x18] = (byte)((int)(uint)(byte)pcVar6[9] >> 7) | pcVar6[8] << 1;
    pcVar6[0x17] = (byte)((int)(uint)(byte)pcVar6[8] >> 7) | pcVar6[7] << 1;
    pcVar6[0x16] = (byte)((int)(uint)(byte)pcVar6[7] >> 7) | pcVar6[6] << 1;
    pcVar6[0x15] = (byte)((int)(uint)(byte)pcVar6[6] >> 7) | pcVar6[5] << 1;
    pcVar6[0x14] = (byte)((int)(uint)(byte)pcVar6[5] >> 7) | pcVar6[4] << 1;
    pcVar6[0x13] = (byte)((int)(uint)(byte)pcVar6[4] >> 7) | pcVar6[3] << 1;
    pcVar6[0x12] = (byte)((int)(uint)(byte)pcVar6[3] >> 7) | pcVar6[2] << 1;
    pcVar6[0x11] = (byte)((int)(uint)(byte)pcVar6[2] >> 7) | pcVar6[1] << 1;
    pcVar6[0x1f] = *pcVar6 >> 7 & 0x87U ^ pcVar6[0xf] << 1;
    pcVar6[0x10] = (byte)((int)(uint)(byte)pcVar6[1] >> 7) | *pcVar6 << 1;
    iVar7 = param_1[0x10];
    *(byte *)(iVar7 + 0x2e) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x1f) >> 7) | *(byte *)(iVar7 + 0x1e) << 1;
    *(byte *)(iVar7 + 0x2d) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x1e) >> 7) | *(byte *)(iVar7 + 0x1d) << 1;
    *(byte *)(iVar7 + 0x2c) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x1d) >> 7) | *(byte *)(iVar7 + 0x1c) << 1;
    *(byte *)(iVar7 + 0x2b) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x1c) >> 7) | *(byte *)(iVar7 + 0x1b) << 1;
    *(byte *)(iVar7 + 0x2a) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x1b) >> 7) | *(byte *)(iVar7 + 0x1a) << 1;
    *(byte *)(iVar7 + 0x29) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x1a) >> 7) | *(byte *)(iVar7 + 0x19) << 1;
    *(byte *)(iVar7 + 0x28) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x19) >> 7) | *(byte *)(iVar7 + 0x18) << 1;
    *(byte *)(iVar7 + 0x27) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x18) >> 7) | *(byte *)(iVar7 + 0x17) << 1;
    *(byte *)(iVar7 + 0x26) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x17) >> 7) | *(byte *)(iVar7 + 0x16) << 1;
    *(byte *)(iVar7 + 0x25) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x16) >> 7) | *(byte *)(iVar7 + 0x15) << 1;
    *(byte *)(iVar7 + 0x24) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x15) >> 7) | *(byte *)(iVar7 + 0x14) << 1;
    *(byte *)(iVar7 + 0x23) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x14) >> 7) | *(byte *)(iVar7 + 0x13) << 1;
    *(byte *)(iVar7 + 0x22) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x13) >> 7) | *(byte *)(iVar7 + 0x12) << 1;
    *(byte *)(iVar7 + 0x21) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x12) >> 7) | *(byte *)(iVar7 + 0x11) << 1;
    *(byte *)(iVar7 + 0x2f) = *(char *)(iVar7 + 0x10) >> 7 & 0x87U ^ *(byte *)(iVar7 + 0x1f) << 1;
    *(byte *)(iVar7 + 0x20) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x11) >> 7) | *(char *)(iVar7 + 0x10) << 1;
    iVar7 = param_1[0x10];
    *(byte *)(iVar7 + 0x3e) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x2f) >> 7) | *(byte *)(iVar7 + 0x2e) << 1;
    *(byte *)(iVar7 + 0x3d) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x2e) >> 7) | *(byte *)(iVar7 + 0x2d) << 1;
    *(byte *)(iVar7 + 0x3c) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x2d) >> 7) | *(byte *)(iVar7 + 0x2c) << 1;
    *(byte *)(iVar7 + 0x3b) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x2c) >> 7) | *(byte *)(iVar7 + 0x2b) << 1;
    *(byte *)(iVar7 + 0x3a) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x2b) >> 7) | *(byte *)(iVar7 + 0x2a) << 1;
    *(byte *)(iVar7 + 0x39) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x2a) >> 7) | *(byte *)(iVar7 + 0x29) << 1;
    *(byte *)(iVar7 + 0x38) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x29) >> 7) | *(byte *)(iVar7 + 0x28) << 1;
    *(byte *)(iVar7 + 0x37) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x28) >> 7) | *(byte *)(iVar7 + 0x27) << 1;
    *(byte *)(iVar7 + 0x36) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x27) >> 7) | *(byte *)(iVar7 + 0x26) << 1;
    *(byte *)(iVar7 + 0x35) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x26) >> 7) | *(byte *)(iVar7 + 0x25) << 1;
    *(byte *)(iVar7 + 0x34) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x25) >> 7) | *(byte *)(iVar7 + 0x24) << 1;
    *(byte *)(iVar7 + 0x33) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x24) >> 7) | *(byte *)(iVar7 + 0x23) << 1;
    *(byte *)(iVar7 + 0x32) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x23) >> 7) | *(byte *)(iVar7 + 0x22) << 1;
    *(byte *)(iVar7 + 0x31) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x22) >> 7) | *(byte *)(iVar7 + 0x21) << 1;
    *(byte *)(iVar7 + 0x3f) = *(char *)(iVar7 + 0x20) >> 7 & 0x87U ^ *(byte *)(iVar7 + 0x2f) << 1;
    *(byte *)(iVar7 + 0x30) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x21) >> 7) | *(char *)(iVar7 + 0x20) << 1;
    iVar7 = param_1[0x10];
    *(byte *)(iVar7 + 0x4b) = *(byte *)(iVar7 + 0x3b) << 1 | *(byte *)(iVar7 + 0x3c) >> 7;
    *(byte *)(iVar7 + 0x4e) = *(byte *)(iVar7 + 0x3e) << 1 | *(byte *)(iVar7 + 0x3f) >> 7;
    *(byte *)(iVar7 + 0x4d) = *(byte *)(iVar7 + 0x3d) << 1 | *(byte *)(iVar7 + 0x3e) >> 7;
    *(byte *)(iVar7 + 0x4c) = *(byte *)(iVar7 + 0x3c) << 1 | *(byte *)(iVar7 + 0x3d) >> 7;
    *(byte *)(iVar7 + 0x48) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x39) >> 7) | *(byte *)(iVar7 + 0x38) << 1;
    *(byte *)(iVar7 + 0x4a) = *(byte *)(iVar7 + 0x3a) << 1 | *(byte *)(iVar7 + 0x3b) >> 7;
    *(byte *)(iVar7 + 0x44) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x35) >> 7) | *(byte *)(iVar7 + 0x34) << 1;
    *(byte *)(iVar7 + 0x49) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x3a) >> 7) | *(byte *)(iVar7 + 0x39) << 1;
    *(byte *)(iVar7 + 0x47) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x38) >> 7) | *(byte *)(iVar7 + 0x37) << 1;
    *(byte *)(iVar7 + 0x46) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x37) >> 7) | *(byte *)(iVar7 + 0x36) << 1;
    *(byte *)(iVar7 + 0x45) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x36) >> 7) | *(byte *)(iVar7 + 0x35) << 1;
    *(byte *)(iVar7 + 0x43) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x34) >> 7) | *(byte *)(iVar7 + 0x33) << 1;
    *(byte *)(iVar7 + 0x42) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x33) >> 7) | *(byte *)(iVar7 + 0x32) << 1;
    *(byte *)(iVar7 + 0x41) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x32) >> 7) | *(byte *)(iVar7 + 0x31) << 1;
    *(byte *)(iVar7 + 0x4f) = *(char *)(iVar7 + 0x30) >> 7 & 0x87U ^ *(byte *)(iVar7 + 0x3f) << 1;
    *(byte *)(iVar7 + 0x40) =
         (byte)((int)(uint)*(byte *)(iVar7 + 0x31) >> 7) | *(char *)(iVar7 + 0x30) << 1;
    param_1[5] = 4;
    return 1;
  }
  ERR_put_error(0xf,0x7a,0x41,"crypto/modes/ocb128.c",0x9f);
  return 0;
}

