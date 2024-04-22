
undefined4 read_pic_disabledcore_pos(undefined param_1,undefined4 param_2)

{
  set_pic_iic_flash_addr_pointer(param_1,0xf,0xe8);
  get_data_from_pic_flash(param_1,param_2);
  return 0;
}

