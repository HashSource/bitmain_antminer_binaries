
uint ssl3_get_req_cert_type(int *param_1,undefined1 *param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  void *__src;
  uint uVar9;
  int local_1c;
  
  __src = *(void **)(param_1[0x26] + 0x11c);
  if (__src == (void *)0x0) {
    uVar5 = tls12_get_psigalgs(param_1,&local_1c);
    if (uVar5 == 0) {
      bVar2 = false;
      bVar3 = false;
      uVar9 = 0;
    }
    else {
      bVar2 = false;
      bVar3 = false;
      uVar9 = 0;
      iVar8 = local_1c;
      do {
        cVar1 = *(char *)(iVar8 + 1);
        if (cVar1 == '\x02') {
          bVar2 = true;
        }
        else if (cVar1 == '\x03') {
          bVar3 = true;
        }
        else if (cVar1 == '\x01') {
          uVar9 = 1;
        }
        iVar8 = iVar8 + 2;
      } while ((uint)(iVar8 - local_1c) < uVar5);
    }
    iVar8 = *param_1;
    uVar5 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
    if ((iVar8 < 0x301) || (-1 < (int)(uVar5 << 0x16))) {
      uVar6 = *(uint *)(param_1[0x26] + 0x38) & 0x30001;
      uVar7 = 1 - uVar6;
      if (1 < uVar6) {
        uVar7 = 0;
      }
      uVar6 = uVar5 & 10;
      if (uVar6 != 0) {
        uVar6 = uVar9 | uVar7;
        if (uVar6 != 0) {
          uVar6 = 1;
          *param_2 = 3;
        }
        if (bVar2 || uVar7 != 0) {
          param_2[uVar6] = 4;
          uVar6 = uVar6 + 1;
        }
        iVar8 = *param_1;
      }
      uVar4 = uVar6;
      if ((iVar8 == 0x300) && ((uVar5 & 0xe) != 0)) {
        param_2[uVar6] = 5;
        uVar4 = uVar6 + 2;
        param_2[uVar6 + 1] = 6;
      }
      if (uVar9 != 0) {
        param_2[uVar4] = 1;
        uVar4 = uVar4 + 1;
      }
      if (bVar2) {
        param_2[uVar4] = 2;
        uVar4 = uVar4 + 1;
      }
      if ((uVar5 & 0x60) != 0) {
        iVar8 = *param_1;
        if (iVar8 < 0x301) {
          return uVar4;
        }
        if (uVar9 != 0 || uVar7 != 0) {
          iVar8 = 0x41;
        }
        if (uVar9 != 0 || uVar7 != 0) {
          param_2[uVar4] = (char)iVar8;
          uVar4 = uVar4 + 1;
        }
        if (uVar7 != 0 || bVar3) {
          param_2[uVar4] = 0x42;
          uVar4 = uVar4 + 1;
        }
      }
      if ((0x300 < *param_1) && (bVar3)) {
        param_2[uVar4] = 0x40;
        uVar4 = uVar4 + 1;
      }
    }
    else {
      *param_2 = 0x15;
      uVar4 = 2;
      param_2[1] = 0x16;
    }
  }
  else {
    memcpy(param_2,__src,*(size_t *)(param_1[0x26] + 0x120));
    uVar4 = *(uint *)(param_1[0x26] + 0x120);
  }
  return uVar4;
}

