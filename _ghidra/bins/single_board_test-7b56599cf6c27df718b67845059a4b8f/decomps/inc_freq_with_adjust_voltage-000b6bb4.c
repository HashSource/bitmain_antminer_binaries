
void inc_freq_with_adjust_voltage
               (uint8_t chain,uint8_t pll_id,uint32_t freq_start,uint32_t freq_end,float freq_step)

{
  short sVar1;
  float fVar2;
  int32_t iVar3;
  uint uVar4;
  int iVar5;
  double dVar6;
  pll_conf pll_config;
  float freq_step_local;
  uint32_t freq_end_local;
  uint32_t freq_start_local;
  uint8_t pll_id_local;
  uint8_t chain_local;
  char time_stamp [48];
  char tmp1 [256];
  pll_userdivider_t userdivider;
  pll_conf target;
  int ret;
  int32_t relax_vol;
  int16_t board_temp;
  int idx;
  int avg;
  float curr_freq;
  uint32_t step_id;
  uint32_t step_count;
  
  avg = 0;
  idx = 1;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  dVar6 = (double)freq_step;
  printf("%s : fixed step freq_start = %d, freq_end = %d, freq_step = %.2f\n\n",
         "inc_freq_with_adjust_voltage",freq_start,freq_end,dVar6);
  snprintf(tmp1,0x100,"fixed step freq_start = %d, freq_end = %d, freq_step = %.2f\n",freq_start,
           freq_end,(int)((ulonglong)dVar6 >> 0x20),(double)freq_step);
  log_to_file(tmp1,time_stamp);
  set_user_divider((uint)chain,'\x01','\0',pll_id);
  if (freq_start < freq_end) {
    fVar2 = (((float)(freq_end - freq_start) + freq_step) - 0.01) / freq_step;
    step_count = (uint)(0.0 < fVar2) * (int)(longlong)fVar2;
  }
  else {
    fVar2 = (((float)(freq_start - freq_end) + freq_step) - 0.01) / freq_step;
    step_count = (uint)(0.0 < fVar2) * (int)(longlong)fVar2;
  }
  uVar4 = step_count + 1;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : step count:%d\n","inc_freq_with_adjust_voltage",uVar4);
  snprintf(tmp1,0x100,"step count:%d",uVar4);
  log_to_file(tmp1,time_stamp);
  for (step_id = 1; step_id <= uVar4; step_id = step_id + 1) {
    memset(&target,0,8);
    if (freq_start < freq_end) {
      curr_freq = (float)freq_start + (float)step_id * freq_step;
      if ((int)((uint)((float)freq_end < curr_freq) << 0x1f) < 0) {
        curr_freq = (float)freq_end;
      }
    }
    else {
      curr_freq = (float)freq_start - (float)step_id * freq_step;
      if (curr_freq < (float)freq_end) {
        curr_freq = (float)freq_end;
      }
    }
    get_pllparam_divider(curr_freq,&target.pll_param,&userdivider,(float *)0x0);
    target.usr_divider = userdivider.userdivider0;
    pll_config.pll_param.fbdiv = target.pll_param.fbdiv;
    pll_config.usr_divider = userdivider.userdivider0;
    pll_config._7_1_ = target._7_1_;
    pll_config.pll_param.postdiv1 = target.pll_param.postdiv1;
    pll_config.pll_param.postdiv2 = target.pll_param.postdiv2;
    pll_config.pll_param.refdiv = target.pll_param.refdiv;
    pll_config.pll_param._3_1_ = target.pll_param._3_1_;
    set_freq((uint)chain,'\x01','\0',pll_id,pll_config);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : chain = %d set freq to %.2f\n","inc_freq_with_adjust_voltage",(uint)chain,
           (uint)chain,(double)curr_freq);
    snprintf(tmp1,0x100,"chain = %d set freq to %.2f",(uint)chain,(double)curr_freq);
    log_to_file(tmp1,time_stamp);
    if ((freq_start < freq_end) && (300.0 <= curr_freq)) {
      iVar3 = get_ctrlboard_temp_min();
      sVar1 = (short)iVar3;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : inc freq get min board temp: %d\n","inc_freq_with_adjust_voltage",(int)sVar1);
      snprintf(tmp1,0x100,"inc freq get min board temp: %d",(int)sVar1);
      log_to_file(tmp1,time_stamp);
      if ((0x23 < sVar1) && (step_id < uVar4)) {
        if (avg == 0) {
          avg = __aeabi_uidiv((gHistory_Result[gPattern_test_counter].pre_open_core_voltage -
                              gHistory_Result[gPattern_test_counter].voltage) + -0x1e,
                              uVar4 - step_id);
        }
        iVar5 = gHistory_Result[gPattern_test_counter].pre_open_core_voltage - idx * avg;
        idx = idx + 1;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : relax voltage %d\n","inc_freq_with_adjust_voltage",iVar5);
        snprintf(tmp1,0x100,"relax voltage %d",iVar5);
        log_to_file(tmp1,time_stamp);
        iVar3 = bitmain_set_voltage((double)(longlong)iVar5 / 100.0);
        if (iVar3 != 0) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : bitmain_set_voltage %d ret=%d\n","inc_freq_with_adjust_voltage",iVar5,iVar3);
          snprintf(tmp1,0x100,"bitmain_set_voltage %d ret=%d",iVar5,iVar3);
          log_to_file(tmp1,time_stamp);
        }
      }
    }
    usleep((Local_Config_Information->Hash_Board).Inc_Freq_Delay * 1000);
  }
  return;
}

