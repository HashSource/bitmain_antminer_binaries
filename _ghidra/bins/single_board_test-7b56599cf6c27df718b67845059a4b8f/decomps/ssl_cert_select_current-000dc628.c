
undefined4 ssl_cert_select_current(int *param_1,X509 *param_2)

{
  int iVar1;
  X509 *pXVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_2 == (X509 *)0x0) {
    return 0;
  }
  piVar4 = param_1 + 5;
  if ((param_2 == (X509 *)param_1[5]) && (piVar3 = piVar4, param_1[6] != 0)) goto LAB_000dc6c2;
  if (param_2 == (X509 *)param_1[10]) {
    piVar3 = param_1 + 10;
    if (param_1[0xb] != 0) goto LAB_000dc6c2;
    if (param_2 == (X509 *)param_1[0xf]) goto LAB_000dc6d8;
LAB_000dc64e:
    if (param_2 != (X509 *)param_1[0x14]) goto LAB_000dc658;
LAB_000dc6e8:
    piVar3 = param_1 + 0x14;
    if (param_1[0x15] != 0) goto LAB_000dc6c2;
    if (param_2 == (X509 *)param_1[0x19]) goto LAB_000dc6f8;
LAB_000dc662:
    if (param_2 != (X509 *)param_1[0x1e]) goto LAB_000dc66c;
LAB_000dc708:
    piVar3 = param_1 + 0x1e;
    if (param_1[0x1f] != 0) goto LAB_000dc6c2;
    if (param_2 == (X509 *)param_1[0x23]) goto LAB_000dc71a;
LAB_000dc678:
    if (param_2 != (X509 *)param_1[0x28]) goto LAB_000dc684;
LAB_000dc72e:
    piVar3 = param_1 + 0x28;
    if (param_1[0x29] != 0) goto LAB_000dc6c2;
    pXVar2 = (X509 *)param_1[0x2d];
  }
  else {
    if (param_2 != (X509 *)param_1[0xf]) goto LAB_000dc64e;
LAB_000dc6d8:
    piVar3 = param_1 + 0xf;
    if (param_1[0x10] != 0) goto LAB_000dc6c2;
    if (param_2 == (X509 *)param_1[0x14]) goto LAB_000dc6e8;
LAB_000dc658:
    if (param_2 != (X509 *)param_1[0x19]) goto LAB_000dc662;
LAB_000dc6f8:
    piVar3 = param_1 + 0x19;
    if (param_1[0x1a] != 0) goto LAB_000dc6c2;
    if (param_2 == (X509 *)param_1[0x1e]) goto LAB_000dc708;
LAB_000dc66c:
    if (param_2 != (X509 *)param_1[0x23]) goto LAB_000dc678;
LAB_000dc71a:
    piVar3 = param_1 + 0x23;
    if (param_1[0x24] != 0) goto LAB_000dc6c2;
    if (param_2 == (X509 *)param_1[0x28]) goto LAB_000dc72e;
LAB_000dc684:
    pXVar2 = (X509 *)param_1[0x2d];
  }
  if ((param_2 != pXVar2) || (piVar3 = param_1 + 0x2d, param_1[0x2e] == 0)) {
    while (((piVar4[1] == 0 || ((X509 *)*piVar4 == (X509 *)0x0)) ||
           (iVar1 = X509_cmp((X509 *)*piVar4,param_2), iVar1 != 0))) {
      piVar4 = piVar4 + 5;
      if (piVar4 == param_1 + 0x32) {
        return 0;
      }
    }
    *param_1 = (int)piVar4;
    return 1;
  }
LAB_000dc6c2:
  *param_1 = (int)piVar3;
  return 1;
}

