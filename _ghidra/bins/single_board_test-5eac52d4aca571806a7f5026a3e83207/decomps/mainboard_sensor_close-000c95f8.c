
/* WARNING: Unknown calling convention */

int32_t mainboard_sensor_close(void)

{
  int32_t extraout_r0;
  int32_t iVar1;
  
  iVar1 = g_sensor_fd;
  if (g_sensor_fd != 0) {
    iic_uninit(g_sensor_fd);
    g_sensor_fd = 0;
    iVar1 = extraout_r0;
  }
  return iVar1;
}

