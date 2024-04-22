
void get_hash_board_id_number(undefined param_1,undefined4 param_2)

{
  puts("get_hash_board_id_number");
  send_pic_command(param_1);
  get_data_from_pic_iic(param_1,0x13,param_2,0xc);
  return;
}

