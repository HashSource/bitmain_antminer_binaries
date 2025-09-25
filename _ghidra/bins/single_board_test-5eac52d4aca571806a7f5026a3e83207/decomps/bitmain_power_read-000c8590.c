
/* WARNING: Unknown calling convention */

int32_t bitmain_power_read(uint8_t addr,uint8_t *buf,uint8_t read_length)

{
  int32_t iVar1;
  uint uVar2;
  uint8_t *puVar3;
  int iVar4;
  uint8_t *puVar5;
  int32_t iVar6;
  uint8_t send_data [8];
  uint8_t read_back_data [50];
  char tmp42 [2048];
  
  uVar2 = (uint)read_length;
  iVar6 = 0;
  memset(read_back_data,0,0x32);
  iVar4 = addr + uVar2 + 0xc;
  send_data[6] = (uint8_t)iVar4;
  send_data[7] = (uint8_t)((uint)iVar4 >> 8);
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x06';
  send_data[3] = '\x06';
  send_data[4] = addr;
  send_data[5] = read_length;
  if ((_g_power_state.power_open == 0) && (iVar6 = bitmain_power_open(), iVar6 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec bitmain_power_open, but open power failed\n",
             "bitmain_power_read");
    _applog(0,tmp42,false);
  }
  else {
    iVar1 = exec_power_cmd(_g_power_state.power_fd,send_data,8,read_back_data,uVar2 + 7);
    if (iVar1 == 0) {
      if (uVar2 != 0) {
        puVar3 = buf + -1;
        puVar5 = read_back_data + 4;
        do {
          puVar5 = puVar5 + 1;
          puVar3 = puVar3 + 1;
          *puVar3 = *puVar5;
        } while (puVar5 != read_back_data + (uVar2 - 1 & 0xff) + 5);
      }
    }
    else {
      builtin_strncpy(tmp42,"set DA conversion N failed\n",0x1c);
      _applog(0,tmp42,false);
      iVar6 = -0x7ffffd00;
    }
  }
  return iVar6;
}

