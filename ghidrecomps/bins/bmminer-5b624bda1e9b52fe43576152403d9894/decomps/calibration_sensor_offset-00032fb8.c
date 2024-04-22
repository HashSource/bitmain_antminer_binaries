
/* WARNING: Unknown calling convention */

int8_t calibration_sensor_offset(uchar device,int chain)

{
  if (*DAT_00032ff8 < 0xe) {
    if (chain % 3 != 1) {
      return '\0';
    }
  }
  else if (((chain & 0xfffffffdU) != 8) && (chain != 0xc)) {
    return '\0';
  }
  calibration_sensor_offset(device,chain);
  return '\0';
}

