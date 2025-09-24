
undefined4 tls_close_construct_packet(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int local_14 [2];
  
  if ((((param_3 == 0x101) || (iVar1 = WPACKET_close(param_2), iVar1 != 0)) &&
      (iVar1 = WPACKET_get_length(param_2,local_14), iVar1 != 0)) && (-1 < local_14[0])) {
    *(int *)(param_1 + 0x74) = local_14[0];
    *(undefined4 *)(param_1 + 0x78) = 0;
    return 1;
  }
  return 0;
}

