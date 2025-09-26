
undefined4
tls_construct_extensions
          (int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  byte *pbVar4;
  undefined4 uVar5;
  undefined1 auStack_30 [4];
  undefined4 local_2c [2];
  
  local_2c[0] = 0;
  iVar1 = WPACKET_start_sub_packet_len__(param_2,2);
  if ((iVar1 == 0) ||
     (((param_3 & 0x180) != 0 && (iVar1 = WPACKET_set_flags(param_2,2), iVar1 == 0)))) {
    uVar5 = 0x333;
    iVar1 = 0x44;
LAB_000f11f2:
    ossl_statem_fatal(param_1,0x50,0x1bf,iVar1,"ssl/statem/extensions.c",uVar5);
  }
  else {
    if ((param_3 & 0x80) != 0) {
      iVar1 = ssl_get_min_max_version(param_1,auStack_30,local_2c,0);
      if (iVar1 != 0) {
        uVar5 = 0x33b;
        goto LAB_000f11f2;
      }
      custom_ext_init(*(int *)(param_1 + 0x404) + 0xf0);
    }
    iVar1 = custom_ext_add(param_1,param_3,param_2,param_4,param_5,local_2c[0]);
    if (iVar1 != 0) {
      if ((param_3 & 0x6080) == 0) {
        iVar1 = 0x27bc94;
        do {
          HintPreloadData(iVar1);
          iVar2 = should_add_extension(param_1,*(undefined4 *)(iVar1 + -0x80),param_3,local_2c[0]);
          if (iVar2 != 0) {
            pcVar3 = *(code **)(iVar1 + -0x70);
            if (*(int *)(param_1 + 0x1c) == 0) {
              pcVar3 = *(code **)(iVar1 + -0x6c);
            }
            if ((pcVar3 != (code *)0x0) &&
               (iVar2 = (*pcVar3)(param_1,param_2,param_3,param_4,param_5), iVar2 == 0)) {
              return 0;
            }
          }
          iVar1 = iVar1 + 0x20;
        } while (iVar1 != 0x27bfd4);
        iVar1 = WPACKET_close(param_2);
      }
      else {
        pbVar4 = (byte *)(param_1 + 0x514);
        iVar1 = 0x27bc94;
        do {
          HintPreloadData(iVar1);
          iVar2 = should_add_extension(param_1,*(undefined4 *)(iVar1 + -0x80),param_3,local_2c[0]);
          if (iVar2 != 0) {
            pcVar3 = *(code **)(iVar1 + -0x70);
            if (*(int *)(param_1 + 0x1c) == 0) {
              pcVar3 = *(code **)(iVar1 + -0x6c);
            }
            if (pcVar3 != (code *)0x0) {
              iVar2 = (*pcVar3)(param_1,param_2,param_3,param_4,param_5);
              if (iVar2 == 0) {
                return 0;
              }
              if (iVar2 == 1) {
                *pbVar4 = *pbVar4 | 2;
              }
            }
          }
          pbVar4 = pbVar4 + 1;
          iVar1 = iVar1 + 0x20;
        } while (pbVar4 != (byte *)(param_1 + 0x52e));
        iVar1 = WPACKET_close(param_2);
      }
      if (iVar1 == 0) {
        ossl_statem_fatal(param_1,0x50,0x1bf,0x44,"ssl/statem/extensions.c",0x367);
        return 0;
      }
      return 1;
    }
  }
  return 0;
}

