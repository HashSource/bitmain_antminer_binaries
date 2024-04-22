
void blake2b_compress(byte *param_1,int param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte bVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  byte *pbVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  undefined4 *puVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  uint uVar46;
  uint uVar47;
  uint uVar48;
  uint uVar49;
  uint uVar50;
  undefined4 *puVar51;
  uint local_338;
  uint local_334;
  uint local_330;
  uint uStack_32c;
  uint local_328;
  uint uStack_324;
  uint local_320;
  uint uStack_31c;
  uint local_318;
  uint local_314;
  uint local_310;
  uint local_30c;
  uint local_308;
  uint uStack_304;
  uint local_300;
  uint uStack_2fc;
  uint local_2f8;
  uint local_2f4;
  uint local_2f0;
  uint local_2ec;
  uint local_2e8;
  uint local_2e4;
  uint local_2d8;
  uint local_2d4;
  uint local_2c8;
  uint local_2c4;
  uint local_2c0;
  uint local_2bc;
  uint local_2b8;
  uint local_2b4;
  undefined4 local_1f0;
  byte *local_1ec;
  uint local_1e8 [7];
  uint uStack_1cc;
  uint local_1c8;
  uint uStack_1c4;
  uint local_1c0;
  uint uStack_1bc;
  uint local_1b8;
  uint uStack_1b4;
  uint local_1b0;
  uint uStack_1ac;
  uint local_1a8 [7];
  uint uStack_18c;
  uint local_188;
  uint uStack_184;
  uint local_180;
  uint uStack_17c;
  uint local_178;
  uint uStack_174;
  uint local_170;
  uint uStack_16c;
  uint local_168 [32];
  byte local_e8 [196];
  
  iVar20 = 8;
  local_1ec = param_1;
  memcpy(local_e8,DAT_0000896c,0xc0);
  puVar6 = &local_1b0;
  puVar26 = (undefined4 *)(local_1ec + 0x78);
  puVar9 = DAT_00008970;
  puVar51 = &local_1f0;
  do {
    uVar7 = puVar26[3];
    iVar20 = iVar20 + -1;
    uVar10 = puVar9[2];
    uVar15 = puVar9[3];
    puVar51[2] = puVar26[2];
    puVar51[3] = uVar7;
    puVar6[2] = uVar10;
    puVar6[3] = uVar15;
    puVar6 = puVar6 + 2;
    puVar26 = puVar26 + 2;
    puVar9 = puVar9 + 2;
    puVar51 = puVar51 + 2;
  } while (iVar20 != 0);
  local_2bc = *(uint *)(local_1ec + 0xc4) ^ uStack_184;
  local_2c0 = *(uint *)(local_1ec + 0xc0) ^ local_188;
  local_188 = local_2c0;
  uStack_184 = local_2bc;
  local_2b8 = *(uint *)(local_1ec + 200) ^ local_180;
  local_2b4 = *(uint *)(local_1ec + 0xcc) ^ uStack_17c;
  local_180 = local_2b8;
  uStack_17c = local_2b4;
  if (param_2 == 0) {
    local_2c8 = local_178;
    local_2c4 = uStack_174;
  }
  else {
    local_2c8 = ~local_178;
    local_2c4 = ~uStack_174;
    local_178 = local_2c8;
    uStack_174 = local_2c4;
  }
  pbVar21 = local_1ec;
  puVar6 = &local_170;
  do {
    pbVar3 = pbVar21 + 2;
    pbVar1 = pbVar21 + 1;
    pbVar4 = pbVar21 + 3;
    bVar5 = *pbVar21;
    uVar10 = *(uint *)(pbVar21 + 4);
    pbVar21 = pbVar21 + 8;
    puVar9 = puVar6 + 2;
    *puVar9 = (uint)bVar5 ^ (uint)*pbVar1 << 8 ^ (uint)*pbVar3 << 0x10 ^ (uint)*pbVar4 << 0x18;
    puVar6[3] = uVar10;
    puVar6 = puVar9;
  } while (puVar9 != local_168 + 0x1e);
  local_300 = local_1e8[2];
  uStack_2fc = local_1e8[3];
  local_2d8 = local_1e8[0];
  local_2d4 = local_1e8[1];
  local_2e8 = local_1c8;
  local_2e4 = uStack_1c4;
  pbVar21 = local_e8;
  local_308 = local_1a8[4];
  uStack_304 = local_1a8[5];
  local_338 = local_1a8[0];
  local_334 = local_1a8[1];
  local_310 = local_1c0;
  local_30c = uStack_1bc;
  local_330 = local_1e8[4];
  uStack_32c = local_1e8[5];
  local_2f8 = local_1b8;
  local_2f4 = uStack_1b4;
  local_328 = local_1a8[6];
  uStack_324 = uStack_18c;
  local_320 = local_1e8[6];
  uStack_31c = uStack_1cc;
  local_2f0 = local_1b0;
  local_2ec = uStack_1ac;
  local_318 = local_170;
  local_314 = uStack_16c;
  do {
    uVar10 = local_168[(uint)pbVar21[2] * 2] + local_310;
    uVar27 = uVar10 + local_300;
    uVar38 = local_168[(uint)pbVar21[2] * 2 + 1] +
             local_30c + CARRY4(local_168[(uint)pbVar21[2] * 2],local_310) +
             uStack_2fc + CARRY4(uVar10,local_300);
    local_2b4 = local_2b4 ^ uVar38;
    uVar44 = local_1a8[2] + local_2b4;
    local_1a8[3] = local_1a8[3] + (local_2b8 ^ uVar27) + (uint)CARRY4(local_1a8[2],local_2b4);
    uVar15 = local_168[(uint)pbVar21[3] * 2] + uVar27;
    local_30c = local_1a8[3] ^ local_30c;
    uVar28 = local_30c >> 0x18 | (uVar44 ^ local_310) << 8;
    uVar10 = local_168[(uint)pbVar21[6] * 2] + local_2f0;
    uVar11 = (uVar44 ^ local_310) >> 0x18 | local_30c << 8;
    uVar29 = uVar10 + local_320;
    uVar39 = local_168[(uint)pbVar21[6] * 2 + 1] +
             local_2ec + CARRY4(local_168[(uint)pbVar21[6] * 2],local_2f0) +
             uStack_31c + CARRY4(uVar10,local_320);
    uVar10 = local_168[(uint)pbVar21[4] * 2] + local_2f8;
    uVar30 = uVar10 + local_330;
    uVar40 = local_168[(uint)pbVar21[4] * 2 + 1] +
             local_2f4 + CARRY4(local_168[(uint)pbVar21[4] * 2],local_2f8) +
             uStack_32c + CARRY4(uVar10,local_330);
    uVar31 = uVar15 + uVar11;
    uVar41 = local_168[(uint)pbVar21[3] * 2 + 1] +
             uVar38 + CARRY4(local_168[(uint)pbVar21[3] * 2],uVar27) +
             uVar28 + CARRY4(uVar15,uVar11);
    local_314 = local_314 ^ uVar39;
    uVar15 = uVar41 ^ local_2b8 ^ uVar27;
    uVar27 = local_2e8 + local_168[(uint)*pbVar21 * 2];
    uVar22 = local_328 + local_314;
    uStack_324 = uStack_324 + (local_318 ^ uVar29) + (uint)CARRY4(local_328,local_314);
    uVar10 = uVar27 + local_2d8;
    uVar23 = uVar15 >> 0x10 | (uVar31 ^ local_2b4) << 0x10;
    uVar8 = local_2e4 +
            local_168[(uint)*pbVar21 * 2 + 1] +
            (uint)CARRY4(local_2e8,local_168[(uint)*pbVar21 * 2]) +
            local_2d4 + CARRY4(uVar27,local_2d8);
    uVar12 = (uVar31 ^ local_2b4) >> 0x10 | uVar15 << 0x10;
    local_2c4 = local_2c4 ^ uVar40;
    uVar32 = local_308 + local_2c4;
    uStack_304 = uStack_304 + (local_2c8 ^ uVar30) + (uint)CARRY4(local_308,local_2c4);
    local_2bc = local_2bc ^ uVar8;
    local_2ec = uStack_324 ^ local_2ec;
    uVar16 = local_2ec >> 0x18 | (uVar22 ^ local_2f0) << 8;
    uVar33 = local_338 + local_2bc;
    local_334 = local_334 + (local_2c0 ^ uVar10) + (uint)CARRY4(local_338,local_2bc);
    uVar15 = (uVar22 ^ local_2f0) >> 0x18 | local_2ec << 8;
    uVar34 = uVar12 + uVar44;
    uVar42 = uVar23 + local_1a8[3] + CARRY4(uVar12,uVar44);
    local_2f4 = uStack_304 ^ local_2f4;
    uVar44 = local_2f4 >> 0x18 | (uVar32 ^ local_2f8) << 8;
    uVar28 = uVar42 ^ uVar28;
    uVar27 = uVar29 + local_168[(uint)pbVar21[7] * 2];
    uVar17 = uVar31 + local_168[(uint)pbVar21[10] * 2];
    uVar18 = uVar28 << 1 | (uVar34 ^ uVar11) >> 0x1f;
    uVar13 = (uVar34 ^ uVar11) << 1 | uVar28 >> 0x1f;
    uVar25 = (uVar32 ^ local_2f8) >> 0x18 | local_2f4 << 8;
    uVar11 = uVar27 + uVar15;
    uVar39 = uVar39 + local_168[(uint)pbVar21[7] * 2 + 1] +
                      (uint)CARRY4(uVar29,local_168[(uint)pbVar21[7] * 2]) +
             uVar16 + CARRY4(uVar27,uVar15);
    local_2e4 = local_334 ^ local_2e4;
    uVar35 = (uVar33 ^ local_2e8) >> 0x18 | local_2e4 << 8;
    uVar28 = local_168[(uint)pbVar21[5] * 2] + uVar30;
    uVar27 = local_168[(uint)pbVar21[1] * 2] + uVar10;
    uVar45 = local_2e4 >> 0x18 | (uVar33 ^ local_2e8) << 8;
    uVar38 = uVar28 + uVar25;
    uVar28 = local_168[(uint)pbVar21[5] * 2 + 1] +
             uVar40 + CARRY4(local_168[(uint)pbVar21[5] * 2],uVar30) +
             uVar44 + CARRY4(uVar28,uVar25);
    uVar29 = uVar39 ^ local_318 ^ uVar29;
    uVar40 = uVar29 >> 0x10 | (uVar11 ^ local_314) << 0x10;
    uVar19 = uVar27 + uVar35;
    uVar48 = (uVar11 ^ local_314) >> 0x10 | uVar29 << 0x10;
    uVar29 = local_168[(uint)pbVar21[1] * 2 + 1] +
             uVar8 + CARRY4(local_168[(uint)pbVar21[1] * 2],uVar10) + uVar45 + CARRY4(uVar27,uVar35)
    ;
    uVar36 = local_168[(uint)pbVar21[8] * 2] + uVar19;
    uVar8 = uVar28 ^ local_2c8 ^ uVar30;
    uVar27 = uVar8 >> 0x10 | (uVar38 ^ local_2c4) << 0x10;
    uVar37 = uVar36 + uVar13;
    uVar30 = (uVar38 ^ local_2c4) >> 0x10 | uVar8 << 0x10;
    uVar43 = local_168[(uint)pbVar21[8] * 2 + 1] +
             uVar29 + CARRY4(local_168[(uint)pbVar21[8] * 2],uVar19) +
             uVar18 + CARRY4(uVar36,uVar13);
    uVar36 = uVar43 ^ uVar40;
    uVar24 = uVar30 + uVar32;
    uVar32 = uVar27 + uStack_304 + CARRY4(uVar30,uVar32);
    uVar46 = uVar36 + uVar24;
    uVar49 = (uVar37 ^ uVar48) + uVar32 + CARRY4(uVar36,uVar24);
    uVar29 = uVar29 ^ local_2c0 ^ uVar10;
    uVar8 = uVar29 >> 0x10 | (uVar19 ^ local_2bc) << 0x10;
    uVar18 = uVar49 ^ uVar18;
    uVar29 = (uVar19 ^ local_2bc) >> 0x10 | uVar29 << 0x10;
    uVar32 = uVar32 ^ uVar44;
    uVar47 = uVar18 >> 0x18 | (uVar46 ^ uVar13) << 8;
    uVar44 = (uVar46 ^ uVar13) >> 0x18 | uVar18 << 8;
    uVar18 = uVar32 << 1 | (uVar24 ^ uVar25) >> 0x1f;
    uVar10 = uVar48 + uVar22;
    uVar40 = uVar40 + uStack_324 + CARRY4(uVar48,uVar22);
    uVar22 = uVar29 + uVar33;
    uVar50 = uVar8 + local_334 + CARRY4(uVar29,uVar33);
    uVar13 = local_168[(uint)pbVar21[9] * 2] + uVar37;
    pbVar1 = pbVar21 + 0xb;
    local_2d8 = uVar13 + uVar44;
    pbVar3 = pbVar21 + 0xe;
    local_2d4 = local_168[(uint)pbVar21[9] * 2 + 1] +
                uVar43 + CARRY4(local_168[(uint)pbVar21[9] * 2],uVar37) +
                uVar47 + CARRY4(uVar13,uVar44);
    uVar13 = local_2d4 ^ uVar37 ^ uVar48;
    uVar19 = (uVar24 ^ uVar25) << 1 | uVar32 >> 0x1f;
    local_314 = uVar13 >> 0x10 | (local_2d8 ^ uVar36) << 0x10;
    local_318 = (local_2d8 ^ uVar36) >> 0x10 | uVar13 << 0x10;
    uVar33 = uVar17 + uVar19;
    uVar37 = uVar41 + local_168[(uint)pbVar21[10] * 2 + 1] +
                      (uint)CARRY4(uVar31,local_168[(uint)pbVar21[10] * 2]) +
             uVar18 + CARRY4(uVar17,uVar19);
    uVar16 = uVar40 ^ uVar16;
    uVar8 = uVar37 ^ uVar8;
    uVar17 = uVar16 << 1 | (uVar10 ^ uVar15) >> 0x1f;
    uVar36 = (uVar10 ^ uVar15) << 1 | uVar16 >> 0x1f;
    uVar45 = uVar50 ^ uVar45;
    uVar15 = uVar45 << 1 | (uVar22 ^ uVar35) >> 0x1f;
    local_308 = local_318 + uVar46;
    uVar13 = (uVar22 ^ uVar35) << 1 | uVar45 >> 0x1f;
    uStack_304 = local_314 + uVar49 + CARRY4(local_318,uVar46);
    uVar24 = uVar8 + uVar10;
    uVar32 = (uVar33 ^ uVar29) + uVar40 + CARRY4(uVar8,uVar10);
    uVar25 = uVar33 + local_168[(uint)*pbVar1 * 2];
    uVar45 = local_168[(uint)*pbVar3 * 2] + uVar11;
    uVar10 = local_168[(uint)pbVar21[0xc] * 2] + uVar38;
    pbVar4 = pbVar21 + 0xd;
    uVar40 = uVar10 + uVar36;
    pbVar2 = pbVar21 + 0xf;
    uVar16 = local_168[(uint)pbVar21[0xc] * 2 + 1] +
             uVar28 + CARRY4(local_168[(uint)pbVar21[0xc] * 2],uVar38) +
             uVar17 + CARRY4(uVar10,uVar36);
    pbVar21 = pbVar21 + 0x10;
    uVar31 = uVar45 + uVar13;
    uVar35 = local_168[(uint)*pbVar3 * 2 + 1] + uVar39 + CARRY4(local_168[(uint)*pbVar3 * 2],uVar11)
             + uVar15 + CARRY4(uVar45,uVar13);
    uVar23 = uVar16 ^ uVar23;
    uVar27 = uVar35 ^ uVar27;
    uVar10 = uVar23 + uVar22;
    uVar11 = (uVar40 ^ uVar12) + uVar50 + CARRY4(uVar23,uVar22);
    uVar39 = uVar27 + uVar34;
    uVar45 = (uVar31 ^ uVar30) + uVar42 + CARRY4(uVar27,uVar34);
    uVar47 = uStack_304 ^ uVar47;
    uVar18 = uVar32 ^ uVar18;
    uVar17 = uVar11 ^ uVar17;
    uVar15 = uVar45 ^ uVar15;
    local_30c = uVar47 << 1 | (local_308 ^ uVar44) >> 0x1f;
    uVar22 = uVar18 >> 0x18 | (uVar24 ^ uVar19) << 8;
    uVar38 = (uVar24 ^ uVar19) >> 0x18 | uVar18 << 8;
    local_310 = (local_308 ^ uVar44) << 1 | uVar47 >> 0x1f;
    uVar28 = uVar17 >> 0x18 | (uVar10 ^ uVar36) << 8;
    uVar44 = uVar15 >> 0x18 | (uVar39 ^ uVar13) << 8;
    uVar36 = (uVar10 ^ uVar36) >> 0x18 | uVar17 << 8;
    local_300 = uVar25 + uVar38;
    uStack_2fc = uVar37 + local_168[(uint)*pbVar1 * 2 + 1] +
                          (uint)CARRY4(uVar33,local_168[(uint)*pbVar1 * 2]) +
                 uVar22 + CARRY4(uVar25,uVar38);
    uVar18 = local_168[(uint)*pbVar4 * 2] + uVar40;
    uVar13 = (uVar39 ^ uVar13) >> 0x18 | uVar15 << 8;
    uVar15 = uStack_2fc ^ uVar33 ^ uVar29;
    local_2bc = uVar15 >> 0x10 | (local_300 ^ uVar8) << 0x10;
    uVar29 = local_168[(uint)*pbVar2 * 2] + uVar31;
    local_2c0 = (local_300 ^ uVar8) >> 0x10 | uVar15 << 0x10;
    local_330 = uVar18 + uVar36;
    uStack_32c = local_168[(uint)*pbVar4 * 2 + 1] +
                 uVar16 + CARRY4(local_168[(uint)*pbVar4 * 2],uVar40) +
                 uVar28 + CARRY4(uVar18,uVar36);
    local_320 = uVar29 + uVar13;
    uStack_31c = local_168[(uint)*pbVar2 * 2 + 1] +
                 uVar35 + CARRY4(local_168[(uint)*pbVar2 * 2],uVar31) +
                 uVar44 + CARRY4(uVar29,uVar13);
    uVar15 = uStack_31c ^ uVar31 ^ uVar30;
    uVar8 = uStack_32c ^ uVar40 ^ uVar12;
    local_2c4 = uVar15 >> 0x10 | (local_320 ^ uVar27) << 0x10;
    local_2b4 = uVar8 >> 0x10 | (local_330 ^ uVar23) << 0x10;
    local_2b8 = (local_330 ^ uVar23) >> 0x10 | uVar8 << 0x10;
    local_2c8 = (local_320 ^ uVar27) >> 0x10 | uVar15 << 0x10;
    local_328 = local_2c0 + uVar24;
    uStack_324 = local_2bc + uVar32 + CARRY4(local_2c0,uVar24);
    local_338 = local_2b8 + uVar10;
    local_334 = local_2b4 + uVar11 + CARRY4(local_2b8,uVar10);
    local_1a8[2] = local_2c8 + uVar39;
    uVar28 = local_334 ^ uVar28;
    local_1a8[3] = local_2c4 + uVar45 + CARRY4(local_2c8,uVar39);
    uVar22 = uStack_324 ^ uVar22;
    local_2f4 = uVar22 << 1 | (local_328 ^ uVar38) >> 0x1f;
    local_2ec = uVar28 << 1 | (local_338 ^ uVar36) >> 0x1f;
    uVar44 = local_1a8[3] ^ uVar44;
    local_2f0 = (local_338 ^ uVar36) << 1 | uVar28 >> 0x1f;
    local_2f8 = (local_328 ^ uVar38) << 1 | uVar22 >> 0x1f;
    local_2e4 = uVar44 << 1 | (local_1a8[2] ^ uVar13) >> 0x1f;
    local_2e8 = (local_1a8[2] ^ uVar13) << 1 | uVar44 >> 0x1f;
  } while (pbVar21 != local_e8 + 0xc0);
  local_170 = local_318;
  uStack_16c = local_314;
  local_1a8[4] = local_308;
  local_1a8[5] = uStack_304;
  local_1c0 = local_310;
  uStack_1bc = local_30c;
  local_1e8[2] = local_300;
  local_1e8[3] = uStack_2fc;
  local_188 = local_2c0;
  uStack_184 = local_2bc;
  local_1a8[6] = local_328;
  uStack_18c = uStack_324;
  local_1b8 = local_2f8;
  uStack_1b4 = local_2f4;
  local_1e8[4] = local_330;
  local_1e8[5] = uStack_32c;
  local_180 = local_2b8;
  uStack_17c = local_2b4;
  local_1a8[0] = local_338;
  local_1a8[1] = local_334;
  local_1b0 = local_2f0;
  uStack_1ac = local_2ec;
  local_1e8[6] = local_320;
  uStack_1cc = uStack_31c;
  local_178 = local_2c8;
  uStack_174 = local_2c4;
  iVar20 = 8;
  local_1c8 = local_2e8;
  uStack_1c4 = local_2e4;
  puVar6 = local_1e8;
  puVar9 = local_1a8;
  puVar14 = (uint *)(local_1ec + 0x80);
  while( true ) {
    iVar20 = iVar20 + -1;
    *puVar14 = *puVar14 ^ local_2d8 ^ local_338;
    puVar14[1] = puVar14[1] ^ local_2d4 ^ local_334;
    if (iVar20 == 0) break;
    local_2d8 = puVar6[2];
    local_2d4 = puVar6[3];
    local_338 = puVar9[2];
    local_334 = puVar9[3];
    puVar6 = puVar6 + 2;
    puVar9 = puVar9 + 2;
    puVar14 = puVar14 + 2;
  }
  return;
}

