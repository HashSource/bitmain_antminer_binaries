
int OCSP_REQ_CTX_nbio(uint *param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  size_t sVar6;
  void *pvVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  char *__nptr;
  char *pcVar13;
  char *__s;
  bool bVar14;
  byte *local_28;
  char *local_24 [2];
  
  uVar10 = *param_1;
  do {
    while( true ) {
      if ((uVar10 & 0x1000) == 0) {
        iVar3 = BIO_read((BIO *)param_1[3],(void *)param_1[1],param_1[2]);
        if (iVar3 < 1) {
          iVar3 = BIO_test_flags((BIO *)param_1[3],8);
          if (iVar3 != 0) {
            iVar3 = 1;
          }
          return -iVar3;
        }
        iVar5 = BIO_write((BIO *)param_1[4],(void *)param_1[1],iVar3);
        if (iVar3 != iVar5) {
          return 0;
        }
        uVar10 = *param_1;
      }
      if (uVar10 == 0x1005) break;
      if (0x1005 < (int)uVar10) {
        if (uVar10 == 0x1007) goto LAB_001c2632;
        if ((int)uVar10 < 0x1007) goto LAB_001c2510;
        if (uVar10 == 0x1008) {
          return 1;
        }
        if (uVar10 != 0x1009) {
          return 0;
        }
        iVar3 = BIO_write((BIO *)param_1[4],"\r\n",2);
        if (iVar3 == 2) {
          *param_1 = 0x1005;
          break;
        }
        goto LAB_001c26b2;
      }
      if (uVar10 == 3) {
LAB_001c25d2:
        lVar4 = BIO_ctrl((BIO *)param_1[4],3,0,&local_28);
        pbVar12 = local_28;
        if (1 < lVar4) {
          if (*local_28 != 0x30) goto LAB_001c26b2;
          uVar10 = (uint)local_28[1];
          bVar14 = -1 < (int)(uVar10 << 0x18);
          if (bVar14) {
            uVar10 = uVar10 + 2;
          }
          if (bVar14) {
            param_1[5] = uVar10;
            local_28 = local_28 + 1;
          }
          else {
            pbVar12 = local_28 + 1;
            if (lVar4 < 6) goto LAB_001c253a;
            uVar10 = uVar10 & 0x7f;
            if (3 < uVar10 - 1) goto LAB_001c26b2;
            pbVar11 = local_28 + 2;
            uVar9 = 0;
            pbVar12 = pbVar11;
            do {
              local_28 = pbVar12 + 1;
              param_1[5] = uVar9 << 8;
              uVar9 = uVar9 << 8 | (uint)*pbVar12;
              param_1[5] = uVar9;
              pbVar12 = local_28;
            } while (pbVar11 + uVar10 != local_28);
            if (param_1[6] < uVar9) goto LAB_001c26b2;
            param_1[5] = uVar9 + uVar10 + 2;
          }
          *param_1 = 4;
LAB_001c2600:
          lVar4 = BIO_ctrl((BIO *)param_1[4],3,0,(void *)0x0);
          pbVar12 = local_28;
          if ((int)param_1[5] <= lVar4) {
            *param_1 = 0x1008;
            return 1;
          }
        }
      }
      else {
        if (3 < (int)uVar10) {
          if (uVar10 != 4) {
            return 0;
          }
          goto LAB_001c2600;
        }
        if ((int)uVar10 < 1) {
          return 0;
        }
        while ((sVar6 = BIO_ctrl((BIO *)param_1[4],3,0,&local_28), 0 < (int)sVar6 &&
               (pvVar7 = memchr(local_28,10,sVar6), pvVar7 != (void *)0x0))) {
          uVar10 = BIO_gets((BIO *)param_1[4],(char *)param_1[1],param_1[2]);
          if ((int)uVar10 < 1) {
            iVar3 = BIO_test_flags((BIO *)param_1[4],8);
            pbVar12 = local_28;
            if (iVar3 == 0) goto LAB_001c26b2;
            goto LAB_001c253a;
          }
          if (uVar10 == param_1[2]) goto LAB_001c26b2;
          if (*param_1 == 1) {
            __nptr = (char *)param_1[1];
            cVar2 = *__nptr;
            while( true ) {
              if (cVar2 == '\0') goto LAB_001c2764;
              iVar3 = ossl_ctype_check(cVar2,8);
              if (iVar3 != 0) break;
              __nptr = __nptr + 1;
              cVar2 = *__nptr;
            }
            cVar2 = *__nptr;
            if (cVar2 == '\0') {
LAB_001c2764:
              iVar3 = 0xd7;
LAB_001c26a6:
              ERR_put_error(0x27,0x76,0x73,"crypto/ocsp/ocsp_ht.c",iVar3);
              goto LAB_001c26b2;
            }
            while (iVar3 = ossl_ctype_check(cVar2,8), iVar3 != 0) {
              __nptr = __nptr + 1;
              cVar2 = *__nptr;
              if (cVar2 == '\0') goto LAB_001c27c6;
            }
            cVar2 = *__nptr;
            pcVar13 = __nptr;
            if (cVar2 == '\0') {
LAB_001c27c6:
              iVar3 = 0xe0;
              goto LAB_001c26a6;
            }
            while (iVar3 = ossl_ctype_check(cVar2,8), iVar3 == 0) {
              cVar2 = pcVar13[1];
              pcVar13 = pcVar13 + 1;
              if (cVar2 == '\0') goto LAB_001c26a0;
            }
            if (*pcVar13 == '\0') {
LAB_001c26a0:
              iVar3 = 0xe9;
              goto LAB_001c26a6;
            }
            *pcVar13 = '\0';
            uVar8 = strtoul(__nptr,local_24,10);
            if (*local_24[0] != '\0') goto LAB_001c26b2;
            __s = pcVar13 + 1;
            cVar2 = pcVar13[1];
            while (cVar2 != '\0') {
              iVar3 = ossl_ctype_check(cVar2,8);
              if (iVar3 == 0) {
                if (*__s != '\0') {
                  sVar6 = strlen(__s);
                  local_24[0] = __s + (sVar6 - 1);
                  while (iVar3 = ossl_ctype_check(*local_24[0],8), iVar3 != 0) {
                    *local_24[0] = '\0';
                    local_24[0] = local_24[0] + -1;
                  }
                }
                break;
              }
              __s = __s + 1;
              cVar2 = *__s;
            }
            if (uVar8 != 200) {
              ERR_put_error(0x27,0x76,0x72,"crypto/ocsp/ocsp_ht.c",0x104);
              if (*__s == '\0') {
                ERR_add_error_data(2,"Code=",__nptr);
              }
              else {
                ERR_add_error_data(4,"Code=",__nptr,",Reason=",__s);
              }
              goto LAB_001c26b2;
            }
            *param_1 = 2;
          }
          else {
            local_28 = (byte *)param_1[1];
            bVar1 = *local_28;
            while( true ) {
              if (bVar1 == 0) {
                *param_1 = 3;
                goto LAB_001c25d2;
              }
              if (bVar1 != 0xd && bVar1 != 10) break;
              local_28 = local_28 + 1;
              bVar1 = *local_28;
            }
          }
        }
        pbVar12 = local_28;
        if ((int)param_1[2] <= (int)sVar6) goto LAB_001c26b2;
      }
LAB_001c253a:
      local_28 = pbVar12;
      uVar10 = *param_1;
    }
    uVar10 = BIO_ctrl((BIO *)param_1[4],3,0,(void *)0x0);
    param_1[5] = uVar10;
    *param_1 = 0x1006;
LAB_001c2510:
    lVar4 = BIO_ctrl((BIO *)param_1[4],3,0,&local_28);
    iVar3 = BIO_write((BIO *)param_1[3],local_28 + (lVar4 - param_1[5]),param_1[5]);
    if (iVar3 < 1) goto LAB_001c27ec;
    uVar10 = param_1[5];
    param_1[5] = uVar10 - iVar3;
    pbVar12 = local_28;
    if (uVar10 - iVar3 != 0) goto LAB_001c253a;
    *param_1 = 0x1007;
    BIO_ctrl((BIO *)param_1[4],1,0,(void *)0x0);
LAB_001c2632:
    lVar4 = BIO_ctrl((BIO *)param_1[3],0xb,0,(void *)0x0);
    if (lVar4 < 1) {
LAB_001c27ec:
      iVar3 = BIO_test_flags((BIO *)param_1[3],8);
      if (iVar3 != 0) {
        return -1;
      }
LAB_001c26b2:
      *param_1 = 0x1000;
      return 0;
    }
    uVar10 = 1;
    *param_1 = 1;
  } while( true );
}

