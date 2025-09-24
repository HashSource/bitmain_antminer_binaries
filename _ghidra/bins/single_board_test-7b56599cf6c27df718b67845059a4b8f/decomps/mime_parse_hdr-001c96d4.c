
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
  
  iVar1 = OPENSSL_sk_new(0x1c9351);
  if (iVar1 == 0) {
    return 0;
  }
  ptr = (undefined4 *)0x0;
LAB_001c96fa:
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
          if ((cVar5 == '\0') || (cVar5 == '\r' || cVar5 == '\n')) goto LAB_001c9abc;
        }
        *pcVar10 = '\0';
        cVar5 = *pcVar6;
        while (cVar5 != '\0') {
          if (cVar5 == '\"') {
            if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001c979a:
              sVar3 = strlen(pcVar6);
              uVar4 = sVar3 - 1;
              if (!CARRY4((uint)pcVar6,uVar4)) {
                cVar5 = pcVar6[uVar4];
                pcVar7 = pcVar6 + uVar4;
                goto joined_r0x001c97ae;
              }
            }
            break;
          }
          iVar2 = ossl_ctype_check(cVar5,8);
          if (iVar2 == 0) goto LAB_001c979a;
          pcVar6 = pcVar6 + 1;
          cVar5 = *pcVar6;
        }
        goto LAB_001c9baa;
      case 3:
        if (cVar5 != ';') goto LAB_001c99aa;
LAB_001c99c8:
        *pcVar10 = '\0';
        cVar5 = *pcVar6;
        while (cVar5 != '\0') {
          if (cVar5 == '\"') {
            if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001c99f6:
              sVar3 = strlen(pcVar6);
              uVar4 = sVar3 - 1;
              if (!CARRY4((uint)pcVar6,uVar4)) {
                cVar5 = pcVar6[uVar4];
                pcVar7 = pcVar6 + uVar4;
                goto joined_r0x001c9a0a;
              }
            }
            break;
          }
          iVar2 = ossl_ctype_check(cVar5,8);
          if (iVar2 == 0) goto LAB_001c99f6;
          pcVar6 = pcVar6 + 1;
          cVar5 = *pcVar6;
        }
        goto LAB_001c9bd2;
      case 4:
        goto switchD_001c9744_caseD_4;
      }
switchD_001c9744_default:
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
    } while ((cVar5 != '\0') && (cVar5 != '\r' && cVar5 != '\n'));
    if (iVar2 != 2) {
      if (iVar2 != 4) goto LAB_001c9abc;
LAB_001c9938:
      cVar5 = *pcVar6;
      while (cVar5 != '\0') {
        if (cVar5 == '\"') {
          if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001c9962:
            sVar3 = strlen(pcVar6);
            uVar4 = sVar3 - 1;
            if (!CARRY4((uint)pcVar6,uVar4)) {
              cVar5 = pcVar6[uVar4];
              pcVar7 = pcVar6 + uVar4;
              goto joined_r0x001c9976;
            }
          }
          break;
        }
        iVar2 = ossl_ctype_check(cVar5,8);
        if (iVar2 == 0) goto LAB_001c9962;
        pcVar6 = pcVar6 + 1;
        cVar5 = *pcVar6;
      }
      goto LAB_001c9c2e;
    }
    goto LAB_001c97de;
  }
  goto LAB_001c9abc;
joined_r0x001c97ae:
  pcVar8 = pcVar6;
  if (cVar5 == '\"') goto LAB_001c9bda;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) {
    cVar5 = pcVar10[1];
    goto joined_r0x001c97da;
  }
  pcVar8 = pcVar7 + -1;
  *pcVar7 = '\0';
  if (pcVar8 < pcVar6) goto LAB_001c9baa;
  cVar5 = *pcVar8;
  pcVar7 = pcVar8;
  goto joined_r0x001c97ae;
joined_r0x001c9a0a:
  if (cVar5 == '\"') goto LAB_001c9bf4;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) goto LAB_001c9a2c;
  pcVar9 = pcVar7 + -1;
  *pcVar7 = '\0';
  if (pcVar9 < pcVar6) goto LAB_001c9bd2;
  cVar5 = *pcVar9;
  pcVar7 = pcVar9;
  goto joined_r0x001c9a0a;
LAB_001c9bf4:
  if (pcVar6 == pcVar7 + -1) {
LAB_001c9bd2:
    pcVar6 = (char *)0x0;
  }
  else {
    *pcVar7 = '\0';
  }
