
stack_st_CONF_VALUE * X509V3_parse_list(char *line)

{
  char cVar1;
  char *ptr;
  size_t sVar2;
  int iVar3;
  char cVar4;
  char *pcVar5;
  char *pcVar6;
  char *__s;
  char *pcVar7;
  char *pcVar8;
  stack_st_CONF_VALUE *local_2c [2];
  
  local_2c[0] = (stack_st_CONF_VALUE *)0x0;
  ptr = CRYPTO_strdup(line,"crypto/x509v3/v3_utl.c",0x141);
  if (ptr == (char *)0x0) {
    ERR_put_error(0x22,0x6d,0x41,"crypto/x509v3/v3_utl.c",0x143);
    goto LAB_0017a7a4;
  }
  cVar1 = *ptr;
  if (cVar1 != '\0') {
    __s = ptr;
    if (cVar1 != '\n' && cVar1 != '\r') {
      pcVar5 = ptr;
joined_r0x0017a5aa:
      do {
        if (cVar1 == ':') {
          *pcVar5 = '\0';
          cVar1 = *__s;
          if (cVar1 != '\0') {
            while (iVar3 = ossl_ctype_check(cVar1,8), iVar3 != 0) {
              __s = __s + 1;
              cVar1 = *__s;
              if (cVar1 == '\0') goto LAB_0017a790;
            }
            if (*__s != '\0') {
              sVar2 = strlen(__s);
              pcVar6 = __s + (sVar2 - 1);
              if (__s + (sVar2 - 1) != __s) {
                do {
                  pcVar8 = pcVar6 + -1;
                  iVar3 = ossl_ctype_check(*pcVar6,8);
                  if (iVar3 == 0) {
                    if (pcVar6 != __s) {
                      pcVar6[1] = '\0';
                    }
                    break;
                  }
                  pcVar6 = pcVar8;
                } while (__s != pcVar8);
                if (*__s == '\0') goto LAB_0017a790;
              }
              cVar1 = pcVar5[1];
              pcVar6 = pcVar5 + 1;
              if (cVar1 == '\0') goto LAB_0017a854;
              pcVar8 = pcVar6;
              cVar4 = cVar1;
              if (cVar1 == '\r' || cVar1 == '\n') goto LAB_0017a6d6;
              while (cVar4 != ',') {
                cVar4 = pcVar8[1];
                if ((cVar4 == '\0') || (pcVar8 = pcVar8 + 1, cVar4 == '\r' || cVar4 == '\n'))
                goto LAB_0017a6d6;
              }
              *pcVar8 = '\0';
              cVar1 = pcVar5[1];
              if (cVar1 != '\0') {
                while (iVar3 = ossl_ctype_check(cVar1,8), iVar3 != 0) {
                  pcVar6 = pcVar6 + 1;
                  cVar1 = *pcVar6;
                  if (cVar1 == '\0') goto LAB_0017a7c6;
                }
                if (*pcVar6 != '\0') {
                  sVar2 = strlen(pcVar6);
                  pcVar5 = pcVar6 + (sVar2 - 1);
                  if (pcVar6 + (sVar2 - 1) != pcVar6) {
                    do {
                      pcVar7 = pcVar5 + -1;
                      iVar3 = ossl_ctype_check(*pcVar5,8);
                      if (iVar3 == 0) {
                        pcVar5[1] = '\0';
                        break;
                      }
                      pcVar5 = pcVar7;
                    } while (pcVar6 != pcVar7);
                    if (*pcVar6 == '\0') goto LAB_0017a7c6;
                  }
                  X509V3_add_value(__s,pcVar6,local_2c);
                  cVar1 = pcVar8[1];
                  pcVar5 = pcVar8;
                  if (cVar1 != '\0') goto LAB_0017a6bc;
                  goto LAB_0017a786;
                }
              }
LAB_0017a7c6:
              ERR_put_error(0x22,0x6d,0x6d,"crypto/x509v3/v3_utl.c",0x16c);
              goto LAB_0017a7a4;
            }
          }
LAB_0017a790:
          iVar3 = 0x154;
          goto LAB_0017a798;
        }
        if (cVar1 == ',') {
          *pcVar5 = '\0';
          cVar1 = *__s;
          while( true ) {
            if (cVar1 == '\0') goto LAB_0017a7dc;
            iVar3 = ossl_ctype_check(cVar1,8);
            if (iVar3 == 0) break;
            __s = __s + 1;
            cVar1 = *__s;
          }
          if (*__s == '\0') {
LAB_0017a7dc:
            iVar3 = 0x15e;
            goto LAB_0017a798;
          }
          sVar2 = strlen(__s);
          pcVar6 = __s + (sVar2 - 1);
          if (__s + (sVar2 - 1) != __s) {
            do {
              pcVar8 = pcVar6 + -1;
              iVar3 = ossl_ctype_check(*pcVar6,8);
              if (iVar3 == 0) {
                pcVar6[1] = '\0';
                break;
              }
              pcVar6 = pcVar8;
            } while (__s != pcVar8);
            if (*__s == '\0') goto LAB_0017a7dc;
          }
          X509V3_add_value(__s,(char *)0x0,local_2c);
          cVar1 = pcVar5[1];
          if (cVar1 == '\0') goto LAB_0017a786;
LAB_0017a6bc:
          __s = pcVar5 + 1;
          pcVar5 = __s;
          if (cVar1 == '\r' || cVar1 == '\n') break;
          goto joined_r0x0017a5aa;
        }
        cVar1 = pcVar5[1];
        pcVar5 = pcVar5 + 1;
        if ((cVar1 == '\0') || (cVar1 == '\n' || cVar1 == '\r')) {
          cVar1 = *__s;
          goto joined_r0x0017a7e8;
        }
      } while( true );
    }
    do {
      iVar3 = ossl_ctype_check(cVar1,8);
      if (iVar3 == 0) {
        if (*__s != '\0') {
          sVar2 = strlen(__s);
          pcVar5 = __s + (sVar2 - 1);
          if (__s + (sVar2 - 1) != __s) goto LAB_0017a818;
          goto LAB_0017a834;
        }
        break;
      }
      __s = __s + 1;
      cVar1 = *__s;
joined_r0x0017a7e8:
    } while (cVar1 != '\0');
  }
  goto LAB_0017a786;
  while( true ) {
    pcVar6 = pcVar6 + 1;
    cVar1 = *pcVar6;
    if (cVar1 == '\0') break;
LAB_0017a6d6:
    iVar3 = ossl_ctype_check(cVar1,8);
    if (iVar3 == 0) {
      if (*pcVar6 != '\0') {
        sVar2 = strlen(pcVar6);
        pcVar5 = pcVar6 + (sVar2 - 1);
        if (pcVar6 + (sVar2 - 1) != pcVar6) goto LAB_0017a6fc;
        goto LAB_0017a71a;
      }
      break;
    }
  }
  goto LAB_0017a854;
  while (pcVar5 = pcVar8, pcVar6 != pcVar8) {
LAB_0017a6fc:
    pcVar8 = pcVar5 + -1;
    iVar3 = ossl_ctype_check(*pcVar5,8);
    if (iVar3 == 0) {
      if (pcVar6 != pcVar5) {
        pcVar5[1] = '\0';
      }
      break;
    }
  }
  if (*pcVar6 != '\0') {
LAB_0017a71a:
    X509V3_add_value(__s,pcVar6,local_2c);
    goto LAB_0017a83e;
  }
LAB_0017a854:
  ERR_put_error(0x22,0x6d,0x6d,"crypto/x509v3/v3_utl.c",0x17b);
  goto LAB_0017a7a4;
  while (pcVar5 = pcVar6, __s != pcVar6) {
LAB_0017a818:
    pcVar6 = pcVar5 + -1;
    iVar3 = ossl_ctype_check(*pcVar5,8);
    if (iVar3 == 0) {
      if (__s != pcVar5) {
        pcVar5[1] = '\0';
      }
      break;
    }
  }
  if (*__s != '\0') {
LAB_0017a834:
    X509V3_add_value(__s,(char *)0x0,local_2c);
LAB_0017a83e:
    CRYPTO_free(ptr);
    return local_2c[0];
  }
LAB_0017a786:
  iVar3 = 0x182;
LAB_0017a798:
  ERR_put_error(0x22,0x6d,0x6c,"crypto/x509v3/v3_utl.c",iVar3);
LAB_0017a7a4:
  CRYPTO_free(ptr);
  OPENSSL_sk_pop_free(local_2c[0],0x1794f9);
  return (stack_st_CONF_VALUE *)0x0;
}

