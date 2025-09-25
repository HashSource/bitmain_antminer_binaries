
uint dtls1_close_construct_packet(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int local_14;
  
  if ((((param_3 == 0x101) || (iVar1 = WPACKET_close(param_2), iVar1 != 0)) &&
      (iVar1 = WPACKET_get_length(param_2,&local_14), iVar1 != 0)) && (-1 < local_14)) {
    if (param_3 == 0x101) {
      *(int *)(param_1 + 0x74) = local_14;
      *(undefined4 *)(param_1 + 0x78) = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x80);
      *(int *)(iVar1 + 0x124) = local_14 + -0xc;
      *(int *)(iVar1 + 0x130) = local_14 + -0xc;
      *(undefined4 *)(param_1 + 0x78) = 0;
      *(int *)(param_1 + 0x74) = local_14;
      if (param_3 == 3) {
        return (uint)(param_3 == 3);
      }
    }
    uVar2 = dtls1_buffer_message(param_1,param_3 == 0x101);
    if (uVar2 != 0) {
      uVar2 = 1;
    }
    return uVar2;
  }
  return 0;
}

