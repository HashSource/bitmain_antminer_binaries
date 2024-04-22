
undefined4 set_iic_power_to_higher_voltage(void)

{
  char cVar1;
  int iVar2;
  FILE *__stream;
  double dVar3;
  bool local_19;
  undefined8 local_18;
  
  local_18 = DAT_003b0f50 + DAT_00035468;
  iVar2 = is7007_Board();
  if (iVar2 != 0) {
    local_18 = DAT_003b0f50 + DAT_00035470;
  }
  local_19 = (int)((uint)((double)CONCAT44(DAT_003b0f58._4_4_,(undefined4)DAT_003b0f58) < local_18)
                  << 0x1f) < 0;
  if (local_19) {
    local_18 = (double)CONCAT44(DAT_003b0f58._4_4_,(undefined4)DAT_003b0f58);
  }
  local_19 = !local_19;
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: setting to voltage %f...\n","power.c",700,(undefined4)local_18,
              local_18._4_4_);
    }
    fclose(__stream);
  }
  cVar1 = set_iic_power_voltage((undefined4)local_18,&power_info,local_19);
  if (cVar1 != '\x01') {
    dVar3 = (double)get_avg_voltage();
    if ((int)((uint)(dVar3 < DAT_00035478) << 0x1f) < 0) {
      stop_mining("power voltage too low\n");
    }
  }
  return 1;
}

