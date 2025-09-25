
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
  
  iVar1 = OPENSSL_sk_new(0x1c5101);
  if (iVar1 == 0) {
    return 0;
  }
  ptr = (undefined4 *)0x0;
LAB_001c54aa:
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
          if ((cVar5 == '\0') || (cVar5 == '\r' || cVar5 == '\n')) goto LAB_001c586c;
        }
        *pcVar10 = '\0';
        cVar5 = *pcVar6;
        while (cVar5 != '\0') {
          if (cVar5 == '\"') {
            if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001c554a:
              sVar3 = strlen(pcVar6);
              uVar4 = sVar3 - 1;
              if (!CARRY4((uint)pcVar6,uVar4)) {
                cVar5 = pcVar6[uVar4];
                pcVar7 = pcVar6 + uVar4;
                goto joined_r0x001c555e;
              }
            }
            break;
          }
          iVar2 = ossl_ctype_check(cVar5,8);
          if (iVar2 == 0) goto LAB_001c554a;
          pcVar6 = pcVar6 + 1;
          cVar5 = *pcVar6;
        }
        goto LAB_001c595a;
      case 3:
        if (cVar5 != ';') goto LAB_001c575a;
LAB_001c5778:
        *pcVar10 = '\0';
        cVar5 = *pcVar6;
        while (cVar5 != '\0') {
          if (cVar5 == '\"') {
            if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001c57a6:
              sVar3 = strlen(pcVar6);
              uVar4 = sVar3 - 1;
              if (!CARRY4((uint)pcVar6,uVar4)) {
                cVar5 = pcVar6[uVar4];
                pcVar7 = pcVar6 + uVar4;
                goto joined_r0x001c57ba;
              }
            }
            break;
          }
          iVar2 = ossl_ctype_check(cVar5,8);
          if (iVar2 == 0) goto LAB_001c57a6;
          pcVar6 = pcVar6 + 1;
          cVar5 = *pcVar6;
        }
        goto LAB_001c5982;
      case 4:
        goto switchD_001c54f4_caseD_4;
      }
switchD_001c54f4_default:
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
    } while ((cVar5 != '\0') && (cVar5 != '\r' && cVar5 != '\n'));
    if (iVar2 != 2) {
      if (iVar2 != 4) goto LAB_001c586c;
LAB_001c56e8:
      cVar5 = *pcVar6;
      while (cVar5 != '\0') {
        if (cVar5 == '\"') {
          if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001c5712:
            sVar3 = strlen(pcVar6);
            uVar4 = sVar3 - 1;
            if (!CARRY4((uint)pcVar6,uVar4)) {
              cVar5 = pcVar6[uVar4];
              pcVar7 = pcVar6 + uVar4;
              goto joined_r0x001c5726;
            }
          }
          break;
        }
        iVar2 = ossl_ctype_check(cVar5,8);
        if (iVar2 == 0) goto LAB_001c5712;
        pcVar6 = pcVar6 + 1;
        cVar5 = *pcVar6;
      }
      goto LAB_001c59de;
    }
    goto LAB_001c558e;
  }
  goto LAB_001c586c;
joined_r0x001c555e:
  pcVar8 = pcVar6;
  if (cVar5 == '\"') goto LAB_001c598a;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) {
    cVar5 = pcVar10[1];
    goto joined_r0x001c558a;
  }
  pcVar8 = pcVar7 + -1;
  *pcVar7 = '\0';
  if (pcVar8 < pcVar6) goto LAB_001c595a;
  cVar5 = *pcVar8;
  pcVar7 = pcVar8;
  goto joined_r0x001c555e;
joined_r0x001c57ba:
  if (cVar5 == '\"') goto LAB_001c59a4;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) goto LAB_001c57dc;
  pcVar9 = pcVar7 + -1;
  *pcVar7 = '\0';
  if (pcVar9 < pcVar6) goto LAB_001c5982;
  cVar5 = *pcVar9;
  pcVar7 = pcVar9;
  goto joined_r0x001c57ba;
LAB_001c59a4:
  if (pcVar6 == pcVar7 + -1) {
LAB_001c5982:
    pcVar6 = (char *)0x0;
  }
  else {
    *pcVar7 = '\0';
  }
