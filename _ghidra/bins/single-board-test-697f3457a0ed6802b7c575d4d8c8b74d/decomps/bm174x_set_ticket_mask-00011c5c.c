
void bm174x_set_ticket_mask(int fd,uint32_t tm)

{
  uint32_t tm_local;
  int fd_local;
  char tmp42 [1024];
  base_type_t item;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"Set ticket mask %u\n",tm);
    _applog(2,tmp42,false);
  }
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '\x14';
  reg_value.ticket_mask = tm;
  item.data = tm;
  bm174x_ioctl(fd,1,&item);
  return;
}

