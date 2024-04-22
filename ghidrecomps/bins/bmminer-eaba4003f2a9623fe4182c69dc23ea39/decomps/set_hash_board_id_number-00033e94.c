
/* WARNING: Variable defined which should be unmapped: id-local */

void set_hash_board_id_number(uchar chain,uchar *id)

{
  uchar *id_local;
  undefined3 uStack_c;
  uchar chain_local;
  
  _uStack_c = CONCAT13(chain,uStack_c);
  send_pic_command(chain);
  send_data_to_pic_iic(chain,'\x12',id,'\f');
  cgsleep_us(CONCAT44(_uStack_c,id));
  return;
}

