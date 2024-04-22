
/* WARNING: Unknown calling convention */

void set_pwm_by_temp(void)

{
  _Bool _Var1;
  FILE *pFVar2;
  FILE *pFile;
  FILE *pFile_4;
  FILE *pFile_1;
  FILE *pFile_3;
  FILE *pFile_2;
  
  _Var1 = is_hashboard_dead();
  if (_Var1) {
    if (1 < log_level) {
      print_crt_time_to_file(temp_log,1);
      pFVar2 = fopen(temp_log,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: error: no need to set_pwm_by_temp for reason: %d\n",
                "temperature.c",0x329,"set_pwm_by_temp",status_value);
      }
      fclose(pFVar2);
    }
  }
  else {
    _Var1 = is_full_speed_fan();
    if (_Var1) {
      set_pwm('d');
      dev->fan_pwm = 'd';
      if (3 < log_level) {
        print_crt_time_to_file(temp_log,3);
        pFVar2 = fopen(temp_log,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s:  Air out temprature is too high, set fixed full fan speed\n",
                  "temperature.c",0x332,"set_pwm_by_temp");
        }
        fclose(pFVar2);
      }
    }
    else if (((config_parameter._4_1_ & 2) == 0) || (100 < config_parameter.fan_pwm_percent)) {
      _Var1 = is_S15();
      if (_Var1) {
        set_pwm_by_airin_temp(dev->temp_low1[0]);
      }
      else {
        _Var1 = is_T15();
        if (_Var1) {
          set_pwm_by_pid_method();
        }
        else {
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d:%s: Miner type is ERROR! PWM running in full speed! \n",
                      "temperature.c",0x343,"set_pwm_by_temp");
            }
            fclose(pFVar2);
          }
          set_pwm('d');
        }
      }
    }
    else {
      set_pwm(config_parameter.fan_pwm_percent);
      if (3 < log_level) {
        print_crt_time_to_file(temp_log,3);
        pFVar2 = fopen(temp_log,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: fan_etf: Set fixed fan speed=%d\n","temperature.c",0x339,
                  "set_pwm_by_temp",(uint)config_parameter.fan_pwm_percent);
        }
        fclose(pFVar2);
      }
    }
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar2 = fopen(temp_log,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: FAN PWM: %d\n","temperature.c",0x349,"set_pwm_by_temp",
                (uint)dev->fan_pwm);
      }
      fclose(pFVar2);
    }
  }
  return;
}

