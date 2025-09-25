
undefined4 final_key_share(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  bool bVar6;
  int local_28;
  uint local_24;
  
  if (((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) ||
      (iVar3 = **(int **)(param_1 + 4), iVar3 == 0x10000 || iVar3 < 0x304)) || (param_2 << 0x14 < 0)
     ) {
LAB_000e2a72:
    uVar4 = 1;
  }
  else {
    if (param_3 == 0 && *(int *)(param_1 + 0x1c) == 0) {
      if ((*(int *)(param_1 + 0x8c) == 0) || (-1 < *(int *)(param_1 + 0x5a4) << 0x1f)) {
        ossl_statem_fatal(param_1,0x6d,0x1f7,0x65,"ssl/statem/extensions.c",0x52d);
        return 0;
      }
LAB_000e2a44:
      iVar3 = tls13_generate_handshake_secret(param_1,0);
      if (iVar3 != 0) goto LAB_000e2a72;
      uVar2 = 0x5ae;
    }
    else {
      if (*(int *)(param_1 + 0x1c) == 0) {
        if (param_3 != 0) goto LAB_000e2a72;
        goto LAB_000e2a44;
      }
      if ((*(int **)(param_1 + 0x7c))[0xd6] != 0) {
        iVar3 = **(int **)(param_1 + 0x7c);
        if ((iVar3 << 0x14 < 0) && (*(int *)(param_1 + 0x5bc) == 0)) {
          if (*(int *)(param_1 + 0x44c) != 0) {
            ossl_statem_fatal(param_1,0x50,0x1f7,0x44,"ssl/statem/extensions.c",0x55e);
            return 0;
          }
          goto LAB_000e2a9c;
        }
LAB_000e2aa4:
        bVar6 = *(int *)(param_1 + 0x44c) == 1;
        if (bVar6) {
          iVar3 = 2;
        }
        if (bVar6) {
          *(int *)(param_1 + 0x44c) = iVar3;
          return 1;
        }
        goto LAB_000e2a72;
      }
      if (param_3 == 0 || *(int *)(param_1 + 0x44c) != 0) {
LAB_000e2b46:
        if (*(int *)(param_1 + 0x8c) == 0) goto LAB_000e2b4c;
        iVar3 = *(int *)(param_1 + 0x5a4);
      }
      else if ((*(int *)(param_1 + 0x8c) == 0) ||
              (iVar3 = *(int *)(param_1 + 0x5a4), iVar3 << 0x1e < 0)) {
        uVar2 = *(undefined4 *)(param_1 + 0x578);
        uVar4 = *(undefined4 *)(param_1 + 0x57c);
        tls1_get_supported_groups(param_1,&local_28,&local_24);
        if (local_24 != 0) {
          uVar5 = 0;
          do {
            uVar1 = *(undefined2 *)(local_28 + uVar5 * 2);
            iVar3 = check_in_list(param_1,uVar1,uVar4,uVar2,1);
            if (iVar3 != 0) {
              if (uVar5 < local_24) {
                *(undefined2 *)(*(int *)(param_1 + 0x7c) + 0x356) = uVar1;
                *(undefined4 *)(param_1 + 0x44c) = 1;
                return 1;
              }
              break;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < local_24);
        }
        goto LAB_000e2b46;
      }
      if (-1 < iVar3 << 0x1f) {
LAB_000e2b4c:
        if (param_3 == 0) {
          uVar2 = 0x6d;
        }
        else {
          uVar2 = 0x28;
        }
        ossl_statem_fatal(param_1,uVar2,0x1f7,0x65,"ssl/statem/extensions.c",0x58b);
        return 0;
      }
      iVar3 = **(int **)(param_1 + 0x7c) << 0x14;
      if ((-1 < iVar3) || (*(int *)(param_1 + 0x5bc) != 0)) goto LAB_000e2aa4;
      if (*(int *)(param_1 + 0x44c) == 0) {
LAB_000e2a9c:
        *(undefined4 *)(param_1 + 0x44c) = 1;
        return 1;
      }
      uVar2 = 0x598;
    }
    uVar4 = 0;
    ossl_statem_fatal(param_1,0x50,0x1f7,0x44,"ssl/statem/extensions.c",uVar2);
  }
  return uVar4;
}

