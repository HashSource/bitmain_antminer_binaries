
/* WARNING: Unknown calling convention */

int dsPIC33EP16GS202_update_pic_app_program(uchar which_iic)

{
  FILE *__stream;
  FILE *pic_program_file;
  ulong uVar1;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  uint j;
  uchar data_read [7];
  uchar buf [16];
  uchar program_data [14080];
  
  puVar4 = program_data;
  memset(program_data,0,0x3700);
  data_read[1] = '\0';
  data_read[2] = '\0';
  data_read[3] = '\0';
  data_read[4] = '\0';
  data_read[5] = '\0';
  data_read[6] = '\0';
  data_read[0] = '\0';
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  buf[9] = '\0';
  buf[10] = '\0';
  buf[11] = '\0';
  buf[12] = '\0';
  buf[13] = '\0';
  buf[14] = '\0';
  buf[15] = '\0';
  puts(DAT_0002fddc);
  __stream = fopen(DAT_0002fde0,DAT_0002fde4);
  if (__stream == (FILE *)0x0) {
    iVar2 = printf(DAT_0002fe00,DAT_0002fdf4);
    return iVar2;
  }
  fseek(__stream,0,0);
  memset(program_data,0,0x3700);
  do {
    fgets((char *)data_read,0x3ff,__stream);
    uVar1 = strtoul((char *)data_read,(char **)0x0,0x10);
    puVar4[3] = (char)uVar1;
    *puVar4 = (char)(uVar1 >> 0x18);
    puVar4[1] = (char)(uVar1 >> 0x10);
    puVar4[2] = (char)(uVar1 >> 8);
    puVar4 = puVar4 + 4;
  } while (puVar4 != &stack0xffffffe8);
  fclose(__stream);
  iVar2 = dsPIC33EP16GS202_reset_pic(which_iic);
  if (iVar2 != 0) {
    iVar2 = dsPIC33EP16GS202_erase_pic_app_program(which_iic);
    if (iVar2 == 0) {
      printf(DAT_0002fdfc,DAT_0002fdf4);
      return 0;
    }
    iVar2 = 0;
    do {
      iVar3 = iVar2 * 0x10;
      buf._0_4_ = *(undefined4 *)(program_data + iVar3);
      buf._4_4_ = *(undefined4 *)(program_data + iVar3 + 4);
      buf._8_4_ = *(undefined4 *)(program_data + iVar3 + 8);
      buf._12_4_ = *(undefined4 *)(program_data + iVar3 + 0xc);
      printf(DAT_0002fde8,iVar2);
      iVar3 = 0;
      do {
        iVar5 = iVar3 + 1;
        printf(DAT_0002fdec,iVar3,(uint)buf[iVar3]);
        iVar3 = iVar5;
      } while (iVar5 != 0x10);
      putchar(10);
      iVar3 = dsPIC33EP16GS202_send_data_to_pic(which_iic,buf);
      if (iVar3 == 0) {
        printf(DAT_0002fdf8,DAT_0002fdf4);
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x370);
    iVar2 = dsPIC33EP16GS202_reset_pic(which_iic);
    if (iVar2 != 0) {
      return 1;
    }
  }
  printf(DAT_0002fdf0,DAT_0002fdf4);
  return 0;
}

