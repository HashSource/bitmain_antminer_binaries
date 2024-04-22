
undefined4 erase_pic_badcore_num(undefined param_1)

{
  bool bVar1;
  
  set_pic_iic_flash_addr_pointer(param_1,0xf,0x80);
  printf("%s: erase_loop = %d\n","erase_pic_badcore_num",1);
  bVar1 = false;
  while (!bVar1) {
    erase_pic_flash(param_1);
    bVar1 = true;
  }
  return 0;
}

