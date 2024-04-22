
/* WARNING: Unknown calling convention */

void set_pwm_by_temp(void)

{
  FILE *pFVar1;
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_2;
  
  if ((config_parameter._4_1_ & 2) == 0) {
    if (read_temp_error) {
      set_PWM('d');
      dev->fan_pwm = 'd';
      if (3 < log_level) {
        print_crt_time_to_file(temp_log,3);
        pFVar1 = fopen(temp_log,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: Set fixed full fan speed\n","temperature.c",0x457,
                  "set_pwm_by_temp");
        }
        fclose(pFVar1);
      }
    }
    else {
      set_PWM_according_to_temperature(last_testpatten_highest_pcb_temp);
    }
  }
  else if (config_parameter.fan_pwm_percent < 0x65) {
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar1 = fopen(temp_log,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Set fixed fan speed=%d\n","temperature.c",0x43f,"set_pwm_by_temp",
                (uint)config_parameter.fan_pwm_percent);
      }
      fclose(pFVar1);
    }
    set_PWM(config_parameter.fan_pwm_percent);
  }
  else if (read_temp_error) {
    set_PWM('d');
    dev->fan_pwm = 'd';
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar1 = fopen(temp_log,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Set fixed full fan speed\n","temperature.c",0x44a,
                "set_pwm_by_temp");
      }
      fclose(pFVar1);
    }
  }
  else {
    set_PWM_according_to_temperature(last_testpatten_highest_pcb_temp);
  }
  return;
}

