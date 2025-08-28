
byte get_power_iic_value_from_voltage(int *param_1)

{
  FILE *__stream;
  double in_d0;
  double dVar1;
  byte local_30;
  double local_28;
  byte local_19;
  double local_18;
  
  if (*param_1 == 2) {
    local_18 = 1925.735 - in_d0 * 171.875;
    if (255.0 < local_18) {
      local_18 = 255.0;
    }
    if ((int)((uint)(local_18 < 0.0) << 0x1f) < 0) {
      local_18 = 0.0;
    }
    local_30 = (0.0 < local_18) * (char)(longlong)local_18;
    local_19 = local_30;
    local_28 = in_d0;
  }
  else {
    local_28 = in_d0 * 100.0;
    dVar1 = (local_28 * 11128.32 - 6233779.2) / (243507.0 - local_28 * 180.9);
    local_30 = (0.0 < dVar1) * (char)(longlong)dVar1;
    local_19 = local_30;
    if ((char)local_30 < '\0') {
      local_19 = 0x7f;
    }
  }
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: iic_index for voltage[%d] = %d\n","power.c",0x15e,(uint)local_19,
              (int)(longlong)local_28);
    }
    fclose(__stream);
  }
  return local_19;
}

