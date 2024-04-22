
void set_pic_iic_flash_addr_pointer(uint param_1,uint param_2,uint param_3)

{
  FILE *__stream;
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte local_2a;
  byte local_29 [5];
  
  uVar2 = (param_1 & 0xf) << 0x10;
  uVar3 = uVar2 | 0x400000;
  iVar1 = 4;
  while( true ) {
    send_pic_command(param_1);
    set_pic_iic(uVar2 | 0x400001);
    set_pic_iic(uVar3 | param_2);
    set_pic_iic(param_3 | uVar3);
    get_pic_iic_flash_addr_pointer(param_1,&local_2a,local_29);
    if ((local_2a == param_2) && (local_29[0] == param_3)) {
      return;
    }
    if (3 < log_level) {
      __stream = fopen(log_file,(char *)&DAT_0005e760);
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,
                "%s:%d:%s: Error of set PIC FLASH addr: addr_H=%x(%x) addr_L=%x(%x) on Chain[%d]\n",
                "driver-btm-c5.c",0x52e,DAT_0002ea08,param_2,(uint)local_2a,param_3,
                (uint)local_29[0],param_1);
      }
      fclose(__stream);
    }
    if (iVar1 == 1) break;
    iVar1 = iVar1 + -1;
    dsPIC33EP16GS202_reset_pic(param_1);
    sleep(5);
  }
  return;
}

