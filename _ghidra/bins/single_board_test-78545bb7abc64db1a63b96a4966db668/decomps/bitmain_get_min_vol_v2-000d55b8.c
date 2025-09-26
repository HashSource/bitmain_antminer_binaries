
/* WARNING: Unknown calling convention */

double bitmain_get_min_vol_v2(void)

{
  switch(_g_power_state.power_version) {
  case 0x62:
  case 100:
  case 0x65:
  case 0x66:
    return 17.0;
  default:
    return -1.0;
  case 0x6a:
    return 12.0;
  }
}

