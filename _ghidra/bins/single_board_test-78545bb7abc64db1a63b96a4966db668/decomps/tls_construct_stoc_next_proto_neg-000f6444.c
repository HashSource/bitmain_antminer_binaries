
undefined4 tls_construct_stoc_next_proto_neg(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x7c) + 0x33c);
  *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x33c) = 0;
  if (iVar1 != 0) {
    pcVar2 = *(code **)(*(int *)(param_1 + 0x4d0) + 0x180);
    if (pcVar2 != (code *)0x0) {
      uVar3 = (*pcVar2)(param_1,&local_18,&local_14,
                        *(undefined4 *)(*(int *)(param_1 + 0x4d0) + 0x184));
      if ((int)uVar3 != 0) {
        return 1;
      }
      iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar3 >> 0x20),0x3374,0,2);
      if ((iVar1 != 0) && (iVar1 = WPACKET_sub_memcpy__(param_2,local_18,local_14,2), iVar1 != 0)) {
        *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x33c) = 1;
        return 1;
      }
      ossl_statem_fatal(param_1,0x50,0x1c9,0x44,"ssl/statem/extensions_srvr.c",0x615);
      return 0;
    }
  }
  return 2;
}

