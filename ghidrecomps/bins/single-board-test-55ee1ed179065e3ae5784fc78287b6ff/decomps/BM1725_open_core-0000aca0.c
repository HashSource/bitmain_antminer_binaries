
void BM1725_open_core(byte param_1)

{
  undefined local_cc;
  undefined local_cb;
  undefined auStack_ca [180];
  undefined local_16;
  undefined local_15;
  uint local_14;
  undefined2 local_e;
  uint local_c;
  
  local_c = 0;
  memset(&local_cc,0,0xb8);
  local_cc = 0xff;
  printf("\n--- %s: Chain : %d\n","BM1725_open_core",(uint)param_1);
  *(undefined *)((int)&gIsOpenCoreEnd + (uint)param_1) = 0;
  *(undefined *)((int)&gIsOpeningCore + (uint)param_1) = 1;
  local_cc = 0x20;
  local_cb = 0x80;
  memset(auStack_ca,0,0xb4);
  local_e = CRC16(&local_cc,0xb6);
  local_16 = (undefined)((ushort)local_e >> 8);
  local_15 = (undefined)local_e;
  for (local_c = 0; local_c < 0x114; local_c = local_c + 1) {
    local_14 = local_c << 0x10 | 0x8201;
    set_BM1725_asic_register(param_1,0,0x24,1,local_14);
    usleep(100);
    dcr_uart_send(param_1,&local_cc,0xb8);
    usleep(Conf._196_4_);
  }
  uart_flush_rx(param_1);
  *(undefined *)((int)&gIsOpeningCore + (uint)param_1) = 0;
  *(undefined *)((int)&gIsOpenCoreEnd + (uint)param_1) = 1;
  return;
}

