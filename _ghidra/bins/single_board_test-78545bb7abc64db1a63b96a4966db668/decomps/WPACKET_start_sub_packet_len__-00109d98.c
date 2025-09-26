
undefined4 WPACKET_start_sub_packet_len__(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int local_1c [2];
  
  if (param_1[5] == 0) {
    return 0;
  }
  piVar1 = (int *)CRYPTO_zalloc(0x14,"ssl/packet.c",0x119);
  if (piVar1 == (int *)0x0) {
    ERR_put_error(0x14,0x27a,0x41,"ssl/packet.c",0x11a);
    uVar2 = 0;
  }
  else {
    iVar3 = param_1[3];
    *piVar1 = param_1[5];
    param_1[5] = (int)piVar1;
    piVar1[3] = iVar3 + param_2;
    piVar1[2] = param_2;
    if (param_2 != 0) {
      iVar3 = WPACKET_allocate_bytes(param_1,param_2,local_1c);
      if (iVar3 != 0) {
        iVar3 = param_1[1];
        if (iVar3 == 0) {
          iVar3 = *(int *)(*param_1 + 4);
        }
        piVar1[1] = local_1c[0] - iVar3;
        return 1;
      }
      return 0;
    }
    piVar1[1] = 0;
    uVar2 = 1;
  }
  return uVar2;
}

