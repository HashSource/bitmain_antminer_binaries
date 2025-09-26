
void gpio_key_callback(uint32_t port,uint8_t val)

{
  char tmp42 [2048];
  
  snprintf(tmp42,0x800,"gpio port %d is not a supported key\n",port);
  _applog(1,tmp42,false);
  return;
}

