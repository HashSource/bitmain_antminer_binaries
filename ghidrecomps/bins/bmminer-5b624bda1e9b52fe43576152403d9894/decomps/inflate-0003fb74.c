
/* WARNING: Type propagation algorithm not settling */

int inflate(byte **param_1,uint *param_2,undefined4 param_3,char *param_4)

{
  ushort uVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  int iVar6;
  byte *pbVar7;
  ushort *puVar8;
  undefined *puVar9;
  uint *extraout_r1;
  uint uVar10;
  undefined4 uVar11;
  uint *puVar12;
  uint *puVar13;
  uint *extraout_r1_00;
  uint **ppuVar14;
  undefined2 *puVar15;
  uint *puVar16;
  uint *puVar17;
  undefined2 uVar18;
  uint *puVar19;
  uint **ppuVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  undefined4 *puVar25;
  uint uVar26;
  uint uVar27;
  uint **ppuVar28;
  uint uVar29;
  uint *puVar30;
  uint **ppuVar31;
  uint *puVar32;
  byte *pbVar33;
  bool bVar34;
  bool bVar35;
  undefined8 uVar36;
  uint *local_70;
  uint *local_6c;
  uint *local_68;
  uint *local_64;
  int local_5c;
  uint *local_50;
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined local_29;
  
  if (((param_1 == (byte **)0x0) || (puVar32 = (uint *)param_1[7], puVar32 == (uint *)0x0)) ||
     (local_6c = (uint *)param_1[3], local_6c == (uint *)0x0)) {
switchD_0003fbea_caseD_1f:
    return -2;
  }
  pbVar33 = *param_1;
  if (pbVar33 == (byte *)0x0) {
    if (param_1[1] != (byte *)0x0) {
      return 0xfffffffe;
    }
    local_64 = (uint *)0x0;
    param_4 = (char *)0x0;
  }
  else {
    local_64 = (uint *)param_1[1];
  }
  ppuVar14 = (uint **)*puVar32;
  ppuVar28 = (uint **)puVar32[0xe];
  bVar34 = ppuVar14 == (uint **)0xb;
  ppuVar31 = (uint **)puVar32[0xf];
  if (bVar34) {
    ppuVar14 = (uint **)0xc;
  }
  local_70 = (uint *)param_1[4];
  local_5c = 0;
  puVar12 = param_2;
  puVar30 = local_64;
  local_68 = local_70;
  if (bVar34) {
    *puVar32 = (uint)ppuVar14;
  }
LAB_0003fbe4:
  puVar17 = DAT_000404e8;
  uVar36 = CONCAT44(puVar12,local_5c);
  switch(ppuVar14) {
  case (uint **)0x0:
    uVar21 = puVar32[2];
    if (uVar21 == 0) {
      ppuVar14 = (uint **)0xc;
      *puVar32 = 0xc;
      puVar12 = (uint *)0x0;
      goto LAB_0003fbe4;
    }
    for (; ppuVar31 < (uint **)0x10; ppuVar31 = ppuVar31 + 2) {
      if (puVar30 == (uint *)0x0) goto LAB_00040332;
      puVar30 = (uint *)((int)puVar30 + -1);
      ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar33 << ((uint)ppuVar31 & 0xff)));
      pbVar33 = pbVar33 + 1;
    }
    if (((int)(uVar21 << 0x1e) < 0) && (ppuVar28 == (uint **)((int)&__DT_SYMTAB[0x4c].st_value + 3))
       ) {
      ppuVar31 = (uint **)0x0;
      uVar21 = crc32(0,0,0);
      param_4 = (char *)0x8b;
      local_2c = 0x1f;
      puVar32[6] = uVar21;
      local_2b = 0x8b;
      ppuVar28 = (uint **)0x0;
      uVar36 = crc32(uVar21,&local_2c,2);
      ppuVar14 = (uint **)0x1;
      puVar32[6] = (uint)uVar36;
      *puVar32 = 1;
      puVar12 = (uint *)((ulonglong)uVar36 >> 0x20);
      goto LAB_0003fbe4;
    }
    puVar32[4] = 0;
    if (puVar32[8] != 0) {
      *(undefined4 *)(puVar32[8] + 0x30) = 0xffffffff;
    }
    puVar17 = DAT_00041314;
    puVar12 = DAT_00041050;
    if ((-1 < (int)(uVar21 << 0x1f)) ||
       (uVar21 = ((uint)ppuVar28 & 0xff) * 0x100 + ((uint)ppuVar28 >> 8),
       uVar21 != (uVar21 / 0x1f + (uVar21 - uVar21 / 0x1f >> 1) >> 4) * 0x1f)) {
      param_4 = (char *)0x1d;
      ppuVar14 = (uint **)0x1d;
      param_1[6] = (byte *)DAT_00041050;
      *puVar32 = 0x1d;
      goto LAB_0003fbe4;
    }
    if (((uint)ppuVar28 & 0xf) == 8) {
      ppuVar28 = (uint **)((uint)ppuVar28 >> 4);
      uVar21 = ((uint)ppuVar28 & 0xf) + 8;
      if (puVar32[9] == 0) {
        puVar32[9] = uVar21;
      }
      else if (puVar32[9] < uVar21) {
        param_4 = (char *)0x1d;
        ppuVar31 = ppuVar31 + -1;
        ppuVar14 = (uint **)0x1d;
        param_1[6] = (byte *)DAT_00041314;
        *puVar32 = 0x1d;
        puVar12 = puVar17;
        goto LAB_0003fbe4;
      }
      param_4 = (char *)(1 << uVar21);
      puVar32[5] = (uint)param_4;
      uVar36 = adler32(0,0);
      if (((uint)ppuVar28 & 0x200) == 0) {
        ppuVar14 = (uint **)0xb;
      }
      else {
        ppuVar14 = (uint **)0x9;
      }
      ppuVar31 = (uint **)0x0;
      puVar32[6] = (uint)(byte *)uVar36;
      param_1[0xc] = (byte *)uVar36;
      *puVar32 = (uint)ppuVar14;
      puVar12 = (uint *)((ulonglong)uVar36 >> 0x20);
      ppuVar28 = ppuVar31;
      goto LAB_0003fbe4;
    }
    break;
  case (uint **)0x1:
    for (; ppuVar31 < (uint **)0x10; ppuVar31 = ppuVar31 + 2) {
      if (puVar30 == (uint *)0x0) goto LAB_00040332;
      puVar30 = (uint *)((int)puVar30 + -1);
      ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar33 << ((uint)ppuVar31 & 0xff)));
      pbVar33 = pbVar33 + 1;
    }
    puVar32[4] = (uint)ppuVar28;
    if (((uint)ppuVar28 & 0xff) == 8) {
      if (((uint)ppuVar28 & 0xe000) == 0) {
        if ((uint *)puVar32[8] != (uint *)0x0) {
          *(uint *)puVar32[8] = (uint)((int)ppuVar28 << 0x17) >> 0x1f;
        }
        if (((uint)ppuVar28 & 0x200) != 0) {
          local_2b = (undefined)((uint)ppuVar28 >> 8);
          local_2c = (char)ppuVar28;
          uVar21 = crc32(puVar32[6],&local_2c,2);
          puVar32[6] = uVar21;
        }
        ppuVar31 = (uint **)0x0;
        ppuVar28 = (uint **)0x0;
        *puVar32 = 2;
        pbVar7 = pbVar33;
LAB_0003ffaa:
        pbVar33 = pbVar7;
        if (puVar30 != (uint *)0x0) {
          while( true ) {
            pbVar33 = pbVar7 + 1;
            puVar30 = (uint *)((int)puVar30 + -1);
            uVar21 = (uint)ppuVar31 & 0xff;
            ppuVar31 = ppuVar31 + 2;
            ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar7 << uVar21));
            if ((uint **)0x1f < ppuVar31) break;
            pbVar7 = pbVar33;
            if (puVar30 == (uint *)0x0) goto LAB_00040332;
          }
          goto LAB_0003ffd2;
        }
        goto LAB_00040332;
      }
      ppuVar14 = (uint **)0x1d;
      param_4 = "unknown header flags set";
      param_1[6] = (byte *)"unknown header flags set";
      *puVar32 = 0x1d;
      goto LAB_0003fbe4;
    }
    break;
  case (uint **)0x2:
    pbVar7 = pbVar33;
    if (ppuVar31 < (uint **)0x20) goto LAB_0003ffaa;
