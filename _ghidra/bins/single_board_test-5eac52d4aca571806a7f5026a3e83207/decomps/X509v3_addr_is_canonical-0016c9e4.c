
undefined4 X509v3_addr_is_canonical(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  size_t sVar8;
  size_t sVar9;
  size_t sVar10;
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
  int local_78;
  int local_74;
  int local_70;
  undefined1 auStack_68 [16];
  undefined1 auStack_58 [16];
  char local_48 [16];
  undefined1 auStack_38 [20];
  
  if (param_1 == 0) {
    return 1;
  }
  iVar4 = 0;
  while( true ) {
    iVar3 = OPENSSL_sk_num(param_1);
    if (iVar3 + -1 <= iVar4) break;
    puVar2 = (undefined4 *)OPENSSL_sk_value(param_1,iVar4);
    piVar7 = (int *)OPENSSL_sk_value(param_1,iVar4 + 1);
    sVar9 = *(size_t *)*puVar2;
    sVar8 = *(size_t *)*piVar7;
    sVar10 = sVar9;
    if ((int)sVar8 <= (int)sVar9) {
      sVar10 = sVar8;
    }
    iVar3 = memcmp((void *)((size_t *)*puVar2)[2],(void *)((size_t *)*piVar7)[2],sVar10);
    if (iVar3 == 0) {
      iVar3 = sVar9 - sVar8;
    }
    iVar4 = iVar4 + 1;
    if (-1 < iVar3) {
      return 0;
    }
  }
  local_ac = 0;
  do {
    iVar4 = OPENSSL_sk_num(param_1);
    if (iVar4 <= local_ac) {
      return 1;
    }
    iVar4 = OPENSSL_sk_value(param_1,local_ac);
    iVar3 = X509v3_addr_get_afi();
    if (iVar3 == 1) {
      local_78 = -0xb;
      local_7c = -10;
      local_80 = -9;
      local_84 = -8;
      local_88 = -7;
      local_8c = -6;
      local_90 = -5;
      local_70 = -4;
      local_74 = -3;
      local_98 = -2;
      local_94 = -1;
      local_9c = 0;
      local_a0 = 3;
      sVar10 = 4;
      local_a8 = 2;
      local_a4 = 1;
    }
    else if (iVar3 == 2) {
      local_78 = 1;
      local_80 = 3;
      local_84 = 4;
      local_88 = 5;
      local_8c = 6;
      local_90 = 7;
      local_70 = 8;
      local_74 = 9;
      local_98 = 10;
      local_94 = 0xb;
      local_9c = 0xc;
      local_a4 = 0xd;
      sVar10 = 0x10;
      local_a0 = 0xf;
      local_a8 = 0xe;
      local_7c = 2;
    }
    else {
      sVar10 = 0;
      local_78 = -0xf;
      local_7c = -0xe;
      local_80 = -0xd;
      local_84 = -0xc;
      local_88 = -0xb;
      local_8c = -10;
      local_90 = -9;
      local_70 = -8;
      local_74 = -7;
      local_98 = -6;
      local_94 = -5;
      local_9c = -4;
      local_a4 = -3;
      local_a0 = -1;
      local_a8 = -2;
    }
    if (iVar4 == 0) {
      return 0;
    }
    piVar7 = *(int **)(iVar4 + 4);
    if (piVar7 == (int *)0x0) {
      return 0;
    }
    if (*piVar7 != 0) {
      if (*piVar7 != 1) {
        return 0;
      }
      iVar3 = piVar7[1];
      iVar4 = OPENSSL_sk_num(iVar3);
      if (iVar4 == 0) {
        return 0;
      }
      iVar4 = 0;
      while (iVar5 = OPENSSL_sk_num(iVar3), iVar4 < iVar5 + -1) {
        iVar5 = iVar4 + 1;
        piVar7 = (int *)OPENSSL_sk_value(iVar3,iVar4);
        uVar6 = OPENSSL_sk_value(iVar3,iVar5);
        iVar4 = extract_min_max(piVar7,auStack_68,auStack_58,sVar10);
        if (iVar4 == 0) {
          return 0;
        }
        iVar4 = extract_min_max(uVar6,local_48,auStack_38,sVar10);
        if (iVar4 == 0) {
          return 0;
        }
        iVar4 = memcmp(auStack_68,local_48,sVar10);
        if (-1 < iVar4) {
          return 0;
        }
        iVar4 = memcmp(auStack_68,auStack_58,sVar10);
        if (0 < iVar4) {
          return 0;
        }
        iVar4 = memcmp(local_48,auStack_38,sVar10);
        if (0 < iVar4) {
          return 0;
        }
        if (((((((local_a0 != -1) &&
                (cVar1 = local_48[local_a0], local_48[local_a0] = cVar1 + -1, cVar1 == '\0')) &&
               (-1 < local_a8)) &&
              ((cVar1 = local_48[local_a8], local_48[local_a8] = cVar1 + -1, cVar1 == '\0' &&
               (-1 < local_a4)))) &&
             ((cVar1 = local_48[local_a4], local_48[local_a4] = cVar1 + -1, cVar1 == '\0' &&
              ((-1 < local_9c &&
               (cVar1 = local_48[local_9c], local_48[local_9c] = cVar1 + -1, cVar1 == '\0')))))) &&
            (((-1 < local_94 &&
              ((((cVar1 = local_48[local_94], local_48[local_94] = cVar1 + -1, cVar1 == '\0' &&
                 (-1 < local_98)) &&
                (cVar1 = local_48[local_98], local_48[local_98] = cVar1 + -1, cVar1 == '\0')) &&
               (((-1 < local_74 &&
                 (cVar1 = local_48[local_74], local_48[local_74] = cVar1 + -1, cVar1 == '\0')) &&
                ((-1 < local_70 &&
                 ((cVar1 = local_48[local_70], local_48[local_70] = cVar1 + -1, cVar1 == '\0' &&
                  (-1 < local_90)))))))))) &&
             (cVar1 = local_48[local_90], local_48[local_90] = cVar1 + -1, cVar1 == '\0')))) &&
           ((((-1 < local_8c &&
              (cVar1 = local_48[local_8c], local_48[local_8c] = cVar1 + -1, cVar1 == '\0')) &&
             (-1 < local_88)) &&
            (((cVar1 = local_48[local_88], local_48[local_88] = cVar1 + -1, cVar1 == '\0' &&
              (-1 < local_84)) &&
             ((((cVar1 = local_48[local_84], local_48[local_84] = cVar1 + -1, cVar1 == '\0' &&
                ((-1 < local_80 &&
                 (cVar1 = local_48[local_80], local_48[local_80] = cVar1 + -1, cVar1 == '\0')))) &&
               (-1 < local_7c)) &&
              ((((cVar1 = local_48[local_7c], local_48[local_7c] = cVar1 + -1, cVar1 == '\0' &&
                 (-1 < local_78)) &&
                (cVar1 = local_48[local_78], local_48[local_78] = cVar1 + -1, cVar1 == '\0')) &&
               (sVar10 == 0x10)))))))))) {
          local_48[0] = local_48[0] + -1;
        }
        iVar4 = memcmp(auStack_58,local_48,sVar10);
        if (-1 < iVar4) {
          return 0;
        }
        iVar4 = iVar5;
        if ((*piVar7 == 1) &&
           (iVar5 = range_should_be_prefix(auStack_68,auStack_58,sVar10), -1 < iVar5)) {
          return 0;
        }
      }
      iVar4 = OPENSSL_sk_num(iVar3);
      piVar7 = (int *)OPENSSL_sk_value(iVar3,iVar4 + -1);
      if ((piVar7 != (int *)0x0) && (*piVar7 == 1)) {
        iVar4 = extract_min_max(piVar7,auStack_68,auStack_58,sVar10);
        if (iVar4 == 0) {
          return 0;
        }
        iVar4 = memcmp(auStack_68,auStack_58,sVar10);
        if (0 < iVar4) {
          return 0;
        }
        iVar4 = range_should_be_prefix(auStack_68,auStack_58,sVar10);
        if (-1 < iVar4) {
          return 0;
        }
      }
    }
    local_ac = local_ac + 1;
  } while( true );
}

