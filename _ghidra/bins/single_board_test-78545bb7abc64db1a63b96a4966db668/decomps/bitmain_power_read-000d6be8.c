
/* WARNING: Unknown calling convention */

int32_t bitmain_power_read(uint8_t addr,uint8_t *buf,uint8_t read_length)

{
  int32_t iVar1;
  uint uVar2;
  int iVar3;
  uint8_t *puVar4;
  uint8_t *puVar5;
  int32_t iVar6;
  uint8_t send_data [8];
  uint8_t read_back_data [50];
  char tmp42 [2048];
  
  uVar2 = (uint)read_length;
  iVar3 = addr + uVar2 + 0xc;
  iVar6 = 0;
  read_back_data[8] = '\0';
  read_back_data[9] = '\0';
  read_back_data[10] = '\0';
  read_back_data[0xb] = '\0';
  read_back_data[0xc] = '\0';
  read_back_data[0xd] = '\0';
  read_back_data[0xe] = '\0';
  read_back_data[0xf] = '\0';
  read_back_data[0x10] = '\0';
  read_back_data[0x11] = '\0';
  read_back_data[0x12] = '\0';
  read_back_data[0x13] = '\0';
  read_back_data[0x14] = '\0';
  read_back_data[0x15] = '\0';
  read_back_data[0x16] = '\0';
  read_back_data[0x17] = '\0';
  read_back_data[0x18] = '\0';
  read_back_data[0x19] = '\0';
  read_back_data[0x1a] = '\0';
  read_back_data[0x1b] = '\0';
  read_back_data[0x1c] = '\0';
  read_back_data[0x1d] = '\0';
  read_back_data[0x1e] = '\0';
  read_back_data[0x1f] = '\0';
  read_back_data[0x20] = '\0';
  read_back_data[0x21] = '\0';
  read_back_data[0x22] = '\0';
  read_back_data[0x23] = '\0';
  read_back_data[0x24] = '\0';
  read_back_data[0x25] = '\0';
  read_back_data[0x26] = '\0';
  read_back_data[0x27] = '\0';
  read_back_data[0x28] = '\0';
  read_back_data[0x29] = '\0';
  read_back_data[0x2a] = '\0';
  read_back_data[0x2b] = '\0';
  read_back_data[0x2c] = '\0';
  read_back_data[0x2d] = '\0';
  read_back_data[0x2e] = '\0';
  read_back_data[0x2f] = '\0';
  read_back_data[0x30] = '\0';
  read_back_data[0x31] = '\0';
  send_data[6] = (uint8_t)iVar3;
  send_data[7] = (uint8_t)((uint)iVar3 >> 8);
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  read_back_data[0] = '\0';
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
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
        puVar5 = buf + -1;
        puVar4 = read_back_data + 4;
        do {
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
          *puVar5 = *puVar4;
        } while (puVar5 != buf + (uVar2 - 1 & 0xff));
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

