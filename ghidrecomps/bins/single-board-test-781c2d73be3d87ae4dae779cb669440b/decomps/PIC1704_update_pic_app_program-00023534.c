
/* WARNING: Unknown calling convention */

int PIC1704_update_pic_app_program(uint which_i2c,uchar which_chain)

{
  int iVar1;
  uchar uVar2;
  FILE *__stream;
  FILE *pic_program_file;
  ulong uVar3;
  int iVar4;
  uchar *puVar5;
  uchar *puVar6;
  uint j;
  uint uVar7;
  byte *pbVar8;
  char data_read [5];
  byte bStack_13c1;
  uchar buf [16];
  uchar program_data [5000];
  
  memset(program_data,0,5000);
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
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  data_read[0] = '\0';
  data_read[1] = '\0';
  data_read[2] = '\0';
  data_read[3] = '\0';
  data_read[4] = '\0';
  puts("\n--- update pic program");
  __stream = fopen("/mnt/card/pic16f1704_app.txt","r");
  if (__stream == (FILE *)0x0) {
    printf("\n%s: open pic16f1704_app.txt failed\n",DAT_000236ec);
    return 0;
  }
  fseek(__stream,0,0);
  memset(program_data,0,5000);
  printf("pic_flash_length = %d\n",0x980);
  puVar5 = program_data;
  do {
    puVar6 = puVar5 + 2;
    fgets(data_read,0x3ff,__stream);
    uVar3 = strtoul(data_read,(char **)0x0,0x10);
    puVar5[1] = (uchar)uVar3;
    *puVar5 = (uchar)(uVar3 >> 8);
    puVar5 = puVar6;
  } while (program_data + 0x1300 != puVar6);
  fclose(__stream);
  iVar4 = reset_PIC16F1704_pic(which_i2c,which_chain);
  if (iVar4 != 0) {
    uVar2 = erase_PIC16F1704_app_flash(which_i2c,which_chain);
    if (uVar2 == '\0') {
      printf("!!! %s: erase flash error!\n\n",DAT_000236ec);
      return 0;
    }
    iVar4 = set_PIC16F1704_flash_pointer(which_i2c,which_chain,'\x06','\0');
    if (iVar4 == 0) {
      printf("!!! %s: set flash pointer error!\n\n",DAT_000236ec);
      return 0;
    }
    iVar4 = 0;
    do {
      pbVar8 = &bStack_13c1;
      iVar1 = iVar4 * 0x10;
      buf._0_4_ = *(undefined4 *)(program_data + iVar1);
      buf._4_4_ = *(undefined4 *)(program_data + iVar1 + 4);
      buf._8_4_ = *(undefined4 *)(program_data + iVar1 + 8);
      buf._12_4_ = *(undefined4 *)(program_data + iVar1 + 0xc);
      printf("send pic program time: %d\n",iVar4);
      j = 0;
      do {
        pbVar8 = pbVar8 + 1;
        uVar7 = j + 1;
        printf("buf[%d] = 0x%02x\n",j,(uint)*pbVar8);
        j = uVar7;
      } while (uVar7 != 0x10);
      iVar4 = iVar4 + 1;
      putchar(10);
      send_data_to_PIC16F1704(which_i2c,which_chain,buf);
      write_data_into_PIC16F1704_flash(which_i2c,which_chain);
    } while (iVar4 != 0x130);
    iVar4 = reset_PIC16F1704_pic(which_i2c,which_chain);
    if (iVar4 != 0) {
      return 1;
    }
  }
  printf("!!! %s: reset pic error!\n\n",DAT_000236ec);
  return 0;
}

