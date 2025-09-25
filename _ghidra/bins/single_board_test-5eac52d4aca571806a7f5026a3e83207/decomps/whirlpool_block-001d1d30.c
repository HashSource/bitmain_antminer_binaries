
void whirlpool_block(uint *param_1,uint *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  int iVar42;
  int iVar43;
  int iVar44;
  int iVar45;
  int iVar46;
  int iVar47;
  int iVar48;
  int iVar49;
  int iVar50;
  int iVar51;
  int iVar52;
  int iVar53;
  int iVar54;
  int iVar55;
  int iVar56;
  int iVar57;
  int iVar58;
  int iVar59;
  byte bVar60;
  uint uVar61;
  uint uVar62;
  uint uVar63;
  uint uVar64;
  uint uVar65;
  uint uVar66;
  uint uVar67;
  uint uVar68;
  uint uVar69;
  uint uVar70;
  uint uVar71;
  uint uVar72;
  uint uVar73;
  byte *pbVar74;
  uint uVar75;
  uint uVar76;
  uint uVar77;
  uint *puVar78;
  uint uVar79;
  uint *puVar80;
  uint uVar81;
  byte *pbVar82;
  uint *puVar83;
  uint uVar84;
  uint uVar85;
  uint *local_290;
  ushort local_288;
  ushort local_280;
  ushort local_278;
  ushort local_270;
  ushort local_268;
  ushort local_260;
  ushort local_258;
  ushort local_250;
  ushort local_248;
  ushort local_240;
  ushort local_238;
  ushort local_230;
  ushort local_228;
  ushort local_220;
  ushort local_218;
  ushort local_210;
  ushort local_208;
  ushort local_200;
  ushort local_1f8;
  ushort local_1f0;
  ushort local_1e8;
  ushort local_1e0;
  ushort local_1d8;
  ushort local_1d0;
  ushort local_1c8;
  ushort local_1c0;
  ushort local_1b8;
  ushort local_1b0;
  ushort local_1a8;
  ushort local_1a0;
  ushort local_198;
  ushort local_190;
  ushort local_188;
  ushort local_180;
  ushort local_174;
  ushort local_170;
  ushort local_168;
  uint *local_104;
  uint *local_f8;
  int local_f0;
  uint local_ec;
  uint *local_b0;
  byte bStack_a9;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_104 = param_2 + 0x10;
  local_ec = (uint)param_2 & 7;
  local_f8 = param_2;
  local_f0 = param_3;
  local_b0 = local_104;
  if (local_ec == 0) goto LAB_001d34ce;
  do {
    puVar80 = local_104 + -0x10;
    puVar83 = &local_a8;
    do {
      uVar77 = puVar80[3];
      puVar78 = puVar80 + 4;
      uVar75 = puVar80[1];
      uVar76 = puVar80[2];
      *puVar83 = *puVar80;
      puVar83[1] = uVar75;
      puVar83[2] = uVar76;
      puVar83[3] = uVar77;
      puVar80 = puVar78;
      puVar83 = puVar83 + 4;
    } while (puVar78 != local_104);
    local_68 = *param_1;
    local_64 = param_1[1];
    local_60 = param_1[2];
    local_5c = param_1[3];
    local_58 = param_1[4];
    local_54 = param_1[5];
    local_a4 = local_64 ^ local_a4;
    local_a8 = local_68 ^ local_a8;
    local_50 = param_1[6];
    local_4c = param_1[7];
    local_48 = param_1[8];
    local_44 = param_1[9];
    local_a0 = local_60 ^ local_a0;
    local_9c = local_5c ^ local_9c;
    local_98 = local_58 ^ local_98;
    local_94 = local_54 ^ local_94;
    local_90 = local_50 ^ local_90;
    local_8c = local_4c ^ local_8c;
    local_40 = param_1[10];
    local_3c = param_1[0xb];
    local_84 = local_44 ^ local_84;
    local_88 = local_48 ^ local_88;
    local_38 = param_1[0xc];
    local_34 = param_1[0xd];
    local_7c = local_3c ^ local_7c;
    local_80 = local_40 ^ local_80;
    local_30 = param_1[0xe];
    local_2c = param_1[0xf];
    local_78 = local_38 ^ local_78;
    local_74 = local_34 ^ local_74;
    local_70 = local_30 ^ local_70;
    local_6c = local_2c ^ local_6c;
    while( true ) {
      uVar73 = local_2c;
      uVar72 = local_30;
      uVar71 = local_34;
      uVar70 = local_38;
      uVar69 = local_3c;
      uVar68 = local_40;
      uVar67 = local_44;
      uVar66 = local_48;
      uVar65 = local_4c;
      uVar64 = local_50;
      uVar63 = local_54;
      uVar62 = local_58;
      uVar61 = local_5c;
      uVar77 = local_60;
      uVar76 = local_64;
      uVar75 = local_68;
      local_290 = (uint *)&DAT_00245d80;
      do {
        iVar1 = ((short)(ushort)local_54._3_1_ * 8 + 7) * 8;
        iVar2 = ((short)(ushort)local_68._1_1_ * 8 + 1) * 8;
        iVar3 = (local_58 & 0xff) * 0x40;
        iVar4 = ((short)(ushort)local_68._3_1_ * 8 + 3) * 8;
        iVar5 = ((short)(ushort)local_68._2_1_ * 8 + 2) * 8;
        iVar6 = ((short)(ushort)(byte)local_64 * 8 + 4) * 8;
        iVar7 = ((short)(ushort)local_64._1_1_ * 8 + 5) * 8;
        local_270 = (ushort)local_64._3_1_;
        iVar8 = ((short)(ushort)local_64._2_1_ * 8 + 6) * 8;
        iVar9 = ((short)local_270 * 8 + 7) * 8;
        local_268 = (ushort)local_60._1_1_;
        local_230 = (ushort)local_54 & 0xff;
        iVar10 = ((short)local_268 * 8 + 1) * 8;
        iVar11 = ((short)(ushort)local_58._1_1_ * 8 + 1) * 8;
        local_258 = (ushort)local_60._3_1_;
        iVar12 = ((short)(ushort)local_60._2_1_ * 8 + 2) * 8;
        iVar13 = ((short)local_258 * 8 + 3) * 8;
        iVar14 = ((short)(ushort)(byte)local_5c * 8 + 4) * 8;
        iVar15 = (local_60 & 0xff) * 0x40;
        iVar16 = (local_50 & 0xff) * 0x40;
        iVar17 = (local_48 & 0xff) * 0x40;
        iVar18 = ((short)(ushort)local_58._2_1_ * 8 + 2) * 8;
        iVar19 = (local_40 & 0xff) * 0x40;
        local_218 = (ushort)local_4c._2_1_;
        iVar20 = ((short)local_218 * 8 + 6) * 8;
        local_208 = (ushort)local_44._1_1_;
        local_258 = (ushort)local_50._1_1_;
        iVar21 = ((short)local_208 * 8 + 5) * 8;
        iVar59 = (int)(short)local_258;
        local_258 = (ushort)local_4c & 0xff;
        local_210 = (ushort)local_4c._3_1_;
        local_200 = (ushort)local_44._2_1_;
        iVar59 = (iVar59 * 8 + 1) * 8;
        iVar22 = ((short)local_210 * 8 + 7) * 8;
        iVar23 = ((short)local_200 * 8 + 6) * 8;
        local_1f8 = (ushort)local_44._3_1_;
        local_200 = (ushort)local_44 & 0xff;
        iVar24 = ((short)local_1f8 * 8 + 7) * 8;
        local_250 = (ushort)local_5c._1_1_;
        iVar25 = ((short)local_250 * 8 + 5) * 8;
        local_238 = (ushort)local_58._3_1_;
        local_1f8 = (ushort)local_3c & 0xff;
        iVar26 = ((short)local_238 * 8 + 3) * 8;
        iVar27 = ((short)local_230 * 8 + 4) * 8;
        local_280 = (ushort)local_50._2_1_;
        local_1d8 = (ushort)local_34 & 0xff;
        iVar28 = ((short)local_280 * 8 + 2) * 8;
        local_278 = (ushort)local_50._3_1_;
        iVar29 = (local_38 & 0xff) * 0x40;
        iVar30 = ((short)local_278 * 8 + 3) * 8;
        local_210 = (ushort)local_48._1_1_;
        iVar31 = ((short)local_210 * 8 + 1) * 8;
        iVar32 = ((short)(ushort)local_48._2_1_ * 8 + 2) * 8;
        iVar33 = ((short)local_1f8 * 8 + 4) * 8;
        local_250 = (ushort)local_40._1_1_;
        iVar34 = ((short)(ushort)local_38._3_1_ * 8 + 3) * 8;
        local_1f0 = (ushort)local_3c._1_1_;
        iVar35 = ((short)local_250 * 8 + 1) * 8;
        iVar36 = ((short)local_1f0 * 8 + 5) * 8;
        local_1e8 = (ushort)local_3c._2_1_;
        local_1e0 = (ushort)local_3c._3_1_;
        iVar37 = ((short)local_1e8 * 8 + 6) * 8;
        local_1d0 = (ushort)local_34._1_1_;
        iVar38 = ((short)local_1d8 * 8 + 4) * 8;
        iVar39 = ((short)local_1e0 * 8 + 7) * 8;
        iVar40 = ((short)local_1d0 * 8 + 5) * 8;
        local_1c8 = (ushort)local_34._2_1_;
        iVar41 = ((short)local_1c8 * 8 + 6) * 8;
        local_248 = (ushort)local_5c._2_1_;
        iVar42 = ((short)local_248 * 8 + 6) * 8;
        iVar43 = (local_30 & 0xff) * 0x40;
        local_240 = (ushort)local_5c._3_1_;
        local_220 = (ushort)local_54._2_1_;
        iVar44 = ((short)local_240 * 8 + 7) * 8;
        iVar45 = ((short)local_220 * 8 + 6) * 8;
        local_1e8 = (ushort)local_2c & 0xff;
        iVar46 = (local_68 & 0xff) * 0x40;
        local_228 = (ushort)local_54._1_1_;
        iVar47 = ((short)local_228 * 8 + 5) * 8;
        puVar80 = local_290 + 2;
        local_270 = (ushort)local_4c._1_1_;
        iVar48 = ((short)local_270 * 8 + 5) * 8;
        iVar49 = ((short)local_258 * 8 + 4) * 8;
        local_208 = (ushort)local_48._3_1_;
        iVar50 = ((short)local_200 * 8 + 4) * 8;
        local_230 = (ushort)local_40._3_1_;
        iVar51 = ((short)local_208 * 8 + 3) * 8;
        local_238 = (ushort)local_40._2_1_;
        iVar52 = ((short)local_230 * 8 + 3) * 8;
        local_210 = (ushort)local_38._2_1_;
        iVar53 = ((short)local_238 * 8 + 2) * 8;
        local_288 = (ushort)local_34._3_1_;
        iVar54 = ((short)local_210 * 8 + 2) * 8;
        local_218 = (ushort)local_38._1_1_;
        iVar55 = ((short)local_288 * 8 + 7) * 8;
        local_1f0 = (ushort)local_30._2_1_;
        local_220 = (ushort)local_30._3_1_;
        iVar56 = ((short)local_218 * 8 + 1) * 8;
        iVar57 = ((short)local_1f0 * 8 + 2) * 8;
        iVar58 = ((short)local_220 * 8 + 3) * 8;
        local_1e0 = (ushort)local_2c._1_1_;
        uVar79 = *(uint *)(&Cx + iVar49) ^
                 *(uint *)(&Cx + iVar47) ^
                 *(uint *)(&Cx + iVar9) ^ *(uint *)(&Cx + iVar42) ^ *(uint *)(&Cx + iVar43) ^
                 *(uint *)(&Cx + iVar51) ^ *(uint *)(&Cx + iVar53) ^ *(uint *)(&Cx + iVar56);
        uVar81 = *(uint *)(&DAT_00241d8c + iVar49) ^
                 *(uint *)(&DAT_00241d8c + iVar47) ^
                 *(uint *)(&DAT_00241d8c + iVar9) ^ *(uint *)(&DAT_00241d8c + iVar42) ^
                 *(uint *)(&DAT_00241d8c + iVar43) ^ *(uint *)(&DAT_00241d8c + iVar51) ^
                 *(uint *)(&DAT_00241d8c + iVar53) ^ *(uint *)(&DAT_00241d8c + iVar56);
        iVar9 = ((short)local_1e8 * 8 + 4) * 8;
        local_60 = *(uint *)(&Cx + iVar34) ^
                   *(uint *)(&Cx + iVar21) ^
                   *(uint *)(&Cx + iVar2) ^ *(uint *)(&Cx + iVar1) ^ *(uint *)(&Cx + iVar15) ^
                   *(uint *)(&Cx + iVar20) ^ *(uint *)(&Cx + iVar33) ^ *(uint *)(&Cx + iVar57);
        local_5c = *(uint *)(&DAT_00241d8c + iVar34) ^
                   *(uint *)(&DAT_00241d8c + iVar21) ^
                   *(uint *)(&DAT_00241d8c + iVar2) ^ *(uint *)(&DAT_00241d8c + iVar1) ^
                   *(uint *)(&DAT_00241d8c + iVar15) ^ *(uint *)(&DAT_00241d8c + iVar20) ^
                   *(uint *)(&DAT_00241d8c + iVar33) ^ *(uint *)(&DAT_00241d8c + iVar57);
        iVar1 = ((short)local_1e0 * 8 + 5) * 8;
        local_240 = (ushort)local_30._1_1_;
        local_58 = *(uint *)(&Cx + iVar23) ^
                   *(uint *)(&Cx + iVar3) ^ *(uint *)(&Cx + iVar5) ^ *(uint *)(&Cx + iVar10) ^
                   *(uint *)(&Cx + iVar22) ^ *(uint *)(&Cx + iVar36) ^ *(uint *)(&Cx + iVar38) ^
                   *(uint *)(&Cx + iVar58);
        local_54 = *(uint *)(&DAT_00241d8c + iVar23) ^
                   *(uint *)(&DAT_00241d8c + iVar3) ^
                   *(uint *)(&DAT_00241d8c + iVar5) ^ *(uint *)(&DAT_00241d8c + iVar10) ^
                   *(uint *)(&DAT_00241d8c + iVar22) ^ *(uint *)(&DAT_00241d8c + iVar36) ^
                   *(uint *)(&DAT_00241d8c + iVar38) ^ *(uint *)(&DAT_00241d8c + iVar58);
        local_1d8 = (ushort)local_2c._2_1_;
        iVar2 = ((short)local_240 * 8 + 1) * 8;
        local_50 = *(uint *)(&Cx + iVar40) ^
                   *(uint *)(&Cx + iVar24) ^
                   *(uint *)(&Cx + iVar11) ^
                   *(uint *)(&Cx + iVar4) ^ *(uint *)(&Cx + iVar12) ^ *(uint *)(&Cx + iVar16) ^
                   *(uint *)(&Cx + iVar37) ^ *(uint *)(&Cx + iVar9);
        local_1d0 = (ushort)local_2c._3_1_;
        local_4c = *(uint *)(&DAT_00241d8c + iVar40) ^
                   *(uint *)(&DAT_00241d8c + iVar24) ^
                   *(uint *)(&DAT_00241d8c + iVar11) ^
                   *(uint *)(&DAT_00241d8c + iVar4) ^ *(uint *)(&DAT_00241d8c + iVar12) ^
                   *(uint *)(&DAT_00241d8c + iVar16) ^ *(uint *)(&DAT_00241d8c + iVar37) ^
                   *(uint *)(&DAT_00241d8c + iVar9);
        iVar3 = ((short)local_1d8 * 8 + 6) * 8;
        local_48 = *(uint *)(&Cx + iVar59) ^
                   *(uint *)(&Cx + iVar18) ^
                   *(uint *)(&Cx + iVar17) ^ *(uint *)(&Cx + iVar13) ^ *(uint *)(&Cx + iVar6) ^
                   *(uint *)(&Cx + iVar39) ^ *(uint *)(&Cx + iVar41) ^ *(uint *)(&Cx + iVar1);
        local_44 = *(uint *)(&DAT_00241d8c + iVar59) ^
                   *(uint *)(&DAT_00241d8c + iVar18) ^
                   *(uint *)(&DAT_00241d8c + iVar17) ^
                   *(uint *)(&DAT_00241d8c + iVar13) ^ *(uint *)(&DAT_00241d8c + iVar6) ^
                   *(uint *)(&DAT_00241d8c + iVar39) ^ *(uint *)(&DAT_00241d8c + iVar41) ^
                   *(uint *)(&DAT_00241d8c + iVar1);
        iVar1 = ((short)local_1d0 * 8 + 7) * 8;
        local_64 = *(uint *)(&DAT_00241d8c + iVar52) ^
                   *(uint *)(&DAT_00241d8c + iVar50) ^
                   *(uint *)(&DAT_00241d8c + iVar48) ^
                   *(uint *)(&DAT_00241d8c + iVar45) ^
                   *(uint *)(&DAT_00241d8c + iVar44) ^
                   *(uint *)(&DAT_00241d8c + iVar46) ^ local_290[3] ^
                   *(uint *)(&DAT_00241d8c + iVar54) ^ *(uint *)(&DAT_00241d8c + iVar2);
        local_68 = *(uint *)(&Cx + iVar52) ^
                   *(uint *)(&Cx + iVar50) ^
                   *(uint *)(&Cx + iVar48) ^
                   *(uint *)(&Cx + iVar45) ^
                   *(uint *)(&Cx + iVar44) ^ *(uint *)(&Cx + iVar46) ^ *puVar80 ^
                   *(uint *)(&Cx + iVar54) ^ *(uint *)(&Cx + iVar2);
        local_40 = *(uint *)(&Cx + iVar31) ^
                   *(uint *)(&Cx + iVar28) ^
                   *(uint *)(&Cx + iVar19) ^ *(uint *)(&Cx + iVar7) ^ *(uint *)(&Cx + iVar14) ^
                   *(uint *)(&Cx + iVar26) ^ *(uint *)(&Cx + iVar55) ^ *(uint *)(&Cx + iVar3);
        local_3c = *(uint *)(&DAT_00241d8c + iVar31) ^
                   *(uint *)(&DAT_00241d8c + iVar28) ^
                   *(uint *)(&DAT_00241d8c + iVar19) ^
                   *(uint *)(&DAT_00241d8c + iVar7) ^ *(uint *)(&DAT_00241d8c + iVar14) ^
                   *(uint *)(&DAT_00241d8c + iVar26) ^ *(uint *)(&DAT_00241d8c + iVar55) ^
                   *(uint *)(&DAT_00241d8c + iVar3);
        local_34 = *(uint *)(&DAT_00241d8c + iVar35) ^
                   *(uint *)(&DAT_00241d8c + iVar30) ^
                   *(uint *)(&DAT_00241d8c + iVar27) ^
                   *(uint *)(&DAT_00241d8c + iVar8) ^ *(uint *)(&DAT_00241d8c + iVar25) ^
                   *(uint *)(&DAT_00241d8c + iVar29) ^ *(uint *)(&DAT_00241d8c + iVar32) ^
                   *(uint *)(&DAT_00241d8c + iVar1);
        local_38 = *(uint *)(&Cx + iVar35) ^
                   *(uint *)(&Cx + iVar30) ^
                   *(uint *)(&Cx + iVar27) ^
                   *(uint *)(&Cx + iVar8) ^ *(uint *)(&Cx + iVar25) ^ *(uint *)(&Cx + iVar29) ^
                   *(uint *)(&Cx + iVar32) ^ *(uint *)(&Cx + iVar1);
        local_238 = (ushort)local_a4 & 0xff;
        iVar1 = ((short)(ushort)local_a8._1_1_ * 8 + 1) * 8;
        iVar2 = ((short)(ushort)local_a8._2_1_ * 8 + 2) * 8;
        local_210 = (ushort)local_9c & 0xff;
        iVar3 = ((short)(ushort)local_a4._3_1_ * 8 + 7) * 8;
        local_1e8 = (ushort)local_94 & 0xff;
        iVar4 = ((short)(ushort)local_a0._1_1_ * 8 + 1) * 8;
        iVar5 = ((short)(ushort)local_9c._2_1_ * 8 + 6) * 8;
        iVar6 = ((short)(ushort)local_9c._3_1_ * 8 + 7) * 8;
        iVar7 = ((short)(ushort)local_94._1_1_ * 8 + 5) * 8;
        iVar8 = (local_70 & 0xff) * 0x40;
        iVar9 = ((short)(ushort)(byte)local_8c * 8 + 4) * 8;
        iVar10 = ((short)(ushort)local_88._3_1_ * 8 + 3) * 8;
        iVar11 = ((short)(ushort)local_94._2_1_ * 8 + 6) * 8;
        iVar12 = ((short)(ushort)local_94._3_1_ * 8 + 7) * 8;
        local_190 = (ushort)local_74 & 0xff;
        iVar13 = ((short)(ushort)local_8c._1_1_ * 8 + 5) * 8;
        iVar14 = ((short)(ushort)local_8c._2_1_ * 8 + 6) * 8;
        local_1a8 = (ushort)local_7c & 0xff;
        iVar15 = ((short)(ushort)local_8c._3_1_ * 8 + 7) * 8;
        iVar16 = ((short)(ushort)(byte)local_84 * 8 + 4) * 8;
        iVar17 = ((short)(ushort)local_84._1_1_ * 8 + 5) * 8;
        iVar18 = ((short)(ushort)local_84._2_1_ * 8 + 6) * 8;
        iVar19 = ((short)(ushort)local_78._1_1_ * 8 + 1) * 8;
        iVar20 = ((short)(ushort)local_80._2_1_ * 8 + 2) * 8;
        iVar21 = (local_a8 & 0xff) * 0x40;
        local_260 = (ushort)local_80._3_1_;
        iVar59 = ((short)local_260 * 8 + 3) * 8;
        iVar22 = ((short)local_1a8 * 8 + 4) * 8;
        iVar23 = ((short)(ushort)local_7c._1_1_ * 8 + 5) * 8;
        iVar24 = (local_a0 & 0xff) * 0x40;
        iVar25 = ((short)(ushort)local_78._2_1_ * 8 + 2) * 8;
        iVar26 = ((short)(ushort)local_78._3_1_ * 8 + 3) * 8;
        uVar84 = uVar79 ^ *(uint *)(&Cx + iVar7) ^
                          *(uint *)(&Cx + iVar8) ^ *(uint *)(&Cx + iVar3) ^ *(uint *)(&Cx + iVar5) ^
                          *(uint *)(&Cx + iVar9) ^ *(uint *)(&Cx + iVar10) ^ *(uint *)(&Cx + iVar20)
                          ^ *(uint *)(&Cx + iVar19);
        uVar85 = uVar81 ^ *(uint *)(&DAT_00241d8c + iVar7) ^
                          *(uint *)(&DAT_00241d8c + iVar8) ^
                          *(uint *)(&DAT_00241d8c + iVar3) ^ *(uint *)(&DAT_00241d8c + iVar5) ^
                          *(uint *)(&DAT_00241d8c + iVar9) ^ *(uint *)(&DAT_00241d8c + iVar10) ^
                          *(uint *)(&DAT_00241d8c + iVar20) ^ *(uint *)(&DAT_00241d8c + iVar19);
        iVar3 = ((short)local_190 * 8 + 4) * 8;
        local_170 = (ushort)local_70._2_1_;
        iVar5 = ((short)(ushort)local_70._1_1_ * 8 + 1) * 8;
        iVar7 = (local_98 & 0xff) * 0x40;
        local_168 = (ushort)local_70._3_1_;
        iVar8 = ((short)local_170 * 8 + 2) * 8;
        iVar9 = ((short)local_168 * 8 + 3) * 8;
        local_240 = (ushort)local_a8._3_1_;
        iVar10 = ((short)local_240 * 8 + 3) * 8;
        local_230 = (ushort)local_a4._1_1_;
        local_228 = (ushort)local_a4._2_1_;
        iVar19 = ((short)local_238 * 8 + 4) * 8;
        iVar20 = ((short)local_230 * 8 + 5) * 8;
        local_220 = (ushort)local_a0._2_1_;
        iVar27 = ((short)local_228 * 8 + 6) * 8;
        iVar28 = ((short)local_220 * 8 + 2) * 8;
        local_218 = (ushort)local_a0._3_1_;
        iVar29 = ((short)local_218 * 8 + 3) * 8;
        local_200 = (ushort)local_98._1_1_;
        local_288 = (ushort)local_6c & 0xff;
        iVar30 = ((short)local_210 * 8 + 4) * 8;
        iVar31 = ((short)local_200 * 8 + 1) * 8;
        local_1f0 = (ushort)local_98._3_1_;
        local_1f8 = (ushort)local_98._2_1_;
        iVar32 = (local_88 & 0xff) * 0x40;
        iVar33 = ((short)local_1f8 * 8 + 2) * 8;
        iVar34 = (local_80 & 0xff) * 0x40;
        local_1e0 = (ushort)local_90._1_1_;
        iVar35 = (local_90 & 0xff) * 0x40;
        iVar36 = ((short)local_1f0 * 8 + 3) * 8;
        iVar37 = ((short)local_1e0 * 8 + 1) * 8;
        local_1d8 = (ushort)local_90._2_1_;
        local_1c8 = (ushort)local_88._1_1_;
        iVar38 = ((short)local_1d8 * 8 + 2) * 8;
        local_1b8 = (ushort)local_84._3_1_;
        iVar39 = ((short)local_1b8 * 8 + 7) * 8;
        iVar40 = ((short)local_1c8 * 8 + 1) * 8;
        local_1a0 = (ushort)local_7c._2_1_;
        local_198 = (ushort)local_7c._3_1_;
        iVar41 = ((short)local_1a0 * 8 + 6) * 8;
        local_188 = (ushort)local_74._1_1_;
        iVar42 = ((short)local_198 * 8 + 7) * 8;
        local_180 = (ushort)local_74._2_1_;
        iVar43 = ((short)local_188 * 8 + 5) * 8;
        iVar44 = ((short)local_180 * 8 + 6) * 8;
        local_174 = (ushort)local_74._3_1_;
        iVar45 = ((short)local_174 * 8 + 7) * 8;
        bVar60 = local_6c._3_1_;
        local_240 = (ushort)local_6c._1_1_;
        local_238 = (ushort)local_6c._2_1_;
        iVar46 = ((short)local_288 * 8 + 4) * 8;
        iVar47 = ((short)local_240 * 8 + 5) * 8;
        iVar48 = ((short)local_238 * 8 + 6) * 8;
        local_208 = (ushort)local_9c._1_1_;
        local_1d0 = (ushort)local_90._3_1_;
        iVar49 = ((short)local_1e8 * 8 + 4) * 8;
        local_70 = uVar84;
        local_6c = uVar85;
        iVar50 = ((short)local_208 * 8 + 5) * 8;
        iVar51 = (local_78 & 0xff) * 0x40;
        local_1c0 = (ushort)local_88._2_1_;
        iVar52 = ((short)local_1d0 * 8 + 3) * 8;
        local_1b0 = (ushort)local_80._1_1_;
        local_230 = (ushort)bVar60;
        iVar53 = ((short)local_1c0 * 8 + 2) * 8;
        iVar54 = ((short)local_1b0 * 8 + 1) * 8;
        iVar55 = ((short)local_230 * 8 + 7) * 8;
        local_a8 = local_68 ^
                   *(uint *)(&Cx + iVar5) ^
                   *(uint *)(&Cx + iVar25) ^
                   *(uint *)(&Cx + iVar59) ^
                   *(uint *)(&Cx + iVar16) ^
                   *(uint *)(&Cx + iVar13) ^
                   *(uint *)(&Cx + iVar6) ^ *(uint *)(&Cx + iVar11) ^ *(uint *)(&Cx + iVar21);
        local_a4 = local_64 ^
                   *(uint *)(&DAT_00241d8c + iVar5) ^
                   *(uint *)(&DAT_00241d8c + iVar25) ^
                   *(uint *)(&DAT_00241d8c + iVar59) ^
                   *(uint *)(&DAT_00241d8c + iVar16) ^
                   *(uint *)(&DAT_00241d8c + iVar13) ^
                   *(uint *)(&DAT_00241d8c + iVar6) ^ *(uint *)(&DAT_00241d8c + iVar11) ^
                   *(uint *)(&DAT_00241d8c + iVar21);
        local_a0 = local_60 ^
                   *(uint *)(&Cx + iVar8) ^
                   *(uint *)(&Cx + iVar26) ^
                   *(uint *)(&Cx + iVar22) ^
                   *(uint *)(&Cx + iVar17) ^
                   *(uint *)(&Cx + iVar14) ^
                   *(uint *)(&Cx + iVar24) ^ *(uint *)(&Cx + iVar12) ^ *(uint *)(&Cx + iVar1);
        local_9c = local_5c ^
                   *(uint *)(&DAT_00241d8c + iVar8) ^
                   *(uint *)(&DAT_00241d8c + iVar26) ^
                   *(uint *)(&DAT_00241d8c + iVar22) ^
                   *(uint *)(&DAT_00241d8c + iVar17) ^
                   *(uint *)(&DAT_00241d8c + iVar14) ^
                   *(uint *)(&DAT_00241d8c + iVar24) ^
                   *(uint *)(&DAT_00241d8c + iVar12) ^ *(uint *)(&DAT_00241d8c + iVar1);
        local_98 = local_58 ^
                   *(uint *)(&Cx + iVar9) ^
                   *(uint *)(&Cx + iVar3) ^
                   *(uint *)(&Cx + iVar23) ^
                   *(uint *)(&Cx + iVar15) ^
                   *(uint *)(&Cx + iVar4) ^ *(uint *)(&Cx + iVar2) ^ *(uint *)(&Cx + iVar7) ^
                   *(uint *)(&Cx + iVar18);
        local_94 = local_54 ^
                   *(uint *)(&DAT_00241d8c + iVar9) ^
                   *(uint *)(&DAT_00241d8c + iVar3) ^
                   *(uint *)(&DAT_00241d8c + iVar23) ^
                   *(uint *)(&DAT_00241d8c + iVar15) ^
                   *(uint *)(&DAT_00241d8c + iVar4) ^ *(uint *)(&DAT_00241d8c + iVar2) ^
                   *(uint *)(&DAT_00241d8c + iVar7) ^ *(uint *)(&DAT_00241d8c + iVar18);
        local_90 = local_50 ^
                   *(uint *)(&Cx + iVar46) ^
                   *(uint *)(&Cx + iVar43) ^
                   *(uint *)(&Cx + iVar39) ^
                   *(uint *)(&Cx + iVar31) ^
                   *(uint *)(&Cx + iVar35) ^ *(uint *)(&Cx + iVar10) ^ *(uint *)(&Cx + iVar28) ^
                   *(uint *)(&Cx + iVar41);
        local_8c = local_4c ^
                   *(uint *)(&DAT_00241d8c + iVar46) ^
                   *(uint *)(&DAT_00241d8c + iVar43) ^
                   *(uint *)(&DAT_00241d8c + iVar39) ^
                   *(uint *)(&DAT_00241d8c + iVar31) ^
                   *(uint *)(&DAT_00241d8c + iVar35) ^
                   *(uint *)(&DAT_00241d8c + iVar10) ^ *(uint *)(&DAT_00241d8c + iVar28) ^
                   *(uint *)(&DAT_00241d8c + iVar41);
        local_88 = local_48 ^
                   *(uint *)(&Cx + iVar47) ^
                   *(uint *)(&Cx + iVar44) ^
                   *(uint *)(&Cx + iVar42) ^
                   *(uint *)(&Cx + iVar37) ^
                   *(uint *)(&Cx + iVar33) ^
                   *(uint *)(&Cx + iVar32) ^ *(uint *)(&Cx + iVar29) ^ *(uint *)(&Cx + iVar19);
        local_84 = local_44 ^
                   *(uint *)(&DAT_00241d8c + iVar47) ^
                   *(uint *)(&DAT_00241d8c + iVar44) ^
                   *(uint *)(&DAT_00241d8c + iVar42) ^
                   *(uint *)(&DAT_00241d8c + iVar37) ^
                   *(uint *)(&DAT_00241d8c + iVar33) ^
                   *(uint *)(&DAT_00241d8c + iVar32) ^
                   *(uint *)(&DAT_00241d8c + iVar29) ^ *(uint *)(&DAT_00241d8c + iVar19);
        local_78 = local_38 ^
                   *(uint *)(&Cx + iVar55) ^
                   *(uint *)(&Cx + iVar50) ^ *(uint *)(&Cx + iVar27) ^ *(uint *)(&Cx + iVar51) ^
                   *(uint *)(&Cx + iVar49) ^ *(uint *)(&Cx + iVar52) ^ *(uint *)(&Cx + iVar53) ^
                   *(uint *)(&Cx + iVar54);
        local_74 = local_34 ^
                   *(uint *)(&DAT_00241d8c + iVar55) ^
                   *(uint *)(&DAT_00241d8c + iVar50) ^ *(uint *)(&DAT_00241d8c + iVar27) ^
                   *(uint *)(&DAT_00241d8c + iVar51) ^ *(uint *)(&DAT_00241d8c + iVar49) ^
                   *(uint *)(&DAT_00241d8c + iVar52) ^ *(uint *)(&DAT_00241d8c + iVar53) ^
                   *(uint *)(&DAT_00241d8c + iVar54);
        local_80 = local_40 ^
                   *(uint *)(&Cx + iVar48) ^
                   *(uint *)(&Cx + iVar45) ^
                   *(uint *)(&Cx + iVar38) ^
                   *(uint *)(&Cx + iVar30) ^ *(uint *)(&Cx + iVar20) ^ *(uint *)(&Cx + iVar34) ^
                   *(uint *)(&Cx + iVar36) ^ *(uint *)(&Cx + iVar40);
        local_7c = local_3c ^
                   *(uint *)(&DAT_00241d8c + iVar48) ^
                   *(uint *)(&DAT_00241d8c + iVar45) ^
                   *(uint *)(&DAT_00241d8c + iVar38) ^
                   *(uint *)(&DAT_00241d8c + iVar30) ^ *(uint *)(&DAT_00241d8c + iVar20) ^
                   *(uint *)(&DAT_00241d8c + iVar34) ^ *(uint *)(&DAT_00241d8c + iVar36) ^
                   *(uint *)(&DAT_00241d8c + iVar40);
        local_290 = puVar80;
        local_30 = uVar79;
        local_2c = uVar81;
      } while (puVar80 != (uint *)&DAT_00245dd0);
      if (local_ec == 0) {
        uVar79 = local_104[-0xf];
        *param_1 = local_a8 ^ uVar75 ^ local_104[-0x10];
        param_1[1] = local_a4 ^ uVar76 ^ uVar79;
        uVar75 = local_104[-0xd];
        param_1[2] = local_a0 ^ uVar77 ^ local_104[-0xe];
        param_1[3] = local_9c ^ uVar61 ^ uVar75;
        uVar75 = local_104[-0xb];
        param_1[4] = uVar62 ^ local_104[-0xc] ^ local_98;
        param_1[5] = uVar63 ^ uVar75 ^ local_94;
        uVar75 = local_104[-9];
        param_1[6] = local_90 ^ uVar64 ^ local_104[-10];
        param_1[7] = local_8c ^ uVar65 ^ uVar75;
        uVar75 = local_104[-7];
        param_1[8] = local_88 ^ uVar66 ^ local_104[-8];
        param_1[9] = local_84 ^ uVar67 ^ uVar75;
        uVar75 = local_104[-5];
        param_1[10] = local_80 ^ uVar68 ^ local_104[-6];
        param_1[0xb] = local_7c ^ uVar69 ^ uVar75;
        uVar75 = local_104[-3];
        param_1[0xc] = local_78 ^ uVar70 ^ local_104[-4];
        param_1[0xd] = local_74 ^ uVar71 ^ uVar75;
        uVar75 = local_104[-1];
        param_1[0xe] = uVar84 ^ uVar72 ^ local_104[-2];
        param_1[0xf] = uVar85 ^ uVar73 ^ uVar75;
      }
      else if (((uint)local_f8 & 3) == 0 && (param_1 + 1 <= local_f8 || local_f8 + 1 <= param_1)) {
        *param_1 = local_104[-0x10] ^ local_a8 ^ *param_1;
        param_1[1] = local_104[-0xf] ^ local_a4 ^ param_1[1];
        param_1[2] = local_104[-0xe] ^ local_a0 ^ param_1[2];
        param_1[3] = local_104[-0xd] ^ local_9c ^ param_1[3];
        param_1[4] = local_104[-0xc] ^ local_98 ^ param_1[4];
        param_1[5] = local_104[-0xb] ^ local_94 ^ param_1[5];
        param_1[6] = local_104[-10] ^ local_90 ^ param_1[6];
        param_1[7] = local_104[-9] ^ local_8c ^ param_1[7];
        param_1[8] = local_104[-8] ^ local_88 ^ param_1[8];
        param_1[9] = local_104[-7] ^ local_84 ^ param_1[9];
        param_1[10] = local_104[-6] ^ local_80 ^ param_1[10];
        param_1[0xb] = local_104[-5] ^ local_7c ^ param_1[0xb];
        param_1[0xc] = local_104[-4] ^ local_78 ^ param_1[0xc];
        param_1[0xd] = local_104[-3] ^ local_74 ^ param_1[0xd];
        param_1[0xe] = local_104[-2] ^ uVar84 ^ param_1[0xe];
        param_1[0xf] = local_104[-1] ^ uVar85 ^ param_1[0xf];
      }
      else {
        pbVar82 = (byte *)((int)local_f8 + -1);
        pbVar74 = &bStack_a9;
        puVar80 = param_1;
        do {
          pbVar82 = pbVar82 + 1;
          pbVar74 = pbVar74 + 1;
          *(byte *)puVar80 = (byte)*puVar80 ^ *pbVar74 ^ *pbVar82;
          puVar80 = (uint *)((int)puVar80 + 1);
        } while ((byte *)((int)&local_6c + 3) != pbVar74);
      }
      local_104 = local_104 + 0x10;
      local_f0 = local_f0 + -1;
      local_f8 = local_b0;
      if (local_f0 == 0) {
        return;
      }
      puVar80 = local_b0 + 0x10;
      local_ec = (uint)local_b0 & 7;
      local_b0 = puVar80;
      if (local_ec != 0) break;
LAB_001d34ce:
      local_68 = *param_1;
      local_64 = param_1[1];
      local_60 = param_1[2];
      local_5c = param_1[3];
      HintPreloadData(local_104);
      local_a4 = local_64 ^ local_104[-0xf];
      local_58 = param_1[4];
      local_54 = param_1[5];
      local_a8 = local_68 ^ local_104[-0x10];
      HintPreloadData(local_f8 + 0x12);
      HintPreloadData(local_f8 + 0x14);
      local_a0 = local_60 ^ local_104[-0xe];
      local_50 = param_1[6];
      local_4c = param_1[7];
      local_48 = param_1[8];
      local_44 = param_1[9];
      local_9c = local_5c ^ local_104[-0xd];
      HintPreloadData(local_f8 + 0x16);
      local_38 = param_1[0xc];
      local_34 = param_1[0xd];
      local_98 = local_58 ^ local_104[-0xc];
      local_94 = local_54 ^ local_104[-0xb];
      local_40 = param_1[10];
      local_3c = param_1[0xb];
      local_8c = local_4c ^ local_104[-9];
      local_90 = local_50 ^ local_104[-10];
      local_88 = local_48 ^ local_104[-8];
      local_84 = local_44 ^ local_104[-7];
      local_80 = local_40 ^ local_104[-6];
      local_7c = local_3c ^ local_104[-5];
      local_78 = local_38 ^ local_104[-4];
      local_74 = local_34 ^ local_104[-3];
      local_30 = param_1[0xe];
      local_2c = param_1[0xf];
      local_6c = local_2c ^ local_104[-1];
      local_70 = local_30 ^ local_104[-2];
    }
  } while( true );
}

