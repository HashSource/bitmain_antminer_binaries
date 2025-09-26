
int ssl3_final_finish_mac(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ssl3_handshake_mac(param_1,4,param_2,param_3,param_4);
  if ((iVar1 != 0) &&
     (iVar2 = ssl3_handshake_mac(param_1,0x40,param_2,param_3,param_4 + iVar1), iVar2 != 0)) {
    return iVar1 + iVar2;
  }
  return 0;
}

