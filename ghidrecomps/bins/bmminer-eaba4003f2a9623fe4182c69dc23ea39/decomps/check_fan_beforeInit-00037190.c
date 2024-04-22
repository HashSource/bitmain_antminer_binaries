
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void check_fan_beforeInit(void)

{
  int iVar1;
  byte bVar2;
  bool bVar3;
  char tmp42 [2048];
  char logstr [256];
  uint fan_speed;
  uchar fan_id;
  int j;
  int i;
  
  fan_id = '\0';
  for (j = 0; j < 2; j = j + 1) {
    for (i = 0; i < 8; i = i + 1) {
      iVar1 = get_fan_speed(&fan_id,&fan_speed);
      if (iVar1 != -1) {
        dev->fan_speed_value[fan_id] = fan_speed * 0x78;
        if ((fan_speed == 0) || (dev->fan_exist[fan_id] != '\0')) {
          if ((fan_speed == 0) && (dev->fan_exist[fan_id] == '\x01')) {
            dev->fan_exist[fan_id] = '\0';
            dev->fan_num = dev->fan_num + 0xff;
            iVar1 = 1 << fan_id;
            bVar3 = iVar1 != 0;
            if (bVar3) {
              iVar1 = 0;
            }
            bVar2 = (byte)iVar1;
            if (!bVar3) {
              bVar2 = 1;
            }
            dev->fan_exist_map = (uint)bVar2 & dev->fan_exist_map;
          }
        }
        else {
          dev->fan_exist[fan_id] = '\x01';
          dev->fan_num = dev->fan_num + '\x01';
          dev->fan_exist_map = 1 << fan_id | dev->fan_exist_map;
        }
        if ((dev->fan_exist[fan_id] == '\x01') && (check_fan_beforeInit::print_num < 100)) {
          check_fan_beforeInit::print_num = check_fan_beforeInit::print_num + 1;
          if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
            snprintf(tmp42,0x800,"get fan[%d] speed=%d\n",(uint)fan_id,dev->fan_speed_value[fan_id])
            ;
            _applog(5,tmp42,false);
          }
          if ((99 < check_fan_beforeInit::print_num) &&
             (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
            tmp42[0] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[0];
            tmp42[1] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[1];
            tmp42[2] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[2];
            tmp42[3] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[3];
            tmp42[4] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[4];
            tmp42[5] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[5];
            tmp42[6] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[6];
            tmp42[7] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[7];
            tmp42[8] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[8];
            tmp42[9] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[9];
            tmp42[10] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[10];
            tmp42[11] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[11];
            tmp42[12] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[12];
            tmp42[13] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[13];
            tmp42[14] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[14];
            tmp42[15] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[15];
            tmp42[16] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[16];
            tmp42[17] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[17];
            tmp42[18] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[18];
            tmp42[19] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[19];
            tmp42[20] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[20];
            tmp42[21] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[21];
            tmp42[22] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[22];
            tmp42[23] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[23];
            tmp42[24] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[24];
            tmp42[25] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[25];
            tmp42[26] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[26];
            tmp42[27] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[27];
            tmp42[28] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[28];
            tmp42[29] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[29];
            tmp42[30] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[30];
            tmp42[31] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[31];
            tmp42[32] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[32];
            tmp42[33] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[33];
            tmp42[34] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[34];
            tmp42[35] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[35];
            tmp42[36] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[36];
            tmp42[37] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[37];
            tmp42[38] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[38];
            tmp42[39] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[39];
            tmp42[40] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[40];
            tmp42[41] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[41];
            tmp42[42] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[42];
            tmp42[43] = s_Fatal_Error__some_Fan_lost_or_Fa_00076a38[43];
            tmp42._44_2_ = (undefined2)ram0x00076a64;
            _applog(5,tmp42,false);
          }
        }
        if (dev->fan_speed_top1 < dev->fan_speed_value[fan_id]) {
          dev->fan_speed_top1 = dev->fan_speed_value[fan_id];
        }
        if (((dev->fan_speed_value[fan_id] < dev->fan_speed_low1) &&
            (dev->fan_speed_value[fan_id] != 0)) || (dev->fan_speed_low1 == 0)) {
          dev->fan_speed_low1 = dev->fan_speed_value[fan_id];
        }
      }
    }
  }
  return;
}

