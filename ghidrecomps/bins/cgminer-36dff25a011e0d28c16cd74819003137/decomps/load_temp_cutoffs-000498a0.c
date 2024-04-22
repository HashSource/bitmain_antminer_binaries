
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
    _rd_lock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x529);
    for (i = 0; i < total_devices; i = i + 1) {
      if (devices[i]->cutofftemp == 0) {
        devices[i]->cutofftemp = 0x5f;
      }
    }
    _rd_unlock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x532);
  }
  else {
    device = 0;
    nextptr = strtok(temp_cutoff_str,",");
    while (nextptr != (char *)0x0) {
      if (total_devices <= device) {
        tmp42[0] = s_Too_many_values_passed_to_set_te_000a2078[0];
        tmp42[1] = s_Too_many_values_passed_to_set_te_000a2078[1];
        tmp42[2] = s_Too_many_values_passed_to_set_te_000a2078[2];
        tmp42[3] = s_Too_many_values_passed_to_set_te_000a2078[3];
        tmp42[4] = s_Too_many_values_passed_to_set_te_000a2078[4];
        tmp42[5] = s_Too_many_values_passed_to_set_te_000a2078[5];
        tmp42[6] = s_Too_many_values_passed_to_set_te_000a2078[6];
        tmp42[7] = s_Too_many_values_passed_to_set_te_000a2078[7];
        tmp42[8] = s_Too_many_values_passed_to_set_te_000a2078[8];
        tmp42[9] = s_Too_many_values_passed_to_set_te_000a2078[9];
        tmp42[10] = s_Too_many_values_passed_to_set_te_000a2078[10];
        tmp42[11] = s_Too_many_values_passed_to_set_te_000a2078[11];
        tmp42[12] = s_Too_many_values_passed_to_set_te_000a2078[12];
        tmp42[13] = s_Too_many_values_passed_to_set_te_000a2078[13];
        tmp42[14] = s_Too_many_values_passed_to_set_te_000a2078[14];
        tmp42[15] = s_Too_many_values_passed_to_set_te_000a2078[15];
        tmp42[16] = s_Too_many_values_passed_to_set_te_000a2078[16];
        tmp42[17] = s_Too_many_values_passed_to_set_te_000a2078[17];
        tmp42[18] = s_Too_many_values_passed_to_set_te_000a2078[18];
        tmp42[19] = s_Too_many_values_passed_to_set_te_000a2078[19];
        tmp42[20] = s_Too_many_values_passed_to_set_te_000a2078[20];
        tmp42[21] = s_Too_many_values_passed_to_set_te_000a2078[21];
        tmp42[22] = s_Too_many_values_passed_to_set_te_000a2078[22];
        tmp42[23] = s_Too_many_values_passed_to_set_te_000a2078[23];
        tmp42[24] = s_Too_many_values_passed_to_set_te_000a2078[24];
        tmp42[25] = s_Too_many_values_passed_to_set_te_000a2078[25];
        tmp42[26] = s_Too_many_values_passed_to_set_te_000a2078[26];
        tmp42[27] = s_Too_many_values_passed_to_set_te_000a2078[27];
        tmp42[28] = s_Too_many_values_passed_to_set_te_000a2078[28];
        tmp42[29] = s_Too_many_values_passed_to_set_te_000a2078[29];
        tmp42[30] = s_Too_many_values_passed_to_set_te_000a2078[30];
        tmp42[31] = s_Too_many_values_passed_to_set_te_000a2078[31];
        tmp42[32] = s_Too_many_values_passed_to_set_te_000a2078[32];
        tmp42[33] = s_Too_many_values_passed_to_set_te_000a2078[33];
        tmp42[34] = s_Too_many_values_passed_to_set_te_000a2078[34];
        tmp42[35] = s_Too_many_values_passed_to_set_te_000a2078[35];
        tmp42[36] = s_Too_many_values_passed_to_set_te_000a2078[36];
        tmp42[37] = s_Too_many_values_passed_to_set_te_000a2078[37];
        tmp42[38] = s_Too_many_values_passed_to_set_te_000a2078[38];
        tmp42[39] = s_Too_many_values_passed_to_set_te_000a2078[39];
        tmp42._40_2_ = (undefined2)ram0x000a20a0;
        _applog(3,tmp42,true);
        _quit(1);
      }
      val = atoi(nextptr);
      if ((val < 0) || (200 < val)) {
        tmp42[0] = s_Invalid_value_passed_to_set_temp_000a204c[0];
        tmp42[1] = s_Invalid_value_passed_to_set_temp_000a204c[1];
        tmp42[2] = s_Invalid_value_passed_to_set_temp_000a204c[2];
        tmp42[3] = s_Invalid_value_passed_to_set_temp_000a204c[3];
        tmp42[4] = s_Invalid_value_passed_to_set_temp_000a204c[4];
        tmp42[5] = s_Invalid_value_passed_to_set_temp_000a204c[5];
        tmp42[6] = s_Invalid_value_passed_to_set_temp_000a204c[6];
        tmp42[7] = s_Invalid_value_passed_to_set_temp_000a204c[7];
        tmp42[8] = s_Invalid_value_passed_to_set_temp_000a204c[8];
        tmp42[9] = s_Invalid_value_passed_to_set_temp_000a204c[9];
        tmp42[10] = s_Invalid_value_passed_to_set_temp_000a204c[10];
        tmp42[11] = s_Invalid_value_passed_to_set_temp_000a204c[11];
        tmp42[12] = s_Invalid_value_passed_to_set_temp_000a204c[12];
        tmp42[13] = s_Invalid_value_passed_to_set_temp_000a204c[13];
        tmp42[14] = s_Invalid_value_passed_to_set_temp_000a204c[14];
        tmp42[15] = s_Invalid_value_passed_to_set_temp_000a204c[15];
        tmp42[16] = s_Invalid_value_passed_to_set_temp_000a204c[16];
        tmp42[17] = s_Invalid_value_passed_to_set_temp_000a204c[17];
        tmp42[18] = s_Invalid_value_passed_to_set_temp_000a204c[18];
        tmp42[19] = s_Invalid_value_passed_to_set_temp_000a204c[19];
        tmp42[20] = s_Invalid_value_passed_to_set_temp_000a204c[20];
        tmp42[21] = s_Invalid_value_passed_to_set_temp_000a204c[21];
        tmp42[22] = s_Invalid_value_passed_to_set_temp_000a204c[22];
        tmp42[23] = s_Invalid_value_passed_to_set_temp_000a204c[23];
        tmp42[24] = s_Invalid_value_passed_to_set_temp_000a204c[24];
        tmp42[25] = s_Invalid_value_passed_to_set_temp_000a204c[25];
        tmp42[26] = s_Invalid_value_passed_to_set_temp_000a204c[26];
        tmp42[27] = s_Invalid_value_passed_to_set_temp_000a204c[27];
        tmp42[28] = s_Invalid_value_passed_to_set_temp_000a204c[28];
        tmp42[29] = s_Invalid_value_passed_to_set_temp_000a204c[29];
        tmp42[30] = s_Invalid_value_passed_to_set_temp_000a204c[30];
        tmp42[31] = s_Invalid_value_passed_to_set_temp_000a204c[31];
        tmp42[32] = s_Invalid_value_passed_to_set_temp_000a204c[32];
        tmp42[33] = s_Invalid_value_passed_to_set_temp_000a204c[33];
        tmp42[34] = s_Invalid_value_passed_to_set_temp_000a204c[34];
        tmp42[35] = s_Invalid_value_passed_to_set_temp_000a204c[35];
        tmp42[36] = s_Invalid_value_passed_to_set_temp_000a204c[36];
        tmp42[37] = s_Invalid_value_passed_to_set_temp_000a204c[37];
        tmp42[38] = s_Invalid_value_passed_to_set_temp_000a204c[38];
        tmp42[39] = s_Invalid_value_passed_to_set_temp_000a204c[39];
        _applog(3,tmp42,true);
        _quit(1);
      }
      _rd_lock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x522);
      devices[device]->cutofftemp = val;
      _rd_unlock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x524);
      device = device + 1;
      nextptr = strtok((char *)0x0,",");
    }
    if (device < 2) {
      _rd_lock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x539);
      for (i = device; i < total_devices; i = i + 1) {
        devices[i]->cutofftemp = val;
      }
      _rd_unlock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x53f);
    }
  }
  return;
}

