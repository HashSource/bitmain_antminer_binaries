
char * BN_bn2hex(BIGNUM *a)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  ulong *puVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  
  iVar2 = BN_is_zero();
  if (iVar2 != 0) {
    pcVar3 = CRYPTO_strdup("0","crypto/bn/bn_print.c",0x1b);
    return pcVar3;
  }
  pcVar3 = (char *)CRYPTO_malloc(a->top * 0x10 + 2,"crypto/bn/bn_print.c",0x1c);
  if (pcVar3 == (char *)0x0) {
    ERR_put_error(3,0x69,0x41,"crypto/bn/bn_print.c",0x1e);
  }
  else {
    pcVar8 = pcVar3;
    if (a->neg != 0) {
      *pcVar3 = '-';
      pcVar8 = pcVar3 + 1;
    }
    iVar2 = a->top + -1;
    if (-1 < iVar2) {
      iVar4 = iVar2 * 4;
      uVar9 = 0;
      do {
        puVar5 = a->d;
        if (uVar9 != 0) {
          builtin_strncpy(pcVar8,"00000000",8);
          uVar9 = 1;
          pcVar8 = pcVar8 + 8;
          puVar5 = a->d;
        }
        uVar6 = *(uint *)((int)puVar5 + iVar4);
        uVar10 = uVar6 >> 0x18;
        uVar9 = uVar9 | uVar10;
        pcVar7 = pcVar8;
        if (uVar9 != 0) {
          cVar1 = "0123456789ABCDEF"[uVar10 & 0xf];
          uVar9 = 1;
          pcVar7 = pcVar8 + 2;
          *pcVar8 = "0123456789ABCDEF"[(int)uVar10 >> 4];
          pcVar8[1] = cVar1;
          uVar6 = *(uint *)((int)a->d + iVar4);
        }
        uVar10 = uVar6 >> 0x10 & 0xff;
        uVar9 = uVar9 | uVar10;
        pcVar8 = pcVar7;
        if (uVar9 != 0) {
          cVar1 = "0123456789ABCDEF"[uVar6 >> 0x10 & 0xf];
          uVar9 = 1;
          pcVar8 = pcVar7 + 2;
          *pcVar7 = "0123456789ABCDEF"[(int)uVar10 >> 4];
          pcVar7[1] = cVar1;
          uVar6 = *(uint *)((int)a->d + iVar4);
        }
        uVar10 = uVar6 >> 8 & 0xff;
        uVar9 = uVar9 | uVar10;
        pcVar7 = pcVar8;
        if (uVar9 != 0) {
          cVar1 = "0123456789ABCDEF"[uVar6 >> 8 & 0xf];
          uVar9 = 1;
          pcVar7 = pcVar8 + 2;
          *pcVar8 = "0123456789ABCDEF"[(int)uVar10 >> 4];
          pcVar8[1] = cVar1;
          uVar6 = *(uint *)((int)a->d + iVar4);
        }
        uVar9 = uVar9 | uVar6 & 0xff;
        pcVar8 = pcVar7;
        if (uVar9 != 0) {
          cVar1 = "0123456789ABCDEF"[uVar6 & 0xf];
          uVar9 = 1;
          pcVar8 = pcVar7 + 2;
          *pcVar7 = "0123456789ABCDEF"[(int)(uVar6 & 0xff) >> 4];
          pcVar7[1] = cVar1;
        }
        iVar2 = iVar2 + -1;
        iVar4 = iVar4 + -4;
      } while (iVar2 != -1);
    }
    *pcVar8 = '\0';
  }
  return pcVar3;
}

