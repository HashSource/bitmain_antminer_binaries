
cgpu_info * get_devices(int id)

{
  cgpu_info *pcVar1;
  int id_local;
  cgpu_info *cgpu;
  
  _rd_lock(&devices_lock,"cgminer.c","get_devices",0x260);
  pcVar1 = devices[id];
  _rd_unlock(&devices_lock,"cgminer.c","get_devices",0x262);
  return pcVar1;
}

