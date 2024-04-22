
undefined4 write_data_into_pic_flash(uint param_1)

{
  send_pic_command();
  set_pic_iic((param_1 & 0xf) << 0x10 | 0x400005);
  usleep(100000);
  return 0;
}

