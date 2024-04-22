
uint ssl3_get_cert_status(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  code *pcVar6;
  uint siz;
  int local_14;
  
  uVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x11f0,0x11f1,0x16,0x4000,&local_14);
  if (local_14 == 0) {
    return uVar1;
  }
  if (uVar1 < 4) {
    iVar4 = 0x91d;
  }
  else {
    pcVar5 = *(char **)(param_1 + 0x40);
    if (*pcVar5 != '\x01') {
      ERR_put_error(0x14,0x121,0x149,DAT_00066bd8,0x923);
      uVar3 = 0x32;
      goto LAB_00066b78;
    }
    siz = (uint)(byte)pcVar5[2] << 8 | (uint)(byte)pcVar5[1] << 0x10 | (uint)(byte)pcVar5[3];
    if (siz + 4 == uVar1) {
      if (*(void **)(param_1 + 0x138) != (void *)0x0) {
        CRYPTO_free(*(void **)(param_1 + 0x138));
      }
      pvVar2 = BUF_memdup(pcVar5 + 4,siz);
      iVar4 = 0x931;
      *(void **)(param_1 + 0x138) = pvVar2;
      if (pvVar2 != (void *)0x0) {
        *(uint *)(param_1 + 0x13c) = siz;
        pcVar6 = *(code **)(*(int *)(param_1 + 0xe4) + 0x13c);
        if (pcVar6 == (code *)0x0) {
          return 1;
        }
        iVar4 = (*pcVar6)(param_1,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x140));
        if (iVar4 == 0) {
          ERR_put_error(0x14,0x121,0x148,DAT_00066bd8,0x93a);
          uVar3 = 0x71;
          goto LAB_00066b78;
        }
        if (-1 < iVar4) {
          return 1;
        }
        iVar4 = 0x93f;
      }
      ERR_put_error(0x14,0x121,0x41,DAT_00066bd8,iVar4);
      uVar3 = 0x50;
      goto LAB_00066b78;
    }
    iVar4 = 0x929;
  }
  ERR_put_error(0x14,0x121,0x9f,DAT_00066bd8,iVar4);
  uVar3 = 0x32;
LAB_00066b78:
  ssl3_send_alert(param_1,2,uVar3);
  *(undefined4 *)(param_1 + 0x34) = 5;
  return 0xffffffff;
}

