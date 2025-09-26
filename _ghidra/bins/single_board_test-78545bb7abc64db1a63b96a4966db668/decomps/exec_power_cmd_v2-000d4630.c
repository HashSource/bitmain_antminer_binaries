
/* WARNING: Unknown calling convention */

int32_t exec_power_cmd_v2(int32_t fd,uint8_t *send_data,uint32_t send_data_len,
                         uint8_t *read_back_data,uint32_t read_back_data_len)

{
  byte *pbVar1;
  uint uVar2;
  char cVar3;
  short sVar4;
  uint8_t *puVar5;
  byte *pbVar6;
  uint uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  int32_t iVar10;
  uint8_t reg_addr;
  char tmp42 [2048];
  
  reg_addr = '\x11';
  if ((send_data_len & 1) == 0) {
    if ((read_back_data_len & 1) == 0) {
      pthread_mutex_lock((pthread_mutex_t *)&power_mutex);
      cVar3 = '\x04';
      do {
        uVar7 = 0;
        if (send_data_len != 0) {
          do {
            puVar5 = send_data + uVar7;
            uVar7 = uVar7 + 1 & 0xff;
            iic_write_reg(fd,&reg_addr,1,puVar5,1,false);
          } while (uVar7 < send_data_len);
        }
        usleep(500000);
        if (read_back_data_len == 0) {
          iVar10 = -0x7ffffcff;
          usleep(100000);
        }
        else {
          uVar7 = 0;
          do {
            puVar5 = read_back_data + uVar7;
            uVar7 = uVar7 + 1 & 0xff;
            iic_read_reg(fd,&reg_addr,1,puVar5,1,false);
          } while (uVar7 < read_back_data_len);
          usleep(100000);
          if (read_back_data == (uint8_t *)0x0 || send_data == (uint8_t *)0x0) {
            iVar10 = -0x7ffffcff;
          }
          else {
            sVar4 = 0;
            uVar7 = read_back_data_len - 2;
            if (2 < uVar7) {
              uVar2 = 2;
              pbVar6 = read_back_data;
              do {
                pbVar1 = pbVar6 + 3;
                uVar2 = uVar2 + 2;
                pbVar6 = pbVar6 + 2;
                sVar4 = sVar4 + (ushort)*pbVar6 + (ushort)*pbVar1 * 0x100;
              } while (uVar2 < uVar7);
            }
            if (sVar4 == CONCAT11(read_back_data[read_back_data_len - 1],read_back_data[uVar7])) {
              if ((((*send_data == *read_back_data) && (send_data[1] == read_back_data[1])) &&
                  (send_data[3] == read_back_data[3])) &&
                 (read_back_data_len == read_back_data[2] + 2)) {
                iVar10 = 0;
                break;
              }
            }
            else {
              snprintf(tmp42,0x800,"power reply the bad crc, crc = 0x%04x, crc_read = 0x%04x\n");
              _applog(0,tmp42,false);
            }
            pbVar6 = read_back_data + -1;
            uVar8 = 0;
            do {
              pbVar6 = pbVar6 + 1;
              uVar9 = uVar8 + 1;
              snprintf(tmp42,0x800,"read_back_data[%d] = 0x%02x",uVar8,(uint)*pbVar6);
              _applog(0,tmp42,false);
              uVar8 = uVar9;
            } while (uVar9 != read_back_data_len);
            iVar10 = -0x7ffffd00;
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
      iVar10 = -1;
    }
  }
  else {
    builtin_strncpy(tmp42,"WARNING: exec_power_cmd_v2 only support even len",0x30);
    tmp42[0x30] = '\n';
    tmp42[0x31] = '\0';
    _applog(3,tmp42,false);
    iVar10 = -1;
  }
  return iVar10;
}

