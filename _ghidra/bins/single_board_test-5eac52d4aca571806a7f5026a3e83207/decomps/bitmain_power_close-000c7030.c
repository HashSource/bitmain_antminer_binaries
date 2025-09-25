
/* WARNING: Unknown calling convention */

int32_t bitmain_power_close(void)

{
  if (_g_power_state.power_open != 0) {
    bitmain_power_close();
  }
  return 0;
}

