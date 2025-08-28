
/* WARNING: Type propagation algorithm not settling */

int inflate(undefined4 *param_1,uint *param_2)

{
  ushort uVar1;
  byte bVar2;
  ushort uVar3;
  char *pcVar4;
  int iVar5;
  ushort *puVar6;
  char *pcVar7;
  uint *extraout_r1;
  undefined4 uVar8;
  uint *puVar9;
  uint *extraout_r1_00;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  undefined2 uVar15;
  uint *puVar16;
  byte *pbVar17;
  int iVar18;
  uint extraout_r3;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint *puVar25;
  uint uVar26;
  uint *puVar27;
  uint *puVar28;
  uint *puVar29;
  byte *__src;
  bool bVar30;
  bool bVar31;
  undefined8 uVar32;
  uint *local_70;
  uint *local_6c;
  uint *local_68;
  uint *local_64;
  int local_5c;
  uint *local_50;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  
  if (((param_1 == (undefined4 *)0x0) || (puVar29 = (uint *)param_1[7], puVar29 == (uint *)0x0)) ||
     (local_6c = (uint *)param_1[3], local_6c == (uint *)0x0)) {
LAB_0003ff9c:
    return -2;
  }
  __src = (byte *)*param_1;
  if (__src == (byte *)0x0) {
    if (param_1[1] != 0) {
      return -2;
    }
    local_64 = (uint *)0x0;
  }
  else {
    local_64 = (uint *)param_1[1];
  }
  uVar10 = *puVar29;
  puVar25 = (uint *)puVar29[0xe];
  bVar30 = uVar10 == 0xb;
  puVar28 = (uint *)puVar29[0xf];
  if (bVar30) {
    uVar10 = 0xc;
  }
  local_70 = (uint *)param_1[4];
  local_5c = 0;
  puVar12 = param_2;
  puVar27 = local_64;
  local_68 = local_70;
  if (bVar30) {
    *puVar29 = uVar10;
  }
LAB_0003fbe4:
  uVar32 = CONCAT44(puVar12,local_5c);
  switch(uVar10) {
  case 0:
    uVar10 = puVar29[2];
    if (uVar10 == 0) {
      uVar10 = 0xc;
      *puVar29 = 0xc;
      puVar12 = (uint *)0x0;
      goto LAB_0003fbe4;
    }
    for (; puVar28 < (uint *)0x10; puVar28 = puVar28 + 2) {
      if (puVar27 == (uint *)0x0) goto LAB_00040332;
      puVar27 = (uint *)((int)puVar27 + -1);
      puVar25 = (uint *)((int)puVar25 + ((uint)*__src << ((uint)puVar28 & 0xff)));
      __src = __src + 1;
    }
    if (((int)(uVar10 << 0x1e) < 0) && (puVar25 == (uint *)((int)&__DT_SYMTAB[0x4c].st_value + 3)))
    {
      puVar28 = (uint *)0x0;
      uVar10 = crc32(0,0,0);
      local_2c = 0x1f;
      puVar29[6] = uVar10;
      local_2b = 0x8b;
      puVar25 = (uint *)0x0;
      uVar32 = crc32(uVar10,&local_2c,2);
      uVar10 = 1;
      puVar29[6] = (uint)uVar32;
      *puVar29 = 1;
      puVar12 = (uint *)((ulonglong)uVar32 >> 0x20);
      goto LAB_0003fbe4;
    }
    puVar29[4] = 0;
    if (puVar29[8] != 0) {
      *(undefined4 *)(puVar29[8] + 0x30) = 0xffffffff;
    }
    if ((-1 < (int)(uVar10 << 0x1f)) ||
       (uVar10 = ((uint)puVar25 & 0xff) * 0x100 + ((uint)puVar25 >> 8),
       uVar10 != (uVar10 / 0x1f + (uVar10 - uVar10 / 0x1f >> 1) >> 4) * 0x1f)) {
      uVar10 = 0x1d;
      param_1[6] = "incorrect header check";
      *puVar29 = 0x1d;
      puVar12 = (uint *)"incorrect header check";
      goto LAB_0003fbe4;
    }
    if (((uint)puVar25 & 0xf) == 8) {
      puVar25 = (uint *)((uint)puVar25 >> 4);
      uVar10 = ((uint)puVar25 & 0xf) + 8;
      if (puVar29[9] == 0) {
        puVar29[9] = uVar10;
      }
      else if (puVar29[9] < uVar10) {
        puVar28 = puVar28 + -1;
        uVar10 = 0x1d;
        param_1[6] = "invalid window size";
        *puVar29 = 0x1d;
        puVar12 = (uint *)"invalid window size";
        goto LAB_0003fbe4;
      }
      puVar29[5] = 1 << uVar10;
      uVar32 = adler32(0,0,0);
      if (((uint)puVar25 & 0x200) == 0) {
        uVar10 = 0xb;
      }
      else {
        uVar10 = 9;
      }
      puVar28 = (uint *)0x0;
      puVar29[6] = (uint)uVar32;
      param_1[0xc] = (uint)uVar32;
      *puVar29 = uVar10;
      puVar12 = (uint *)((ulonglong)uVar32 >> 0x20);
      puVar25 = puVar28;
      goto LAB_0003fbe4;
    }
    break;
  case 1:
    for (; puVar28 < (uint *)0x10; puVar28 = puVar28 + 2) {
      if (puVar27 == (uint *)0x0) goto LAB_00040332;
      puVar27 = (uint *)((int)puVar27 + -1);
      puVar25 = (uint *)((int)puVar25 + ((uint)*__src << ((uint)puVar28 & 0xff)));
      __src = __src + 1;
    }
    puVar29[4] = (uint)puVar25;
    if (((uint)puVar25 & 0xff) == 8) {
      if (((uint)puVar25 & 0xe000) == 0) {
        if ((uint *)puVar29[8] != (uint *)0x0) {
          *(uint *)puVar29[8] = (uint)((int)puVar25 << 0x17) >> 0x1f;
        }
        if (((uint)puVar25 & 0x200) != 0) {
          local_2b = (undefined1)((uint)puVar25 >> 8);
          local_2c = (char)puVar25;
          uVar10 = crc32(puVar29[6],&local_2c,2);
          puVar29[6] = uVar10;
        }
        puVar28 = (uint *)0x0;
        puVar25 = (uint *)0x0;
        *puVar29 = 2;
        pbVar17 = __src;
LAB_0003ffaa:
        __src = pbVar17;
        if (puVar27 != (uint *)0x0) {
          while( true ) {
            __src = pbVar17 + 1;
            puVar27 = (uint *)((int)puVar27 + -1);
            uVar10 = (uint)puVar28 & 0xff;
            puVar28 = puVar28 + 2;
            puVar25 = (uint *)((int)puVar25 + ((uint)*pbVar17 << uVar10));
            if ((uint *)0x1f < puVar28) break;
            pbVar17 = __src;
            if (puVar27 == (uint *)0x0) goto LAB_00040332;
          }
          goto LAB_0003ffd2;
        }
        goto LAB_00040332;
      }
      uVar10 = 0x1d;
      param_1[6] = "unknown header flags set";
      *puVar29 = 0x1d;
      goto LAB_0003fbe4;
    }
    break;
  case 2:
    pbVar17 = __src;
    if (puVar28 < (uint *)0x20) goto LAB_0003ffaa;
LAB_0003ffd2:
    if (puVar29[8] != 0) {
      *(uint **)(puVar29[8] + 4) = puVar25;
    }
    if ((int)(puVar29[4] << 0x16) < 0) {
      local_2b = (undefined1)((uint)puVar25 >> 8);
      local_2c = SUB41(puVar25,0);
      local_2a = (undefined1)((uint)puVar25 >> 0x10);
      local_29 = (undefined1)((uint)puVar25 >> 0x18);
      uVar10 = crc32(puVar29[6],&local_2c,4);
      puVar29[6] = uVar10;
    }
    puVar25 = (uint *)0x0;
    puVar28 = (uint *)0x0;
    *puVar29 = 3;
    pbVar17 = __src;
LAB_0003fff2:
    __src = pbVar17;
    if (puVar27 != (uint *)0x0) {
      while( true ) {
        __src = pbVar17 + 1;
        puVar27 = (uint *)((int)puVar27 + -1);
        uVar10 = (uint)puVar28 & 0xff;
        puVar28 = puVar28 + 2;
        puVar25 = (uint *)((int)puVar25 + ((uint)*pbVar17 << uVar10));
        if ((uint *)0xf < puVar28) break;
        pbVar17 = __src;
        if (puVar27 == (uint *)0x0) goto LAB_00040332;
      }
      goto LAB_0004001a;
    }
    goto LAB_00040332;
  case 3:
    pbVar17 = __src;
    if (puVar28 < (uint *)0x10) goto LAB_0003fff2;
LAB_0004001a:
    uVar10 = puVar29[8];
    if (uVar10 != 0) {
      *(uint *)(uVar10 + 8) = (uint)puVar25 & 0xff;
      *(uint *)(uVar10 + 0xc) = (uint)puVar25 >> 8;
    }
    uVar10 = puVar29[4];
    if ((int)(uVar10 << 0x16) < 0) {
      local_2b = (undefined1)((uint)puVar25 >> 8);
      local_2c = (char)puVar25;
      uVar19 = crc32(puVar29[6],&local_2c,2);
      uVar10 = puVar29[4];
      puVar29[6] = uVar19;
    }
    *puVar29 = 4;
    if ((uVar10 & 0x400) == 0) {
      puVar28 = (uint *)0x0;
      puVar25 = (uint *)0x0;
LAB_00040a3a:
      uVar24 = puVar29[8];
      uVar19 = uVar24;
      if (uVar24 != 0) {
        uVar19 = 0;
        *(undefined4 *)(uVar24 + 0x10) = 0;
      }
    }
    else {
      puVar28 = (uint *)0x0;
      puVar25 = (uint *)0x0;
      do {
        if (puVar27 == (uint *)0x0) goto LAB_00040332;
        puVar27 = (uint *)((int)puVar27 + -1);
        uVar19 = (uint)puVar28 & 0xff;
        puVar28 = puVar28 + 2;
        puVar25 = (uint *)((int)puVar25 + ((uint)*__src << uVar19));
        __src = __src + 1;
joined_r0x000409b0:
      } while (puVar28 < (uint *)0x10);
      puVar29[0x10] = (uint)puVar25;
      if (puVar29[8] != 0) {
        *(uint **)(puVar29[8] + 0x14) = puVar25;
      }
      if ((uVar10 & 0x200) == 0) {
        puVar28 = (uint *)0x0;
        puVar25 = (uint *)0x0;
        uVar19 = uVar10 & 0x400;
      }
      else {
        local_2c = SUB41(puVar25,0);
        local_2b = (undefined1)((uint)puVar25 >> 8);
        puVar25 = (uint *)0x0;
        uVar19 = crc32(puVar29[6],&local_2c,2);
        uVar10 = puVar29[4];
        puVar28 = (uint *)0x0;
        puVar29[6] = uVar19;
        uVar19 = uVar10 & 0x400;
      }
    }
    *puVar29 = 5;
LAB_000400a4:
    if (uVar19 != 0) {
      puVar14 = (uint *)puVar29[0x10];
      puVar12 = puVar27;
      if (puVar14 <= puVar27) {
        puVar12 = puVar14;
      }
      if (puVar12 != (uint *)0x0) {
        uVar19 = puVar29[8];
        if ((uVar19 != 0) && (*(int *)(uVar19 + 0x10) != 0)) {
          iVar5 = *(int *)(uVar19 + 0x14) - (int)puVar14;
          puVar14 = puVar12;
          if (*(char **)(uVar19 + 0x18) < (char *)((int)puVar12 + iVar5)) {
            puVar14 = (uint *)(*(char **)(uVar19 + 0x18) + -iVar5);
          }
          memcpy((void *)(*(int *)(uVar19 + 0x10) + iVar5),__src,(size_t)puVar14);
          uVar10 = puVar29[4];
        }
        if ((int)(uVar10 << 0x16) < 0) {
          uVar10 = crc32(puVar29[6],__src,puVar12);
          puVar29[6] = uVar10;
        }
        puVar27 = (uint *)((int)puVar27 - (int)puVar12);
        __src = __src + (int)puVar12;
        puVar14 = (uint *)(puVar29[0x10] - (int)puVar12);
        puVar29[0x10] = (uint)puVar14;
      }
      if (puVar14 != (uint *)0x0) goto LAB_00040332;
      uVar10 = puVar29[4];
    }
    puVar29[0x10] = 0;
    *puVar29 = 6;
joined_r0x000409cc:
    if ((uVar10 & 0x800) == 0) {
      if (puVar29[8] != 0) {
        *(undefined4 *)(puVar29[8] + 0x1c) = 0;
      }
    }
    else {
      if (puVar27 == (uint *)0x0) goto LAB_00040332;
      puVar12 = (uint *)0x0;
      do {
        uVar10 = puVar29[8];
        bVar2 = __src[(int)puVar12];
        puVar12 = (uint *)((int)puVar12 + 1);
        if ((uVar10 != 0) && (*(int *)(uVar10 + 0x1c) != 0)) {
          uVar19 = puVar29[0x10];
          bVar30 = uVar19 < *(uint *)(uVar10 + 0x20);
          if (bVar30) {
            *(byte *)(*(int *)(uVar10 + 0x1c) + uVar19) = bVar2;
          }
          if (bVar30) {
            puVar29[0x10] = uVar19 + 1;
          }
        }
      } while (bVar2 != 0 && puVar12 < puVar27);
      if ((int)(puVar29[4] << 0x16) < 0) {
        uVar10 = crc32(puVar29[6],__src,puVar12);
        puVar29[6] = uVar10;
      }
      puVar27 = (uint *)((int)puVar27 - (int)puVar12);
      __src = __src + (int)puVar12;
      if (bVar2 != 0) goto LAB_00040332;
      uVar10 = puVar29[4];
    }
    *puVar29 = 7;
    puVar29[0x10] = 0;
joined_r0x00040138:
    if ((uVar10 & 0x1000) == 0) {
      if (puVar29[8] != 0) {
        *(undefined4 *)(puVar29[8] + 0x24) = 0;
      }
    }
    else {
      if (puVar27 == (uint *)0x0) goto LAB_00040332;
      puVar12 = (uint *)0x0;
      do {
        uVar10 = puVar29[8];
        bVar2 = __src[(int)puVar12];
        puVar12 = (uint *)((int)puVar12 + 1);
        if ((uVar10 != 0) && (*(int *)(uVar10 + 0x24) != 0)) {
          uVar19 = puVar29[0x10];
          bVar30 = uVar19 < *(uint *)(uVar10 + 0x28);
          if (bVar30) {
            *(byte *)(*(int *)(uVar10 + 0x24) + uVar19) = bVar2;
          }
          if (bVar30) {
            puVar29[0x10] = uVar19 + 1;
          }
        }
      } while (bVar2 != 0 && puVar12 < puVar27);
      if ((int)(puVar29[4] << 0x16) < 0) {
        uVar10 = crc32(puVar29[6],__src,puVar12);
        puVar29[6] = uVar10;
      }
      puVar27 = (uint *)((int)puVar27 - (int)puVar12);
      __src = __src + (int)puVar12;
      if (bVar2 != 0) goto LAB_00040332;
      uVar10 = puVar29[4];
    }
    *puVar29 = 8;
LAB_0004018e:
    if ((int)(uVar10 << 0x16) < 0) {
      for (; puVar28 < (uint *)0x10; puVar28 = puVar28 + 2) {
        if (puVar27 == (uint *)0x0) goto LAB_00040332;
        puVar27 = (uint *)((int)puVar27 + -1);
        puVar25 = (uint *)((int)puVar25 + ((uint)*__src << ((uint)puVar28 & 0xff)));
        __src = __src + 1;
      }
      if ((uint *)(uint)(ushort)puVar29[6] != puVar25) {
        uVar10 = 0x1d;
        param_1[6] = "header crc mismatch";
        *puVar29 = 0x1d;
        puVar12 = (uint *)"header crc mismatch";
        goto LAB_0003fbe4;
      }
      puVar28 = (uint *)0x0;
      puVar25 = (uint *)0x0;
    }
    uVar19 = puVar29[8];
    if (uVar19 != 0) {
      *(uint *)(uVar19 + 0x2c) = (uVar10 << 0x16) >> 0x1f;
      *(undefined4 *)(uVar19 + 0x30) = 1;
    }
    uVar32 = crc32(0,0,0);
    puVar29[6] = (uint)uVar32;
    uVar10 = 0xb;
    param_1[0xc] = (uint)uVar32;
    *puVar29 = 0xb;
    puVar12 = (uint *)((ulonglong)uVar32 >> 0x20);
    goto LAB_0003fbe4;
  case 4:
    uVar10 = puVar29[4];
    if ((int)(uVar10 << 0x15) < 0) goto joined_r0x000409b0;
    goto LAB_00040a3a;
  case 5:
    uVar10 = puVar29[4];
    uVar19 = uVar10 & 0x400;
    goto LAB_000400a4;
  case 6:
    uVar10 = puVar29[4];
    goto joined_r0x000409cc;
  case 7:
    uVar10 = puVar29[4];
    goto joined_r0x00040138;
  case 8:
    uVar10 = puVar29[4];
    goto LAB_0004018e;
  case 9:
    for (; puVar28 < (uint *)0x20; puVar28 = puVar28 + 2) {
      if (puVar27 == (uint *)0x0) goto LAB_00040332;
      puVar27 = (uint *)((int)puVar27 + -1);
      puVar25 = (uint *)((int)puVar25 + ((uint)*__src << ((uint)puVar28 & 0xff)));
      __src = __src + 1;
    }
    uVar10 = (uint)puVar25 >> 0x18;
    uVar24 = (uint)puVar25 >> 8;
    iVar5 = (int)puVar25 * 0x1000000;
    uVar19 = (uint)puVar25 & 0xff00;
    puVar25 = (uint *)0x0;
    uVar10 = uVar10 + iVar5 + (uVar24 & 0xff00) + uVar19 * 0x100;
    puVar28 = (uint *)0x0;
    puVar29[6] = uVar10;
    param_1[0xc] = uVar10;
    *puVar29 = 10;
  case 10:
    if (puVar29[3] == 0) {
      param_1[3] = local_6c;
      param_1[4] = local_70;
      *param_1 = __src;
      param_1[1] = puVar27;
      puVar29[0xe] = (uint)puVar25;
      puVar29[0xf] = (uint)puVar28;
      return 2;
    }
    uVar32 = adler32(0,0,0);
    puVar12 = (uint *)((ulonglong)uVar32 >> 0x20);
    puVar29[6] = (uint)uVar32;
    param_1[0xc] = (uint)uVar32;
    *puVar29 = 0xb;
switchD_0003fbea_caseD_b:
    if ((char *)((int)param_2 + -5) < (char *)0x2) goto LAB_00040332;
switchD_0003fbea_caseD_c:
    if (puVar29[1] == 0) {
      if (puVar28 < (uint *)0x3) {
        if (puVar27 == (uint *)0x0) goto LAB_00040332;
        puVar27 = (uint *)((int)puVar27 + -1);
        uVar10 = (uint)puVar28 & 0xff;
        puVar28 = puVar28 + 2;
        puVar25 = (uint *)((int)puVar25 + ((uint)*__src << uVar10));
        __src = __src + 1;
      }
      puVar29[1] = (uint)puVar25 & 1;
      uVar10 = (uint)puVar25 >> 1 & 3;
      if (uVar10 == 2) {
        uVar10 = 0x10;
        *puVar29 = 0x10;
      }
      else if (uVar10 == 3) {
        uVar10 = 0x1d;
        param_1[6] = "invalid block type";
        *puVar29 = 0x1d;
      }
      else if (uVar10 == 1) {
        puVar29[0x13] = (uint)&lenfix_6141;
        uVar10 = 0x13;
        puVar29[0x14] = (uint)distfix_6142;
        puVar29[0x15] = 9;
        puVar29[0x16] = 5;
        *puVar29 = 0x13;
        if (param_2 == (uint *)0x6) {
          puVar25 = (uint *)((uint)puVar25 >> 3);
          puVar28 = (uint *)((int)puVar28 + -3);
          goto LAB_00040332;
        }
      }
      else {
        uVar10 = 0xd;
        *puVar29 = 0xd;
      }
      puVar28 = (uint *)((int)puVar28 + -3);
      puVar12 = (uint *)((uint)puVar25 >> 1);
      puVar25 = (uint *)((uint)puVar25 >> 3);
    }
    else {
      uVar19 = (uint)puVar28 & 7;
      uVar10 = 0x1a;
      puVar28 = (uint *)((uint)puVar28 & 0xfffffff8);
      *puVar29 = 0x1a;
      puVar25 = (uint *)((uint)puVar25 >> uVar19);
    }
    goto LAB_0003fbe4;
  case 0xb:
    goto switchD_0003fbea_caseD_b;
  case 0xc:
    goto switchD_0003fbea_caseD_c;
  case 0xd:
    puVar25 = (uint *)((uint)puVar25 >> ((uint)puVar28 & 7));
    for (puVar28 = (uint *)((uint)puVar28 & 0xfffffff8); puVar28 < (uint *)0x20;
        puVar28 = puVar28 + 2) {
      if (puVar27 == (uint *)0x0) goto LAB_00040332;
      puVar27 = (uint *)((int)puVar27 + -1);
      puVar25 = (uint *)((int)puVar25 + ((uint)*__src << ((uint)puVar28 & 0xff)));
      __src = __src + 1;
    }
    puVar14 = (uint *)((uint)puVar25 & 0xffff);
    if (puVar14 == (uint *)((uint)puVar25 >> 0x10 ^ 0xffff)) {
      puVar29[0x10] = (uint)puVar14;
      *puVar29 = 0xe;
      if (param_2 != (uint *)0x6) {
        puVar28 = (uint *)0x0;
        puVar25 = (uint *)0x0;
        goto LAB_00040488;
      }
      puVar28 = (uint *)0x0;
      puVar25 = (uint *)0x0;
      goto LAB_00040332;
    }
    uVar10 = 0x1d;
    param_1[6] = "invalid stored block lengths";
    *puVar29 = 0x1d;
    puVar12 = (uint *)"invalid stored block lengths";
    goto LAB_0003fbe4;
  case 0xe:
    puVar14 = (uint *)puVar29[0x10];
LAB_00040488:
    *puVar29 = 0xf;
LAB_0004048e:
    if (puVar14 == (uint *)0x0) {
      uVar10 = 0xb;
      *puVar29 = 0xb;
    }
    else {
      if (puVar27 < puVar14) {
        puVar14 = puVar27;
      }
      if (local_70 <= puVar14) {
        puVar14 = local_70;
      }
      if (puVar14 == (uint *)0x0) goto LAB_00040332;
      local_70 = (uint *)((int)local_70 - (int)puVar14);
      memcpy(local_6c,__src,(size_t)puVar14);
      __src = __src + (int)puVar14;
      uVar10 = *puVar29;
      puVar29[0x10] = puVar29[0x10] - (int)puVar14;
      local_6c = (uint *)((int)local_6c + (int)puVar14);
      puVar12 = extraout_r1;
      puVar27 = (uint *)((int)puVar27 - (int)puVar14);
    }
    goto LAB_0003fbe4;
  case 0xf:
    puVar14 = (uint *)puVar29[0x10];
    goto LAB_0004048e;
  case 0x10:
    for (; puVar28 < (uint *)0xe; puVar28 = puVar28 + 2) {
      if (puVar27 == (uint *)0x0) goto LAB_00040332;
      puVar27 = (uint *)((int)puVar27 + -1);
      puVar25 = (uint *)((int)puVar25 + ((uint)*__src << ((uint)puVar28 & 0xff)));
      __src = __src + 1;
    }
    uVar19 = ((uint)puVar25 & 0x1f) + 0x101;
    puVar12 = (uint *)(((uint)((int)puVar25 << 0x16) >> 0x1b) + 1);
    uVar10 = ((uint)((int)puVar25 << 0x12) >> 0x1c) + 4;
    puVar28 = (uint *)((int)puVar28 + -0xe);
    puVar29[0x18] = uVar19;
    puVar25 = (uint *)((uint)puVar25 >> 0xe);
    puVar29[0x19] = (uint)puVar12;
    puVar29[0x17] = uVar10;
    if ((uVar19 < 0x11f) && (puVar12 < (uint *)0x1f)) {
      uVar19 = 0;
      puVar29[0x1a] = 0;
      *puVar29 = 0x11;
LAB_0004056e:
      puVar6 = (ushort *)(order_6170 + (uVar19 - 1) * 2);
      pbVar17 = __src;
      do {
        uVar19 = uVar19 + 1;
        __src = pbVar17;
        if (puVar28 < (uint *)0x3) {
          if (puVar27 == (uint *)0x0) goto LAB_00040332;
          __src = pbVar17 + 1;
          puVar27 = (uint *)((int)puVar27 + -1);
          uVar24 = (uint)puVar28 & 0xff;
          puVar28 = puVar28 + 2;
          puVar25 = (uint *)((int)puVar25 + ((uint)*pbVar17 << uVar24));
        }
        puVar6 = puVar6 + 1;
        uVar1 = *puVar6;
        uVar3 = (ushort)puVar25;
        puVar28 = (uint *)((int)puVar28 + -3);
        puVar29[0x1a] = uVar19;
        puVar25 = (uint *)((uint)puVar25 >> 3);
        *(ushort *)((int)puVar29 + (uVar1 + 0x38) * 2) = uVar3 & 7;
        pbVar17 = __src;
      } while (uVar19 < uVar10);
      goto LAB_000405b6;
    }
    uVar10 = 0x1d;
    param_1[6] = "too many length or distance symbols";
    *puVar29 = 0x1d;
    goto LAB_0003fbe4;
  case 0x11:
    uVar10 = puVar29[0x17];
    uVar19 = puVar29[0x1a];
    if (uVar19 < uVar10) goto LAB_0004056e;
LAB_000405b6:
    if (uVar19 < 0x13) {
      puVar6 = (ushort *)(order_6170 + (uVar19 - 1) * 2);
      do {
        puVar6 = puVar6 + 1;
        pcVar7 = (char *)((int)puVar29 + (*puVar6 + 0x38) * 2);
        pcVar7[0] = '\0';
        pcVar7[1] = '\0';
      } while (puVar6 != (ushort *)(order_6170 + 0x24));
      puVar29[0x1a] = 0x13;
    }
    puVar29[0x1b] = (uint)(puVar29 + 0x14c);
    puVar29[0x13] = (uint)(puVar29 + 0x14c);
    puVar29[0x15] = 7;
    local_5c = inflate_table(0,puVar29 + 0x1c,0x13,puVar29 + 0x1b,puVar29 + 0x15,puVar29 + 0xbc);
    if (local_5c == 0) {
      puVar29[0x1a] = 0;
      *puVar29 = 0x12;
      puVar14 = (uint *)0x0;
LAB_0004062e:
      local_50 = (uint *)puVar29[0x18];
      uVar10 = puVar29[0x19];
      while (puVar14 < (uint *)(uVar10 + (int)local_50)) {
        uVar19 = (1 << (puVar29[0x15] & 0xff)) - 1;
        iVar5 = puVar29[0x13] + ((uint)puVar25 & uVar19) * 4;
        puVar16 = (uint *)(uint)*(byte *)(iVar5 + 1);
        uVar1 = *(ushort *)(iVar5 + 2);
        pbVar17 = __src;
        if (puVar28 < puVar16) {
          do {
            __src = pbVar17;
            if (puVar27 == (uint *)0x0) goto LAB_00040332;
            __src = pbVar17 + 1;
            puVar27 = (uint *)((int)puVar27 + -1);
            uVar24 = (uint)puVar28 & 0xff;
            puVar28 = puVar28 + 2;
            puVar25 = (uint *)((int)puVar25 + ((uint)*pbVar17 << uVar24));
            iVar5 = puVar29[0x13] + ((uint)puVar25 & uVar19) * 4;
            puVar16 = (uint *)(uint)*(byte *)(iVar5 + 1);
            uVar1 = *(ushort *)(iVar5 + 2);
            pbVar17 = __src;
          } while (puVar28 < puVar16);
        }
        if (uVar1 < 0x10) {
          puVar12 = puVar14 + 0xe;
          puVar14 = (uint *)((int)puVar14 + 1);
          *(ushort *)((int)puVar29 + (int)puVar12 * 2) = uVar1;
          puVar25 = (uint *)((uint)puVar25 >> (int)puVar16);
          puVar28 = (uint *)((int)puVar28 - (int)puVar16);
          puVar29[0x1a] = (uint)puVar14;
        }
        else {
          if (uVar1 == 0x10) {
            puVar12 = (uint *)((int)puVar16 + 2);
            for (; puVar28 < puVar12; puVar28 = puVar28 + 2) {
              if (puVar27 == (uint *)0x0) goto LAB_00040332;
              puVar27 = (uint *)((int)puVar27 + -1);
              puVar25 = (uint *)((int)puVar25 + ((uint)*__src << ((uint)puVar28 & 0xff)));
              __src = __src + 1;
            }
            puVar25 = (uint *)((uint)puVar25 >> (int)puVar16);
            puVar28 = (uint *)((int)puVar28 - (int)puVar16);
            if (puVar14 != (uint *)0x0) {
              puVar28 = (uint *)((int)puVar28 + -2);
              uVar15 = *(undefined2 *)((int)puVar29 + (int)((int)puVar14 + 0x37) * 2);
              uVar19 = ((uint)puVar25 & 3) + 3;
              puVar25 = (uint *)((uint)puVar25 >> 2);
              goto LAB_000406fa;
            }
LAB_000412a0:
            param_1[6] = "invalid bit length repeat";
            uVar10 = 0x1d;
            *puVar29 = 0x1d;
            goto LAB_0003fbe4;
          }
          if (uVar1 == 0x11) {
            for (; puVar28 < (uint *)((int)puVar16 + 3); puVar28 = puVar28 + 2) {
              if (puVar27 == (uint *)0x0) goto LAB_00040332;
              puVar27 = (uint *)((int)puVar27 + -1);
              puVar25 = (uint *)((int)puVar25 + ((uint)*__src << ((uint)puVar28 & 0xff)));
              __src = __src + 1;
            }
            puVar28 = (uint *)((int)puVar28 + (-3 - (int)puVar16));
            uVar19 = ((uint)puVar25 >> (int)puVar16 & 7) + 3;
            puVar25 = (uint *)(((uint)puVar25 >> (int)puVar16) >> 3);
            uVar15 = 0;
          }
          else {
            for (; puVar28 < (uint *)((int)puVar16 + 7); puVar28 = puVar28 + 2) {
              if (puVar27 == (uint *)0x0) goto LAB_00040332;
              puVar27 = (uint *)((int)puVar27 + -1);
              puVar25 = (uint *)((int)puVar25 + ((uint)*__src << ((uint)puVar28 & 0xff)));
              __src = __src + 1;
            }
            uVar19 = (uint)puVar25 >> (int)puVar16;
            puVar25 = (uint *)(uVar19 >> 7);
            puVar28 = (uint *)((int)puVar28 + (-7 - (int)puVar16));
            uVar19 = (uVar19 & 0x7f) + 0xb;
            uVar15 = 0;
          }
LAB_000406fa:
          puVar12 = (uint *)(uVar19 + (int)puVar14);
          if ((uint *)(uVar10 + (int)local_50) < puVar12) goto LAB_000412a0;
          uVar21 = uVar19 - 1;
          uVar24 = (uint)((int)((int)puVar29 + (int)(puVar14 + 0xe) * 2) * 0x40000000) >> 0x1f;
          if (uVar19 < uVar24) {
            uVar24 = uVar19;
          }
          puVar16 = puVar14;
          if ((int)(uVar24 << 0x1f) < 0) {
            pcVar7 = (char *)((int)puVar29 + (int)((int)puVar14 + 0x37) * 2);
            do {
              puVar16 = (uint *)((int)puVar16 + 1);
              pcVar7 = pcVar7 + 2;
              *(undefined2 *)pcVar7 = uVar15;
              uVar21 = uVar21 - 1;
            } while ((uint)((int)puVar16 - (int)puVar14) < uVar24);
          }
          uVar20 = uVar19 - uVar24 >> 1;
          if (uVar20 == 0) {
LAB_000407d6:
            if (0xf < uVar21) {
              puVar13 = puVar16 + 0xe;
              pcVar7 = (char *)((int)puVar29 + (int)puVar13 * 2);
              puVar14 = puVar16;
              do {
                uVar21 = uVar21 - 0x10;
                *(undefined2 *)pcVar7 = uVar15;
                puVar16 = puVar14 + 4;
                HintPreloadData((char *)((int)puVar29 + (int)puVar13 * 2 + 0x50));
                *(undefined2 *)(pcVar7 + 2) = uVar15;
                puVar13 = puVar14 + 0x12;
                *(undefined2 *)(pcVar7 + 4) = uVar15;
                *(undefined2 *)(pcVar7 + 6) = uVar15;
                *(undefined2 *)(pcVar7 + 8) = uVar15;
                *(undefined2 *)(pcVar7 + 10) = uVar15;
                *(undefined2 *)(pcVar7 + 0xc) = uVar15;
                *(undefined2 *)(pcVar7 + 0xe) = uVar15;
                *(undefined2 *)(pcVar7 + 0x10) = uVar15;
                *(undefined2 *)(pcVar7 + 0x12) = uVar15;
                *(undefined2 *)(pcVar7 + 0x14) = uVar15;
                *(undefined2 *)(pcVar7 + 0x16) = uVar15;
                *(undefined2 *)(pcVar7 + 0x18) = uVar15;
                *(undefined2 *)(pcVar7 + 0x1a) = uVar15;
                *(undefined2 *)(pcVar7 + 0x1c) = uVar15;
                *(undefined2 *)(pcVar7 + 0x1e) = uVar15;
                pcVar7 = pcVar7 + 0x20;
                puVar14 = puVar16;
              } while (0xf < uVar21);
            }
            pcVar7 = (char *)((int)puVar29 + (int)((int)puVar16 + 0x37) * 2);
            do {
              pcVar7 = pcVar7 + 2;
              *(undefined2 *)pcVar7 = uVar15;
            } while (pcVar7 != (char *)((int)puVar29 + (int)((int)puVar16 + uVar21) * 2 + 0x70));
          }
          else {
            uVar8 = CONCAT22(uVar15,uVar15);
            pcVar7 = (char *)((int)puVar29 + (int)((int)(puVar14 + 0xe) + uVar24) * 2);
            if (uVar20 < 9) {
              uVar23 = 0;
            }
            else {
              uVar23 = 0;
              pcVar4 = pcVar7;
              do {
                pcVar7 = pcVar4 + 0x20;
                uVar26 = uVar23 + 9;
                uVar23 = uVar23 + 8;
                HintPreloadData(pcVar4 + 0xa0);
                *(undefined4 *)pcVar4 = uVar8;
                *(undefined4 *)(pcVar4 + 4) = uVar8;
                *(undefined4 *)(pcVar4 + 8) = uVar8;
                *(undefined4 *)(pcVar4 + 0xc) = uVar8;
                *(undefined4 *)(pcVar4 + 0x10) = uVar8;
                *(undefined4 *)(pcVar4 + 0x14) = uVar8;
                *(undefined4 *)(pcVar4 + 0x18) = uVar8;
                *(undefined4 *)(pcVar4 + 0x1c) = uVar8;
                pcVar4 = pcVar7;
              } while (uVar26 < uVar20 - 7);
            }
            do {
              uVar23 = uVar23 + 1;
              *(undefined4 *)pcVar7 = uVar8;
              pcVar7 = pcVar7 + 4;
            } while (uVar23 < uVar20);
            uVar21 = uVar21 + uVar20 * -2;
            puVar16 = (uint *)((int)puVar16 + uVar20 * 2);
            if (uVar19 - uVar24 != uVar20 * 2) goto LAB_000407d6;
          }
          puVar29[0x1a] = (uint)puVar12;
          puVar14 = puVar12;
        }
      }
      if ((short)puVar29[0x9c] == 0) {
        uVar10 = 0x1d;
        param_1[6] = "invalid code -- missing end-of-block";
        *puVar29 = 0x1d;
        puVar12 = (uint *)"invalid code -- missing end-of-block";
      }
      else {
        puVar29[0x1b] = (uint)(puVar29 + 0x14c);
        puVar29[0x13] = (uint)(puVar29 + 0x14c);
        puVar29[0x15] = 9;
        local_5c = inflate_table(1,puVar29 + 0x1c,local_50,puVar29 + 0x1b,puVar29 + 0x15,
                                 puVar29 + 0xbc);
        if (local_5c == 0) {
          puVar29[0x16] = 6;
          puVar29[0x14] = puVar29[0x1b];
          uVar32 = inflate_table(2,(char *)((int)puVar29 + (puVar29[0x18] + 0x38) * 2),puVar29[0x19]
                                 ,puVar29 + 0x1b,puVar29 + 0x16,puVar29 + 0xbc);
          local_5c = (int)uVar32;
          if (local_5c == 0) {
            *puVar29 = 0x13;
            if (param_2 == (uint *)0x6) goto LAB_00040332;
switchD_0003fbea_caseD_13:
            *puVar29 = 0x14;
switchD_0003fbea_caseD_14:
            uVar10 = (uint)((ulonglong)uVar32 >> 0x20);
            local_5c = (int)uVar32;
            bVar31 = (uint *)0x101 < local_70;
            bVar30 = local_70 == (uint *)0x102;
            if (bVar31) {
              bVar30 = puVar27 == (uint *)&DAT_00000005;
            }
            if ((!bVar31 || (uint *)0x4 >= puVar27) || bVar30) {
              uVar10 = 0;
            }
            if ((bVar31 && (uint *)0x4 < puVar27) && !bVar30) {
              param_1[4] = local_70;
              *param_1 = __src;
              param_1[3] = local_6c;
              param_1[1] = puVar27;
              puVar29[0xe] = (uint)puVar25;
              puVar29[0xf] = (uint)puVar28;
              inflate_fast(param_1,local_68);
              uVar10 = *puVar29;
              puVar25 = (uint *)puVar29[0xe];
              local_6c = (uint *)param_1[3];
              local_70 = (uint *)param_1[4];
              bVar30 = uVar10 == 0xb;
              uVar19 = extraout_r3;
              if (bVar30) {
                uVar19 = 0xffffffff;
              }
              __src = (byte *)*param_1;
              puVar14 = local_6c;
              if (bVar30) {
                puVar14 = puVar29 + 0x6f0;
              }
              puVar27 = (uint *)param_1[1];
              puVar28 = (uint *)puVar29[0xf];
              puVar12 = extraout_r1_00;
              if (bVar30) {
                puVar14[1] = uVar19;
              }
            }
            else {
              uVar19 = puVar29[0x13];
              puVar29[0x6f1] = uVar10;
              puVar16 = puVar29 + 0x6f1;
              uVar24 = (1 << (puVar29[0x15] & 0xff)) - 1;
              uVar10 = (uint)puVar25 & uVar24;
              iVar5 = uVar19 + uVar10 * 4;
              bVar2 = *(byte *)(uVar19 + uVar10 * 4);
              puVar14 = (uint *)(uint)*(byte *)(iVar5 + 1);
              uVar1 = *(ushort *)(iVar5 + 2);
              pbVar17 = __src;
              if (puVar28 < puVar14) {
                do {
                  __src = pbVar17;
                  if (puVar27 == (uint *)0x0) goto LAB_00040332;
                  __src = pbVar17 + 1;
                  puVar27 = (uint *)((int)puVar27 + -1);
                  uVar10 = (uint)puVar28 & 0xff;
                  puVar28 = puVar28 + 2;
                  puVar25 = (uint *)((int)puVar25 + ((uint)*pbVar17 << uVar10));
                  uVar10 = (uint)puVar25 & uVar24;
                  iVar5 = uVar19 + uVar10 * 4;
                  bVar2 = *(byte *)(uVar19 + uVar10 * 4);
                  puVar14 = (uint *)(uint)*(byte *)(iVar5 + 1);
                  uVar1 = *(ushort *)(iVar5 + 2);
                  pbVar17 = __src;
                } while (puVar28 < puVar14);
              }
              puVar12 = (uint *)(uint)bVar2;
              uVar10 = (uint)uVar1;
              if (puVar12 == (uint *)0x0) {
                puVar25 = (uint *)((uint)puVar25 >> (int)puVar14);
                puVar28 = (uint *)((int)puVar28 - (int)puVar14);
                puVar29[0x10] = uVar10;
                *puVar16 = (uint)puVar14;
LAB_0003fe6c:
                uVar10 = 0x19;
                *puVar29 = 0x19;
              }
              else {
                if ((bVar2 & 0xf0) == 0) {
                  uVar24 = (1 << ((uint)((int)puVar14 + (int)puVar12) & 0xff)) - 1;
                  iVar5 = ((uVar24 & (uint)puVar25) >> (int)puVar14) + uVar10;
                  iVar22 = uVar19 + iVar5 * 4;
                  bVar2 = *(byte *)(uVar19 + iVar5 * 4);
                  uVar21 = (uint)*(byte *)(iVar22 + 1);
                  uVar1 = *(ushort *)(iVar22 + 2);
                  puVar13 = (uint *)((int)puVar14 + uVar21);
                  pbVar17 = __src;
                  if (puVar28 < puVar13) {
                    do {
                      __src = pbVar17;
                      if (puVar27 == (uint *)0x0) goto LAB_00040332;
                      __src = pbVar17 + 1;
                      puVar27 = (uint *)((int)puVar27 + -1);
                      uVar21 = (uint)puVar28 & 0xff;
                      puVar28 = puVar28 + 2;
                      puVar25 = (uint *)((int)puVar25 + ((uint)*pbVar17 << uVar21));
                      iVar5 = (((uint)puVar25 & uVar24) >> (int)puVar14) + uVar10;
                      iVar22 = uVar19 + iVar5 * 4;
                      bVar2 = *(byte *)(uVar19 + iVar5 * 4);
                      uVar21 = (uint)*(byte *)(iVar22 + 1);
                      uVar1 = *(ushort *)(iVar22 + 2);
                      puVar13 = (uint *)(uVar21 + (int)puVar14);
                      local_50 = puVar29;
                      pbVar17 = __src;
                    } while (puVar28 < puVar13);
                  }
                  puVar12 = (uint *)(uint)bVar2;
                  puVar28 = (uint *)((int)puVar28 + (-uVar21 - (int)puVar14));
                  puVar25 = (uint *)(((uint)puVar25 >> (int)puVar14) >> uVar21);
                  puVar29[0x10] = (uint)uVar1;
                  *puVar16 = (uint)puVar13;
                  if (puVar12 == (uint *)0x0) goto LAB_0003fe6c;
                }
                else {
                  puVar25 = (uint *)((uint)puVar25 >> (int)puVar14);
                  puVar28 = (uint *)((int)puVar28 - (int)puVar14);
                  puVar29[0x10] = uVar10;
                  *puVar16 = (uint)puVar14;
                }
                if ((int)puVar12 << 0x1a < 0) {
                  *puVar29 = 0xb;
                  *puVar16 = 0xffffffff;
                  uVar10 = 0xb;
                }
                else {
                  if (-1 < (int)puVar12 << 0x19) {
                    puVar12 = (uint *)((uint)puVar12 & 0xf);
                    puVar29[0x12] = (uint)puVar12;
                    *puVar29 = 0x15;
joined_r0x0004030e:
                    if (puVar12 == (uint *)0x0) {
                      uVar10 = puVar29[0x10];
                    }
                    else {
                      for (; puVar28 < puVar12; puVar28 = puVar28 + 2) {
                        if (puVar27 == (uint *)0x0) goto LAB_00040332;
                        puVar27 = (uint *)((int)puVar27 + -1);
                        puVar25 = (uint *)((int)puVar25 + ((uint)*__src << ((uint)puVar28 & 0xff)));
                        __src = __src + 1;
                      }
                      puVar28 = (uint *)((int)puVar28 - (int)puVar12);
                      uVar10 = (uint)puVar25 & (1 << ((uint)puVar12 & 0xff)) - 1U;
                      puVar25 = (uint *)((uint)puVar25 >> ((uint)puVar12 & 0xff));
                      uVar10 = uVar10 + puVar29[0x10];
                      puVar29[0x10] = uVar10;
                      puVar29[0x6f1] = (uint)((int)puVar12 + puVar29[0x6f1]);
                    }
                    puVar29[0x6f2] = uVar10;
                    *puVar29 = 0x16;
switchD_0003fbea_caseD_16:
                    uVar10 = puVar29[0x14];
                    uVar24 = (1 << (puVar29[0x16] & 0xff)) - 1;
                    uVar19 = (uint)puVar25 & uVar24;
                    iVar5 = uVar10 + uVar19 * 4;
                    bVar2 = *(byte *)(uVar10 + uVar19 * 4);
                    puVar12 = (uint *)(uint)*(byte *)(iVar5 + 1);
                    uVar1 = *(ushort *)(iVar5 + 2);
                    pbVar17 = __src;
                    if (puVar28 < puVar12) {
                      do {
                        __src = pbVar17;
                        if (puVar27 == (uint *)0x0) goto LAB_00040332;
                        __src = pbVar17 + 1;
                        puVar27 = (uint *)((int)puVar27 + -1);
                        uVar19 = (uint)puVar28 & 0xff;
                        puVar28 = puVar28 + 2;
                        puVar25 = (uint *)((int)puVar25 + ((uint)*pbVar17 << uVar19));
                        uVar19 = (uint)puVar25 & uVar24;
                        iVar5 = uVar10 + uVar19 * 4;
                        bVar2 = *(byte *)(uVar10 + uVar19 * 4);
                        puVar12 = (uint *)(uint)*(byte *)(iVar5 + 1);
                        uVar1 = *(ushort *)(iVar5 + 2);
                        pbVar17 = __src;
                      } while (puVar28 < puVar12);
                    }
                    uVar24 = (uint)bVar2;
                    uVar19 = (uint)uVar1;
                    if ((bVar2 & 0xf0) == 0) {
                      uVar24 = (1 << ((uint)((int)puVar12 + uVar24) & 0xff)) - 1;
                      iVar22 = ((uVar24 & (uint)puVar25) >> (int)puVar12) + uVar19;
                      iVar5 = uVar10 + iVar22 * 4;
                      bVar2 = *(byte *)(uVar10 + iVar22 * 4);
                      puVar14 = (uint *)(uint)*(byte *)(iVar5 + 1);
                      uVar1 = *(ushort *)(iVar5 + 2);
                      pbVar17 = __src;
                      if (puVar28 < (uint *)((int)puVar12 + (int)puVar14)) {
                        do {
                          __src = pbVar17;
                          if (puVar27 == (uint *)0x0) goto LAB_00040332;
                          __src = pbVar17 + 1;
                          puVar27 = (uint *)((int)puVar27 + -1);
                          uVar21 = (uint)puVar28 & 0xff;
                          puVar28 = puVar28 + 2;
                          puVar25 = (uint *)((int)puVar25 + ((uint)*pbVar17 << uVar21));
                          iVar22 = (((uint)puVar25 & uVar24) >> (int)puVar12) + uVar19;
                          iVar5 = uVar10 + iVar22 * 4;
                          bVar2 = *(byte *)(uVar10 + iVar22 * 4);
                          puVar14 = (uint *)(uint)*(byte *)(iVar5 + 1);
                          uVar1 = *(ushort *)(iVar5 + 2);
                          local_50 = puVar29;
                          pbVar17 = __src;
                        } while (puVar28 < (uint *)((int)puVar14 + (int)puVar12));
                      }
                      uVar24 = (uint)bVar2;
                      uVar19 = (uint)uVar1;
                      puVar28 = (uint *)((int)puVar28 - (int)puVar12);
                      puVar25 = (uint *)((uint)puVar25 >> (int)puVar12);
                      pcVar7 = (char *)((int)puVar12 + puVar29[0x6f1]);
                      puVar12 = puVar14;
                    }
                    else {
                      pcVar7 = (char *)puVar29[0x6f1];
                    }
                    puVar25 = (uint *)((uint)puVar25 >> (int)puVar12);
                    puVar28 = (uint *)((int)puVar28 - (int)puVar12);
                    puVar29[0x6f1] = (uint)(pcVar7 + (int)puVar12);
                    if ((int)(uVar24 << 0x19) < 0) {
                      uVar10 = 0x1d;
                      param_1[6] = "invalid distance code";
                      *puVar29 = 0x1d;
                      puVar12 = (uint *)"invalid distance code";
                      goto LAB_0003fbe4;
                    }
                    puVar12 = (uint *)(uVar24 & 0xf);
                    puVar29[0x12] = (uint)puVar12;
                    puVar29[0x11] = uVar19;
                    *puVar29 = 0x17;
joined_r0x00040320:
                    if (puVar12 != (uint *)0x0) {
                      for (; puVar28 < puVar12; puVar28 = puVar28 + 2) {
                        if (puVar27 == (uint *)0x0) goto LAB_00040332;
                        puVar27 = (uint *)((int)puVar27 + -1);
                        puVar25 = (uint *)((int)puVar25 + ((uint)*__src << ((uint)puVar28 & 0xff)));
                        __src = __src + 1;
                      }
                      puVar28 = (uint *)((int)puVar28 - (int)puVar12);
                      uVar10 = (uint)puVar25 & (1 << ((uint)puVar12 & 0xff)) - 1U;
                      puVar25 = (uint *)((uint)puVar25 >> ((uint)puVar12 & 0xff));
                      puVar29[0x11] = puVar29[0x11] + uVar10;
                      puVar29[0x6f1] = (uint)((int)puVar12 + puVar29[0x6f1]);
                    }
                    *puVar29 = 0x18;
switchD_0003fbea_caseD_18:
                    if (local_70 == (uint *)0x0) goto LAB_00040332;
                    uVar10 = puVar29[0x11];
                    if ((uint)((int)local_68 - (int)local_70) < uVar10) {
                      puVar16 = (uint *)(uVar10 - ((int)local_68 - (int)local_70));
                      if (((uint *)puVar29[0xb] < puVar16) && (puVar29[0x6f0] != 0)) {
                        uVar10 = 0x1d;
                        param_1[6] = "invalid distance too far back";
                        *puVar29 = 0x1d;
                        puVar12 = (uint *)"invalid distance too far back";
                        goto LAB_0003fbe4;
                      }
                      puVar13 = (uint *)puVar29[0xc];
                      if (puVar13 < puVar16) {
                        puVar12 = (uint *)((int)puVar16 - (int)puVar13);
                        puVar9 = (uint *)(puVar29[10] - (int)puVar12);
                        local_50 = (uint *)(puVar29[0xd] + (int)puVar9);
                      }
                      else {
                        puVar9 = (uint *)((int)puVar13 + (puVar29[0xd] - (int)puVar16));
                        puVar12 = puVar16;
                      }
                      puVar14 = (uint *)puVar29[0x10];
                      if (puVar16 <= puVar13) {
                        local_50 = puVar9;
                      }
                      if (puVar14 <= puVar12) {
                        puVar12 = puVar14;
                      }
                    }
                    else {
                      puVar14 = (uint *)puVar29[0x10];
                      local_50 = (uint *)((int)local_6c - uVar10);
                      puVar12 = puVar14;
                    }
                    puVar16 = local_70;
                    if (puVar12 < local_70) {
                      puVar16 = puVar12;
                    }
                    uVar10 = (uint)puVar16 >> 2;
                    puVar29[0x10] = (int)puVar14 - (int)puVar16;
                    local_70 = (uint *)((int)local_70 - (int)puVar16);
                    puVar12 = puVar16;
                    puVar14 = local_6c;
                    if (uVar10 == 0 ||
                        ((((uint)local_50 | (uint)local_6c) & 3) != 0 ||
                        (puVar16 < (uint *)0x4 || local_50 < local_6c + 1 && local_6c < local_50 + 1
                        ))) {
LAB_00040be8:
                      puVar12 = (uint *)((int)puVar14 + (int)puVar12);
                      pcVar7 = (char *)((int)local_50 + -1);
                      do {
                        pcVar7 = pcVar7 + 1;
                        puVar13 = (uint *)((int)puVar14 + 1);
                        *(char *)puVar14 = *pcVar7;
                        puVar14 = puVar13;
                      } while (puVar13 != puVar12);
                    }
                    else {
                      if (uVar10 < 9) {
                        uVar19 = 0;
                        puVar12 = local_50;
                      }
                      else {
                        uVar19 = 0;
                        puVar13 = local_6c;
                        puVar9 = local_50;
                        do {
                          puVar12 = puVar9 + 8;
                          puVar14 = puVar13 + 8;
                          uVar24 = uVar19 + 9;
                          uVar19 = uVar19 + 8;
                          HintPreloadData(puVar9 + 0x1d);
                          *puVar13 = *puVar9;
                          puVar13[1] = puVar9[1];
                          puVar13[2] = puVar9[2];
                          puVar13[3] = puVar9[3];
                          puVar13[4] = puVar9[4];
                          puVar13[5] = puVar9[5];
                          puVar13[6] = puVar9[6];
                          puVar13[7] = puVar9[7];
                          puVar13 = puVar14;
                          puVar9 = puVar12;
                        } while (uVar24 < uVar10 - 7);
                      }
                      puVar12 = puVar12 + -1;
                      do {
                        puVar12 = puVar12 + 1;
                        uVar19 = uVar19 + 1;
                        *puVar14 = *puVar12;
                        puVar14 = puVar14 + 1;
                      } while (uVar19 < uVar10);
                      local_50 = local_50 + uVar10;
                      puVar12 = puVar16 + -uVar10;
                      puVar14 = local_6c + uVar10;
                      if ((uint *)(uVar10 * 4) != puVar16) goto LAB_00040be8;
                    }
                    local_6c = (uint *)((int)local_6c + (int)puVar16);
                    if (puVar29[0x10] == 0) {
                      uVar10 = 0x14;
                      *puVar29 = 0x14;
                    }
                    else {
                      uVar10 = *puVar29;
                    }
                    goto LAB_0003fbe4;
                  }
                  uVar10 = 0x1d;
                  param_1[6] = "invalid literal/length code";
                  *puVar29 = 0x1d;
                  puVar12 = (uint *)"invalid literal/length code";
                }
              }
            }
          }
          else {
            uVar10 = 0x1d;
            param_1[6] = "invalid distances set";
            *puVar29 = 0x1d;
            puVar12 = (uint *)"invalid distances set";
          }
        }
        else {
          uVar10 = 0x1d;
          param_1[6] = "invalid literal/lengths set";
          *puVar29 = 0x1d;
          puVar12 = (uint *)"invalid literal/lengths set";
        }
      }
    }
    else {
      uVar10 = 0x1d;
      param_1[6] = "invalid code lengths set";
      *puVar29 = 0x1d;
      puVar12 = (uint *)"invalid code lengths set";
    }
    goto LAB_0003fbe4;
  case 0x12:
    puVar14 = (uint *)puVar29[0x1a];
    goto LAB_0004062e;
  case 0x13:
    goto switchD_0003fbea_caseD_13;
  case 0x14:
    goto switchD_0003fbea_caseD_14;
  case 0x15:
    puVar12 = (uint *)puVar29[0x12];
    goto joined_r0x0004030e;
  case 0x16:
    goto switchD_0003fbea_caseD_16;
  case 0x17:
    puVar12 = (uint *)puVar29[0x12];
    goto joined_r0x00040320;
  case 0x18:
    goto switchD_0003fbea_caseD_18;
  case 0x19:
    if (local_70 == (uint *)0x0) goto LAB_00040332;
    puVar12 = (uint *)puVar29[0x10];
    local_70 = (uint *)((int)local_70 + -1);
    uVar10 = 0x14;
    *(char *)local_6c = (char)puVar12;
    *puVar29 = 0x14;
    local_6c = (uint *)((int)local_6c + 1);
    goto LAB_0003fbe4;
  case 0x1a:
    uVar10 = puVar29[2];
    if (uVar10 == 0) {
LAB_00040c86:
      *puVar29 = 0x1b;
      goto LAB_0004093e;
    }
    for (; puVar28 < (uint *)0x20; puVar28 = puVar28 + 2) {
      if (puVar27 == (uint *)0x0) goto LAB_00040332;
      puVar27 = (uint *)((int)puVar27 + -1);
      puVar25 = (uint *)((int)puVar25 + ((uint)*__src << ((uint)puVar28 & 0xff)));
      __src = __src + 1;
    }
    uVar10 = puVar29[7];
    iVar5 = (int)local_68 - (int)local_70;
    param_1[5] = param_1[5] + iVar5;
    puVar29[7] = uVar10 + iVar5;
    if (iVar5 != 0) {
      if (puVar29[4] == 0) {
        uVar10 = adler32(puVar29[6],(int)local_6c - iVar5);
      }
      else {
        uVar10 = crc32(puVar29[6],(int)local_6c - iVar5);
      }
      puVar29[6] = uVar10;
      param_1[0xc] = uVar10;
    }
    puVar12 = puVar25;
    if (puVar29[4] == 0) {
      puVar12 = (uint *)(((uint)puVar25 >> 0x18) + (int)puVar25 * 0x1000000 +
                         ((uint)puVar25 >> 8 & 0xff00) + ((uint)puVar25 & 0xff00) * 0x100);
    }
    if (puVar12 == (uint *)puVar29[6]) {
      uVar10 = puVar29[2];
      puVar28 = (uint *)0x0;
      puVar25 = (uint *)0x0;
      local_68 = local_70;
      goto LAB_00040c86;
    }
    uVar10 = 0x1d;
    param_1[6] = "incorrect data check";
    local_68 = local_70;
    *puVar29 = 0x1d;
    puVar12 = (uint *)"incorrect data check";
    goto LAB_0003fbe4;
  case 0x1b:
    uVar10 = puVar29[2];
LAB_0004093e:
    if ((uVar10 != 0) && (puVar29[4] != 0)) {
      for (; puVar28 < (uint *)0x20; puVar28 = puVar28 + 2) {
        if (puVar27 == (uint *)0x0) goto LAB_00040332;
        puVar27 = (uint *)((int)puVar27 + -1);
        puVar25 = (uint *)((int)puVar25 + ((uint)*__src << ((uint)puVar28 & 0xff)));
        __src = __src + 1;
      }
      if ((uint *)puVar29[7] != puVar25) {
        uVar10 = 0x1d;
        param_1[6] = "incorrect length check";
        *puVar29 = 0x1d;
        puVar12 = (uint *)"incorrect length check";
        goto LAB_0003fbe4;
      }
      puVar28 = (uint *)0x0;
      puVar25 = (uint *)0x0;
    }
    local_5c = 1;
    *puVar29 = 0x1c;
    goto LAB_00040332;
  case 0x1c:
    goto switchD_0003fbea_caseD_1c;
  case 0x1d:
    local_5c = -3;
    goto LAB_00040332;
  case 0x1e:
    return -4;
  default:
    goto LAB_0003ff9c;
  }
  uVar10 = 0x1d;
  param_1[6] = "unknown compression method";
  *puVar29 = 0x1d;
  puVar12 = (uint *)"unknown compression method";
  goto LAB_0003fbe4;
switchD_0003fbea_caseD_1c:
  local_5c = 1;
LAB_00040332:
  uVar10 = puVar29[10];
  *param_1 = __src;
  param_1[3] = local_6c;
  param_1[4] = local_70;
  param_1[1] = puVar27;
  puVar29[0xe] = (uint)puVar25;
  puVar29[0xf] = (uint)puVar28;
  if (((uVar10 != 0) ||
      (((local_70 != local_68 && (*puVar29 < 0x1d)) &&
       ((*puVar29 < 0x1a || (param_2 != (uint *)0x4)))))) &&
     (iVar5 = updatewindow(param_1,local_6c,(int)local_68 - (int)local_70), iVar5 != 0)) {
    *puVar29 = 0x1e;
    return -4;
  }
  iVar5 = param_1[1];
  uVar19 = puVar29[7];
  iVar22 = (int)local_68 - param_1[4];
  uVar10 = puVar29[2];
  param_1[2] = param_1[2] + ((int)local_64 - iVar5);
  param_1[5] = param_1[5] + iVar22;
  puVar29[7] = uVar19 + iVar22;
  if ((uVar10 != 0) && (iVar22 != 0)) {
    if (puVar29[4] == 0) {
      uVar10 = adler32(puVar29[6],param_1[3] - iVar22,iVar22);
    }
    else {
      uVar10 = crc32();
    }
    puVar29[6] = uVar10;
    param_1[0xc] = uVar10;
  }
  uVar10 = *puVar29;
  if (puVar29[1] == 0) {
    iVar11 = 0;
  }
  else {
    iVar11 = 0x40;
  }
  iVar11 = iVar11 + puVar29[0xf];
  if (uVar10 == 0xb) {
    iVar11 = iVar11 + 0x80;
  }
  else if (uVar10 == 0x13 || uVar10 == 0xe) {
    iVar18 = 0x100;
    goto LAB_00040404;
  }
  iVar18 = 0;
LAB_00040404:
  param_1[0xb] = iVar11 + iVar18;
  if (((iVar22 == 0 && (int)local_64 - iVar5 == 0) || (param_2 == (uint *)0x4)) && (local_5c == 0))
  {
    local_5c = -5;
  }
  return local_5c;
}

