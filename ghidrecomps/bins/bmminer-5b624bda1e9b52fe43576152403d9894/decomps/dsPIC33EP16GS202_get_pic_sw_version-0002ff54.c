
/* WARNING: Unknown calling convention */

int dsPIC33EP16GS202_get_pic_sw_version(uchar which_iic,uchar *version)

{
  undefined4 uVar1;
  char *pcVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  uchar uVar7;
  int iVar8;
  char logstr [256];
  
  iVar8 = 3;
  printf(DAT_000300c4,DAT_000300c0);
  pcVar2 = DAT_000300c8;
  uVar1 = DAT_000300c0;
  *version = 0xff;
  printf(pcVar2,uVar1,0,0x1b);
  do {
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'U');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,0xaa);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x04');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x17');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\0');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x1b');
    usleep(100000);
    bVar3 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar4 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar5 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar6 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    uVar7 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    printf(DAT_000300cc,DAT_000300c0,(uint)bVar3,(uint)bVar4);
    usleep(100000);
    pcVar2 = DAT_000300d8;
    uVar1 = DAT_000300c0;
    if ((bVar4 == 0x17) && (bVar3 == 5)) {
      if (((ushort)bVar6 == (ushort)(bVar5 + 0x1c) >> 8) && (uVar7 == (uchar)(bVar5 + 0x1c))) {
        *version = bVar5;
        printf(pcVar2,uVar1);
        return 1;
      }
      printf(DAT_000300d4,DAT_000300c0);
      sleep(1);
    }
    else {
      sprintf(logstr,DAT_000300d0,DAT_000300c0,(uint)which_iic);
      writeInitLogFile(logstr);
      sleep(1);
    }
    iVar8 = iVar8 + -1;
    if (iVar8 == 0) {
      return 0;
    }
  } while( true );
}

