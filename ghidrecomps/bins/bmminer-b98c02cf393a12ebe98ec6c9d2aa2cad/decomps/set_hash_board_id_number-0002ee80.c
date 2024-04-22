
void set_hash_board_id_number(undefined4 param_1,undefined4 param_2)

{
  send_pic_command();
  send_data_to_pic_iic(param_1,0x12,param_2,0xc);
  cgsleep_us(100000,0);
  return;
}

