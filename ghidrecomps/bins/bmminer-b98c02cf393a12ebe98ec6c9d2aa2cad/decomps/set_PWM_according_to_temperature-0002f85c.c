
void set_PWM_according_to_temperature(void)

{
  uint uVar1;
  FILE *pFVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  
  dVar8 = 0.0;
  iVar6 = 0;
  iVar4 = dev;
  dVar9 = dVar8;
  do {
    if ((*(short *)(iVar4 + 0x56a) != 0) && (*(short *)(iVar4 + 0x572) != 0)) {
      iVar6 = iVar6 + 1;
      dVar9 = dVar9 + (double)(longlong)(int)*(short *)(iVar4 + 0x56a);
      dVar8 = dVar8 + (double)(longlong)(int)*(short *)(iVar4 + 0x572);
    }
    iVar4 = iVar4 + 0x40;
  } while (dev + 0x400 != iVar4);
  dVar8 = dVar8 / (double)(longlong)iVar6;
  dVar9 = dVar9 / (double)(longlong)iVar6;
  if (dVar8 <= 85.0) {
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
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: %s: fan set normal mode\n","driver-btm-c5.c",0xceb,
                  "set_PWM_according_to_temperature","set_PWM_according_to_temperature");
        }
        fclose(pFVar2);
      }
      fan_mode_13087 = 0;
    }
LAB_0002f8f8:
    if (dVar8 == 0.0 && dVar9 == 0.0) goto LAB_0002f952;
    dVar8 = 65.0;
    if (65.0 <= dVar9) {
      dVar11 = 100.0;
      dVar10 = 0.0;
    }
    else {
      iVar4 = 0x3e;
      iVar6 = 1;
      puVar3 = fan_spend_temp_arg;
      while( true ) {
        dVar8 = (double)(longlong)iVar4;
        if (dVar8 <= dVar9) break;
        iVar6 = iVar6 + 1;
        if (iVar6 == 6) {
          dVar10 = 0.0;
          dVar11 = dVar10;
          dVar8 = dVar10;
          goto LAB_0002facc;
        }
        iVar4 = *(int *)(puVar3 + 0x24);
        puVar3 = puVar3 + 0x10;
      }
      dVar10 = *(double *)(fan_spend_temp_arg + iVar6 * 0x10 + 8);
      dVar11 = (double)(longlong)*(int *)(fan_spend_temp_arg + iVar6 * 0x10);
    }
LAB_0002facc:
    uVar7 = (uint)(longlong)(dVar11 + (dVar9 - dVar8) * dVar10);
  }
  else {
    higher_than_top_counter_13086 = higher_than_top_counter_13086 + 1;
    if ((4 < higher_than_top_counter_13086) && (fan_mode_13087 != 1)) {
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: %s: fan set force mode\n","driver-btm-c5.c",0xcdf,
                  "set_PWM_according_to_temperature","set_PWM_according_to_temperature");
        }
        fclose(pFVar2);
      }
      fan_mode_13087 = 1;
    }
    cgtime(&force_mode_timepoint_13088);
LAB_0002f8f0:
    if (fan_mode_13087 != 1) goto LAB_0002f8f8;
LAB_0002f952:
    uVar7 = 100;
  }
  if ((do_pre_heating != '\0') && ((int)((uint)(dVar9 < 50.0) << 0x1f) < 0)) {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: doing pre-heating, set fan pwm to 0...\n","driver-btm-c5.c",0xd03,
                "set_PWM_according_to_temperature");
      }
      fclose(pFVar2);
    }
    iVar4 = dev;
    *(undefined **)(dev + 4) = &DAT_000a0028;
    *(undefined1 *)(iVar4 + 0x53fc) = 0x14;
    set_fan_control(&DAT_000a0028);
    *(undefined1 *)(dev + 0x5442) = 0;
    return;
  }
  if ((uVar7 - *(byte *)(dev + 0x5442)) + 1 < 3) {
    return;
  }
  if (5 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: %s: Set PWM percent : %d\n","driver-btm-c5.c",0xd0c,
              "set_PWM_according_to_temperature","set_PWM_according_to_temperature",uVar7);
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
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: %s: Set PWM percent : %d\n","driver-btm-c5.c",0xd17,
                  "set_PWM_according_to_temperature","set_PWM_according_to_temperature",uVar5);
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
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: %s: Set PWM percent : %d\n","driver-btm-c5.c",0xd11,
                  "set_PWM_according_to_temperature","set_PWM_according_to_temperature",uVar5);
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

