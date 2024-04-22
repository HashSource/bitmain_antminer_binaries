
/* WARNING: Unknown calling convention */

int set_Voltage_S9_plus_plus_BM1387_54(uchar which_iic,uchar pic_voltage)

{
  uchar uVar1;
  uchar uVar2;
  uchar voltage1;
  uint uVar3;
  int iVar4;
  char logstr [256];
  
  uVar3 = (uint)pic_voltage;
  printf(DAT_0002fa10);
  if ((int)(uVar3 << 0x18) < 0) {
    printf(DAT_0002fa1c,DAT_0002fa18,uVar3);
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
        printf(DAT_0002fa20,DAT_0002fa18,DAT_0002fa18,(uint)which_iic);
        AT24C02_save_voltage(which_iic,pic_voltage);
        return 1;
      }
      sprintf(logstr,DAT_0002fa14);
      writeInitLogFile(logstr);
      sleep(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return 0;
}

