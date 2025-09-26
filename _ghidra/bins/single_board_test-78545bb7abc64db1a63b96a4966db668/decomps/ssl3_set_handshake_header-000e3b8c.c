
int ssl3_set_handshake_header(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0x101) {
    return 1;
  }
  iVar1 = WPACKET_put_bytes__(param_2,1,param_3,param_3 >> 0x1f,1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = WPACKET_start_sub_packet_len__(param_2,3);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

