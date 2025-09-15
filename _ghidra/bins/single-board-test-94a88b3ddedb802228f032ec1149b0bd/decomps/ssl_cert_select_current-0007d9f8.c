
undefined4 ssl_cert_select_current(int *param_1,X509 *param_2)

{
  X509 *a;
  int iVar1;
  int *piVar2;
  
  if (param_2 != (X509 *)0x0) {
    a = (X509 *)param_1[0xf];
    if ((((((a == param_2) && (piVar2 = param_1 + 0xf, param_1[0x10] != 0)) ||
          (((X509 *)param_1[0x16] == param_2 && (piVar2 = param_1 + 0x16, param_1[0x17] != 0)))) ||
         (((X509 *)param_1[0x1d] == param_2 && (piVar2 = param_1 + 0x1d, param_1[0x1e] != 0)))) ||
        ((((X509 *)param_1[0x24] == param_2 && (piVar2 = param_1 + 0x24, param_1[0x25] != 0)) ||
         (((((X509 *)param_1[0x2b] == param_2 && (piVar2 = param_1 + 0x2b, param_1[0x2c] != 0)) ||
           (((X509 *)param_1[0x32] == param_2 && (piVar2 = param_1 + 0x32, param_1[0x33] != 0)))) ||
          (((X509 *)param_1[0x39] == param_2 && (piVar2 = param_1 + 0x39, param_1[0x3a] != 0))))))))
       || (((X509 *)param_1[0x40] == param_2 && (piVar2 = param_1 + 0x40, param_1[0x41] != 0)))) {
      *param_1 = (int)piVar2;
      return 1;
    }
    if (((((((((param_1[0x10] != 0) && (a != (X509 *)0x0)) &&
             (iVar1 = X509_cmp(a,param_2), piVar2 = param_1 + 0xf, iVar1 == 0)) ||
            (((param_1[0x17] != 0 && ((X509 *)param_1[0x16] != (X509 *)0x0)) &&
             (iVar1 = X509_cmp((X509 *)param_1[0x16],param_2), piVar2 = param_1 + 0x16, iVar1 == 0))
            )) || (((param_1[0x1e] != 0 && ((X509 *)param_1[0x1d] != (X509 *)0x0)) &&
                   (iVar1 = X509_cmp((X509 *)param_1[0x1d],param_2), piVar2 = param_1 + 0x1d,
                   iVar1 == 0)))) ||
          (((param_1[0x25] != 0 && ((X509 *)param_1[0x24] != (X509 *)0x0)) &&
           (iVar1 = X509_cmp((X509 *)param_1[0x24],param_2), piVar2 = param_1 + 0x24, iVar1 == 0))))
         || (((param_1[0x2c] != 0 && ((X509 *)param_1[0x2b] != (X509 *)0x0)) &&
             (iVar1 = X509_cmp((X509 *)param_1[0x2b],param_2), piVar2 = param_1 + 0x2b, iVar1 == 0))
            )) || ((((param_1[0x33] != 0 && ((X509 *)param_1[0x32] != (X509 *)0x0)) &&
                    (iVar1 = X509_cmp((X509 *)param_1[0x32],param_2), piVar2 = param_1 + 0x32,
                    iVar1 == 0)) ||
                   (((param_1[0x3a] != 0 && ((X509 *)param_1[0x39] != (X509 *)0x0)) &&
                    (iVar1 = X509_cmp((X509 *)param_1[0x39],param_2), piVar2 = param_1 + 0x39,
                    iVar1 == 0)))))) ||
       (((param_1[0x41] != 0 && ((X509 *)param_1[0x40] != (X509 *)0x0)) &&
        (iVar1 = X509_cmp((X509 *)param_1[0x40],param_2), piVar2 = param_1 + 0x40, iVar1 == 0)))) {
      *param_1 = (int)piVar2;
      return 1;
    }
  }
  return 0;
}

