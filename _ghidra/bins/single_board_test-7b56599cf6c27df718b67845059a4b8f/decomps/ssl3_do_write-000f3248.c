
undefined4 ssl3_do_write(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  bool bVar4;
  int local_1c [2];
  
  local_1c[0] = 0;
  iVar1 = ssl3_write_bytes(param_1,param_2,param_1[0x1e] + *(int *)(param_1[0x1b] + 4),param_1[0x1d]
                           ,local_1c);
  if (iVar1 < 0) {
LAB_000f32cc:
    uVar2 = 0xffffffff;
  }
  else {
    if (param_2 == 0x16) {
      if ((-1 < *(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c) &&
         (iVar1 = *(int *)param_1[1], iVar1 != 0x10000 && 0x303 < iVar1)) {
        uVar3 = param_1[0x10];
        bVar4 = 0x20 < uVar3;
        if (uVar3 != 0x21) {
          bVar4 = uVar3 != 0x2a;
        }
        if (!bVar4 || (uVar3 == 0x21 || uVar3 == 0x2b)) goto LAB_000f3270;
      }
      iVar1 = ssl3_finish_mac(param_1,*(int *)(param_1[0x1b] + 4) + param_1[0x1e],local_1c[0]);
      if (iVar1 == 0) goto LAB_000f32cc;
    }
LAB_000f3270:
    iVar1 = param_1[0x1d];
    if (iVar1 == local_1c[0]) {
      uVar2 = 1;
      if ((code *)param_1[0x21] != (code *)0x0) {
        (*(code *)param_1[0x21])
                  (1,*param_1,param_2,*(undefined4 *)(param_1[0x1b] + 4),iVar1 + param_1[0x1e],
                   param_1,param_1[0x22]);
        return 1;
      }
    }
    else {
      uVar2 = 0;
      param_1[0x1d] = iVar1 - local_1c[0];
      param_1[0x1e] = local_1c[0] + param_1[0x1e];
    }
  }
  return uVar2;
}

