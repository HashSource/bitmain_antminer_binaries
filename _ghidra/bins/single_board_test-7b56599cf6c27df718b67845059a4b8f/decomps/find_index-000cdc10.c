
int32_t find_index(uint32_t which_chain,uint8_t slave_addr)

{
  char tmp42 [2048];
  
  snprintf(tmp42,0x800," Bad T-sensor param, input chain is %d\n",which_chain);
  _applog(0,tmp42,false);
  return -0x7ffff9ff;
}

