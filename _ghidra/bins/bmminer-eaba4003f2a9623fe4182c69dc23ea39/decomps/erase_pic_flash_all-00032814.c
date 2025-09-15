
uchar erase_pic_flash_all(uchar chain)

{
  uchar chain_local;
  uint pic_flash_length;
  uchar end_addr_l;
  uchar end_addr_h;
  uchar start_addr_l;
  uchar start_addr_h;
  uint erase_loop;
  uint i;
  
  set_pic_iic_flash_addr_pointer(chain,'\x03','\0');
  for (i = 0; i < 100; i = i + 1) {
    erase_pic_flash(chain);
  }
  return 'd';
}

