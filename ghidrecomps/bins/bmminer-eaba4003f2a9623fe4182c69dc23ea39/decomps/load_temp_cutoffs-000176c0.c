
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void load_temp_cutoffs(void)

{
  char tmp42 [2048];
  char *nextptr;
  int device;
  int val;
  int i;
  
  val = 0;
  if (temp_cutoff_str == (char *)0x0) {
    _rd_lock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x523);
    for (i = 0; i < total_devices; i = i + 1) {
      if (devices[i]->cutofftemp == 0) {
        devices[i]->cutofftemp = 0x5f;
      }
    }
    _rd_unlock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x52c);
  }
  else {
    device = 0;
    nextptr = strtok(temp_cutoff_str,",");
    while (nextptr != (char *)0x0) {
      if (total_devices <= device) {
        builtin_strncpy(tmp42,"Too many values passed to set temp cutof",0x28);
        tmp42[0x28] = 'f';
        tmp42[0x29] = '\0';
        _applog(3,tmp42,true);
        _quit(1);
      }
      val = atoi(nextptr);
      if ((val < 0) || (200 < val)) {
        builtin_strncpy(tmp42,"Invalid value passed to set temp cutoff",0x28);
        _applog(3,tmp42,true);
        _quit(1);
      }
      _rd_lock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x51c);
      devices[device]->cutofftemp = val;
      _rd_unlock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x51e);
      device = device + 1;
      nextptr = strtok((char *)0x0,",");
    }
    if (device < 2) {
      _rd_lock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x533);
      for (i = device; i < total_devices; i = i + 1) {
        devices[i]->cutofftemp = val;
      }
      _rd_unlock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x539);
    }
  }
  return;
}

