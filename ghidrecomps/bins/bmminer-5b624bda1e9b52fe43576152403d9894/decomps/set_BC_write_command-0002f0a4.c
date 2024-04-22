
/* WARNING: Unknown calling convention */

void set_BC_write_command(uint value)

{
  int iVar1;
  int iVar2;
  char logstr [256];
  
  *(uint *)(*(int *)(DAT_0002f0f8 + 0x8d4) + 0xc0) = value;
  if ((int)value < 0) {
    iVar2 = 0xbb9;
    do {
      iVar1 = get_BC_write_command();
      if (-1 < iVar1) {
        return;
      }
      cgsleep_ms(1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    logstr._0_4_ = *DAT_0002f0fc;
    logstr._4_4_ = DAT_0002f0fc[1];
    logstr._8_4_ = DAT_0002f0fc[2];
    logstr._12_4_ = DAT_0002f0fc[3];
    logstr._16_4_ = DAT_0002f0fc[4];
    logstr._20_4_ = DAT_0002f0fc[5];
    logstr._24_4_ = DAT_0002f0fc[6];
    logstr._28_4_ = DAT_0002f0fc[7];
    logstr._32_4_ = DAT_0002f0fc[8];
    logstr._36_4_ = DAT_0002f0fc[9];
    logstr._40_4_ = DAT_0002f0fc[10];
    logstr._44_4_ = DAT_0002f0fc[0xb];
    logstr._48_4_ = DAT_0002f0fc[0xc];
    logstr._52_4_ = DAT_0002f0fc[0xd];
    writeInitLogFile(logstr);
  }
  else {
    get_BC_write_command();
  }
  return;
}

