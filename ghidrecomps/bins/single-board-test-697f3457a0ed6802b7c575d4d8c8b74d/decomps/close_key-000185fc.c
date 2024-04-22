
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void close_key(void)

{
  char tmp42 [1024];
  
  close(cgpu.key_fd);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    tmp42[0] = s_key_closed____00034ee8[0];
    tmp42[1] = s_key_closed____00034ee8[1];
    tmp42[2] = s_key_closed____00034ee8[2];
    tmp42[3] = s_key_closed____00034ee8[3];
    tmp42[4] = s_key_closed____00034ee8[4];
    tmp42[5] = s_key_closed____00034ee8[5];
    tmp42[6] = s_key_closed____00034ee8[6];
    tmp42[7] = s_key_closed____00034ee8[7];
    tmp42[8] = s_key_closed____00034ee8[8];
    tmp42[9] = s_key_closed____00034ee8[9];
    tmp42[10] = s_key_closed____00034ee8[10];
    tmp42[11] = s_key_closed____00034ee8[11];
    tmp42._12_2_ = (undefined2)ram0x00034ef4;
    tmp42[14] = (char)((uint)ram0x00034ef4 >> 0x10);
    _applog(2,tmp42,false);
  }
  return;
}

