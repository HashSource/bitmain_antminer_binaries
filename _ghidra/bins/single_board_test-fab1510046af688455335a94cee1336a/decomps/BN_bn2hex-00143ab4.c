
char * BN_bn2hex(BIGNUM *a)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  
  if (a->neg == 0) {
    iVar5 = a->top;
  }
  else {
    iVar5 = a->top;
    if (iVar5 == 0) {
      pcVar2 = (char *)CRYPTO_malloc(3,"bn_print.c",0x4c);
      goto LAB_00143ad6;
    }
  }
  pcVar2 = (char *)CRYPTO_malloc(iVar5 * 8 + 2,"bn_print.c",0x4e);
LAB_00143ad6:
  if (pcVar2 == (char *)0x0) {
    ERR_put_error(3,0x69,0x41,"bn_print.c",0x51);
  }
  else {
    pcVar6 = pcVar2;
    if (a->neg != 0) {
      *pcVar2 = '-';
      pcVar6 = pcVar2 + 1;
    }
    iVar5 = a->top;
    pcVar7 = pcVar6;
    if (iVar5 == 0) {
      pcVar7 = pcVar6 + 1;
      *pcVar6 = '0';
      iVar5 = a->top;
    }
    iVar5 = iVar5 + -1;
    if (-1 < iVar5) {
      iVar3 = iVar5 * 4;
      uVar9 = 0;
      do {
        uVar4 = *(uint *)((int)a->d + iVar3);
        uVar9 = uVar9 | uVar4 >> 0x18;
        if (uVar9 != 0) {
          uVar9 = 1;
          cVar1 = "0123456789ABCDEF"[(int)(uVar4 >> 0x18) >> 4];
          pcVar7[1] = "0123456789ABCDEF"[uVar4 >> 0x18 & 0xf];
          *pcVar7 = cVar1;
          pcVar7 = pcVar7 + 2;
          uVar4 = *(uint *)((int)a->d + iVar3);
        }
        uVar8 = uVar4 >> 0x10 & 0xff;
        uVar9 = uVar8 | uVar9;
        if (uVar9 != 0) {
          uVar9 = 1;
          cVar1 = "0123456789ABCDEF"[(int)uVar8 >> 4];
          pcVar7[1] = "0123456789ABCDEF"[uVar4 >> 0x10 & 0xf];
          *pcVar7 = cVar1;
          pcVar7 = pcVar7 + 2;
          uVar4 = *(uint *)((int)a->d + iVar3);
        }
        uVar8 = uVar4 >> 8 & 0xff;
        uVar9 = uVar8 | uVar9;
        if (uVar9 != 0) {
          uVar9 = 1;
          cVar1 = "0123456789ABCDEF"[(int)uVar8 >> 4];
          pcVar7[1] = "0123456789ABCDEF"[uVar4 >> 8 & 0xf];
          *pcVar7 = cVar1;
          pcVar7 = pcVar7 + 2;
          uVar4 = *(uint *)((int)a->d + iVar3);
        }
        uVar9 = uVar4 & 0xff | uVar9;
        if (uVar9 != 0) {
          uVar9 = 1;
          cVar1 = "0123456789ABCDEF"[(int)(uVar4 & 0xff) >> 4];
          pcVar7[1] = "0123456789ABCDEF"[uVar4 & 0xf];
          *pcVar7 = cVar1;
          pcVar7 = pcVar7 + 2;
        }
        iVar5 = iVar5 + -1;
        iVar3 = iVar3 + -4;
      } while (iVar5 != -1);
    }
    *pcVar7 = '\0';
  }
  return pcVar2;
}

