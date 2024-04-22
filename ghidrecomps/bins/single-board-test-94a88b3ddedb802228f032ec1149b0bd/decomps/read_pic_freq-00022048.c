
undefined4 read_pic_freq(undefined param_1,int param_2)

{
  int local_c;
  
  set_pic_iic_flash_addr_pointer(param_1,0xf,0xa0);
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    get_data_from_pic_flash(param_1,local_c * 0x10 + param_2);
    usleep(200000);
  }
  return 0;
}

