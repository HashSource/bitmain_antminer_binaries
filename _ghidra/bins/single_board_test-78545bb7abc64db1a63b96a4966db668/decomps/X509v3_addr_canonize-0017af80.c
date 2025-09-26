
int X509v3_addr_canonize(undefined4 param_1)

{
  char *__s1;
  char cVar1;
  int iVar2;
  int iVar3;
  IPAddressOrRange *a;
  IPAddressOrRange *a_00;
  int *piVar4;
  size_t __n;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_c0;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  undefined4 local_6c;
  undefined1 auStack_68 [16];
  undefined1 uStack_58;
  char acStack_57 [31];
  undefined1 auStack_38 [20];
  
  iVar7 = 0;
  while( true ) {
    iVar2 = OPENSSL_sk_num(param_1);
    if (iVar2 <= iVar7) {
      OPENSSL_sk_set_cmp_func(param_1,0x179455);
      OPENSSL_sk_sort(param_1);
      iVar7 = X509v3_addr_is_canonical(param_1);
      if (iVar7 != 0) {
        iVar7 = 1;
      }
      return iVar7;
    }
    iVar2 = OPENSSL_sk_value(param_1,iVar7);
    if (**(int **)(iVar2 + 4) == 1) break;
LAB_0017af92:
    iVar7 = iVar7 + 1;
  }
  iVar5 = (*(int **)(iVar2 + 4))[1];
  iVar2 = X509v3_addr_get_afi();
  if (iVar2 == 1) {
    __n = 4;
    local_84 = -10;
    local_88 = -9;
    local_8c = -8;
    local_90 = -7;
    local_94 = -6;
    local_98 = -5;
    local_9c = -4;
    local_a0 = -3;
    local_a4 = -2;
    local_a8 = -1;
    local_b0 = 0;
    local_80 = 2;
    iVar2 = -0xb;
    local_c0 = 4;
    local_7c = 3;
    local_ac = 1;
  }
  else if (iVar2 == 2) {
    __n = 0x10;
    local_88 = 3;
    local_8c = 4;
    local_90 = 5;
    local_94 = 6;
    local_98 = 7;
    local_9c = 8;
    local_a0 = 9;
    local_a4 = 10;
    local_a8 = 0xb;
    local_b0 = 0xc;
    local_ac = 0xd;
    local_80 = 0xe;
    local_c0 = 0x10;
    local_7c = 0xf;
    iVar2 = 1;
    local_84 = 2;
  }
  else {
    __n = 0;
    local_84 = -0xe;
    local_88 = -0xd;
    local_8c = -0xc;
    local_90 = -0xb;
    local_94 = -10;
    local_98 = -9;
    local_9c = -8;
    local_a0 = -7;
    local_a4 = -6;
    local_a8 = -5;
    local_b0 = -4;
    local_ac = -3;
    local_80 = -2;
    iVar2 = -0xf;
    local_c0 = 0;
    local_7c = -1;
  }
  iVar6 = 0;
  OPENSSL_sk_sort(iVar5);
LAB_0017b018:
  iVar3 = OPENSSL_sk_num(iVar5);
  if (iVar6 < iVar3 + -1) {
    do {
      iVar8 = iVar6 + 1;
      a = (IPAddressOrRange *)OPENSSL_sk_value(iVar5,iVar6);
      a_00 = (IPAddressOrRange *)OPENSSL_sk_value(iVar5,iVar8);
      iVar3 = extract_min_max(a,auStack_68,&uStack_58,local_c0);
      if (iVar3 == 0) {
        return 0;
      }
      __s1 = acStack_57 + 0xf;
      iVar3 = extract_min_max(a_00,__s1,auStack_38,local_c0);
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = memcmp(auStack_68,&uStack_58,__n);
      if (0 < iVar3) {
        return 0;
      }
      iVar3 = memcmp(__s1,auStack_38,__n);
      if (0 < iVar3) {
        return 0;
      }
      iVar3 = memcmp(&uStack_58,__s1,__n);
      if (-1 < iVar3) {
        return 0;
      }
      if (local_7c != -1) {
        cVar1 = acStack_57[local_7c + 0xf];
        acStack_57[local_7c + 0xf] = cVar1 + -1;
        if (((((((cVar1 == '\0') && (-1 < local_80)) &&
               (cVar1 = acStack_57[local_80 + 0xf], acStack_57[local_80 + 0xf] = cVar1 + -1,
               cVar1 == '\0')) &&
              (((-1 < local_ac &&
                (cVar1 = acStack_57[local_ac + 0xf], acStack_57[local_ac + 0xf] = cVar1 + -1,
                cVar1 == '\0')) &&
               ((-1 < local_b0 &&
                ((cVar1 = acStack_57[local_b0 + 0xf], acStack_57[local_b0 + 0xf] = cVar1 + -1,
                 cVar1 == '\0' && (-1 < local_a8)))))))) &&
             (cVar1 = acStack_57[local_a8 + 0xf], acStack_57[local_a8 + 0xf] = cVar1 + -1,
             cVar1 == '\0')) &&
            ((((((-1 < local_a4 &&
                 (cVar1 = acStack_57[local_a4 + 0xf], acStack_57[local_a4 + 0xf] = cVar1 + -1,
                 cVar1 == '\0')) && (-1 < local_a0)) &&
               ((cVar1 = acStack_57[local_a0 + 0xf], acStack_57[local_a0 + 0xf] = cVar1 + -1,
                cVar1 == '\0' && (-1 < local_9c)))) &&
              (cVar1 = acStack_57[local_9c + 0xf], acStack_57[local_9c + 0xf] = cVar1 + -1,
              cVar1 == '\0')) &&
             (((-1 < local_98 &&
               (cVar1 = acStack_57[local_98 + 0xf], acStack_57[local_98 + 0xf] = cVar1 + -1,
               cVar1 == '\0')) &&
              (((-1 < local_94 &&
                (((cVar1 = acStack_57[local_94 + 0xf], acStack_57[local_94 + 0xf] = cVar1 + -1,
                  cVar1 == '\0' && (-1 < local_90)) &&
                 (cVar1 = acStack_57[local_90 + 0xf], acStack_57[local_90 + 0xf] = cVar1 + -1,
                 cVar1 == '\0')))) &&
               (((-1 < local_8c &&
                 (cVar1 = acStack_57[local_8c + 0xf], acStack_57[local_8c + 0xf] = cVar1 + -1,
                 cVar1 == '\0')) && (-1 < local_88)))))))))) &&
           (((cVar1 = acStack_57[local_88 + 0xf], acStack_57[local_88 + 0xf] = cVar1 + -1,
             cVar1 == '\0' && (-1 < local_84)) &&
            ((cVar1 = acStack_57[local_84 + 0xf], acStack_57[local_84 + 0xf] = cVar1 + -1,
             cVar1 == '\0' &&
             (((-1 < iVar2 &&
               (cVar1 = acStack_57[iVar2 + 0xf], acStack_57[iVar2 + 0xf] = cVar1 + -1, cVar1 == '\0'
               )) && (local_c0 == 0x10)))))))) {
          acStack_57[0xf] = acStack_57[0xf] + -1;
          iVar3 = memcmp(&uStack_58,__s1,__n);
        }
        else {
          iVar3 = memcmp(&uStack_58,__s1,__n);
        }
        if (iVar3 == 0) goto LAB_0017b2ae;
      }
      iVar3 = OPENSSL_sk_num(iVar5);
      iVar6 = iVar8;
      if (iVar3 + -1 <= iVar8) break;
    } while( true );
  }
  iVar2 = OPENSSL_sk_num(iVar5);
  piVar4 = (int *)OPENSSL_sk_value(iVar5,iVar2 + -1);
  if ((piVar4 != (int *)0x0) && (*piVar4 == 1)) {
    iVar2 = extract_min_max(piVar4,acStack_57 + 0xf,auStack_38,local_c0);
    if ((iVar2 == 0) || (iVar2 = memcmp(acStack_57 + 0xf,auStack_38,__n), 0 < iVar2)) {
      return 0;
    }
  }
  goto LAB_0017af92;
LAB_0017b2ae:
  iVar3 = memcmp(auStack_68,auStack_38,__n);
  if (0 < iVar3) {
    return 0;
  }
  iVar3 = range_should_be_prefix(auStack_68,auStack_38,local_c0);
  if (iVar3 < 0) {
    iVar3 = make_addressRange_part_2(&local_6c,auStack_68,auStack_38,local_c0);
  }
  else {
    iVar3 = make_addressPrefix(&local_6c,auStack_68,iVar3,local_c0);
  }
  if (iVar3 == 0) {
    return 0;
  }
  OPENSSL_sk_set(iVar5,iVar6,local_6c);
  OPENSSL_sk_delete(iVar5,iVar8);
  IPAddressOrRange_free(a);
  IPAddressOrRange_free(a_00);
  goto LAB_0017b018;
}

