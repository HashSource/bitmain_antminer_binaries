
void get_data_from_pic_iic(uint param_1,uint param_2,undefined *param_3,int param_4)

{
  undefined uVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  
  uVar4 = (param_1 & 0xf) << 0x10;
  set_pic_iic(param_2 | 0x400000 | uVar4);
  if (param_4 != 0) {
    puVar2 = param_3;
    do {
      uVar1 = set_pic_iic(uVar4 | 0x2400000);
      puVar3 = puVar2 + 1;
      *puVar2 = uVar1;
      puVar2 = puVar3;
    } while (puVar3 != param_3 + param_4);
  }
  return;
}

