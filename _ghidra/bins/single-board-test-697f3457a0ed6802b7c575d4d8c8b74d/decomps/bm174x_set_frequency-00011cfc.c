
void bm174x_set_frequency(int fd,uint32_t freq)

{
  uint32_t freq_local;
  int fd_local;
  char tmp42 [1024];
  base_type_t item;
  uint32_t pll_value;
  
  pll_value = 0;
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"Set frequency %u\n",freq);
    _applog(2,tmp42,false);
  }
  get_plldata(freq,&pll_value);
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '\f';
  item.data = pll_value;
  reg_value.pll_parameter = pll_value;
  bm174x_ioctl(fd,1,&item);
  return;
}

