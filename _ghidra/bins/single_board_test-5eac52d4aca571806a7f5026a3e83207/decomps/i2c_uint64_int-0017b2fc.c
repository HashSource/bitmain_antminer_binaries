
int i2c_uint64_int(undefined1 *param_1,undefined4 param_2,uint param_3,uint param_4,int param_5)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  byte *pbVar18;
  byte *pbVar19;
  byte *pbVar20;
  byte *pbVar21;
  byte *pbVar22;
  byte *pbVar23;
  byte *pbVar24;
  byte *pbVar25;
  byte *pbVar26;
  byte *pbVar27;
  byte *pbVar28;
  byte *pbVar29;
  byte *pbVar30;
  uint uVar31;
  undefined1 *puVar32;
  byte bVar33;
  byte *pbVar34;
  int iVar35;
  uint uVar36;
  undefined1 *puVar37;
  int iVar38;
  byte *pbVar39;
  uint uVar40;
  undefined1 local_21 [5];
  
  iVar35 = 8;
  puVar32 = local_21;
  do {
    puVar37 = puVar32;
    uVar40 = param_4 >> 8;
    uVar36 = param_3 & 0xff;
    uVar31 = param_3 >> 8 | param_4 << 0x18;
    iVar35 = iVar35 + -1;
    *puVar37 = (char)param_3;
    param_3 = uVar31;
    param_4 = uVar40;
    puVar32 = puVar37 + -1;
  } while (uVar31 != 0 || uVar40 != 0);
  uVar31 = 8 - iVar35;
  if (uVar31 == 0) {
    if (param_1 != (undefined1 *)0x0) {
      *param_1 = 0;
    }
    iVar35 = 1;
  }
  else {
    if (uVar36 < 0x80 || param_5 != 0) {
      if (param_5 == 0) {
        uVar40 = 0;
        uVar36 = 0;
      }
      else if (uVar36 < 0x81) {
        uVar40 = 0;
        if (uVar36 == 0x80) {
          if (uVar31 == 1) {
            uVar36 = 0;
          }
          else {
            if (uVar31 < 0x22) {
              iVar38 = 1;
              bVar33 = 0;
            }
            else {
              puVar32 = puVar37 + 0x23;
              iVar38 = 1;
              bVar33 = 0;
              do {
                pbVar34 = puVar32 + -0x22;
                iVar38 = iVar38 + 0x20;
                pbVar39 = puVar32 + -0x21;
                pbVar1 = puVar32 + -0x20;
                pbVar2 = puVar32 + -0x1e;
                pbVar3 = puVar32 + -0x1f;
                pbVar4 = puVar32 + -0x1d;
                pbVar5 = puVar32 + -0x17;
                pbVar6 = puVar32 + -0x1c;
                pbVar7 = puVar32 + -0x1b;
                pbVar8 = puVar32 + -0x1a;
                pbVar9 = puVar32 + -0x19;
                pbVar10 = puVar32 + -0x18;
                pbVar11 = puVar32 + -0x16;
                pbVar12 = puVar32 + -0x14;
                pbVar13 = puVar32 + -0x15;
                HintPreloadData(puVar32);
                pbVar14 = puVar32 + -0x13;
                pbVar15 = puVar32 + -0x12;
                pbVar16 = puVar32 + -0x11;
                pbVar17 = puVar32 + -0x10;
                pbVar18 = puVar32 + -0xf;
                pbVar19 = puVar32 + -0xe;
                pbVar20 = puVar32 + -0xd;
                pbVar21 = puVar32 + -0xc;
                pbVar22 = puVar32 + -0xb;
                pbVar23 = puVar32 + -10;
                pbVar24 = puVar32 + -9;
                pbVar25 = puVar32 + -8;
                pbVar26 = puVar32 + -7;
                pbVar27 = puVar32 + -6;
                pbVar28 = puVar32 + -5;
                pbVar29 = puVar32 + -4;
                pbVar30 = puVar32 + -3;
                puVar32 = puVar32 + 0x20;
                bVar33 = bVar33 | *pbVar20 |
                                  *pbVar19 |
                                  *pbVar18 |
                                  *pbVar17 |
                                  *pbVar16 |
                                  *pbVar15 |
                                  *pbVar14 |
                                  *pbVar12 |
                                  *pbVar13 |
                                  *pbVar11 |
                                  *pbVar5 | *pbVar10 |
                                            *pbVar8 | *pbVar7 | *pbVar34 | *pbVar39 | *pbVar1 |
                                                                *pbVar3 | *pbVar2 | *pbVar4 |
                                                                *pbVar6 | *pbVar9 | *pbVar21 |
                                  *pbVar22 | *pbVar23 | *pbVar24 | *pbVar25 | *pbVar26 | *pbVar27 |
                                  *pbVar28 | *pbVar29 | *pbVar30;
              } while (puVar37 + (-iVar35 - 0x1aU & 0xffffffe0) + 0x43 != puVar32);
            }
            pbVar34 = puVar37 + iVar38;
            do {
              pbVar39 = pbVar34 + 1;
              bVar33 = bVar33 | *pbVar34;
              pbVar34 = pbVar39;
            } while ((uint)((int)pbVar39 - (int)puVar37) < uVar31);
            if (bVar33 == 0) {
              uVar36 = 0;
            }
            else {
              uVar36 = 0xff;
            }
            uVar40 = uVar36 & 1;
          }
        }
        else {
          uVar36 = 0xff;
        }
      }
      else {
        uVar36 = 0xff;
        uVar40 = 1;
      }
    }
    else {
      uVar36 = 0;
      uVar40 = 1;
    }
    iVar35 = uVar31 + uVar40;
    if (param_1 != (undefined1 *)0x0) {
      puVar32 = param_1 + iVar35;
      pbVar34 = puVar37 + uVar31;
      puVar37 = puVar32 + -uVar31;
      uVar31 = uVar36 & 1;
      *param_1 = (char)uVar36;
      do {
        pbVar34 = pbVar34 + -1;
        uVar31 = uVar31 + (*pbVar34 ^ uVar36);
        puVar32 = puVar32 + -1;
        *puVar32 = (char)uVar31;
        uVar31 = uVar31 >> 8;
      } while (puVar32 != puVar37);
      return iVar35;
    }
  }
  return iVar35;
}