LAB_001c9a2c:
  ptr = (undefined4 *)mime_hdr_new(pcVar8,pcVar6);
  if (ptr == (undefined4 *)0x0) goto LAB_001c9896;
  iVar2 = OPENSSL_sk_push(iVar1,ptr);
  if (iVar2 != 0) {
    cVar5 = pcVar10[1];
    pcVar6 = pcVar10 + 1;
    pcVar10 = pcVar6;
    if (cVar5 != '\0') {
LAB_001c9a58:
      pcVar10 = pcVar6;
      pcVar7 = pcVar6;
      if (cVar5 != '\r' && cVar5 != '\n') {
switchD_001c9744_caseD_4:
        while (cVar5 != '=') {
          pcVar10 = pcVar7 + 1;
          cVar5 = *pcVar10;
          if ((cVar5 == '\0') || (pcVar7 = pcVar10, cVar5 == '\r' || cVar5 == '\n'))
          goto LAB_001c9abc;
        }
        *pcVar7 = '\0';
        cVar5 = *pcVar6;
        while (cVar5 != '\0') {
          if (cVar5 == '\"') {
            if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001c98f4:
              sVar3 = strlen(pcVar6);
              uVar4 = sVar3 - 1;
              if (!CARRY4((uint)pcVar6,uVar4)) {
                cVar5 = pcVar6[uVar4];
                pcVar10 = pcVar6 + uVar4;
                goto joined_r0x001c9908;
              }
            }
            break;
          }
          iVar2 = ossl_ctype_check(cVar5,8);
          if (iVar2 == 0) goto LAB_001c98f4;
          pcVar6 = pcVar6 + 1;
          cVar5 = *pcVar6;
        }
        goto LAB_001c9bbe;
      }
    }
    goto LAB_001c9abc;
  }
  goto LAB_001c9858;
joined_r0x001c9908:
  pcVar8 = pcVar6;
  if (cVar5 == '\"') goto LAB_001c9c10;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) {
    cVar5 = pcVar7[1];
    goto joined_r0x001c9934;
  }
  pcVar8 = pcVar10 + -1;
  *pcVar10 = '\0';
  if (pcVar8 < pcVar6) goto LAB_001c9bbe;
  cVar5 = *pcVar8;
  pcVar10 = pcVar8;
  goto joined_r0x001c9908;
LAB_001c9c10:
  if (pcVar6 == pcVar10 + -1) {
LAB_001c9bbe:
    cVar5 = pcVar7[1];
    pcVar8 = (char *)0x0;
  }
  else {
    *pcVar10 = '\0';
    cVar5 = pcVar7[1];
  }
joined_r0x001c9934:
  pcVar10 = pcVar7 + 1;
  while( true ) {
    pcVar6 = pcVar7 + 1;
    if ((cVar5 == '\0') || (pcVar6 = pcVar7 + 1, cVar5 == '\r' || cVar5 == '\n')) goto LAB_001c9938;
    if (cVar5 == ';') break;
    if (cVar5 == '\"') {
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
      while( true ) {
        if ((cVar5 == '\0') || (cVar5 == '\r' || cVar5 == '\n')) goto LAB_001c9abc;
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
        if ((cVar5 == '\0') || (cVar5 == '\r' || cVar5 == '\n')) goto LAB_001c9abc;
        iVar2 = 4;
        goto LAB_001c9aa8;
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
LAB_001c9b5c:
        sVar3 = strlen(pcVar7);
        uVar4 = sVar3 - 1;
        if (!CARRY4((uint)pcVar7,uVar4)) {
          cVar5 = pcVar7[uVar4];
          pcVar6 = pcVar7 + uVar4;
          goto joined_r0x001c9b6e;
        }
      }
      break;
    }
    iVar2 = ossl_ctype_check(cVar5,8);
    if (iVar2 == 0) goto LAB_001c9b5c;
    pcVar7 = pcVar7 + 1;
    cVar5 = *pcVar7;
  }
LAB_001c9bd6:
  pcVar7 = (char *)0x0;
LAB_001c9b8c:
  pcVar6 = pcVar10 + 1;
  mime_hdr_addparam_isra_1(ptr + 2,pcVar8,pcVar7);
  cVar5 = pcVar10[1];
  pcVar10 = pcVar6;
  if (cVar5 == '\0') goto LAB_001c9abc;
  goto LAB_001c9a58;
joined_r0x001c9b6e:
  if (cVar5 == '\"') goto LAB_001c9c02;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) goto LAB_001c9b8c;
  pcVar9 = pcVar6 + -1;
  *pcVar6 = '\0';
  if (pcVar9 < pcVar7) goto LAB_001c9bd6;
  cVar5 = *pcVar9;
  pcVar6 = pcVar9;
  goto joined_r0x001c9b6e;
LAB_001c9c02:
  if (pcVar7 != pcVar6 + -1) {
    *pcVar6 = '\0';
    goto LAB_001c9b8c;
  }
  goto LAB_001c9bd6;
