
undefined4 erase_pic_flash_all(undefined param_1)

{
  uint local_c;
  
  set_pic_iic_flash_addr_pointer(param_1,3,0);
  printf("%s: erase_loop = %d\n","erase_pic_flash_all",100);
  for (local_c = 0; local_c < 100; local_c = local_c + 1) {
    erase_pic_flash(param_1);
  }
  return 0;
}