LAB_001c57dc:
  ptr = (undefined4 *)mime_hdr_new(pcVar8,pcVar6);
  if (ptr == (undefined4 *)0x0) goto LAB_001c5646;
  iVar2 = OPENSSL_sk_push(iVar1,ptr);
  if (iVar2 != 0) {
    cVar5 = pcVar10[1];
    pcVar6 = pcVar10 + 1;
    pcVar10 = pcVar6;
    if (cVar5 != '\0') {
LAB_001c5808:
      pcVar10 = pcVar6;
      pcVar7 = pcVar6;
      if (cVar5 != '\r' && cVar5 != '\n') {
switchD_001c54f4_caseD_4:
        while (cVar5 != '=') {
          pcVar10 = pcVar7 + 1;
          cVar5 = *pcVar10;
          if ((cVar5 == '\0') || (pcVar7 = pcVar10, cVar5 == '\r' || cVar5 == '\n'))
          goto LAB_001c586c;
        }
        *pcVar7 = '\0';
        cVar5 = *pcVar6;
        while (cVar5 != '\0') {
          if (cVar5 == '\"') {
            if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001c56a4:
              sVar3 = strlen(pcVar6);
              uVar4 = sVar3 - 1;
              if (!CARRY4((uint)pcVar6,uVar4)) {
                cVar5 = pcVar6[uVar4];
                pcVar10 = pcVar6 + uVar4;
                goto joined_r0x001c56b8;
              }
            }
            break;
          }
          iVar2 = ossl_ctype_check(cVar5,8);
          if (iVar2 == 0) goto LAB_001c56a4;
          pcVar6 = pcVar6 + 1;
          cVar5 = *pcVar6;
        }
        goto LAB_001c596e;
      }
    }
    goto LAB_001c586c;
  }
  goto LAB_001c5608;
joined_r0x001c56b8:
  pcVar8 = pcVar6;
  if (cVar5 == '\"') goto LAB_001c59c0;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) {
    cVar5 = pcVar7[1];
    goto joined_r0x001c56e4;
  }
  pcVar8 = pcVar10 + -1;
  *pcVar10 = '\0';
  if (pcVar8 < pcVar6) goto LAB_001c596e;
  cVar5 = *pcVar8;
  pcVar10 = pcVar8;
  goto joined_r0x001c56b8;
LAB_001c59c0:
  if (pcVar6 == pcVar10 + -1) {
LAB_001c596e:
    cVar5 = pcVar7[1];
    pcVar8 = (char *)0x0;
  }
  else {
    *pcVar10 = '\0';
    cVar5 = pcVar7[1];
  }
joined_r0x001c56e4:
  pcVar10 = pcVar7 + 1;
  while( true ) {
    pcVar6 = pcVar7 + 1;
    if ((cVar5 == '\0') || (pcVar6 = pcVar7 + 1, cVar5 == '\r' || cVar5 == '\n')) goto LAB_001c56e8;
    if (cVar5 == ';') break;
    if (cVar5 == '\"') {
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
      while( true ) {
        if ((cVar5 == '\0') || (cVar5 == '\r' || cVar5 == '\n')) goto LAB_001c586c;
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
        if ((cVar5 == '\0') || (cVar5 == '\r' || cVar5 == '\n')) goto LAB_001c586c;
        iVar2 = 4;
        goto LAB_001c5858;
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
LAB_001c590c:
        sVar3 = strlen(pcVar7);
        uVar4 = sVar3 - 1;
        if (!CARRY4((uint)pcVar7,uVar4)) {
          cVar5 = pcVar7[uVar4];
          pcVar6 = pcVar7 + uVar4;
          goto joined_r0x001c591e;
        }
      }
      break;
    }
    iVar2 = ossl_ctype_check(cVar5,8);
    if (iVar2 == 0) goto LAB_001c590c;
    pcVar7 = pcVar7 + 1;
    cVar5 = *pcVar7;
  }
LAB_001c5986:
  pcVar7 = (char *)0x0;
LAB_001c593c:
  pcVar6 = pcVar10 + 1;
  mime_hdr_addparam_isra_1(ptr + 2,pcVar8,pcVar7);
  cVar5 = pcVar10[1];
  pcVar10 = pcVar6;
  if (cVar5 == '\0') goto LAB_001c586c;
  goto LAB_001c5808;
joined_r0x001c591e:
  if (cVar5 == '\"') goto LAB_001c59b2;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) goto LAB_001c593c;
  pcVar9 = pcVar6 + -1;
  *pcVar6 = '\0';
  if (pcVar9 < pcVar7) goto LAB_001c5986;
  cVar5 = *pcVar9;
  pcVar6 = pcVar9;
  goto joined_r0x001c591e;
LAB_001c59b2:
  if (pcVar7 != pcVar6 + -1) {
    *pcVar6 = '\0';
    goto LAB_001c593c;
  }
  goto LAB_001c5986;
