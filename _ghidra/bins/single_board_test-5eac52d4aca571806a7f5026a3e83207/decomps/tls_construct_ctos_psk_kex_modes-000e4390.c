
undefined4 tls_construct_ctos_psk_kex_modes(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = *(uint *)(param_1 + 0x4ec);
  iVar1 = WPACKET_put_bytes__(param_2,param_2,0x2d,0,2);
  if ((iVar1 != 0) && (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 != 0)) {
    uVar3 = WPACKET_start_sub_packet_len__(param_2,1);
    if ((int)uVar3 != 0) {
      uVar3 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar3 >> 0x20),1,0,1);
      if ((((int)uVar3 != 0) &&
          (((uVar2 = uVar2 & 0x400, uVar2 == 0 ||
            (iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar3 >> 0x20),0,0,1), iVar1 != 0)
            ) && (iVar1 = WPACKET_close(param_2), iVar1 != 0)))) &&
         (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
        if (uVar2 != 0) {
          *(undefined4 *)(param_1 + 0x5a4) = 3;
          return 1;
        }
        *(undefined4 *)(param_1 + 0x5a4) = 2;
        return 1;
      }
    }
  }
  ossl_statem_fatal(param_1,0x50,0x1fd,0x44,"ssl/statem/extensions_clnt.c",0x24a);
  return 0;
}

