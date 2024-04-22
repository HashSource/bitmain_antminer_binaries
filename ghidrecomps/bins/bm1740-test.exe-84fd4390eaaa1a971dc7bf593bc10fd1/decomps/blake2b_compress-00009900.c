
undefined4 blake2b_compress(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined8 uVar12;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  uint auStack_90 [33];
  int local_c;
  
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    uVar12 = load64(param_2 + local_c * 8);
    iVar1 = local_c;
    auStack_90[local_c * 2] = (uint)uVar12;
    auStack_90[iVar1 * 2 + 1] = (uint)((ulonglong)uVar12 >> 0x20);
  }
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    puVar4 = (undefined4 *)(param_1 + local_c * 8);
    uVar5 = puVar4[1];
    *(undefined4 *)(&local_110 + local_c) = *puVar4;
    *(undefined4 *)((int)&local_110 + local_c * 8 + 4) = uVar5;
  }
  local_d0._0_4_ = blake2b_IV;
  local_d0._4_4_ = DAT_0002ba9c;
  local_c8._0_4_ = DAT_0002baa0;
  local_c8._4_4_ = DAT_0002baa4;
  local_c0._0_4_ = DAT_0002baa8;
  local_c0._4_4_ = DAT_0002baac;
  local_b8._0_4_ = DAT_0002bab0;
  local_b8._4_4_ = DAT_0002bab4;
  local_b0._0_4_ = DAT_0002bab8 ^ *(uint *)(param_1 + 0x40);
  local_b0._4_4_ = DAT_0002babc ^ *(uint *)(param_1 + 0x44);
  local_a8._0_4_ = DAT_0002bac0 ^ *(uint *)(param_1 + 0x48);
  local_a8._4_4_ = DAT_0002bac4 ^ *(uint *)(param_1 + 0x4c);
  local_a0._0_4_ = DAT_0002bac8 ^ *(uint *)(param_1 + 0x50);
  local_a0._4_4_ = DAT_0002bacc ^ *(uint *)(param_1 + 0x54);
  local_98._0_4_ = DAT_0002bad0 ^ *(uint *)(param_1 + 0x58);
  local_98._4_4_ = DAT_0002bad4 ^ *(uint *)(param_1 + 0x5c);
  bVar9 = CARRY4((uint)local_110,(uint)local_f0);
  uVar2 = (uint)local_110 + (uint)local_f0;
  local_110._0_4_ = auStack_90[(uint)blake2b_sigma[0] * 2] + uVar2;
  local_110._4_4_ =
       auStack_90[(uint)blake2b_sigma[0] * 2 + 1] +
       local_110._4_4_ + local_f0._4_4_ + bVar9 +
       (uint)CARRY4(auStack_90[(uint)blake2b_sigma[0] * 2],uVar2);
  local_b0 = rotr64((uint)local_110 ^ (uint)local_b0,local_110._4_4_ ^ local_b0._4_4_,0x20);
  local_d0 = local_b0 + CONCAT44(local_d0._4_4_,(undefined4)local_d0);
  uVar10 = rotr64((uint)local_d0 ^ (uint)local_f0,(uint)(local_d0 >> 0x20) ^ local_f0._4_4_,0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = uVar10 + CONCAT44(local_110._4_4_,(uint)local_110) +
              CONCAT44(auStack_90[(uint)blake2b_sigma[1] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[1] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_110 ^ local_b0),(int)((local_110 ^ local_b0) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_d0 ^ local_f0),(int)((local_d0 ^ local_f0) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  bVar9 = CARRY4((uint)local_108,(uint)local_e8);
  uVar2 = (uint)local_108 + (uint)local_e8;
  local_108._0_4_ = auStack_90[(uint)blake2b_sigma[2] * 2] + uVar2;
  local_108._4_4_ =
       auStack_90[(uint)blake2b_sigma[2] * 2 + 1] +
       local_108._4_4_ + local_e8._4_4_ + bVar9 +
       (uint)CARRY4(auStack_90[(uint)blake2b_sigma[2] * 2],uVar2);
  local_f0 = uVar10;
  local_a8 = rotr64((uint)local_108 ^ (uint)local_a8,local_108._4_4_ ^ local_a8._4_4_,0x20);
  local_c8 = local_a8 + CONCAT44(local_c8._4_4_,(undefined4)local_c8);
  uVar10 = rotr64((uint)local_c8 ^ (uint)local_e8,(uint)(local_c8 >> 0x20) ^ local_e8._4_4_,0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = uVar10 + CONCAT44(local_108._4_4_,(uint)local_108) +
              CONCAT44(auStack_90[(uint)blake2b_sigma[3] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[3] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_108 ^ local_a8),(int)((local_108 ^ local_a8) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_c8 ^ local_e8),(int)((local_c8 ^ local_e8) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  bVar9 = CARRY4((uint)local_100,(uint)local_e0);
  uVar2 = (uint)local_100 + (uint)local_e0;
  local_100._0_4_ = auStack_90[(uint)blake2b_sigma[4] * 2] + uVar2;
  local_100._4_4_ =
       auStack_90[(uint)blake2b_sigma[4] * 2 + 1] +
       local_100._4_4_ + local_e0._4_4_ + bVar9 +
       (uint)CARRY4(auStack_90[(uint)blake2b_sigma[4] * 2],uVar2);
  local_e8 = uVar10;
  local_a0 = rotr64((uint)local_100 ^ (uint)local_a0,local_100._4_4_ ^ local_a0._4_4_,0x20);
  local_c0 = local_a0 + CONCAT44(local_c0._4_4_,(undefined4)local_c0);
  uVar10 = rotr64((uint)local_c0 ^ (uint)local_e0,(uint)(local_c0 >> 0x20) ^ local_e0._4_4_,0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = uVar10 + CONCAT44(local_100._4_4_,(uint)local_100) +
              CONCAT44(auStack_90[(uint)blake2b_sigma[5] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[5] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_100 ^ local_a0),(int)((local_100 ^ local_a0) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_c0 ^ local_e0),(int)((local_c0 ^ local_e0) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  bVar9 = CARRY4((uint)local_f8,(uint)local_d8);
  uVar2 = (uint)local_f8 + (uint)local_d8;
  local_f8._0_4_ = auStack_90[(uint)blake2b_sigma[6] * 2] + uVar2;
  local_f8._4_4_ =
       auStack_90[(uint)blake2b_sigma[6] * 2 + 1] +
       local_f8._4_4_ + local_d8._4_4_ + bVar9 +
       (uint)CARRY4(auStack_90[(uint)blake2b_sigma[6] * 2],uVar2);
  local_e0 = uVar10;
  local_98 = rotr64((uint)local_f8 ^ (uint)local_98,local_f8._4_4_ ^ local_98._4_4_,0x20);
  local_b8 = local_98 + CONCAT44(local_b8._4_4_,(undefined4)local_b8);
  uVar10 = rotr64((uint)local_b8 ^ (uint)local_d8,(uint)(local_b8 >> 0x20) ^ local_d8._4_4_,0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = uVar10 + CONCAT44(local_f8._4_4_,(uint)local_f8) +
             CONCAT44(auStack_90[(uint)blake2b_sigma[7] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[7] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_f8 ^ local_98),(int)((local_f8 ^ local_98) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_b8 ^ local_d8),(int)((local_b8 ^ local_d8) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[8] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[8] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[9] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[9] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[10] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[10] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[11] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[11] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_d8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[12] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[12] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[13] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[13] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_f0 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[14] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[14] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[15] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[15] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[16] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[16] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[17] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[17] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[18] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[18] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[19] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[19] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[20] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[20] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[21] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[21] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_d8 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[22] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[22] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[23] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[23] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[24] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[24] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[25] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[25] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[26] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[26] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[27] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[27] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_d8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[28] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[28] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[29] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[29] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_f0 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[30] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[30] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[31] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[31] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[32] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[32] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[33] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[33] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[34] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[34] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[35] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[35] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[36] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[36] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[37] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[37] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_d8 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[38] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[38] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[39] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[39] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[40] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[40] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[41] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[41] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[42] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[42] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[43] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[43] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_d8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[44] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[44] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[45] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[45] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_f0 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[46] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[46] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[47] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[47] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[48] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[48] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[49] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[49] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[50] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[50] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[51] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[51] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[52] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[52] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[53] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[53] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_d8 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[54] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[54] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[55] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[55] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[56] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[56] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[57] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[57] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[58] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[58] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[59] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[59] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_d8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[60] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[60] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[61] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[61] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_f0 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[62] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[62] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[63] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[63] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[64] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[64] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[65] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[65] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[66] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[66] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[67] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[67] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[68] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[68] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[69] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[69] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_d8 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[70] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[70] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[71] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[71] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[72] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[72] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[73] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[73] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[74] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[74] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[75] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[75] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_d8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[76] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[76] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[77] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[77] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_f0 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[78] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[78] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[79] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[79] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[80] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[80] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[81] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[81] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[82] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[82] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[83] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[83] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[84] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[84] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[85] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[85] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_d8 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[86] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[86] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[87] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[87] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[88] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[88] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[89] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[89] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[90] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[90] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[91] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[91] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_d8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[92] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[92] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[93] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[93] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_f0 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[94] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[94] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[95] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[95] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[96] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[96] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[97] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[97] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[98] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[98] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[99] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[99] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[100] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[100] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[101] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[101] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_d8 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[102] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[102] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[103] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[103] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[104] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[104] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[105] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[105] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[106] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[106] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[107] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[107] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_d8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[108] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[108] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[109] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[109] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_f0 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[110] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[110] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[111] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[111] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[112] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[112] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[113] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[113] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[114] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[114] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[115] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[115] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[116] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[116] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[117] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[117] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_d8 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[118] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[118] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[119] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[119] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[120] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[120] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[121] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[121] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[122] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[122] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[123] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[123] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_d8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[124] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[124] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[125] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[125] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_f0 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[126] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[126] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[127] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[127] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[128] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[128] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[129] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[129] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[130] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[130] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[131] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[131] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[132] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[132] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[133] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[133] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_d8 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[134] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[134] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[135] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[135] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[136] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[136] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[137] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[137] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[138] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[138] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[139] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[139] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_d8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[140] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[140] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[141] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[141] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_f0 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[142] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[142] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[143] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[143] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[144] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[144] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[145] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[145] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[146] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[146] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[147] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[147] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[148] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[148] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[149] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[149] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_d8 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[150] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[150] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[151] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[151] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[152] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[152] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[153] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[153] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[154] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[154] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[155] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[155] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_d8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[156] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[156] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[157] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[157] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_f0 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[158] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[158] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[159] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[159] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[160] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[160] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[161] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[161] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[162] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[162] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[163] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[163] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[164] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[164] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[165] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[165] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_d8 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[166] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[166] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[167] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[167] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[168] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[168] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[169] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[169] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[170] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[170] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[171] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[171] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_d8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[172] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[172] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[173] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[173] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_f0 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[174] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[174] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[175] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[175] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[176] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[176] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[177] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[177] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_b0 ^ local_110),(int)((local_b0 ^ local_110) >> 0x20),0x10);
  local_d0 = local_d0 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_d0),(int)((local_f0 ^ local_d0) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[178] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[178] * 2]);
  local_f0 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[179] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[179] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a8 ^ local_108),(int)((local_a8 ^ local_108) >> 0x20),0x10);
  local_c8 = local_c8 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c8),(int)((local_e8 ^ local_c8) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[180] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[180] * 2]);
  local_e8 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[181] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[181] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_a0 ^ local_100),(int)((local_a0 ^ local_100) >> 0x20),0x10);
  local_c0 = local_c0 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_c0),(int)((local_e0 ^ local_c0) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + local_d8 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[182] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[182] * 2]);
  local_e0 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[183] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[183] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_f8),(int)((local_98 ^ local_f8) >> 0x20),0x10);
  local_b8 = local_b8 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_b8),(int)((local_d8 ^ local_b8) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + local_e8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[184] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[184] * 2]);
  local_d8 = uVar10;
  uVar10 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x20);
  local_c0 = local_c0 + uVar10;
  local_98 = uVar10;
  uVar10 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x18);
  local_e8._0_4_ = (int)uVar10;
  local_e8._4_4_ = (int)(uVar10 >> 0x20);
  local_110 = local_110 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[185] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[185] * 2]);
  local_e8 = uVar10;
  lVar11 = rotr64((int)(local_98 ^ local_110),(int)((local_98 ^ local_110) >> 0x20),0x10);
  local_c0 = local_c0 + lVar11;
  local_98 = lVar11;
  uVar12 = rotr64((int)(local_e8 ^ local_c0),(int)((local_e8 ^ local_c0) >> 0x20),0x3f);
  local_e8._0_4_ = (int)uVar12;
  local_e8._4_4_ = (int)((ulonglong)uVar12 >> 0x20);
  local_108 = local_108 + local_e0 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[186] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[186] * 2]);
  local_e8 = uVar12;
  uVar10 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x20);
  local_b8 = local_b8 + uVar10;
  local_b0 = uVar10;
  uVar10 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x18);
  local_e0._0_4_ = (int)uVar10;
  local_e0._4_4_ = (int)(uVar10 >> 0x20);
  local_108 = local_108 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[187] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[187] * 2]);
  local_e0 = uVar10;
  lVar11 = rotr64((int)(local_b0 ^ local_108),(int)((local_b0 ^ local_108) >> 0x20),0x10);
  local_b8 = local_b8 + lVar11;
  local_b0 = lVar11;
  uVar12 = rotr64((int)(local_e0 ^ local_b8),(int)((local_e0 ^ local_b8) >> 0x20),0x3f);
  local_e0._0_4_ = (int)uVar12;
  local_e0._4_4_ = (int)((ulonglong)uVar12 >> 0x20);
  local_100 = local_100 + local_d8 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[188] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[188] * 2]);
  local_e0 = uVar12;
  uVar10 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x20);
  local_d0 = local_d0 + uVar10;
  local_a8 = uVar10;
  uVar10 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x18);
  local_d8._0_4_ = (int)uVar10;
  local_d8._4_4_ = (int)(uVar10 >> 0x20);
  local_100 = local_100 + uVar10 +
              CONCAT44(auStack_90[(uint)blake2b_sigma[189] * 2 + 1],
                       auStack_90[(uint)blake2b_sigma[189] * 2]);
  local_d8 = uVar10;
  lVar11 = rotr64((int)(local_a8 ^ local_100),(int)((local_a8 ^ local_100) >> 0x20),0x10);
  local_d0 = local_d0 + lVar11;
  local_a8 = lVar11;
  uVar12 = rotr64((int)(local_d8 ^ local_d0),(int)((local_d8 ^ local_d0) >> 0x20),0x3f);
  local_d8._0_4_ = (int)uVar12;
  local_d8._4_4_ = (int)((ulonglong)uVar12 >> 0x20);
  local_f8 = local_f8 + local_f0 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[190] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[190] * 2]);
  local_d8 = uVar12;
  uVar10 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x20);
  local_c8 = local_c8 + uVar10;
  local_a0 = uVar10;
  uVar10 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x18);
  local_f0._0_4_ = (int)uVar10;
  local_f0._4_4_ = (int)(uVar10 >> 0x20);
  local_f8 = local_f8 + uVar10 +
             CONCAT44(auStack_90[(uint)blake2b_sigma[191] * 2 + 1],
                      auStack_90[(uint)blake2b_sigma[191] * 2]);
  local_f0 = uVar10;
  lVar11 = rotr64((int)(local_a0 ^ local_f8),(int)((local_a0 ^ local_f8) >> 0x20),0x10);
  local_c8 = local_c8 + lVar11;
  local_a0 = lVar11;
  uVar12 = rotr64((int)(local_f0 ^ local_c8),(int)((local_f0 ^ local_c8) >> 0x20),0x3f);
  local_f0._0_4_ = (int)uVar12;
  local_f0._4_4_ = (int)((ulonglong)uVar12 >> 0x20);
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    puVar6 = (uint *)(param_1 + local_c * 8);
    uVar2 = puVar6[1];
    uVar7 = *(uint *)((int)&local_110 + local_c * 8 + 4);
    uVar8 = *(uint *)((int)&local_110 + (local_c + 8) * 8 + 4);
    puVar3 = (uint *)(param_1 + local_c * 8);
    *puVar3 = *(uint *)(&local_110 + local_c + 8) ^ *puVar6 ^ *(uint *)(&local_110 + local_c);
    puVar3[1] = uVar8 ^ uVar2 ^ uVar7;
  }
  return 0;
}

