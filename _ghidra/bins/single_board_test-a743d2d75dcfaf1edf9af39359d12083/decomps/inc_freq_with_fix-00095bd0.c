
void inc_freq_with_fix(uint8_t chain,uint8_t pll_id,uint32_t freq_start,uint32_t freq_end,
                      float freq_step)

{
  float fVar1;
  double dVar2;
  double dVar3;
  undefined8 uVar4;
  pll_conf pll_config;
  float freq_step_local;
  uint32_t freq_end_local;
  uint32_t freq_start_local;
  uint8_t pll_id_local;
  uint8_t chain_local;
  char time_stamp [48];
  char tmp1 [2048];
  pll_userdivider_t userdivider;
  pll_conf target;
  int PLL_2;
  int PLL_0;
  float curr_freq;
  uint32_t step_id;
  uint32_t step_count;
  undefined4 uVar5;
  
  inc_freq_with_fix::cycle_pll_id = (int)pll_id;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  dVar2 = (double)freq_step;
  printf("%s: fixed step freq_start = %d, freq_end = %d, freq_step = %.2f\n\n","inc_freq_with_fix",
         freq_start,freq_end,dVar2);
  dVar3 = (double)freq_step;
  uVar5 = (undefined4)((ulonglong)dVar2 >> 0x20);
  uVar4 = CONCAT44(uVar5,freq_end);
  snprintf(tmp1,0x800,"fixed step freq_start = %d, freq_end = %d, freq_step = %.2f\n",freq_start,
           freq_end,uVar5,dVar3);
  log_to_file(tmp1,time_stamp);
  if (freq_end == freq_start) {
    snprintf(tmp1,0x100,"no need to freq up, freq_start = freq_end = %d",freq_start,uVar4,dVar3);
    puts(tmp1);
  }
  else {
    set_user_divider((uint)chain,'\0',pll_id);
    if (freq_start < freq_end) {
      fVar1 = (((float)(freq_end - freq_start) + freq_step) - 0.01) / freq_step;
      step_count = (uint)(0.0 < fVar1) * (int)(longlong)fVar1;
    }
    else {
      fVar1 = (((float)(freq_start - freq_end) + freq_step) - 0.01) / freq_step;
      step_count = (uint)(0.0 < fVar1) * (int)(longlong)fVar1;
    }
    if ((step_count & 1) != 0) {
      step_count = step_count + 1;
    }
    for (step_id = 1; step_id <= step_count; step_id = step_id + 1) {
      if (inc_freq_with_fix::cycle_pll_id == 0) {
        inc_freq_with_fix::cycle_pll_id = 2;
      }
      else {
        inc_freq_with_fix::cycle_pll_id = 0;
      }
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
      set_freq((uint)chain,'\x01','\0',(uint8_t)inc_freq_with_fix::cycle_pll_id,pll_config);
      usleep(500000);
      set_chain_clock_select_control(chain,'\0',(uint8_t)inc_freq_with_fix::cycle_pll_id);
    }
  }
  return;
}