joined_r0x001c5726:
  if (cVar5 == '\"') goto LAB_001c5a00;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) {
    mime_hdr_addparam_isra_1(ptr + 2,pcVar8,pcVar6);
    goto LAB_001c586c;
  }
  pcVar9 = pcVar7 + -1;
  *pcVar7 = '\0';
  if (pcVar9 < pcVar6) goto LAB_001c59de;
  cVar5 = *pcVar9;
  pcVar7 = pcVar9;
  goto joined_r0x001c5726;
LAB_001c5a00:
  if (pcVar6 == pcVar7 + -1) {
LAB_001c59de:
    mime_hdr_addparam_isra_1(ptr + 2,pcVar8,0);
  }
  else {
    *pcVar7 = '\0';
    mime_hdr_addparam_isra_1(ptr + 2,pcVar8,pcVar6);
  }
  goto LAB_001c586c;
joined_r0x001c55cc:
  if (cVar5 == '\"') goto LAB_001c59ee;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) goto LAB_001c55ee;
  pcVar9 = pcVar7 + -1;
  *pcVar7 = '\0';
  if (pcVar9 < pcVar6) goto LAB_001c59da;
  cVar5 = *pcVar9;
  pcVar7 = pcVar9;
  goto joined_r0x001c55cc;
LAB_001c59ee:
  if (pcVar6 == pcVar7 + -1) goto LAB_001c59da;
  *pcVar7 = '\0';
  goto LAB_001c55ee;
LAB_001c598a:
  if (pcVar6 != pcVar7 + -1) {
    *pcVar7 = '\0';
    pcVar10 = pcVar10 + 1;
    cVar5 = *pcVar10;
    pcVar6 = pcVar10;
    goto joined_r0x001c599e;
  }
LAB_001c595a:
  cVar5 = pcVar10[1];
  pcVar8 = (char *)0x0;
joined_r0x001c558a:
  pcVar6 = pcVar10 + 1;
  pcVar10 = pcVar6;
  if (cVar5 != '\0') {
    while( true ) {
      if (cVar5 == '\r' || cVar5 == '\n') goto LAB_001c558e;
      if (cVar5 == ';') goto LAB_001c5778;
LAB_001c575a:
      if (cVar5 == '(') break;
      pcVar10 = pcVar10 + 1;
      cVar5 = *pcVar10;
joined_r0x001c599e:
      if (cVar5 == '\0') goto LAB_001c558e;
    }
    cVar5 = pcVar10[1];
    pcVar10 = pcVar10 + 1;
    if ((cVar5 != '\0') && (cVar5 != '\r' && cVar5 != '\n')) {
      iVar2 = 2;
LAB_001c5858:
      do {
        if (cVar5 == ')') goto switchD_001c54f4_default;
        pcVar10 = pcVar10 + 1;
        cVar5 = *pcVar10;
        if ((cVar5 == '\0') || (cVar5 == '\r' || cVar5 == '\n')) break;
      } while( true );
    }
    goto LAB_001c586c;
  }
LAB_001c558e:
  cVar5 = *pcVar6;
  while (cVar5 != '\0') {
    if (cVar5 == '\"') {
      if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001c55b8:
        sVar3 = strlen(pcVar6);
        uVar4 = sVar3 - 1;
        if (!CARRY4((uint)pcVar6,uVar4)) {
          cVar5 = pcVar6[uVar4];
          pcVar7 = pcVar6 + uVar4;
          goto joined_r0x001c55cc;
        }
      }
      break;
    }
    iVar2 = ossl_ctype_check(cVar5,8);
    if (iVar2 == 0) goto LAB_001c55b8;
    pcVar6 = pcVar6 + 1;
    cVar5 = *pcVar6;
  }
LAB_001c59da:
  pcVar6 = (char *)0x0;
LAB_001c55ee:
  ptr = (undefined4 *)mime_hdr_new(pcVar8,pcVar6);
  if (ptr != (undefined4 *)0x0) {
    iVar2 = OPENSSL_sk_push(iVar1,ptr);
    if (iVar2 != 0) {
LAB_001c586c:
      if (pcVar10 == local_428) {
        return iVar1;
      }
      goto LAB_001c54aa;
    }
LAB_001c5608:
    CRYPTO_free((void *)*ptr);
    CRYPTO_free((void *)ptr[1]);
    if (ptr[2] != 0) {
      OPENSSL_sk_pop_free(ptr[2],0x1c50cd);
    }
    CRYPTO_free(ptr);
  }
LAB_001c5646:
  OPENSSL_sk_pop_free(iVar1,0x1c5149);
  return 0;
}

