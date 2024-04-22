
void change_high_pll_test(uchar chain,float freq,int index)

{
  uint uVar1;
  uint __bsx;
  int index_local;
  float freq_local;
  uchar chain_local;
  char tmp42 [2048];
  uchar divider;
  float pll_freq;
  uint vil_pll_t;
  uchar vil_pll [4];
  uint pll_index;
  uint pll;
  
  divider = freq_high_pll_1385[index].divider;
  get_pllparam_divider(freq,&vil_pll_t,&divider,&pll_freq);
  uVar1 = (vil_pll_t & 0xff00) << 8;
  vil_pll = (uchar  [4])
            (vil_pll_t << 0x18 | vil_pll_t >> 0x18 | (vil_pll_t & 0xff0000) >> 8 | uVar1);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"set freq %f, divider %d, vil_pll %02x%02x%02x%02x",tmp42,(double)freq,
             (uint)divider,vil_pll_t >> 0x18,(vil_pll_t & 0xff0000) >> 0x10,uVar1 >> 0x10,
             vil_pll_t & 0xff);
    _applog(5,tmp42,false);
  }
  set_config_BM1393(chain,'\0','\x01','p',divider - 1);
  set_config_BM1393(chain,'\0','\x01','\b',
                    (uint)vil_pll >> 0x18 |
                    (int)vil_pll << 0x18 | ((uint)vil_pll >> 8 & 0xff) << 0x10 |
                    ((uint)vil_pll >> 0x10 & 0xff) << 8);
  set_config_BM1393(chain,'\0','\x01','p',divider - 1);
  set_config_BM1393(chain,'\0','\x01','\b',
                    (uint)vil_pll >> 0x18 |
                    (int)vil_pll << 0x18 | ((uint)vil_pll >> 8 & 0xff) << 0x10 |
                    ((uint)vil_pll >> 0x10 & 0xff) << 8);
  return;
}

