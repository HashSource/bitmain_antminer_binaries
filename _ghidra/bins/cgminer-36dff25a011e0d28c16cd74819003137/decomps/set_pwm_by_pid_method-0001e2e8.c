
/* WARNING: Unknown calling convention */

int set_pwm_by_pid_method(void)

{
  int iVar1;
  FILE *pFVar2;
  int airin_pcb_temp_00;
  int iVar3;
  float fVar4;
  FILE *pFile_1;
  FILE *pFile;
  float delta_pwm;
  float b;
  float a;
  int target_airout_pcb_temp;
  int airout_pcb_temp;
  int airin_pcb_temp;
  int pwm_percent;
  
  pwm_percent = (int)dev->fan_pwm;
  airin_pcb_temp_00 = dev->temp_low1[0];
  iVar3 = dev->temp_top1[0];
  if (iVar3 < 0x44) {
    iVar1 = get_target_airout_pcb_temp(airin_pcb_temp_00);
    fVar4 = (float)(longlong)(iVar3 - iVar1) * 1.0 -
            (float)(longlong)(set_pwm_by_pid_method::last_airout_pcb_temp - iVar1) * 0.5;
    if (((int)fVar4 + 1 < 0 == SCARRY4((int)fVar4,1)) && ((int)fVar4 < 2)) {
      if (3 < log_level) {
        print_crt_time_to_file(temp_log,3);
        pFVar2 = fopen(temp_log,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,
                  "%s:%d:%s: PWM keep %d:  airin_pcb_temp=%d, airout_pcb_temp=%d, last_airout_pcb_temp=%d, target_airout_pcb_temp=%d, delta_pwm=%0.1f\n"
                  ,"temperature.c",0x1c8,"set_pwm_by_pid_method",pwm_percent,airin_pcb_temp_00,iVar3
                  ,set_pwm_by_pid_method::last_airout_pcb_temp,iVar1,(double)fVar4);
        }
        fclose(pFVar2);
      }
    }
    else {
      pwm_percent = (int)(longlong)((float)(longlong)pwm_percent + fVar4 + 0.5);
      if (pwm_percent < 0x14) {
        pwm_percent = 0x14;
      }
      if (100 < pwm_percent) {
        pwm_percent = 100;
      }
      if (3 < log_level) {
        print_crt_time_to_file(temp_log,3);
        pFVar2 = fopen(temp_log,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,
                  "%s:%d:%s: PWM change from %d to %d:  airin_pcb_temp=%d, airout_pcb_temp=%d, last_airout_pcb_temp=%d, target_airout_pcb_temp=%d, delta_pwm=%0.1f\n"
                  ,"temperature.c",0x1d4,"set_pwm_by_pid_method",(uint)dev->fan_pwm,pwm_percent,
                  airin_pcb_temp_00,iVar3,set_pwm_by_pid_method::last_airout_pcb_temp,iVar1);
        }
        fclose(pFVar2);
      }
      set_pwm((uchar)pwm_percent);
    }
    dev->fan_pwm = (uint8_t)pwm_percent;
    set_pwm_by_pid_method::last_airout_pcb_temp = iVar3;
  }
  else {
    set_pwm('d');
    pwm_percent = 100;
  }
  return pwm_percent;
}

