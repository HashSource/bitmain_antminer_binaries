
undefined4 tls_construct_ctos_supported_groups(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  uint uVar4;
  undefined8 uVar5;
  int local_28;
  uint local_24 [2];
  
  uVar4 = 0;
  local_28 = 0;
  local_24[0] = 0;
  iVar2 = use_ecc();
  if (iVar2 == 0) {
    return 2;
  }
  tls1_get_supported_groups(param_1,&local_28,local_24);
  iVar2 = WPACKET_put_bytes__(param_2,extraout_r1,10,0,2);
  if (((iVar2 == 0) || (iVar2 = WPACKET_start_sub_packet_len__(param_2,2), iVar2 == 0)) ||
     (iVar2 = WPACKET_start_sub_packet_len__(param_2,2), iVar2 == 0)) {
    uVar3 = 0xcf;
  }
  else {
    if (local_24[0] != 0) {
      do {
        uVar1 = *(undefined2 *)(local_28 + uVar4 * 2);
        uVar4 = uVar4 + 1;
        uVar5 = tls_curve_allowed(param_1,uVar1,0x20004);
        if (((int)uVar5 != 0) &&
           (iVar2 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar5 >> 0x20),uVar1,0,2),
           iVar2 == 0)) {
          uVar3 = 0xda;
          goto LAB_000e7e4c;
        }
      } while (uVar4 < local_24[0]);
    }
    iVar2 = WPACKET_close(param_2);
    if ((iVar2 != 0) && (iVar2 = WPACKET_close(param_2), iVar2 != 0)) {
      return 1;
    }
    uVar3 = 0xe2;
  }
LAB_000e7e4c:
  ossl_statem_fatal(param_1,0x50,0x1e0,0x44,"ssl/statem/extensions_clnt.c",uVar3);
  return 0;
}

