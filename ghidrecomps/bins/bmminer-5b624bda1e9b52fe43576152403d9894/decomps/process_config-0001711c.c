
/* WARNING: Unknown calling convention */

int process_config(void)

{
  undefined uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  bool bVar15;
  bool bVar16;
  char tmp42 [2048];
  
  iVar3 = DAT_000173c0;
  iVar2 = DAT_000173a8;
  iVar7 = *(int *)(DAT_000173a8 + 0xf20);
  uVar5 = *(undefined4 *)(DAT_000173a8 + 0xf78);
  iVar6 = *(int *)(DAT_000173a8 + 0xf74);
  *(int *)(DAT_000173c0 + 0xd60) = iVar7;
  *(undefined4 *)(iVar3 + 0xdb0) = uVar5;
  *(int *)(iVar3 + 0xdac) = iVar6;
  iVar4 = DAT_00017624;
  if (iVar7 == 1) {
    if (iVar6 == 1) {
      if (((*DAT_00017610 == '\0') && (*DAT_00017614 == '\0')) && (*DAT_0001761c < 3)) {
        return -1;
      }
      tmp42._0_4_ = *DAT_00017620;
      tmp42._4_4_ = DAT_00017620[1];
      tmp42._8_4_ = DAT_00017620[2];
      tmp42._12_4_ = DAT_00017620[3];
      tmp42._16_4_ = DAT_00017620[4];
      tmp42._20_4_ = DAT_00017620[5];
      tmp42._24_4_ = DAT_00017620[6];
      tmp42._28_4_ = DAT_00017620[7];
      tmp42._32_4_ = DAT_00017620[8];
      tmp42._36_4_ = DAT_00017620[9];
      tmp42._40_4_ = DAT_00017620[10];
      tmp42._44_2_ = (undefined2)DAT_00017620[0xb];
      _applog(3,tmp42,false);
      return -1;
    }
  }
  else if ((iVar7 == 0) && (iVar6 == 1)) {
    iVar13 = *(int *)(iVar2 + 0xf7c);
    iVar14 = *(int *)(iVar2 + 0xf80);
    iVar7 = *(int *)(iVar2 + 0xf84);
    iVar6 = *(int *)(iVar2 + 0xf88);
    *(char *)((int)cgpu.results[0x6b] + DAT_00017624 + 0x42a8) = (char)uVar5;
    *(undefined *)((int)cgpu.results[0x6b] + iVar4 + 0x42a9) = 1;
    *(undefined *)((int)cgpu.results[0x6b] + iVar4 + 0x42aa) = 3;
    if (iVar14 + iVar13 + iVar7 + iVar6 == 0) {
      if (((*DAT_00017610 == '\0') && (*DAT_00017614 == '\0')) && (*DAT_0001761c < 3)) {
        return -1;
      }
      tmp42._0_4_ = *DAT_0001762c;
      tmp42._4_4_ = DAT_0001762c[1];
      tmp42._8_4_ = DAT_0001762c[2];
      tmp42._12_4_ = DAT_0001762c[3];
      tmp42._16_4_ = DAT_0001762c[4];
      tmp42._20_4_ = DAT_0001762c[5];
      tmp42._24_4_ = DAT_0001762c[6];
      tmp42._28_4_ = DAT_0001762c[7];
      tmp42._32_4_ = DAT_0001762c[8];
      tmp42[36] = (char)(short)DAT_0001762c[9];
      tmp42[37] = (char)((ushort)(short)DAT_0001762c[9] >> 8);
      _applog(3,tmp42,false);
      return -1;
    }
    uVar1 = *(undefined *)(iVar2 + 0xf8c);
    uVar5 = *(undefined4 *)(iVar2 + 0xfa8);
    uVar9 = *(undefined4 *)(iVar2 + 0xfac);
    *(char *)(iVar3 + 0xdb4) = (char)iVar13;
    *(char *)(iVar3 + 0xdb5) = (char)iVar14;
    *(char *)(iVar3 + 0xdb6) = (char)iVar7;
    *(char *)(iVar3 + 0xdb7) = (char)iVar6;
    *(undefined *)((int)cgpu.results[0x6b] + iVar4 + 0x42ab) = uVar1;
    *(undefined *)(iVar3 + 0xdb8) = uVar1;
    *(undefined *)((int)cgpu.results[0x6b] + iVar4 + 0x42ac) = uVar1;
    *(undefined *)((int)cgpu.results[0x6b] + iVar4 + 0x42ad) = uVar1;
    *(undefined *)((int)cgpu.results[0x6b] + iVar4 + 0x42ae) = uVar1;
    *(char *)(iVar3 + 0xdd4) = (char)uVar5;
    *(char *)(iVar3 + 0xdd5) = (char)uVar9;
  }
  uVar9 = *(undefined4 *)(iVar2 + 0xf9c);
  iVar6 = *(int *)(iVar2 + 0xf0c);
  *(undefined4 *)(iVar3 + 0xdbc) = *(undefined4 *)(iVar2 + 0xf90);
  uVar5 = *(undefined4 *)(iVar2 + 0xf94);
  *(undefined4 *)(iVar3 + 0xdc8) = uVar9;
  uVar9 = *(undefined4 *)(iVar2 + 4000);
  *(undefined4 *)(iVar3 + 0xdc0) = uVar5;
  uVar5 = *(undefined4 *)(iVar2 + 0xfa4);
  *(undefined4 *)(iVar3 + 0xdcc) = uVar9;
  uVar9 = *(undefined4 *)(iVar2 + 0xf60);
  *(undefined4 *)(iVar3 + 0xdd0) = uVar5;
  uVar5 = *(undefined4 *)(iVar2 + 0xf64);
  uVar11 = *(undefined4 *)(iVar2 + 0xf98);
  *(undefined4 *)(iVar3 + 0xd98) = uVar9;
  *(undefined4 *)(iVar3 + 0xd9c) = uVar5;
  uVar9 = *(undefined4 *)(iVar2 + 0xf68);
  uVar5 = *(undefined4 *)(iVar2 + 0xf6c);
  *(int *)(iVar3 + 0xd3c) = iVar6;
  *(undefined4 *)(iVar3 + 0xdc4) = uVar11;
  *(undefined4 *)(iVar3 + 0xda0) = uVar9;
  *(undefined4 *)(iVar3 + 0xda4) = uVar5;
  *(undefined4 *)(iVar3 + 0xd64) = 0x56b;
  *(undefined4 *)(iVar3 + 0xd58) = 0x20;
  *(undefined4 *)(iVar2 + 0xf08) = 4;
  *(undefined4 *)(iVar3 + 0xd54) = 4;
  iVar4 = iVar6;
  if (((iVar6 != 1) && (iVar6 != 2)) && (iVar4 = 4, 1 < iVar6 - 3U)) {
    if (iVar6 - 5U < 4) {
      iVar4 = 8;
    }
    else if (iVar6 - 9U < 8) {
      iVar4 = 0x10;
    }
    else if (iVar6 - 0x11U < 0x10) {
      iVar4 = 0x20;
    }
    else if (iVar6 - 0x21U < 0x20) {
      iVar4 = 0x40;
    }
    else if (iVar6 - 0x41U < 0x40) {
      iVar4 = 0x80;
    }
    else if ((*DAT_000173ac == '\0') ||
            (((*DAT_000173b0 == '\0' && (*DAT_000173b4 == '\0')) && (*DAT_000173b8 < 7)))) {
      iVar4 = -1;
    }
    else {
      snprintf(tmp42,0x800,DAT_000173bc,iVar6);
      _applog(7,tmp42,false);
      iVar4 = -1;
    }
  }
  uVar12 = *(undefined4 *)(iVar2 + 0xf28);
  uVar9 = *(undefined4 *)(iVar2 + 0xf2c);
  *(undefined4 *)(iVar3 + 0xd8c) = *(undefined4 *)(iVar2 + 0xf5c);
  uVar8 = *(undefined4 *)(iVar2 + 0xf30);
  uVar5 = *(undefined4 *)(iVar2 + 0xf34);
  *(undefined4 *)(iVar3 + 0xda8) = *(undefined4 *)(iVar2 + 0xf70);
  uVar11 = *(undefined4 *)(iVar2 + 0xf38);
  uVar10 = *(undefined4 *)(iVar2 + 0xf18);
  *(undefined4 *)(iVar3 + 0xd68) = uVar12;
  *(undefined4 *)(iVar3 + 0xd78) = uVar11;
  uVar11 = *(undefined4 *)(iVar2 + 0xf3c);
  *(undefined4 *)(iVar3 + 0xd5c) = uVar10;
  uVar12 = *(undefined4 *)(iVar2 + 0xfb0);
  *(undefined4 *)(iVar3 + 0xd7c) = uVar11;
  uVar11 = *(undefined4 *)(iVar2 + 0xf40);
  uVar10 = *(undefined4 *)(iVar2 + 0xef4);
  *(undefined4 *)(iVar3 + 0xd6c) = uVar9;
  *(undefined4 *)(iVar3 + 0xd80) = uVar11;
  uVar11 = *(undefined4 *)(iVar2 + 0xf54);
  uVar9 = *(undefined4 *)(iVar2 + 0xfb4);
  *(undefined4 *)(iVar3 + 0xd70) = uVar8;
  *(undefined4 *)(iVar3 + 0xd74) = uVar5;
  uVar8 = *(undefined4 *)(iVar2 + 0xfb8);
  uVar5 = *(undefined4 *)(iVar2 + 0xfbc);
  *(undefined4 *)(iVar3 + 0xd84) = uVar11;
  uVar11 = *(undefined4 *)(iVar2 + 0xf58);
  *(undefined4 *)(iVar3 + 0xddc) = uVar9;
  *(undefined4 *)(iVar3 + 0xde0) = uVar8;
  *(undefined4 *)(iVar3 + 0xd88) = uVar11;
  *(undefined4 *)(iVar3 + 0xd40) = uVar10;
  *(undefined4 *)(iVar3 + 0xdd8) = uVar12;
  *(undefined4 *)(iVar3 + 0xde4) = uVar5;
  iVar6 = DAT_000173c0;
  iVar7 = *(int *)(iVar2 + 0xef8);
  uVar5 = *(undefined4 *)(iVar2 + 0xfc4);
  *(undefined4 *)(iVar3 + 0xde8) = *(undefined4 *)(iVar2 + 0xfc0);
  *(undefined4 *)(iVar3 + 0xdec) = uVar5;
  if (iVar7 < 1) {
    iVar4 = __aeabi_idiv(0x1000000,iVar4);
    iVar4 = __aeabi_idiv(*(int *)(iVar6 + 0xd54) * iVar4,uVar10);
    *(int *)(iVar6 + 0xd44) = (iVar4 * 0x5f) / 100;
  }
  else {
    *(int *)(iVar6 + 0xd44) = iVar7;
  }
  iVar4 = __aeabi_idiv(0x196e6a);
  iVar6 = __aeabi_uidiv(0x2faf08,iVar4 << 9);
  iVar4 = DAT_000173c0;
  iVar7 = iVar6 + -1;
  bVar16 = SBORROW4(iVar7,0x1a);
  bVar15 = iVar7 == 0x1a;
  *(int *)(iVar3 + 0xd48) = iVar7;
  if (0x1a < iVar7) {
    iVar7 = 0x1a;
  }
  if (bVar15 || iVar6 + -0x1b < 0 != bVar16) {
    if (iVar7 < 1) {
      if (((*DAT_00017610 == '\0') && (*DAT_00017614 == '\0')) && (*DAT_0001761c < 3)) {
        return -1;
      }
      snprintf(tmp42,0x800,DAT_00017628);
      _applog(3,tmp42,false);
      return -1;
    }
  }
  else {
    *(int *)(iVar4 + 0xd48) = iVar7;
  }
  iVar4 = *(int *)(iVar2 + 0xee4);
  if (iVar4 - 1U < 5000) {
    *(int *)(iVar3 + 0xd2c) = iVar4;
  }
  else {
    if (((*DAT_000173b0 != '\0') || (*DAT_000173b4 != '\0')) || (2 < *DAT_0001761c)) {
      snprintf(tmp42,0x800,DAT_000173c4);
      _applog(3,tmp42,false);
    }
    iVar4 = *(int *)(iVar3 + 0xd2c);
  }
  iVar6 = *(int *)(iVar2 + 0xee8);
  if ((iVar4 < iVar6) || (iVar6 < 0)) {
    if ((*DAT_00017610 == '\0') && ((*DAT_00017614 == '\0' && (*DAT_0001761c < 3))))
    goto LAB_00017376;
    snprintf(tmp42,0x800,DAT_00017618,*(undefined4 *)(iVar2 + 0xee4));
    _applog(3,tmp42,false);
    iVar4 = *(int *)(iVar3 + 0xd2c);
    iVar6 = *(int *)(iVar2 + 0xeec);
    if (iVar6 <= iVar4) goto LAB_0001737e;
LAB_000173fe:
    if (((*DAT_00017610 == '\0') && (*DAT_00017614 == '\0')) && (*DAT_0001761c < 3))
    goto LAB_00017388;
    snprintf(tmp42,0x800,DAT_00017618,*(undefined4 *)(iVar2 + 0xee4));
    _applog(3,tmp42,false);
    iVar6 = *(int *)(iVar2 + 0xef0);
    if (*(int *)(iVar3 + 0xd2c) < iVar6) goto LAB_00017434;
  }
  else {
    *(int *)(iVar3 + 0xd30) = iVar6;
LAB_00017376:
    iVar6 = *(int *)(iVar2 + 0xeec);
    if (iVar4 < iVar6) goto LAB_000173fe;
LAB_0001737e:
    if (iVar6 < 0) goto LAB_000173fe;
    *(int *)(iVar3 + 0xd34) = iVar6;
LAB_00017388:
    iVar6 = *(int *)(iVar2 + 0xef0);
    if (iVar4 < iVar6) goto LAB_00017434;
  }
  if (-1 < iVar6) {
    *(int *)(iVar3 + 0xd38) = iVar6;
    return 0;
  }
LAB_00017434:
  if (((*DAT_00017610 != '\0') || (*DAT_00017614 != '\0')) || (2 < *DAT_0001761c)) {
    snprintf(tmp42,0x800,DAT_00017618,*(undefined4 *)(iVar2 + 0xee4));
    _applog(3,tmp42,false);
  }
  return 0;
}

