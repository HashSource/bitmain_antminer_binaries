
uint bm1740_verify_nonce_integrality(void *param_1)

{
  ushort uVar1;
  int iVar2;
  char acStack_134 [258];
  ushort local_32;
  int local_30;
  void *local_2c;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_14 = 0;
  for (local_18 = 0; (int)local_18 < 0x10; local_18 = local_18 + 1) {
    uVar1 = CRC16(g_nonce_list + local_18 * 0x5b,0x59);
    local_32 = uVar1 >> 8 | (ushort)((uVar1 & 0xff) << 8);
    iVar2 = memcmp(&local_32,g_nonce_list + local_18 * 0x5b + 0x59,2);
    if (iVar2 != 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        snprintf(acStack_134,0x100,"%s CRC error. cal-crc=%x, chip-crc=%x\n",
                 "bm1740_verify_nonce_integrality",(uint)local_32,
                 (uint)(byte)g_nonce_list[local_18 * 0x5b + 0x59]);
        _applog(0,acStack_134,0);
      }
      local_14 = 1 << (local_18 & 0xff) | local_14;
    }
  }
  for (local_1c = 0; (int)local_1c < 0x10; local_1c = local_1c + 1) {
    if (((byte)g_nonce_list[local_1c * 0x5b] & 0xf) != local_1c) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        snprintf(acStack_134,0x100,"nonce is not continous i=%d\n",local_1c);
        _applog(0,acStack_134,0);
      }
      return 0xffffffff;
    }
  }
  for (local_20 = 0; local_20 < 0xf; local_20 = local_20 + 1) {
    if (g_nonce_list[local_20 * 0x5b + 1] != g_nonce_list[(local_20 + 1) * 0x5b + 1]) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        snprintf(acStack_134,0x100,"chip_addr is different %02x != %02x\n",
                 (uint)(byte)g_nonce_list[local_20 * 0x5b + 1],
                 (uint)(byte)g_nonce_list[(local_20 + 1) * 0x5b + 1]);
        _applog(0,acStack_134,0);
      }
      return 0xffffffff;
    }
  }
  for (local_24 = 0; local_24 < 0xf; local_24 = local_24 + 1) {
    if (g_nonce_list[local_24 * 0x5b + 2] != g_nonce_list[(local_24 + 1) * 0x5b + 2]) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        snprintf(acStack_134,0x100,"workID is different %02x != %02x\n",
                 (uint)(byte)g_nonce_list[local_24 * 0x5b + 2],
                 (uint)(byte)g_nonce_list[(local_24 + 1) * 0x5b + 2]);
        _applog(0,acStack_134,0);
      }
      return 0xffffffff;
    }
  }
  local_28 = 0;
  while( true ) {
    if (0xe < local_28) {
      local_2c = param_1;
      for (local_30 = 0; local_30 < 0xf; local_30 = local_30 + 1) {
        memcpy(local_2c,g_nonce_list + local_30 * 0x5b + 4,0x55);
        local_2c = (void *)((int)local_2c + 0x55);
      }
      memcpy(local_2c,DAT_00013608,0x45);
      memcpy((void *)((int)param_1 + 0x548),DAT_0001360c,4);
      *(undefined *)((int)param_1 + 0x540) = g_nonce_list[1366];
      *(undefined *)((int)param_1 + 0x541) = g_nonce_list[1367];
      *(undefined *)((int)param_1 + 0x542) = g_nonce_list[1368];
      *(undefined *)((int)param_1 + 0x543) = g_nonce_list[1441];
      memcpy((void *)((int)param_1 + 0x544),DAT_00013610,4);
      return local_14;
    }
    if (g_nonce_list[local_28 * 0x5b + 3] != g_nonce_list[(local_28 + 1) * 0x5b + 3]) break;
    local_28 = local_28 + 1;
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
    snprintf(acStack_134,0x100,"nonceID is different %02x != %02x\n",
             (uint)(byte)g_nonce_list[local_28 * 0x5b + 3],
             (uint)(byte)g_nonce_list[(local_28 + 1) * 0x5b + 3]);
    _applog(0,acStack_134,0);
  }
  return 0xffffffff;
}

