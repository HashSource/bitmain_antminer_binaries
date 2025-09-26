
undefined4
create_ticket_prequel(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = *(int **)(param_1 + 4);
  iVar2 = *(int *)(*(int *)(param_1 + 0x474) + 0x1ac);
  if (*(int *)(piVar1[0x19] + 0x30) << 0x1c < 0) {
LAB_000ff9ca:
    if (*(int *)(param_1 + 0x8c) != 0) {
      iVar2 = 0;
    }
  }
  else {
    iVar3 = *piVar1;
    piVar1 = (int *)(uint)(0x303 < iVar3);
    if (iVar3 == 0x10000) {
      piVar1 = (int *)0x0;
    }
    if (piVar1 == (int *)0x0) goto LAB_000ff9ca;
    if (0x93a7f < iVar2) {
      iVar2 = 0x93a80;
    }
  }
  iVar2 = WPACKET_put_bytes__(param_2,piVar1,iVar2,0,4);
  if (iVar2 != 0) {
    if ((((*(uint *)((*(int **)(param_1 + 4))[0x19] + 0x30) & 8) == 0) &&
        (iVar2 = **(int **)(param_1 + 4), iVar2 != 0x10000 && 0x303 < iVar2)) &&
       ((iVar2 = WPACKET_put_bytes__(param_2,iVar2 != 0x10000 && 0x303 < iVar2,param_3,0,4),
        iVar2 == 0 || (iVar2 = WPACKET_sub_memcpy__(param_2,param_4,8,1), iVar2 == 0)))) {
      uVar4 = 0;
      ossl_statem_fatal(param_1,0x50,0x27e,0x44,"ssl/statem/statem_srvr.c",0xf0a);
    }
    else {
      iVar2 = WPACKET_start_sub_packet_len__(param_2,2);
      if (iVar2 == 0) {
        uVar4 = 0xf12;
        goto LAB_000ffa46;
      }
      uVar4 = 1;
    }
    return uVar4;
  }
  uVar4 = 0xf02;
LAB_000ffa46:
  ossl_statem_fatal(param_1,0x50,0x27e,0x44,"ssl/statem/statem_srvr.c",uVar4);
  return 0;
}

