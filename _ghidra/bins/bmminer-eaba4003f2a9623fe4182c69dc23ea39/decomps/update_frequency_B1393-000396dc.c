
void update_frequency_B1393(uint freq,uint chain,uint mode,uchar addr)

{
  uchar addr_local;
  uint mode_local;
  uint chain_local;
  uint freq_local;
  
  set_frequency_with_addr(freq,(uchar)mode,addr,(uchar)chain);
  usleep(500);
  set_divider(1,chain,mode,addr);
  usleep(500);
  set_frequency_with_addr(freq,(uchar)mode,addr,(uchar)chain);
  usleep(500);
  return;
}

