
void change_high_pll_by_pll_no(uchar chain,float freq,int pll_no)

{
  int iVar1;
  uint uVar2;
  uint __bsx;
  int pll_no_local;
  float freq_local;
  uchar chain_local;
  char tmp42 [2048];
  uchar divider;
  float pll_freq;
  uint vil_pll_t;
  uchar vil_pll [4];
  uint pll;
  int local_pll_index;
  uint pll_index;
  uchar para_reg;
  uchar divider_reg;
  
  iVar1 = get_index_from_high_pll_yf((int)freq);
  divider = freq_high_pll_1385[iVar1].divider;
  get_pllparam_divider(freq,&vil_pll_t,&divider,&pll_freq);
  uVar2 = (vil_pll_t & 0xff00) << 8;
  vil_pll = (uchar  [4])
            (vil_pll_t << 0x18 | vil_pll_t >> 0x18 | (vil_pll_t & 0xff0000) >> 8 | uVar2);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"set freq %f, pll_no %d, divider %d, vil_pll %02x%02x%02x%02x",tmp42,
             (double)freq,pll_no,(uint)divider,vil_pll_t >> 0x18,(vil_pll_t & 0xff0000) >> 0x10,
             uVar2 >> 0x10,vil_pll_t & 0xff);
    _applog(5,tmp42,false);
  }
  if (pll_no == 0) {
    divider_reg = 'p';
    para_reg = '\b';
  }
  else {
    divider_reg = '|';
    para_reg = 'h';
  }
  set_config_BM1393(chain,'\0','\x01',divider_reg,divider - 1);
  set_config_BM1393(chain,'\0','\x01',para_reg,
                    (uint)vil_pll >> 0x18 |
                    (int)vil_pll << 0x18 | ((uint)vil_pll >> 8 & 0xff) << 0x10 |
                    ((uint)vil_pll >> 0x10 & 0xff) << 8);
  set_config_BM1393(chain,'\0','\x01',divider_reg,divider - 1);
  set_config_BM1393(chain,'\0','\x01',para_reg,
                    (uint)vil_pll >> 0x18 |
                    (int)vil_pll << 0x18 | ((uint)vil_pll >> 8 & 0xff) << 0x10 |
                    ((uint)vil_pll >> 0x10 & 0xff) << 8);
  return;
}

