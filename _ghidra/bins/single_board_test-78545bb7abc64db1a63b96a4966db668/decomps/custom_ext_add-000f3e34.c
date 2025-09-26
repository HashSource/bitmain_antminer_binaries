
undefined4
custom_ext_add(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
              undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  undefined8 uVar8;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c [2];
  
  iVar6 = *(int *)(param_1 + 0x404);
  if (*(int *)(iVar6 + 0xf4) != 0) {
    uVar4 = 0;
    do {
      iVar1 = *(int *)(iVar6 + 0xf0);
      iVar5 = iVar1 + uVar4 * 0x24;
      local_30 = 0;
      local_2c[0] = 0;
      uVar8 = should_add_extension(param_1,*(undefined4 *)(iVar5 + 8),param_2,param_6);
      iVar2 = (int)((ulonglong)uVar8 >> 0x20);
      if (((int)uVar8 != 0) &&
         (((param_2 & 0x1f00) == 0 || (iVar2 = *(int *)(iVar5 + 0xc) << 0x1f, iVar2 < 0)))) {
        pcVar7 = *(code **)(iVar5 + 0x10);
        if ((param_2 & 0x80) == 0) {
          if (pcVar7 != (code *)0x0) goto LAB_000f3e70;
        }
        else {
          if (pcVar7 != (code *)0x0) {
LAB_000f3e70:
            uVar8 = (*pcVar7)(param_1,*(undefined2 *)(iVar1 + uVar4 * 0x24),param_2,&local_30,
                              local_2c,param_4,param_5,&local_34,*(undefined4 *)(iVar5 + 0x18));
            iVar2 = (int)((ulonglong)uVar8 >> 0x20);
            if ((int)uVar8 < 0) {
              ossl_statem_fatal(param_1,local_34,0x22a,0xea,"ssl/statem/extensions_cust.c",0xd5);
              return 0;
            }
            if ((int)uVar8 == 0) goto LAB_000f3f08;
          }
          iVar2 = WPACKET_put_bytes__(param_3,iVar2,*(undefined2 *)(iVar1 + uVar4 * 0x24),0,2);
          if ((((iVar2 == 0) || (iVar2 = WPACKET_start_sub_packet_len__(param_3,2), iVar2 == 0)) ||
              ((local_2c[0] != 0 && (iVar2 = WPACKET_memcpy(param_3,local_30), iVar2 == 0)))) ||
             (iVar2 = WPACKET_close(param_3), iVar2 == 0)) {
            uVar3 = 0xe1;
LAB_000f3f62:
            ossl_statem_fatal(param_1,0x50,0x22a,0x44,"ssl/statem/extensions_cust.c",uVar3);
            return 0;
          }
          if ((param_2 & 0x80) != 0) {
            if ((int)(*(uint *)(iVar5 + 0xc) << 0x1e) < 0) {
              uVar3 = 0xea;
              goto LAB_000f3f62;
            }
            *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 2;
          }
          if (*(code **)(iVar5 + 0x14) != (code *)0x0) {
            (**(code **)(iVar5 + 0x14))
                      (param_1,*(undefined2 *)(iVar1 + uVar4 * 0x24),param_2,local_30,
                       *(undefined4 *)(iVar5 + 0x18));
          }
        }
      }
LAB_000f3f08:
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(iVar6 + 0xf4));
  }
  return 1;
}

