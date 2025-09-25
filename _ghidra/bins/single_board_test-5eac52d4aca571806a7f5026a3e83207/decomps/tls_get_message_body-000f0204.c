
undefined4 tls_get_message_body(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_2c [2];
  
  if (*(int *)(param_1[0x1f] + 0x20c) == 0x101) {
    *param_2 = param_1[0x1d];
    return 1;
  }
  iVar1 = param_1[0x1d];
  iVar4 = param_1[0x1c];
  iVar2 = *(int *)(param_1[0x1f] + 0x208) - iVar1;
  if (iVar2 != 0) {
    do {
      iVar1 = (**(code **)(param_1[1] + 0x38))(param_1,0x16,0,iVar1 + iVar4,iVar2,0,local_2c);
      if (iVar1 < 1) {
        param_1[5] = 3;
        *param_2 = 0;
        return 0;
      }
      iVar2 = iVar2 - local_2c[0];
      iVar1 = param_1[0x1d] + local_2c[0];
      param_1[0x1d] = iVar1;
    } while (iVar2 != 0);
  }
  if ((**(char **)(param_1[0x1b] + 4) == '\x14') && (iVar1 = ssl3_take_mac(param_1), iVar1 == 0))
  goto LAB_000f031e;
  iVar1 = RECORD_LAYER_is_sslv2_record(param_1 + 0x194);
  if (iVar1 == 0) {
    if ((*(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c < 0) ||
       (iVar1 = *(int *)param_1[1], iVar1 < 0x304 || iVar1 == 0x10000)) {
      iVar1 = *(int *)(param_1[0x1f] + 0x20c);
LAB_000f0298:
      if (iVar1 != 2) {
        uVar3 = param_1[0x1d];
        iVar1 = *(int *)(param_1[0x1b] + 4);
LAB_000f02a2:
        iVar1 = ssl3_finish_mac(param_1,iVar1,uVar3 + 4);
        if (iVar1 == 0) {
LAB_000f031e:
          *param_2 = 0;
          return 0;
        }
        goto LAB_000f02b0;
      }
      uVar3 = param_1[0x1d];
      if (uVar3 < 0x26) {
        iVar1 = *(int *)(param_1[0x1b] + 4);
        goto LAB_000f02a2;
      }
      iVar1 = *(int *)(param_1[0x1b] + 4);
      iVar2 = memcmp(hrrrandom,(void *)(iVar1 + 6),0x20);
      if (iVar2 != 0) goto LAB_000f02a2;
    }
    else {
      iVar1 = *(int *)(param_1[0x1f] + 0x20c);
      if (iVar1 != 4 && iVar1 != 0x18) goto LAB_000f0298;
LAB_000f02b0:
      uVar3 = param_1[0x1d];
    }
    if ((code *)param_1[0x21] == (code *)0x0) goto LAB_000f02d2;
    (*(code *)param_1[0x21])
              (0,*param_1,0x16,*(undefined4 *)(param_1[0x1b] + 4),uVar3 + 4,param_1,param_1[0x22]);
  }
  else {
    iVar1 = ssl3_finish_mac(param_1,*(undefined4 *)(param_1[0x1b] + 4),param_1[0x1d]);
    if (iVar1 == 0) goto LAB_000f031e;
    if ((code *)param_1[0x21] != (code *)0x0) {
      (*(code *)param_1[0x21])
                (0,2,0,*(undefined4 *)(param_1[0x1b] + 4),param_1[0x1d],param_1,param_1[0x22]);
      uVar3 = param_1[0x1d];
      goto LAB_000f02d2;
    }
  }
  uVar3 = param_1[0x1d];
LAB_000f02d2:
  *param_2 = uVar3;
  return 1;
}

