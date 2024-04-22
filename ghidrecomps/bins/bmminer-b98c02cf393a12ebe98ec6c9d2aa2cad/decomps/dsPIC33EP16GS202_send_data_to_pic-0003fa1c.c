
undefined4 dsPIC33EP16GS202_send_data_to_pic(undefined4 param_1,undefined *param_2)

{
  int iVar1;
  int iVar2;
  FILE *__stream;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  pbVar3 = param_2 + -1;
  uVar4 = 0x16;
  do {
    pbVar3 = pbVar3 + 1;
    uVar5 = uVar4 + *pbVar3;
    uVar4 = uVar5 & 0xffff;
  } while (param_2 + 0xf != pbVar3);
  iVar6 = 3;
  do {
    T9_plus_write_pic_iic(0,0,0,param_1,0x55);
    T9_plus_write_pic_iic(0,0,0,param_1,0xaa);
    T9_plus_write_pic_iic(0,0,0,param_1,0x14);
    T9_plus_write_pic_iic(0,0,0,param_1,2);
    T9_plus_write_pic_iic(0,0,0,param_1,*param_2);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[1]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[2]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[3]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[4]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[5]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[6]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[7]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[8]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[9]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[10]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[0xb]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[0xc]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[0xd]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[0xe]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[0xf]);
    T9_plus_write_pic_iic(0,0,0,param_1,uVar4 >> 8);
    T9_plus_write_pic_iic(0,0,0,param_1,uVar5 & 0xff);
    usleep(200000);
    iVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    iVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    usleep(100000);
    if (iVar1 == 2 && iVar2 == 1) {
      return 1;
    }
    if (3 < log_level) {
      __stream = fopen(log_file,(char *)&DAT_0005e760);
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: %s failed on Chain[%d]!\n","dsPIC33EP16GS202.c",0x140,
                DAT_0003fca0,DAT_0003fca0,param_1);
      }
      fclose(__stream);
    }
    sleep(1);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return 0;
}

