
/* WARNING: Unknown calling convention */

int32_t bitmain_power_read_v2(uint8_t addr,uint8_t *buf,uint8_t read_length)

{
  byte *pbVar1;
  int32_t iVar2;
  uint uVar3;
  byte *pbVar4;
  uint8_t *puVar5;
  uint uVar6;
  uint8_t *puVar7;
  uint __c;
  uint8_t cmd [10];
  uint8_t read_back_data [72];
  
  uVar3 = (uint)read_length;
  if (uVar3 < 0x41) {
    __c = addr & 1;
    if ((addr & 1) == 0) {
      cmd[0] = 'U';
      cmd[1] = 0xaa;
      cmd[2] = '\b';
      cmd[3] = '\x06';
      cmd[4] = '\0';
      cmd[5] = '\0';
      cmd[6] = '\0';
      cmd[7] = '\0';
      cmd[8] = '\0';
      cmd[9] = '\0';
      memset(read_back_data,__c,0x48);
      pbVar4 = cmd;
      cmd[5] = (uint8_t)__c;
      cmd[4] = addr;
      cmd[6] = read_length;
      cmd[7] = (uint8_t)__c;
      do {
        pbVar1 = pbVar4 + 3;
        pbVar4 = pbVar4 + 2;
        uVar6 = __c + (uint)*pbVar4 + (uint)*pbVar1 * 0x100;
        __c = uVar6 & 0xffff;
      } while (pbVar4 != cmd + 6);
      cmd._8_2_ = (undefined2)uVar6;
      iVar2 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,10,read_back_data,uVar3 + 8);
      if (iVar2 == 0) {
        iVar2 = 0;
        if (uVar3 != 0) {
          puVar5 = buf + -1;
          puVar7 = read_back_data + 5;
          do {
            puVar7 = puVar7 + 1;
            puVar5 = puVar5 + 1;
            *puVar5 = *puVar7;
          } while (puVar7 != read_back_data + (read_length - 1 & 0xffff) + 6);
          return 0;
        }
      }
      else {
        iVar2 = -1;
      }
    }
    else {
      builtin_memcpy(read_back_data,"read data should start from even address",0x28);
      read_back_data[0x28] = '\n';
      read_back_data[0x29] = '\0';
      _applog(3,(char *)read_back_data,false);
      iVar2 = -1;
    }
  }
  else {
    builtin_memcpy(read_back_data,"read length should less then 64\n",0x20);
    read_back_data._32_4_ = read_back_data._32_4_ & 0xffffff00;
    _applog(3,(char *)read_back_data,false);
    iVar2 = -1;
  }
  return iVar2;
}

