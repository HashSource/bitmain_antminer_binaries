
void scan_freq_set_freq_by_chip(uint8_t chain,uint8_t chip_addr,float freq)

{
  int iVar1;
  FILE *__stream;
  uint32_t pll_00;
  float freq_local;
  uint8_t chip_addr_local;
  uint8_t chain_local;
  uint8_t divider;
  float pll_freq;
  uint32_t vil_pll_t;
  uint8_t vil_pll [4];
  FILE *pFile;
  uint32_t pll_index;
  uint32_t pll;
  int index;
  
  iVar1 = get_index_from_high_pll((int)freq);
  divider = freq_high_pll_1393[iVar1].divider;
  pll_00 = freq_high_pll_1393[iVar1].pll_out;
  if (opt_use_pll_list == false) {
    get_pllparam_divider(freq,&vil_pll_t,&divider,&pll_freq);
    vil_pll = (uint8_t  [4])__bswap_32(vil_pll_t);
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: chain %d chip %d set freq %d, pll_out %d","driver-btm-soc.c",
                0x13a8,"scan_freq_set_freq_by_chip",(uint)chain,(uint)chip_addr,
                freq_high_pll_1393[iVar1].freq,pll_00);
      }
      fclose(__stream);
    }
    iVar1 = get_index_from_pll_B1393(pll_00);
    get_plldata_from_index(iVar1,vil_pll);
  }
  set_config_BM1393(chain,chip_addr,'\0','p',divider - 1);
  set_config_BM1393(chain,chip_addr,'\0','\b',
                    ((uint)vil_pll >> 0x10 & 0xff) << 8 |
                    (int)vil_pll << 0x18 | ((uint)vil_pll >> 8 & 0xff) << 0x10 |
                    (uint)vil_pll >> 0x18);
  set_config_BM1393(chain,chip_addr,'\0','p',divider - 1);
  set_config_BM1393(chain,chip_addr,'\0','\b',
                    ((uint)vil_pll >> 0x10 & 0xff) << 8 |
                    (int)vil_pll << 0x18 | ((uint)vil_pll >> 8 & 0xff) << 0x10 |
                    (uint)vil_pll >> 0x18);
  return;
}

