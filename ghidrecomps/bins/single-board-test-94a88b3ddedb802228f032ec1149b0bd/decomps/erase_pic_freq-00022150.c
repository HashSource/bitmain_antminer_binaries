
undefined4 erase_pic_freq(undefined param_1)

{
  uint local_c;
  
  set_pic_iic_flash_addr_pointer(param_1,0xf,0xa0);
  printf("%s: erase_loop = %d\n","erase_pic_freq",2);
  for (local_c = 0; local_c < 2; local_c = local_c + 1) {
    erase_pic_flash(param_1);
  }
  return 0;
}

