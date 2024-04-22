
uint ssl3_get_req_cert_type(int *param_1,undefined *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  void *__src;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  int local_1c;
  
  __src = *(void **)(param_1[0x26] + 0x11c);
  if (__src == (void *)0x0) {
    uVar3 = tls12_get_psigalgs(param_1,&local_1c);
    if (uVar3 == 0) {
      uVar4 = 0;
      uVar8 = 0;
      uVar9 = 0;
    }
    else {
      uVar4 = 0;
      uVar8 = 0;
      uVar9 = 0;
      iVar7 = local_1c;
      do {
        cVar1 = *(char *)(iVar7 + 1);
        if (cVar1 == '\x02') {
          uVar4 = 1;
        }
        else if (cVar1 == '\x03') {
          uVar8 = 1;
        }
        else if (cVar1 == '\x01') {
          uVar9 = 1;
        }
        iVar7 = iVar7 + 2;
      } while ((uint)(iVar7 - local_1c) < uVar3);
    }
    iVar7 = *param_1;
    uVar3 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
    if ((iVar7 < 0x301) || (-1 < (int)(uVar3 << 0x16))) {
      uVar5 = *(uint *)(param_1[0x26] + 0x38) & 0x30001;
      uVar6 = 1 - uVar5;
      if (1 < uVar5) {
        uVar6 = 0;
      }
      uVar5 = uVar3 & 10;
      if (uVar5 != 0) {
        uVar5 = uVar9 | uVar6;
        if (uVar5 != 0) {
          uVar5 = 1;
          *param_2 = 3;
        }
        if ((uVar4 | uVar6) != 0) {
          param_2[uVar5] = 4;
          uVar5 = uVar5 + 1;
        }
        iVar7 = *param_1;
      }
      uVar2 = uVar5;
      if ((iVar7 == 0x300) && ((uVar3 & 0xe) != 0)) {
        param_2[uVar5] = 5;
        uVar2 = uVar5 + 2;
        param_2[uVar5 + 1] = 6;
      }
      if (uVar9 != 0) {
        param_2[uVar2] = 1;
        uVar2 = uVar2 + 1;
      }
      if (uVar4 != 0) {
        param_2[uVar2] = 2;
        uVar2 = uVar2 + 1;
      }
      if ((uVar3 & 0x60) != 0) {
        iVar7 = *param_1;
        if (iVar7 < 0x301) {
          return uVar2;
        }
        bVar10 = (uVar9 | uVar6) != 0;
        if (bVar10) {
          iVar7 = 0x41;
        }
        if (bVar10) {
          param_2[uVar2] = (char)iVar7;
          uVar2 = uVar2 + 1;
        }
        if ((uVar6 | uVar8) != 0) {
          param_2[uVar2] = 0x42;
          uVar2 = uVar2 + 1;
        }
      }
      if ((0x300 < *param_1) && (uVar8 != 0)) {
        param_2[uVar2] = 0x40;
        uVar2 = uVar2 + 1;
      }
    }
    else {
      *param_2 = 0x15;
      uVar2 = 2;
      param_2[1] = 0x16;
    }
  }
  else {
    memcpy(param_2,__src,*(size_t *)(param_1[0x26] + 0x120));
    uVar2 = *(uint *)(param_1[0x26] + 0x120);
  }
  return uVar2;
}