LAB_0003ffd2:
    if (puVar32[8] != 0) {
      *(uint ***)(puVar32[8] + 4) = ppuVar28;
    }
    if ((int)(puVar32[4] << 0x16) < 0) {
      local_2b = (undefined)((uint)ppuVar28 >> 8);
      local_2c = SUB41(ppuVar28,0);
      local_2a = (undefined)((uint)ppuVar28 >> 0x10);
      local_29 = (undefined)((uint)ppuVar28 >> 0x18);
      uVar21 = crc32(puVar32[6],&local_2c,4);
      puVar32[6] = uVar21;
    }
    ppuVar28 = (uint **)0x0;
    ppuVar31 = (uint **)0x0;
    *puVar32 = 3;
    pbVar7 = pbVar33;
LAB_0003fff2:
    pbVar33 = pbVar7;
    if (puVar30 != (uint *)0x0) {
      while( true ) {
        pbVar33 = pbVar7 + 1;
        puVar30 = (uint *)((int)puVar30 + -1);
        uVar21 = (uint)ppuVar31 & 0xff;
        ppuVar31 = ppuVar31 + 2;
        ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar7 << uVar21));
        if ((uint **)0xf < ppuVar31) break;
        pbVar7 = pbVar33;
        if (puVar30 == (uint *)0x0) goto LAB_00040332;
      }
      goto LAB_0004001a;
    }
    goto LAB_00040332;
  case (uint **)0x3:
    pbVar7 = pbVar33;
    if (ppuVar31 < (uint **)0x10) goto LAB_0003fff2;
LAB_0004001a:
    uVar21 = puVar32[8];
    if (uVar21 != 0) {
      *(uint *)(uVar21 + 8) = (uint)ppuVar28 & 0xff;
      *(uint *)(uVar21 + 0xc) = (uint)ppuVar28 >> 8;
    }
    uVar21 = puVar32[4];
    if ((int)(uVar21 << 0x16) < 0) {
      local_2b = (undefined)((uint)ppuVar28 >> 8);
      local_2c = (char)ppuVar28;
      uVar23 = crc32(puVar32[6],&local_2c,2);
      uVar21 = puVar32[4];
      puVar32[6] = uVar23;
    }
    *puVar32 = 4;
    if ((uVar21 & 0x400) == 0) {
      ppuVar31 = (uint **)0x0;
      ppuVar28 = (uint **)0x0;
LAB_00040a3a:
      uVar27 = puVar32[8];
      uVar23 = uVar27;
      if (uVar27 != 0) {
        uVar23 = 0;
        *(undefined4 *)(uVar27 + 0x10) = 0;
      }
    }
    else {
      ppuVar31 = (uint **)0x0;
      ppuVar28 = (uint **)0x0;
      do {
        if (puVar30 == (uint *)0x0) goto LAB_00040332;
        puVar30 = (uint *)((int)puVar30 + -1);
        uVar23 = (uint)ppuVar31 & 0xff;
        ppuVar31 = ppuVar31 + 2;
        ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar33 << uVar23));
        pbVar33 = pbVar33 + 1;
joined_r0x000409b0:
      } while (ppuVar31 < (uint **)0x10);
      puVar32[0x10] = (uint)ppuVar28;
      if (puVar32[8] != 0) {
        *(uint ***)(puVar32[8] + 0x14) = ppuVar28;
      }
      if ((uVar21 & 0x200) == 0) {
        ppuVar31 = (uint **)0x0;
        ppuVar28 = (uint **)0x0;
        uVar23 = uVar21 & 0x400;
      }
      else {
        local_2c = SUB41(ppuVar28,0);
        local_2b = (undefined)((uint)ppuVar28 >> 8);
        ppuVar28 = (uint **)0x0;
        uVar23 = crc32(puVar32[6],&local_2c,2);
        uVar21 = puVar32[4];
        ppuVar31 = (uint **)0x0;
        puVar32[6] = uVar23;
        uVar23 = uVar21 & 0x400;
      }
    }
    *puVar32 = 5;
LAB_000400a4:
    if (uVar23 != 0) {
      puVar17 = (uint *)puVar32[0x10];
      puVar12 = puVar30;
      if (puVar17 <= puVar30) {
        puVar12 = puVar17;
      }
      if (puVar12 != (uint *)0x0) {
        uVar23 = puVar32[8];
        if ((uVar23 != 0) && (*(int *)(uVar23 + 0x10) != 0)) {
          iVar6 = *(int *)(uVar23 + 0x14) - (int)puVar17;
          puVar17 = puVar12;
          if (*(uint *)(uVar23 + 0x18) < (uint)((int)puVar12 + iVar6)) {
            puVar17 = (uint *)(*(uint *)(uVar23 + 0x18) - iVar6);
          }
          memcpy((void *)(*(int *)(uVar23 + 0x10) + iVar6),pbVar33,(size_t)puVar17);
          uVar21 = puVar32[4];
        }
        if ((int)(uVar21 << 0x16) < 0) {
          uVar21 = crc32(puVar32[6],pbVar33,puVar12);
          puVar32[6] = uVar21;
        }
        puVar30 = (uint *)((int)puVar30 - (int)puVar12);
        pbVar33 = pbVar33 + (int)puVar12;
        puVar17 = (uint *)(puVar32[0x10] - (int)puVar12);
        puVar32[0x10] = (uint)puVar17;
      }
      if (puVar17 != (uint *)0x0) goto LAB_00040332;
      uVar21 = puVar32[4];
    }
    puVar32[0x10] = 0;
    *puVar32 = 6;
joined_r0x000409cc:
    if ((uVar21 & 0x800) == 0) {
      if (puVar32[8] != 0) {
        *(undefined4 *)(puVar32[8] + 0x1c) = 0;
      }
    }
    else {
      if (puVar30 == (uint *)0x0) goto LAB_00040332;
      puVar12 = (uint *)0x0;
      do {
        uVar21 = puVar32[8];
        bVar2 = pbVar33[(int)puVar12];
        puVar12 = (uint *)((int)puVar12 + 1);
        if ((uVar21 != 0) && (*(int *)(uVar21 + 0x1c) != 0)) {
          uVar23 = puVar32[0x10];
          bVar34 = uVar23 < *(uint *)(uVar21 + 0x20);
          if (bVar34) {
            *(byte *)(*(int *)(uVar21 + 0x1c) + uVar23) = bVar2;
          }
          if (bVar34) {
            puVar32[0x10] = uVar23 + 1;
          }
        }
      } while (bVar2 != 0 && puVar12 < puVar30);
      if ((int)(puVar32[4] << 0x16) < 0) {
        uVar21 = crc32(puVar32[6],pbVar33,puVar12);
        puVar32[6] = uVar21;
      }
      puVar30 = (uint *)((int)puVar30 - (int)puVar12);
      pbVar33 = pbVar33 + (int)puVar12;
      if (bVar2 != 0) goto LAB_00040332;
      uVar21 = puVar32[4];
    }
    *puVar32 = 7;
    puVar32[0x10] = 0;
joined_r0x00040138:
    if ((uVar21 & 0x1000) == 0) {
      if (puVar32[8] != 0) {
        *(undefined4 *)(puVar32[8] + 0x24) = 0;
      }
    }
    else {
      if (puVar30 == (uint *)0x0) goto LAB_00040332;
      puVar12 = (uint *)0x0;
      do {
        uVar21 = puVar32[8];
        bVar2 = pbVar33[(int)puVar12];
        puVar12 = (uint *)((int)puVar12 + 1);
        if ((uVar21 != 0) && (*(int *)(uVar21 + 0x24) != 0)) {
          uVar23 = puVar32[0x10];
          bVar34 = uVar23 < *(uint *)(uVar21 + 0x28);
          if (bVar34) {
            *(byte *)(*(int *)(uVar21 + 0x24) + uVar23) = bVar2;
          }
          if (bVar34) {
            puVar32[0x10] = uVar23 + 1;
          }
        }
      } while (bVar2 != 0 && puVar12 < puVar30);
      if ((int)(puVar32[4] << 0x16) < 0) {
        uVar21 = crc32(puVar32[6],pbVar33,puVar12);
        puVar32[6] = uVar21;
      }
      puVar30 = (uint *)((int)puVar30 - (int)puVar12);
      pbVar33 = pbVar33 + (int)puVar12;
      if (bVar2 != 0) goto LAB_00040332;
      uVar21 = puVar32[4];
    }
    *puVar32 = 8;
