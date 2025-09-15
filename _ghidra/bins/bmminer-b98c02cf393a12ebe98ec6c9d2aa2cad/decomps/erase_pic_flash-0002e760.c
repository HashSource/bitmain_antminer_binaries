
undefined4 erase_pic_flash(uint param_1)

{
  send_pic_command();
  set_pic_iic((param_1 & 0xf) << 0x10 | 0x400004);
  usleep(100000);
  return 0;
}

