
void * restart_thread(void *userdata)

{
  void *userdata_local;
  char tmp42 [2048];
  
  _mutex_lock(&quit_restart_lock,"api-btm.c","restart_thread",0x134b);
  _mutex_unlock(&quit_restart_lock,"api-btm.c","restart_thread",0x134c);
  if (((opt_debug != false) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    tmp42[0] = s_API__restarting_cgminer_000ae824[0];
    tmp42[1] = s_API__restarting_cgminer_000ae824[1];
    tmp42[2] = s_API__restarting_cgminer_000ae824[2];
    tmp42[3] = s_API__restarting_cgminer_000ae824[3];
    tmp42[4] = s_API__restarting_cgminer_000ae824[4];
    tmp42[5] = s_API__restarting_cgminer_000ae824[5];
    tmp42[6] = s_API__restarting_cgminer_000ae824[6];
    tmp42[7] = s_API__restarting_cgminer_000ae824[7];
    tmp42[8] = s_API__restarting_cgminer_000ae824[8];
    tmp42[9] = s_API__restarting_cgminer_000ae824[9];
    tmp42[10] = s_API__restarting_cgminer_000ae824[10];
    tmp42[11] = s_API__restarting_cgminer_000ae824[11];
    tmp42[12] = s_API__restarting_cgminer_000ae824[12];
    tmp42[13] = s_API__restarting_cgminer_000ae824[13];
    tmp42[14] = s_API__restarting_cgminer_000ae824[14];
    tmp42[15] = s_API__restarting_cgminer_000ae824[15];
    tmp42[16] = s_API__restarting_cgminer_000ae824[16];
    tmp42[17] = s_API__restarting_cgminer_000ae824[17];
    tmp42[18] = s_API__restarting_cgminer_000ae824[18];
    tmp42[19] = s_API__restarting_cgminer_000ae824[19];
    tmp42[20] = s_API__restarting_cgminer_000ae824[20];
    tmp42[21] = s_API__restarting_cgminer_000ae824[21];
    tmp42[22] = s_API__restarting_cgminer_000ae824[22];
    tmp42[23] = s_API__restarting_cgminer_000ae824[23];
    _applog(7,tmp42,false);
  }
  app_restart();
  return (void *)0x0;
}