LAB_0004018e:
    puVar12 = DAT_000404e0;
    if ((int)(uVar21 << 0x16) < 0) {
      for (; ppuVar31 < (uint **)0x10; ppuVar31 = ppuVar31 + 2) {
        if (puVar30 == (uint *)0x0) goto LAB_00040332;
        puVar30 = (uint *)((int)puVar30 + -1);
        ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar33 << ((uint)ppuVar31 & 0xff)));
        pbVar33 = pbVar33 + 1;
      }
      if ((uint **)(uint)*(ushort *)(puVar32 + 6) != ppuVar28) {
        param_4 = (char *)0x1d;
        ppuVar14 = (uint **)0x1d;
        param_1[6] = (byte *)DAT_000404e0;
        *puVar32 = 0x1d;
        goto LAB_0003fbe4;
      }
      ppuVar31 = (uint **)0x0;
      ppuVar28 = (uint **)0x0;
    }
    uVar23 = puVar32[8];
    if (uVar23 != 0) {
      *(uint *)(uVar23 + 0x2c) = (uVar21 << 0x16) >> 0x1f;
      *(undefined4 *)(uVar23 + 0x30) = 1;
    }
    uVar36 = crc32(0,0,0);
    param_4 = (char *)0xb;
    puVar32[6] = (uint)(byte *)uVar36;
    ppuVar14 = (uint **)0xb;
    param_1[0xc] = (byte *)uVar36;
    *puVar32 = 0xb;
    puVar12 = (uint *)((ulonglong)uVar36 >> 0x20);
    goto LAB_0003fbe4;
  case (uint **)0x4:
    uVar21 = puVar32[4];
    if ((int)(uVar21 << 0x15) < 0) goto joined_r0x000409b0;
    goto LAB_00040a3a;
  case (uint **)0x5:
    uVar21 = puVar32[4];
    uVar23 = uVar21 & 0x400;
    goto LAB_000400a4;
  case (uint **)0x6:
    uVar21 = puVar32[4];
    goto joined_r0x000409cc;
  case (uint **)0x7:
    uVar21 = puVar32[4];
    goto joined_r0x00040138;
  case (uint **)0x8:
    uVar21 = puVar32[4];
    goto LAB_0004018e;
  case (uint **)0x9:
    for (; ppuVar31 < (uint **)0x20; ppuVar31 = ppuVar31 + 2) {
      if (puVar30 == (uint *)0x0) goto LAB_00040332;
      puVar30 = (uint *)((int)puVar30 + -1);
      ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar33 << ((uint)ppuVar31 & 0xff)));
      pbVar33 = pbVar33 + 1;
    }
    uVar21 = (uint)ppuVar28 >> 0x18;
    uVar27 = (uint)ppuVar28 >> 8;
    iVar6 = (int)ppuVar28 * 0x1000000;
    uVar23 = (uint)ppuVar28 & 0xff00;
    ppuVar28 = (uint **)0x0;
    pbVar7 = (byte *)(uVar21 + iVar6 + (uVar27 & 0xff00) + uVar23 * 0x100);
    ppuVar31 = (uint **)0x0;
    puVar32[6] = (uint)pbVar7;
    param_1[0xc] = pbVar7;
    *puVar32 = 10;
  case (uint **)0xa:
    if (puVar32[3] == 0) {
      param_1[3] = (byte *)local_6c;
      param_1[4] = (byte *)local_70;
      *param_1 = pbVar33;
      param_1[1] = (byte *)puVar30;
      puVar32[0xe] = (uint)ppuVar28;
      puVar32[0xf] = (uint)ppuVar31;
      return 2;
    }
    uVar36 = adler32(0,0,0);
    puVar12 = (uint *)((ulonglong)uVar36 >> 0x20);
    puVar32[6] = (uint)(byte *)uVar36;
    param_1[0xc] = (byte *)uVar36;
    *puVar32 = 0xb;
switchD_0003fbea_caseD_b:
    if ((int)param_2 - 5U < 2) goto LAB_00040332;
switchD_0003fbea_caseD_c:
    if (puVar32[1] == 0) {
      if (ppuVar31 < (uint **)0x3) {
        if (puVar30 == (uint *)0x0) goto LAB_00040332;
        puVar30 = (uint *)((int)puVar30 + -1);
        uVar21 = (uint)ppuVar31 & 0xff;
        ppuVar31 = ppuVar31 + 2;
        ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar33 << uVar21));
        pbVar33 = pbVar33 + 1;
      }
      puVar32[1] = (uint)ppuVar28 & 1;
      uVar21 = DAT_00041054;
      param_4 = (char *)((uint)(uint *)((uint)ppuVar28 >> 1) & 3);
      if ((uint **)param_4 == (uint **)0x2) {
        ppuVar14 = (uint **)0x10;
        *puVar32 = 0x10;
      }
      else if ((uint **)param_4 == (uint **)0x3) {
        ppuVar14 = (uint **)0x1d;
        param_1[6] = DAT_00041058;
        *puVar32 = 0x1d;
        param_4 = (char *)ppuVar14;
      }
      else if ((uint **)param_4 == (uint **)0x1) {
        puVar32[0x13] = (uint)&lenfix_6141;
        ppuVar14 = (uint **)0x13;
        puVar32[0x14] = uVar21;
        puVar32[0x15] = 9;
        puVar32[0x16] = 5;
        *puVar32 = 0x13;
        param_4 = (char *)(uint **)0x5;
        if (param_2 == (uint *)0x6) {
          ppuVar28 = (uint **)((uint)ppuVar28 >> 3);
          ppuVar31 = (uint **)((int)ppuVar31 + -3);
          goto LAB_00040332;
        }
      }
      else {
        ppuVar14 = (uint **)0xd;
        *puVar32 = 0xd;
      }
      ppuVar31 = (uint **)((int)ppuVar31 + -3);
      puVar12 = (uint *)((uint)ppuVar28 >> 1);
      ppuVar28 = (uint **)((uint)ppuVar28 >> 3);
    }
    else {
      param_4 = (char *)((uint)ppuVar31 & 7);
      ppuVar14 = (uint **)0x1a;
      ppuVar31 = (uint **)((uint)ppuVar31 & 0xfffffff8);
      *puVar32 = 0x1a;
      ppuVar28 = (uint **)((uint)ppuVar28 >> (int)param_4);
    }
    goto LAB_0003fbe4;
  case (uint **)0xb:
    goto switchD_0003fbea_caseD_b;
  case (uint **)0xc:
    goto switchD_0003fbea_caseD_c;
  case (uint **)0xd:
    ppuVar28 = (uint **)((uint)ppuVar28 >> ((uint)ppuVar31 & 7));
    for (ppuVar31 = (uint **)((uint)ppuVar31 & 0xfffffff8); ppuVar31 < (uint **)0x20;
        ppuVar31 = ppuVar31 + 2) {
      if (puVar30 == (uint *)0x0) goto LAB_00040332;
      puVar30 = (uint *)((int)puVar30 + -1);
      ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar33 << ((uint)ppuVar31 & 0xff)));
      pbVar33 = pbVar33 + 1;
    }
    puVar19 = (uint *)((uint)ppuVar28 & 0xffff);
    if (puVar19 == (uint *)((uint)ppuVar28 >> 0x10 ^ 0xffff)) {
      puVar32[0x10] = (uint)puVar19;
      *puVar32 = 0xe;
      if (param_2 != (uint *)0x6) {
        ppuVar31 = (uint **)0x0;
        ppuVar28 = (uint **)0x0;
        goto LAB_00040488;
      }
      ppuVar31 = (uint **)0x0;
      ppuVar28 = (uint **)0x0;
      goto LAB_00040332;
    }
    param_4 = (char *)0x1d;
    ppuVar14 = (uint **)0x1d;
    param_1[6] = (byte *)DAT_000404e8;
    *puVar32 = 0x1d;
    puVar12 = puVar17;
    goto LAB_0003fbe4;
  case (uint **)0xe:
    puVar19 = (uint *)puVar32[0x10];
