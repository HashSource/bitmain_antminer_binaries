
/* WARNING: Unknown calling convention */

int32_t upgrade_pic(uint8_t which_chain,int8_t *file_path)

{
  int iVar1;
  byte bVar2;
  int32_t iVar3;
  FILE *__stream;
  ulong uVar4;
  byte *pbVar5;
  int32_t iVar6;
  uint32_t addr;
  uint32_t addr_00;
  char *pcVar7;
  byte *pbVar8;
  uint uVar9;
  uint8_t *puVar10;
  uint8_t *puVar11;
  uint32_t fd;
  uint uVar12;
  uint8_t read_back_data [2];
  uint8_t data_read [5];
  byte bStack_1be1;
  uint8_t buf [16];
  uint8_t send_data [6];
  undefined2 uStack_1bca;
  undefined4 local_1bc0;
  uint local_1bbc;
  undefined4 local_1bb8;
  undefined4 local_1bb4;
  char tmp42 [2048];
  uint8_t program_data [5000];
  
  uVar9 = (uint)which_chain;
  if (0xf < uVar9) {
    snprintf((char *)program_data,0x800,"%s: Bad pic param, input chain is %d\n","upgrade_pic",uVar9
            );
    _applog(0,(char *)program_data,false);
    return -0x7ffffdff;
  }
  if ((g_bitmain_pic_state[uVar9].chain_has_opened == 0) &&
     (iVar3 = open_pic(which_chain), iVar3 < 0)) {
    snprintf((char *)program_data,0x800,"%s: auto exec open_pic, but chain %d open eeprom failed\n",
             "upgrade_pic",uVar9);
    _applog(0,(char *)program_data,false);
    return iVar3;
  }
  memset(program_data,0,5000);
  fd = g_bitmain_pic_state[uVar9].pic_fd;
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
  buf[0xb] = '\0';
  buf[0xc] = '\0';
  buf[0xd] = '\0';
  buf[0xe] = '\0';
  buf[0xf] = '\0';
  snprintf(tmp42,0x800,"%s\n","_update_pic_app_program_1704");
  _applog(2,tmp42,false);
  __stream = fopen(file_path,"r");
  if (__stream == (FILE *)0x0) {
    snprintf(tmp42,0x800,"%s: open %s failed\n","_update_pic_app_program_1704",file_path);
    _applog(0,tmp42,false);
    return -0x7ffffe00;
  }
  fseek(__stream,0,0);
  memset(program_data,0,5000);
  snprintf(tmp42,0x800,"%s: pic_flash_length = %d\n","_update_pic_app_program_1704",0x980);
  _applog(2,tmp42,false);
  puVar10 = program_data;
  do {
    puVar11 = puVar10 + 2;
    fgets((char *)data_read,0x3ff,__stream);
    uVar4 = strtoul((char *)data_read,(char **)0x0,0x10);
    puVar10[1] = (uint8_t)uVar4;
    *puVar10 = (uint8_t)(uVar4 >> 8);
    puVar10 = puVar11;
  } while (puVar11 != program_data + 0x1300);
  fclose(__stream);
  iVar3 = reset_pic(which_chain);
  if (iVar3 == 0) {
    iVar3 = _bitmain_pic_seek_1704(fd,addr);
    if (iVar3 != 0) {
      snprintf(tmp42,0x800,"%s set 1704 flash pointer err\n","_erase_pic_app");
      _applog(0,tmp42,false);
      pcVar7 = "%s: erase app flash error!\n\n";
      goto LAB_000d3dc0;
    }
    pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
    send_data[1] = 0xaa;
    stack0xffffe434 = CONCAT22(uStack_1bca,0x800);
    send_data[2] = '\x04';
    send_data[3] = '\x04';
    read_back_data[0] = '\0';
    read_back_data[1] = '\0';
    send_data[0] = 'U';
    iVar3 = iic_write(fd,send_data,6);
    if (iVar3 == 6) {
      usleep(300000);
      iVar3 = iic_read(fd,read_back_data,2);
      if (iVar3 != 2) {
        pcVar7 = "%s read iic err\n";
        goto LAB_000d3e72;
      }
      usleep(300000);
      if ((read_back_data[0] != 4) || (read_back_data[1] != 1)) {
        snprintf(tmp42,0x800,"%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n"
                 ,"_bitmain_pic_erase_1704",(uint)read_back_data[0],(uint)read_back_data[1]);
        _applog(0,tmp42,false);
      }
    }
    else {
      pcVar7 = "%s write iic err\n";
LAB_000d3e72:
      snprintf(tmp42,0x800,pcVar7,"_bitmain_pic_erase_1704");
      _applog(0,tmp42,false);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
    iVar3 = _bitmain_pic_seek_1704(fd,addr_00);
    if (iVar3 != 0) {
      pcVar7 = "%s: set 1704 flash pointer err!\n\n";
      goto LAB_000d3dc0;
    }
    do {
      iVar1 = iVar3 * 0x10;
      buf._0_4_ = *(undefined4 *)(program_data + iVar1);
      buf._4_4_ = *(undefined4 *)(program_data + iVar1 + 4);
      buf._8_4_ = *(undefined4 *)(program_data + iVar1 + 8);
      buf._12_4_ = *(undefined4 *)(program_data + iVar1 + 0xc);
      snprintf(tmp42,0x800,"send pic program time: %d",iVar3);
      _applog(2,tmp42,false);
      pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
      pbVar8 = send_data + 3;
      uVar9 = 0x16;
      local_1bbc = 0;
      send_data[0] = 'U';
      local_1bb4 = 0;
      local_1bb8 = 0;
      send_data[1] = 0xaa;
      stack0xffffe434 = 0;
      send_data[2] = '\x14';
      send_data[3] = '\x02';
      read_back_data[0] = '\0';
      read_back_data[1] = '\0';
      pbVar5 = &bStack_1be1;
      local_1bc0 = 0;
      do {
        pbVar5 = pbVar5 + 1;
        bVar2 = *pbVar5;
        pbVar8 = pbVar8 + 1;
        *pbVar8 = bVar2;
        uVar9 = uVar9 + bVar2 & 0xffff;
      } while (pbVar8 != (byte *)((int)&local_1bc0 + 3));
      local_1bbc = (uint)CONCAT11((char)uVar9,(char)(uVar9 >> 8));
      iVar6 = iic_write(fd,send_data,0x16);
      if (iVar6 == 0x16) {
        usleep(300000);
        iVar6 = iic_read(fd,read_back_data,2);
        if (iVar6 != 2) {
          pcVar7 = "%s read iic 1 err\n";
          goto LAB_000d3e32;
        }
        uVar12 = (uint)read_back_data[0];
        uVar9 = (uint)read_back_data[1];
        if ((uVar12 == 2) && (uVar9 == 1)) {
          send_data[0] = 'U';
          send_data[1] = 0xaa;
          send_data[2] = '\x04';
          send_data[3] = '\x05';
          stack0xffffe434 = CONCAT22(uStack_1bca,0x900);
          iVar6 = iic_write(fd,send_data,6);
          if (iVar6 == 6) {
            usleep(300000);
            iVar6 = iic_read(fd,read_back_data,2);
            if (iVar6 == 2) {
              uVar12 = (uint)read_back_data[0];
              uVar9 = (uint)read_back_data[1];
              if ((uVar12 != 5) || (uVar9 != 1)) {
                pcVar7 = "%s failed 2! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n";
                goto LAB_000d3e02;
              }
              snprintf(tmp42,0x800,"%s  success write to pic flash\n","_bitmain_pic_write_1704");
              _applog(2,tmp42,false);
              goto LAB_000d3d6c;
            }
            pcVar7 = "%s read iic 2 err\n";
          }
          else {
            pcVar7 = "%s write iic 2 err\n";
          }
          snprintf(tmp42,0x800,pcVar7,"_bitmain_pic_write_1704");
          _applog(0,tmp42,false);
        }
        else {
          pcVar7 = "%s failed 1! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n";
LAB_000d3e02:
          snprintf(tmp42,0x800,pcVar7,"_bitmain_pic_write_1704",uVar12,uVar9);
          _applog(0,tmp42,false);
        }
      }
      else {
        pcVar7 = "%s write iic 1 err\n";
LAB_000d3e32:
        snprintf(tmp42,0x800,pcVar7,"_bitmain_pic_write_1704");
        _applog(0,tmp42,false);
      }
LAB_000d3d6c:
      iVar3 = iVar3 + 1;
      pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
    } while (iVar3 != 0x130);
    iVar3 = reset_pic(which_chain);
    if (iVar3 == 0) {
      return 0;
    }
  }
  pcVar7 = "%s: reset pic error!\n\n";
LAB_000d3dc0:
  snprintf(tmp42,0x800,pcVar7,"_update_pic_app_program_1704");
  _applog(0,tmp42,false);
  return iVar3;
}

