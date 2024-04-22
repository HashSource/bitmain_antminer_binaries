
int dtls1_write_bytes(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (0x4000 < param_4) {
    OpenSSLDie(DAT_00077b40,0x5cb,DAT_00077b44);
  }
  *(undefined4 *)(param_1 + 0x18) = 1;
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x108) == 0) {
    if (((*(int *)(*(int *)(param_1 + 0x58) + 0x18c) == 0) ||
        (iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x3c))(param_1), 0 < iVar1)) &&
       (iVar1 = param_4, param_4 != 0)) {
      iVar1 = do_dtls1_write_part_2(param_1,param_2,param_3,param_4,0);
    }
    return iVar1;
  }
  OpenSSLDie(DAT_00077b40,0x5e1,DAT_00077b48);
  iVar1 = ssl3_write_pending(param_1,param_2,param_3,param_4);
  return iVar1;
}

