
char * OPENSSL_uni2utf8(uchar *param_1,uint param_2)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  ulong uVar4;
  uint uVar5;
  uchar *puVar6;
  int iVar7;
  int iVar8;
  
  if ((param_2 & 1) != 0) {
    return (char *)0x0;
  }
  if (0 < (int)param_2) {
    if (param_2 != 1) {
      iVar7 = 0;
      iVar8 = 0;
      uVar3 = param_2;
      puVar6 = param_1;
      do {
        uVar4 = (ulong)CONCAT11(*puVar6,puVar6[1]);
        if ((uVar4 - 0xd800 < 0x800) &&
           (((int)uVar3 < 4 ||
            (uVar5 = CONCAT11(puVar6[2],puVar6[3]) - 0xdc00,
            uVar4 = ((uVar4 - 0xd800) * 0x400 | uVar5) + 0x10000, 0x3ff < uVar5)))) break;
        if (3 < (int)uVar3) {
          uVar3 = 4;
        }
        iVar1 = UTF8_putc((uchar *)0x0,uVar3,uVar4);
        if (iVar1 < 0) break;
        iVar8 = iVar8 + iVar1;
        if (iVar1 == 4) {
          iVar7 = iVar7 + 4;
        }
        else {
          iVar7 = iVar7 + 2;
        }
        uVar3 = param_2 - iVar7;
        puVar6 = param_1 + iVar7;
        if ((int)param_2 <= iVar7) goto LAB_001c4508;
      } while (uVar3 != 1);
    }
    pcVar2 = OPENSSL_uni2asc(param_1,param_2);
    return pcVar2;
  }
  if (param_2 == 0) {
    iVar8 = 0;
LAB_001c4512:
    iVar8 = iVar8 + 1;
  }
  else {
    iVar8 = 0;
LAB_001c4508:
    if ((param_1[param_2 - 2] != '\0') || (param_1[param_2 - 1] != '\0')) goto LAB_001c4512;
  }
  pcVar2 = (char *)CRYPTO_malloc(iVar8,"crypto/pkcs12/p12_utl.c",0xca);
  if (pcVar2 == (char *)0x0) {
    ERR_put_error(0x23,0x7f,0x41,"crypto/pkcs12/p12_utl.c",0xcb);
    return (char *)0x0;
  }
  if ((int)param_2 < 1) {
    if (param_2 == 0) {
      iVar7 = 0;
      goto LAB_001c459c;
    }
    iVar7 = 0;
  }
  else {
    iVar8 = 0;
    iVar7 = iVar8;
LAB_001c4582:
    do {
      iVar1 = param_2 - iVar8;
      if (iVar1 == 1) {
LAB_001c4588:
        iVar1 = -1;
      }
      else {
        uVar4 = (ulong)CONCAT11(param_1[iVar8],param_1[iVar8 + 1]);
        if (uVar4 - 0xd800 < 0x800) {
          if (3 < iVar1) {
            uVar3 = CONCAT11(param_1[iVar8 + 2],param_1[iVar8 + 3]) - 0xdc00;
            if (uVar3 < 0x400) {
              uVar4 = (uVar3 | (uVar4 - 0xd800) * 0x400) + 0x10000;
              goto LAB_001c4568;
            }
          }
          goto LAB_001c4588;
        }
LAB_001c4568:
        if (3 < iVar1) {
          iVar1 = 4;
        }
        iVar1 = UTF8_putc((uchar *)(pcVar2 + iVar7),iVar1,uVar4);
        if (iVar1 == 4) {
          iVar8 = iVar8 + 4;
          iVar7 = iVar7 + 4;
          if ((int)param_2 <= iVar8) break;
          goto LAB_001c4582;
        }
      }
      iVar8 = iVar8 + 2;
      iVar7 = iVar7 + iVar1;
    } while (iVar8 < (int)param_2);
  }
  if ((param_1[param_2 - 2] == '\0') && (param_1[param_2 - 1] == '\0')) {
    return pcVar2;
  }
LAB_001c459c:
  pcVar2[iVar7] = '\0';
  return pcVar2;
}

