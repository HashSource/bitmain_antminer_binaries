
void blake64(int param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  undefined8 uVar6;
  uint local_1b4;
  void *local_1b0;
  undefined8 local_1a8;
  undefined8 local_1a0;
  undefined8 local_198;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined8 local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  uint local_128;
  uint uStack_124;
  uint local_120;
  uint uStack_11c;
  uint local_118;
  uint uStack_114;
  uint local_110;
  uint uStack_10c;
  int local_108;
  uint local_104;
  uint local_100;
  uint uStack_fc;
  uint local_f8;
  uint uStack_f4;
  uint local_f0;
  uint uStack_ec;
  uint local_e8;
  uint uStack_e4;
  uint local_e0;
  uint uStack_dc;
  uint local_d8;
  uint uStack_d4;
  uint local_d0;
  uint uStack_cc;
  uint local_c8;
  uint uStack_c4;
  uint local_c0;
  uint uStack_bc;
  uint local_b8;
  uint uStack_b4;
  uint local_b0;
  uint uStack_ac;
  uint local_a8;
  uint uStack_a4;
  uint local_a0;
  uint uStack_9c;
  uint local_98;
  uint uStack_94;
  uint local_90;
  uint uStack_8c;
  uint local_88;
  uint uStack_84;
  uint local_7c;
  uint local_78;
  uint uStack_74;
  uint local_70;
  uint uStack_6c;
  uint local_68;
  uint uStack_64;
  uint local_60;
  uint uStack_5c;
  uint local_58;
  uint uStack_54;
  uint local_50;
  uint uStack_4c;
  uint local_48;
  uint uStack_44;
  uint local_40;
  uint uStack_3c;
  uint local_38;
  uint uStack_34;
  uint local_30;
  uint uStack_2c;
  int local_24;
  
  local_24 = *(int *)(param_1 + 0x80);
  local_108 = param_1;
  if (param_3 < 0x80U - local_24) {
    memcpy((void *)(param_1 + local_24),param_2,param_3);
    *(uint *)(param_1 + 0x80) = local_24 + param_3;
  }
  else {
    local_30 = *(uint *)(param_1 + 0x88);
    uStack_2c = *(uint *)(param_1 + 0x8c);
    local_38 = *(uint *)(param_1 + 0x90);
    uStack_34 = *(uint *)(param_1 + 0x94);
    local_40 = *(uint *)(param_1 + 0x98);
    uStack_3c = *(uint *)(param_1 + 0x9c);
    local_48 = *(uint *)(param_1 + 0xa0);
    uStack_44 = *(uint *)(param_1 + 0xa4);
    local_50 = *(uint *)(param_1 + 0xa8);
    uStack_4c = *(uint *)(param_1 + 0xac);
    local_58 = *(uint *)(param_1 + 0xb0);
    uStack_54 = *(uint *)(param_1 + 0xb4);
    local_60 = *(uint *)(param_1 + 0xb8);
    uStack_5c = *(uint *)(param_1 + 0xbc);
    local_68 = *(uint *)(param_1 + 0xc0);
    uStack_64 = *(uint *)(param_1 + 0xc4);
    local_110 = *(uint *)(param_1 + 200);
    uStack_10c = *(uint *)(param_1 + 0xcc);
    local_118 = *(uint *)(param_1 + 0xd0);
    uStack_114 = *(uint *)(param_1 + 0xd4);
    local_120 = *(uint *)(param_1 + 0xd8);
    uStack_11c = *(uint *)(param_1 + 0xdc);
    local_128 = *(uint *)(param_1 + 0xe0);
    uStack_124 = *(uint *)(param_1 + 0xe4);
    local_70 = *(uint *)(param_1 + 0xe8);
    uStack_6c = *(uint *)(param_1 + 0xec);
    local_78 = *(uint *)(param_1 + 0xf0);
    uStack_74 = *(uint *)(param_1 + 0xf4);
    local_1b4 = param_3;
    local_1b0 = param_2;
    uVar6 = CONCAT44(local_130._4_4_,(undefined4)local_130);
    while (local_1b4 != 0) {
      local_7c = 0x80 - local_24;
      if (local_1b4 < local_7c) {
        local_7c = local_1b4;
      }
      local_130 = uVar6;
      memcpy((void *)(local_108 + local_24),local_1b0,local_7c);
      local_24 = local_24 + local_7c;
      local_1b0 = (void *)((int)local_1b0 + local_7c);
      local_1b4 = local_1b4 - local_7c;
      uVar6 = local_130;
      if (local_24 == 0x80) {
        bVar5 = 0xfffffbff < local_70;
        local_70 = local_70 + 0x400;
        uStack_6c = uStack_6c + bVar5;
        bVar5 = uStack_6c == 0;
        if (uStack_6c == 0) {
          bVar5 = local_70 < 0x400;
        }
        if (bVar5) {
          bVar5 = 0xfffffffe < local_78;
          local_78 = local_78 + 1;
          uStack_74 = uStack_74 + bVar5;
        }
        local_88 = local_30;
        uStack_84 = uStack_2c;
        local_90 = local_38;
        uStack_8c = uStack_34;
        local_98 = local_40;
        uStack_94 = uStack_3c;
        local_a0 = local_48;
        uStack_9c = uStack_44;
        local_a8 = local_50;
        uStack_a4 = uStack_4c;
        local_b0 = local_58;
        uStack_ac = uStack_54;
        local_b8 = local_60;
        uStack_b4 = uStack_5c;
        local_c0 = local_68;
        uStack_bc = uStack_64;
        local_c8 = DAT_0001a3e0 ^ local_110;
        uStack_c4 = DAT_0001a3e4 ^ uStack_10c;
        local_d0 = DAT_0001a3e8 ^ local_118;
        uStack_cc = DAT_0001a3ec ^ uStack_114;
        local_d8 = DAT_0001a3f0 ^ local_120;
        uStack_d4 = DAT_0001a3f4 ^ uStack_11c;
        local_e0 = DAT_0001a3f8 ^ local_128;
        uStack_dc = DAT_0001a3fc ^ uStack_124;
        local_e8 = DAT_0001a400 ^ local_70;
        uStack_e4 = DAT_0001a404 ^ uStack_6c;
        local_f0 = DAT_0001a408 ^ local_70;
        uStack_ec = DAT_0001a40c ^ uStack_6c;
        local_f8 = DAT_0001a410 ^ local_78;
        uStack_f4 = DAT_0001a414 ^ uStack_74;
        local_100 = DAT_0001a418 ^ local_78;
        uStack_fc = DAT_0001a41c ^ uStack_74;
        uVar6 = sph_dec64be_aligned(local_108);
        local_1a8 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 8);
        local_1a0 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 0x10);
        local_198 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 0x18);
        local_190 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 0x20);
        local_188 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 0x28);
        local_180 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 0x30);
        local_178 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 0x38);
        local_170 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 0x40);
        local_168 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 0x48);
        local_160 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 0x50);
        local_158 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 0x58);
        local_150 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 0x60);
        local_148 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 0x68);
        local_140 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 0x70);
        local_138 = uVar6;
        uVar6 = sph_dec64be_aligned(local_108 + 0x78);
        local_130._0_4_ = (int)uVar6;
        local_130._4_4_ = (int)((ulonglong)uVar6 >> 0x20);
        for (local_104 = 0; local_104 < 0x10; local_104 = local_104 + 1) {
          uVar2 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 4) * 8) ^
                  *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40))) + local_88 + local_a8;
          uStack_84 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 4) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40) * 8 + 4)) +
                      uStack_84 + uStack_a4 + CARRY4(local_88,local_a8) +
                      (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 4) * 8) ^
                                   *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40)),
                                   local_88 + local_a8);
          local_88 = uVar2;
          uVar3 = uVar2 ^ local_e8;
          local_e8 = uStack_84 ^ uStack_e4;
          uStack_e4 = uVar3;
          uVar4 = local_e8 + local_c8;
          uStack_c4 = uVar3 + uStack_c4 + CARRY4(local_e8,local_c8);
          local_c8 = uVar4;
          uVar1 = (uStack_c4 ^ uStack_a4) >> 0x19 | (uVar4 ^ local_a8) << 7;
          local_a8 = (uVar4 ^ local_a8) >> 0x19 | (uStack_c4 ^ uStack_a4) << 7;
          uStack_a4 = uVar1;
          local_88 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40) * 8) ^
                     *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 4))) +
                     uVar2 + local_a8;
          uStack_84 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 4) * 8 + 4)) +
                      uStack_84 + uVar1 + CARRY4(uVar2,local_a8) +
                      (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40) * 8) ^
                                   *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 4)),
                                   uVar2 + local_a8);
          uStack_e4 = (uStack_84 ^ uVar3) >> 0x10 | (local_88 ^ local_e8) << 0x10;
          local_e8 = (local_88 ^ local_e8) >> 0x10 | (uStack_84 ^ uVar3) << 0x10;
          local_c8 = local_e8 + uVar4;
          uStack_c4 = uStack_e4 + uStack_c4 + CARRY4(local_e8,uVar4);
          uStack_a4 = (uStack_c4 ^ uVar1) >> 0xb | (local_c8 ^ local_a8) << 0x15;
          local_a8 = (local_c8 ^ local_a8) >> 0xb | (uStack_c4 ^ uVar1) << 0x15;
          uVar2 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0xc) * 8) ^
                  *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 8))) +
                  local_90 + local_b0;
          uStack_8c = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0xc) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 8) * 8 + 4)) +
                      uStack_8c + uStack_ac + CARRY4(local_90,local_b0) +
                      (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0xc) * 8) ^
                                   *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 8)),
                                   local_90 + local_b0);
          local_90 = uVar2;
          uVar3 = uVar2 ^ local_f0;
          local_f0 = uStack_8c ^ uStack_ec;
          uStack_ec = uVar3;
          uVar4 = local_f0 + local_d0;
          uStack_cc = uVar3 + uStack_cc + CARRY4(local_f0,local_d0);
          local_d0 = uVar4;
          uVar1 = (uStack_cc ^ uStack_ac) >> 0x19 | (uVar4 ^ local_b0) << 7;
          local_b0 = (uVar4 ^ local_b0) >> 0x19 | (uStack_cc ^ uStack_ac) << 7;
          uStack_ac = uVar1;
          local_90 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 8) * 8) ^
                     *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0xc))) +
                     uVar2 + local_b0;
          uStack_8c = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 8) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0xc) * 8 + 4))
                      + uStack_8c + uVar1 + CARRY4(uVar2,local_b0) +
                        (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 8) * 8) ^
                                     *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0xc)
                                              ),uVar2 + local_b0);
          uStack_ec = (uStack_8c ^ uVar3) >> 0x10 | (local_90 ^ local_f0) << 0x10;
          local_f0 = (local_90 ^ local_f0) >> 0x10 | (uStack_8c ^ uVar3) << 0x10;
          local_d0 = local_f0 + uVar4;
          uStack_cc = uStack_ec + uStack_cc + CARRY4(local_f0,uVar4);
          uStack_ac = (uStack_cc ^ uVar1) >> 0xb | (local_d0 ^ local_b0) << 0x15;
          local_b0 = (local_d0 ^ local_b0) >> 0xb | (uStack_cc ^ uVar1) << 0x15;
          uVar2 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x14) * 8) ^
                  *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x10))) +
                  local_98 + local_b8;
          uStack_94 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x14) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x10) * 8 + 4)
                      ) + uStack_94 + uStack_b4 + CARRY4(local_98,local_b8) +
                          (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x14) * 8)
                                       ^ *(uint *)(&local_1a8 +
                                                  *(int *)(sigma + local_104 * 0x40 + 0x10)),
                                       local_98 + local_b8);
          local_98 = uVar2;
          uVar3 = uVar2 ^ local_f8;
          local_f8 = uStack_94 ^ uStack_f4;
          uStack_f4 = uVar3;
          uVar4 = local_f8 + local_d8;
          uStack_d4 = uVar3 + uStack_d4 + CARRY4(local_f8,local_d8);
          local_d8 = uVar4;
          uVar1 = (uStack_d4 ^ uStack_b4) >> 0x19 | (uVar4 ^ local_b8) << 7;
          local_b8 = (uVar4 ^ local_b8) >> 0x19 | (uStack_d4 ^ uStack_b4) << 7;
          uStack_b4 = uVar1;
          local_98 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x10) * 8) ^
                     *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x14))) +
                     uVar2 + local_b8;
          uStack_94 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x10) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x14) * 8 + 4)
                      ) + uStack_94 + uVar1 + CARRY4(uVar2,local_b8) +
                          (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x10) * 8)
                                       ^ *(uint *)(&local_1a8 +
                                                  *(int *)(sigma + local_104 * 0x40 + 0x14)),
                                       uVar2 + local_b8);
          uStack_f4 = (uStack_94 ^ uVar3) >> 0x10 | (local_98 ^ local_f8) << 0x10;
          local_f8 = (local_98 ^ local_f8) >> 0x10 | (uStack_94 ^ uVar3) << 0x10;
          local_d8 = local_f8 + uVar4;
          uStack_d4 = uStack_f4 + uStack_d4 + CARRY4(local_f8,uVar4);
          uStack_b4 = (uStack_d4 ^ uVar1) >> 0xb | (local_d8 ^ local_b8) << 0x15;
          local_b8 = (local_d8 ^ local_b8) >> 0xb | (uStack_d4 ^ uVar1) << 0x15;
          uVar2 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x1c) * 8) ^
                  *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x18))) +
                  local_a0 + local_c0;
          uStack_9c = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x1c) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x18) * 8 + 4)
                      ) + uStack_9c + uStack_bc + CARRY4(local_a0,local_c0) +
                          (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x1c) * 8)
                                       ^ *(uint *)(&local_1a8 +
                                                  *(int *)(sigma + local_104 * 0x40 + 0x18)),
                                       local_a0 + local_c0);
          local_a0 = uVar2;
          uVar3 = uVar2 ^ local_100;
          local_100 = uStack_9c ^ uStack_fc;
          uStack_fc = uVar3;
          uVar4 = local_100 + local_e0;
          uStack_dc = uVar3 + uStack_dc + CARRY4(local_100,local_e0);
          local_e0 = uVar4;
          uVar1 = (uStack_dc ^ uStack_bc) >> 0x19 | (uVar4 ^ local_c0) << 7;
          local_c0 = (uVar4 ^ local_c0) >> 0x19 | (uStack_dc ^ uStack_bc) << 7;
          uStack_bc = uVar1;
          local_a0 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x18) * 8) ^
                     *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x1c))) +
                     uVar2 + local_c0;
          uStack_9c = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x18) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x1c) * 8 + 4)
                      ) + uStack_9c + uVar1 + CARRY4(uVar2,local_c0) +
                          (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x18) * 8)
                                       ^ *(uint *)(&local_1a8 +
                                                  *(int *)(sigma + local_104 * 0x40 + 0x1c)),
                                       uVar2 + local_c0);
          uStack_fc = (uStack_9c ^ uVar3) >> 0x10 | (local_a0 ^ local_100) << 0x10;
          local_100 = (local_a0 ^ local_100) >> 0x10 | (uStack_9c ^ uVar3) << 0x10;
          local_e0 = local_100 + uVar4;
          uStack_dc = uStack_fc + uStack_dc + CARRY4(local_100,uVar4);
          uStack_bc = (uStack_dc ^ uVar1) >> 0xb | (local_e0 ^ local_c0) << 0x15;
          local_c0 = (local_e0 ^ local_c0) >> 0xb | (uStack_dc ^ uVar1) << 0x15;
          uVar2 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x24) * 8) ^
                  *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x20))) +
                  local_88 + local_b0;
          uStack_84 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x24) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x20) * 8 + 4)
                      ) + uStack_84 + uStack_ac + CARRY4(local_88,local_b0) +
                          (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x24) * 8)
                                       ^ *(uint *)(&local_1a8 +
                                                  *(int *)(sigma + local_104 * 0x40 + 0x20)),
                                       local_88 + local_b0);
          local_88 = uVar2;
          uVar3 = uVar2 ^ local_100;
          local_100 = uStack_84 ^ uStack_fc;
          uStack_fc = uVar3;
          uVar4 = local_100 + local_d8;
          uStack_d4 = uVar3 + uStack_d4 + CARRY4(local_100,local_d8);
          local_d8 = uVar4;
          uVar1 = (uStack_d4 ^ uStack_ac) >> 0x19 | (uVar4 ^ local_b0) << 7;
          local_b0 = (uVar4 ^ local_b0) >> 0x19 | (uStack_d4 ^ uStack_ac) << 7;
          uStack_ac = uVar1;
          local_88 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x20) * 8) ^
                     *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x24))) +
                     uVar2 + local_b0;
          uStack_84 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x20) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x24) * 8 + 4)
                      ) + uStack_84 + uVar1 + CARRY4(uVar2,local_b0) +
                          (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x20) * 8)
                                       ^ *(uint *)(&local_1a8 +
                                                  *(int *)(sigma + local_104 * 0x40 + 0x24)),
                                       uVar2 + local_b0);
          local_100 = local_88 ^ local_100;
          uVar3 = uStack_84 ^ uVar3;
          uStack_fc = uVar3 >> 0x10 | local_100 << 0x10;
          local_100 = local_100 >> 0x10 | uVar3 << 0x10;
          uStack_d4 = uStack_fc + uStack_d4 + CARRY4(local_100,uVar4);
          local_d8 = local_100 + uVar4;
          uVar2 = local_100 + uVar4 ^ local_b0;
          uVar1 = uStack_d4 ^ uVar1;
          local_b0 = uVar2 >> 0xb | uVar1 << 0x15;
          uStack_ac = uVar1 >> 0xb | uVar2 << 0x15;
          uVar2 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x2c) * 8) ^
                  *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x28))) +
                  local_90 + local_b8;
          uStack_8c = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x2c) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x28) * 8 + 4)
                      ) + uStack_8c + uStack_b4 + CARRY4(local_90,local_b8) +
                          (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x2c) * 8)
                                       ^ *(uint *)(&local_1a8 +
                                                  *(int *)(sigma + local_104 * 0x40 + 0x28)),
                                       local_90 + local_b8);
          local_90 = uVar2;
          uVar3 = uVar2 ^ local_e8;
          local_e8 = uStack_8c ^ uStack_e4;
          uStack_e4 = uVar3;
          uVar4 = local_e8 + local_e0;
          uStack_dc = uVar3 + uStack_dc + CARRY4(local_e8,local_e0);
          local_e0 = uVar4;
          uVar1 = (uStack_dc ^ uStack_b4) >> 0x19 | (uVar4 ^ local_b8) << 7;
          local_b8 = (uVar4 ^ local_b8) >> 0x19 | (uStack_dc ^ uStack_b4) << 7;
          uStack_b4 = uVar1;
          local_90 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x28) * 8) ^
                     *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x2c))) +
                     uVar2 + local_b8;
          uStack_8c = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x28) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x2c) * 8 + 4)
                      ) + uStack_8c + uVar1 + CARRY4(uVar2,local_b8) +
                          (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x28) * 8)
                                       ^ *(uint *)(&local_1a8 +
                                                  *(int *)(sigma + local_104 * 0x40 + 0x2c)),
                                       uVar2 + local_b8);
          local_e8 = local_90 ^ local_e8;
          uVar3 = uStack_8c ^ uVar3;
          uStack_e4 = uVar3 >> 0x10 | local_e8 << 0x10;
          local_e8 = local_e8 >> 0x10 | uVar3 << 0x10;
          uStack_dc = uStack_e4 + uStack_dc + CARRY4(local_e8,uVar4);
          local_e0 = local_e8 + uVar4;
          uVar2 = local_e8 + uVar4 ^ local_b8;
          uVar1 = uStack_dc ^ uVar1;
          local_b8 = uVar2 >> 0xb | uVar1 << 0x15;
          uStack_b4 = uVar1 >> 0xb | uVar2 << 0x15;
          uVar2 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x34) * 8) ^
                  *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x30))) +
                  local_98 + local_c0;
          uStack_94 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x34) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x30) * 8 + 4)
                      ) + uStack_94 + uStack_bc + CARRY4(local_98,local_c0) +
                          (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x34) * 8)
                                       ^ *(uint *)(&local_1a8 +
                                                  *(int *)(sigma + local_104 * 0x40 + 0x30)),
                                       local_98 + local_c0);
          local_98 = uVar2;
          uVar3 = uVar2 ^ local_f0;
          local_f0 = uStack_94 ^ uStack_ec;
          uStack_ec = uVar3;
          uVar4 = local_f0 + local_c8;
          uStack_c4 = uVar3 + uStack_c4 + CARRY4(local_f0,local_c8);
          local_c8 = uVar4;
          uVar1 = (uStack_c4 ^ uStack_bc) >> 0x19 | (uVar4 ^ local_c0) << 7;
          local_c0 = (uVar4 ^ local_c0) >> 0x19 | (uStack_c4 ^ uStack_bc) << 7;
          uStack_bc = uVar1;
          local_98 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x30) * 8) ^
                     *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x34))) +
                     uVar2 + local_c0;
          uStack_94 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x30) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x34) * 8 + 4)
                      ) + uStack_94 + uVar1 + CARRY4(uVar2,local_c0) +
                          (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x30) * 8)
                                       ^ *(uint *)(&local_1a8 +
                                                  *(int *)(sigma + local_104 * 0x40 + 0x34)),
                                       uVar2 + local_c0);
          local_f0 = local_98 ^ local_f0;
          uVar3 = uStack_94 ^ uVar3;
          uStack_ec = uVar3 >> 0x10 | local_f0 << 0x10;
          local_f0 = local_f0 >> 0x10 | uVar3 << 0x10;
          uStack_c4 = uStack_ec + uStack_c4 + CARRY4(local_f0,uVar4);
          local_c8 = local_f0 + uVar4;
          uVar2 = local_f0 + uVar4 ^ local_c0;
          uVar1 = uStack_c4 ^ uVar1;
          local_c0 = uVar2 >> 0xb | uVar1 << 0x15;
          uStack_bc = uVar1 >> 0xb | uVar2 << 0x15;
          uVar2 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x3c) * 8) ^
                  *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x38))) +
                  local_a0 + local_a8;
          uStack_9c = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x3c) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x38) * 8 + 4)
                      ) + uStack_9c + uStack_a4 + CARRY4(local_a0,local_a8) +
                          (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x3c) * 8)
                                       ^ *(uint *)(&local_1a8 +
                                                  *(int *)(sigma + local_104 * 0x40 + 0x38)),
                                       local_a0 + local_a8);
          local_a0 = uVar2;
          uVar3 = uVar2 ^ local_f8;
          local_f8 = uStack_9c ^ uStack_f4;
          uStack_f4 = uVar3;
          uVar4 = local_f8 + local_d0;
          uStack_cc = uVar3 + uStack_cc + CARRY4(local_f8,local_d0);
          local_d0 = uVar4;
          uVar1 = (uStack_cc ^ uStack_a4) >> 0x19 | (uVar4 ^ local_a8) << 7;
          local_a8 = (uVar4 ^ local_a8) >> 0x19 | (uStack_cc ^ uStack_a4) << 7;
          uStack_a4 = uVar1;
          local_a0 = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x38) * 8) ^
                     *(uint *)(&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x3c))) +
                     uVar2 + local_a8;
          uStack_9c = (*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x38) * 8 + 4) ^
                      *(uint *)((int)&local_1a8 + *(int *)(sigma + local_104 * 0x40 + 0x3c) * 8 + 4)
                      ) + uStack_9c + uVar1 + CARRY4(uVar2,local_a8) +
                          (uint)CARRY4(*(uint *)(CB + *(int *)(sigma + local_104 * 0x40 + 0x38) * 8)
                                       ^ *(uint *)(&local_1a8 +
                                                  *(int *)(sigma + local_104 * 0x40 + 0x3c)),
                                       uVar2 + local_a8);
          local_f8 = local_a0 ^ local_f8;
          uVar3 = uStack_9c ^ uVar3;
          uStack_f4 = local_f8 << 0x10 | uVar3 >> 0x10;
          local_f8 = uVar3 << 0x10 | local_f8 >> 0x10;
          uStack_cc = uStack_f4 + uStack_cc + CARRY4(local_f8,uVar4);
          local_d0 = local_f8 + uVar4;
          uVar2 = local_f8 + uVar4 ^ local_a8;
          uVar1 = uStack_cc ^ uVar1;
          local_a8 = uVar1 << 0x15 | uVar2 >> 0xb;
          uStack_a4 = uVar2 << 0x15 | uVar1 >> 0xb;
        }
        local_30 = local_30 ^ local_110 ^ local_88 ^ local_c8;
        uStack_2c = uStack_2c ^ uStack_10c ^ uStack_84 ^ uStack_c4;
        local_38 = local_38 ^ local_118 ^ local_90 ^ local_d0;
        uStack_34 = uStack_34 ^ uStack_114 ^ uStack_8c ^ uStack_cc;
        local_40 = local_40 ^ local_120 ^ local_98 ^ local_d8;
        uStack_3c = uStack_3c ^ uStack_11c ^ uStack_94 ^ uStack_d4;
        local_48 = local_48 ^ local_128 ^ local_a0 ^ local_e0;
        uStack_44 = uStack_44 ^ uStack_124 ^ uStack_9c ^ uStack_dc;
        local_50 = local_50 ^ local_110 ^ local_a8 ^ local_e8;
        uStack_4c = uStack_4c ^ uStack_10c ^ uStack_a4 ^ uStack_e4;
        local_58 = local_58 ^ local_118 ^ local_b0 ^ local_f0;
        uStack_54 = uStack_54 ^ uStack_114 ^ uStack_ac ^ uStack_ec;
        local_60 = local_60 ^ local_120 ^ local_b8 ^ local_f8;
        uStack_5c = uStack_5c ^ uStack_11c ^ uStack_b4 ^ uStack_f4;
        local_68 = local_68 ^ local_128 ^ local_c0 ^ local_100;
        uStack_64 = uStack_64 ^ uStack_124 ^ uStack_bc ^ uStack_fc;
        local_24 = 0;
      }
    }
    *(uint *)(param_1 + 0x88) = local_30;
    *(uint *)(param_1 + 0x8c) = uStack_2c;
    *(uint *)(param_1 + 0x90) = local_38;
    *(uint *)(param_1 + 0x94) = uStack_34;
    *(uint *)(param_1 + 0x98) = local_40;
    *(uint *)(param_1 + 0x9c) = uStack_3c;
    *(uint *)(param_1 + 0xa0) = local_48;
    *(uint *)(param_1 + 0xa4) = uStack_44;
    *(uint *)(param_1 + 0xa8) = local_50;
    *(uint *)(param_1 + 0xac) = uStack_4c;
    *(uint *)(param_1 + 0xb0) = local_58;
    *(uint *)(param_1 + 0xb4) = uStack_54;
    *(uint *)(param_1 + 0xb8) = local_60;
    *(uint *)(param_1 + 0xbc) = uStack_5c;
    *(uint *)(param_1 + 0xc0) = local_68;
    *(uint *)(param_1 + 0xc4) = uStack_64;
    *(uint *)(param_1 + 200) = local_110;
    *(uint *)(param_1 + 0xcc) = uStack_10c;
    *(uint *)(param_1 + 0xd0) = local_118;
    *(uint *)(param_1 + 0xd4) = uStack_114;
    *(uint *)(param_1 + 0xd8) = local_120;
    *(uint *)(param_1 + 0xdc) = uStack_11c;
    *(uint *)(param_1 + 0xe0) = local_128;
    *(uint *)(param_1 + 0xe4) = uStack_124;
    *(uint *)(param_1 + 0xe8) = local_70;
    *(uint *)(param_1 + 0xec) = uStack_6c;
    *(uint *)(param_1 + 0xf0) = local_78;
    *(uint *)(param_1 + 0xf4) = uStack_74;
    *(int *)(param_1 + 0x80) = local_24;
  }
  return;
}

