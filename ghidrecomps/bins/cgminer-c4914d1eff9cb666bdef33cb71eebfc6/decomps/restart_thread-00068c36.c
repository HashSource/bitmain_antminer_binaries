
void * restart_thread(void *userdata)

{
  void *userdata_local;
  char tmp42 [2048];
  
  _mutex_lock(&quit_restart_lock,"api-btm.c","restart_thread",0x134d);
  _mutex_unlock(&quit_restart_lock,"api-btm.c","restart_thread",0x134e);
  if (((opt_debug != false) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    tmp42[0] = s_API__restarting_cgminer_00093c24[0];
    tmp42[1] = s_API__restarting_cgminer_00093c24[1];
    tmp42[2] = s_API__restarting_cgminer_00093c24[2];
    tmp42[3] = s_API__restarting_cgminer_00093c24[3];
    tmp42[4] = s_API__restarting_cgminer_00093c24[4];
    tmp42[5] = s_API__restarting_cgminer_00093c24[5];
    tmp42[6] = s_API__restarting_cgminer_00093c24[6];
    tmp42[7] = s_API__restarting_cgminer_00093c24[7];
    tmp42[8] = s_API__restarting_cgminer_00093c24[8];
    tmp42[9] = s_API__restarting_cgminer_00093c24[9];
    tmp42[10] = s_API__restarting_cgminer_00093c24[10];
    tmp42[11] = s_API__restarting_cgminer_00093c24[11];
    tmp42[12] = s_API__restarting_cgminer_00093c24[12];
    tmp42[13] = s_API__restarting_cgminer_00093c24[13];
    tmp42[14] = s_API__restarting_cgminer_00093c24[14];
    tmp42[15] = s_API__restarting_cgminer_00093c24[15];
    tmp42[16] = s_API__restarting_cgminer_00093c24[16];
    tmp42[17] = s_API__restarting_cgminer_00093c24[17];
    tmp42[18] = s_API__restarting_cgminer_00093c24[18];
    tmp42[19] = s_API__restarting_cgminer_00093c24[19];
    tmp42[20] = s_API__restarting_cgminer_00093c24[20];
    tmp42[21] = s_API__restarting_cgminer_00093c24[21];
    tmp42[22] = s_API__restarting_cgminer_00093c24[22];
    tmp42[23] = s_API__restarting_cgminer_00093c24[23];
    _applog(7,tmp42,false);
  }
  app_restart();
  return (void *)0x0;
}

