
/* WARNING: Unknown calling convention */

int dsPIC33EP16GS202_get_pic_sw_version(uchar which_iic,uchar *version)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uchar uVar5;
  int iVar6;
  char logstr [256];
  
  iVar6 = 3;
  printf("\n--- %s\n","dsPIC33EP16GS202_get_pic_sw_version");
  *version = 0xff;
  printf("--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n","dsPIC33EP16GS202_get_pic_sw_version",0,
         0x1b);
  do {
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'U');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,0xaa);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x04');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x17');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\0');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x1b');
    usleep(100000);
    bVar1 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar2 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar3 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar4 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    uVar5 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    printf("--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x\n",
           "dsPIC33EP16GS202_get_pic_sw_version",(uint)bVar1,(uint)bVar2);
    usleep(100000);
    if ((bVar2 == 0x17) && (bVar1 == 5)) {
      if (((ushort)bVar4 == (ushort)(bVar3 + 0x1c) >> 8) && (uVar5 == (uchar)(bVar3 + 0x1c))) {
        *version = bVar3;
        printf("\n--- %s ok\n\n","dsPIC33EP16GS202_get_pic_sw_version");
        return 1;
      }
      printf("\n--- %s failed!\n\n","dsPIC33EP16GS202_get_pic_sw_version");
      sleep(1);
    }
    else {
      sprintf(logstr,"%s failed on Chain[%d]!\n","dsPIC33EP16GS202_get_pic_sw_version",
              (uint)which_iic);
      writeInitLogFile(logstr);
      sleep(1);
    }
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) {
      return 0;
    }
  } while( true );
}

