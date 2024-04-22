
void write_host_MAC_and_time(undefined param_1,int param_2)

{
  uint local_c;
  
  printf("\n--- %s\n","write_host_MAC_and_time");
  send_pic_command(param_1);
  send_data_to_pic_iic(param_1,0x14,param_2,0xc);
  for (local_c = 0; local_c < 0xc; local_c = local_c + 1) {
    printf("%s: buf[%d] = 0x%02x\n","write_host_MAC_and_time",local_c,
           (uint)*(byte *)(local_c + param_2));
  }
  usleep(100000);
  return;
}

