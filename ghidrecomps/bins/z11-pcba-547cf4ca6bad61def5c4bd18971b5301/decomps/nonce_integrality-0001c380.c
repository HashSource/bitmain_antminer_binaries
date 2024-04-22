
undefined4 nonce_integrality(byte param_1,byte param_2,int param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  char acStack_41c [1026];
  ushort local_1a;
  void *local_18;
  uint local_14;
  
  for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
    uVar1 = CRC16_v1((uint)param_2 * 0x5b0 + local_14 * 0x5b + param_4 + (uint)param_1 * 0x5b0,0x59)
    ;
    local_1a = uVar1 >> 8 | uVar1 << 8;
    iVar2 = memcmp(&local_1a,
                   (void *)(param_4 + (uint)param_1 * 0x5b0 +
                           (uint)param_2 * 0x5b0 + local_14 * 0x5b + 0x59),2);
    if (iVar2 != 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        snprintf(acStack_41c,0x400,"%s CRC error. cal-crc=%x, chip-crc=%02x%02x\n",
                 "nonce_integrality",(uint)local_1a,
                 (uint)*(byte *)((uint)param_2 * 0x5b0 + local_14 * 0x5b +
                                 param_4 + (uint)param_1 * 0x5b0 + 0x59),
                 (uint)*(byte *)((uint)param_2 * 0x5b0 + local_14 * 0x5b +
                                 param_4 + (uint)param_1 * 0x5b0 + 0x5a));
        _applog(0,acStack_41c,0);
      }
      return 0xffffffff;
    }
  }
  for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
    if ((*(byte *)((uint)param_2 * 0x5b0 + local_14 * 0x5b + param_4 + (uint)param_1 * 0x5b0) & 0xf)
        != local_14) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        snprintf(acStack_41c,0x400,"nonce is not continous i=%d\n",local_14);
        _applog(0,acStack_41c,0);
      }
      return 0xffffffff;
    }
  }
  for (local_14 = 0; (int)local_14 < 0xf; local_14 = local_14 + 1) {
    if (*(char *)((uint)param_2 * 0x5b0 + local_14 * 0x5b + param_4 + (uint)param_1 * 0x5b0 + 1) !=
        *(char *)((uint)param_2 * 0x5b0 + (local_14 + 1) * 0x5b + param_4 + (uint)param_1 * 0x5b0 +
                 1)) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        snprintf(acStack_41c,0x400,"chip_addr is different %02x != %02x\n",
                 (uint)*(byte *)((uint)param_2 * 0x5b0 + local_14 * 0x5b +
                                 param_4 + (uint)param_1 * 0x5b0 + 1),
                 (uint)*(byte *)((uint)param_2 * 0x5b0 + (local_14 + 1) * 0x5b +
                                 param_4 + (uint)param_1 * 0x5b0 + 1));
        _applog(0,acStack_41c,0);
      }
      return 0xffffffff;
    }
  }
  for (local_14 = 0; (int)local_14 < 0xf; local_14 = local_14 + 1) {
    if (*(char *)((uint)param_2 * 0x5b0 + local_14 * 0x5b + param_4 + (uint)param_1 * 0x5b0 + 2) !=
        *(char *)((uint)param_2 * 0x5b0 + (local_14 + 1) * 0x5b + param_4 + (uint)param_1 * 0x5b0 +
                 2)) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        snprintf(acStack_41c,0x400,"workID is different %02x != %02x\n",
                 (uint)*(byte *)((uint)param_2 * 0x5b0 + local_14 * 0x5b +
                                 param_4 + (uint)param_1 * 0x5b0 + 2),
                 (uint)*(byte *)((uint)param_2 * 0x5b0 + (local_14 + 1) * 0x5b +
                                 param_4 + (uint)param_1 * 0x5b0 + 2));
        _applog(0,acStack_41c,0);
      }
      return 0xffffffff;
    }
  }
  local_14 = 0;
  while( true ) {
    if (0xe < (int)local_14) {
      local_18 = (void *)((uint)param_2 * 0x54d + param_3 + (uint)param_1 * 0x54d);
      for (local_14 = 0; (int)local_14 < 0xf; local_14 = local_14 + 1) {
        memcpy(local_18,(void *)((uint)param_2 * 0x5b0 + local_14 * 0x5b + 4 +
                                param_4 + (uint)param_1 * 0x5b0),0x55);
        local_18 = (void *)((int)local_18 + 0x55);
      }
      memcpy(local_18,(void *)((uint)param_2 * 0x5b0 + 0x559 + param_4 + (uint)param_1 * 0x5b0),0x45
            );
      memcpy((void *)(param_3 + (uint)param_1 * 0x54d + (uint)param_2 * 0x54d + 0x548),
             (void *)((uint)param_2 * 0x5b0 + 0x5aa + param_4 + (uint)param_1 * 0x5b0),4);
      *(undefined *)((uint)param_2 * 0x54d + param_3 + (uint)param_1 * 0x54d + 0x540) =
           *(undefined *)((uint)param_2 * 0x5b0 + param_4 + (uint)param_1 * 0x5b0 + 0x556);
      *(undefined *)((uint)param_2 * 0x54d + param_3 + (uint)param_1 * 0x54d + 0x541) =
           *(undefined *)((uint)param_2 * 0x5b0 + param_4 + (uint)param_1 * 0x5b0 + 0x557);
      *(undefined *)((uint)param_2 * 0x54d + param_3 + (uint)param_1 * 0x54d + 0x542) =
           *(undefined *)((uint)param_2 * 0x5b0 + param_4 + (uint)param_1 * 0x5b0 + 0x558);
      *(undefined *)((uint)param_2 * 0x54d + param_3 + (uint)param_1 * 0x54d + 0x543) =
           *(undefined *)((uint)param_2 * 0x5b0 + param_4 + (uint)param_1 * 0x5b0 + 0x5a1);
      memcpy((void *)((uint)param_2 * 0x54d + param_3 + (uint)param_1 * 0x54d + 0x544),
             (void *)((uint)param_2 * 0x5b0 + 0x5a2 + param_4 + (uint)param_1 * 0x5b0),4);
      return 0;
    }
    if (*(char *)((uint)param_2 * 0x5b0 + local_14 * 0x5b + param_4 + (uint)param_1 * 0x5b0 + 3) !=
        *(char *)((uint)param_2 * 0x5b0 + (local_14 + 1) * 0x5b + param_4 + (uint)param_1 * 0x5b0 +
                 3)) break;
    local_14 = local_14 + 1;
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
    snprintf(acStack_41c,0x400,"nonceID is different %02x != %02x chipid=%d\n",
             (uint)*(byte *)((uint)param_2 * 0x5b0 + local_14 * 0x5b +
                             param_4 + (uint)param_1 * 0x5b0 + 3),
             (uint)*(byte *)((uint)param_2 * 0x5b0 + (local_14 + 1) * 0x5b +
                             param_4 + (uint)param_1 * 0x5b0 + 3),(uint)param_1);
    _applog(0,acStack_41c,0);
  }
  return 0xffffffff;
}