LAB_00040488:
    param_4 = (char *)0xf;
    *puVar32 = 0xf;
LAB_0004048e:
    if (puVar19 == (uint *)0x0) {
      ppuVar14 = (uint **)0xb;
      *puVar32 = 0xb;
    }
    else {
      if (puVar30 < puVar19) {
        puVar19 = puVar30;
      }
      if (local_70 <= puVar19) {
        puVar19 = local_70;
      }
      if (puVar19 == (uint *)0x0) goto LAB_00040332;
      local_70 = (uint *)((int)local_70 - (int)puVar19);
      memcpy(local_6c,pbVar33,(size_t)puVar19);
      pbVar33 = pbVar33 + (int)puVar19;
      param_4 = (char *)(puVar32[0x10] - (int)puVar19);
      ppuVar14 = (uint **)*puVar32;
      puVar32[0x10] = (uint)param_4;
      local_6c = (uint *)((int)local_6c + (int)puVar19);
      puVar12 = extraout_r1;
      puVar30 = (uint *)((int)puVar30 - (int)puVar19);
    }
    goto LAB_0003fbe4;
  case (uint **)0xf:
    puVar19 = (uint *)puVar32[0x10];
    goto LAB_0004048e;
  case (uint **)0x10:
    for (; ppuVar31 < (uint **)0xe; ppuVar31 = ppuVar31 + 2) {
      if (puVar30 == (uint *)0x0) goto LAB_00040332;
      puVar30 = (uint *)((int)puVar30 + -1);
      ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar33 << ((uint)ppuVar31 & 0xff)));
      pbVar33 = pbVar33 + 1;
    }
    param_4 = (char *)(((uint)ppuVar28 & 0x1f) + 0x101);
    puVar12 = (uint *)(((uint)((int)ppuVar28 << 0x16) >> 0x1b) + 1);
    uVar21 = ((uint)((int)ppuVar28 << 0x12) >> 0x1c) + 4;
    ppuVar31 = (uint **)((int)ppuVar31 + -0xe);
    puVar32[0x18] = (uint)param_4;
    ppuVar28 = (uint **)((uint)ppuVar28 >> 0xe);
    puVar32[0x19] = (uint)puVar12;
    puVar32[0x17] = uVar21;
    if ((param_4 < (uint **)0x11f) && (puVar12 < (uint *)0x1f)) {
      uVar23 = 0;
      puVar32[0x1a] = 0;
      *puVar32 = 0x11;
LAB_0004056e:
      puVar8 = (ushort *)(DAT_0004088c + (uVar23 - 1) * 2);
      pbVar7 = pbVar33;
      do {
        uVar23 = uVar23 + 1;
        pbVar33 = pbVar7;
        if (ppuVar31 < (uint **)0x3) {
          if (puVar30 == (uint *)0x0) goto LAB_00040332;
          pbVar33 = pbVar7 + 1;
          puVar30 = (uint *)((int)puVar30 + -1);
          uVar27 = (uint)ppuVar31 & 0xff;
          ppuVar31 = ppuVar31 + 2;
          ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar7 << uVar27));
        }
        puVar8 = puVar8 + 1;
        uVar1 = *puVar8;
        uVar3 = (ushort)ppuVar28;
        ppuVar31 = (uint **)((int)ppuVar31 + -3);
        puVar32[0x1a] = uVar23;
        ppuVar28 = (uint **)((uint)ppuVar28 >> 3);
        *(ushort *)((int)puVar32 + (uVar1 + 0x38) * 2) = uVar3 & 7;
        pbVar7 = pbVar33;
      } while (uVar23 < uVar21);
      goto LAB_000405b6;
    }
    ppuVar14 = (uint **)0x1d;
    param_1[6] = (byte *)"too many length or distance symbols";
    *puVar32 = 0x1d;
    goto LAB_0003fbe4;
  case (uint **)0x11:
    uVar21 = puVar32[0x17];
    uVar23 = puVar32[0x1a];
    if (uVar23 < uVar21) goto LAB_0004056e;
LAB_000405b6:
    if (uVar23 < 0x13) {
      puVar8 = (ushort *)(DAT_0004088c + (uVar23 - 1) * 2);
      do {
        puVar8 = puVar8 + 1;
        bVar34 = puVar8 != DAT_00040890;
        *(undefined2 *)((int)puVar32 + (*puVar8 + 0x38) * 2) = 0;
      } while (bVar34);
      puVar32[0x1a] = 0x13;
    }
    puVar32[0x1b] = (uint)(puVar32 + 0x14c);
    puVar32[0x13] = (uint)(puVar32 + 0x14c);
    puVar32[0x15] = 7;
    local_5c = inflate_table(0,puVar32 + 0x1c,0x13,puVar32 + 0x1b,puVar32 + 0x15,puVar32 + 0xbc);
    puVar12 = DAT_00040894;
    if (local_5c == 0) {
      puVar32[0x1a] = 0;
      *puVar32 = 0x12;
      puVar17 = (uint *)0x0;
LAB_0004062e:
      local_50 = (uint *)puVar32[0x18];
      uVar21 = puVar32[0x19];
      while (puVar12 = DAT_00041310, puVar17 < (uint *)(uVar21 + (int)local_50)) {
        uVar26 = puVar32[0x13];
        uVar27 = (1 << (puVar32[0x15] & 0xff)) - 1;
        uVar23 = (uint)ppuVar28 & uVar27;
        ppuVar14 = (uint **)(uint)*(byte *)(uVar26 + uVar23 * 4 + 1);
        uVar1 = *(ushort *)(uVar26 + uVar23 * 4 + 2);
        pbVar7 = pbVar33;
        if (ppuVar31 < ppuVar14) {
          do {
            pbVar33 = pbVar7;
            if (puVar30 == (uint *)0x0) goto LAB_00040332;
            pbVar33 = pbVar7 + 1;
            puVar30 = (uint *)((int)puVar30 + -1);
            uVar23 = (uint)ppuVar31 & 0xff;
            ppuVar31 = ppuVar31 + 2;
            ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar7 << uVar23));
            uVar23 = (uint)ppuVar28 & uVar27;
            ppuVar14 = (uint **)(uint)*(byte *)(uVar26 + uVar23 * 4 + 1);
            uVar1 = *(ushort *)(uVar26 + uVar23 * 4 + 2);
            pbVar7 = pbVar33;
          } while (ppuVar31 < ppuVar14);
        }
        if (uVar1 < 0x10) {
          puVar12 = puVar17 + 0xe;
          puVar17 = (uint *)((int)puVar17 + 1);
          *(ushort *)((int)puVar32 + (int)puVar12 * 2) = uVar1;
          ppuVar28 = (uint **)((uint)ppuVar28 >> (int)ppuVar14);
          ppuVar31 = (uint **)((int)ppuVar31 - (int)ppuVar14);
          puVar32[0x1a] = (uint)puVar17;
        }
        else {
          if (uVar1 == 0x10) {
            puVar12 = (uint *)((int)ppuVar14 + 2);
            for (; ppuVar31 < puVar12; ppuVar31 = ppuVar31 + 2) {
              if (puVar30 == (uint *)0x0) goto LAB_00040332;
              puVar30 = (uint *)((int)puVar30 + -1);
              ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar33 << ((uint)ppuVar31 & 0xff)));
              pbVar33 = pbVar33 + 1;
            }
            ppuVar28 = (uint **)((uint)ppuVar28 >> (int)ppuVar14);
            ppuVar31 = (uint **)((int)ppuVar31 - (int)ppuVar14);
            if (puVar17 != (uint *)0x0) {
              ppuVar31 = (uint **)((int)ppuVar31 + -2);
              uVar18 = *(undefined2 *)((int)puVar32 + ((int)puVar17 + 0x37) * 2);
              uVar23 = ((uint)ppuVar28 & 3) + 3;
              ppuVar28 = (uint **)((uint)ppuVar28 >> 2);
              goto LAB_000406fa;
            }
