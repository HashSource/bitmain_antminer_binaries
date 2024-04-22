
void update_pic_program(uchar chain)

{
  FILE *__stream;
  ulong uVar1;
  int iVar2;
  uchar chain_local;
  uchar buf [16];
  uchar data_read [5];
  uchar program_data [10240];
  FILE *pic_program_file;
  uint pic_flash_length;
  uchar end_addr_l;
  uchar end_addr_h;
  uchar start_addr_l;
  uchar start_addr_h;
  uint data_int;
  uint j;
  uint i;
  
  memset(program_data,0,0x2800);
  data_read[0] = '\0';
  data_read[1] = '\0';
  data_read[2] = '\0';
  data_read[3] = '\0';
  data_read[4] = '\0';
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
  __stream = fopen("/etc/config/hash_s8_app.txt","r");
  if (__stream == (FILE *)0x0) {
    printf("\n%s: open hash_s8_app.txt failed\n","update_pic_program");
  }
  else {
    fseek(__stream,0,0);
    memset(program_data,0,0x2800);
    chain_local = chain;
    for (i = 0; i < 0xc80; i = i + 1) {
      fgets((char *)data_read,0x3ff,__stream);
      uVar1 = strtoul((char *)data_read,(char **)0x0,0x10);
      program_data[i * 2] = (uchar)(uVar1 >> 8);
      program_data[i * 2 + 1] = (uchar)uVar1;
    }
    fclose(__stream);
    reset_iic_pic(chain_local);
    erase_pic_flash_all(chain_local);
    set_pic_iic_flash_addr_pointer(chain_local,'\x03','\0');
    for (i = 0; i < 400; i = i + 1) {
      iVar2 = i * 0x10;
      buf._0_4_ = *(undefined4 *)(program_data + iVar2);
      buf._4_4_ = *(undefined4 *)(program_data + iVar2 + 4);
      buf._8_4_ = *(undefined4 *)(program_data + iVar2 + 8);
      buf._12_4_ = *(undefined4 *)(program_data + iVar2 + 0xc);
      printf("send pic program time: %d\n",i);
      for (j = 0; j < 0x10; j = j + 1) {
        printf("buf[%d] = 0x%02x\n",j,(uint)buf[j]);
      }
      putchar(10);
      send_data_to_pic_flash(chain_local,buf);
      write_data_into_pic_flash(chain_local);
    }
  }
  return;
}

