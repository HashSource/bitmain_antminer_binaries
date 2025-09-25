
/* WARNING: Unknown calling convention */

int32_t upgrade_pic(uint8_t which_chain,int8_t *file_path)

{
  int iVar1;
  int32_t iVar2;
  FILE *__stream;
  ulong uVar3;
  uint32_t addr;
  uint32_t addr_00;
  char *pcVar4;
  uint8_t *puVar5;
  uint uVar6;
  uint8_t *puVar7;
  int iVar8;
  uint32_t fd;
  uint uVar9;
  uint8_t read_back_data [2];
  uint8_t data_read [5];
  uint8_t uStack_1be1;
  uint8_t buf [16];
  uint8_t send_data [6];
  undefined2 uStack_1bca;
  char tmp42 [2048];
  uint8_t program_data [5000];
  
  uVar6 = (uint)which_chain;
  if (0xf < uVar6) {
    snprintf((char *)program_data,0x800,"%s: Bad pic param, input chain is %d\n","upgrade_pic",uVar6
            );
    _applog(0,(char *)program_data,false);
    return -0x7ffffdff;
  }
  if ((g_bitmain_pic_state[uVar6].chain_has_opened == 0) &&
     (iVar2 = open_pic(which_chain), iVar2 < 0)) {
    snprintf((char *)program_data,0x800,"%s: auto exec open_pic, but chain %d open eeprom failed\n",
             "upgrade_pic",uVar6);
    _applog(0,(char *)program_data,false);
    return iVar2;
  }
  memset(program_data,0,5000);
  fd = g_bitmain_pic_state[uVar6].pic_fd;
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
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  data_read[0] = '\0';
  data_read[1] = '\0';
  data_read[2] = '\0';
  data_read[3] = '\0';
  data_read[4] = '\0';
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
  puVar5 = program_data;
  do {
    puVar7 = puVar5 + 2;
    fgets((char *)data_read,0x3ff,__stream);
    uVar3 = strtoul((char *)data_read,(char **)0x0,0x10);
    puVar5[1] = (uint8_t)uVar3;
    *puVar5 = (uint8_t)(uVar3 >> 8);
    puVar5 = puVar7;
  } while (puVar7 != program_data + 0x1300);
  fclose(__stream);
  iVar2 = reset_pic(which_chain);
  if (iVar2 == 0) {
    iVar2 = _bitmain_pic_seek_1704(fd,addr);
    if (iVar2 != 0) {
      snprintf(tmp42,0x800,"%s set 1704 flash pointer err\n","_erase_pic_app");
      _applog(0,tmp42,false);
      pcVar4 = "%s: erase app flash error!\n\n";
      goto LAB_000c589c;
    }
    pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
    send_data[1] = 0xaa;
    stack0xffffe434 = CONCAT22(uStack_1bca,0x800);
    send_data[2] = '\x04';
    send_data[3] = '\x04';
    read_back_data[0] = '\0';
    read_back_data[1] = '\0';
    send_data[0] = 'U';
    iVar2 = iic_write(fd,send_data,6);
    if (iVar2 == 6) {
      usleep(300000);
      iVar2 = iic_read(fd,read_back_data,2);
      if (iVar2 != 2) {
        pcVar4 = "%s read iic err\n";
        goto LAB_000c592e;
      }
      usleep(300000);
      if ((read_back_data[0] != 4) || (read_back_data[1] != 1)) {
        snprintf(tmp42,0x800,"%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n"
                 ,"_bitmain_pic_erase_1704",(uint)read_back_data[0],(uint)read_back_data[1]);
        _applog(0,tmp42,false);
      }
    }
    else {
      pcVar4 = "%s write iic err\n";
LAB_000c592e:
      snprintf(tmp42,0x800,pcVar4,"_bitmain_pic_erase_1704");
      _applog(0,tmp42,false);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
    iVar2 = _bitmain_pic_seek_1704(fd,addr_00);
    if (iVar2 != 0) {
      pcVar4 = "%s: set 1704 flash pointer err!\n\n";
      goto LAB_000c589c;
    }
    iVar8 = 0;
    do {
      iVar1 = iVar8 * 0x10;
      buf._0_4_ = *(undefined4 *)(program_data + iVar1);
      buf._4_4_ = *(undefined4 *)(program_data + iVar1 + 4);
      buf._8_4_ = *(undefined4 *)(program_data + iVar1 + 8);
      buf._12_4_ = *(undefined4 *)(program_data + iVar1 + 0xc);
      snprintf(tmp42,0x800,"send pic program time: %d",iVar8);
      _applog(2,tmp42,false);
      pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
      memset(send_data,0,0x20);
      send_data[0] = 'U';
      puVar7 = send_data + 3;
      puVar5 = &uStack_1be1;
      send_data[1] = 0xaa;
      send_data[2] = '\x14';
      send_data[3] = '\x02';
      read_back_data[0] = '\0';
      read_back_data[1] = '\0';
      unique0x100001e2 = 0;
      do {
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
        *puVar7 = *puVar5;
      } while (puVar5 != buf + 0xf);
      iVar2 = iic_write(fd,send_data,0x16);
      if (iVar2 == 0x16) {
        usleep(300000);
        iVar2 = iic_read(fd,read_back_data,2);
        if (iVar2 != 2) {
          pcVar4 = "%s read iic 1 err\n";
          goto LAB_000c58da;
        }
        uVar9 = (uint)read_back_data[0];
        uVar6 = (uint)read_back_data[1];
        if ((uVar9 == 2) && (uVar6 == 1)) {
          send_data[0] = 'U';
          send_data[1] = 0xaa;
          send_data[2] = '\x04';
          stack0xffffe434 = CONCAT22(uStack_1bca,0x900);
          send_data[3] = '\x05';
          iVar2 = iic_write(fd,send_data,6);
          if (iVar2 == 6) {
            usleep(300000);
            iVar2 = iic_read(fd,read_back_data,2);
            if (iVar2 == 2) {
              uVar9 = (uint)read_back_data[0];
              uVar6 = (uint)read_back_data[1];
              if ((uVar9 != 5) || (uVar6 != 1)) {
                pcVar4 = "%s failed 2! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n";
                goto LAB_000c58fe;
              }
              snprintf(tmp42,0x800,"%s  success write to pic flash\n","_bitmain_pic_write_1704");
              _applog(2,tmp42,false);
              goto LAB_000c584e;
            }
            pcVar4 = "%s read iic 2 err\n";
          }
          else {
            pcVar4 = "%s write iic 2 err\n";
          }
          goto LAB_000c58da;
        }
        pcVar4 = "%s failed 1! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n";
LAB_000c58fe:
        snprintf(tmp42,0x800,pcVar4,"_bitmain_pic_write_1704",uVar9,uVar6);
        _applog(0,tmp42,false);
      }
      else {
        pcVar4 = "%s write iic 1 err\n";
LAB_000c58da:
        snprintf(tmp42,0x800,pcVar4);
        _applog(0,tmp42,false);
      }
LAB_000c584e:
      iVar8 = iVar8 + 1;
      pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
    } while (iVar8 != 0x130);
    iVar2 = reset_pic(which_chain);
    if (iVar2 == 0) {
      return 0;
    }
  }
  pcVar4 = "%s: reset pic error!\n\n";
LAB_000c589c:
  snprintf(tmp42,0x800,pcVar4,"_update_pic_app_program_1704");
  _applog(0,tmp42,false);
  return iVar2;
}

