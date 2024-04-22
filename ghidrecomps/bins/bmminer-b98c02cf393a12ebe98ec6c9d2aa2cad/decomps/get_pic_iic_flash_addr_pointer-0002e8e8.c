
void get_pic_iic_flash_addr_pointer(uint param_1,undefined *param_2,undefined *param_3)

{
  undefined uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (param_1 & 0xf) << 0x10;
  send_pic_command();
  uVar3 = uVar2 | 0x2400000;
  set_pic_iic(uVar2 | 0x400008);
  uVar1 = set_pic_iic(uVar3);
  *param_2 = uVar1;
  uVar1 = set_pic_iic(uVar3);
  *param_3 = uVar1;
  return;
}

