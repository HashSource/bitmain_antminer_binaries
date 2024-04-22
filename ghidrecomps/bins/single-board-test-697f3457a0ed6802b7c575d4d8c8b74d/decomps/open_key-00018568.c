
/* WARNING: Unknown calling convention */

int open_key(void)

{
  char tmp42 [1024];
  
  cgpu.key_fd = open("/sys/class/gpio/gpio943/value",0x800);
  if ((cgpu.key_fd < 0) &&
     (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    tmp42[0] = s_open_key_failed____00034ed4[0];
    tmp42[1] = s_open_key_failed____00034ed4[1];
    tmp42[2] = s_open_key_failed____00034ed4[2];
    tmp42[3] = s_open_key_failed____00034ed4[3];
    tmp42[4] = s_open_key_failed____00034ed4[4];
    tmp42[5] = s_open_key_failed____00034ed4[5];
    tmp42[6] = s_open_key_failed____00034ed4[6];
    tmp42[7] = s_open_key_failed____00034ed4[7];
    tmp42[8] = s_open_key_failed____00034ed4[8];
    tmp42[9] = s_open_key_failed____00034ed4[9];
    tmp42[10] = s_open_key_failed____00034ed4[10];
    tmp42[11] = s_open_key_failed____00034ed4[11];
    tmp42[12] = s_open_key_failed____00034ed4[12];
    tmp42[13] = s_open_key_failed____00034ed4[13];
    tmp42[14] = s_open_key_failed____00034ed4[14];
    tmp42[15] = s_open_key_failed____00034ed4[15];
    tmp42[16] = s_open_key_failed____00034ed4[16];
    tmp42[17] = s_open_key_failed____00034ed4[17];
    tmp42[18] = s_open_key_failed____00034ed4[18];
    tmp42[19] = s_open_key_failed____00034ed4[19];
    _applog(2,tmp42,false);
  }
  return cgpu.key_fd;
}

