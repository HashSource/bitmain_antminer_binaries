
/* WARNING: Variable defined which should be unmapped: buf-local */

void write_host_MAC_and_time(uchar chain,uchar *buf)

{
  uchar *buf_local;
  undefined3 uStack_c;
  uchar chain_local;
  
  _uStack_c = CONCAT13(chain,uStack_c);
  send_pic_command(chain);
  send_data_to_pic_iic(chain,'\x14',buf,'\f');
  cgsleep_us(CONCAT44(_uStack_c,buf));
  return;
}

