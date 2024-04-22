
/* WARNING: Unknown calling convention */

void set_BM1397_freq_slowly(uchar which_chain,uchar chip_addr,uint freq,_Bool mode)

{
  uint uVar1;
  uint freq_00;
  
  freq_00 = 0x32;
  do {
    set_BM1397_freq(which_chain,chip_addr,freq_00,true);
    uVar1 = freq_00 + 0x32;
    freq_00 = freq_00 + 0x19;
  } while (uVar1 < freq);
  set_BM1397_freq(which_chain,chip_addr,freq,true);
  return;
}

