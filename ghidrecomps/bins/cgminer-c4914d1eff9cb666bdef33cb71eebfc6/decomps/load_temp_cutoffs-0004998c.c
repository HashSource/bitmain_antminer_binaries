
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
    _rd_lock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x52a);
    for (i = 0; i < total_devices; i = i + 1) {
      if (devices[i]->cutofftemp == 0) {
        devices[i]->cutofftemp = 0x5f;
      }
    }
    _rd_unlock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x533);
  }
  else {
    device = 0;
    nextptr = strtok(temp_cutoff_str,",");
    while (nextptr != (char *)0x0) {
      if (total_devices <= device) {
        tmp42[0] = s_Too_many_values_passed_to_set_te_0008accc[0];
        tmp42[1] = s_Too_many_values_passed_to_set_te_0008accc[1];
        tmp42[2] = s_Too_many_values_passed_to_set_te_0008accc[2];
        tmp42[3] = s_Too_many_values_passed_to_set_te_0008accc[3];
        tmp42[4] = s_Too_many_values_passed_to_set_te_0008accc[4];
        tmp42[5] = s_Too_many_values_passed_to_set_te_0008accc[5];
        tmp42[6] = s_Too_many_values_passed_to_set_te_0008accc[6];
        tmp42[7] = s_Too_many_values_passed_to_set_te_0008accc[7];
        tmp42[8] = s_Too_many_values_passed_to_set_te_0008accc[8];
        tmp42[9] = s_Too_many_values_passed_to_set_te_0008accc[9];
        tmp42[10] = s_Too_many_values_passed_to_set_te_0008accc[10];
        tmp42[11] = s_Too_many_values_passed_to_set_te_0008accc[11];
        tmp42[12] = s_Too_many_values_passed_to_set_te_0008accc[12];
        tmp42[13] = s_Too_many_values_passed_to_set_te_0008accc[13];
        tmp42[14] = s_Too_many_values_passed_to_set_te_0008accc[14];
        tmp42[15] = s_Too_many_values_passed_to_set_te_0008accc[15];
        tmp42[16] = s_Too_many_values_passed_to_set_te_0008accc[16];
        tmp42[17] = s_Too_many_values_passed_to_set_te_0008accc[17];
        tmp42[18] = s_Too_many_values_passed_to_set_te_0008accc[18];
        tmp42[19] = s_Too_many_values_passed_to_set_te_0008accc[19];
        tmp42[20] = s_Too_many_values_passed_to_set_te_0008accc[20];
        tmp42[21] = s_Too_many_values_passed_to_set_te_0008accc[21];
        tmp42[22] = s_Too_many_values_passed_to_set_te_0008accc[22];
        tmp42[23] = s_Too_many_values_passed_to_set_te_0008accc[23];
        tmp42[24] = s_Too_many_values_passed_to_set_te_0008accc[24];
        tmp42[25] = s_Too_many_values_passed_to_set_te_0008accc[25];
        tmp42[26] = s_Too_many_values_passed_to_set_te_0008accc[26];
        tmp42[27] = s_Too_many_values_passed_to_set_te_0008accc[27];
        tmp42[28] = s_Too_many_values_passed_to_set_te_0008accc[28];
        tmp42[29] = s_Too_many_values_passed_to_set_te_0008accc[29];
        tmp42[30] = s_Too_many_values_passed_to_set_te_0008accc[30];
        tmp42[31] = s_Too_many_values_passed_to_set_te_0008accc[31];
        tmp42[32] = s_Too_many_values_passed_to_set_te_0008accc[32];
        tmp42[33] = s_Too_many_values_passed_to_set_te_0008accc[33];
        tmp42[34] = s_Too_many_values_passed_to_set_te_0008accc[34];
        tmp42[35] = s_Too_many_values_passed_to_set_te_0008accc[35];
        tmp42[36] = s_Too_many_values_passed_to_set_te_0008accc[36];
        tmp42[37] = s_Too_many_values_passed_to_set_te_0008accc[37];
        tmp42[38] = s_Too_many_values_passed_to_set_te_0008accc[38];
        tmp42[39] = s_Too_many_values_passed_to_set_te_0008accc[39];
        tmp42._40_2_ = (undefined2)ram0x0008acf4;
        _applog(3,tmp42,true);
        _quit(1);
      }
      val = atoi(nextptr);
      if ((val < 0) || (200 < val)) {
        tmp42[0] = s_Invalid_value_passed_to_set_temp_0008aca0[0];
        tmp42[1] = s_Invalid_value_passed_to_set_temp_0008aca0[1];
        tmp42[2] = s_Invalid_value_passed_to_set_temp_0008aca0[2];
        tmp42[3] = s_Invalid_value_passed_to_set_temp_0008aca0[3];
        tmp42[4] = s_Invalid_value_passed_to_set_temp_0008aca0[4];
        tmp42[5] = s_Invalid_value_passed_to_set_temp_0008aca0[5];
        tmp42[6] = s_Invalid_value_passed_to_set_temp_0008aca0[6];
        tmp42[7] = s_Invalid_value_passed_to_set_temp_0008aca0[7];
        tmp42[8] = s_Invalid_value_passed_to_set_temp_0008aca0[8];
        tmp42[9] = s_Invalid_value_passed_to_set_temp_0008aca0[9];
        tmp42[10] = s_Invalid_value_passed_to_set_temp_0008aca0[10];
        tmp42[11] = s_Invalid_value_passed_to_set_temp_0008aca0[11];
        tmp42[12] = s_Invalid_value_passed_to_set_temp_0008aca0[12];
        tmp42[13] = s_Invalid_value_passed_to_set_temp_0008aca0[13];
        tmp42[14] = s_Invalid_value_passed_to_set_temp_0008aca0[14];
        tmp42[15] = s_Invalid_value_passed_to_set_temp_0008aca0[15];
        tmp42[16] = s_Invalid_value_passed_to_set_temp_0008aca0[16];
        tmp42[17] = s_Invalid_value_passed_to_set_temp_0008aca0[17];
        tmp42[18] = s_Invalid_value_passed_to_set_temp_0008aca0[18];
        tmp42[19] = s_Invalid_value_passed_to_set_temp_0008aca0[19];
        tmp42[20] = s_Invalid_value_passed_to_set_temp_0008aca0[20];
        tmp42[21] = s_Invalid_value_passed_to_set_temp_0008aca0[21];
        tmp42[22] = s_Invalid_value_passed_to_set_temp_0008aca0[22];
        tmp42[23] = s_Invalid_value_passed_to_set_temp_0008aca0[23];
        tmp42[24] = s_Invalid_value_passed_to_set_temp_0008aca0[24];
        tmp42[25] = s_Invalid_value_passed_to_set_temp_0008aca0[25];
        tmp42[26] = s_Invalid_value_passed_to_set_temp_0008aca0[26];
        tmp42[27] = s_Invalid_value_passed_to_set_temp_0008aca0[27];
        tmp42[28] = s_Invalid_value_passed_to_set_temp_0008aca0[28];
        tmp42[29] = s_Invalid_value_passed_to_set_temp_0008aca0[29];
        tmp42[30] = s_Invalid_value_passed_to_set_temp_0008aca0[30];
        tmp42[31] = s_Invalid_value_passed_to_set_temp_0008aca0[31];
        tmp42[32] = s_Invalid_value_passed_to_set_temp_0008aca0[32];
        tmp42[33] = s_Invalid_value_passed_to_set_temp_0008aca0[33];
        tmp42[34] = s_Invalid_value_passed_to_set_temp_0008aca0[34];
        tmp42[35] = s_Invalid_value_passed_to_set_temp_0008aca0[35];
        tmp42[36] = s_Invalid_value_passed_to_set_temp_0008aca0[36];
        tmp42[37] = s_Invalid_value_passed_to_set_temp_0008aca0[37];
        tmp42[38] = s_Invalid_value_passed_to_set_temp_0008aca0[38];
        tmp42[39] = s_Invalid_value_passed_to_set_temp_0008aca0[39];
        _applog(3,tmp42,true);
        _quit(1);
      }
      _rd_lock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x523);
      devices[device]->cutofftemp = val;
      _rd_unlock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x525);
      device = device + 1;
      nextptr = strtok((char *)0x0,",");
    }
    if (device < 2) {
      _rd_lock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x53a);
      for (i = device; i < total_devices; i = i + 1) {
        devices[i]->cutofftemp = val;
      }
      _rd_unlock(&devices_lock,"cgminer.c","load_temp_cutoffs",0x540);
    }
  }
  return;
}

