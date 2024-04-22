
int set_pwm_by_airin_temp(int air_in_lowest_temp)

{
  _Bool _Var1;
  FILE *__stream;
  int air_in_lowest_temp_local;
  FILE *pFile;
  float rate;
  float rate_1;
  int i;
  fan_speed_temp_args_t *pfan_speed_temp_arg;
  int pwm_percent;
  
  pwm_percent = (int)dev->fan_pwm;
  if (opt_bitmain_economic_mode) {
    _Var1 = is_S15();
    if (_Var1) {
      pfan_speed_temp_arg = fan_speed_temp_arg[0];
    }
    else {
      _Var1 = is_T15();
      if (_Var1) {
        pfan_speed_temp_arg = DAT_0001ea58;
      }
    }
  }
  else {
    _Var1 = is_S15();
    if (_Var1) {
      pfan_speed_temp_arg = DAT_0001ea5c;
    }
    else {
      _Var1 = is_T15();
      if (_Var1) {
        pfan_speed_temp_arg = DAT_0001ea60;
      }
    }
  }
  if (pfan_speed_temp_arg->temp < air_in_lowest_temp) {
    for (i = 0; i < 5; i = i + 1) {
      if (pfan_speed_temp_arg[i + 1].temp == 100) {
        pwm_percent = (int)((float)(longlong)(air_in_lowest_temp - pfan_speed_temp_arg[i].temp) *
                            ((float)(longlong)
                                    (pfan_speed_temp_arg[i].fan_speed -
                                    pfan_speed_temp_arg[i + 0x1fffffff].fan_speed) /
                            (float)(longlong)
                                   (pfan_speed_temp_arg[i].temp -
                                   pfan_speed_temp_arg[i + 0x1fffffff].temp)) +
                           (float)(longlong)pfan_speed_temp_arg[i].fan_speed);
        break;
      }
      if ((pfan_speed_temp_arg[i].temp < air_in_lowest_temp) &&
         (air_in_lowest_temp <= pfan_speed_temp_arg[i + 1].temp)) {
        pwm_percent = (int)((float)(longlong)(air_in_lowest_temp - pfan_speed_temp_arg[i].temp) *
                            ((float)(longlong)
                                    (pfan_speed_temp_arg[i + 1].fan_speed -
                                    pfan_speed_temp_arg[i].fan_speed) /
                            (float)(longlong)
                                   (pfan_speed_temp_arg[i + 1].temp - pfan_speed_temp_arg[i].temp))
                           + (float)(longlong)pfan_speed_temp_arg[i].fan_speed);
        break;
      }
    }
  }
  else {
    pwm_percent = pfan_speed_temp_arg->fan_speed;
  }
  if (pwm_percent < 0x14) {
    pwm_percent = 0x14;
  }
  if (100 < pwm_percent) {
    pwm_percent = 100;
  }
  dev->fan_pwm = (uchar)pwm_percent;
  if (3 < log_level) {
    print_crt_time_to_file(temp_log,3);
    __stream = fopen(temp_log,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: air_in_lowest_temp=%d, set fan speed=%d\n","temperature.c",0x21b,
              "set_pwm_by_airin_temp",air_in_lowest_temp,pwm_percent);
    }
    fclose(__stream);
  }
  set_pwm((uchar)pwm_percent);
  return pwm_percent;
}

