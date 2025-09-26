
int32_t switch_slection(int32_t which_chain,int8_t channal)

{
  int32_t iVar1;
  int8_t channal_local;
  int32_t which_chain_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t iic_data [2];
  int32_t ret;
  
  iVar1 = switch_open(which_chain);
  if (iVar1 < 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: open switch fail on chain %d\n","switch_slection",which_chain);
    snprintf(tmp1,0x800,"open switch fail on chain %d",which_chain);
    log_to_file(tmp1,time_stamp);
  }
  else {
    iic_data[0] = (uint8_t)(1 << (uint)(byte)channal);
    iic_data[1] = '\0';
    iic_write(_g_switch_state[which_chain].switch_fd,iic_data,1);
    iic_read(_g_switch_state[which_chain].switch_fd,iic_data + 1,1);
    if (iic_data[0] == iic_data[1]) {
      iVar1 = 0;
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: chain %d switch sel channel %d read back sel data  0x%0x 0x%0x\n",
             "switch_slection",which_chain,(int)channal,(uint)iic_data[0],(uint)iic_data[1]);
      snprintf(tmp1,0x800,"chain %d switch sel channel %d read back sel data  0x%0x 0x%0x",
               which_chain,(int)channal,(uint)iic_data[0],(uint)iic_data[1]);
      log_to_file(tmp1,time_stamp);
      iVar1 = -10;
    }
  }
  return iVar1;
}

