
undefined4
bytes_to_cipher_list
          (undefined4 param_1,int *param_2,int *param_3,int *param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int extraout_r1;
  undefined4 uVar5;
  uint uVar6;
  uint __n;
  void *pvVar7;
  char local_2c;
  undefined1 auStack_2b [7];
  
  if (param_5 == 0) {
    __n = 2;
  }
  else {
    __n = 3;
  }
  if (param_2[1] == 0) {
    if (param_6 == 0) {
      ERR_put_error(0x14,0x207,0xb7,"ssl/ssl_lib.c",0x1553);
      return 0;
    }
    ossl_statem_fatal(param_1,0x2f,0x207,0xb7,"ssl/ssl_lib.c",0x1551);
    return 0;
  }
  __aeabi_uidivmod(param_2[1],__n);
  if (extraout_r1 != 0) {
    if (param_6 != 0) {
      ossl_statem_fatal(param_1,0x32,0x207,0x97,"ssl/ssl_lib.c",0x155a);
      return 0;
    }
    ERR_put_error(0x14,0x207,0x97,"ssl/ssl_lib.c",0x155d);
    return 0;
  }
  iVar1 = OPENSSL_sk_new_null();
  iVar2 = OPENSSL_sk_new_null();
  if (iVar2 != 0 && iVar1 != 0) {
    uVar6 = param_2[1];
    if (param_5 == 0) {
      while (__n <= uVar6) {
        pvVar7 = (void *)*param_2;
        memcpy(&local_2c,pvVar7,__n);
        param_2[1] = uVar6 - __n;
        *param_2 = (int)pvVar7 + __n;
        piVar3 = (int *)ssl_get_cipher_by_char(param_1,&local_2c,1);
        if (piVar3 != (int *)0x0) {
          if (*piVar3 != 0) {
            iVar4 = OPENSSL_sk_push(iVar1,piVar3);
            if (iVar4 == 0) goto LAB_000ee66a;
            if (*piVar3 != 0) goto LAB_000ee56a;
          }
          iVar4 = OPENSSL_sk_push(iVar2,piVar3);
          if (iVar4 == 0) goto LAB_000ee66a;
        }
LAB_000ee56a:
        uVar6 = param_2[1];
      }
    }
    else {
      while (__n <= uVar6) {
        pvVar7 = (void *)*param_2;
        uVar6 = uVar6 - __n;
        memcpy(&local_2c,pvVar7,__n);
        *param_2 = (int)pvVar7 + __n;
        param_2[1] = uVar6;
        if (local_2c == '\0') {
          piVar3 = (int *)ssl_get_cipher_by_char(param_1,auStack_2b,1);
          if (piVar3 != (int *)0x0) {
            if (*piVar3 != 0) {
              iVar4 = OPENSSL_sk_push(iVar1,piVar3);
              if (iVar4 == 0) goto LAB_000ee66a;
              if (*piVar3 != 0) goto LAB_000ee5cc;
            }
            iVar4 = OPENSSL_sk_push(iVar2,piVar3);
            if (iVar4 == 0) goto LAB_000ee66a;
          }
LAB_000ee5cc:
          uVar6 = param_2[1];
        }
      }
    }
    if (uVar6 == 0) {
      if (param_3 == (int *)0x0) {
        OPENSSL_sk_free(iVar1);
      }
      else {
        *param_3 = iVar1;
      }
      if (param_4 != (int *)0x0) {
        *param_4 = iVar2;
        return 1;
      }
      OPENSSL_sk_free(iVar2);
      return 1;
    }
    if (param_6 == 0) {
      ERR_put_error(0x14,0x207,0x10f,"ssl/ssl_lib.c",0x1588);
    }
    else {
      ossl_statem_fatal(param_1,0x32,0x207,0x10f,"ssl/ssl_lib.c",0x1586);
    }
    goto LAB_000ee606;
  }
  if (param_6 == 0) {
    iVar4 = 0x1568;
    goto LAB_000ee5f8;
  }
  uVar5 = 0x1566;
LAB_000ee622:
  ossl_statem_fatal(param_1,0x50,0x207,0x41,"ssl/ssl_lib.c",uVar5);
LAB_000ee606:
  OPENSSL_sk_free(iVar1);
  OPENSSL_sk_free(iVar2);
  return 0;
LAB_000ee66a:
  if (param_6 == 0) {
    iVar4 = 0x157e;
LAB_000ee5f8:
    ERR_put_error(0x14,0x207,0x41,"ssl/ssl_lib.c",iVar4);
    goto LAB_000ee606;
  }
  uVar5 = 0x157c;
  goto LAB_000ee622;
}

