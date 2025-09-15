
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_PWM_according_to_temperature(void)

{
  byte bVar1;
  _Bool _Var2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uchar pwm_percent;
  uint uVar7;
  int iVar8;
  bool bVar9;
  int iVar10;
  char logstr [256];
  char tmp42 [2048];
  
  bVar1 = dev->fan_pwm;
  if (is218_Temp) {
    temp_highest = dev->temp_top1[0];
  }
  else {
    temp_highest = dev->temp_top1[1];
  }
  iVar8 = dev->temp_top1[0];
  iVar5 = temp_highest - last_temperature;
  iVar3 = iVar5;
  iVar10 = set_PWM_according_to_temperature::fix_fan_steps;
  sprintf(logstr,
          "set FAN speed according to: temp_highest=%d temp_top1[PWM_T]=%d temp_top1[TEMP_POS_LOCAL]=%d temp_change=%d fix_fan_steps=%d\n"
          ,temp_highest,dev->temp_top1[1],iVar8,iVar5,
          set_PWM_according_to_temperature::fix_fan_steps);
  writeLogFile(logstr);
  if (is218_Temp != false) {
    if (temp_highest != 0 && temp_highest < 0x4b) {
      if (iVar5 + 1U < 3) {
        return;
      }
      builtin_strncpy(logstr,"set normal FAN speed...\n",0x18);
      logstr[0x18] = '\0';
      writeLogFile(logstr);
      _Var2 = opt_debug;
      uVar4 = (temp_highest + -0x19) * 2;
      uVar7 = 0;
      uVar6 = uVar7;
      if (-1 < (int)uVar4) {
        if ((int)uVar4 < 0x65) {
          uVar7 = uVar4;
          uVar6 = uVar4 & 0xff;
        }
        else {
          uVar7 = 100;
          uVar6 = uVar7;
        }
      }
      last_temperature = temp_highest;
      dev->fan_pwm = (uchar)uVar6;
      if ((_Var2 != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: Set PWM percent : %d\n","set_PWM_according_to_temperature",uVar7);
        _applog(7,tmp42,false);
      }
      set_PWM((uchar)uVar6);
      return;
    }
    set_PWM('d');
    dev->fan_pwm = 'd';
LAB_00033686:
    logstr[0xc] = ' ';
    logstr[0xd] = 's';
    logstr[0xe] = 'p';
    logstr[0xf] = 'e';
    logstr[8] = ' ';
    logstr[9] = 'F';
    logstr[10] = 'A';
    logstr[0xb] = 'N';
    logstr[4] = 'f';
    logstr[5] = 'u';
    logstr[6] = 'l';
    logstr[7] = 'l';
    logstr[0] = 's';
    logstr[1] = 'e';
    logstr[2] = 't';
    logstr[3] = ' ';
    builtin_strncpy(logstr + 0x10,"ed..",4);
    logstr[0x14] = '.';
    logstr[0x15] = '\n';
    logstr[0x16] = '\0';
    writeLogFile(logstr);
    return;
  }
  if (((temp_highest == 0 || 0x59 < temp_highest) || (0x59 < dev->temp_top1[1])) ||
     (0x4a < dev->temp_top1[0])) {
    set_PWM('d');
    bVar9 = set_PWM_according_to_temperature::fix_fan_steps < 0;
    iVar3 = set_PWM_according_to_temperature::fix_fan_steps;
    if (bVar9) {
      iVar3 = 0;
    }
    dev->fan_pwm = 'd';
    if (bVar9) {
      set_PWM_according_to_temperature::fix_fan_steps = iVar3;
    }
    goto LAB_00033686;
  }
  if (iVar5 + 1U < 3) {
    if (temp_highest < 0x51) {
      if (set_PWM_according_to_temperature::fix_fan_steps + 0x27 < 0 !=
          SCARRY4(set_PWM_according_to_temperature::fix_fan_steps,0x27)) {
        return;
      }
      if (bVar1 == 0) {
        return;
      }
      set_PWM_according_to_temperature::fix_fan_steps =
           set_PWM_according_to_temperature::fix_fan_steps + -1;
    }
    else {
      if (temp_highest < 0x55) {
        return;
      }
      if (99 < bVar1) {
        return;
      }
      set_PWM_according_to_temperature::fix_fan_steps =
           set_PWM_according_to_temperature::fix_fan_steps + 1;
    }
    sprintf(logstr,"set normal FAN speed... with fix_fan_steps=%d\n",
            set_PWM_according_to_temperature::fix_fan_steps,
            set_PWM_according_to_temperature::fix_fan_steps,iVar8,iVar3,iVar10);
    writeLogFile(logstr);
    iVar3 = (temp_highest + -0x28 + set_PWM_according_to_temperature::fix_fan_steps) * 2;
    pwm_percent = '\0';
    if (-1 < iVar3) {
      if (iVar3 < 0x65) {
        pwm_percent = (uchar)iVar3;
      }
      else {
        pwm_percent = 'd';
      }
    }
    dev->fan_pwm = pwm_percent;
    set_PWM(pwm_percent);
    return;
  }
  sprintf(logstr,"set normal FAN speed...with fix_fan_steps=%d\n",
          set_PWM_according_to_temperature::fix_fan_steps,temp_highest,iVar8,iVar3,iVar10);
  writeLogFile(logstr);
  _Var2 = opt_debug;
  uVar7 = (temp_highest + -0x28 + set_PWM_according_to_temperature::fix_fan_steps) * 2;
  if ((int)uVar7 < 0) {
    uVar7 = 0;
LAB_000337d2:
    if (0x54 < temp_highest) {
      if (uVar7 != 100) {
        set_PWM_according_to_temperature::fix_fan_steps =
             set_PWM_according_to_temperature::fix_fan_steps + 1;
        uVar7 = (temp_highest + -0x28 + set_PWM_according_to_temperature::fix_fan_steps) * 2;
        if ((int)uVar7 < 0) {
          uVar7 = 0;
          uVar6 = uVar7;
          goto LAB_00033786;
        }
        if ((int)uVar7 < 0x65) goto LAB_00033784;
      }
LAB_000337ea:
      uVar7 = 100;
      uVar6 = uVar7;
      goto LAB_00033786;
    }
  }
  else {
    if ((int)uVar7 < 0x65) goto LAB_000337d2;
    if (0x54 < temp_highest) goto LAB_000337ea;
    uVar7 = 100;
  }
LAB_00033784:
  uVar6 = uVar7 & 0xff;
LAB_00033786:
  last_temperature = temp_highest;
  dev->fan_pwm = (uchar)uVar6;
  if ((_Var2 != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: Set PWM percent : %d\n","set_PWM_according_to_temperature",uVar7);
    _applog(7,tmp42,false);
  }
  set_PWM((uchar)uVar6);
  return;
}

