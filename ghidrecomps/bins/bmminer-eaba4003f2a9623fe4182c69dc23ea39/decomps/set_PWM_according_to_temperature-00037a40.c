
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void set_PWM_according_to_temperature(void)

{
  char tmp42 [2048];
  char logstr [1024];
  int temp_change;
  int pwm_percent;
  
  if ((is218_Temp) || (chip_hasNoMiddle)) {
    temp_highest = dev->temp_top1[0];
  }
  else {
    temp_highest = dev->temp_top1[0];
  }
  if ((temp_highest < 0x4b) && (temp_highest != 0)) {
    if ((1 < temp_highest - last_temperature) || (temp_highest - last_temperature < -1)) {
      if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
        tmp42._0_4_ = s_set_normal_FAN_speed____00076b64._0_4_;
        tmp42._4_4_ = s_set_normal_FAN_speed____00076b64._4_4_;
        tmp42._8_4_ = s_set_normal_FAN_speed____00076b64._8_4_;
        tmp42._12_4_ = s_set_normal_FAN_speed____00076b64._12_4_;
        tmp42._16_4_ = s_set_normal_FAN_speed____00076b64._16_4_;
        tmp42._20_4_ = s_set_normal_FAN_speed____00076b64._20_4_;
        tmp42[24] = (char)ram0x00076b7c;
        _applog(5,tmp42,false);
      }
      pwm_percent = (temp_highest + -0x19) * 2;
      if (pwm_percent < 0x14) {
        pwm_percent = 0x14;
      }
      if (100 < pwm_percent) {
        pwm_percent = 100;
      }
      dev->fan_pwm = (uchar)pwm_percent;
      last_temperature = temp_highest;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"%s: Set PWM percent : %d\n","set_PWM_according_to_temperature",
                 pwm_percent);
        _applog(5,tmp42,false);
      }
      set_PWM((uchar)pwm_percent);
    }
  }
  else {
    set_PWM('d');
    dev->fan_pwm = 'd';
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      tmp42[0] = s_set_full_FAN_speed____00076b4c[0];
      tmp42[1] = s_set_full_FAN_speed____00076b4c[1];
      tmp42[2] = s_set_full_FAN_speed____00076b4c[2];
      tmp42[3] = s_set_full_FAN_speed____00076b4c[3];
      tmp42[4] = s_set_full_FAN_speed____00076b4c[4];
      tmp42[5] = s_set_full_FAN_speed____00076b4c[5];
      tmp42[6] = s_set_full_FAN_speed____00076b4c[6];
      tmp42[7] = s_set_full_FAN_speed____00076b4c[7];
      tmp42[8] = s_set_full_FAN_speed____00076b4c[8];
      tmp42[9] = s_set_full_FAN_speed____00076b4c[9];
      tmp42[10] = s_set_full_FAN_speed____00076b4c[10];
      tmp42[11] = s_set_full_FAN_speed____00076b4c[11];
      tmp42[12] = s_set_full_FAN_speed____00076b4c[12];
      tmp42[13] = s_set_full_FAN_speed____00076b4c[13];
      tmp42[14] = s_set_full_FAN_speed____00076b4c[14];
      tmp42[15] = s_set_full_FAN_speed____00076b4c[15];
      tmp42[16] = s_set_full_FAN_speed____00076b4c[16];
      tmp42[17] = s_set_full_FAN_speed____00076b4c[17];
      tmp42[18] = s_set_full_FAN_speed____00076b4c[18];
      tmp42[19] = s_set_full_FAN_speed____00076b4c[19];
      tmp42._20_3_ = (undefined3)ram0x00076b60;
      _applog(5,tmp42,false);
    }
  }
  return;
}

