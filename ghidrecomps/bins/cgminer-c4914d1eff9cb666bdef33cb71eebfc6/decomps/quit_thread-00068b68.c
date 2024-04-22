
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * quit_thread(void *userdata)

{
  void *userdata_local;
  char tmp42 [2048];
  
  _mutex_lock(&quit_restart_lock,"api-btm.c","quit_thread",0x133f);
  _mutex_unlock(&quit_restart_lock,"api-btm.c","quit_thread",0x1340);
  if (((opt_debug != false) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    tmp42[0] = s_API__killing_cgminer_00093c0c[0];
    tmp42[1] = s_API__killing_cgminer_00093c0c[1];
    tmp42[2] = s_API__killing_cgminer_00093c0c[2];
    tmp42[3] = s_API__killing_cgminer_00093c0c[3];
    tmp42[4] = s_API__killing_cgminer_00093c0c[4];
    tmp42[5] = s_API__killing_cgminer_00093c0c[5];
    tmp42[6] = s_API__killing_cgminer_00093c0c[6];
    tmp42[7] = s_API__killing_cgminer_00093c0c[7];
    tmp42[8] = s_API__killing_cgminer_00093c0c[8];
    tmp42[9] = s_API__killing_cgminer_00093c0c[9];
    tmp42[10] = s_API__killing_cgminer_00093c0c[10];
    tmp42[11] = s_API__killing_cgminer_00093c0c[11];
    tmp42[12] = s_API__killing_cgminer_00093c0c[12];
    tmp42[13] = s_API__killing_cgminer_00093c0c[13];
    tmp42[14] = s_API__killing_cgminer_00093c0c[14];
    tmp42[15] = s_API__killing_cgminer_00093c0c[15];
    tmp42[16] = s_API__killing_cgminer_00093c0c[16];
    tmp42[17] = s_API__killing_cgminer_00093c0c[17];
    tmp42[18] = s_API__killing_cgminer_00093c0c[18];
    tmp42[19] = s_API__killing_cgminer_00093c0c[19];
    tmp42[20] = (char)ram0x00093c20;
    _applog(7,tmp42,false);
  }
  kill_work();
  return (void *)0x0;
}

