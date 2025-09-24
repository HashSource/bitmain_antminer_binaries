
undefined4 tls_construct_ctos_supported_versions(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined8 uVar6;
  int local_28;
  int local_24;
  
  uVar6 = ssl_get_min_max_version(param_1,&local_28,&local_24,0);
  iVar1 = (int)uVar6;
  if (iVar1 != 0) {
    uVar2 = 0x212;
    goto LAB_000e8526;
  }
  if (local_24 < 0x304) {
    return 2;
  }
  iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar6 >> 0x20),0x2b,0,2);
  if ((iVar1 == 0) || (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 == 0)) {
LAB_000e8554:
    uVar2 = 0x222;
  }
  else {
    uVar6 = WPACKET_start_sub_packet_len__(param_2,1);
    uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
    if ((int)uVar6 == 0) goto LAB_000e8554;
    if (local_28 <= local_24) {
      iVar1 = local_24;
      iVar3 = local_24;
      iVar4 = local_24 >> 0x1f;
      do {
        bVar5 = iVar3 != 0;
        iVar1 = iVar1 + -1;
        uVar6 = WPACKET_put_bytes__(param_2,uVar2,iVar3,iVar4,2);
        uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
        if ((int)uVar6 == 0) {
          uVar2 = 0x22a;
          goto LAB_000e855c;
        }
        iVar3 = iVar3 + -1;
        iVar4 = iVar4 + -1 + (uint)bVar5;
      } while (local_28 <= iVar1);
    }
    iVar1 = WPACKET_close(param_2);
    if ((iVar1 != 0) && (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
      return 1;
    }
    uVar2 = 0x231;
  }
LAB_000e855c:
  iVar1 = 0x44;
LAB_000e8526:
  ossl_statem_fatal(param_1,0x50,0x1e1,iVar1,"ssl/statem/extensions_clnt.c",uVar2);
  return 0;
}