LAB_000412a0:
            param_4 = (char *)0x1d;
            param_1[6] = DAT_0004131c;
            ppuVar14 = (uint **)0x1d;
            *puVar32 = 0x1d;
            goto LAB_0003fbe4;
          }
          if (uVar1 == 0x11) {
            for (; ppuVar31 < (uint **)((int)ppuVar14 + 3); ppuVar31 = ppuVar31 + 2) {
              if (puVar30 == (uint *)0x0) goto LAB_00040332;
              puVar30 = (uint *)((int)puVar30 + -1);
              ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar33 << ((uint)ppuVar31 & 0xff)));
              pbVar33 = pbVar33 + 1;
            }
            ppuVar31 = (uint **)((int)ppuVar31 + (-3 - (int)ppuVar14));
            uVar23 = ((uint)ppuVar28 >> (int)ppuVar14 & 7) + 3;
            ppuVar28 = (uint **)(((uint)ppuVar28 >> (int)ppuVar14) >> 3);
            uVar18 = 0;
          }
          else {
            for (; ppuVar31 < (uint **)((int)ppuVar14 + 7); ppuVar31 = ppuVar31 + 2) {
              if (puVar30 == (uint *)0x0) goto LAB_00040332;
              puVar30 = (uint *)((int)puVar30 + -1);
              ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar33 << ((uint)ppuVar31 & 0xff)));
              pbVar33 = pbVar33 + 1;
            }
            uVar23 = (uint)ppuVar28 >> (int)ppuVar14;
            ppuVar28 = (uint **)(uVar23 >> 7);
            ppuVar31 = (uint **)((int)ppuVar31 + (-7 - (int)ppuVar14));
            uVar23 = (uVar23 & 0x7f) + 0xb;
            uVar18 = 0;
          }
