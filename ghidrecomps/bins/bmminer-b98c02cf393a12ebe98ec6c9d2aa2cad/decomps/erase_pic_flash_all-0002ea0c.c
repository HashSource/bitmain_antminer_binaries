
void erase_pic_flash_all(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  int iVar1;
  
  iVar1 = 100;
  set_pic_iic_flash_addr_pointer(param_1,3,0,param_4,param_4);
  do {
    erase_pic_flash(param_1);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

