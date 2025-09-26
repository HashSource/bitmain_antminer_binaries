
int32_t chain_switch_disable(int32_t which_chain)

{
  int32_t iVar1;
  int32_t which_chain_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t iic_data [2];
  int32_t ret;
  
  iVar1 = switch_open(which_chain);
  if (iVar1 < 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: open switch fail on chain %d\n","chain_switch_disable",which_chain);
    snprintf(tmp1,0x800,"open switch fail on chain %d",which_chain);
    log_to_file(tmp1,time_stamp);
  }
  else {
    iic_data[0] = '\0';
    iic_data[1] = '\0';
    iic_write(_g_switch_state[which_chain].switch_fd,iic_data,1);
    iVar1 = 0;
  }
  return iVar1;
}

