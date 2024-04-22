
/* WARNING: Unknown calling convention */

void set_hash_board_id_number(uchar chain,uchar *id)

{
  int64_t in_stack_00000000;
  
  send_pic_command(chain);
  send_data_to_pic_iic(chain,'\x12',id,'\f');
  cgsleep_us(in_stack_00000000);
  return;
}

