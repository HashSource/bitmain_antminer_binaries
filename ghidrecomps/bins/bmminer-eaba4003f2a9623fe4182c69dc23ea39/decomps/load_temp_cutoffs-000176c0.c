
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void load_temp_cutoffs(void)

{
  char tmp42 [2048];
  char *nextptr;
  int device;
  int val;
  int i;
  
  val = 0;
  if (temp_cutoff_str == (char *)0x0) {
    _rd_lock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x523);
    for (i = 0; i < total_devices; i = i + 1) {
      if (devices[i]->cutofftemp == 0) {
        devices[i]->cutofftemp = opt_cutofftemp;
      }
    }
    _rd_unlock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x52c);
  }
  else {
    device = 0;
    nextptr = strtok(temp_cutoff_str,",");
    while (nextptr != (char *)0x0) {
      if (total_devices <= device) {
        tmp42[0] = s_Too_many_values_passed_to_set_te_000715b4[0];
        tmp42[1] = s_Too_many_values_passed_to_set_te_000715b4[1];
        tmp42[2] = s_Too_many_values_passed_to_set_te_000715b4[2];
        tmp42[3] = s_Too_many_values_passed_to_set_te_000715b4[3];
        tmp42[4] = s_Too_many_values_passed_to_set_te_000715b4[4];
        tmp42[5] = s_Too_many_values_passed_to_set_te_000715b4[5];
        tmp42[6] = s_Too_many_values_passed_to_set_te_000715b4[6];
        tmp42[7] = s_Too_many_values_passed_to_set_te_000715b4[7];
        tmp42[8] = s_Too_many_values_passed_to_set_te_000715b4[8];
        tmp42[9] = s_Too_many_values_passed_to_set_te_000715b4[9];
        tmp42[10] = s_Too_many_values_passed_to_set_te_000715b4[10];
        tmp42[11] = s_Too_many_values_passed_to_set_te_000715b4[11];
        tmp42[12] = s_Too_many_values_passed_to_set_te_000715b4[12];
        tmp42[13] = s_Too_many_values_passed_to_set_te_000715b4[13];
        tmp42[14] = s_Too_many_values_passed_to_set_te_000715b4[14];
        tmp42[15] = s_Too_many_values_passed_to_set_te_000715b4[15];
        tmp42[16] = s_Too_many_values_passed_to_set_te_000715b4[16];
        tmp42[17] = s_Too_many_values_passed_to_set_te_000715b4[17];
        tmp42[18] = s_Too_many_values_passed_to_set_te_000715b4[18];
        tmp42[19] = s_Too_many_values_passed_to_set_te_000715b4[19];
        tmp42[20] = s_Too_many_values_passed_to_set_te_000715b4[20];
        tmp42[21] = s_Too_many_values_passed_to_set_te_000715b4[21];
        tmp42[22] = s_Too_many_values_passed_to_set_te_000715b4[22];
        tmp42[23] = s_Too_many_values_passed_to_set_te_000715b4[23];
        tmp42[24] = s_Too_many_values_passed_to_set_te_000715b4[24];
        tmp42[25] = s_Too_many_values_passed_to_set_te_000715b4[25];
        tmp42[26] = s_Too_many_values_passed_to_set_te_000715b4[26];
        tmp42[27] = s_Too_many_values_passed_to_set_te_000715b4[27];
        tmp42[28] = s_Too_many_values_passed_to_set_te_000715b4[28];
        tmp42[29] = s_Too_many_values_passed_to_set_te_000715b4[29];
        tmp42[30] = s_Too_many_values_passed_to_set_te_000715b4[30];
        tmp42[31] = s_Too_many_values_passed_to_set_te_000715b4[31];
        tmp42[32] = s_Too_many_values_passed_to_set_te_000715b4[32];
        tmp42[33] = s_Too_many_values_passed_to_set_te_000715b4[33];
        tmp42[34] = s_Too_many_values_passed_to_set_te_000715b4[34];
        tmp42[35] = s_Too_many_values_passed_to_set_te_000715b4[35];
        tmp42[36] = s_Too_many_values_passed_to_set_te_000715b4[36];
        tmp42[37] = s_Too_many_values_passed_to_set_te_000715b4[37];
        tmp42[38] = s_Too_many_values_passed_to_set_te_000715b4[38];
        tmp42[39] = s_Too_many_values_passed_to_set_te_000715b4[39];
        tmp42._40_2_ = (undefined2)ram0x000715dc;
        _applog(3,tmp42,true);
        _quit(1);
      }
      val = atoi(nextptr);
      if ((val < 0) || (200 < val)) {
        tmp42[0] = s_Invalid_value_passed_to_set_temp_00071588[0];
        tmp42[1] = s_Invalid_value_passed_to_set_temp_00071588[1];
        tmp42[2] = s_Invalid_value_passed_to_set_temp_00071588[2];
        tmp42[3] = s_Invalid_value_passed_to_set_temp_00071588[3];
        tmp42[4] = s_Invalid_value_passed_to_set_temp_00071588[4];
        tmp42[5] = s_Invalid_value_passed_to_set_temp_00071588[5];
        tmp42[6] = s_Invalid_value_passed_to_set_temp_00071588[6];
        tmp42[7] = s_Invalid_value_passed_to_set_temp_00071588[7];
        tmp42[8] = s_Invalid_value_passed_to_set_temp_00071588[8];
        tmp42[9] = s_Invalid_value_passed_to_set_temp_00071588[9];
        tmp42[10] = s_Invalid_value_passed_to_set_temp_00071588[10];
        tmp42[11] = s_Invalid_value_passed_to_set_temp_00071588[11];
        tmp42[12] = s_Invalid_value_passed_to_set_temp_00071588[12];
        tmp42[13] = s_Invalid_value_passed_to_set_temp_00071588[13];
        tmp42[14] = s_Invalid_value_passed_to_set_temp_00071588[14];
        tmp42[15] = s_Invalid_value_passed_to_set_temp_00071588[15];
        tmp42[16] = s_Invalid_value_passed_to_set_temp_00071588[16];
        tmp42[17] = s_Invalid_value_passed_to_set_temp_00071588[17];
        tmp42[18] = s_Invalid_value_passed_to_set_temp_00071588[18];
        tmp42[19] = s_Invalid_value_passed_to_set_temp_00071588[19];
        tmp42[20] = s_Invalid_value_passed_to_set_temp_00071588[20];
        tmp42[21] = s_Invalid_value_passed_to_set_temp_00071588[21];
        tmp42[22] = s_Invalid_value_passed_to_set_temp_00071588[22];
        tmp42[23] = s_Invalid_value_passed_to_set_temp_00071588[23];
        tmp42[24] = s_Invalid_value_passed_to_set_temp_00071588[24];
        tmp42[25] = s_Invalid_value_passed_to_set_temp_00071588[25];
        tmp42[26] = s_Invalid_value_passed_to_set_temp_00071588[26];
        tmp42[27] = s_Invalid_value_passed_to_set_temp_00071588[27];
        tmp42[28] = s_Invalid_value_passed_to_set_temp_00071588[28];
        tmp42[29] = s_Invalid_value_passed_to_set_temp_00071588[29];
        tmp42[30] = s_Invalid_value_passed_to_set_temp_00071588[30];
        tmp42[31] = s_Invalid_value_passed_to_set_temp_00071588[31];
        tmp42[32] = s_Invalid_value_passed_to_set_temp_00071588[32];
        tmp42[33] = s_Invalid_value_passed_to_set_temp_00071588[33];
        tmp42[34] = s_Invalid_value_passed_to_set_temp_00071588[34];
        tmp42[35] = s_Invalid_value_passed_to_set_temp_00071588[35];
        tmp42[36] = s_Invalid_value_passed_to_set_temp_00071588[36];
        tmp42[37] = s_Invalid_value_passed_to_set_temp_00071588[37];
        tmp42[38] = s_Invalid_value_passed_to_set_temp_00071588[38];
        tmp42[39] = s_Invalid_value_passed_to_set_temp_00071588[39];
        _applog(3,tmp42,true);
        _quit(1);
      }
      _rd_lock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x51c);
      devices[device]->cutofftemp = val;
      _rd_unlock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x51e);
      device = device + 1;
      nextptr = strtok((char *)0x0,",");
    }
    if (device < 2) {
      _rd_lock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x533);
      for (i = device; i < total_devices; i = i + 1) {
        devices[i]->cutofftemp = val;
      }
      _rd_unlock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x539);
    }
  }
  return;
}

