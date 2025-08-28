
void set_hash_board_id_number(uchar chain,uchar *id)

{
  uchar *id_local;
  uchar chain_local;
  
  send_pic_command(chain);
  send_data_to_pic_iic(chain,'\x12',id,'\f');
  cgsleep_us(100000);
  return;
}

