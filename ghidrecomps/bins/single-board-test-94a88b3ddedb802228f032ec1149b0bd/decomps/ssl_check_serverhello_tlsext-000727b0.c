
undefined4 ssl_check_serverhello_tlsext(int param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  code *pcVar5;
  undefined4 local_14;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  local_14 = 0x70;
  if ((*(int *)(param_1 + 0x148) != 0) && (*(int *)(param_1 + 0x144) != 0)) {
    pcVar4 = *(char **)(*(int *)(param_1 + 0xc0) + 0xd8);
    if (((pcVar4 != (char *)0x0) && (iVar3 = *(int *)(*(int *)(param_1 + 0xc0) + 0xd4), iVar3 != 0))
       && ((((*(uint *)(iVar2 + 0xc) & 0xe0) != 0 || (*(int *)(iVar2 + 0x10) << 0x19 < 0)) &&
           (*pcVar4 != '\0')))) {
      pcVar1 = pcVar4 + iVar3 + -1;
      do {
        if (pcVar4 == pcVar1) {
          ERR_put_error(0x14,0x118,0x9d,DAT_000728e0,0xc2c);
          return 0xffffffff;
        }
        pcVar4 = pcVar4 + 1;
      } while (*pcVar4 != '\0');
    }
  }
  iVar2 = *(int *)(param_1 + 0xe4);
  if ((iVar2 == 0) || (pcVar5 = *(code **)(iVar2 + 0x100), pcVar5 == (code *)0x0)) {
    iVar2 = *(int *)(param_1 + 0x170);
    if (iVar2 != 0) {
      pcVar5 = *(code **)(iVar2 + 0x100);
      if (pcVar5 != (code *)0x0) goto LAB_000727e2;
      iVar2 = 0;
    }
  }
  else {
LAB_000727e2:
    iVar2 = (*pcVar5)(param_1,&local_14,*(undefined4 *)(iVar2 + 0x104));
  }
  if (((*(int *)(param_1 + 0x128) != -1) && (*(int *)(param_1 + 300) == 0)) &&
     ((iVar3 = *(int *)(param_1 + 0xe4), iVar3 != 0 && (*(int *)(iVar3 + 0x13c) != 0)))) {
    if (*(void **)(param_1 + 0x138) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x138));
      iVar3 = *(int *)(param_1 + 0xe4);
      *(undefined4 *)(param_1 + 0x138) = 0;
    }
    pcVar5 = *(code **)(iVar3 + 0x13c);
    *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
    iVar3 = (*pcVar5)(param_1,*(undefined4 *)(iVar3 + 0x140));
    if (iVar3 == 0) {
      local_14 = 0x71;
      goto LAB_00072840;
    }
    if (iVar3 < 0) {
      local_14 = 0x50;
      goto LAB_00072840;
    }
  }
  if (iVar2 != 2) {
    if (iVar2 == 3) {
      *(undefined4 *)(param_1 + 0x124) = 0;
      return 1;
    }
    if (iVar2 == 1) {
      ssl3_send_alert(param_1,1,local_14);
      return 1;
    }
    return 1;
  }
LAB_00072840:
  ssl3_send_alert(param_1,2);
  return 0xffffffff;
}

