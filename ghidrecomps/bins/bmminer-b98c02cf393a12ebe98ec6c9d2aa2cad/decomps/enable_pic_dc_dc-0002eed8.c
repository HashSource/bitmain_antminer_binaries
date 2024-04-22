
void enable_pic_dc_dc(uint param_1)

{
  uint uVar1;
  
  uVar1 = (param_1 & 0xf) << 0x10;
  send_pic_command();
  set_pic_iic(uVar1 | 0x400015);
  set_pic_iic(uVar1 | 0x400001);
  return;
}

