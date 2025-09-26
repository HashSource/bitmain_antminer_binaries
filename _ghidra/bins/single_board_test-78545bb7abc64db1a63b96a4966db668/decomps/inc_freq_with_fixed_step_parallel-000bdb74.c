
void inc_freq_with_fixed_step_parallel
               (uint8_t chain,uint8_t pll_id,uint32_t freq_start,uint32_t freq_end,float freq_step)

{
  float fVar1;
  uint uVar2;
  double dVar3;
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
  int PLL_1;
  int PLL_0;
  float curr_freq;
  uint32_t step_id;
  uint32_t step_count;
  
  inc_freq_with_fixed_step_parallel::cycle_pll_id = (int)pll_id;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  dVar3 = (double)freq_step;
  printf("%s : set freq_start = %d, freq_end = %d, freq_step = %.2f\n\n",
         "inc_freq_with_fixed_step_parallel",freq_start,freq_end,dVar3);
  snprintf(tmp1,0x100,"set freq_start = %d, freq_end = %d, freq_step = %.2f\n",freq_start,freq_end,
           (int)((ulonglong)dVar3 >> 0x20),(double)freq_step);
  log_to_file(tmp1,time_stamp);
  set_user_divider((uint)chain,'\x01','\0',pll_id);
  get_pllparam_divider(50.0,&target.pll_param,&userdivider,(float *)0x0);
  if (freq_start < freq_end) {
    fVar1 = (((float)(freq_end - freq_start) + freq_step) - 0.01) / freq_step;
    step_count = (uint)(0.0 < fVar1) * (int)(longlong)fVar1;
  }
  else {
    fVar1 = (((float)(freq_start - freq_end) + freq_step) - 0.01) / freq_step;
    step_count = (uint)(0.0 < fVar1) * (int)(longlong)fVar1;
  }
  uVar2 = step_count + 1;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : set_count:%d\n","inc_freq_with_fixed_step_parallel",uVar2);
  snprintf(tmp1,0x100,"set_count:%d",uVar2);
  log_to_file(tmp1,time_stamp);
  for (step_id = 1; step_id <= uVar2; step_id = step_id + 1) {
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
    set_freq((uint)chain,'\x01','\0',(uint8_t)inc_freq_with_fixed_step_parallel::cycle_pll_id,
             pll_config);
    usleep(300000);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : set freq end\n","inc_freq_with_fixed_step_parallel");
  builtin_strncpy(tmp1,"set freq end",0xc);
  tmp1[0xc] = '\0';
  log_to_file(tmp1,time_stamp);
  return;
}

