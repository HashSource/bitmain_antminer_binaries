
/* WARNING: Unknown calling convention */

void set_PWM_according_to_temperature(void)

{
  char cVar1;
  byte bVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uchar pwm_percent;
  uint uVar14;
  undefined4 uVar15;
  bool bVar16;
  int iVar17;
  char logstr [256];
  char tmp42 [2048];
  
  iVar9 = DAT_00033800;
  iVar8 = DAT_000337fc;
  piVar3 = DAT_000337f8;
  iVar6 = *DAT_000337f8;
  bVar2 = *(byte *)(iVar6 + 0x2fed);
  if (*(char *)(DAT_000337fc + 0xe18) == '\0') {
    iVar11 = *(int *)(iVar6 + 0x2fc7);
    *(int *)(DAT_00033800 + 0x628) = iVar11;
  }
  else {
    iVar11 = *(int *)(iVar6 + 0x2fc3);
    *(int *)(DAT_00033800 + 0x628) = iVar11;
  }
  uVar15 = *(undefined4 *)(iVar6 + 0x2fc3);
  iVar12 = iVar11 - *(int *)(iVar9 + 0x62c);
  uVar7 = *(undefined4 *)(iVar9 + 0x630);
  iVar17 = iVar12;
  sprintf(logstr,DAT_00033804,iVar11,*(undefined4 *)(iVar6 + 0x2fc7),uVar15,iVar12,uVar7);
  writeLogFile(logstr);
  puVar5 = DAT_0003380c;
  pcVar4 = DAT_00033808;
  iVar6 = DAT_00033800;
  if (*(char *)(iVar8 + 0xe18) != '\0') {
    if (*(int *)(DAT_00033800 + 0x628) != 0 && *(int *)(DAT_00033800 + 0x628) < 0x4b) {
      if (iVar12 + 1U < 3) {
        return;
      }
      logstr._0_4_ = *DAT_0003382c;
      logstr._4_4_ = DAT_0003382c[1];
      logstr._8_4_ = DAT_0003382c[2];
      logstr._12_4_ = DAT_0003382c[3];
      logstr._16_4_ = DAT_0003382c[4];
      logstr._20_4_ = DAT_0003382c[5];
      logstr[24] = (char)DAT_0003382c[6];
      writeLogFile(logstr);
      pcVar4 = DAT_00033810;
      uVar10 = (*(int *)(iVar6 + 0x628) + -0x19) * 2;
      uVar14 = 0;
      uVar13 = uVar14;
      if (-1 < (int)uVar10) {
        if ((int)uVar10 < 0x65) {
          uVar14 = uVar10;
          uVar13 = uVar10 & 0xff;
        }
        else {
          uVar14 = 100;
          uVar13 = uVar14;
        }
      }
      iVar8 = *piVar3;
      *(int *)(iVar9 + 0x62c) = *(int *)(iVar6 + 0x628);
      cVar1 = *pcVar4;
      *(uchar *)(iVar8 + 0x2fed) = (uchar)uVar13;
      if ((cVar1 != '\0') &&
         (((*DAT_00033814 != '\0' || (*DAT_00033818 != '\0')) || (6 < *DAT_0003381c)))) {
        snprintf(tmp42,0x800,DAT_00033820,DAT_00033824,uVar14);
        _applog(7,tmp42,false);
      }
      set_PWM((uchar)uVar13);
      return;
    }
    set_PWM('d');
    logstr._0_4_ = *puVar5;
    logstr._4_4_ = puVar5[1];
    logstr._8_4_ = puVar5[2];
    logstr._12_4_ = puVar5[3];
    *(undefined *)(*piVar3 + 0x2fed) = 100;
LAB_00033686:
    logstr._16_4_ = puVar5[4];
    logstr._20_3_ = (undefined3)puVar5[5];
    writeLogFile(logstr);
    return;
  }
  iVar8 = *(int *)(DAT_00033800 + 0x628);
  if (((iVar8 == 0 || 0x59 < iVar8) || (0x59 < *(int *)(*piVar3 + 0x2fc7))) ||
     (0x4a < *(int *)(*piVar3 + 0x2fc3))) {
    set_PWM('d');
    iVar8 = DAT_00033800;
    iVar9 = *(int *)(iVar9 + 0x630);
    bVar16 = iVar9 < 0;
    if (bVar16) {
      iVar9 = 0;
    }
    *(undefined *)(*piVar3 + 0x2fed) = 100;
    if (bVar16) {
      *(int *)(iVar8 + 0x630) = iVar9;
    }
    logstr._0_4_ = *puVar5;
    logstr._4_4_ = puVar5[1];
    logstr._8_4_ = puVar5[2];
    logstr._12_4_ = puVar5[3];
    goto LAB_00033686;
  }
  if (iVar12 + 1U < 3) {
    if (iVar8 < 0x51) {
      iVar8 = *(int *)(DAT_00033800 + 0x630);
      if (iVar8 + 0x27 < 0 != SCARRY4(iVar8,0x27)) {
        return;
      }
      if (bVar2 == 0) {
        return;
      }
      iVar8 = iVar8 + -1;
    }
    else {
      if (iVar8 < 0x55) {
        return;
      }
      if (99 < bVar2) {
        return;
      }
      iVar8 = *(int *)(DAT_00033800 + 0x630) + 1;
    }
    *(int *)(DAT_00033800 + 0x630) = iVar8;
    sprintf(logstr,pcVar4,iVar8,iVar8,uVar15,iVar17,uVar7);
    writeLogFile(logstr);
    iVar8 = (*(int *)(iVar6 + 0x628) + -0x28 + *(int *)(iVar6 + 0x630)) * 2;
    pwm_percent = '\0';
    if (-1 < iVar8) {
      if (iVar8 < 0x65) {
        pwm_percent = (uchar)iVar8;
      }
      else {
        pwm_percent = 'd';
      }
    }
    *(uchar *)(*piVar3 + 0x2fed) = pwm_percent;
    set_PWM(pwm_percent);
    return;
  }
  sprintf(logstr,DAT_00033828,*(undefined4 *)(DAT_00033800 + 0x630),iVar8,uVar15,iVar17,uVar7);
  writeLogFile(logstr);
  iVar8 = *(int *)(iVar6 + 0x628);
  uVar14 = (iVar8 + -0x28 + *(int *)(iVar6 + 0x630)) * 2;
  if ((int)uVar14 < 0) {
    uVar14 = 0;
LAB_000337d2:
    if (0x54 < iVar8) {
      if (uVar14 != 100) {
        iVar6 = *(int *)(iVar6 + 0x630) + 1;
        *(int *)(iVar9 + 0x630) = iVar6;
        uVar14 = (iVar8 + -0x28 + iVar6) * 2;
        if ((int)uVar14 < 0) {
          uVar14 = 0;
          uVar13 = uVar14;
          goto LAB_00033786;
        }
        if ((int)uVar14 < 0x65) goto LAB_00033784;
      }
LAB_000337ea:
      uVar14 = 100;
      uVar13 = uVar14;
      goto LAB_00033786;
    }
  }
  else {
    if ((int)uVar14 < 0x65) goto LAB_000337d2;
    if (0x54 < iVar8) goto LAB_000337ea;
    uVar14 = 100;
  }
LAB_00033784:
  uVar13 = uVar14 & 0xff;
LAB_00033786:
  pcVar4 = DAT_00033810;
  iVar6 = *piVar3;
  *(int *)(iVar9 + 0x62c) = iVar8;
  cVar1 = *pcVar4;
  *(uchar *)(iVar6 + 0x2fed) = (uchar)uVar13;
  if ((cVar1 != '\0') &&
     (((*DAT_00033814 != '\0' || (*DAT_00033818 != '\0')) || (6 < *DAT_0003381c)))) {
    snprintf(tmp42,0x800,DAT_00033820,DAT_00033824,uVar14);
    _applog(7,tmp42,false);
  }
  set_PWM((uchar)uVar13);
  return;
}

