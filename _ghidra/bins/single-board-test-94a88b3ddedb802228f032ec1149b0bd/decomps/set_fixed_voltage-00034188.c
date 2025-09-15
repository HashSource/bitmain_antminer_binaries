
void set_fixed_voltage(void)

{
  FILE *__stream;
  undefined8 in_d0;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  local_20 = (undefined4)in_d0;
  uStack_1c = (undefined4)((ulonglong)in_d0 >> 0x20);
  DAT_003b0f50._0_4_ = local_20;
  DAT_003b0f50._4_4_ = uStack_1c;
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: s9_84_fixed_voltage = %f\n","power.c",0xef,(undefined4)DAT_003b0f50,
              DAT_003b0f50._4_4_);
    }
    fclose(__stream);
  }
  return;
}

