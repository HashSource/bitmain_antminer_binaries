
int dtls1_set_handshake_header(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined1 auStack_14 [4];
  
  if (param_3 == 0x101) {
    iVar1 = *(int *)(param_1 + 0x80);
    *(undefined1 *)(iVar1 + 0x120) = 1;
    *(undefined4 *)(iVar1 + 0x124) = 0;
    *(undefined2 *)(iVar1 + 0x108) = *(undefined2 *)(iVar1 + 0x10a);
    *(undefined2 *)(iVar1 + 0x128) = *(undefined2 *)(iVar1 + 0x10a);
    *(undefined4 *)(iVar1 + 300) = 0;
    *(undefined4 *)(iVar1 + 0x130) = 0;
    iVar1 = WPACKET_put_bytes__(param_2,iVar1,1,0,1);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  dtls1_set_message_header(param_1,param_3 & 0xff,0,0,0);
  iVar1 = WPACKET_allocate_bytes(param_2,0xc,auStack_14);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = WPACKET_start_sub_packet(param_2);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

