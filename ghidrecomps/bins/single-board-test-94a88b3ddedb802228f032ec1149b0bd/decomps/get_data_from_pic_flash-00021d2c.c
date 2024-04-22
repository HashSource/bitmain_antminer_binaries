
void get_data_from_pic_flash(undefined param_1,undefined4 param_2)

{
  send_pic_command(param_1);
  get_data_from_pic_iic(param_1,3,param_2,0x10);
  return;
}

