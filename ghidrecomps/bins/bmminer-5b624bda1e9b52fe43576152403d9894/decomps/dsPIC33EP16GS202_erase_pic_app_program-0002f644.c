
/* WARNING: Unknown calling convention */

int dsPIC33EP16GS202_erase_pic_app_program(uchar which_iic)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char logstr [256];
  
  iVar3 = 3;
  while( true ) {
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'U');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,0xaa);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x04');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\t');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\0');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\r');
    usleep(100000);
    bVar1 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar2 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    printf("--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x\n",
           "dsPIC33EP16GS202_erase_pic_app_program",(uint)bVar1,(uint)bVar2);
    usleep(200000);
    if ((bVar1 == 9) && (bVar2 == 1)) break;
    sprintf(logstr,"%s failed on Chain[%d]!\n");
    writeInitLogFile(logstr);
    sleep(1);
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 0;
    }
  }
  printf("\n--- %s ok\n\n","dsPIC33EP16GS202_erase_pic_app_program",
         "dsPIC33EP16GS202_erase_pic_app_program",(uint)which_iic);
  return 1;
}

