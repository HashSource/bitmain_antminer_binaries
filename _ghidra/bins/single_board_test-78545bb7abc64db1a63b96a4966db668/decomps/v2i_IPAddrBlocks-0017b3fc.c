
int v2i_IPAddrBlocks(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  ulong uVar7;
  size_t sVar8;
  char cVar9;
  char *pcVar10;
  char *pcVar11;
  char *__accept;
  int iVar12;
  int local_78;
  ulong *local_74;
  undefined1 *local_60;
  undefined1 *local_54;
  char *local_50;
  ulong local_4c;
  uchar auStack_48 [16];
  uchar auStack_38 [20];
  
  iVar1 = OPENSSL_sk_new(0x179455);
  if (iVar1 == 0) {
    ERR_put_error(0x22,0x9f,0x41,"crypto/x509v3/v3_addr.c",0x390);
  }
  else {
    local_60 = v4addr_chars_23295;
    local_54 = v4addr_chars_23295;
    for (iVar12 = 0; iVar2 = OPENSSL_sk_num(param_3), iVar12 < iVar2; iVar12 = iVar12 + 1) {
      puVar3 = (undefined4 *)OPENSSL_sk_value(param_3,iVar12);
      iVar2 = name_cmp((char *)puVar3[1],"IPv4");
      if (iVar2 == 0) {
        iVar2 = 4;
        local_78 = 1;
        __accept = local_60;
LAB_0017b472:
        local_74 = (ulong *)0x0;
        pcVar4 = CRYPTO_strdup((char *)puVar3[2],"crypto/x509v3/v3_addr.c",0x3c6);
      }
      else {
        iVar2 = name_cmp((char *)puVar3[1],"IPv6");
        if (iVar2 == 0) {
          local_78 = 2;
          iVar2 = 0x10;
          __accept = "0123456789.:abcdefABCDEF";
          goto LAB_0017b472;
        }
        iVar2 = name_cmp((char *)puVar3[1],"IPv4-SAFI");
        if (iVar2 == 0) {
          iVar2 = 4;
          local_78 = 1;
          __accept = local_54;
        }
        else {
          iVar2 = name_cmp((char *)puVar3[1],"IPv6-SAFI");
          if (iVar2 != 0) {
            pcVar4 = (char *)0x0;
            ERR_put_error(0x22,0x9f,0x73,"crypto/x509v3/v3_addr.c",0x3a7);
            ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
            goto LAB_0017b52c;
          }
          local_78 = 2;
          iVar2 = 0x10;
          __accept = "0123456789.:abcdefABCDEF";
        }
        local_4c = strtoul((char *)puVar3[2],&local_50,0);
        if (*local_50 == ' ' || *local_50 == '\t') {
          do {
            local_50 = local_50 + 1;
          } while (*local_50 == ' ' || *local_50 == '\t');
        }
        pcVar4 = local_50;
        if ((0xff < local_4c) || (pcVar4 = local_50 + 1, *local_50 != ':')) {
          local_50 = pcVar4;
          pcVar4 = (char *)0x0;
          ERR_put_error(0x22,0x9f,0xa4,"crypto/x509v3/v3_addr.c",0x3bf);
          ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
          goto LAB_0017b52c;
        }
        if (local_50[1] == '\t' || local_50[1] == ' ') {
          pcVar6 = local_50 + 2;
          do {
            pcVar4 = pcVar6;
            pcVar6 = pcVar4 + 1;
          } while (*pcVar4 == '\t' || *pcVar4 == ' ');
        }
        local_74 = &local_4c;
        local_50 = pcVar4;
        pcVar4 = CRYPTO_strdup(pcVar4,"crypto/x509v3/v3_addr.c",0x3c4);
      }
      if (pcVar4 == (char *)0x0) {
        iVar12 = 0x3c9;
        goto LAB_0017b7b2;
      }
      iVar5 = strcmp(pcVar4,"inherit");
      if (iVar5 == 0) {
        iVar2 = X509v3_addr_add_inherit(iVar1,local_78,local_74);
        if (iVar2 == 0) {
          ERR_put_error(0x22,0x9f,0xa5,"crypto/x509v3/v3_addr.c",0x3d4);
          ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
          goto LAB_0017b52c;
        }
        CRYPTO_free(pcVar4);
      }
      else {
        pcVar6 = (char *)strspn(pcVar4,__accept);
        cVar9 = pcVar4[(int)pcVar6];
        pcVar10 = pcVar4 + (int)pcVar6;
        if (cVar9 == ' ' || cVar9 == '\t') {
          pcVar11 = pcVar10;
          do {
            pcVar6 = pcVar11 + (1 - (int)pcVar4);
            pcVar11 = pcVar11 + 1;
            cVar9 = *pcVar11;
          } while (cVar9 == '\t' || cVar9 == ' ');
        }
        *pcVar10 = '\0';
        pcVar10 = pcVar6 + 1;
        iVar5 = a2i_ipadd(auStack_48,pcVar4);
        if (iVar5 != iVar2) {
          ERR_put_error(0x22,0x9f,0xa6,"crypto/x509v3/v3_addr.c",0x3e3);
          ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
          goto LAB_0017b52c;
        }
        if (cVar9 == '-') {
          pcVar11 = pcVar10 + (int)pcVar4;
          if (pcVar4[(int)pcVar10] == '\t' || pcVar4[(int)pcVar10] == ' ') {
            pcVar6 = pcVar6 + 2 + (int)pcVar4;
            do {
              pcVar11 = pcVar6;
              pcVar10 = pcVar11 + -(int)pcVar4;
              pcVar6 = pcVar11 + 1;
            } while (*pcVar11 == '\t' || *pcVar11 == ' ');
          }
          sVar8 = strspn(pcVar11,__accept);
          if ((pcVar10 == pcVar10 + sVar8) || (pcVar4[(int)(pcVar10 + sVar8)] != '\0')) {
            ERR_put_error(0x22,0x9f,0x74,"crypto/x509v3/v3_addr.c",0x3fe);
            ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
            goto LAB_0017b52c;
          }
          iVar5 = a2i_ipadd(auStack_38,pcVar11);
          if (iVar5 != iVar2) {
            ERR_put_error(0x22,0x9f,0xa6,"crypto/x509v3/v3_addr.c",0x404);
            ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
            goto LAB_0017b52c;
          }
          if (local_78 == 2) {
            sVar8 = 0x10;
          }
          else {
            sVar8 = 4;
          }
          iVar2 = memcmp(auStack_48,auStack_38,sVar8);
          if (0 < iVar2) {
            ERR_put_error(0x22,0x9f,0x74,"crypto/x509v3/v3_addr.c",0x40a);
            ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
            goto LAB_0017b52c;
          }
          iVar2 = X509v3_addr_add_range(iVar1,local_78,local_74,auStack_48,auStack_38);
          if (iVar2 == 0) {
            iVar12 = 0x40f;
            goto LAB_0017b7b2;
          }
        }
        else if (cVar9 == '/') {
          uVar7 = strtoul(pcVar10 + (int)pcVar4,&local_50,10);
          if (((pcVar10 + (int)pcVar4 == local_50) || (*local_50 != '\0')) ||
             (uVar7 != iVar2 * 8 && (int)(uVar7 + iVar2 * -8) < 0 == SBORROW4(uVar7,iVar2 * 8) ||
              (int)uVar7 < 0)) {
            ERR_put_error(0x22,0x9f,0x74,"crypto/x509v3/v3_addr.c",0x3f0);
            ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
            goto LAB_0017b52c;
          }
          iVar2 = X509v3_addr_add_prefix(iVar1,local_78,local_74,auStack_48,uVar7);
          if (iVar2 == 0) {
            iVar12 = 0x3f5;
            goto LAB_0017b7b2;
          }
        }
        else {
          if (cVar9 != '\0') {
            ERR_put_error(0x22,0x9f,0x74,"crypto/x509v3/v3_addr.c",0x41b);
            ERR_add_error_data(6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
            goto LAB_0017b52c;
          }
          iVar2 = X509v3_addr_add_prefix(iVar1,local_78,local_74,auStack_48,iVar2 << 3);
          if (iVar2 == 0) {
            iVar12 = 0x415;
LAB_0017b7b2:
            ERR_put_error(0x22,0x9f,0x41,"crypto/x509v3/v3_addr.c",iVar12);
            goto LAB_0017b52c;
          }
        }
        CRYPTO_free(pcVar4);
      }
    }
    iVar12 = X509v3_addr_canonize(iVar1);
    if (iVar12 == 0) {
      pcVar4 = (char *)0x0;
LAB_0017b52c:
      CRYPTO_free(pcVar4);
      OPENSSL_sk_pop_free(iVar1,0x179441);
      iVar1 = 0;
    }
  }
  return iVar1;
}

