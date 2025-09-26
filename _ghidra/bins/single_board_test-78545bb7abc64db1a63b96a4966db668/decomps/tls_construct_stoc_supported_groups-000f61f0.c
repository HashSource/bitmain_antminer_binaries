
undefined4 tls_construct_stoc_supported_groups(int param_1,undefined4 param_2)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined8 uVar8;
  int local_28;
  uint local_24;
  
  if (*(short *)(*(int *)(param_1 + 0x7c) + 0x356) == 0) {
    return 2;
  }
  tls1_get_supported_groups(param_1,&local_28,&local_24);
  if (local_24 == 0) {
    uVar6 = 0x592;
LAB_000f62ce:
    uVar5 = 0;
    ossl_statem_fatal(param_1,0x50,0x220,0x44,"ssl/statem/extensions_srvr.c",uVar6);
  }
  else {
    bVar3 = true;
    uVar7 = 0;
    do {
      sVar2 = *(short *)(local_28 + uVar7 * 2);
      uVar7 = uVar7 + 1;
      uVar8 = tls_curve_allowed(param_1,sVar2,0x20004);
      uVar6 = (undefined4)((ulonglong)uVar8 >> 0x20);
      if ((int)uVar8 != 0) {
        if (bVar3) {
          sVar1 = *(short *)(*(int *)(param_1 + 0x7c) + 0x356);
          if (sVar1 == sVar2) {
            return 2;
          }
          iVar4 = WPACKET_put_bytes__(param_2,sVar1,10,0,2);
          if ((iVar4 != 0) && (iVar4 = WPACKET_start_sub_packet_len__(param_2,2), iVar4 != 0)) {
            uVar8 = WPACKET_start_sub_packet_len__(param_2,2);
            uVar6 = (undefined4)((ulonglong)uVar8 >> 0x20);
            if ((int)uVar8 != 0) goto LAB_000f626e;
          }
          uVar6 = 0x5aa;
          goto LAB_000f62a2;
        }
LAB_000f626e:
        iVar4 = WPACKET_put_bytes__(param_2,uVar6,sVar2,0,2);
        bVar3 = false;
        if (iVar4 == 0) {
          uVar6 = 0x5b3;
          goto LAB_000f62ce;
        }
      }
    } while (uVar7 < local_24);
    iVar4 = WPACKET_close(param_2);
    if ((iVar4 == 0) || (iVar4 = WPACKET_close(param_2), iVar4 == 0)) {
      uVar6 = 0x5bc;
LAB_000f62a2:
      ossl_statem_fatal(param_1,0x50,0x220,0x44,"ssl/statem/extensions_srvr.c",uVar6);
      uVar5 = 0;
    }
    else {
      uVar5 = 1;
    }
  }
  return uVar5;
}

