
void set_freq_by_chip(uchar chain,uchar chip_addr,float freq)

{
  byte bVar1;
  int iVar2;
  uint pll_00;
  float freq_local;
  uchar chip_addr_local;
  uchar chain_local;
  char tmp42 [2048];
  uchar divider;
  float pll_freq;
  uint vil_pll_t;
  uchar vil_pll [4];
  uint pll_index;
  uint pll;
  int index;
  
  iVar2 = get_index_from_high_pll_yf((int)freq);
  bVar1 = freq_high_pll_1385[iVar2].divider;
  pll_00 = freq_high_pll_1385[iVar2].pll_out;
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"chain %d chip %d set freq %d, pll_out %d",(uint)chain,(uint)chip_addr,
             freq_high_pll_1385[iVar2].freq,pll_00);
    _applog(5,tmp42,false);
  }
  iVar2 = get_index_from_pll_B1393(pll_00);
  get_plldata_from_index(iVar2,vil_pll);
  set_config_BM1393(chain,chip_addr,'\0','p',bVar1 - 1);
  usleep(5000);
  set_config_BM1393(chain,chip_addr,'\0','\b',
                    (uint)vil_pll[3] |
                    (uint)vil_pll[0] << 0x18 | (uint)vil_pll[1] << 0x10 | (uint)vil_pll[2] << 8);
  return;
}

