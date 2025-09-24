
int tls_process_finished(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint len;
  bool bVar5;
  undefined4 uVar6;
  undefined1 auStack_1c [8];
  
  if (*(int *)(param_1 + 0x1c) == 0) {
LAB_000f59a4:
    piVar2 = *(int **)(param_1 + 4);
    if ((*(uint *)(piVar2[0x19] + 0x30) & 8) == 0) {
      if (*piVar2 != 0x10000 && 0x303 < *piVar2) {
        iVar1 = RECORD_LAYER_processed_read_pending(param_1 + 0x650);
        if (iVar1 != 0) {
          uVar6 = 0x315;
          uVar4 = 0xb6;
          goto LAB_000f5a7e;
        }
        piVar2 = *(int **)(param_1 + 4);
        if (*(int *)(piVar2[0x19] + 0x30) << 0x1c < 0) goto LAB_000f594c;
      }
LAB_000f59de:
      if (*piVar2 != 0x10000 && 0x303 < *piVar2) {
        iVar1 = *(int *)(param_1 + 0x7c);
        goto LAB_000f5958;
      }
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x5f4);
    *(undefined4 *)(param_1 + 100) = 0;
    bVar5 = iVar1 != 4;
    if (bVar5) {
      iVar1 = 1;
    }
    if (bVar5) {
      *(int *)(param_1 + 0x54) = iVar1;
    }
    piVar2 = *(int **)(param_1 + 4);
    if (-1 < *(int *)(piVar2[0x19] + 0x30) << 0x1c) {
      iVar1 = *piVar2 + -0x10000;
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      if (*piVar2 < 0x304) {
        iVar1 = 0;
      }
      if (iVar1 != 0) {
        iVar1 = tls13_save_handshake_digest_for_pha();
        if (iVar1 == 0) {
          return 0;
        }
        goto LAB_000f59a4;
      }
      goto LAB_000f59de;
    }
  }
LAB_000f594c:
  iVar1 = *(int *)(param_1 + 0x7c);
  if (*(int *)(iVar1 + 0xdc) == 0) {
    uVar6 = 0x31c;
    uVar4 = 0x9a;
LAB_000f5a7e:
    ossl_statem_fatal(param_1,10,0x16c,uVar4,"ssl/statem/statem_lib.c",uVar6);
    return 0;
  }
LAB_000f5958:
  len = *(uint *)(iVar1 + 0x204);
  *(undefined4 *)(iVar1 + 0xdc) = 0;
  if (len == param_2[1]) {
    iVar1 = CRYPTO_memcmp((void *)*param_2,(void *)(iVar1 + 0x184),len);
    if (iVar1 == 0) {
      if (len < 0x41) {
        iVar1 = *(int *)(param_1 + 0x7c);
        if (*(int *)(param_1 + 0x1c) == 0) {
          memcpy((void *)(iVar1 + 0x2f4),(void *)(iVar1 + 0x184),len);
          *(uint *)(*(int *)(param_1 + 0x7c) + 0x334) = len;
        }
        else {
          memcpy((void *)(iVar1 + 0x2b0),(void *)(iVar1 + 0x184),len);
          *(uint *)(*(int *)(param_1 + 0x7c) + 0x2f0) = len;
        }
        iVar1 = (*(int **)(param_1 + 4))[0x19];
        if ((*(int *)(iVar1 + 0x30) << 0x1c < 0) ||
           (iVar3 = **(int **)(param_1 + 4), iVar3 == 0x10000 || iVar3 < 0x304)) {
          return 1;
        }
        if (*(int *)(param_1 + 0x1c) == 0) {
          iVar1 = (**(code **)(iVar1 + 0xc))(param_1,param_1 + 0x14c,param_1 + 0x10c,0,auStack_1c);
          if (((iVar1 != 0) &&
              (iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x10))(param_1,0x111),
              iVar1 != 0)) && (iVar1 = tls_process_initial_server_flight(param_1), iVar1 != 0)) {
            return 1;
          }
          iVar1 = 0;
        }
        else {
          if (*(int *)(param_1 + 0x5f4) == 4) {
            return 1;
          }
          iVar1 = (**(code **)(iVar1 + 0x10))(param_1,0x121);
          if (iVar1 != 0) {
            iVar1 = 1;
          }
        }
      }
      else {
        ossl_statem_fatal(param_1,0x50,0x16c,0x44,"ssl/statem/statem_lib.c",0x335);
        iVar1 = 0;
      }
    }
    else {
      ossl_statem_fatal(param_1,0x33,0x16c,0x95,"ssl/statem/statem_lib.c",0x32c);
      iVar1 = 0;
    }
  }
  else {
    ossl_statem_fatal(param_1,0x32,0x16c,0x6f,"ssl/statem/statem_lib.c",0x325);
    iVar1 = 0;
  }
  return iVar1;
}

