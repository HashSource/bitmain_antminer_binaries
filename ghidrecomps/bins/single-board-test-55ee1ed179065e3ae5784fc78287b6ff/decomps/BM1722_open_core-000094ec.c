
void BM1722_open_core(byte param_1)

{
  undefined local_cc;
  undefined local_cb;
  undefined auStack_ca [180];
  undefined local_16;
  undefined local_15;
  undefined2 local_12;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  memset(&local_cc,0,0xb8);
  local_cc = 0xff;
  printf("\n--- %s: Chain : %d\n","BM1722_open_core",(uint)param_1);
  *(undefined *)((int)&gIsOpenCoreEnd + (uint)param_1) = 0;
  *(undefined *)((int)&gIsOpeningCore + (uint)param_1) = 1;
  local_cc = 0x20;
  local_cb = 0;
  memset(auStack_ca,0,0xb4);
  local_12 = CRC16(&local_cc,0xb6);
  local_16 = (undefined)((ushort)local_12 >> 8);
  local_15 = (undefined)local_12;
  for (local_c = 0; local_c < (uint)Conf._112_4_; local_c = local_c + 1) {
    if (local_c < 0x20) {
      if (local_c == 0) {
        local_10 = 0;
      }
      local_10 = local_10 << 1 | 1;
      set_BM1722_asic_register(param_1,0,0x50,1,local_10);
    }
    else if ((local_c < 0x40) && (0x1f < local_c)) {
      if (local_c == 0x20) {
        local_10 = 0;
      }
      local_10 = local_10 << 1 | 1;
      set_BM1722_asic_register(param_1,0,0x54,1,local_10);
    }
    else if ((local_c < 0x60) && (0x3f < local_c)) {
      if (local_c == 0x40) {
        local_10 = 0;
      }
      local_10 = local_10 << 1 | 1;
      set_BM1722_asic_register(param_1,0,0x58,1,local_10);
    }
    else if ((local_c < 0x80) && (0x5f < local_c)) {
      if (local_c == 0x60) {
        local_10 = 0;
      }
      local_10 = local_10 << 1 | 1;
      set_BM1722_asic_register(param_1,0,0x5c,1,local_10);
    }
    dcr_uart_send(param_1,&local_cc,0xb8);
    usleep(Conf._196_4_);
  }
  uart_flush_rx(param_1);
  *(undefined *)((int)&gIsOpeningCore + (uint)param_1) = 0;
  *(undefined *)((int)&gIsOpenCoreEnd + (uint)param_1) = 1;
  return;
}

