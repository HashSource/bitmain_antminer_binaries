
/* WARNING: Unknown calling convention */

void get_system_capability(bitmain_sys_capability_t *info)

{
  if (info == (bitmain_sys_capability_t *)0x0) {
    return;
  }
  check_hotplug_realtime(info);
  memcpy(info,&capability,0x124);
  return;
}

