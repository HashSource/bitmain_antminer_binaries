
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
  uint uVar56;
  uint uVar57;
  uint uVar58;
  uint uVar59;
  uint uVar60;
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
  int iVar74;
  uint *puVar75;
  uint *puVar76;
  uint uVar77;
  uint uVar78;
  uint uVar79;
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
  
  local_f0 = param_2 + 0x10;
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
      puVar75 = local_f0 + -0x10;
      puVar76 = local_a0;
      do {
        uVar68 = *puVar75;
        uVar69 = puVar75[1];
        uVar71 = puVar75[2];
        uVar72 = puVar75[3];
        puVar75 = puVar75 + 4;
        *puVar76 = uVar68;
        puVar76[1] = uVar69;
        puVar76[2] = uVar71;
        puVar76[3] = uVar72;
        puVar76 = puVar76 + 4;
      } while (puVar75 != local_f0);
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
    uVar67 = local_24;
    uVar66 = local_28;
    uVar65 = local_2c;
    uVar64 = local_30;
    uVar63 = local_34;
    uVar62 = local_38;
    uVar61 = local_3c;
    uVar60 = local_40;
    uVar59 = local_44;
    uVar58 = local_48;
    uVar57 = local_4c;
    uVar56 = local_50;
    uVar72 = local_54;
    uVar71 = local_58;
    uVar69 = local_5c;
    uVar68 = local_60;
    local_10c = (uint *)&DAT_0017ef70;
    do {
      iVar74 = (local_60 & 0xff) * 0x40;
      iVar1 = (local_54 >> 0x18) * 0x40;
      iVar2 = (local_4c >> 0x10 & 0xff) * 0x40;
      iVar3 = (local_44 >> 8 & 0xff) * 0x40;
      iVar4 = (local_3c & 0xff) * 0x40;
      iVar5 = (local_38 >> 0x18) * 0x40;
      iVar6 = (local_30 >> 0x10 & 0xff) * 0x40;
      iVar7 = (local_28 >> 8 & 0xff) * 0x40;
      puVar76 = local_10c + 2;
      iVar8 = (local_60 >> 0x10 & 0xff) * 0x40;
      iVar9 = (local_60 >> 8 & 0xff) * 0x40;
      iVar10 = (local_5c >> 8 & 0xff) * 0x40;
      iVar11 = (local_5c & 0xff) * 0x40;
      iVar12 = (local_60 >> 0x18) * 0x40;
      iVar13 = (local_50 & 0xff) * 0x40;
      iVar14 = (local_4c >> 0x18) * 0x40;
      iVar15 = (local_5c >> 0x10 & 0xff) * 0x40;
      iVar16 = (local_5c >> 0x18) * 0x40;
      iVar17 = (local_58 >> 8 & 0xff) * 0x40;
      iVar18 = (local_58 & 0xff) * 0x40;
      local_60 = *(uint *)(&DAT_0017afa8 + iVar2) ^
                 *puVar76 ^ *(uint *)(&Cx + iVar74) ^ *(uint *)(&DAT_0017afb0 + iVar1) ^
                 *(uint *)(&DAT_0017afa0 + iVar3) ^ *(uint *)(&DAT_0017af98 + iVar4) ^
                 *(uint *)(&DAT_0017af90 + iVar5) ^ *(uint *)(&DAT_0017af88 + iVar6) ^
                 *(uint *)(&DAT_0017af80 + iVar7);
      local_5c = *(uint *)(&DAT_0017afac + iVar2) ^
                 local_10c[3] ^ *(uint *)(&DAT_0017af7c + iVar74) ^ *(uint *)(&DAT_0017afb4 + iVar1)
                 ^ *(uint *)(&DAT_0017afa4 + iVar3) ^ *(uint *)(&DAT_0017af9c + iVar4) ^
                 *(uint *)(&DAT_0017af94 + iVar5) ^ *(uint *)(&DAT_0017af8c + iVar6) ^
                 *(uint *)(&DAT_0017af84 + iVar7);
      iVar74 = (local_58 >> 0x10 & 0xff) * 0x40;
      iVar1 = (local_48 & 0xff) * 0x40;
      iVar2 = (local_50 >> 8 & 0xff) * 0x40;
      iVar3 = (local_44 >> 0x18) * 0x40;
      iVar4 = (local_44 >> 0x10 & 0xff) * 0x40;
      iVar5 = (local_40 & 0xff) * 0x40;
      iVar6 = (local_58 >> 0x18) * 0x40;
      iVar7 = (local_50 >> 0x10 & 0xff) * 0x40;
      iVar19 = (local_48 >> 8 & 0xff) * 0x40;
      iVar20 = (local_3c >> 8 & 0xff) * 0x40;
      iVar21 = (local_3c >> 0x10 & 0xff) * 0x40;
      iVar22 = (local_3c >> 0x18) * 0x40;
      iVar23 = (local_54 & 0xff) * 0x40;
      iVar24 = (local_50 >> 0x18) * 0x40;
      iVar25 = (local_38 & 0xff) * 0x40;
      iVar26 = (local_48 >> 0x10 & 0xff) * 0x40;
      iVar27 = (local_34 >> 0x10 & 0xff) * 0x40;
      iVar28 = (local_34 & 0xff) * 0x40;
      iVar29 = (local_40 >> 8 & 0xff) * 0x40;
      iVar30 = (local_34 >> 8 & 0xff) * 0x40;
      iVar31 = (local_34 >> 0x18) * 0x40;
      iVar32 = (local_54 >> 8 & 0xff) * 0x40;
      iVar33 = (local_4c & 0xff) * 0x40;
      iVar34 = (local_30 & 0xff) * 0x40;
      iVar35 = (local_48 >> 0x18) * 0x40;
      iVar36 = (local_40 >> 0x10 & 0xff) * 0x40;
      iVar37 = (local_38 >> 8 & 0xff) * 0x40;
      iVar38 = (local_30 >> 0x18) * 0x40;
      iVar39 = (local_2c & 0xff) * 0x40;
      iVar40 = (local_2c >> 8 & 0xff) * 0x40;
      iVar41 = (local_54 >> 0x10 & 0xff) * 0x40;
      iVar42 = (local_2c >> 0x10 & 0xff) * 0x40;
      iVar43 = (local_28 & 0xff) * 0x40;
      iVar44 = (local_2c >> 0x18) * 0x40;
      iVar45 = (local_44 & 0xff) * 0x40;
      iVar46 = (local_4c >> 8 & 0xff) * 0x40;
      iVar47 = (local_40 >> 0x18) * 0x40;
      iVar48 = (local_30 >> 8 & 0xff) * 0x40;
      iVar49 = (local_38 >> 0x10 & 0xff) * 0x40;
      iVar50 = (local_24 >> 8 & 0xff) * 0x40;
      iVar51 = (local_24 >> 0x10 & 0xff) * 0x40;
      iVar52 = (local_28 >> 0x10 & 0xff) * 0x40;
      iVar53 = (local_28 >> 0x18) * 0x40;
      iVar54 = (local_24 & 0xff) * 0x40;
      iVar55 = (local_24 >> 0x18) * 0x40;
      local_24 = *(uint *)(&DAT_0017af9c + iVar45) ^
                 *(uint *)(&DAT_0017afac + iVar41) ^ *(uint *)(&DAT_0017afb4 + iVar16) ^
                 *(uint *)(&DAT_0017af7c + iVar43) ^ *(uint *)(&DAT_0017afa4 + iVar46) ^
                 *(uint *)(&DAT_0017af94 + iVar47) ^ *(uint *)(&DAT_0017af8c + iVar49) ^
                 *(uint *)(&DAT_0017af84 + iVar48);
      local_28 = *(uint *)(&DAT_0017af98 + iVar45) ^
                 *(uint *)(&DAT_0017afa8 + iVar41) ^ *(uint *)(&DAT_0017afb0 + iVar16) ^
                 *(uint *)(&Cx + iVar43) ^ *(uint *)(&DAT_0017afa0 + iVar46) ^
                 *(uint *)(&DAT_0017af90 + iVar47) ^ *(uint *)(&DAT_0017af88 + iVar49) ^
                 *(uint *)(&DAT_0017af80 + iVar48);
      local_54 = *(uint *)(&DAT_0017afb4 + iVar14) ^ *(uint *)(&DAT_0017af84 + iVar9) ^
                 *(uint *)(&DAT_0017af7c + iVar18) ^ *(uint *)(&DAT_0017afac + iVar4) ^
                 *(uint *)(&DAT_0017afa4 + iVar20) ^ *(uint *)(&DAT_0017af9c + iVar28) ^
                 *(uint *)(&DAT_0017af94 + iVar38) ^ *(uint *)(&DAT_0017af8c + iVar52);
      local_58 = *(uint *)(&DAT_0017afb0 + iVar14) ^ *(uint *)(&DAT_0017af80 + iVar9) ^
                 *(uint *)(&Cx + iVar18) ^ *(uint *)(&DAT_0017afa8 + iVar4) ^
                 *(uint *)(&DAT_0017afa0 + iVar20) ^ *(uint *)(&DAT_0017af98 + iVar28) ^
                 *(uint *)(&DAT_0017af90 + iVar38) ^ *(uint *)(&DAT_0017af88 + iVar52);
      local_50 = *(uint *)(&DAT_0017af80 + iVar17) ^ *(uint *)(&DAT_0017af88 + iVar8) ^
                 *(uint *)(&Cx + iVar13) ^ *(uint *)(&DAT_0017afb0 + iVar3) ^
                 *(uint *)(&DAT_0017afa8 + iVar21) ^ *(uint *)(&DAT_0017afa0 + iVar30) ^
                 *(uint *)(&DAT_0017af98 + iVar39) ^ *(uint *)(&DAT_0017af90 + iVar53);
      local_4c = *(uint *)(&DAT_0017af84 + iVar17) ^ *(uint *)(&DAT_0017af8c + iVar8) ^
                 *(uint *)(&DAT_0017af7c + iVar13) ^ *(uint *)(&DAT_0017afb4 + iVar3) ^
                 *(uint *)(&DAT_0017afac + iVar21) ^ *(uint *)(&DAT_0017afa4 + iVar30) ^
                 *(uint *)(&DAT_0017af9c + iVar39) ^ *(uint *)(&DAT_0017af94 + iVar53);
      local_48 = *(uint *)(&DAT_0017af88 + iVar74) ^ *(uint *)(&DAT_0017af90 + iVar12) ^
                 *(uint *)(&Cx + iVar1) ^ *(uint *)(&DAT_0017af80 + iVar2) ^
                 *(uint *)(&DAT_0017afb0 + iVar22) ^ *(uint *)(&DAT_0017afa8 + iVar27) ^
                 *(uint *)(&DAT_0017afa0 + iVar40) ^ *(uint *)(&DAT_0017af98 + iVar54);
      local_44 = *(uint *)(&DAT_0017af8c + iVar74) ^ *(uint *)(&DAT_0017af94 + iVar12) ^
                 *(uint *)(&DAT_0017af7c + iVar1) ^ *(uint *)(&DAT_0017af84 + iVar2) ^
                 *(uint *)(&DAT_0017afb4 + iVar22) ^ *(uint *)(&DAT_0017afac + iVar27) ^
                 *(uint *)(&DAT_0017afa4 + iVar40) ^ *(uint *)(&DAT_0017af9c + iVar54);
      local_40 = *(uint *)(&DAT_0017af90 + iVar6) ^ *(uint *)(&DAT_0017af98 + iVar11) ^
                 *(uint *)(&Cx + iVar5) ^ *(uint *)(&DAT_0017af88 + iVar7) ^
                 *(uint *)(&DAT_0017af80 + iVar19) ^ *(uint *)(&DAT_0017afb0 + iVar31) ^
                 *(uint *)(&DAT_0017afa8 + iVar42) ^ *(uint *)(&DAT_0017afa0 + iVar50);
      local_3c = *(uint *)(&DAT_0017af94 + iVar6) ^ *(uint *)(&DAT_0017af9c + iVar11) ^
                 *(uint *)(&DAT_0017af7c + iVar5) ^ *(uint *)(&DAT_0017af8c + iVar7) ^
                 *(uint *)(&DAT_0017af84 + iVar19) ^ *(uint *)(&DAT_0017afb4 + iVar31) ^
                 *(uint *)(&DAT_0017afac + iVar42) ^ *(uint *)(&DAT_0017afa4 + iVar50);
      local_38 = *(uint *)(&DAT_0017af90 + iVar24) ^
                 *(uint *)(&DAT_0017af98 + iVar23) ^ *(uint *)(&DAT_0017afa0 + iVar10) ^
                 *(uint *)(&Cx + iVar25) ^ *(uint *)(&DAT_0017af88 + iVar26) ^
                 *(uint *)(&DAT_0017af80 + iVar29) ^ *(uint *)(&DAT_0017afb0 + iVar44) ^
                 *(uint *)(&DAT_0017afa8 + iVar51);
      local_34 = *(uint *)(&DAT_0017af94 + iVar24) ^
                 *(uint *)(&DAT_0017af9c + iVar23) ^ *(uint *)(&DAT_0017afa4 + iVar10) ^
                 *(uint *)(&DAT_0017af7c + iVar25) ^ *(uint *)(&DAT_0017af8c + iVar26) ^
                 *(uint *)(&DAT_0017af84 + iVar29) ^ *(uint *)(&DAT_0017afb4 + iVar44) ^
                 *(uint *)(&DAT_0017afac + iVar51);
      iVar74 = (local_a0[3] >> 0x18) * 0x40;
      iVar1 = (local_a0[5] >> 0x10 & 0xff) * 0x40;
      iVar2 = (local_a0[5] >> 0x18) * 0x40;
      local_30 = *(uint *)(&DAT_0017afa0 + iVar32) ^ *(uint *)(&DAT_0017afa8 + iVar15) ^
                 *(uint *)(&Cx + iVar34) ^ *(uint *)(&DAT_0017af98 + iVar33) ^
                 *(uint *)(&DAT_0017af90 + iVar35) ^ *(uint *)(&DAT_0017af88 + iVar36) ^
                 *(uint *)(&DAT_0017af80 + iVar37) ^ *(uint *)(&DAT_0017afb0 + iVar55);
      local_2c = *(uint *)(&DAT_0017afa4 + iVar32) ^ *(uint *)(&DAT_0017afac + iVar15) ^
                 *(uint *)(&DAT_0017af7c + iVar34) ^ *(uint *)(&DAT_0017af9c + iVar33) ^
                 *(uint *)(&DAT_0017af94 + iVar35) ^ *(uint *)(&DAT_0017af8c + iVar36) ^
                 *(uint *)(&DAT_0017af84 + iVar37) ^ *(uint *)(&DAT_0017afb4 + iVar55);
      iVar3 = (local_a0[0] >> 0x10 & 0xff) * 0x40;
      iVar4 = (local_a0[1] >> 0x18) * 0x40;
      iVar5 = (local_a0[3] >> 0x10 & 0xff) * 0x40;
      iVar6 = (local_a0[0] >> 8 & 0xff) * 0x40;
      iVar7 = (local_a0[2] >> 8 & 0xff) * 0x40;
      iVar8 = (local_a0[0] >> 0x18) * 0x40;
      iVar9 = (local_a0[0] & 0xff) * 0x40;
      iVar10 = (local_a0[2] >> 0x10 & 0xff) * 0x40;
      iVar11 = (local_a0[1] & 0xff) * 0x40;
      iVar12 = (local_84 >> 8 & 0xff) * 0x40;
      iVar13 = (local_a0[2] >> 0x18) * 0x40;
      iVar14 = (local_7c & 0xff) * 0x40;
      iVar15 = (local_a0[1] >> 8 & 0xff) * 0x40;
      iVar16 = (local_a0[3] & 0xff) * 0x40;
      iVar17 = (local_78 >> 0x18) * 0x40;
      iVar18 = (local_a0[1] >> 0x10 & 0xff) * 0x40;
      iVar19 = (local_a0[3] >> 8 & 0xff) * 0x40;
      iVar20 = (local_a0[2] & 0xff) * 0x40;
      iVar21 = (local_68 & 0xff) * 0x40;
      iVar22 = (local_70 >> 0x10 & 0xff) * 0x40;
      iVar23 = (local_68 >> 8 & 0xff) * 0x40;
      local_a0[0] = *(uint *)(&DAT_0017af80 + iVar23) ^
                    *(uint *)(&DAT_0017afb0 + iVar74) ^ *(uint *)(&DAT_0017afa8 + iVar1) ^
                    *(uint *)(&Cx + iVar9) ^ *(uint *)(&DAT_0017afa0 + iVar12) ^
                    *(uint *)(&DAT_0017af98 + iVar14) ^ *(uint *)(&DAT_0017af90 + iVar17) ^
                    *(uint *)(&DAT_0017af88 + iVar22) ^ local_60;
      local_a0[1] = *(uint *)(&DAT_0017af84 + iVar23) ^
                    *(uint *)(&DAT_0017afb4 + iVar74) ^ *(uint *)(&DAT_0017afac + iVar1) ^
                    *(uint *)(&DAT_0017af7c + iVar9) ^ *(uint *)(&DAT_0017afa4 + iVar12) ^
                    *(uint *)(&DAT_0017af9c + iVar14) ^ *(uint *)(&DAT_0017af94 + iVar17) ^
                    *(uint *)(&DAT_0017af8c + iVar22) ^ local_5c;
      iVar74 = (local_a0[5] >> 8 & 0xff) * 0x40;
      iVar1 = (local_80 & 0xff) * 0x40;
      iVar9 = (local_a0[6] & 0xff) * 0x40;
      iVar12 = (local_a0[4] & 0xff) * 0x40;
      iVar14 = (local_84 & 0xff) * 0x40;
      iVar17 = (local_80 >> 0x18) * 0x40;
      iVar22 = (local_78 >> 0x10 & 0xff) * 0x40;
      iVar23 = (local_70 >> 8 & 0xff) * 0x40;
      uVar77 = *(uint *)(&DAT_0017af80 + iVar23) ^
               *(uint *)(&DAT_0017afa0 + iVar74) ^
               *(uint *)(&DAT_0017afb0 + iVar4) ^ *(uint *)(&DAT_0017afa8 + iVar5) ^
               *(uint *)(&Cx + iVar21) ^ *(uint *)(&DAT_0017af98 + iVar14) ^
               *(uint *)(&DAT_0017af90 + iVar17) ^ *(uint *)(&DAT_0017af88 + iVar22) ^ local_28;
      uVar78 = *(uint *)(&DAT_0017af84 + iVar23) ^
               *(uint *)(&DAT_0017afa4 + iVar74) ^
               *(uint *)(&DAT_0017afb4 + iVar4) ^ *(uint *)(&DAT_0017afac + iVar5) ^
               *(uint *)(&DAT_0017af7c + iVar21) ^ *(uint *)(&DAT_0017af9c + iVar14) ^
               *(uint *)(&DAT_0017af94 + iVar17) ^ *(uint *)(&DAT_0017af8c + iVar22) ^ local_24;
      iVar74 = (local_70 & 0xff) * 0x40;
      iVar4 = (local_84 >> 0x18) * 0x40;
      iVar5 = (local_84 >> 0x10 & 0xff) * 0x40;
      iVar14 = (local_70 >> 0x18) * 0x40;
      iVar17 = (local_7c >> 8 & 0xff) * 0x40;
      iVar21 = (local_74 & 0xff) * 0x40;
      iVar22 = (local_78 & 0xff) * 0x40;
      iVar23 = (local_68 >> 0x10 & 0xff) * 0x40;
      local_a0[3] = *(uint *)(&DAT_0017af8c + iVar23) ^
                    *(uint *)(&DAT_0017af7c + iVar20) ^
                    *(uint *)(&DAT_0017af84 + iVar6) ^ *(uint *)(&DAT_0017afb4 + iVar2) ^
                    *(uint *)(&DAT_0017afac + iVar5) ^ *(uint *)(&DAT_0017afa4 + iVar17) ^
                    *(uint *)(&DAT_0017af9c + iVar21) ^ *(uint *)(&DAT_0017af94 + iVar14) ^ local_54
      ;
      local_a0[2] = *(uint *)(&DAT_0017af88 + iVar23) ^
                    *(uint *)(&Cx + iVar20) ^
                    *(uint *)(&DAT_0017af80 + iVar6) ^ *(uint *)(&DAT_0017afb0 + iVar2) ^
                    *(uint *)(&DAT_0017afa8 + iVar5) ^ *(uint *)(&DAT_0017afa0 + iVar17) ^
                    *(uint *)(&DAT_0017af98 + iVar21) ^ *(uint *)(&DAT_0017af90 + iVar14) ^ local_58
      ;
      iVar2 = (local_a0[4] >> 0x10 & 0xff) * 0x40;
      iVar5 = (local_a0[4] >> 0x18) * 0x40;
      iVar6 = (local_7c >> 0x10 & 0xff) * 0x40;
      iVar14 = (local_a0[4] >> 8 & 0xff) * 0x40;
      iVar17 = (local_74 >> 8 & 0xff) * 0x40;
      iVar20 = (local_6c & 0xff) * 0x40;
      iVar21 = (local_68 >> 0x18) * 0x40;
      local_a0[4] = *(uint *)(&DAT_0017af90 + iVar21) ^
                    *(uint *)(&DAT_0017afa8 + iVar6) ^
                    *(uint *)(&Cx + iVar12) ^
                    *(uint *)(&DAT_0017af88 + iVar3) ^ *(uint *)(&DAT_0017af80 + iVar7) ^
                    *(uint *)(&DAT_0017afb0 + iVar4) ^ *(uint *)(&DAT_0017afa0 + iVar17) ^
                    *(uint *)(&DAT_0017af98 + iVar20) ^ local_50;
      uVar70 = *(uint *)(&DAT_0017af94 + iVar21) ^
               *(uint *)(&DAT_0017afac + iVar6) ^
               *(uint *)(&DAT_0017af7c + iVar12) ^
               *(uint *)(&DAT_0017af8c + iVar3) ^ *(uint *)(&DAT_0017af84 + iVar7) ^
               *(uint *)(&DAT_0017afb4 + iVar4) ^ *(uint *)(&DAT_0017afa4 + iVar17) ^
               *(uint *)(&DAT_0017af9c + iVar20) ^ local_4c;
      iVar3 = (local_a0[6] >> 0x10 & 0xff) * 0x40;
      iVar4 = (local_7c >> 0x18) * 0x40;
      iVar6 = (local_80 >> 8 & 0xff) * 0x40;
      iVar7 = (local_a0[5] & 0xff) * 0x40;
      iVar12 = (local_74 >> 0x10 & 0xff) * 0x40;
      iVar17 = (local_a0[6] >> 8 & 0xff) * 0x40;
      iVar20 = (local_6c >> 8 & 0xff) * 0x40;
      iVar21 = (local_64 & 0xff) * 0x40;
      uVar79 = *(uint *)(&DAT_0017af98 + iVar21) ^
               *(uint *)(&DAT_0017afb0 + iVar4) ^
               *(uint *)(&Cx + iVar9) ^
               *(uint *)(&DAT_0017af90 + iVar8) ^ *(uint *)(&DAT_0017af88 + iVar10) ^
               *(uint *)(&DAT_0017af80 + iVar14) ^ *(uint *)(&DAT_0017afa8 + iVar12) ^
               *(uint *)(&DAT_0017afa0 + iVar20) ^ local_48;
      local_84 = *(uint *)(&DAT_0017af9c + iVar21) ^
                 *(uint *)(&DAT_0017afb4 + iVar4) ^
                 *(uint *)(&DAT_0017af7c + iVar9) ^
                 *(uint *)(&DAT_0017af94 + iVar8) ^ *(uint *)(&DAT_0017af8c + iVar10) ^
                 *(uint *)(&DAT_0017af84 + iVar14) ^ *(uint *)(&DAT_0017afac + iVar12) ^
                 *(uint *)(&DAT_0017afa4 + iVar20) ^ local_44;
      iVar4 = (local_a0[6] >> 0x18) * 0x40;
      iVar8 = (local_80 >> 0x10 & 0xff) * 0x40;
      iVar9 = (local_74 >> 0x18) * 0x40;
      iVar10 = (local_6c >> 0x18) * 0x40;
      iVar12 = (local_6c >> 0x10 & 0xff) * 0x40;
      iVar14 = (local_64 >> 8 & 0xff) * 0x40;
      local_80 = *(uint *)(&DAT_0017afa0 + iVar14) ^
                 *(uint *)(&DAT_0017af88 + iVar2) ^
                 *(uint *)(&Cx + iVar1) ^
                 *(uint *)(&DAT_0017af98 + iVar11) ^ *(uint *)(&DAT_0017af90 + iVar13) ^
                 *(uint *)(&DAT_0017af80 + iVar17) ^ *(uint *)(&DAT_0017afb0 + iVar9) ^
                 *(uint *)(&DAT_0017afa8 + iVar12) ^ local_40;
      local_7c = *(uint *)(&DAT_0017afa4 + iVar14) ^
                 *(uint *)(&DAT_0017af8c + iVar2) ^
                 *(uint *)(&DAT_0017af7c + iVar1) ^
                 *(uint *)(&DAT_0017af9c + iVar11) ^ *(uint *)(&DAT_0017af94 + iVar13) ^
                 *(uint *)(&DAT_0017af84 + iVar17) ^ *(uint *)(&DAT_0017afb4 + iVar9) ^
                 *(uint *)(&DAT_0017afac + iVar12) ^ local_3c;
      iVar1 = (local_78 >> 8 & 0xff) * 0x40;
      iVar2 = (local_64 >> 0x18) * 0x40;
      iVar9 = (local_64 >> 0x10 & 0xff) * 0x40;
      local_74 = *(uint *)(&DAT_0017af8c + iVar3) ^
                 *(uint *)(&DAT_0017af94 + iVar5) ^
                 *(uint *)(&DAT_0017afa4 + iVar15) ^ *(uint *)(&DAT_0017af9c + iVar16) ^
                 *(uint *)(&DAT_0017af7c + iVar22) ^ *(uint *)(&DAT_0017af84 + iVar6) ^
                 *(uint *)(&DAT_0017afb4 + iVar10) ^ *(uint *)(&DAT_0017afac + iVar9) ^ local_34;
      local_78 = *(uint *)(&DAT_0017af88 + iVar3) ^
                 *(uint *)(&DAT_0017af90 + iVar5) ^
                 *(uint *)(&DAT_0017afa0 + iVar15) ^ *(uint *)(&DAT_0017af98 + iVar16) ^
                 *(uint *)(&Cx + iVar22) ^ *(uint *)(&DAT_0017af80 + iVar6) ^
                 *(uint *)(&DAT_0017afb0 + iVar10) ^ *(uint *)(&DAT_0017afa8 + iVar9) ^ local_38;
      local_a0[5] = uVar70;
      local_70 = *(uint *)(&DAT_0017af88 + iVar8) ^
                 *(uint *)(&DAT_0017afa0 + iVar19) ^ *(uint *)(&DAT_0017afa8 + iVar18) ^
                 *(uint *)(&Cx + iVar74) ^ *(uint *)(&DAT_0017af98 + iVar7) ^
                 *(uint *)(&DAT_0017af90 + iVar4) ^ *(uint *)(&DAT_0017af80 + iVar1) ^
                 *(uint *)(&DAT_0017afb0 + iVar2) ^ local_30;
      local_6c = *(uint *)(&DAT_0017af8c + iVar8) ^
                 *(uint *)(&DAT_0017afa4 + iVar19) ^ *(uint *)(&DAT_0017afac + iVar18) ^
                 *(uint *)(&DAT_0017af7c + iVar74) ^ *(uint *)(&DAT_0017af9c + iVar7) ^
                 *(uint *)(&DAT_0017af94 + iVar4) ^ *(uint *)(&DAT_0017af84 + iVar1) ^
                 *(uint *)(&DAT_0017afb4 + iVar2) ^ local_2c;
      local_a0[6] = uVar79;
      local_68 = uVar77;
      local_64 = uVar78;
      local_10c = puVar76;
    } while (puVar76 != (uint *)&DAT_0017efc0);
    if (((uint)local_f8 & 7) == 0) {
      uVar73 = local_f0[-0xf];
      *param_1 = local_f0[-0x10] ^ uVar68 ^ local_a0[0];
      param_1[1] = uVar73 ^ uVar69 ^ local_a0[1];
      uVar68 = local_f8[3];
      param_1[2] = local_f8[2] ^ uVar71 ^ local_a0[2];
      param_1[3] = uVar68 ^ uVar72 ^ local_a0[3];
      uVar68 = local_f8[5];
      param_1[4] = local_f8[4] ^ uVar56 ^ local_a0[4];
      param_1[5] = uVar68 ^ uVar57 ^ uVar70;
      uVar68 = local_f8[7];
      param_1[6] = local_f8[6] ^ uVar58 ^ uVar79;
      param_1[7] = uVar68 ^ uVar59 ^ local_84;
      uVar68 = local_f8[9];
      param_1[8] = local_f8[8] ^ uVar60 ^ local_80;
      param_1[9] = uVar68 ^ uVar61 ^ local_7c;
      uVar68 = local_f8[0xb];
      param_1[10] = local_f8[10] ^ uVar62 ^ local_78;
      param_1[0xb] = uVar68 ^ uVar63 ^ local_74;
      uVar68 = local_f8[0xd];
      param_1[0xc] = local_f8[0xc] ^ uVar64 ^ local_70;
      param_1[0xd] = uVar68 ^ uVar65 ^ local_6c;
      uVar68 = local_f8[0xf];
      param_1[0xe] = local_f8[0xe] ^ uVar66 ^ uVar77;
      param_1[0xf] = uVar68 ^ uVar67 ^ uVar78;
    }
    else if (((uint)local_f8 & 3) == 0 && (param_1 + 1 <= local_f8 || local_f8 + 1 <= param_1)) {
      *param_1 = local_f0[-0x10] ^ *param_1 ^ local_a0[0];
      param_1[1] = param_1[1] ^ local_a0[1] ^ local_f8[1];
      param_1[2] = param_1[2] ^ local_a0[2] ^ local_f8[2];
      param_1[3] = local_f8[3] ^ param_1[3] ^ local_a0[3];
      param_1[4] = local_f8[4] ^ param_1[4] ^ local_a0[4];
      param_1[5] = uVar70 ^ param_1[5] ^ local_f8[5];
      param_1[6] = local_f8[6] ^ param_1[6] ^ uVar79;
      param_1[7] = local_f8[7] ^ local_84 ^ param_1[7];
      param_1[8] = local_f8[8] ^ local_80 ^ param_1[8];
      param_1[9] = local_f8[9] ^ param_1[9] ^ local_7c;
      param_1[10] = param_1[10] ^ local_78 ^ local_f8[10];
      param_1[0xb] = param_1[0xb] ^ local_74 ^ local_f8[0xb];
      param_1[0xc] = local_f8[0xc] ^ param_1[0xc] ^ local_70;
      param_1[0xd] = local_f8[0xd] ^ param_1[0xd] ^ local_6c;
      param_1[0xe] = param_1[0xe] ^ uVar77 ^ local_f8[0xe];
      param_1[0xf] = local_f8[0xf] ^ param_1[0xf] ^ uVar78;
    }
    else {
      iVar74 = 0;
      do {
        *(byte *)((int)param_1 + iVar74) =
             *(byte *)((int)param_1 + iVar74) ^ *(byte *)((int)local_a0 + iVar74) ^
             *(byte *)((int)local_f8 + iVar74);
        iVar74 = iVar74 + 1;
      } while (iVar74 != 0x40);
    }
    local_f8 = local_f8 + 0x10;
    local_f0 = local_f0 + 0x10;
    local_ec = local_ec + -1;
  } while (local_ec != 0);
  return;
}

