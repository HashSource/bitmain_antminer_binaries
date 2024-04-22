
void set_PWM_according_to_temperature(void)

{
  uint uVar1;
  FILE *pFVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  
  iVar6 = 0;
  iVar3 = dev;
  dVar8 = DAT_0002fb80;
  dVar9 = DAT_0002fb80;
  do {
    if ((*(short *)(iVar3 + 0x56a) != 0) && (*(short *)(iVar3 + 0x572) != 0)) {
      iVar6 = iVar6 + 1;
      dVar9 = dVar9 + (double)(longlong)(int)*(short *)(iVar3 + 0x56a);
      dVar8 = dVar8 + (double)(longlong)(int)*(short *)(iVar3 + 0x572);
    }
    iVar3 = iVar3 + 0x40;
  } while (dev + 0x400 != iVar3);
  dVar8 = dVar8 / (double)(longlong)iVar6;
  dVar9 = dVar9 / (double)(longlong)iVar6;
  if (dVar8 == DAT_0002fb88 || dVar8 < DAT_0002fb88 != (NAN(dVar8) || NAN(DAT_0002fb88))) {
    higher_than_top_counter_13086 = 0;
    cgtime(&now_13089);
    timw_diff_13090._4_4_ = (undefined *)(now_13089._4_4_ - force_mode_timepoint_13088._4_4_);
    timw_diff_13090._0_4_ = (int)now_13089 - (int)force_mode_timepoint_13088;
    if ((int)timw_diff_13090._4_4_ < 0) {
      timw_diff_13090._4_4_ = &DAT_000f4240 + (int)timw_diff_13090._4_4_;
      timw_diff_13090._0_4_ = (int)timw_diff_13090 + -1;
    }
    if ((int)timw_diff_13090 < 0x3d) goto LAB_0002f8f0;
    if (fan_mode_13087 != 0) {
      if (3 < log_level) {
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: %s: fan set normal mode\n","driver-btm-c5.c",0xceb,DAT_0002fd00,
                  DAT_0002fd00);
        }
        fclose(pFVar2);
      }
      fan_mode_13087 = 0;
    }
LAB_0002f8f8:
    if (dVar8 == 0.0 && dVar9 == 0.0) goto LAB_0002f952;
    dVar8 = DAT_0002fcf8;
    dVar10 = DAT_0002fcf0;
    dVar11 = DAT_0002fb90;
    if (dVar9 < DAT_0002fb90 != (NAN(dVar9) || NAN(DAT_0002fb90))) {
      iVar6 = 0x3e;
      iVar4 = 1;
      iVar3 = DAT_0002fba4;
      while( true ) {
        dVar11 = (double)(longlong)iVar6;
        if (dVar9 < dVar11 == (NAN(dVar9) || NAN(dVar11))) break;
        iVar4 = iVar4 + 1;
        dVar8 = DAT_0002fb80;
        dVar10 = DAT_0002fb80;
        dVar11 = DAT_0002fb80;
        if (iVar4 == 6) goto LAB_0002facc;
        iVar6 = *(int *)(iVar3 + 0x24);
        iVar3 = iVar3 + 0x10;
      }
      dVar8 = *(double *)(iVar4 * 0x10 + DAT_0002fba4 + 8);
      dVar10 = (double)(longlong)*(int *)(fan_spend_temp_arg + iVar4 * 0x10);
    }
LAB_0002facc:
    uVar7 = (uint)(longlong)(dVar10 + (dVar9 - dVar11) * dVar8);
  }
  else {
    higher_than_top_counter_13086 = higher_than_top_counter_13086 + 1;
    if ((4 < higher_than_top_counter_13086) && (fan_mode_13087 != 1)) {
      if (3 < log_level) {
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: %s: fan set force mode\n","driver-btm-c5.c",0xcdf,DAT_0002fd00,
                  DAT_0002fd00);
        }
        fclose(pFVar2);
      }
      fan_mode_13087 = 1;
    }
    cgtime(DAT_0002fba0);
LAB_0002f8f0:
    if (fan_mode_13087 != 1) goto LAB_0002f8f8;
LAB_0002f952:
    uVar7 = 100;
  }
  if ((do_pre_heating != '\0') && ((int)((uint)(dVar9 < DAT_0002fb98) << 0x1f) < 0)) {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: doing pre-heating, set fan pwm to 0...\n","driver-btm-c5.c",0xd03,
                DAT_0002fba8);
      }
      fclose(pFVar2);
    }
    iVar3 = dev;
    *(undefined **)(dev + 4) = &DAT_000a0028;
    *(undefined *)(iVar3 + 0x53fc) = 0x14;
    set_fan_control(&DAT_000a0028);
    *(undefined *)(dev + 0x5442) = 0;
    return;
  }
  if ((uVar7 - *(byte *)(dev + 0x5442)) + 1 < 3) {
    return;
  }
  if (5 < log_level) {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: %s: Set PWM percent : %d\n","driver-btm-c5.c",0xd0c,DAT_0002fd00,
              DAT_0002fd00,uVar7);
    }
    fclose(pFVar2);
  }
  if (is7007_ctrl_board == -1) {
    isC5_Board();
  }
  if (is7007_ctrl_board == 1) {
    if (opt_economic_mode == '\0') {
      if (is_working_in_low_temperature == '\0') goto LAB_0002f9d4;
      uVar1 = uVar7 * 3;
      uVar5 = uVar1 & ~((int)uVar1 >> 0x20);
      if ((int)uVar1 < 0) {
        uVar5 = uVar1 + 3;
      }
      uVar5 = (int)uVar5 >> 2;
      if (3 < log_level) {
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: %s: Set PWM percent : %d\n","driver-btm-c5.c",0xd17,DAT_0002fd00
                  ,DAT_0002fd00,uVar5);
        }
        goto LAB_0002fb38;
      }
    }
    else {
      uVar1 = uVar7 * 3;
      uVar5 = uVar1 & ~((int)uVar1 >> 0x20);
      if ((int)uVar1 < 0) {
        uVar5 = uVar1 + 3;
      }
      uVar5 = (int)uVar5 >> 2;
      if (3 < log_level) {
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: %s: Set PWM percent : %d\n","driver-btm-c5.c",0xd11,DAT_0002fba8
                  ,DAT_0002fba8,uVar5);
        }
LAB_0002fb38:
        fclose(pFVar2);
      }
    }
    set_PWM(uVar5 & 0xff);
  }
  else {
LAB_0002f9d4:
    set_PWM(uVar7 & 0xff);
  }
  *(char *)(dev + 0x5442) = (char)uVar7;
  return;
}

