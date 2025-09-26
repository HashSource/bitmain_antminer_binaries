
/* WARNING: Unknown calling convention */

int32_t exec_power_cmd_v2(int32_t fd,uint8_t *send_data,uint32_t send_data_len,
                         uint8_t *read_back_data,uint32_t read_back_data_len)

{
  byte *pbVar1;
  uint uVar2;
  char cVar3;
  short sVar4;
  uint8_t *puVar5;
  uint uVar6;
  byte *pbVar7;
  int32_t iVar8;
  uint8_t reg_addr;
  char tmp42 [2048];
  
  reg_addr = '\x11';
  if ((send_data_len & 1) == 0) {
    if ((read_back_data_len & 1) == 0) {
      pthread_mutex_lock((pthread_mutex_t *)&power_mutex);
      cVar3 = '\x04';
      do {
        uVar6 = 0;
        if (send_data_len != 0) {
          do {
            puVar5 = send_data + uVar6;
            uVar6 = uVar6 + 1 & 0xff;
            iic_write_reg(fd,&reg_addr,1,puVar5,1,false);
          } while (uVar6 < send_data_len);
        }
        usleep(500000);
        if (read_back_data_len == 0) {
          iVar8 = -0x7ffffcff;
          usleep(100000);
        }
        else {
          uVar6 = 0;
          do {
            puVar5 = read_back_data + uVar6;
            uVar6 = uVar6 + 1 & 0xff;
            iic_read_reg(fd,&reg_addr,1,puVar5,1,false);
          } while (uVar6 < read_back_data_len);
          usleep(100000);
          if (read_back_data == (uint8_t *)0x0 || send_data == (uint8_t *)0x0) {
            iVar8 = -0x7ffffcff;
          }
          else {
            sVar4 = 0;
            uVar6 = read_back_data_len - 2;
            if (2 < uVar6) {
              uVar2 = 2;
              pbVar1 = read_back_data;
              do {
                pbVar7 = pbVar1 + 3;
                uVar2 = uVar2 + 2;
                pbVar1 = pbVar1 + 2;
                sVar4 = sVar4 + (ushort)*pbVar1 + (ushort)*pbVar7 * 0x100;
              } while (uVar2 < uVar6);
            }
            if (CONCAT11((read_back_data + read_back_data_len)[-1],read_back_data[uVar6]) == sVar4)
            {
              if ((((*send_data == *read_back_data) && (send_data[1] == read_back_data[1])) &&
                  (send_data[3] == read_back_data[3])) &&
                 (read_back_data_len == read_back_data[2] + 2)) {
                iVar8 = 0;
                break;
              }
            }
            else {
              snprintf(tmp42,0x800,"power reply the bad crc, crc = 0x%04x, crc_read = 0x%04x\n");
              _applog(0,tmp42,false);
            }
            pbVar1 = read_back_data;
            do {
              pbVar7 = pbVar1 + 1;
              snprintf(tmp42,0x800,"read_back_data[%d] = 0x%02x",(int)pbVar1 - (int)read_back_data,
                       (uint)*pbVar1);
              _applog(0,tmp42,false);
              pbVar1 = pbVar7;
            } while (read_back_data + read_back_data_len != pbVar7);
            iVar8 = -0x7ffffd00;
          }
        }
        cVar3 = cVar3 + -1;
      } while (cVar3 != '\0');
      pthread_mutex_unlock((pthread_mutex_t *)&power_mutex);
    }
    else {
      builtin_strncpy(tmp42,"WARNING: exec_power_cmd_v2 only support even len",0x30);
      tmp42[0x30] = '\n';
      tmp42[0x31] = '\0';
      _applog(3,tmp42,false);
      iVar8 = -1;
    }
  }
  else {
    builtin_strncpy(tmp42,"WARNING: exec_power_cmd_v2 only support even len",0x30);
    tmp42[0x30] = '\n';
    tmp42[0x31] = '\0';
    _applog(3,tmp42,false);
    iVar8 = -1;
  }
  return iVar8;
}

