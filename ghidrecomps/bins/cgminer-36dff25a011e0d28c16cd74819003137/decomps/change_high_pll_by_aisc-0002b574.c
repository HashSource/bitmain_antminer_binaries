
void change_high_pll_by_aisc(uint32_t chain,uint32_t asic,float freq,int index)

{
  uchar which_chain;
  uchar chip_addr_00;
  FILE *__stream;
  int index_00;
  uint32_t pll_00;
  int index_local;
  float freq_local;
  uint32_t asic_local;
  uint32_t chain_local;
  uint8_t divider;
  float pll_freq;
  uint32_t vil_pll_t;
  uint8_t vil_pll [4];
  FILE *pFile;
  uint32_t chip_addr;
  uint32_t pll_index;
  uint32_t pll;
  
  divider = freq_high_pll_1391[index].divider;
  pll_00 = freq_high_pll_1391[index].pll_out;
  chip_addr_00 = (char)asic * '\x05';
  if (opt_use_pll_list) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: set freq %d, pll_out %d\n","driver-btm-soc.c",0x1342,
                "change_high_pll_by_aisc",freq_high_pll_1391[index].freq,pll_00);
      }
      fclose(__stream);
    }
    index_00 = get_index_from_pll_B1391(pll_00);
    get_plldata_from_index(index_00,vil_pll);
  }
  else {
    get_pllparam_divider(freq,&vil_pll_t,&divider,&pll_freq);
    vil_pll = (uint8_t  [4])__bswap_32(vil_pll_t);
  }
  vil_pll = (uint8_t  [4])((uint)vil_pll | 0x40);
  which_chain = (uchar)chain;
  set_config_BM1391_t(which_chain,chip_addr_00,'\0','p',divider - 1 | 0xf0f0f00);
  set_config_BM1391_t(which_chain,chip_addr_00,'\0','\b',
                      (int)vil_pll << 0x18 | ((uint)vil_pll >> 8 & 0xff) << 0x10 |
                      ((uint)vil_pll >> 0x10 & 0xff) << 8 | (uint)vil_pll >> 0x18);
  set_config_BM1391_t(which_chain,chip_addr_00,'\0','p',divider - 1 | 0xf0f0f00);
  set_config_BM1391_t(which_chain,chip_addr_00,'\0','\b',
                      (int)vil_pll << 0x18 | ((uint)vil_pll >> 8 & 0xff) << 0x10 |
                      ((uint)vil_pll >> 0x10 & 0xff) << 8 | (uint)vil_pll >> 0x18);
  return;
}