LAB_000406fa:
          puVar12 = (uint *)(uVar23 + (int)puVar17);
          if ((uint *)(uVar21 + (int)local_50) < puVar12) goto LAB_000412a0;
          uVar26 = uVar23 - 1;
          uVar27 = (uint)(((int)puVar32 + (int)(puVar17 + 0xe) * 2) * 0x40000000) >> 0x1f;
          if (uVar23 < uVar27) {
            uVar27 = uVar23;
          }
          puVar19 = puVar17;
          if ((int)(uVar27 << 0x1f) < 0) {
            puVar15 = (undefined2 *)((int)puVar32 + ((int)puVar17 + 0x37) * 2);
            do {
              puVar19 = (uint *)((int)puVar19 + 1);
              puVar15 = puVar15 + 1;
              *puVar15 = uVar18;
              uVar26 = uVar26 - 1;
            } while ((uint)((int)puVar19 - (int)puVar17) < uVar27);
          }
          uVar23 = uVar23 - uVar27;
          uVar24 = uVar23 >> 1;
          uVar10 = uVar23 & 0xfffffffe;
          if (uVar24 == 0) {
LAB_000407d6:
            if (0xf < uVar26) {
              puVar16 = puVar19 + 0xe;
              puVar15 = (undefined2 *)((int)puVar32 + (int)puVar16 * 2);
              puVar17 = puVar19;
              do {
                uVar26 = uVar26 - 0x10;
                *puVar15 = uVar18;
                puVar19 = puVar17 + 4;
                HintPreloadData((int)puVar32 + (int)puVar16 * 2 + 0x50);
                puVar15[1] = uVar18;
                puVar16 = puVar17 + 0x12;
                puVar15[2] = uVar18;
                puVar15[3] = uVar18;
                puVar15[4] = uVar18;
                puVar15[5] = uVar18;
                puVar15[6] = uVar18;
                puVar15[7] = uVar18;
                puVar15[8] = uVar18;
                puVar15[9] = uVar18;
                puVar15[10] = uVar18;
                puVar15[0xb] = uVar18;
                puVar15[0xc] = uVar18;
                puVar15[0xd] = uVar18;
                puVar15[0xe] = uVar18;
                puVar15[0xf] = uVar18;
                puVar15 = puVar15 + 0x10;
                puVar17 = puVar19;
              } while (0xf < uVar26);
            }
            puVar15 = (undefined2 *)((int)puVar32 + ((int)puVar19 + 0x37) * 2);
            do {
              puVar15 = puVar15 + 1;
              *puVar15 = uVar18;
            } while (puVar15 != (undefined2 *)((int)puVar32 + ((int)puVar19 + uVar26) * 2 + 0x70));
          }
          else {
            uVar11 = CONCAT22(uVar18,uVar18);
            puVar25 = (undefined4 *)((int)puVar32 + ((int)(puVar17 + 0xe) + uVar27) * 2);
            if (uVar24 < 9) {
              uVar27 = 0;
            }
            else {
              uVar27 = 0;
              puVar4 = puVar25;
              do {
                puVar25 = puVar4 + 8;
                uVar29 = uVar27 + 9;
                uVar27 = uVar27 + 8;
                HintPreloadData(puVar4 + 0x28);
                *puVar4 = uVar11;
                puVar4[1] = uVar11;
                puVar4[2] = uVar11;
                puVar4[3] = uVar11;
                puVar4[4] = uVar11;
                puVar4[5] = uVar11;
                puVar4[6] = uVar11;
                puVar4[7] = uVar11;
                puVar4 = puVar25;
              } while (uVar29 < uVar24 - 7);
            }
            do {
              uVar27 = uVar27 + 1;
              *puVar25 = uVar11;
              puVar25 = puVar25 + 1;
            } while (uVar27 < uVar24);
            uVar26 = uVar26 - uVar10;
            puVar19 = (uint *)((int)puVar19 + uVar10);
            if (uVar23 != uVar10) goto LAB_000407d6;
          }
          puVar32[0x1a] = (uint)puVar12;
          puVar17 = puVar12;
        }
      }
      if (*(short *)(puVar32 + 0x9c) == 0) {
        param_4 = (char *)0x1d;
        ppuVar14 = (uint **)0x1d;
        param_1[6] = (byte *)DAT_00041310;
        *puVar32 = 0x1d;
      }
      else {
        puVar32[0x1b] = (uint)(puVar32 + 0x14c);
        puVar32[0x13] = (uint)(puVar32 + 0x14c);
        puVar32[0x15] = 9;
        local_5c = inflate_table(1,puVar32 + 0x1c,local_50,puVar32 + 0x1b,puVar32 + 0x15,
                                 puVar32 + 0xbc);
        puVar12 = DAT_00041318;
        if (local_5c == 0) {
          puVar32[0x16] = 6;
          puVar32[0x14] = puVar32[0x1b];
          uVar36 = inflate_table(2,(int)puVar32 + (puVar32[0x18] + 0x38) * 2,puVar32[0x19],
                                 puVar32 + 0x1b,puVar32 + 0x16,puVar32 + 0xbc);
          puVar12 = DAT_00041320;
          local_5c = (int)uVar36;
          if (local_5c == 0) {
            *puVar32 = 0x13;
            if (param_2 == (uint *)0x6) goto LAB_00040332;
switchD_0003fbea_caseD_13:
            param_4 = (char *)0x14;
            *puVar32 = 0x14;
switchD_0003fbea_caseD_14:
            uVar21 = (uint)((ulonglong)uVar36 >> 0x20);
            local_5c = (int)uVar36;
            bVar35 = (uint *)0x101 < local_70;
            bVar34 = local_70 == (uint *)0x102;
            if (bVar35) {
              bVar34 = puVar30 == (uint *)0x5;
            }
            if ((!bVar35 || (uint *)0x4 >= puVar30) || bVar34) {
              uVar21 = 0;
            }
            if ((bVar35 && (uint *)0x4 < puVar30) && !bVar34) {
              param_1[4] = (byte *)local_70;
              *param_1 = pbVar33;
              param_1[3] = (byte *)local_6c;
              param_1[1] = (byte *)puVar30;
              puVar32[0xe] = (uint)ppuVar28;
              puVar32[0xf] = (uint)ppuVar31;
              inflate_fast(param_1,local_68);
              ppuVar14 = (uint **)*puVar32;
              ppuVar28 = (uint **)puVar32[0xe];
              local_6c = (uint *)param_1[3];
              local_70 = (uint *)param_1[4];
              bVar34 = ppuVar14 == (uint **)0xb;
              if (bVar34) {
                param_4 = (char *)0xffffffff;
              }
              pbVar33 = *param_1;
              puVar17 = local_6c;
              if (bVar34) {
                puVar17 = puVar32 + 0x6f0;
              }
              puVar30 = (uint *)param_1[1];
              ppuVar31 = (uint **)puVar32[0xf];
              puVar12 = extraout_r1_00;
              if (bVar34) {
                puVar17[1] = (uint)param_4;
              }
            }
            else {
              uVar23 = puVar32[0x13];
              puVar32[0x6f1] = uVar21;
              ppuVar14 = (uint **)(puVar32 + 0x6f1);
              uVar27 = (1 << (puVar32[0x15] & 0xff)) - 1;
              uVar21 = (uint)ppuVar28 & uVar27;
              bVar2 = *(byte *)(uVar23 + uVar21 * 4);
              param_4 = (char *)(uint)*(byte *)(uVar23 + uVar21 * 4 + 1);
              uVar1 = *(ushort *)(uVar23 + uVar21 * 4 + 2);
              pbVar7 = pbVar33;
              if (ppuVar31 < param_4) {
                do {
                  pbVar33 = pbVar7;
                  if (puVar30 == (uint *)0x0) goto LAB_00040332;
                  pbVar33 = pbVar7 + 1;
                  puVar30 = (uint *)((int)puVar30 + -1);
                  uVar21 = (uint)ppuVar31 & 0xff;
                  ppuVar31 = ppuVar31 + 2;
                  ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar7 << uVar21));
                  uVar21 = (uint)ppuVar28 & uVar27;
                  bVar2 = *(byte *)(uVar23 + uVar21 * 4);
                  param_4 = (char *)(uint)*(byte *)(uVar23 + uVar21 * 4 + 1);
                  uVar1 = *(ushort *)(uVar23 + uVar21 * 4 + 2);
                  pbVar7 = pbVar33;
                } while (ppuVar31 < param_4);
              }
              puVar12 = (uint *)(uint)bVar2;
              uVar21 = (uint)uVar1;
              if (puVar12 == (uint *)0x0) {
                ppuVar28 = (uint **)((uint)ppuVar28 >> (int)param_4);
                ppuVar31 = (uint **)((int)ppuVar31 - (int)param_4);
                puVar32[0x10] = uVar21;
                *ppuVar14 = (uint *)param_4;
LAB_0003fe6c:
                ppuVar14 = (uint **)0x19;
                *puVar32 = 0x19;
              }
              else {
                if ((bVar2 & 0xf0) == 0) {
                  uVar27 = (1 << ((int)param_4 + (int)puVar12 & 0xffU)) - 1;
                  iVar6 = ((uVar27 & (uint)ppuVar28) >> (int)param_4) + uVar21;
                  bVar2 = *(byte *)(uVar23 + iVar6 * 4);
                  uVar26 = (uint)*(byte *)(uVar23 + iVar6 * 4 + 1);
                  uVar1 = *(ushort *)(uVar23 + iVar6 * 4 + 2);
                  ppuVar20 = (uint **)((int)param_4 + uVar26);
                  pbVar7 = pbVar33;
                  if (ppuVar31 < ppuVar20) {
                    do {
                      pbVar33 = pbVar7;
                      if (puVar30 == (uint *)0x0) goto LAB_00040332;
                      pbVar33 = pbVar7 + 1;
                      puVar30 = (uint *)((int)puVar30 + -1);
                      uVar26 = (uint)ppuVar31 & 0xff;
                      ppuVar31 = ppuVar31 + 2;
                      ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar7 << uVar26));
                      iVar6 = (((uint)ppuVar28 & uVar27) >> (int)param_4) + uVar21;
                      bVar2 = *(byte *)(uVar23 + iVar6 * 4);
                      uVar26 = (uint)*(byte *)(uVar23 + iVar6 * 4 + 1);
                      uVar1 = *(ushort *)(uVar23 + iVar6 * 4 + 2);
                      ppuVar20 = (uint **)(uVar26 + (int)param_4);
                      local_50 = puVar32;
                      pbVar7 = pbVar33;
                    } while (ppuVar31 < ppuVar20);
                  }
                  puVar12 = (uint *)(uint)bVar2;
                  ppuVar31 = (uint **)((int)ppuVar31 + (-uVar26 - (int)param_4));
                  ppuVar28 = (uint **)(((uint)ppuVar28 >> (int)param_4) >> uVar26);
                  puVar32[0x10] = (uint)uVar1;
                  *ppuVar14 = (uint *)ppuVar20;
                  param_4 = (char *)ppuVar14;
                  if (puVar12 == (uint *)0x0) goto LAB_0003fe6c;
                }
                else {
                  ppuVar28 = (uint **)((uint)ppuVar28 >> (int)param_4);
                  ppuVar31 = (uint **)((int)ppuVar31 - (int)param_4);
                  puVar32[0x10] = uVar21;
                  *ppuVar14 = (uint *)param_4;
                }
                puVar17 = DAT_0004105c;
                if ((int)puVar12 << 0x1a < 0) {
                  param_4 = (char *)0xb;
                  *puVar32 = 0xb;
                  *ppuVar14 = (uint *)0xffffffff;
                  ppuVar14 = (uint **)0xb;
                }
                else {
                  if ((int)puVar12 << 0x19 < 0) {
                    param_4 = (char *)0x1d;
                    ppuVar14 = (uint **)0x1d;
                    param_1[6] = (byte *)DAT_0004105c;
                    *puVar32 = 0x1d;
                    puVar12 = puVar17;
                    goto LAB_0003fbe4;
                  }
                  ppuVar14 = (uint **)((uint)puVar12 & 0xf);
                  puVar32[0x12] = (uint)ppuVar14;
                  *puVar32 = 0x15;
joined_r0x0004030e:
                  if (ppuVar14 == (uint **)0x0) {
                    uVar21 = puVar32[0x10];
                  }
                  else {
                    for (; ppuVar31 < ppuVar14; ppuVar31 = ppuVar31 + 2) {
                      if (puVar30 == (uint *)0x0) goto LAB_00040332;
                      puVar30 = (uint *)((int)puVar30 + -1);
                      ppuVar28 = (uint **)((int)ppuVar28 +
                                          ((uint)*pbVar33 << ((uint)ppuVar31 & 0xff)));
                      pbVar33 = pbVar33 + 1;
                    }
                    ppuVar31 = (uint **)((int)ppuVar31 - (int)ppuVar14);
                    uVar21 = (uint)ppuVar28 & (1 << ((uint)ppuVar14 & 0xff)) - 1U;
                    ppuVar28 = (uint **)((uint)ppuVar28 >> ((uint)ppuVar14 & 0xff));
                    uVar21 = uVar21 + puVar32[0x10];
                    puVar32[0x10] = uVar21;
                    puVar32[0x6f1] = (int)ppuVar14 + puVar32[0x6f1];
                  }
                  puVar32[0x6f2] = uVar21;
                  *puVar32 = 0x16;
switchD_0003fbea_caseD_16:
                  uVar21 = puVar32[0x14];
                  uVar27 = (1 << (puVar32[0x16] & 0xff)) - 1;
                  uVar23 = (uint)ppuVar28 & uVar27;
                  bVar2 = *(byte *)(uVar21 + uVar23 * 4);
                  ppuVar14 = (uint **)(uint)*(byte *)(uVar21 + uVar23 * 4 + 1);
                  uVar1 = *(ushort *)(uVar21 + uVar23 * 4 + 2);
                  pbVar7 = pbVar33;
                  if (ppuVar31 < ppuVar14) {
                    do {
                      pbVar33 = pbVar7;
                      if (puVar30 == (uint *)0x0) goto LAB_00040332;
                      pbVar33 = pbVar7 + 1;
                      puVar30 = (uint *)((int)puVar30 + -1);
                      uVar23 = (uint)ppuVar31 & 0xff;
                      ppuVar31 = ppuVar31 + 2;
                      ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar7 << uVar23));
                      uVar23 = (uint)ppuVar28 & uVar27;
                      bVar2 = *(byte *)(uVar21 + uVar23 * 4);
                      ppuVar14 = (uint **)(uint)*(byte *)(uVar21 + uVar23 * 4 + 1);
                      uVar1 = *(ushort *)(uVar21 + uVar23 * 4 + 2);
                      pbVar7 = pbVar33;
                    } while (ppuVar31 < ppuVar14);
                  }
                  uVar27 = (uint)bVar2;
                  uVar23 = (uint)uVar1;
                  if ((bVar2 & 0xf0) == 0) {
                    uVar27 = (1 << ((int)ppuVar14 + uVar27 & 0xff)) - 1;
                    iVar6 = ((uVar27 & (uint)ppuVar28) >> (int)ppuVar14) + uVar23;
                    bVar2 = *(byte *)(uVar21 + iVar6 * 4);
                    ppuVar20 = (uint **)(uint)*(byte *)(uVar21 + iVar6 * 4 + 1);
                    uVar1 = *(ushort *)(uVar21 + iVar6 * 4 + 2);
                    pbVar7 = pbVar33;
                    if (ppuVar31 < (uint **)((int)ppuVar14 + (int)ppuVar20)) {
                      do {
                        pbVar33 = pbVar7;
                        if (puVar30 == (uint *)0x0) goto LAB_00040332;
                        pbVar33 = pbVar7 + 1;
                        puVar30 = (uint *)((int)puVar30 + -1);
                        uVar26 = (uint)ppuVar31 & 0xff;
                        ppuVar31 = ppuVar31 + 2;
                        ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar7 << uVar26));
                        iVar6 = (((uint)ppuVar28 & uVar27) >> (int)ppuVar14) + uVar23;
                        bVar2 = *(byte *)(uVar21 + iVar6 * 4);
                        ppuVar20 = (uint **)(uint)*(byte *)(uVar21 + iVar6 * 4 + 1);
                        uVar1 = *(ushort *)(uVar21 + iVar6 * 4 + 2);
                        local_50 = puVar32;
                        pbVar7 = pbVar33;
                      } while (ppuVar31 < (uint **)((int)ppuVar20 + (int)ppuVar14));
                    }
                    uVar27 = (uint)bVar2;
                    uVar23 = (uint)uVar1;
                    ppuVar31 = (uint **)((int)ppuVar31 - (int)ppuVar14);
                    ppuVar28 = (uint **)((uint)ppuVar28 >> (int)ppuVar14);
                    uVar21 = (int)ppuVar14 + puVar32[0x6f1];
                    ppuVar14 = ppuVar20;
                  }
                  else {
                    uVar21 = puVar32[0x6f1];
                  }
                  ppuVar28 = (uint **)((uint)ppuVar28 >> (int)ppuVar14);
                  ppuVar31 = (uint **)((int)ppuVar31 - (int)ppuVar14);
                  puVar32[0x6f1] = uVar21 + (int)ppuVar14;
                  puVar12 = DAT_0004104c;
                  if (-1 < (int)(uVar27 << 0x19)) {
                    ppuVar14 = (uint **)(uVar27 & 0xf);
                    puVar32[0x12] = (uint)ppuVar14;
                    puVar32[0x11] = uVar23;
                    *puVar32 = 0x17;
joined_r0x00040320:
                    if (ppuVar14 != (uint **)0x0) {
                      for (; ppuVar31 < ppuVar14; ppuVar31 = ppuVar31 + 2) {
                        if (puVar30 == (uint *)0x0) goto LAB_00040332;
                        puVar30 = (uint *)((int)puVar30 + -1);
                        ppuVar28 = (uint **)((int)ppuVar28 +
                                            ((uint)*pbVar33 << ((uint)ppuVar31 & 0xff)));
                        pbVar33 = pbVar33 + 1;
                      }
                      ppuVar31 = (uint **)((int)ppuVar31 - (int)ppuVar14);
                      uVar21 = (uint)ppuVar28 & (1 << ((uint)ppuVar14 & 0xff)) - 1U;
                      ppuVar28 = (uint **)((uint)ppuVar28 >> ((uint)ppuVar14 & 0xff));
                      puVar32[0x11] = puVar32[0x11] + uVar21;
                      puVar32[0x6f1] = (int)ppuVar14 + puVar32[0x6f1];
                    }
                    *puVar32 = 0x18;
switchD_0003fbea_caseD_18:
                    puVar12 = DAT_0004005c;
                    if (local_70 == (uint *)0x0) goto LAB_00040332;
                    uVar21 = puVar32[0x11];
                    if ((uint)((int)local_68 - (int)local_70) < uVar21) {
                      puVar19 = (uint *)(uVar21 - ((int)local_68 - (int)local_70));
                      if (((uint *)puVar32[0xb] < puVar19) && (puVar32[0x6f0] != 0)) {
                        param_4 = (char *)0x1d;
                        ppuVar14 = (uint **)0x1d;
                        param_1[6] = (byte *)DAT_0004005c;
                        *puVar32 = 0x1d;
                        goto LAB_0003fbe4;
                      }
                      puVar16 = (uint *)puVar32[0xc];
                      if (puVar16 < puVar19) {
                        puVar12 = (uint *)((int)puVar19 - (int)puVar16);
                        puVar13 = (uint *)(puVar32[10] - (int)puVar12);
                        local_50 = (uint *)(puVar32[0xd] + (int)puVar13);
                      }
                      else {
                        puVar13 = (uint *)((int)puVar16 + (puVar32[0xd] - (int)puVar19));
                        puVar12 = puVar19;
                      }
                      puVar17 = (uint *)puVar32[0x10];
                      if (puVar19 <= puVar16) {
                        local_50 = puVar13;
                      }
                      if (puVar17 <= puVar12) {
                        puVar12 = puVar17;
                      }
                    }
                    else {
                      puVar17 = (uint *)puVar32[0x10];
                      local_50 = (uint *)((int)local_6c - uVar21);
                      puVar12 = puVar17;
                    }
                    puVar19 = local_70;
                    if (puVar12 < local_70) {
                      puVar19 = puVar12;
                    }
                    uVar21 = (uint)puVar19 >> 2;
                    puVar32[0x10] = (int)puVar17 - (int)puVar19;
                    puVar16 = (uint *)((uint)puVar19 & 0xfffffffc);
                    local_70 = (uint *)((int)local_70 - (int)puVar19);
                    puVar12 = puVar19;
                    puVar17 = local_6c;
                    if (uVar21 == 0 ||
                        ((((uint)local_50 | (uint)local_6c) & 3) != 0 ||
                        (puVar19 < (uint *)0x4 || local_50 < local_6c + 1 && local_6c < local_50 + 1
                        ))) {
LAB_00040be8:
                      puVar12 = (uint *)((int)puVar17 + (int)puVar12);
                      puVar9 = (undefined *)((int)local_50 + -1);
                      do {
                        puVar9 = puVar9 + 1;
                        puVar16 = (uint *)((int)puVar17 + 1);
                        *(undefined *)puVar17 = *puVar9;
                        puVar17 = puVar16;
                      } while (puVar16 != puVar12);
                    }
                    else {
                      if (uVar21 < 9) {
                        uVar23 = 0;
                        puVar12 = local_50;
                      }
                      else {
                        uVar23 = 0;
                        puVar13 = local_6c;
                        puVar5 = local_50;
                        do {
                          puVar12 = puVar5 + 8;
                          puVar17 = puVar13 + 8;
                          uVar27 = uVar23 + 9;
                          uVar23 = uVar23 + 8;
                          HintPreloadData(puVar5 + 0x1d);
                          *puVar13 = *puVar5;
                          puVar13[1] = puVar5[1];
                          puVar13[2] = puVar5[2];
                          puVar13[3] = puVar5[3];
                          puVar13[4] = puVar5[4];
                          puVar13[5] = puVar5[5];
                          puVar13[6] = puVar5[6];
                          puVar13[7] = puVar5[7];
                          puVar13 = puVar17;
                          puVar5 = puVar12;
                        } while (uVar27 < uVar21 - 7);
                      }
                      puVar12 = puVar12 + -1;
                      do {
                        puVar12 = puVar12 + 1;
                        uVar23 = uVar23 + 1;
                        *puVar17 = *puVar12;
                        puVar17 = puVar17 + 1;
                      } while (uVar23 < uVar21);
                      local_50 = (uint *)((int)local_50 + (int)puVar16);
                      puVar12 = (uint *)((int)puVar19 - (int)puVar16);
                      puVar17 = (uint *)((int)local_6c + (int)puVar16);
                      if (puVar16 != puVar19) goto LAB_00040be8;
                    }
                    param_4 = (char *)puVar32[0x10];
                    local_6c = (uint *)((int)local_6c + (int)puVar19);
                    if ((uint **)param_4 == (uint **)0x0) {
                      ppuVar14 = (uint **)0x14;
                      *puVar32 = 0x14;
                    }
                    else {
                      ppuVar14 = (uint **)*puVar32;
                    }
                    goto LAB_0003fbe4;
                  }
                  param_4 = (char *)0x1d;
                  ppuVar14 = (uint **)0x1d;
                  param_1[6] = (byte *)DAT_0004104c;
                  *puVar32 = 0x1d;
                }
              }
            }
          }
          else {
            param_4 = (char *)0x1d;
            ppuVar14 = (uint **)0x1d;
            param_1[6] = (byte *)DAT_00041320;
            *puVar32 = 0x1d;
          }
        }
        else {
          param_4 = (char *)0x1d;
          ppuVar14 = (uint **)0x1d;
          param_1[6] = (byte *)DAT_00041318;
          *puVar32 = 0x1d;
        }
      }
    }
    else {
      param_4 = (char *)0x1d;
      ppuVar14 = (uint **)0x1d;
      param_1[6] = (byte *)DAT_00040894;
      *puVar32 = 0x1d;
    }
    goto LAB_0003fbe4;
  case (uint **)0x12:
    puVar17 = (uint *)puVar32[0x1a];
    goto LAB_0004062e;
  case (uint **)0x13:
    goto switchD_0003fbea_caseD_13;
  case (uint **)0x14:
    goto switchD_0003fbea_caseD_14;
  case (uint **)0x15:
    ppuVar14 = (uint **)puVar32[0x12];
    goto joined_r0x0004030e;
  case (uint **)0x16:
    goto switchD_0003fbea_caseD_16;
  case (uint **)0x17:
    ppuVar14 = (uint **)puVar32[0x12];
    goto joined_r0x00040320;
  case (uint **)0x18:
    goto switchD_0003fbea_caseD_18;
  case (uint **)0x19:
    if (local_70 == (uint *)0x0) goto LAB_00040332;
    param_4 = (char *)0x14;
    puVar12 = (uint *)puVar32[0x10];
    local_70 = (uint *)((int)local_70 + -1);
    ppuVar14 = (uint **)0x14;
    *(char *)local_6c = (char)puVar12;
    *puVar32 = 0x14;
    local_6c = (uint *)((int)local_6c + 1);
    goto LAB_0003fbe4;
  case (uint **)0x1a:
    uVar21 = puVar32[2];
    if (uVar21 == 0) {
LAB_00040c86:
      *puVar32 = 0x1b;
      goto LAB_0004093e;
    }
    for (; ppuVar31 < (uint **)0x20; ppuVar31 = ppuVar31 + 2) {
      if (puVar30 == (uint *)0x0) goto LAB_00040332;
      puVar30 = (uint *)((int)puVar30 + -1);
      ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar33 << ((uint)ppuVar31 & 0xff)));
      pbVar33 = pbVar33 + 1;
    }
    uVar21 = puVar32[7];
    iVar6 = (int)local_68 - (int)local_70;
    param_1[5] = param_1[5] + iVar6;
    puVar32[7] = uVar21 + iVar6;
    if (iVar6 != 0) {
      if (puVar32[4] == 0) {
        pbVar7 = (byte *)adler32(puVar32[6],(int)local_6c - iVar6);
      }
      else {
        pbVar7 = (byte *)crc32(puVar32[6],(int)local_6c - iVar6);
      }
      puVar32[6] = (uint)pbVar7;
      param_1[0xc] = pbVar7;
    }
    puVar12 = DAT_00040c1c;
    ppuVar14 = ppuVar28;
    if (puVar32[4] == 0) {
      ppuVar14 = (uint **)(((uint)ppuVar28 >> 0x18) + (int)ppuVar28 * 0x1000000 +
                           ((uint)ppuVar28 >> 8 & 0xff00) + ((uint)ppuVar28 & 0xff00) * 0x100);
    }
    if (ppuVar14 == (uint **)puVar32[6]) {
      uVar21 = puVar32[2];
      ppuVar31 = (uint **)0x0;
      ppuVar28 = (uint **)0x0;
      local_68 = local_70;
      goto LAB_00040c86;
    }
    param_4 = (char *)0x1d;
    ppuVar14 = (uint **)0x1d;
    param_1[6] = (byte *)DAT_00040c1c;
    local_68 = local_70;
    *puVar32 = 0x1d;
    goto LAB_0003fbe4;
  case (uint **)0x1b:
    uVar21 = puVar32[2];
