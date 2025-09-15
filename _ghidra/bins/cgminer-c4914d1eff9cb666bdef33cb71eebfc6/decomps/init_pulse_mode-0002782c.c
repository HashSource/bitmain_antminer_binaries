
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void init_pulse_mode(void)

{
  if ((g_device_minor_type == PKG_BSL) || (g_device_minor_type == PKG_B_BGM)) {
    g_pulse_mode = '\0';
  }
  else {
    g_pulse_mode = '\x01';
  }
  return;
}

