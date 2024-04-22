
int16_t get_remote(int16_t remote)

{
  double dVar1;
  int16_t remote_local;
  char tmp42 [2048];
  float t_re_re;
  
  dVar1 = ((double)(longlong)(int)(short)(remote + -0x40) * DAT_0003cfd8 - DAT_0003cfe0) /
          DAT_0003cfe8;
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"remote : %d temp : %f",(int)(short)(remote + -0x40),(double)(float)dVar1);
    _applog(7,tmp42,false);
  }
  return (int16_t)(int)dVar1;
}

