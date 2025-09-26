
void inc_freq_with_target(float *matrix,int len,float freq,int pll,uint8_t *state)

{
  int iVar1;
  int iVar2;
  float freq_00;
  _pll_conf pll_config;
  uint8_t *state_local;
  int pll_local;
  float freq_local;
  int len_local;
  float *matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  pll_userdivider_t userdivider;
  _pll_conf target;
  float asic_freq;
  int domain_asic;
  int domain;
  int j;
  int i;
  
  iVar1 = (g_rt.config)->domains;
  iVar2 = (g_rt.config)->asics_in_domain;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : set freq to %.2f from matrix.\n","inc_freq_with_target",SUB84((double)freq,0),
         (int)((ulonglong)(double)freq >> 0x20));
  snprintf(tmp1,0x100,"set freq to %.2f from matrix.",tmp1,(double)freq);
  log_to_file(tmp1,time_stamp);
  for (i = 0; i < iVar2; i = i + 1) {
    for (j = 0; j < iVar1; j = j + 1) {
      freq_00 = matrix[i + iVar2 * j];
      memset(&target,0,8);
      if (state[i + iVar2 * j] != '\x02') {
        set_user_divider((g_rt.config)->chain,(uint8_t)((i + iVar2 * j & 0xffU) << 1),'\0');
        get_pllparam_divider(freq_00,&target.pll_param,&userdivider,(float *)0x0);
        target.usr_divider = userdivider.userdivider0;
        pll_config.pll_param.fbdiv = target.pll_param.fbdiv;
        pll_config.usr_divider = userdivider.userdivider0;
        pll_config._7_1_ = target._7_1_;
        pll_config.pll_param.postdiv1 = target.pll_param.postdiv1;
        pll_config.pll_param.postdiv2 = target.pll_param.postdiv2;
        pll_config.pll_param.refdiv = target.pll_param.refdiv;
        pll_config.pll_param._3_1_ = target.pll_param._3_1_;
        set_freq_mix((g_rt.config)->chain,'\0',(uint8_t)((i + iVar2 * j & 0xffU) << 1),(uint8_t)pll,
                     pll_config);
      }
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : set freq over.\n","inc_freq_with_target");
  builtin_strncpy(tmp1,"set freq ove",0xc);
  tmp1[0xc] = 'r';
  tmp1[0xd] = '.';
  tmp1[0xe] = '\0';
  log_to_file(tmp1,time_stamp);
  return;
}

