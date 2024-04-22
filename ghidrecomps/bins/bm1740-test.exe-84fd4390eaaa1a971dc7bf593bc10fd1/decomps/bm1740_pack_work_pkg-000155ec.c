
undefined4 bm1740_pack_work_pkg(undefined *param_1,int param_2)

{
  undefined4 uVar1;
  char acStack_110 [258];
  ushort local_e;
  undefined *local_c;
  
  if (param_2 == 0x92) {
    param_1[2] = param_1[2] & 0x1f | 0x20;
    *param_1 = 0x55;
    param_1[1] = 0xaa;
    local_c = param_1;
    local_e = CRC16(param_1 + 2,0x8e);
    *(ushort *)(local_c + 0x90) = local_e >> 8 | (ushort)((local_e & 0xff) << 8);
    if (g_crc16_err_enable != 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf(acStack_110,0x100,"true crc16 = %x\n",(uint)*(ushort *)(local_c + 0x90));
        _applog(3,acStack_110,0);
      }
      *(short *)(local_c + 0x90) = *(short *)(local_c + 0x90) + 1;
    }
    uVar1 = 0x92;
  }
  else {
    printf("%s wrong work\n","bm1740_pack_work_pkg");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

