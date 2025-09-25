
/* WARNING: Type propagation algorithm not settling */

undefined4 def_load_bio(CONF *param_1,BIO *param_2,undefined4 *param_3)

{
  ushort uVar1;
  BUF_MEM *str;
  CONF_VALUE *pCVar2;
  int iVar3;
  size_t sVar4;
  size_t __n;
  BIO *pBVar5;
  char *pcVar6;
  BIO *a;
  int *piVar7;
  byte *pbVar8;
  CONF_VALUE *pCVar9;
  int iVar10;
  CONF_VALUE *pCVar11;
  uint uVar12;
  uint uVar13;
  byte bVar14;
  lhash_st_CONF_VALUE *plVar15;
  char *pcVar16;
  void *pvVar17;
  CONF_VALUE *ptr;
  byte *pbVar18;
  byte *pbVar19;
  int iVar20;
  CONF_VALUE *pCVar21;
  bool bVar22;
  CONF_VALUE *local_b4;
  CONF_VALUE *local_a8;
  CONF_VALUE *local_a0;
  CONF_VALUE *local_94;
  CONF_VALUE *local_8c;
  int local_88;
  CONF_VALUE *local_84;
  stat local_80;
  
  plVar15 = param_1->data;
  local_8c = (CONF_VALUE *)0x0;
  local_88 = 0;
  str = BUF_MEM_new();
  if (str == (BUF_MEM *)0x0) {
    ERR_put_error(0xe,0x79,7,"crypto/conf/conf_def.c",0xcb);
    pCVar2 = (CONF_VALUE *)0x0;
    ptr = (CONF_VALUE *)0x0;
    local_b4 = (CONF_VALUE *)0x0;
    local_a8 = (CONF_VALUE *)0x0;
    goto LAB_001cdc32;
  }
  pCVar2 = (CONF_VALUE *)CRYPTO_strdup("default","crypto/conf/conf_def.c",0xcf);
  iVar10 = 0xd1;
  local_8c = pCVar2;
  if (pCVar2 == (CONF_VALUE *)0x0) {
LAB_001cdc18:
    iVar20 = 0x41;
  }
  else {
    iVar10 = _CONF_new_data(param_1);
    if (iVar10 == 0) {
      iVar10 = 0xd6;
      pCVar2 = (CONF_VALUE *)0x0;
      goto LAB_001cdc18;
    }
    local_94 = _CONF_new_section(param_1,(char *)local_8c);
    if (local_94 != (CONF_VALUE *)0x0) {
      ptr = (CONF_VALUE *)0x0;
      iVar20 = 0;
      iVar10 = 0;
      bVar22 = true;
      local_a8 = (CONF_VALUE *)0x0;
      local_b4 = (CONF_VALUE *)0x0;
LAB_001cdb3a:
      iVar3 = BUF_MEM_grow(str,iVar20 + 0x200);
      if (iVar3 != 0) {
        pcVar16 = str->data + iVar20;
        str->data[iVar20] = '\0';
        BIO_gets(param_2,pcVar16,0x1ff);
        pcVar16[0x1ff] = '\0';
        sVar4 = strlen(pcVar16);
        __n = sVar4;
        if (bVar22) {
          local_80.st_dev._0_2_ = 0xbbef;
          local_80.st_dev._2_1_ = 0xbf;
          if ((2 < (int)sVar4) && (iVar3 = memcmp(pcVar16,&local_80,3), iVar3 == 0)) {
            __n = sVar4 - 3;
            memmove(pcVar16,pcVar16 + 3,__n);
            pcVar16[sVar4 - 3] = '\0';
          }
        }
        while (__n == 0 && iVar10 == 0) {
          if (local_88 == 0) {
            pBVar5 = (BIO *)OPENSSL_sk_pop(local_b4);
joined_r0x001cdd04:
            if (pBVar5 == (BIO *)0x0) {
              BUF_MEM_free(str);
              CRYPTO_free(local_8c);
              OPENSSL_sk_free(local_b4);
              return 1;
            }
          }
          else {
            pBVar5 = (BIO *)get_next_file(ptr,&local_88);
            if (pBVar5 == (BIO *)0x0) {
              CRYPTO_free(ptr);
              pBVar5 = (BIO *)OPENSSL_sk_pop(local_b4);
              ptr = (CONF_VALUE *)0x0;
              goto joined_r0x001cdd04;
            }
          }
          BIO_vfree(param_2);
          BIO_gets(pBVar5,pcVar16,0x1ff);
          pcVar16[0x1ff] = '\0';
          __n = strlen(pcVar16);
          param_2 = pBVar5;
        }
        sVar4 = __n;
        if ((int)__n < 1) {
          bVar22 = true;
LAB_001cde20:
          if (__n == 0) {
            bVar22 = false;
          }
          if (!bVar22) {
LAB_001cdd50:
            bVar22 = false;
            iVar10 = iVar20 + sVar4;
            pcVar16[sVar4] = '\0';
            local_a8 = (CONF_VALUE *)((int)&local_a8->section + 1);
            pCVar2 = (CONF_VALUE *)str->data;
            if (0 < iVar10) {
              iVar20 = iVar10 + -1;
              uVar13 = (uint)*(byte *)((int)pCVar2 + iVar20);
              pcVar16 = (char *)((int)pCVar2 + iVar20);
              if (-1 < (int)(uVar13 << 0x18)) goto LAB_001cdd76;
            }
            pvVar17 = param_1->meth_data;
            pCVar9 = pCVar2;
LAB_001cddb4:
            do {
              pCVar11 = pCVar9;
              bVar14 = *(byte *)&pCVar11->section;
              uVar13 = (uint)bVar14;
              if ((char)bVar14 < '\0') break;
              uVar1 = *(ushort *)((int)pvVar17 + uVar13 * 2);
              if ((uVar1 & 0x800) != 0) goto LAB_001cdf88;
              pCVar9 = (CONF_VALUE *)((int)&pCVar11->section + 1);
            } while ((uVar1 & 0x10) != 0);
joined_r0x001cddc2:
            uVar12 = uVar13;
            if ((char)bVar14 < '\0') {
LAB_001cde04:
              uVar13 = (uint)*(byte *)((int)&pCVar11->section + 1);
              goto LAB_001cde06;
            }
            uVar13 = (uint)*(ushort *)((int)pvVar17 + uVar12 * 2);
            if ((int)(uVar13 << 0x18) < 0) goto LAB_001cdf88;
            if ((int)(uVar13 << 0x15) < 0) goto LAB_001cde4a;
            if ((int)(uVar13 << 0x19) < 0) {
              do {
                do {
                  do {
                    pCVar9 = pCVar11;
                    pCVar11 = (CONF_VALUE *)((int)&pCVar9->section + 1);
                    bVar14 = *(byte *)&pCVar11->section;
                    uVar13 = (uint)bVar14;
                    pCVar21 = (CONF_VALUE *)((int)&pCVar9->section + 2);
                  } while ((char)bVar14 < '\0');
                  uVar1 = *(ushort *)((int)pvVar17 + uVar13 * 2);
                  if ((uVar1 & 8) != 0) {
                    if (uVar12 == uVar13) goto LAB_001cde04;
                    goto joined_r0x001cddc2;
                  }
                  if (uVar12 == uVar13) goto LAB_001cde04;
                } while (-1 < (int)((uint)uVar1 << 0x1a));
                bVar14 = *(byte *)((int)&pCVar9->section + 2);
                pCVar11 = pCVar21;
              } while (((char)bVar14 < '\0') ||
                      (uVar13 = (uint)bVar14,
                      -1 < (int)((uint)*(ushort *)((int)pvVar17 + (uint)bVar14 * 2) << 0x1c)));
              goto joined_r0x001cddc2;
            }
            if ((int)(uVar13 << 0x1a) < 0) {
              bVar14 = *(byte *)((int)&pCVar11->section + 1);
              if (((char)bVar14 < '\0') ||
                 (-1 < (int)((uint)*(ushort *)((int)pvVar17 + (uint)bVar14 * 2) << 0x1c))) {
                bVar14 = *(byte *)((int)&pCVar11->section + 2);
                pCVar11 = (CONF_VALUE *)((int)&pCVar11->section + 2);
                uVar13 = (uint)bVar14;
              }
              else {
                pCVar11 = (CONF_VALUE *)((int)&pCVar11->section + 1);
                uVar13 = (uint)bVar14;
              }
              goto joined_r0x001cddc2;
            }
            if (-1 < (int)(uVar13 << 0x1c)) goto LAB_001cde04;
            goto LAB_001cdea6;
          }
          iVar10 = iVar20 + sVar4;
          if (0 < iVar10) goto LAB_001cdfa4;
          goto LAB_001cde3a;
        }
        pcVar6 = pcVar16 + (__n - 1);
        if (pcVar16[__n - 1] == '\r' || pcVar16[__n - 1] == '\n') {
          do {
            sVar4 = sVar4 - 1;
            if (sVar4 == 0) goto LAB_001cdd50;
            pcVar6 = pcVar6 + -1;
          } while (*pcVar6 == '\r' || *pcVar6 == '\n');
          bVar22 = __n == sVar4;
          goto LAB_001cde20;
        }
        iVar10 = iVar20 + __n;
        if (iVar10 < 1) {
LAB_001cde3a:
          iVar20 = iVar10;
          iVar10 = 1;
        }
        else {
LAB_001cdfa4:
          pCVar2 = (CONF_VALUE *)str->data;
          iVar20 = iVar10 + -1;
          uVar13 = (uint)*(byte *)((int)pCVar2 + iVar20);
          pcVar16 = (char *)((int)pCVar2 + iVar20);
          if ((int)(uVar13 << 0x18) < 0) goto LAB_001cde3a;
          bVar22 = true;
LAB_001cdd76:
          pvVar17 = param_1->meth_data;
          if ((-1 < (int)((uint)*(ushort *)((int)pvVar17 + uVar13 * 2) << 0x1a)) ||
             (((iVar10 != 1 && (-1 < (int)((uint)(byte)pcVar16[-1] << 0x18))) &&
              ((int)((uint)*(ushort *)((int)pvVar17 + (uint)(byte)pcVar16[-1] * 2) << 0x1a) < 0))))
          {
            pCVar9 = pCVar2;
            if (!bVar22) goto LAB_001cddb4;
            goto LAB_001cde3a;
          }
          iVar10 = 1;
        }
        goto LAB_001cde12;
      }
      iVar20 = 0xe4;
      iVar10 = 7;
LAB_001ce106:
      pCVar2 = (CONF_VALUE *)0x0;
      ERR_put_error(0xe,0x79,iVar10,"crypto/conf/conf_def.c",iVar20);
      goto LAB_001cdc32;
    }
    iVar10 = 0xdc;
    iVar20 = 0x67;
    pCVar2 = (CONF_VALUE *)0x0;
  }
  ERR_put_error(0xe,0x79,iVar20,"crypto/conf/conf_def.c",iVar10);
  ptr = pCVar2;
  local_b4 = pCVar2;
  local_a8 = pCVar2;
LAB_001cdc32:
  BUF_MEM_free(str);
  CRYPTO_free(local_8c);
  while (iVar10 = OPENSSL_sk_num(local_b4), 0 < iVar10) {
    pBVar5 = (BIO *)OPENSSL_sk_pop(local_b4);
    BIO_vfree(param_2);
    param_2 = pBVar5;
  }
  OPENSSL_sk_free();
  CRYPTO_free(ptr);
  if (local_88 != 0) {
    OPENSSL_DIR_end(&local_88);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = local_a8;
  }
  BIO_snprintf((char *)&local_80,0xd,"%ld",local_a8);
  ERR_add_error_data(2,"line ",&local_80);
  if (plVar15 != param_1->data) {
    CONF_free(param_1->data);
    param_1->data = (lhash_st_CONF_VALUE *)0x0;
  }
  if (pCVar2 != (CONF_VALUE *)0x0) {
    CRYPTO_free(pCVar2->name);
    CRYPTO_free(pCVar2->value);
    CRYPTO_free(pCVar2);
  }
  return 0;
LAB_001cdf88:
  *(char *)&pCVar11->section = '\0';
  pvVar17 = param_1->meth_data;
LAB_001cdea6:
  uVar13 = (uint)*(byte *)&pCVar2->section;
  if (-1 < (int)(uVar13 << 0x18)) {
    uVar12 = (uint)*(ushort *)((int)pvVar17 + uVar13 * 2);
    if ((int)(uVar12 << 0x1b) < 0) {
      do {
        if ((int)(uVar12 << 0x1c) < 0) goto LAB_001cdf96;
        pCVar2 = (CONF_VALUE *)((int)&pCVar2->section + 1);
        uVar13 = (uint)*(byte *)&pCVar2->section;
        if ((int)(uVar13 << 0x18) < 0) goto LAB_001cded0;
        uVar1 = *(ushort *)((int)pvVar17 + uVar13 * 2);
        uVar12 = (uint)uVar1;
      } while ((uVar1 & 0x10) != 0);
    }
    if ((uVar12 & 8) == 0) {
      if (uVar13 != 0x5b) goto LAB_001cded0;
      bVar14 = *(byte *)((int)&pCVar2->section + 1);
      pbVar18 = (byte *)((int)&pCVar2->section + 1);
      while (((uVar13 = (uint)bVar14, pbVar8 = pbVar18, -1 < (char)bVar14 &&
              (uVar12 = (uint)*(ushort *)((int)pvVar17 + uVar13 * 2), (int)(uVar12 << 0x1b) < 0)) &&
             (-1 < (int)(uVar12 << 0x1c)))) {
        pbVar18 = pbVar18 + 1;
        bVar14 = *pbVar18;
      }
joined_r0x001ce37e:
      while (pbVar19 = pbVar18, (char)bVar14 < '\0') {
LAB_001ce3a8:
        bVar22 = pbVar8 == pbVar19;
        pbVar18 = pbVar19;
        pbVar8 = pbVar19;
        if (uVar13 == 0 || bVar22) {
          pCVar2 = (CONF_VALUE *)0x0;
          ERR_put_error(0xe,0x79,100,"crypto/conf/conf_def.c",0x152);
          goto LAB_001cdc32;
        }
      }
      uVar1 = *(ushort *)((int)pvVar17 + uVar13 * 2);
      if ((uVar1 & 0x20) != 0) {
        bVar14 = pbVar18[1];
        uVar13 = (uint)bVar14;
        if (((char)bVar14 < '\0') ||
           (-1 < (int)((uint)*(ushort *)((int)pvVar17 + uVar13 * 2) << 0x1c))) {
          bVar14 = pbVar18[2];
          uVar13 = (uint)bVar14;
          pbVar18 = pbVar18 + 2;
        }
        else {
          pbVar18 = pbVar18 + 1;
        }
        goto joined_r0x001ce37e;
      }
      if ((uVar1 & 0x307) != 0) {
        bVar14 = pbVar18[1];
        uVar13 = (uint)bVar14;
        pbVar18 = pbVar18 + 1;
        goto joined_r0x001ce37e;
      }
      while (((uVar1 & 0x10) != 0 && (-1 < (int)((uint)uVar1 << 0x1c)))) {
        pbVar19 = pbVar19 + 1;
        bVar14 = *pbVar19;
        uVar13 = (uint)bVar14;
        if ((char)bVar14 < '\0') goto LAB_001ce3a8;
        uVar1 = *(ushort *)((int)pvVar17 + uVar13 * 2);
      }
      if (uVar13 != 0x5d) goto LAB_001ce3a8;
      *pbVar18 = 0;
      iVar10 = str_copy(param_1,0,&local_8c);
      if (iVar10 == 0) {
        pCVar2 = (CONF_VALUE *)0x0;
        goto LAB_001cdc32;
      }
      local_94 = _CONF_get_section(param_1,(char *)local_8c);
      if ((local_94 == (CONF_VALUE *)0x0) &&
         (local_94 = _CONF_new_section(param_1,(char *)local_8c), local_94 == (CONF_VALUE *)0x0)) {
        iVar20 = 0x15c;
        iVar10 = 0x67;
        goto LAB_001ce106;
      }
    }
LAB_001cdf96:
    iVar20 = 0;
    iVar10 = iVar20;
    goto LAB_001cde12;
  }
LAB_001cded0:
  bVar14 = *(byte *)&pCVar2->section;
  uVar13 = (uint)bVar14;
  pCVar9 = pCVar2;
LAB_001cdedc:
  if (-1 < (char)bVar14) {
    while (uVar1 = *(ushort *)((int)pvVar17 + uVar13 * 2), (int)((uint)uVar1 << 0x1a) < 0) {
      bVar14 = *(byte *)((int)&pCVar9->section + 1);
      uVar13 = (uint)bVar14;
      if ((-1 < (char)bVar14) && ((int)((uint)*(ushort *)((int)pvVar17 + uVar13 * 2) << 0x1c) < 0))
      {
        pCVar9 = (CONF_VALUE *)((int)&pCVar9->section + 1);
        goto LAB_001cdedc;
      }
      bVar14 = *(byte *)((int)&pCVar9->section + 2);
      uVar13 = (uint)bVar14;
      pCVar9 = (CONF_VALUE *)((int)&pCVar9->section + 2);
      if ((char)bVar14 < '\0') goto LAB_001cdf0e;
    }
    if ((uVar1 & 0x307) == 0) {
      if ((uVar13 == 0x3a) && (*(char *)((int)&pCVar9->section + 1) == ':')) {
        pCVar21 = (CONF_VALUE *)((int)&pCVar9->section + 2);
        *(byte *)&pCVar9->section = (byte)uVar1 & 7;
        bVar14 = *(byte *)((int)&pCVar9->section + 2);
        uVar13 = (uint)bVar14;
        pvVar17 = param_1->meth_data;
        pCVar11 = pCVar21;
        goto LAB_001ce4a2;
      }
      goto LAB_001cdf0e;
    }
    bVar14 = *(byte *)((int)&pCVar9->section + 1);
    uVar13 = (uint)bVar14;
    pCVar9 = (CONF_VALUE *)((int)&pCVar9->section + 1);
    goto LAB_001cdedc;
  }
LAB_001cdf0e:
  local_a0 = local_8c;
  pCVar21 = pCVar2;
  pCVar11 = pCVar9;
  if (-1 < (char)bVar14) {
    uVar12 = (uint)*(ushort *)((int)pvVar17 + uVar13 * 2);
joined_r0x001cdf20:
    do {
      if ((-1 < (int)(uVar12 << 0x1b)) || ((int)(uVar12 << 0x1c) < 0)) break;
      pCVar11 = (CONF_VALUE *)((int)&pCVar11->section + 1);
      uVar13 = (uint)*(byte *)&pCVar11->section;
      if ((int)(uVar13 << 0x18) < 0) goto LAB_001cdf3c;
      uVar12 = (uint)*(ushort *)((int)pvVar17 + uVar13 * 2);
    } while( true );
  }
  iVar10 = strncmp((char *)pCVar21,".include",8);
  if (iVar10 != 0) {
    if (uVar13 != 0x3d) goto LAB_001cdf66;
    *(char *)&pCVar9->section = '\0';
    pbVar18 = (byte *)((int)&pCVar11->section + 1);
    bVar14 = *(byte *)((int)&pCVar11->section + 1);
    pvVar17 = param_1->meth_data;
    while (((pbVar8 = pbVar18, -1 < (int)((uint)bVar14 << 0x18) &&
            (uVar13 = (uint)*(ushort *)((int)pvVar17 + (uint)bVar14 * 2), (int)(uVar13 << 0x1b) < 0)
            ) && (-1 < (int)(uVar13 << 0x1c)))) {
      pbVar18 = pbVar18 + 1;
      bVar14 = *pbVar18;
    }
    do {
      do {
        pbVar19 = pbVar8;
        pbVar8 = pbVar19 + 1;
      } while ((int)((uint)*pbVar19 << 0x18) < 0);
    } while (-1 < (int)((uint)*(ushort *)((int)pvVar17 + (uint)*pbVar19 * 2) << 0x1c));
    pbVar8 = pbVar19 + -1;
    if (((pbVar18 <= pbVar8) && (-1 < (int)((uint)pbVar19[-1] << 0x18))) &&
       ((int)((uint)*(ushort *)((int)pvVar17 + (uint)pbVar19[-1] * 2) << 0x1b) < 0)) {
      pbVar19 = pbVar19 + -2;
      while (pbVar8 = pbVar19, pbVar8 != pbVar18 + -1) {
        if (((*pbVar8 & 0x80) != 0) ||
           (pbVar19 = pbVar8 + -1,
           -1 < (int)((uint)*(ushort *)((int)pvVar17 + (uint)*pbVar8 * 2) << 0x1b))) break;
      }
    }
    pbVar8[1] = 0;
    pCVar2 = (CONF_VALUE *)CRYPTO_malloc(0xc,"crypto/conf/conf_def.c",0x19f);
    if (pCVar2 == (CONF_VALUE *)0x0) {
      iVar10 = 0x1a0;
    }
    else {
      pcVar16 = CRYPTO_strdup((char *)pCVar21,"crypto/conf/conf_def.c",0x1a3);
      pCVar2->value = (char *)0x0;
      pCVar2->name = pcVar16;
      if (pcVar16 == (char *)0x0) {
        iVar10 = 0x1a6;
      }
      else {
        iVar10 = str_copy(param_1,local_a0,&pCVar2->value,pbVar18);
        if (iVar10 == 0) goto LAB_001cdc32;
        iVar10 = strcmp((char *)local_a0,(char *)local_8c);
        pCVar9 = local_94;
        if (((iVar10 != 0) &&
            (pCVar9 = _CONF_get_section(param_1,(char *)local_a0), pCVar9 == (CONF_VALUE *)0x0)) &&
           (pCVar9 = _CONF_new_section(param_1,(char *)local_a0), pCVar9 == (CONF_VALUE *)0x0)) {
          iVar10 = 0x1b2;
          iVar20 = 0x67;
          goto LAB_001ce2e8;
        }
        iVar10 = _CONF_add_string(param_1,pCVar9,pCVar2);
        if (iVar10 != 0) goto LAB_001cdf96;
        iVar10 = 0x1b8;
      }
    }
    iVar20 = 0x41;
LAB_001ce2e8:
    ERR_put_error(0xe,0x79,iVar20,"crypto/conf/conf_def.c",iVar10);
    goto LAB_001cdc32;
  }
  goto LAB_001cdf4c;
LAB_001cde4a:
  while( true ) {
    pCVar9 = pCVar11;
    pCVar11 = (CONF_VALUE *)((int)&pCVar9->section + 1);
    bVar14 = *(byte *)&pCVar11->section;
    uVar13 = (uint)bVar14;
    if ((-1 < (char)bVar14) && ((int)((uint)*(ushort *)((int)pvVar17 + uVar13 * 2) << 0x1c) < 0))
    break;
    if (uVar12 == uVar13) {
      uVar13 = (uint)*(byte *)((int)&pCVar9->section + 2);
      if (uVar12 != uVar13) goto LAB_001cde06;
      pCVar11 = (CONF_VALUE *)((int)&pCVar9->section + 2);
    }
  }
  if (uVar12 == uVar13) {
    uVar13 = (uint)*(byte *)((int)&pCVar9->section + 2);
LAB_001cde06:
    bVar14 = (byte)uVar13;
    pCVar11 = (CONF_VALUE *)((int)&pCVar11->section + 1);
  }
  goto joined_r0x001cddc2;
LAB_001ce4a2:
  local_a0 = pCVar2;
  if (-1 < (char)bVar14) {
    uVar1 = *(ushort *)((int)pvVar17 + uVar13 * 2);
    uVar12 = (uint)uVar1;
    if ((int)(uVar12 << 0x1a) < 0) {
      bVar14 = *(byte *)((int)&pCVar11->section + 1);
      uVar13 = (uint)bVar14;
      if (((char)bVar14 < '\0') ||
         (-1 < (int)((uint)*(ushort *)((int)pvVar17 + uVar13 * 2) << 0x1c))) {
        bVar14 = *(byte *)((int)&pCVar11->section + 2);
        uVar13 = (uint)bVar14;
        pCVar11 = (CONF_VALUE *)((int)&pCVar11->section + 2);
      }
      else {
        pCVar11 = (CONF_VALUE *)((int)&pCVar11->section + 1);
      }
    }
    else {
      pCVar9 = pCVar11;
      if ((uVar1 & 0x307) == 0) goto joined_r0x001cdf20;
      bVar14 = *(byte *)((int)&pCVar11->section + 1);
      uVar13 = (uint)bVar14;
      pCVar11 = (CONF_VALUE *)((int)&pCVar11->section + 1);
    }
    goto LAB_001ce4a2;
  }
LAB_001cdf3c:
  iVar10 = strncmp((char *)pCVar21,".include",8);
  if (iVar10 != 0) goto LAB_001cdf66;
LAB_001cdf4c:
  if (pCVar11 == (CONF_VALUE *)&pCVar21->value && uVar13 != 0x3d) {
LAB_001cdf66:
    pCVar2 = (CONF_VALUE *)0x0;
    ERR_put_error(0xe,0x79,0x65,"crypto/conf/conf_def.c",0x197);
    goto LAB_001cdc32;
  }
  local_84 = (CONF_VALUE *)0x0;
  pCVar2 = pCVar11;
  if (*(char *)&pCVar11->section == '=') {
    bVar14 = *(byte *)((int)&pCVar11->section + 1);
    pCVar11 = (CONF_VALUE *)((int)&pCVar11->section + 1);
    while (((pCVar2 = pCVar11, -1 < (int)((uint)bVar14 << 0x18) &&
            (uVar13 = (uint)*(ushort *)((int)pvVar17 + (uint)bVar14 * 2), (int)(uVar13 << 0x1b) < 0)
            ) && (-1 < (int)(uVar13 << 0x1c)))) {
      pCVar11 = (CONF_VALUE *)((int)&pCVar11->section + 1);
      bVar14 = *(byte *)&pCVar11->section;
    }
  }
  do {
    do {
      pCVar9 = pCVar2;
      pCVar2 = (CONF_VALUE *)((int)&pCVar9->section + 1);
    } while ((int)((uint)*(byte *)&pCVar9->section << 0x18) < 0);
  } while (-1 < (int)((uint)*(ushort *)((int)pvVar17 + (uint)*(byte *)&pCVar9->section * 2) << 0x1c)
          );
  pCVar2 = (CONF_VALUE *)((int)&pCVar9[-1].value + 3);
  if (((pCVar11 <= pCVar2) &&
      (uVar13 = (uint)*(byte *)((int)&pCVar9[-1].value + 3), -1 < (int)(uVar13 << 0x18))) &&
     ((int)((uint)*(ushort *)((int)pvVar17 + uVar13 * 2) << 0x1b) < 0)) {
    pCVar9 = (CONF_VALUE *)((int)&pCVar9[-1].value + 2);
    while (pCVar2 = pCVar9, pCVar2 != (CONF_VALUE *)((int)&pCVar11[-1].value + 3)) {
      if (((int)((uint)*(byte *)&pCVar2->section << 0x18) < 0) ||
         (pCVar9 = (CONF_VALUE *)((int)&pCVar2[-1].value + 3),
         -1 < (int)((uint)*(ushort *)((int)pvVar17 + (uint)*(byte *)&pCVar2->section * 2) << 0x1b)))
      break;
    }
  }
  *(char *)((int)&pCVar2->section + 1) = '\0';
  iVar10 = str_copy(param_1,local_a0,&local_84,pCVar11);
  pCVar2 = local_84;
  if (iVar10 == 0) goto LAB_001ce16a;
  memset(&local_80,0,0x58);
  iVar10 = __xstat(3,(char *)pCVar2,&local_80);
  pBVar5 = param_2;
  if (iVar10 < 0) {
    piVar7 = __errno_location();
    ERR_put_error(2,0x16,*piVar7,"crypto/conf/conf_def.c",0x2b4);
    ERR_add_error_data(1,pCVar2);
    goto LAB_001ce190;
  }
  if ((local_80.st_mode & 0xf000) == 0x4000) {
    if (local_88 == 0) {
      a = (BIO *)get_next_file(pCVar2,&local_88);
      if (a == (BIO *)0x0) goto LAB_001ce190;
      ptr = local_84;
      if (pCVar2 != local_84) goto LAB_001ce134;
      goto LAB_001ce0ae;
    }
    ERR_put_error(0xe,0x74,0x6f,"crypto/conf/conf_def.c",0x2bd);
    ERR_add_error_data(1,pCVar2);
LAB_001ce190:
    if (ptr != local_84) {
      a = (BIO *)0x0;
      pCVar2 = ptr;
      goto LAB_001ce134;
    }
  }
  else {
    a = BIO_new_file((char *)pCVar2,"r");
    pCVar2 = ptr;
    if (local_84 != ptr) {
LAB_001ce134:
      CRYPTO_free(local_84);
      ptr = pCVar2;
    }
    if (a != (BIO *)0x0) {
LAB_001ce0ae:
      if ((local_b4 == (CONF_VALUE *)0x0) &&
         (local_b4 = (CONF_VALUE *)OPENSSL_sk_new_null(), local_b4 == (CONF_VALUE *)0x0)) {
        iVar10 = 0x188;
      }
      else {
        iVar10 = OPENSSL_sk_push(local_b4,param_2);
        pBVar5 = a;
        if (iVar10 != 0) goto LAB_001ce0c2;
        iVar10 = 0x18e;
      }
      ERR_put_error(0xe,0x79,0x41,"crypto/conf/conf_def.c",iVar10);
      BIO_free(a);
LAB_001ce16a:
      pCVar2 = (CONF_VALUE *)0x0;
      goto LAB_001cdc32;
    }
  }
LAB_001ce0c2:
  param_2 = pBVar5;
  iVar10 = 0;
  iVar20 = 0;
LAB_001cde12:
  bVar22 = false;
  goto LAB_001cdb3a;
}

