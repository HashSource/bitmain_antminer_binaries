
/* WARNING: Unknown calling convention */

int set_pwm_by_pid_method(void)

{
  _Bool _Var1;
  FILE *pFVar2;
  uint uVar3;
  int iVar4;
  int min_entrance_pcb_temp;
  int iVar5;
  int iVar6;
  FILE *pFile;
  FILE *pFile_2;
  FILE *pFile_1;
  int max_pwm_chip_temp;
  int pwm_change;
  float b;
  float a;
  int target_chip_temp;
  int entrance_pcb_temp;
  int current_chip_temp;
  int pwm_percent;
  
  uVar3 = (uint)dev->fan_pwm;
  _Var1 = is_special_mode();
  if (_Var1) {
    iVar4 = 0x5f;
  }
  else {
    iVar4 = 0x5a;
  }
  min_entrance_pcb_temp = dev->temp_low1[0];
  iVar5 = dev->temp_top1[1];
  if (set_pwm_by_pid_method::last_chip_temp == 0) {
    set_pwm_by_pid_method::last_chip_temp = iVar5;
  }
  if (iVar4 < iVar5) {
    pwm_percent = 100;
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar2 = fopen(temp_log,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: chip temp %d exceeds %d will set max pwm\n","temperature.c",0x707,
                "set_pwm_by_pid_method",iVar5,iVar4);
      }
      fclose(pFVar2);
    }
  }
  else {
    iVar4 = get_target_chip_temp(min_entrance_pcb_temp);
    iVar6 = (int)((float)(longlong)(iVar5 - iVar4) * 4.0 -
                 (float)(longlong)(set_pwm_by_pid_method::last_chip_temp - iVar4) * 2.0);
    if ((-2 < iVar6) && (iVar6 < 2)) {
      if (log_level < 4) {
        return uVar3;
      }
      print_crt_time_to_file(temp_log,3);
      pFVar2 = fopen(temp_log,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,
                "%s:%d:%s: PWM keep %d: last_temp=%d, current_temp=%d, entrance_pcb_temp=%d, target_temp=%d, pwm_change=%d\n"
                ,"temperature.c",0x711,"set_pwm_by_pid_method",uVar3,
                set_pwm_by_pid_method::last_chip_temp,iVar5,min_entrance_pcb_temp,iVar4,iVar6);
      }
      fclose(pFVar2);
      return uVar3;
    }
    pwm_percent = iVar6 + uVar3;
    if (pwm_percent < 5) {
      pwm_percent = 5;
    }
    if (100 < pwm_percent) {
      pwm_percent = 100;
    }
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar2 = fopen(temp_log,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,
                "%s:%d:%s: PWM change from %d to %d: last_temp=%d, current_temp=%d, entrance_pcb_temp=%d, target_temp=%d, pwm_change=%d\n"
                ,"temperature.c",0x71d,"set_pwm_by_pid_method",(uint)dev->fan_pwm,pwm_percent,
                set_pwm_by_pid_method::last_chip_temp,iVar5,min_entrance_pcb_temp,iVar4,iVar6);
      }
      fclose(pFVar2);
    }
  }
  set_PWM((uchar)pwm_percent);
  dev->fan_pwm = (uchar)pwm_percent;
  set_pwm_by_pid_method::last_chip_temp = iVar5;
  return pwm_percent;
}

