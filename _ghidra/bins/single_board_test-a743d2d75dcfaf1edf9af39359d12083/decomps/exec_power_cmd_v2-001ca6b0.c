
/* WARNING: Unknown calling convention */

int32_t exec_power_cmd_v2(int32_t fd,uint8_t *send_data,uint32_t send_data_len,
                         uint8_t *read_back_data,uint32_t read_back_data_len)

{
  undefined4 uVar1;
  byte *pbVar2;
  uint uVar3;
  char cVar4;
  short sVar5;
  uint8_t *puVar6;
  uint uVar7;
  byte *pbVar8;
  int32_t iVar9;
  uint8_t reg_addr;
  char tmp42 [2048];
  
  reg_addr = '\x11';
  if ((send_data_len & 1) == 0) {
    if ((read_back_data_len & 1) == 0) {
      pthread_mutex_lock((pthread_mutex_t *)&power_mutex);
      cVar4 = '\x04';
      do {
        uVar7 = 0;
        if (send_data_len != 0) {
          do {
            puVar6 = send_data + uVar7;
            uVar7 = uVar7 + 1 & 0xff;
            iic_write_reg(fd,&reg_addr,1,puVar6,1,false);
          } while (uVar7 < send_data_len);
        }
        usleep(500000);
        if (read_back_data_len == 0) {
          iVar9 = -0x7ffffcff;
          usleep(100000);
        }
        else {
          uVar7 = 0;
          do {
            puVar6 = read_back_data + uVar7;
            uVar7 = uVar7 + 1 & 0xff;
            iic_read_reg(fd,&reg_addr,1,puVar6,1,false);
          } while (uVar7 < read_back_data_len);
          usleep(100000);
          uVar1 = tmp42._24_4_;
          if (read_back_data == (uint8_t *)0x0 || send_data == (uint8_t *)0x0) {
            iVar9 = -0x7ffffcff;
          }
          else {
            sVar5 = 0;
            uVar7 = read_back_data_len - 2;
            if (2 < uVar7) {
              uVar3 = 2;
              pbVar2 = read_back_data;
              do {
                pbVar8 = pbVar2 + 3;
                uVar3 = uVar3 + 2;
                pbVar2 = pbVar2 + 2;
                sVar5 = sVar5 + (ushort)*pbVar2 + (ushort)*pbVar8 * 0x100;
              } while (uVar3 < uVar7);
            }
            if (CONCAT11((read_back_data + read_back_data_len)[-1],read_back_data[uVar7]) == sVar5)
            {
              if ((((*send_data == *read_back_data) && (send_data[1] == read_back_data[1])) &&
                  (send_data[3] == read_back_data[3])) &&
                 (read_back_data_len == read_back_data[2] + 2)) {
                iVar9 = 0;
                break;
              }
              builtin_strncpy(tmp42,"power reply the bad data\n",0x1a);
              tmp42._26_2_ = SUB42(uVar1,2);
              _applog(0,tmp42,false);
            }
            else {
              snprintf(tmp42,0x800,"power reply the bad crc, crc = 0x%04x, crc_read = 0x%04x\n");
              _applog(0,tmp42,false);
            }
            pbVar2 = read_back_data;
            do {
              pbVar8 = pbVar2 + 1;
              snprintf(tmp42,0x800,"read_back_data[%d] = 0x%02x",(int)pbVar2 - (int)read_back_data,
                       (uint)*pbVar2);
              _applog(0,tmp42,false);
              pbVar2 = pbVar8;
            } while (read_back_data + read_back_data_len != pbVar8);
            iVar9 = -0x7ffffd00;
          }
        }
        cVar4 = cVar4 + -1;
      } while (cVar4 != '\0');
      pthread_mutex_unlock((pthread_mutex_t *)&power_mutex);
    }
    else {
      builtin_strncpy(tmp42,"WARNING: exec_power_cmd_v2 only support even len",0x30);
      tmp42[0x30] = '\n';
      tmp42[0x31] = '\0';
      _applog(3,tmp42,false);
      iVar9 = -1;
    }
  }
  else {
    builtin_strncpy(tmp42,"WARNING: exec_power_cmd_v2 only support even len",0x30);
    tmp42[0x30] = '\n';
    tmp42[0x31] = '\0';
    _applog(3,tmp42,false);
    iVar9 = -1;
  }
  return iVar9;
}

