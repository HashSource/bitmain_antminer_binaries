
void send_data_to_pic_iic(uint param_1,uint param_2,byte *param_3,int param_4)

{
  byte *pbVar1;
  uint uVar3;
  byte *pbVar2;
  
  uVar3 = (param_1 & 0xf) << 0x10 | 0x400000;
  set_pic_iic(param_2 | uVar3);
  if (param_4 != 0) {
    pbVar2 = param_3;
    do {
      pbVar1 = pbVar2 + 1;
      set_pic_iic(*pbVar2 | uVar3);
      pbVar2 = pbVar1;
    } while (pbVar1 != param_3 + param_4);
  }
  return;
}

