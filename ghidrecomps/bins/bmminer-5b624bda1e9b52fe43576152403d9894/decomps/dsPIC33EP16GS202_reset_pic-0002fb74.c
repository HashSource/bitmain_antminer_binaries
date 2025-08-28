
/* WARNING: Unknown calling convention */

int dsPIC33EP16GS202_reset_pic(uchar which_iic)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char logstr [256];
  
  iVar3 = 3;
  printf("\n--- %s\n","dsPIC33EP16GS202_reset_pic");
  printf("--- %s: which_iic=%d crc_data[0] = 0x%x, crc_data[1] = 0x%x\n",
         "dsPIC33EP16GS202_reset_pic",(uint)which_iic,0,0xb);
  while( true ) {
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'U');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,0xaa);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x04');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\a');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\0');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\v');
    usleep(400000);
    bVar1 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar2 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    printf("--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x\n",
           "dsPIC33EP16GS202_reset_pic",(uint)bVar1,(uint)bVar2);
    usleep(100000);
    if ((bVar1 == 7) && (bVar2 == 1)) break;
    sprintf(logstr,"%s failed on Chain[%d]!\n");
    writeInitLogFile(logstr);
    sleep(1);
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 0;
    }
  }
  printf("\n--- %s ok\n\n","dsPIC33EP16GS202_reset_pic","dsPIC33EP16GS202_reset_pic",(uint)which_iic
        );
  sleep(1);
  return 1;
}

