
int do_dtls1_write(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x108) != 0) {
    OpenSSLDie(DAT_00077bb4,0x5e1,DAT_00077bb8);
    iVar1 = ssl3_write_pending(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  if ((*(int *)(*(int *)(param_1 + 0x58) + 0x18c) != 0) &&
     (iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x3c))(), iVar1 < 1)) {
    return iVar1;
  }
  if (param_5 != 0 || param_4 != 0) {
    iVar1 = do_dtls1_write_part_2(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  return 0;
}

