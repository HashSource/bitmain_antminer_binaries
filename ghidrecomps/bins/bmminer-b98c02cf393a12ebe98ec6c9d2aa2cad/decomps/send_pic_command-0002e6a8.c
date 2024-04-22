
void send_pic_command(uint param_1)

{
  uint uVar1;
  
  uVar1 = (param_1 & 0xf) << 0x10;
  set_pic_iic(uVar1 | 0x400055);
  set_pic_iic(uVar1 | 0x4000aa);
  return;
}

