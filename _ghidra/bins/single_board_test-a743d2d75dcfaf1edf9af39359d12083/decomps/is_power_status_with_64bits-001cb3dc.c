
/* WARNING: Unknown calling convention */

_Bool is_power_status_with_64bits(void)

{
  return _g_power_state.power_version == 0xc1;
}

