
void get_hash_board_id_number(uchar chain,uchar *id)

{
  uchar *id_local;
  uchar chain_local;
  
  send_pic_command(chain);
  get_data_from_pic_iic(chain,'\x13',id,'\f');
  return;
}