LAB_0004093e:
    puVar12 = DAT_00040c20;
    if ((uVar21 != 0) && (puVar32[4] != 0)) {
      for (; ppuVar31 < (uint **)0x20; ppuVar31 = ppuVar31 + 2) {
        if (puVar30 == (uint *)0x0) goto LAB_00040332;
        puVar30 = (uint *)((int)puVar30 + -1);
        ppuVar28 = (uint **)((int)ppuVar28 + ((uint)*pbVar33 << ((uint)ppuVar31 & 0xff)));
        pbVar33 = pbVar33 + 1;
      }
      if ((uint **)puVar32[7] != ppuVar28) {
        ppuVar14 = (uint **)0x1d;
        param_1[6] = (byte *)DAT_00040c20;
        *puVar32 = 0x1d;
        param_4 = (char *)ppuVar14;
        goto LAB_0003fbe4;
      }
      ppuVar31 = (uint **)0x0;
      ppuVar28 = (uint **)0x0;
    }
    local_5c = 1;
    *puVar32 = 0x1c;
    goto LAB_00040332;
  case (uint **)0x1c:
    goto switchD_0003fbea_caseD_1c;
  case (uint **)0x1d:
    local_5c = -3;
    goto LAB_00040332;
  case (uint **)0x1e:
    return -4;
  default:
    goto switchD_0003fbea_caseD_1f;
  }
  puVar12 = DAT_000404e4;
  param_4 = (char *)0x1d;
  ppuVar14 = (uint **)0x1d;
  param_1[6] = (byte *)DAT_000404e4;
  *puVar32 = 0x1d;
  goto LAB_0003fbe4;
