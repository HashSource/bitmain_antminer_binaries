
void set_hash_board_id_number(undefined param_1,undefined4 param_2)

{
  printf("\n--- %s\n","set_hash_board_id_number");
  send_pic_command(param_1);
  send_data_to_pic_iic(param_1,0x12,param_2,0xc);
  usleep(100000);
  return;
}

