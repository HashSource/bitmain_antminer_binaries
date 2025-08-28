
/* WARNING: Unknown calling convention */

int set_Voltage_S9_plus_plus_BM1387_54(uchar which_iic,uchar pic_voltage)

{
  uchar uVar1;
  uchar uVar2;
  uint uVar3;
  int iVar4;
  char logstr [256];
  
  uVar3 = (uint)pic_voltage;
  printf("voltage1 = %d\n");
  if ((int)(uVar3 << 0x18) < 0) {
    printf("\n--- %s voltage1(%d) > 127 \n\n","set_Voltage_S9_plus_plus_BM1387_54",uVar3);
  }
  else {
    iVar4 = 3;
    do {
      T9_plus_write_pic_iic(false,false,'\0',which_iic,'U');
      T9_plus_write_pic_iic(false,false,'\0',which_iic,0xaa);
      T9_plus_write_pic_iic(false,false,'\0',which_iic,'\a');
      T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x10');
      T9_plus_write_pic_iic(false,false,'\0',which_iic,pic_voltage);
      T9_plus_write_pic_iic(false,false,'\0',which_iic,'\0');
      T9_plus_write_pic_iic(false,false,'\0',which_iic,'\0');
      T9_plus_write_pic_iic(false,false,'\0',which_iic,(uchar)(uVar3 + 0x17 >> 8));
      T9_plus_write_pic_iic(false,false,'\0',which_iic,(uchar)(uVar3 + 0x17));
      usleep(100000);
      uVar1 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
      uVar2 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
      if ((uVar1 == '\x10') && (uVar2 == '\x01')) {
        printf("\n--- %s ok!\n\n","set_Voltage_S9_plus_plus_BM1387_54",
               "set_Voltage_S9_plus_plus_BM1387_54",(uint)which_iic);
        AT24C02_save_voltage(which_iic,pic_voltage);
        return 1;
      }
      sprintf(logstr,"%s failed on Chain[%d]!\n\n");
      writeInitLogFile(logstr);
      sleep(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return 0;
}

