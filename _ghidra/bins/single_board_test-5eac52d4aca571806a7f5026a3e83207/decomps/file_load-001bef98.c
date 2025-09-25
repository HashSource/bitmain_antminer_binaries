
void * file_load(int *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  void *pvVar2;
  long lVar3;
  int *piVar4;
  void *pvVar5;
  size_t sVar6;
  int iVar7;
  size_t sVar8;
  ulong uVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  uint uVar13;
  int *piVar14;
  uint uVar16;
  bool bVar17;
  int local_18c;
  char *local_188;
  uchar *local_184;
  size_t local_180;
  char *local_174;
  char *local_168;
  BUF_MEM *local_164;
  char *local_148;
  char *local_144;
  uchar *local_140;
  size_t local_13c;
  EVP_CIPHER *local_138;
  int local_134;
  undefined4 local_130;
  undefined *local_12c;
  EVP_CIPHER_INFO local_128 [13];
  int *piVar15;
  
  param_1[1] = 0;
  ERR_clear_error();
  if (*param_1 != 2) {
    do {
      local_128[0].cipher = (EVP_CIPHER *)0x0;
      if (param_1[4] != 0) {
        pvVar2 = (void *)(**(code **)(param_1[4] + 4))
                                   (0,0,0,0,param_1 + 5,local_128,param_2,param_3);
        if (pvVar2 != (void *)0x0) {
          return pvVar2;
        }
        (**(code **)(param_1[4] + 0xc))(param_1 + 5);
        param_1[5] = 0;
        param_1[4] = 0;
      }
      iVar10 = *param_1;
      if (iVar10 != 2) {
        lVar3 = BIO_ctrl((BIO *)param_1[3],2,0,(void *)0x0);
        if (lVar3 != 0) {
          return (void *)0x0;
        }
        iVar10 = *param_1;
      }
      pvVar2 = (void *)0x0;
LAB_001bf03a:
      local_148 = (char *)0x0;
      local_144 = (char *)0x0;
      local_140 = (uchar *)0x0;
      local_13c = 0;
      if (iVar10 == 1) {
        if (param_1[2] << 0x1f < 0) {
          iVar10 = PEM_read_bio_ex((BIO *)param_1[3],&local_148,&local_144,&local_140,&local_13c,3);
        }
        else {
          iVar10 = PEM_read_bio((BIO *)param_1[3],&local_148,&local_144,&local_140,
                                (long *)&local_13c);
        }
        pcVar11 = local_144;
        if (0 < iVar10) {
          local_174 = local_144;
          sVar6 = strlen(local_144);
          if (sVar6 < 0xb) goto LAB_001bf08a;
          iVar10 = PEM_get_EVP_CIPHER_INFO(pcVar11,local_128);
          if (iVar10 != 0) {
            local_12c = &DAT_00234820;
            local_134 = param_2;
            local_130 = param_3;
            iVar10 = PEM_do_header(local_128,local_140,(long *)&local_13c,(undefined1 *)0x1bf6e1,
                                   &local_134);
            if (iVar10 != 0) goto LAB_001bf084;
          }
        }
LAB_001bf2f4:
        iVar10 = -1;
        local_18c = -1;
        param_1[1] = param_1[1] + 1;
        if (-1 < param_1[2] << 0x1f) goto LAB_001bf232;
LAB_001bf30c:
        CRYPTO_secure_clear_free(local_148,0,"crypto/store/loader_file.c",0x46c);
      }
      else {
        local_128[0].cipher = (EVP_CIPHER *)0x0;
        iVar10 = asn1_d2i_read_bio(param_1[3],local_128);
        if (iVar10 < 0) goto LAB_001bf2f4;
        local_140 = (uchar *)(local_128[0].cipher)->block_size;
        local_13c = (local_128[0].cipher)->nid;
        CRYPTO_free(local_128[0].cipher);
LAB_001bf084:
        local_174 = local_144;
LAB_001bf08a:
        local_18c = -1;
        local_188 = local_148;
        local_184 = local_140;
        local_168 = (char *)0x0;
        local_164 = (BUF_MEM *)0x0;
        local_180 = local_13c;
        while( true ) {
          local_138 = (EVP_CIPHER *)0x0;
          piVar4 = (int *)CRYPTO_zalloc(0x1c,"crypto/store/loader_file.c",0x40b);
          if (piVar4 == (int *)0x0) break;
          pvVar2 = (void *)0x0;
          local_18c = 0;
          piVar14 = &file_handlers;
          do {
            while( true ) {
              piVar15 = piVar14 + 1;
              iVar10 = *piVar14;
              local_128[0].cipher = (EVP_CIPHER *)0x0;
              local_134 = 0;
              pvVar5 = (void *)(**(code **)(iVar10 + 4))
                                         (local_188,local_174,local_184,local_180,local_128,
                                          &local_134,param_2,param_3);
              piVar14 = piVar15;
              if (0 < local_134) break;
LAB_001bf0fa:
              if (piVar15 == (int *)&OSSL_STORE_str_functs) goto LAB_001bf164;
            }
            piVar4[local_18c] = iVar10;
            if (local_138 != (EVP_CIPHER *)0x0) {
              (**(code **)(iVar10 + 0xc))(&local_138);
            }
            local_18c = local_18c + local_134;
            local_138 = local_128[0].cipher;
            if (1 < local_18c) {
              OSSL_STORE_INFO_free(pvVar2);
              pvVar2 = (void *)0x0;
              OSSL_STORE_INFO_free(pvVar5);
              if (*(code **)(iVar10 + 0xc) != (code *)0x0) {
                (**(code **)(iVar10 + 0xc))(&local_138);
              }
              local_138 = (EVP_CIPHER *)0x0;
              goto LAB_001bf0fa;
            }
            if (pvVar2 == (void *)0x0) {
              pvVar2 = pvVar5;
            }
          } while (piVar15 != (int *)&OSSL_STORE_str_functs);
LAB_001bf164:
          if ((local_18c == 1) && (*(int *)(*piVar4 + 0x10) != 0)) {
            param_1[4] = *piVar4;
            param_1[5] = (int)local_138;
          }
          CRYPTO_free(piVar4);
          CRYPTO_free(local_168);
          BUF_MEM_free(local_164);
          if (pvVar2 == (void *)0x0) goto LAB_001bf20c;
          iVar10 = OSSL_STORE_INFO_get_type(pvVar2);
          if (iVar10 != -1) {
            ERR_clear_error();
            goto LAB_001bf22c;
          }
          local_188 = (char *)ossl_store_info_get0_EMBEDDED_pem_name(pvVar2);
          local_164 = (BUF_MEM *)ossl_store_info_get0_EMBEDDED_buffer(pvVar2);
          local_184 = (uchar *)local_164->data;
          local_180 = local_164->length;
          CRYPTO_free(pvVar2);
          local_168 = local_188;
        }
        ERR_put_error(0x2c,0x7c,0x41,"crypto/store/loader_file.c",0x40f);
        CRYPTO_free(local_168);
        BUF_MEM_free(local_164);
LAB_001bf20c:
        bVar17 = local_148 != (char *)0x0;
        pcVar11 = local_148;
        if (bVar17) {
          pcVar11 = (char *)(local_18c + -1);
        }
        if ((bVar17 && local_18c != 1) && (int)pcVar11 < 0 == (bVar17 && SBORROW4(local_18c,1))) {
          pvVar2 = (void *)0x0;
          param_1[1] = param_1[1] + 1;
        }
        else {
          if (local_18c < 2) {
            if (local_18c != 1) {
              pvVar2 = (void *)0x0;
              goto LAB_001bf22c;
            }
            uVar9 = ERR_peek_error();
            if ((uVar9 == 0) &&
               (ERR_put_error(0x2c,0x77,0x6e,"crypto/store/loader_file.c",0x56e),
               local_148 != (char *)0x0)) {
              ERR_add_error_data(3,"PEM type is \'",local_148,"\'");
            }
          }
          else {
            ERR_put_error(0x2c,0x77,0x6b,"crypto/store/loader_file.c",0x566);
          }
          pvVar2 = (void *)0x0;
          param_1[1] = param_1[1] + 1;
        }
LAB_001bf22c:
        iVar10 = local_18c;
        if (param_1[2] << 0x1f < 0) goto LAB_001bf30c;
LAB_001bf232:
        CRYPTO_free(local_148);
        local_18c = iVar10;
      }
      if (param_1[2] << 0x1f < 0) {
        CRYPTO_secure_clear_free(local_144,0,"crypto/store/loader_file.c",0x46c);
      }
      else {
        CRYPTO_free(local_144);
      }
      if (param_1[2] << 0x1f < 0) {
        CRYPTO_secure_clear_free(local_140,local_13c,"crypto/store/loader_file.c",0x46c);
      }
      else {
        CRYPTO_free(local_140);
      }
      if (local_18c == 0) {
        if (*param_1 == 2) {
          iVar10 = param_1[4];
LAB_001bf2a2:
          if (iVar10 != 0) goto joined_r0x001bf35a;
        }
        else if ((param_1[4] == 0) ||
                (iVar10 = (**(code **)(param_1[4] + 8))(param_1[5]), iVar10 != 0)) {
          iVar10 = BIO_ctrl((BIO *)param_1[3],2,0,(void *)0x0);
          goto LAB_001bf2a2;
        }
        if (0 < param_1[1]) goto joined_r0x001bf35a;
        iVar10 = *param_1;
        goto LAB_001bf03a;
      }
      if (1 < local_18c) {
        return (void *)0x0;
      }
joined_r0x001bf35a:
      if (pvVar2 == (void *)0x0) {
        return (void *)0x0;
      }
      iVar10 = param_1[0xb];
      if ((iVar10 == 0) || (iVar7 = OSSL_STORE_INFO_get_type(pvVar2), iVar10 == iVar7)) {
        return pvVar2;
      }
      OSSL_STORE_INFO_free(pvVar2);
    } while( true );
  }
LAB_001bf406:
  pcVar11 = (char *)param_1[9];
  do {
    if (pcVar11 == (char *)0x0) {
      if (param_1[4] == 0) {
        ERR_put_error(0x2c,0x77,2,"crypto/store/loader_file.c",0x514);
        piVar4 = __errno_location();
        *piVar4 = param_1[10];
        param_1[1] = param_1[1] + 1;
        iVar10 = openssl_strerror_r(*piVar4,local_128,0x100);
        if (iVar10 != 0) {
          ERR_add_error_data(1,local_128);
        }
      }
      return (void *)0x0;
    }
    if (*pcVar11 != '.') {
      if ((char)param_1[6] == '\0') goto LAB_001bf524;
      uVar13 = param_1[0xb];
      uVar16 = uVar13;
      if (uVar13 != 0) {
        uVar16 = 1;
      }
      if (((uVar13 == 4 || (uVar13 == 0 || uVar13 == 5)) &&
          (iVar10 = strncasecmp(pcVar11,(char *)(param_1 + 6),8), iVar10 == 0)) &&
         (pcVar11[8] == '.')) {
        cVar1 = pcVar11[9];
        pcVar12 = pcVar11 + 9;
        if (cVar1 == 'r') {
          if (uVar13 == 5) {
            uVar16 = 0;
          }
          else {
            uVar16 = uVar16 & 1;
          }
          pcVar12 = pcVar11 + 10;
          if (uVar16 == 0) {
            cVar1 = pcVar11[10];
            goto LAB_001bf4fe;
          }
        }
        else if (uVar13 != 5) {
LAB_001bf4fe:
          iVar10 = ossl_ctype_check(cVar1,4);
          if (iVar10 != 0) {
            do {
              pcVar11 = pcVar12;
              iVar10 = ossl_ctype_check(*pcVar11,4);
              pcVar12 = pcVar11 + 1;
            } while (iVar10 != 0);
            if (*pcVar11 == '\0') {
              pcVar11 = (char *)param_1[9];
LAB_001bf524:
              pcVar12 = (char *)param_1[5];
              if (*pcVar12 == '\0') {
                iVar10 = 1;
                sVar6 = strlen(pcVar12);
                pcVar12 = "/";
              }
              else {
                sVar6 = strlen(pcVar12);
                if (pcVar12[sVar6 - 1] == '/') {
                  iVar10 = 0;
                  pcVar12 = "";
                }
                else {
                  iVar10 = 1;
                  pcVar12 = "/";
                }
              }
              sVar8 = strlen(pcVar11);
              iVar10 = iVar10 + sVar6 + 1 + sVar8;
              pvVar2 = (void *)CRYPTO_zalloc(iVar10,"crypto/store/loader_file.c",0x4b7);
              if (pvVar2 == (void *)0x0) {
                ERR_put_error(0x2c,0x7e,0x41,"crypto/store/loader_file.c",0x4b9);
                return (void *)0x0;
              }
              OPENSSL_strlcat(pvVar2,param_1[5],iVar10);
              OPENSSL_strlcat(pvVar2,pcVar12,iVar10);
              OPENSSL_strlcat(pvVar2,pcVar11,iVar10);
              iVar10 = OPENSSL_DIR_read(param_1 + 3,param_1[5]);
              param_1[9] = iVar10;
              piVar4 = __errno_location();
              iVar7 = *piVar4;
              param_1[10] = iVar7;
              if (iVar7 == 0 && iVar10 == 0) {
                param_1[4] = 1;
              }
              pvVar5 = (void *)OSSL_STORE_INFO_new_NAME(pvVar2);
              if (pvVar5 == (void *)0x0) {
                CRYPTO_free(pvVar2);
                ERR_put_error(0x2c,0x77,0x2c,"crypto/store/loader_file.c",0x531);
                return (void *)0x0;
              }
              return pvVar5;
            }
          }
        }
      }
    }
    iVar10 = OPENSSL_DIR_read(param_1 + 3,param_1[5]);
    param_1[9] = iVar10;
    piVar4 = __errno_location();
    iVar7 = *piVar4;
    param_1[10] = iVar7;
    if (iVar7 == 0 && iVar10 == 0) {
      iVar10 = 1;
      param_1[4] = 1;
      if (*param_1 != 2) {
LAB_001bf460:
        iVar10 = (**(code **)(iVar10 + 8))(param_1[5]);
        if (iVar10 == 0) goto LAB_001bf406;
LAB_001bf46a:
        iVar10 = BIO_ctrl((BIO *)param_1[3],2,0,(void *)0x0);
      }
    }
    else {
      iVar10 = param_1[4];
      if (*param_1 != 2) {
        if (iVar10 != 0) goto LAB_001bf460;
        goto LAB_001bf46a;
      }
    }
    if (iVar10 != 0) {
      return (void *)0x0;
    }
    pcVar11 = (char *)param_1[9];
  } while( true );
}

