
void send_data_to_pic_flash(undefined param_1,undefined4 param_2)

{
  send_pic_command(param_1);
  send_data_to_pic_iic(param_1,2,param_2,0x10);
  return;
}

