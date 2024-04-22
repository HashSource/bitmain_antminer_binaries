
/* WARNING: Unknown calling convention */

void write_host_MAC_and_time(uchar chain,uchar *buf)

{
  int64_t in_stack_00000000;
  
  send_pic_command(chain);
  send_data_to_pic_iic(chain,'\x14',buf,'\f');
  cgsleep_us(in_stack_00000000);
  return;
}