joined_r0x001c9976:
  if (cVar5 == '\"') goto LAB_001c9c50;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) {
    mime_hdr_addparam_isra_1(ptr + 2,pcVar8,pcVar6);
    goto LAB_001c9abc;
  }
  pcVar9 = pcVar7 + -1;
  *pcVar7 = '\0';
  if (pcVar9 < pcVar6) goto LAB_001c9c2e;
  cVar5 = *pcVar9;
  pcVar7 = pcVar9;
  goto joined_r0x001c9976;
LAB_001c9c50:
  if (pcVar6 == pcVar7 + -1) {
LAB_001c9c2e:
    mime_hdr_addparam_isra_1(ptr + 2,pcVar8,0);
  }
  else {
    *pcVar7 = '\0';
    mime_hdr_addparam_isra_1(ptr + 2,pcVar8,pcVar6);
  }
  goto LAB_001c9abc;
joined_r0x001c981c:
  if (cVar5 == '\"') goto LAB_001c9c3e;
  iVar2 = ossl_ctype_check(cVar5,8);
  if (iVar2 == 0) goto LAB_001c983e;
  pcVar9 = pcVar7 + -1;
  *pcVar7 = '\0';
  if (pcVar9 < pcVar6) goto LAB_001c9c2a;
  cVar5 = *pcVar9;
  pcVar7 = pcVar9;
  goto joined_r0x001c981c;
LAB_001c9c3e:
  if (pcVar6 == pcVar7 + -1) goto LAB_001c9c2a;
  *pcVar7 = '\0';
  goto LAB_001c983e;
LAB_001c9bda:
  if (pcVar6 != pcVar7 + -1) {
    *pcVar7 = '\0';
    pcVar10 = pcVar10 + 1;
    cVar5 = *pcVar10;
    pcVar6 = pcVar10;
    goto joined_r0x001c9bee;
  }
LAB_001c9baa:
  cVar5 = pcVar10[1];
  pcVar8 = (char *)0x0;
joined_r0x001c97da:
  pcVar6 = pcVar10 + 1;
  pcVar10 = pcVar6;
  if (cVar5 != '\0') {
    while( true ) {
      if (cVar5 == '\r' || cVar5 == '\n') goto LAB_001c97de;
      if (cVar5 == ';') goto LAB_001c99c8;
LAB_001c99aa:
      if (cVar5 == '(') break;
      pcVar10 = pcVar10 + 1;
      cVar5 = *pcVar10;
joined_r0x001c9bee:
      if (cVar5 == '\0') goto LAB_001c97de;
    }
    cVar5 = pcVar10[1];
    pcVar10 = pcVar10 + 1;
    if ((cVar5 != '\0') && (cVar5 != '\r' && cVar5 != '\n')) {
      iVar2 = 2;
LAB_001c9aa8:
      do {
        if (cVar5 == ')') goto switchD_001c9744_default;
        pcVar10 = pcVar10 + 1;
        cVar5 = *pcVar10;
        if ((cVar5 == '\0') || (cVar5 == '\r' || cVar5 == '\n')) break;
      } while( true );
    }
    goto LAB_001c9abc;
  }
LAB_001c97de:
  cVar5 = *pcVar6;
  while (cVar5 != '\0') {
    if (cVar5 == '\"') {
      if ((pcVar6[1] != '\0') && (pcVar6 = pcVar6 + 1, pcVar6 != (char *)0x0)) {
LAB_001c9808:
        sVar3 = strlen(pcVar6);
        uVar4 = sVar3 - 1;
        if (!CARRY4((uint)pcVar6,uVar4)) {
          cVar5 = pcVar6[uVar4];
          pcVar7 = pcVar6 + uVar4;
          goto joined_r0x001c981c;
        }
      }
      break;
    }
    iVar2 = ossl_ctype_check(cVar5,8);
    if (iVar2 == 0) goto LAB_001c9808;
    pcVar6 = pcVar6 + 1;
    cVar5 = *pcVar6;
  }
LAB_001c9c2a:
  pcVar6 = (char *)0x0;
LAB_001c983e:
  ptr = (undefined4 *)mime_hdr_new(pcVar8,pcVar6);
  if (ptr != (undefined4 *)0x0) {
    iVar2 = OPENSSL_sk_push(iVar1,ptr);
    if (iVar2 != 0) {
LAB_001c9abc:
      if (pcVar10 == local_428) {
        return iVar1;
      }
      goto LAB_001c96fa;
    }
LAB_001c9858:
    CRYPTO_free((void *)*ptr);
    CRYPTO_free((void *)ptr[1]);
    if (ptr[2] != 0) {
      OPENSSL_sk_pop_free(ptr[2],0x1c931d);
    }
    CRYPTO_free(ptr);
  }
LAB_001c9896:
  OPENSSL_sk_pop_free(iVar1,0x1c9399);
  return 0;
}

