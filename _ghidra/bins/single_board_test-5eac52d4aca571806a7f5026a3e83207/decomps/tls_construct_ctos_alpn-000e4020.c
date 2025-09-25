
undefined4 tls_construct_ctos_alpn(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x594);
  iVar3 = *(int *)(param_1 + 0x7c);
  *(undefined4 *)(iVar3 + 0x350) = 0;
  if ((iVar2 == 0) || ((*(int *)(iVar3 + 0x180) != 0 && (*(int *)(iVar3 + 0x204) != 0)))) {
    uVar1 = 2;
  }
  else {
    iVar2 = WPACKET_put_bytes__(param_2,param_2,0x10,0,2);
    if ((iVar2 == 0) ||
       (((iVar2 = WPACKET_start_sub_packet_len__(param_2,2), iVar2 == 0 ||
         (iVar2 = WPACKET_sub_memcpy__
                            (param_2,*(undefined4 *)(param_1 + 0x594),
                             *(undefined4 *)(param_1 + 0x598),2), iVar2 == 0)) ||
        (iVar2 = WPACKET_close(param_2), iVar2 == 0)))) {
      ossl_statem_fatal(param_1,0x50,0x1d2,0x44,"ssl/statem/extensions_clnt.c",0x1a0);
      return 0;
    }
    uVar1 = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x350) = 1;
  }
  return uVar1;
}

