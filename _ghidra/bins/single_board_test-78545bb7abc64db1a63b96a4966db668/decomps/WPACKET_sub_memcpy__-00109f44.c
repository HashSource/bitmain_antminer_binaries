
int WPACKET_sub_memcpy__
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = WPACKET_start_sub_packet_len__(param_1,param_4);
  if ((iVar1 != 0) && (iVar1 = WPACKET_memcpy(param_1,param_2,param_3), iVar1 != 0)) {
    iVar1 = WPACKET_close(param_1);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  return 0;
}

