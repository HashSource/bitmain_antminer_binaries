
int mime_parse_hdr(BIO *param_1)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  uint uVar4;
  char cVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 *ptr;
  char *pcVar9;
  char *pcVar10;
  char local_428 [1028];
  
  iVar1 = OPENSSL_sk_new(0x1d2f29);
  if (iVar1 == 0) {
    return 0;
  }
  ptr = (undefined4 *)0x0;
LAB_001d32d2:
  iVar2 = BIO_gets(param_1,local_428,0x400);
  if (iVar2 < 1) {
    return iVar1;
  }
  iVar2 = 1;
  if (ptr != (undefined4 *)0x0) {
    iVar2 = ossl_ctype_check(local_428[0],8);
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = 3;
    }
  }
  pcVar10 = local_428;
  if ((local_428[0] != '\0') && (local_428[0] != '\r' && local_428[0] != '\n')) {
    pcVar8 = (char *)0x0;
    pcVar6 = local_428;
    cVar5 = local_428[0];
    do {
      pcVar7 = pcVar10;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
      switch(iVar2) {
      case 2:
        while (cVar5 != ':') {
          pcVar10 = pcVar10 + 1;
          cVar5 = *pcVar10;
          if ((cVar5 == '\0') || (cVar5 == '\r' || cVar5 == '\n')) goto LAB_001d3694;
        }
        *pcVar10 = '\0';
        cVar5 = *pcVar6;
        while (cVar5 != '\0') {
          if (cVar5 == '\"') {
            if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001d3372:
              sVar3 = strlen(pcVar6);
              uVar4 = sVar3 - 1;
              if (!CARRY4((uint)pcVar6,uVar4)) {
                cVar5 = pcVar6[uVar4];
                pcVar7 = pcVar6 + uVar4;
                goto joined_r0x001d3386;
              }
            }
            break;
          }
          iVar2 = ossl_ctype_check(cVar5,8);
          if (iVar2 == 0) goto LAB_001d3372;
          pcVar6 = pcVar6 + 1;
          cVar5 = *pcVar6;
        }
        goto LAB_001d3782;
      case 3:
        if (cVar5 != ';') goto LAB_001d3582;
LAB_001d35a0:
        *pcVar10 = '\0';
        cVar5 = *pcVar6;
        while (cVar5 != '\0') {
          if (cVar5 == '\"') {
            if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001d35ce:
              sVar3 = strlen(pcVar6);
              uVar4 = sVar3 - 1;
              if (!CARRY4((uint)pcVar6,uVar4)) {
                cVar5 = pcVar6[uVar4];
                pcVar7 = pcVar6 + uVar4;
                goto joined_r0x001d35e2;
              }
            }
            break;
          }
          iVar2 = ossl_ctype_check(cVar5,8);
          if (iVar2 == 0) goto LAB_001d35ce;
          pcVar6 = pcVar6 + 1;
          cVar5 = *pcVar6;
        }
        goto LAB_001d37aa;
      case 4:
        goto switchD_001d331c_caseD_4;
      }
switchD_001d331c_default:
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
    } while ((cVar5 != '\0') && (cVar5 != '\r' && cVar5 != '\n'));
    if (iVar2 != 2) {
      if (iVar2 != 4) goto LAB_001d3694;
LAB_001d3510:
      cVar5 = *pcVar6;
      while (cVar5 != '\0') {
        if (cVar5 == '\"') {
          if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001d353a:
            sVar3 = strlen(pcVar6);
            uVar4 = sVar3 - 1;
            if (!CARRY4((uint)pcVar6,uVar4)) {
              cVar5 = pcVar6[uVar4];
              pcVar7 = pcVar6 + uVar4;
              goto joined_r0x001d354e;
            }
          }
          break;
        }
        iVar2 = ossl_ctype_check(cVar5,8);
        if (iVar2 == 0) goto LAB_001d353a;
        pcVar6 = pcVar6 + 1;
        cVar5 = *pcVar6;
      }
      goto LAB_001d3806;
    }
    goto LAB_001d33b6;
  }
  goto LAB_001d3694;
joined_r0x001d3386:
  pcVar8 = pcVar6;
  if (cVar5 == '\"') goto LAB_001d37b2;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) {
    cVar5 = pcVar10[1];
    goto joined_r0x001d33b2;
  }
  pcVar8 = pcVar7 + -1;
  *pcVar7 = '\0';
  if (pcVar8 < pcVar6) goto LAB_001d3782;
  cVar5 = *pcVar8;
  pcVar7 = pcVar8;
  goto joined_r0x001d3386;
joined_r0x001d35e2:
  if (cVar5 == '\"') goto LAB_001d37cc;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) goto LAB_001d3604;
  pcVar9 = pcVar7 + -1;
  *pcVar7 = '\0';
  if (pcVar9 < pcVar6) goto LAB_001d37aa;
  cVar5 = *pcVar9;
  pcVar7 = pcVar9;
  goto joined_r0x001d35e2;
LAB_001d37cc:
  if (pcVar6 == pcVar7 + -1) {
LAB_001d37aa:
    pcVar6 = (char *)0x0;
  }
  else {
    *pcVar7 = '\0';
  }
