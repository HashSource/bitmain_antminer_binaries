
void aria_encrypt(byte *param_1,undefined1 *param_2,uint *param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int local_3c;
  uint *local_30;
  
  if ((param_1 != (byte *)0x0 && (param_3 != (uint *)0x0 && param_2 != (undefined1 *)0x0)) &&
     (uVar10 = param_3[0x44], (uVar10 & 0xfffffffd) == 0xc || uVar10 == 0x10)) {
    local_30 = param_3 + 8;
    uVar16 = (uint)param_1[0xb] ^ param_3[2] ^ (uint)param_1[8] << 0x18;
    uVar13 = (uint)param_1[7] ^ param_3[1] ^ (uint)param_1[4] << 0x18;
    uVar14 = uVar13 ^ (uint)param_1[5] << 0x10;
    uVar15 = uVar14 ^ (uint)param_1[6] << 8;
    uVar11 = (uint)param_1[3] ^ *param_3 ^ (uint)*param_1 << 0x18;
    uVar7 = (uint)param_1[0xf] ^ param_3[3] ^ (uint)param_1[0xc] << 0x18;
    uVar12 = uVar11 ^ (uint)param_1[1] << 0x10;
    uVar17 = uVar16 ^ (uint)param_1[9] << 0x10;
    uVar18 = uVar17 ^ (uint)param_1[10] << 8;
    uVar8 = uVar7 ^ (uint)param_1[0xd] << 0x10;
    uVar5 = uVar12 ^ (uint)param_1[2] << 8;
    uVar9 = uVar8 ^ (uint)param_1[0xe] << 8;
    uVar16 = *(uint *)(&X1 + ((uVar18 << 0x10) >> 0x18) * 4) ^
             *(uint *)(S1 + (uVar16 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar17 & 0xff) * 4) ^
             *(uint *)(S2 + ((uVar18 << 8) >> 0x18) * 4);
    uVar13 = *(uint *)(&X1 + ((uVar15 << 0x10) >> 0x18) * 4) ^
             *(uint *)(S1 + (uVar13 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar14 & 0xff) * 4) ^
             *(uint *)(S2 + ((uVar15 << 8) >> 0x18) * 4) ^ uVar16;
    uVar11 = *(uint *)(&X1 + ((uVar5 << 0x10) >> 0x18) * 4) ^
             *(uint *)(S1 + (uVar11 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar12 & 0xff) * 4) ^
             *(uint *)(S2 + ((uVar5 << 8) >> 0x18) * 4) ^ uVar13;
    uVar5 = *(uint *)(&X1 + ((uVar9 << 0x10) >> 0x18) * 4) ^
            *(uint *)(S1 + (uVar7 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar8 & 0xff) * 4) ^
            *(uint *)(S2 + ((uVar9 << 8) >> 0x18) * 4);
    uVar8 = uVar5 ^ uVar13;
    uVar7 = uVar16 ^ uVar5 ^ uVar11;
    uVar5 = uVar7 >> 0x10 | uVar7 << 0x10;
    uVar8 = uVar8 >> 0x18 | uVar8 << 0x18 | (uVar8 & 0xff00) << 8 | (uVar8 & 0xff0000) >> 8;
    uVar7 = ((uVar13 ^ uVar7) & 0xff00ff) << 8 ^ (uVar13 ^ uVar7) >> 8 & 0xff00ff ^ uVar5;
    uVar11 = uVar11 ^ uVar7;
    uVar5 = uVar5 ^ uVar8 ^ uVar11;
    uVar11 = uVar11 ^ param_3[4];
    uVar9 = uVar5 ^ uVar7 ^ param_3[5];
    local_3c = uVar10 - 2;
    uVar7 = uVar7 ^ uVar8 ^ param_3[7];
    uVar5 = uVar5 ^ param_3[6];
    if (local_3c != 0) {
      puVar6 = param_3 + 0x1b;
      do {
        uVar8 = *(uint *)(S1 + ((uVar5 << 0x10) >> 0x18) * 4) ^
                *(uint *)(X2 + ((uVar5 << 8) >> 0x18) * 4) ^
                *(uint *)(&X1 + (uVar5 >> 0x18) * 4) ^ *(uint *)(S2 + (uVar5 & 0xff) * 4);
        uVar5 = *(uint *)(S1 + ((uVar9 << 0x10) >> 0x18) * 4) ^
                *(uint *)(&X1 + (uVar9 >> 0x18) * 4) ^ *(uint *)(S2 + (uVar9 & 0xff) * 4) ^
                *(uint *)(X2 + ((uVar9 << 8) >> 0x18) * 4) ^ uVar8;
        uVar7 = *(uint *)(X2 + ((uVar7 << 8) >> 0x18) * 4) ^
                *(uint *)(&X1 + (uVar7 >> 0x18) * 4) ^ *(uint *)(S2 + (uVar7 & 0xff) * 4) ^
                *(uint *)(S1 + ((uVar7 << 0x10) >> 0x18) * 4);
        uVar9 = *(uint *)(S1 + ((uVar11 << 0x10) >> 0x18) * 4) ^
                *(uint *)(&X1 + (uVar11 >> 0x18) * 4) ^ *(uint *)(S2 + (uVar11 & 0xff) * 4) ^
                *(uint *)(X2 + ((uVar11 << 8) >> 0x18) * 4) ^ uVar5;
        uVar11 = uVar7 ^ uVar5;
        uVar8 = uVar8 ^ uVar7 ^ uVar9;
        uVar5 = uVar5 ^ uVar8;
        HintPreloadData(puVar6);
        HintPreloadData(puVar6 + 4);
        uVar11 = uVar11 >> 8 & 0xff00ff ^ (uVar11 & 0xff00ff) << 8;
        uVar7 = (uVar5 >> 0x18 | uVar5 << 0x18) ^ uVar8 ^ (uVar5 & 0xff00) << 8 ^
                (uVar5 & 0xff0000) >> 8;
        uVar5 = uVar7 ^ (uVar9 >> 0x10 | uVar9 << 0x10);
        uVar8 = uVar8 ^ uVar11 ^ uVar5;
        uVar11 = uVar7 ^ uVar11 ^ puVar6[-0x10];
        uVar7 = uVar8 ^ uVar7 ^ puVar6[-0x12];
        uVar5 = uVar5 ^ puVar6[-0x13];
        uVar8 = uVar8 ^ puVar6[-0x11];
        uVar9 = *(uint *)(&X1 + ((uVar8 << 0x10) >> 0x18) * 4) ^
                *(uint *)(S1 + (uVar8 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar8 & 0xff) * 4) ^
                *(uint *)(S2 + ((uVar8 << 8) >> 0x18) * 4);
        uVar8 = *(uint *)(S1 + (uVar7 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar7 & 0xff) * 4) ^
                *(uint *)(S2 + ((uVar7 << 8) >> 0x18) * 4) ^
                *(uint *)(&X1 + ((uVar7 << 0x10) >> 0x18) * 4) ^ uVar9;
        uVar7 = *(uint *)(S1 + (uVar11 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar11 & 0xff) * 4) ^
                *(uint *)(S2 + ((uVar11 << 8) >> 0x18) * 4) ^
                *(uint *)(&X1 + ((uVar11 << 0x10) >> 0x18) * 4);
        uVar13 = uVar7 ^ uVar8;
        uVar11 = *(uint *)(&X1 + ((uVar5 << 0x10) >> 0x18) * 4) ^
                 *(uint *)(S1 + (uVar5 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar5 & 0xff) * 4) ^
                 *(uint *)(S2 + ((uVar5 << 8) >> 0x18) * 4) ^ uVar8;
        uVar7 = uVar9 ^ uVar7 ^ uVar11;
        uVar5 = uVar7 >> 0x10 | uVar7 << 0x10;
        uVar9 = uVar13 >> 0x18 | uVar13 << 0x18 | (uVar13 & 0xff00) << 8 | (uVar13 & 0xff0000) >> 8;
        uVar8 = ((uVar8 ^ uVar7) & 0xff00ff) << 8 ^ (uVar8 ^ uVar7) >> 8 & 0xff00ff ^ uVar5;
        uVar11 = uVar11 ^ uVar8;
        uVar7 = uVar9 ^ puVar6[-0xc] ^ uVar8;
        uVar5 = uVar5 ^ uVar9 ^ uVar11;
        local_3c = local_3c + -2;
        uVar9 = uVar5 ^ puVar6[-0xe] ^ uVar8;
        uVar11 = uVar11 ^ puVar6[-0xf];
        uVar5 = uVar5 ^ puVar6[-0xd];
        puVar6 = puVar6 + 8;
      } while (local_3c != 0);
      local_30 = local_30 + ((uVar10 - 4 >> 1) + 1) * 8;
    }
    bVar1 = S2[(uVar5 & 0xff) * 4];
    bVar4 = (&X1)[(uVar5 >> 0x18) * 4];
    bVar2 = S1[((uVar5 << 0x10) >> 0x18) * 4];
    bVar3 = X2[((uVar5 << 8) >> 0x18) * 4 + 1];
    uVar11 = ((uint)(byte)S2[(uVar11 & 0xff) * 4] | (uint)(byte)(&X1)[(uVar11 >> 0x18) * 4] << 0x18
              | (uint)(byte)S1[((uVar11 << 0x10) >> 0x18) * 4] << 8 |
             (uint)(byte)X2[((uVar11 << 8) >> 0x18) * 4 + 1] << 0x10) ^ *local_30;
    uVar10 = local_30[2];
    uVar5 = ((uint)(byte)S2[(uVar9 & 0xff) * 4] | (uint)(byte)(&X1)[(uVar9 >> 0x18) * 4] << 0x18 |
             (uint)(byte)S1[((uVar9 << 0x10) >> 0x18) * 4] << 8 |
            (uint)(byte)X2[((uVar9 << 8) >> 0x18) * 4 + 1] << 0x10) ^ local_30[1];
    uVar7 = ((uint)(byte)S2[(uVar7 & 0xff) * 4] | (uint)(byte)(&X1)[(uVar7 >> 0x18) * 4] << 0x18 |
             (uint)(byte)S1[((uVar7 << 0x10) >> 0x18) * 4] << 8 |
            (uint)(byte)X2[((uVar7 << 8) >> 0x18) * 4 + 1] << 0x10) ^ local_30[3];
    *param_2 = (char)(uVar11 >> 0x18);
    uVar10 = uVar10 ^ ((uint)bVar1 | (uint)bVar4 << 0x18 | (uint)bVar2 << 8 | (uint)bVar3 << 0x10);
    param_2[3] = (char)uVar11;
    param_2[7] = (char)uVar5;
    param_2[0xb] = (char)uVar10;
    param_2[1] = (char)(uVar11 >> 0x10);
    param_2[2] = (char)(uVar11 >> 8);
    param_2[4] = (char)(uVar5 >> 0x18);
    param_2[5] = (char)(uVar5 >> 0x10);
    param_2[6] = (char)(uVar5 >> 8);
    param_2[8] = (char)(uVar10 >> 0x18);
    param_2[9] = (char)(uVar10 >> 0x10);
    param_2[10] = (char)(uVar10 >> 8);
    param_2[0xc] = (char)(uVar7 >> 0x18);
    param_2[0xf] = (char)uVar7;
    param_2[0xd] = (char)(uVar7 >> 0x10);
    param_2[0xe] = (char)(uVar7 >> 8);
    return;
  }
  return;
}