switchD_0003fbea_caseD_1c:
  local_5c = 1;
LAB_00040332:
  uVar21 = puVar32[10];
  *param_1 = pbVar33;
  param_1[3] = (byte *)local_6c;
  param_1[4] = (byte *)local_70;
  param_1[1] = (byte *)puVar30;
  puVar32[0xe] = (uint)ppuVar28;
  puVar32[0xf] = (uint)ppuVar31;
  if (((uVar21 != 0) ||
      (((local_70 != local_68 && (*puVar32 < 0x1d)) &&
       ((*puVar32 < 0x1a || (param_2 != (uint *)0x4)))))) &&
     (iVar6 = updatewindow(param_1,local_6c,(int)local_68 - (int)local_70), iVar6 != 0)) {
    *puVar32 = 0x1e;
    return -4;
  }
  pbVar33 = param_1[1];
  uVar23 = puVar32[7];
  uVar27 = (int)local_68 - (int)param_1[4];
  uVar21 = puVar32[2];
  param_1[2] = param_1[2] + ((int)local_64 - (int)pbVar33);
  param_1[5] = param_1[5] + uVar27;
  puVar32[7] = uVar23 + uVar27;
  if ((uVar21 != 0) && (uVar27 != 0)) {
    if (puVar32[4] == 0) {
      pbVar7 = (byte *)adler32(puVar32[6],(int)param_1[3] - uVar27,uVar27);
    }
    else {
      pbVar7 = (byte *)crc32();
    }
    puVar32[6] = (uint)pbVar7;
    param_1[0xc] = pbVar7;
  }
  uVar21 = *puVar32;
  if (puVar32[1] == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 0x40;
  }
  iVar6 = iVar6 + puVar32[0xf];
  if (uVar21 == 0xb) {
    iVar6 = iVar6 + 0x80;
  }
  else if (uVar21 == 0x13 || uVar21 == 0xe) {
    iVar22 = 0x100;
    goto LAB_00040404;
  }
  iVar22 = 0;
LAB_00040404:
  param_1[0xb] = (byte *)(iVar6 + iVar22);
  if ((((uVar27 | (int)local_64 - (int)pbVar33) == 0) || (param_2 == (uint *)0x4)) &&
     (local_5c == 0)) {
    local_5c = -5;
  }
  return local_5c;
}