LAB_001d3604:
  ptr = (undefined4 *)mime_hdr_new(pcVar8,pcVar6);
  if (ptr == (undefined4 *)0x0) goto LAB_001d346e;
  iVar2 = OPENSSL_sk_push(iVar1,ptr);
  if (iVar2 != 0) {
    cVar5 = pcVar10[1];
    pcVar6 = pcVar10 + 1;
    pcVar10 = pcVar6;
    if (cVar5 != '\0') {
LAB_001d3630:
      pcVar10 = pcVar6;
      pcVar7 = pcVar6;
      if (cVar5 != '\r' && cVar5 != '\n') {
switchD_001d331c_caseD_4:
        while (cVar5 != '=') {
          pcVar10 = pcVar7 + 1;
          cVar5 = *pcVar10;
          if ((cVar5 == '\0') || (pcVar7 = pcVar10, cVar5 == '\r' || cVar5 == '\n'))
          goto LAB_001d3694;
        }
        *pcVar7 = '\0';
        cVar5 = *pcVar6;
        while (cVar5 != '\0') {
          if (cVar5 == '\"') {
            if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001d34cc:
              sVar3 = strlen(pcVar6);
              uVar4 = sVar3 - 1;
              if (!CARRY4((uint)pcVar6,uVar4)) {
                cVar5 = pcVar6[uVar4];
                pcVar10 = pcVar6 + uVar4;
                goto joined_r0x001d34e0;
              }
            }
            break;
          }
          iVar2 = ossl_ctype_check(cVar5,8);
          if (iVar2 == 0) goto LAB_001d34cc;
          pcVar6 = pcVar6 + 1;
          cVar5 = *pcVar6;
        }
        goto LAB_001d3796;
      }
    }
    goto LAB_001d3694;
  }
  goto LAB_001d3430;
joined_r0x001d34e0:
  pcVar8 = pcVar6;
  if (cVar5 == '\"') goto LAB_001d37e8;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) {
    cVar5 = pcVar7[1];
    goto joined_r0x001d350c;
  }
  pcVar8 = pcVar10 + -1;
  *pcVar10 = '\0';
  if (pcVar8 < pcVar6) goto LAB_001d3796;
  cVar5 = *pcVar8;
  pcVar10 = pcVar8;
  goto joined_r0x001d34e0;
LAB_001d37e8:
  if (pcVar6 == pcVar10 + -1) {
LAB_001d3796:
    cVar5 = pcVar7[1];
    pcVar8 = (char *)0x0;
  }
  else {
    *pcVar10 = '\0';
    cVar5 = pcVar7[1];
  }
joined_r0x001d350c:
  pcVar10 = pcVar7 + 1;
  while( true ) {
    pcVar6 = pcVar7 + 1;
    if ((cVar5 == '\0') || (pcVar6 = pcVar7 + 1, cVar5 == '\r' || cVar5 == '\n')) goto LAB_001d3510;
    if (cVar5 == ';') break;
    if (cVar5 == '\"') {
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
      while( true ) {
        if ((cVar5 == '\0') || (cVar5 == '\r' || cVar5 == '\n')) goto LAB_001d3694;
        if (cVar5 == '\"') break;
        pcVar10 = pcVar10 + 1;
        cVar5 = *pcVar10;
      }
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
    }
    else {
      if (cVar5 == '(') {
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
        if ((cVar5 == '\0') || (cVar5 == '\r' || cVar5 == '\n')) goto LAB_001d3694;
        iVar2 = 4;
        goto LAB_001d3680;
      }
      pcVar10 = pcVar10 + 1;
      cVar5 = *pcVar10;
    }
  }
  *pcVar10 = '\0';
  cVar5 = *pcVar6;
  pcVar7 = pcVar6;
  while (cVar5 != '\0') {
    if (cVar5 == '\"') {
      if ((pcVar7[1] != '\0') && (pcVar7 = pcVar7 + 1, pcVar7 != (char *)0x0)) {
LAB_001d3734:
        sVar3 = strlen(pcVar7);
        uVar4 = sVar3 - 1;
        if (!CARRY4((uint)pcVar7,uVar4)) {
          cVar5 = pcVar7[uVar4];
          pcVar6 = pcVar7 + uVar4;
          goto joined_r0x001d3746;
        }
      }
      break;
    }
    iVar2 = ossl_ctype_check(cVar5,8);
    if (iVar2 == 0) goto LAB_001d3734;
    pcVar7 = pcVar7 + 1;
    cVar5 = *pcVar7;
  }
LAB_001d37ae:
  pcVar7 = (char *)0x0;
LAB_001d3764:
  pcVar6 = pcVar10 + 1;
  mime_hdr_addparam_isra_1(ptr + 2,pcVar8,pcVar7);
  cVar5 = pcVar10[1];
  pcVar10 = pcVar6;
  if (cVar5 == '\0') goto LAB_001d3694;
  goto LAB_001d3630;
