
void whirlpool_block(uint *param_1,uint *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint *puVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  uint *puVar22;
  uint uVar23;
  int iVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  uint *puVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  uint *puVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  uint *puVar42;
  int iVar43;
  int iVar44;
  uint *puVar45;
  int iVar46;
  uint *puVar47;
  int iVar48;
  int iVar49;
  int iVar50;
  uint uVar51;
  int iVar52;
  int iVar53;
  int iVar54;
  int iVar55;
  int iVar56;
  int iVar57;
  uint uVar58;
  int iVar59;
  int iVar60;
  uint *puVar61;
  int iVar62;
  int iVar63;
  int iVar64;
  int iVar65;
  int iVar66;
  int iVar67;
  int iVar68;
  int iVar69;
  int iVar70;
  int iVar71;
  int iVar72;
  int iVar73;
  int iVar74;
  int iVar75;
  uint uVar76;
  int iVar77;
  uint *puVar78;
  int iVar79;
  int iVar80;
  uint *local_10c;
  uint *local_f8;
  uint *local_f0;
  int local_ec;
  uint local_a0 [7];
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  
  iVar1 = DAT_0011c840;
  local_f0 = param_2 + 0x10;
  puVar35 = (uint *)(DAT_0011c840 + 0x4048);
  local_f8 = param_2;
  local_ec = param_3;
  do {
    if (((uint)local_f8 & 7) == 0) {
      local_60 = *param_1;
      local_5c = param_1[1];
      local_58 = param_1[2];
      local_54 = param_1[3];
      HintPreloadData(local_f0);
      HintPreloadData(local_f8 + 0x12);
      HintPreloadData(local_f8 + 0x14);
      HintPreloadData(local_f8 + 0x16);
      local_50 = param_1[4];
      local_4c = param_1[5];
      local_a0[0] = local_f0[-0x10] ^ local_60;
      local_48 = param_1[6];
      local_44 = param_1[7];
      local_a0[1] = local_f0[-0xf] ^ local_5c;
      local_a0[2] = local_f8[2] ^ local_58;
      local_a0[3] = local_f8[3] ^ local_54;
      local_40 = param_1[8];
      local_3c = param_1[9];
      local_a0[5] = local_f8[5] ^ local_4c;
      local_a0[4] = local_f8[4] ^ local_50;
      local_a0[6] = local_f8[6] ^ local_48;
      local_84 = local_f8[7] ^ local_44;
      local_38 = param_1[10];
      local_34 = param_1[0xb];
      local_80 = local_f8[8] ^ local_40;
      local_7c = local_f8[9] ^ local_3c;
      local_30 = param_1[0xc];
      local_2c = param_1[0xd];
      local_78 = local_f8[10] ^ local_38;
      local_74 = local_f8[0xb] ^ local_34;
      local_28 = param_1[0xe];
      local_24 = param_1[0xf];
      local_70 = local_f8[0xc] ^ local_30;
      local_6c = local_f8[0xd] ^ local_2c;
      local_68 = local_f8[0xe] ^ local_28;
      local_64 = local_f8[0xf] ^ local_24;
    }
    else {
      puVar17 = local_f0 + -0x10;
      puVar42 = local_a0;
      do {
        uVar14 = *puVar17;
        uVar16 = puVar17[1];
        uVar20 = puVar17[2];
        uVar23 = puVar17[3];
        puVar17 = puVar17 + 4;
        *puVar42 = uVar14;
        puVar42[1] = uVar16;
        puVar42[2] = uVar20;
        puVar42[3] = uVar23;
        puVar42 = puVar42 + 4;
      } while (puVar17 != local_f0);
      local_60 = *param_1;
      local_5c = param_1[1];
      local_58 = param_1[2];
      local_54 = param_1[3];
      local_a0[1] = local_a0[1] ^ local_5c;
      local_a0[0] = local_a0[0] ^ local_60;
      local_50 = param_1[4];
      local_4c = param_1[5];
      local_48 = param_1[6];
      local_44 = param_1[7];
      local_a0[2] = local_a0[2] ^ local_58;
      local_a0[3] = local_a0[3] ^ local_54;
      local_a0[5] = local_a0[5] ^ local_4c;
      local_a0[4] = local_a0[4] ^ local_50;
      local_40 = param_1[8];
      local_3c = param_1[9];
      local_a0[6] = local_a0[6] ^ local_48;
      local_84 = local_84 ^ local_44;
      local_80 = local_80 ^ local_40;
      local_7c = local_7c ^ local_3c;
      local_38 = param_1[10];
      local_34 = param_1[0xb];
      local_78 = local_78 ^ local_38;
      local_74 = local_74 ^ local_34;
      local_30 = param_1[0xc];
      local_2c = param_1[0xd];
      local_6c = local_6c ^ local_2c;
      local_70 = local_70 ^ local_30;
      local_28 = param_1[0xe];
      local_24 = param_1[0xf];
      local_68 = local_28 ^ local_68;
      local_64 = local_24 ^ local_64;
    }
    uVar13 = local_24;
    uVar12 = local_28;
    uVar11 = local_2c;
    uVar10 = local_30;
    uVar9 = local_34;
    uVar8 = local_38;
    uVar7 = local_3c;
    uVar6 = local_40;
    uVar5 = local_44;
    uVar4 = local_48;
    uVar3 = local_4c;
    uVar2 = local_50;
    uVar23 = local_54;
    uVar20 = local_58;
    uVar16 = local_5c;
    uVar14 = local_60;
    local_10c = DAT_0011c83c;
    do {
      puVar17 = (uint *)(iVar1 + (local_60 & 0xff) * 0x40);
      iVar21 = iVar1 + (local_54 >> 0x18) * 0x40;
      iVar77 = iVar1 + (local_4c >> 0x10 & 0xff) * 0x40;
      iVar70 = iVar1 + (local_44 >> 8 & 0xff) * 0x40;
      iVar64 = iVar1 + (local_3c & 0xff) * 0x40;
      iVar52 = iVar1 + (local_38 >> 0x18) * 0x40;
      iVar59 = iVar1 + (local_30 >> 0x10 & 0xff) * 0x40;
      iVar43 = iVar1 + (local_28 >> 8 & 0xff) * 0x40;
      puVar42 = local_10c + 2;
      iVar53 = iVar1 + (local_60 >> 0x10 & 0xff) * 0x40;
      iVar65 = iVar1 + (local_60 >> 8 & 0xff) * 0x40;
      iVar24 = iVar1 + (local_5c >> 8 & 0xff) * 0x40;
      iVar71 = iVar1 + (local_5c & 0xff) * 0x40;
      iVar36 = iVar1 + (local_60 >> 0x18) * 0x40;
      puVar22 = (uint *)(iVar1 + (local_50 & 0xff) * 0x40);
      iVar25 = iVar1 + (local_4c >> 0x18) * 0x40;
      iVar27 = iVar1 + (local_5c >> 0x10 & 0xff) * 0x40;
      iVar15 = iVar1 + (local_5c >> 0x18) * 0x40;
      iVar18 = iVar1 + (local_58 >> 8 & 0xff) * 0x40;
      puVar78 = (uint *)(iVar1 + (local_58 & 0xff) * 0x40);
      local_60 = *(uint *)(iVar77 + 0x30) ^ *puVar42 ^ *puVar17 ^ *(uint *)(iVar21 + 0x38) ^
                 *(uint *)(iVar70 + 0x28) ^ *(uint *)(iVar64 + 0x20) ^ *(uint *)(iVar52 + 0x18) ^
                 *(uint *)(iVar59 + 0x10) ^ *(uint *)(iVar43 + 8);
      local_5c = *(uint *)(iVar77 + 0x34) ^ local_10c[3] ^ puVar17[1] ^ *(uint *)(iVar21 + 0x3c) ^
                 *(uint *)(iVar70 + 0x2c) ^ *(uint *)(iVar64 + 0x24) ^ *(uint *)(iVar52 + 0x1c) ^
                 *(uint *)(iVar59 + 0x14) ^ *(uint *)(iVar43 + 0xc);
      iVar72 = iVar1 + (local_58 >> 0x10 & 0xff) * 0x40;
      puVar17 = (uint *)(iVar1 + (local_48 & 0xff) * 0x40);
      iVar52 = iVar1 + (local_50 >> 8 & 0xff) * 0x40;
      iVar59 = iVar1 + (local_44 >> 0x18) * 0x40;
      iVar73 = iVar1 + (local_44 >> 0x10 & 0xff) * 0x40;
      puVar28 = (uint *)(iVar1 + (local_40 & 0xff) * 0x40);
      iVar37 = iVar1 + (local_58 >> 0x18) * 0x40;
      iVar64 = iVar1 + (local_50 >> 0x10 & 0xff) * 0x40;
      iVar79 = iVar1 + (local_48 >> 8 & 0xff) * 0x40;
      iVar44 = iVar1 + (local_3c >> 8 & 0xff) * 0x40;
      iVar66 = iVar1 + (local_3c >> 0x10 & 0xff) * 0x40;
      iVar67 = iVar1 + (local_3c >> 0x18) * 0x40;
      iVar60 = iVar1 + (local_54 & 0xff) * 0x40;
      iVar54 = iVar1 + (local_50 >> 0x18) * 0x40;
      puVar45 = (uint *)(iVar1 + (local_38 & 0xff) * 0x40);
      iVar38 = iVar1 + (local_48 >> 0x10 & 0xff) * 0x40;
      iVar55 = iVar1 + (local_34 >> 0x10 & 0xff) * 0x40;
      iVar70 = iVar1 + (local_34 & 0xff) * 0x40;
      iVar39 = iVar1 + (local_40 >> 8 & 0xff) * 0x40;
      iVar77 = iVar1 + (local_34 >> 8 & 0xff) * 0x40;
      iVar21 = iVar1 + (local_34 >> 0x18) * 0x40;
      iVar29 = iVar1 + (local_54 >> 8 & 0xff) * 0x40;
      iVar30 = iVar1 + (local_4c & 0xff) * 0x40;
      puVar61 = (uint *)(iVar1 + (local_30 & 0xff) * 0x40);
      iVar31 = iVar1 + (local_48 >> 0x18) * 0x40;
      iVar68 = iVar1 + (local_40 >> 0x10 & 0xff) * 0x40;
      iVar74 = iVar1 + (local_38 >> 8 & 0xff) * 0x40;
      iVar43 = iVar1 + (local_30 >> 0x18) * 0x40;
      iVar40 = iVar1 + (local_2c & 0xff) * 0x40;
      iVar56 = iVar1 + (local_2c >> 8 & 0xff) * 0x40;
      iVar46 = iVar1 + (local_54 >> 0x10 & 0xff) * 0x40;
      iVar32 = iVar1 + (local_2c >> 0x10 & 0xff) * 0x40;
      puVar47 = (uint *)(iVar1 + (local_28 & 0xff) * 0x40);
      iVar33 = iVar1 + (local_2c >> 0x18) * 0x40;
      iVar48 = iVar1 + (local_44 & 0xff) * 0x40;
      iVar62 = iVar1 + (local_4c >> 8 & 0xff) * 0x40;
      iVar49 = iVar1 + (local_40 >> 0x18) * 0x40;
      iVar75 = iVar1 + (local_30 >> 8 & 0xff) * 0x40;
      iVar80 = iVar1 + (local_38 >> 0x10 & 0xff) * 0x40;
      iVar41 = iVar1 + (local_24 >> 8 & 0xff) * 0x40;
      iVar34 = iVar1 + (local_24 >> 0x10 & 0xff) * 0x40;
      iVar69 = iVar1 + (local_28 >> 0x10 & 0xff) * 0x40;
      iVar57 = iVar1 + (local_28 >> 0x18) * 0x40;
      iVar50 = iVar1 + (local_24 & 0xff) * 0x40;
      iVar63 = iVar1 + (local_24 >> 0x18) * 0x40;
      local_24 = *(uint *)(iVar48 + 0x24) ^
                 *(uint *)(iVar46 + 0x34) ^ *(uint *)(iVar15 + 0x3c) ^ puVar47[1] ^
                 *(uint *)(iVar62 + 0x2c) ^ *(uint *)(iVar49 + 0x1c) ^ *(uint *)(iVar80 + 0x14) ^
                 *(uint *)(iVar75 + 0xc);
      local_28 = *(uint *)(iVar48 + 0x20) ^
                 *(uint *)(iVar46 + 0x30) ^ *(uint *)(iVar15 + 0x38) ^ *puVar47 ^
                 *(uint *)(iVar62 + 0x28) ^ *(uint *)(iVar49 + 0x18) ^ *(uint *)(iVar80 + 0x10) ^
                 *(uint *)(iVar75 + 8);
      local_54 = *(uint *)(iVar25 + 0x3c) ^ *(uint *)(iVar65 + 0xc) ^ puVar78[1] ^
                 *(uint *)(iVar73 + 0x34) ^ *(uint *)(iVar44 + 0x2c) ^ *(uint *)(iVar70 + 0x24) ^
                 *(uint *)(iVar43 + 0x1c) ^ *(uint *)(iVar69 + 0x14);
      local_58 = *(uint *)(iVar25 + 0x38) ^ *(uint *)(iVar65 + 8) ^ *puVar78 ^
                 *(uint *)(iVar73 + 0x30) ^ *(uint *)(iVar44 + 0x28) ^ *(uint *)(iVar70 + 0x20) ^
                 *(uint *)(iVar43 + 0x18) ^ *(uint *)(iVar69 + 0x10);
      local_50 = *(uint *)(iVar18 + 8) ^ *(uint *)(iVar53 + 0x10) ^ *puVar22 ^
                 *(uint *)(iVar59 + 0x38) ^ *(uint *)(iVar66 + 0x30) ^ *(uint *)(iVar77 + 0x28) ^
                 *(uint *)(iVar40 + 0x20) ^ *(uint *)(iVar57 + 0x18);
      local_4c = *(uint *)(iVar18 + 0xc) ^ *(uint *)(iVar53 + 0x14) ^ puVar22[1] ^
                 *(uint *)(iVar59 + 0x3c) ^ *(uint *)(iVar66 + 0x34) ^ *(uint *)(iVar77 + 0x2c) ^
                 *(uint *)(iVar40 + 0x24) ^ *(uint *)(iVar57 + 0x1c);
      local_48 = *(uint *)(iVar72 + 0x10) ^ *(uint *)(iVar36 + 0x18) ^ *puVar17 ^
                 *(uint *)(iVar52 + 8) ^ *(uint *)(iVar67 + 0x38) ^ *(uint *)(iVar55 + 0x30) ^
                 *(uint *)(iVar56 + 0x28) ^ *(uint *)(iVar50 + 0x20);
      local_44 = *(uint *)(iVar72 + 0x14) ^ *(uint *)(iVar36 + 0x1c) ^ puVar17[1] ^
                 *(uint *)(iVar52 + 0xc) ^ *(uint *)(iVar67 + 0x3c) ^ *(uint *)(iVar55 + 0x34) ^
                 *(uint *)(iVar56 + 0x2c) ^ *(uint *)(iVar50 + 0x24);
      local_40 = *(uint *)(iVar37 + 0x18) ^ *(uint *)(iVar71 + 0x20) ^ *puVar28 ^
                 *(uint *)(iVar64 + 0x10) ^ *(uint *)(iVar79 + 8) ^ *(uint *)(iVar21 + 0x38) ^
                 *(uint *)(iVar32 + 0x30) ^ *(uint *)(iVar41 + 0x28);
      local_3c = *(uint *)(iVar37 + 0x1c) ^ *(uint *)(iVar71 + 0x24) ^ puVar28[1] ^
                 *(uint *)(iVar64 + 0x14) ^ *(uint *)(iVar79 + 0xc) ^ *(uint *)(iVar21 + 0x3c) ^
                 *(uint *)(iVar32 + 0x34) ^ *(uint *)(iVar41 + 0x2c);
      local_38 = *(uint *)(iVar54 + 0x18) ^
                 *(uint *)(iVar60 + 0x20) ^ *(uint *)(iVar24 + 0x28) ^ *puVar45 ^
                 *(uint *)(iVar38 + 0x10) ^ *(uint *)(iVar39 + 8) ^ *(uint *)(iVar33 + 0x38) ^
                 *(uint *)(iVar34 + 0x30);
      local_34 = *(uint *)(iVar54 + 0x1c) ^
                 *(uint *)(iVar60 + 0x24) ^ *(uint *)(iVar24 + 0x2c) ^ puVar45[1] ^
                 *(uint *)(iVar38 + 0x14) ^ *(uint *)(iVar39 + 0xc) ^ *(uint *)(iVar33 + 0x3c) ^
                 *(uint *)(iVar34 + 0x34);
      iVar15 = iVar1 + (local_a0[3] >> 0x18) * 0x40;
      iVar18 = iVar1 + (local_a0[5] >> 0x10 & 0xff) * 0x40;
      iVar77 = iVar1 + (local_a0[5] >> 0x18) * 0x40;
      local_30 = *(uint *)(iVar29 + 0x28) ^ *(uint *)(iVar27 + 0x30) ^ *puVar61 ^
                 *(uint *)(iVar30 + 0x20) ^ *(uint *)(iVar31 + 0x18) ^ *(uint *)(iVar68 + 0x10) ^
                 *(uint *)(iVar74 + 8) ^ *(uint *)(iVar63 + 0x38);
      local_2c = *(uint *)(iVar29 + 0x2c) ^ *(uint *)(iVar27 + 0x34) ^ puVar61[1] ^
                 *(uint *)(iVar30 + 0x24) ^ *(uint *)(iVar31 + 0x1c) ^ *(uint *)(iVar68 + 0x14) ^
                 *(uint *)(iVar74 + 0xc) ^ *(uint *)(iVar63 + 0x3c);
      iVar29 = iVar1 + (local_a0[0] >> 0x10 & 0xff) * 0x40;
      iVar70 = iVar1 + (local_a0[1] >> 0x18) * 0x40;
      iVar64 = iVar1 + (local_a0[3] >> 0x10 & 0xff) * 0x40;
      iVar27 = iVar1 + (local_a0[0] >> 8 & 0xff) * 0x40;
      iVar38 = iVar1 + (local_a0[2] >> 8 & 0xff) * 0x40;
      iVar30 = iVar1 + (local_a0[0] >> 0x18) * 0x40;
      puVar17 = (uint *)(iVar1 + (local_a0[0] & 0xff) * 0x40);
      iVar31 = iVar1 + (local_a0[2] >> 0x10 & 0xff) * 0x40;
      iVar32 = iVar1 + (local_a0[1] & 0xff) * 0x40;
      iVar21 = iVar1 + (local_84 >> 8 & 0xff) * 0x40;
      iVar33 = iVar1 + (local_a0[2] >> 0x18) * 0x40;
      iVar43 = iVar1 + (local_7c & 0xff) * 0x40;
      iVar34 = iVar1 + (local_a0[1] >> 8 & 0xff) * 0x40;
      iVar36 = iVar1 + (local_a0[3] & 0xff) * 0x40;
      iVar24 = iVar1 + (local_78 >> 0x18) * 0x40;
      iVar52 = iVar1 + (local_a0[1] >> 0x10 & 0xff) * 0x40;
      iVar37 = iVar1 + (local_a0[3] >> 8 & 0xff) * 0x40;
      puVar61 = (uint *)(iVar1 + (local_a0[2] & 0xff) * 0x40);
      puVar22 = (uint *)(iVar1 + (local_68 & 0xff) * 0x40);
      iVar25 = iVar1 + (local_70 >> 0x10 & 0xff) * 0x40;
      iVar59 = iVar1 + (local_68 >> 8 & 0xff) * 0x40;
      local_a0[0] = *(uint *)(iVar59 + 8) ^
                    *(uint *)(iVar15 + 0x38) ^ *(uint *)(iVar18 + 0x30) ^ *puVar17 ^
                    *(uint *)(iVar21 + 0x28) ^ *(uint *)(iVar43 + 0x20) ^ *(uint *)(iVar24 + 0x18) ^
                    *(uint *)(iVar25 + 0x10) ^ local_60;
      local_a0[1] = *(uint *)(iVar59 + 0xc) ^
                    *(uint *)(iVar15 + 0x3c) ^ *(uint *)(iVar18 + 0x34) ^ puVar17[1] ^
                    *(uint *)(iVar21 + 0x2c) ^ *(uint *)(iVar43 + 0x24) ^ *(uint *)(iVar24 + 0x1c) ^
                    *(uint *)(iVar25 + 0x14) ^ local_5c;
      iVar15 = iVar1 + (local_a0[5] >> 8 & 0xff) * 0x40;
      puVar17 = (uint *)(iVar1 + (local_80 & 0xff) * 0x40);
      puVar47 = (uint *)(iVar1 + (local_a0[6] & 0xff) * 0x40);
      puVar28 = (uint *)(iVar1 + (local_a0[4] & 0xff) * 0x40);
      iVar18 = iVar1 + (local_84 & 0xff) * 0x40;
      iVar21 = iVar1 + (local_80 >> 0x18) * 0x40;
      iVar43 = iVar1 + (local_78 >> 0x10 & 0xff) * 0x40;
      iVar24 = iVar1 + (local_70 >> 8 & 0xff) * 0x40;
      uVar51 = *(uint *)(iVar24 + 8) ^
               *(uint *)(iVar15 + 0x28) ^
               *(uint *)(iVar70 + 0x38) ^ *(uint *)(iVar64 + 0x30) ^ *puVar22 ^
               *(uint *)(iVar18 + 0x20) ^ *(uint *)(iVar21 + 0x18) ^ *(uint *)(iVar43 + 0x10) ^
               local_28;
      uVar58 = *(uint *)(iVar24 + 0xc) ^
               *(uint *)(iVar15 + 0x2c) ^
               *(uint *)(iVar70 + 0x3c) ^ *(uint *)(iVar64 + 0x34) ^ puVar22[1] ^
               *(uint *)(iVar18 + 0x24) ^ *(uint *)(iVar21 + 0x1c) ^ *(uint *)(iVar43 + 0x14) ^
               local_24;
      puVar22 = (uint *)(iVar1 + (local_70 & 0xff) * 0x40);
      iVar25 = iVar1 + (local_84 >> 0x18) * 0x40;
      iVar18 = iVar1 + (local_84 >> 0x10 & 0xff) * 0x40;
      iVar15 = iVar1 + (local_70 >> 0x18) * 0x40;
      iVar21 = iVar1 + (local_7c >> 8 & 0xff) * 0x40;
      iVar43 = iVar1 + (local_74 & 0xff) * 0x40;
      puVar45 = (uint *)(iVar1 + (local_78 & 0xff) * 0x40);
      iVar24 = iVar1 + (local_68 >> 0x10 & 0xff) * 0x40;
      local_a0[3] = *(uint *)(iVar24 + 0x14) ^
                    puVar61[1] ^ *(uint *)(iVar27 + 0xc) ^ *(uint *)(iVar77 + 0x3c) ^
                    *(uint *)(iVar18 + 0x34) ^ *(uint *)(iVar21 + 0x2c) ^ *(uint *)(iVar43 + 0x24) ^
                    *(uint *)(iVar15 + 0x1c) ^ local_54;
      local_a0[2] = *(uint *)(iVar24 + 0x10) ^
                    *puVar61 ^ *(uint *)(iVar27 + 8) ^ *(uint *)(iVar77 + 0x38) ^
                    *(uint *)(iVar18 + 0x30) ^ *(uint *)(iVar21 + 0x28) ^ *(uint *)(iVar43 + 0x20) ^
                    *(uint *)(iVar15 + 0x18) ^ local_58;
      iVar77 = iVar1 + (local_a0[4] >> 0x10 & 0xff) * 0x40;
      iVar70 = iVar1 + (local_a0[4] >> 0x18) * 0x40;
      iVar15 = iVar1 + (local_7c >> 0x10 & 0xff) * 0x40;
      iVar27 = iVar1 + (local_a0[4] >> 8 & 0xff) * 0x40;
      iVar18 = iVar1 + (local_74 >> 8 & 0xff) * 0x40;
      iVar21 = iVar1 + (local_6c & 0xff) * 0x40;
      iVar43 = iVar1 + (local_68 >> 0x18) * 0x40;
      local_a0[4] = *(uint *)(iVar43 + 0x18) ^
                    *(uint *)(iVar15 + 0x30) ^
                    *puVar28 ^ *(uint *)(iVar29 + 0x10) ^ *(uint *)(iVar38 + 8) ^
                    *(uint *)(iVar25 + 0x38) ^ *(uint *)(iVar18 + 0x28) ^ *(uint *)(iVar21 + 0x20) ^
                    local_50;
      uVar19 = *(uint *)(iVar43 + 0x1c) ^
               *(uint *)(iVar15 + 0x34) ^
               puVar28[1] ^ *(uint *)(iVar29 + 0x14) ^ *(uint *)(iVar38 + 0xc) ^
               *(uint *)(iVar25 + 0x3c) ^ *(uint *)(iVar18 + 0x2c) ^ *(uint *)(iVar21 + 0x24) ^
               local_4c;
      iVar64 = iVar1 + (local_a0[6] >> 0x10 & 0xff) * 0x40;
      iVar18 = iVar1 + (local_7c >> 0x18) * 0x40;
      iVar15 = iVar1 + (local_80 >> 8 & 0xff) * 0x40;
      iVar21 = iVar1 + (local_a0[5] & 0xff) * 0x40;
      iVar24 = iVar1 + (local_74 >> 0x10 & 0xff) * 0x40;
      iVar43 = iVar1 + (local_a0[6] >> 8 & 0xff) * 0x40;
      iVar25 = iVar1 + (local_6c >> 8 & 0xff) * 0x40;
      iVar59 = iVar1 + (local_64 & 0xff) * 0x40;
      uVar76 = *(uint *)(iVar59 + 0x20) ^
               *(uint *)(iVar18 + 0x38) ^
               *puVar47 ^ *(uint *)(iVar30 + 0x18) ^ *(uint *)(iVar31 + 0x10) ^
               *(uint *)(iVar27 + 8) ^ *(uint *)(iVar24 + 0x30) ^ *(uint *)(iVar25 + 0x28) ^
               local_48;
      local_84 = *(uint *)(iVar59 + 0x24) ^
                 *(uint *)(iVar18 + 0x3c) ^
                 puVar47[1] ^ *(uint *)(iVar30 + 0x1c) ^ *(uint *)(iVar31 + 0x14) ^
                 *(uint *)(iVar27 + 0xc) ^ *(uint *)(iVar24 + 0x34) ^ *(uint *)(iVar25 + 0x2c) ^
                 local_44;
      iVar29 = iVar1 + (local_a0[6] >> 0x18) * 0x40;
      iVar27 = iVar1 + (local_80 >> 0x10 & 0xff) * 0x40;
      iVar24 = iVar1 + (local_74 >> 0x18) * 0x40;
      iVar18 = iVar1 + (local_6c >> 0x18) * 0x40;
      iVar25 = iVar1 + (local_6c >> 0x10 & 0xff) * 0x40;
      iVar59 = iVar1 + (local_64 >> 8 & 0xff) * 0x40;
      local_80 = *(uint *)(iVar59 + 0x28) ^
                 *(uint *)(iVar77 + 0x10) ^
                 *puVar17 ^ *(uint *)(iVar32 + 0x20) ^ *(uint *)(iVar33 + 0x18) ^
                 *(uint *)(iVar43 + 8) ^ *(uint *)(iVar24 + 0x38) ^ *(uint *)(iVar25 + 0x30) ^
                 local_40;
      local_7c = *(uint *)(iVar59 + 0x2c) ^
                 *(uint *)(iVar77 + 0x14) ^
                 puVar17[1] ^ *(uint *)(iVar32 + 0x24) ^ *(uint *)(iVar33 + 0x1c) ^
                 *(uint *)(iVar43 + 0xc) ^ *(uint *)(iVar24 + 0x3c) ^ *(uint *)(iVar25 + 0x34) ^
                 local_3c;
      iVar24 = iVar1 + (local_78 >> 8 & 0xff) * 0x40;
      iVar25 = iVar1 + (local_64 >> 0x18) * 0x40;
      iVar43 = iVar1 + (local_64 >> 0x10 & 0xff) * 0x40;
      local_74 = *(uint *)(iVar64 + 0x14) ^
                 *(uint *)(iVar70 + 0x1c) ^
                 *(uint *)(iVar34 + 0x2c) ^ *(uint *)(iVar36 + 0x24) ^ puVar45[1] ^
                 *(uint *)(iVar15 + 0xc) ^ *(uint *)(iVar18 + 0x3c) ^ *(uint *)(iVar43 + 0x34) ^
                 local_34;
      local_78 = *(uint *)(iVar64 + 0x10) ^
                 *(uint *)(iVar70 + 0x18) ^
                 *(uint *)(iVar34 + 0x28) ^ *(uint *)(iVar36 + 0x20) ^ *puVar45 ^
                 *(uint *)(iVar15 + 8) ^ *(uint *)(iVar18 + 0x38) ^ *(uint *)(iVar43 + 0x30) ^
                 local_38;
      local_a0[5] = uVar19;
      local_70 = *(uint *)(iVar27 + 0x10) ^
                 *(uint *)(iVar37 + 0x28) ^ *(uint *)(iVar52 + 0x30) ^ *puVar22 ^
                 *(uint *)(iVar21 + 0x20) ^ *(uint *)(iVar29 + 0x18) ^ *(uint *)(iVar24 + 8) ^
                 *(uint *)(iVar25 + 0x38) ^ local_30;
      local_6c = *(uint *)(iVar27 + 0x14) ^
                 *(uint *)(iVar37 + 0x2c) ^ *(uint *)(iVar52 + 0x34) ^ puVar22[1] ^
                 *(uint *)(iVar21 + 0x24) ^ *(uint *)(iVar29 + 0x1c) ^ *(uint *)(iVar24 + 0xc) ^
                 *(uint *)(iVar25 + 0x3c) ^ local_2c;
      local_a0[6] = uVar76;
      local_68 = uVar51;
      local_64 = uVar58;
      local_10c = puVar42;
    } while (puVar42 != puVar35);
    if (((uint)local_f8 & 7) == 0) {
      uVar26 = local_f0[-0xf];
      *param_1 = local_f0[-0x10] ^ uVar14 ^ local_a0[0];
      param_1[1] = uVar26 ^ uVar16 ^ local_a0[1];
      uVar14 = local_f8[3];
      param_1[2] = local_f8[2] ^ uVar20 ^ local_a0[2];
      param_1[3] = uVar14 ^ uVar23 ^ local_a0[3];
      uVar14 = local_f8[5];
      param_1[4] = local_f8[4] ^ uVar2 ^ local_a0[4];
      param_1[5] = uVar14 ^ uVar3 ^ uVar19;
      uVar14 = local_f8[7];
      param_1[6] = local_f8[6] ^ uVar4 ^ uVar76;
      param_1[7] = uVar14 ^ uVar5 ^ local_84;
      uVar14 = local_f8[9];
      param_1[8] = local_f8[8] ^ uVar6 ^ local_80;
      param_1[9] = uVar14 ^ uVar7 ^ local_7c;
      uVar14 = local_f8[0xb];
      param_1[10] = local_f8[10] ^ uVar8 ^ local_78;
      param_1[0xb] = uVar14 ^ uVar9 ^ local_74;
      uVar14 = local_f8[0xd];
      param_1[0xc] = local_f8[0xc] ^ uVar10 ^ local_70;
      param_1[0xd] = uVar14 ^ uVar11 ^ local_6c;
      uVar14 = local_f8[0xf];
      param_1[0xe] = local_f8[0xe] ^ uVar12 ^ uVar51;
      param_1[0xf] = uVar14 ^ uVar13 ^ uVar58;
    }
    else if (((uint)local_f8 & 3) == 0 && (param_1 + 1 <= local_f8 || local_f8 + 1 <= param_1)) {
      *param_1 = local_f0[-0x10] ^ *param_1 ^ local_a0[0];
      param_1[1] = param_1[1] ^ local_a0[1] ^ local_f8[1];
      param_1[2] = param_1[2] ^ local_a0[2] ^ local_f8[2];
      param_1[3] = local_f8[3] ^ param_1[3] ^ local_a0[3];
      param_1[4] = local_f8[4] ^ param_1[4] ^ local_a0[4];
      param_1[5] = uVar19 ^ param_1[5] ^ local_f8[5];
      param_1[6] = local_f8[6] ^ param_1[6] ^ uVar76;
      param_1[7] = local_f8[7] ^ local_84 ^ param_1[7];
      param_1[8] = local_f8[8] ^ local_80 ^ param_1[8];
      param_1[9] = local_f8[9] ^ param_1[9] ^ local_7c;
      param_1[10] = param_1[10] ^ local_78 ^ local_f8[10];
      param_1[0xb] = param_1[0xb] ^ local_74 ^ local_f8[0xb];
      param_1[0xc] = local_f8[0xc] ^ param_1[0xc] ^ local_70;
      param_1[0xd] = local_f8[0xd] ^ param_1[0xd] ^ local_6c;
      param_1[0xe] = param_1[0xe] ^ uVar51 ^ local_f8[0xe];
      param_1[0xf] = local_f8[0xf] ^ param_1[0xf] ^ uVar58;
    }
    else {
      iVar15 = 0;
      do {
        *(byte *)((int)param_1 + iVar15) =
             *(byte *)((int)param_1 + iVar15) ^ *(byte *)((int)local_a0 + iVar15) ^
             *(byte *)((int)local_f8 + iVar15);
        iVar15 = iVar15 + 1;
      } while (iVar15 != 0x40);
    }
    local_f8 = local_f8 + 0x10;
    local_f0 = local_f0 + 0x10;
    local_ec = local_ec + -1;
  } while (local_ec != 0);
  return;
}

