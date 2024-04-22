
char * BN_bn2hex(BIGNUM *a)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  
  if (a->neg == 0) {
    iVar6 = a->top;
  }
  else {
    iVar6 = a->top;
    if (iVar6 == 0) {
      pcVar3 = (char *)CRYPTO_malloc(3,DAT_0009e164,0x4c);
      goto LAB_0009e05a;
    }
  }
  pcVar3 = (char *)CRYPTO_malloc(iVar6 * 8 + 2,DAT_0009e164,0x4e);
LAB_0009e05a:
  if (pcVar3 == (char *)0x0) {
    ERR_put_error(3,0x69,0x41,DAT_0009e164,0x51);
  }
  else {
    pcVar7 = pcVar3;
    if (a->neg != 0) {
      *pcVar3 = '-';
      pcVar7 = pcVar3 + 1;
    }
    iVar6 = a->top;
    pcVar8 = pcVar7;
    if (iVar6 == 0) {
      pcVar8 = pcVar7 + 1;
      *pcVar7 = '0';
      iVar6 = a->top;
    }
    iVar2 = DAT_0009e168;
    iVar6 = iVar6 + -1;
    if (-1 < iVar6) {
      iVar4 = iVar6 * 4;
      uVar10 = 0;
      do {
        uVar5 = *(uint *)((int)a->d + iVar4);
        uVar10 = uVar10 | uVar5 >> 0x18;
        if (uVar10 != 0) {
          uVar10 = 1;
          cVar1 = *(char *)(iVar2 + ((int)(uVar5 >> 0x18) >> 4));
          pcVar8[1] = *(char *)(iVar2 + (uVar5 >> 0x18 & 0xf));
          *pcVar8 = cVar1;
          pcVar8 = pcVar8 + 2;
          uVar5 = *(uint *)((int)a->d + iVar4);
        }
        uVar9 = uVar5 >> 0x10 & 0xff;
        uVar10 = uVar9 | uVar10;
        if (uVar10 != 0) {
          uVar10 = 1;
          cVar1 = *(char *)(iVar2 + ((int)uVar9 >> 4));
          pcVar8[1] = *(char *)(iVar2 + (uVar5 >> 0x10 & 0xf));
          *pcVar8 = cVar1;
          pcVar8 = pcVar8 + 2;
          uVar5 = *(uint *)((int)a->d + iVar4);
        }
        uVar9 = uVar5 >> 8 & 0xff;
        uVar10 = uVar9 | uVar10;
        if (uVar10 != 0) {
          uVar10 = 1;
          cVar1 = *(char *)(iVar2 + ((int)uVar9 >> 4));
          pcVar8[1] = *(char *)(iVar2 + (uVar5 >> 8 & 0xf));
          *pcVar8 = cVar1;
          pcVar8 = pcVar8 + 2;
          uVar5 = *(uint *)((int)a->d + iVar4);
        }
        uVar10 = uVar5 & 0xff | uVar10;
        if (uVar10 != 0) {
          uVar10 = 1;
          cVar1 = *(char *)(iVar2 + ((int)(uVar5 & 0xff) >> 4));
          pcVar8[1] = *(char *)(iVar2 + (uVar5 & 0xf));
          *pcVar8 = cVar1;
          pcVar8 = pcVar8 + 2;
        }
        iVar6 = iVar6 + -1;
        iVar4 = iVar4 + -4;
      } while (iVar6 != -1);
    }
    *pcVar8 = '\0';
  }
  return pcVar3;
}