joined_r0x001d3746:
  if (cVar5 == '\"') goto LAB_001d37da;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) goto LAB_001d3764;
  pcVar9 = pcVar6 + -1;
  *pcVar6 = '\0';
  if (pcVar9 < pcVar7) goto LAB_001d37ae;
  cVar5 = *pcVar9;
  pcVar6 = pcVar9;
  goto joined_r0x001d3746;
LAB_001d37da:
  if (pcVar7 != pcVar6 + -1) {
    *pcVar6 = '\0';
    goto LAB_001d3764;
  }
  goto LAB_001d37ae;
joined_r0x001d354e:
  if (cVar5 == '\"') goto LAB_001d3828;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) {
    mime_hdr_addparam_isra_1(ptr + 2,pcVar8,pcVar6);
    goto LAB_001d3694;
  }
  pcVar9 = pcVar7 + -1;
  *pcVar7 = '\0';
  if (pcVar9 < pcVar6) goto LAB_001d3806;
  cVar5 = *pcVar9;
  pcVar7 = pcVar9;
  goto joined_r0x001d354e;
LAB_001d3828:
  if (pcVar6 == pcVar7 + -1) {
LAB_001d3806:
    mime_hdr_addparam_isra_1(ptr + 2,pcVar8,0);
  }
  else {
    *pcVar7 = '\0';
    mime_hdr_addparam_isra_1(ptr + 2,pcVar8,pcVar6);
  }
  goto LAB_001d3694;
joined_r0x001d33f4:
  if (cVar5 == '\"') goto LAB_001d3816;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) goto LAB_001d3416;
  pcVar9 = pcVar7 + -1;
  *pcVar7 = '\0';
  if (pcVar9 < pcVar6) goto LAB_001d3802;
  cVar5 = *pcVar9;
  pcVar7 = pcVar9;
  goto joined_r0x001d33f4;
LAB_001d3816:
  if (pcVar6 == pcVar7 + -1) goto LAB_001d3802;
  *pcVar7 = '\0';
  goto LAB_001d3416;
LAB_001d37b2:
  if (pcVar6 != pcVar7 + -1) {
    *pcVar7 = '\0';
    pcVar10 = pcVar10 + 1;
    cVar5 = *pcVar10;
    pcVar6 = pcVar10;
    goto joined_r0x001d37c6;
  }
LAB_001d3782:
  cVar5 = pcVar10[1];
  pcVar8 = (char *)0x0;
joined_r0x001d33b2:
  pcVar6 = pcVar10 + 1;
  pcVar10 = pcVar6;
  if (cVar5 != '\0') {
    while( true ) {
      if (cVar5 == '\r' || cVar5 == '\n') goto LAB_001d33b6;
      if (cVar5 == ';') goto LAB_001d35a0;
LAB_001d3582:
      if (cVar5 == '(') break;
      pcVar10 = pcVar10 + 1;
      cVar5 = *pcVar10;
joined_r0x001d37c6:
      if (cVar5 == '\0') goto LAB_001d33b6;
    }
    cVar5 = pcVar10[1];
    pcVar10 = pcVar10 + 1;
    if ((cVar5 != '\0') && (cVar5 != '\r' && cVar5 != '\n')) {
      iVar2 = 2;
LAB_001d3680:
      do {
        if (cVar5 == ')') goto switchD_001d331c_default;
        pcVar10 = pcVar10 + 1;
        cVar5 = *pcVar10;
        if ((cVar5 == '\0') || (cVar5 == '\r' || cVar5 == '\n')) break;
      } while( true );
    }
    goto LAB_001d3694;
  }
LAB_001d33b6:
  cVar5 = *pcVar6;
  while (cVar5 != '\0') {
    if (cVar5 == '\"') {
      if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001d33e0:
        sVar3 = strlen(pcVar6);
        uVar4 = sVar3 - 1;
        if (!CARRY4((uint)pcVar6,uVar4)) {
          cVar5 = pcVar6[uVar4];
          pcVar7 = pcVar6 + uVar4;
          goto joined_r0x001d33f4;
        }
      }
      break;
    }
    iVar2 = ossl_ctype_check(cVar5,8);
    if (iVar2 == 0) goto LAB_001d33e0;
    pcVar6 = pcVar6 + 1;
    cVar5 = *pcVar6;
  }
LAB_001d3802:
  pcVar6 = (char *)0x0;
LAB_001d3416:
  ptr = (undefined4 *)mime_hdr_new(pcVar8,pcVar6);
  if (ptr != (undefined4 *)0x0) {
    iVar2 = OPENSSL_sk_push(iVar1,ptr);
    if (iVar2 != 0) {
LAB_001d3694:
      if (pcVar10 == local_428) {
        return iVar1;
      }
      goto LAB_001d32d2;
    }
LAB_001d3430:
    CRYPTO_free((void *)*ptr);
    CRYPTO_free((void *)ptr[1]);
    if (ptr[2] != 0) {
      OPENSSL_sk_pop_free(ptr[2],0x1d2ef5);
    }
    CRYPTO_free(ptr);
  }
LAB_001d346e:
  OPENSSL_sk_pop_free(iVar1,0x1d2f71);
  return 0;
}

