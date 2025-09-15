
uint tls1_check_chain(uint *param_1,X509 *param_2,EVP_PKEY *param_3,_STACK *param_4,uint param_5)

{
  int *piVar1;
  EVP_PKEY *pEVar2;
  EC_GROUP *pEVar3;
  EC_METHOD *pEVar4;
  EC_POINT *pEVar5;
  point_conversion_form_t pVar6;
  char *pcVar7;
  X509_NAME *pXVar8;
  int iVar9;
  X509 *pXVar10;
  X509_NAME *pXVar11;
  int iVar12;
  EVP_MD *pEVar13;
  char cVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  char *pcVar19;
  rsa_st *prVar20;
  uint uVar21;
  int *piVar22;
  _STACK *p_Var23;
  uint uVar24;
  int *piVar25;
  bool bVar26;
  EVP_PKEY *local_50;
  uint local_4c;
  int local_48;
  uint local_44;
  undefined1 local_38 [8];
  char local_30;
  char local_2f;
  
  piVar25 = (int *)param_1[0x26];
  local_44 = piVar25[0xe] & 0x30000;
  if (param_5 != 0xffffffff) {
    iVar15 = param_5 + 2;
    bVar26 = iVar15 != 0;
    if (bVar26) {
      piVar22 = piVar25 + param_5 * 7 + 0xf;
    }
    else {
      piVar22 = (int *)*piVar25;
      iVar15 = -0x49249249;
      param_5 = (int)piVar22 - (int)(piVar25 + 0xf);
    }
    param_2 = (X509 *)*piVar22;
    if (!bVar26) {
      param_5 = (int)param_5 >> 2;
    }
    local_50 = (EVP_PKEY *)piVar22[1];
    uVar24 = piVar25[0xe] & 0x30001;
    if (!bVar26) {
      param_5 = iVar15 * param_5;
    }
    param_4 = (_STACK *)piVar22[3];
    if (param_2 != (X509 *)0x0 && local_50 != (EVP_PKEY *)0x0) {
      if (local_44 == 0) {
        uVar16 = 0x30;
        local_4c = 0;
      }
      else {
        iVar15 = X509_chain_check_suiteb(0,param_2,param_4,local_44);
        if (iVar15 != 0) {
          local_4c = 0;
          uVar21 = 0;
          goto LAB_0007368c;
        }
        uVar16 = 0x830;
        local_44 = 0x800;
        local_4c = 0;
      }
      goto LAB_00073754;
    }
    local_4c = 0;
    uVar21 = 0;
    goto LAB_0007368c;
  }
  if ((param_2 == (X509 *)0x0 || param_3 == (EVP_PKEY *)0x0) ||
     (param_5 = ssl_cert_type(param_2,param_3), param_5 == 0xffffffff)) {
    return 0;
  }
  if ((piVar25[0xe] & 0x30001U) == 0) {
    local_4c = 0x50;
  }
  else {
    local_4c = 0x6f0;
  }
  piVar22 = piVar25 + param_5 * 7 + 0xf;
  local_50 = param_3;
  if (local_44 == 0) {
    uVar16 = 0x30;
    uVar24 = 1;
  }
  else {
    iVar15 = X509_chain_check_suiteb(0,param_2,param_4,local_44);
    if (iVar15 != 0) {
      uVar16 = 0x30;
    }
    else {
      uVar16 = 0x830;
    }
    uVar24 = 1;
    if (iVar15 != 0) {
      local_44 = 0;
    }
    else {
      local_44 = 0x800;
    }
    local_4c = local_4c | 0x800;
  }
LAB_00073754:
  if ((((int)*param_1 >> 8 != 3) || ((int)*param_1 < 0x303)) || (uVar24 == 0)) {
    if (local_4c == 0) {
      local_48 = 2;
    }
    else {
LAB_0007391c:
      local_44 = uVar16;
      local_48 = 1;
    }
LAB_0007376a:
    pEVar2 = X509_get_pubkey(param_2);
    if (pEVar2 == (EVP_PKEY *)0x0) goto LAB_00073928;
    if (pEVar2->type == 0x198) {
      prVar20 = (pEVar2->pkey).rsa;
      if (((prVar20 == (rsa_st *)0x0) ||
          (pEVar3 = EC_KEY_get0_group((EC_KEY *)prVar20), pEVar3 == (EC_GROUP *)0x0)) ||
         (pEVar4 = EC_GROUP_method_of(pEVar3), pEVar4 == (EC_METHOD *)0x0)) {
LAB_00073922:
        EVP_PKEY_free(pEVar2);
      }
      else {
        iVar15 = EC_METHOD_get_field_type(pEVar4);
        EC_GROUP_get_curve_name(pEVar3);
        iVar9 = tls1_ec_nid2curve_id();
        if (iVar9 == 0) {
          local_30 = -1;
          if (iVar15 != 0x196) {
            local_2f = '\x02';
          }
          else {
            local_2f = '\x01';
          }
        }
        else {
          local_2f = (char)iVar9;
          local_30 = '\0';
        }
        pEVar5 = EC_KEY_get0_public_key((EC_KEY *)prVar20);
        if (pEVar5 == (EC_POINT *)0x0) goto LAB_00073922;
        pVar6 = EC_KEY_get_conv_form((EC_KEY *)prVar20);
        if (pVar6 == POINT_CONVERSION_COMPRESSED) {
          if (iVar15 != 0x196) {
            local_38[0] = 2;
          }
          else {
            local_38[0] = 1;
          }
        }
        else {
          local_38[0] = 0;
        }
        EVP_PKEY_free(pEVar2);
        pcVar19 = (char *)param_1[9];
        if (pcVar19 != (char *)0x0) {
          pcVar19 = &local_30;
        }
        iVar15 = tls1_check_ec_key(param_1,pcVar19,local_38);
        if (iVar15 != 0) {
          uVar21 = param_1[0x26];
          if ((*(uint *)(uVar21 + 0x38) & 0x30000) == 0) goto LAB_00073786;
          if (local_30 == '\0') {
            if (local_2f == '\x17') {
              iVar15 = 0x31a;
            }
            else {
              if (local_2f != '\x18') goto LAB_00073928;
              iVar15 = 0x31b;
            }
            if (*(int *)(uVar21 + 0x140) != 0) {
              if (*(int *)(*(int *)(uVar21 + 0x13c) + 8) != iVar15) {
                iVar12 = 0;
                iVar9 = *(int *)(uVar21 + 0x13c);
                do {
                  iVar12 = iVar12 + 1;
                  if (iVar12 == *(int *)(uVar21 + 0x140)) goto LAB_00073928;
                  piVar1 = (int *)(iVar9 + 0x18);
                  iVar9 = iVar9 + 0x10;
                } while (*piVar1 != iVar15);
              }
              if (local_48 == 2) {
                if (iVar15 == 0x31a) {
                  pEVar13 = EVP_sha256();
                  *(EVP_MD **)(uVar21 + 0xd0) = pEVar13;
                }
                else {
                  pEVar13 = EVP_sha384();
                  *(EVP_MD **)(uVar21 + 0xd0) = pEVar13;
                }
              }
              goto LAB_00073786;
            }
          }
        }
      }
LAB_00073928:
      uVar21 = local_44;
      if (local_4c == 0) goto LAB_0007368c;
    }
    else {
      EVP_PKEY_free(pEVar2);
LAB_00073786:
      local_44 = local_44 | 0x40;
    }
    if (param_1[9] == 0) {
      local_44 = local_44 | 0x80;
      if (uVar24 != 0) {
LAB_000737a0:
        iVar15 = local_50->type;
        if (iVar15 == 0x74) {
          cVar14 = '\x02';
LAB_00073b6a:
          pcVar19 = (char *)piVar25[0x47];
          if (pcVar19 == (char *)0x0) {
            iVar15 = *(int *)(param_1[0x16] + 0x35c);
            pcVar19 = (char *)(param_1[0x16] + 0x360);
          }
          else {
            iVar15 = piVar25[0x48];
          }
          if (0 < iVar15) {
            if (*pcVar19 != cVar14) {
              pcVar7 = pcVar19 + iVar15 + -1;
              do {
                if (pcVar19 == pcVar7) goto LAB_00073b98;
                pcVar19 = pcVar19 + 1;
              } while (*pcVar19 != cVar14);
            }
            local_44 = local_44 | 0x400;
          }
LAB_00073b98:
          if ((local_44 & 0x400) == 0 && local_4c == 0) {
            local_4c = 0;
            uVar21 = local_44;
            goto LAB_0007368c;
          }
        }
        else {
          if (0x74 < iVar15) {
            if (iVar15 != 0x198) {
              if (iVar15 == 0x398) goto LAB_00073bd6;
              goto LAB_000737ba;
            }
            cVar14 = '@';
            goto LAB_00073b6a;
          }
          if (iVar15 == 6) {
            cVar14 = '\x01';
            goto LAB_00073b6a;
          }
          if (iVar15 == 0x1c) {
LAB_00073bd6:
            uVar24 = X509_certificate_type(param_2,local_50);
            if ((uVar24 & 0x100) == 0) {
              cVar14 = '\0';
            }
            else {
              cVar14 = '\x03';
            }
            if ((int)(uVar24 << 0x16) < 0) {
              cVar14 = '\x04';
            }
            else if (cVar14 == '\0') goto LAB_000737ba;
            goto LAB_00073b6a;
          }
LAB_000737ba:
          local_44 = local_44 | 0x400;
        }
        p_Var23 = *(_STACK **)(param_1[0x16] + 0x36c);
        iVar15 = sk_num(p_Var23);
        if (iVar15 == 0) {
          local_44 = local_44 | 0x200;
        }
        if ((local_44 & 0x200) == 0) {
          pXVar8 = X509_get_issuer_name(param_2);
          iVar15 = 0;
LAB_00073c1e:
          iVar9 = sk_num(p_Var23);
          if (iVar15 < iVar9) goto LAB_00073c10;
          for (iVar15 = 0; iVar9 = sk_num(param_4), iVar15 < iVar9; iVar15 = iVar15 + 1) {
            pXVar10 = (X509 *)sk_value(param_4,iVar15);
            pXVar8 = X509_get_issuer_name(pXVar10);
            iVar9 = 0;
            while( true ) {
              iVar12 = sk_num(p_Var23);
              if (iVar12 <= iVar9) break;
              pXVar11 = (X509_NAME *)sk_value(p_Var23,iVar9);
              iVar12 = X509_NAME_cmp(pXVar8,pXVar11);
              iVar9 = iVar9 + 1;
              if (iVar12 == 0) goto LAB_00073c7a;
            }
          }
        }
        goto LAB_000737da;
      }
    }
    else if (uVar24 != 0) {
      iVar9 = 0;
      uVar24 = local_44 | 0x80;
      iVar15 = sk_num(param_4);
      if (0 < iVar15) {
        do {
          pXVar10 = (X509 *)sk_value(param_4,iVar9);
          pEVar2 = X509_get_pubkey(pXVar10);
          if (pEVar2 == (EVP_PKEY *)0x0) {
LAB_000739b6:
            uVar21 = uVar24;
            uVar24 = local_44;
            if (local_4c == 0) goto LAB_0007368c;
            break;
          }
          if (pEVar2->type == 0x198) {
            prVar20 = (pEVar2->pkey).rsa;
            if (((prVar20 != (rsa_st *)0x0) &&
                (pEVar3 = EC_KEY_get0_group((EC_KEY *)prVar20), pEVar3 != (EC_GROUP *)0x0)) &&
               (pEVar4 = EC_GROUP_method_of(pEVar3), pEVar4 != (EC_METHOD *)0x0)) {
              iVar15 = EC_METHOD_get_field_type(pEVar4);
              EC_GROUP_get_curve_name(pEVar3);
              iVar12 = tls1_ec_nid2curve_id();
              if (iVar12 == 0) {
                local_30 = -1;
                if (iVar15 == 0x196) {
                  local_2f = '\x01';
                }
                else {
                  local_2f = '\x02';
                }
              }
              else {
                local_2f = (char)iVar12;
                local_30 = '\0';
              }
              pEVar5 = EC_KEY_get0_public_key((EC_KEY *)prVar20);
              if (pEVar5 != (EC_POINT *)0x0) {
                pVar6 = EC_KEY_get_conv_form((EC_KEY *)prVar20);
                if (pVar6 == POINT_CONVERSION_COMPRESSED) {
                  local_38[0] = 2;
                  if (iVar15 == 0x196) {
                    local_38[0] = 1;
                  }
                }
                else {
                  local_38[0] = 0;
                }
                EVP_PKEY_free(pEVar2);
                pcVar19 = (char *)param_1[9];
                if (pcVar19 != (char *)0x0) {
                  pcVar19 = &local_30;
                }
                iVar15 = tls1_check_ec_key(param_1,pcVar19,local_38);
                if (iVar15 == 0) goto LAB_000739b6;
                goto LAB_0007382a;
              }
            }
            EVP_PKEY_free(pEVar2);
            goto LAB_000739b6;
          }
          EVP_PKEY_free(pEVar2);
LAB_0007382a:
          iVar9 = iVar9 + 1;
          iVar15 = sk_num(param_4);
        } while (iVar9 < iVar15);
      }
      local_44 = uVar24;
      if (param_1[9] == 0) goto LAB_000737a0;
    }
    local_44 = local_44 | 0x600;
    if (local_4c == 0) goto LAB_00073852;
    goto LAB_00073ab0;
  }
  iVar15 = 0;
  if (piVar25[0x49] != 0) {
LAB_00073adc:
    iVar9 = X509_get_signature_nid(param_2);
    if (iVar15 == 0) {
      if (piVar25[0x50] != 0) {
        if (iVar9 != *(int *)(piVar25[0x4f] + 8)) {
          iVar12 = 0;
          iVar18 = piVar25[0x4f];
          do {
            iVar12 = iVar12 + 1;
            if (iVar12 == piVar25[0x50]) goto LAB_000738aa;
            piVar1 = (int *)(iVar18 + 0x18);
            iVar18 = iVar18 + 0x10;
          } while (iVar9 != *piVar1);
        }
        goto LAB_00073c9c;
      }
    }
    else {
LAB_000738a4:
      if (iVar9 == iVar15) goto LAB_00073c9c;
    }
LAB_000738aa:
    uVar21 = local_44;
    if (local_4c == 0) goto LAB_0007368c;
LAB_000738b4:
    uVar21 = local_44 | 0x20;
    for (iVar9 = 0; iVar12 = sk_num(param_4), iVar9 < iVar12; iVar9 = iVar9 + 1) {
      sk_value(param_4,iVar9);
      if (iVar15 != -1) {
        iVar12 = X509_get_signature_nid();
        if (iVar15 == 0) {
          if (piVar25[0x50] == 0) {
LAB_0007390e:
            uVar16 = local_44;
            if (local_4c != 0) goto LAB_0007391c;
            goto LAB_0007368c;
          }
          if (iVar12 != *(int *)(piVar25[0x4f] + 8)) {
            iVar18 = 0;
            iVar17 = piVar25[0x4f];
            do {
              iVar18 = iVar18 + 1;
              if (iVar18 == piVar25[0x50]) goto LAB_0007390e;
              piVar1 = (int *)(iVar17 + 0x18);
              iVar17 = iVar17 + 0x10;
            } while (iVar12 != *piVar1);
          }
        }
        else if (iVar12 != iVar15) goto LAB_0007390e;
      }
    }
    uVar16 = uVar21;
    if (local_4c != 0) goto LAB_0007391c;
    local_48 = 2;
    local_44 = uVar21;
    goto LAB_0007376a;
  }
  if (5 < param_5) {
    iVar15 = -1;
LAB_00073c9c:
    local_44 = local_44 | 0x10;
    goto LAB_000738b4;
  }
  iVar15 = *(int *)(CSWTCH_188 + param_5 * 4);
  if (iVar15 < 1) {
    if (iVar15 != -1) goto LAB_00073adc;
    goto LAB_00073c9c;
  }
  iVar9 = piVar25[0x4b];
  if (iVar9 == 0) {
LAB_0007389e:
    iVar9 = X509_get_signature_nid(param_2);
    goto LAB_000738a4;
  }
  uVar16 = piVar25[0x4c];
  uVar21 = 0;
  if (uVar16 != 0) {
    do {
      if ((*(char *)(iVar9 + uVar21) == '\x02') &&
         (*(char *)(iVar9 + uVar21 + 1) == *(char *)((int)&CSWTCH_189 + param_5))) break;
      uVar21 = uVar21 + 2;
    } while (uVar21 < uVar16);
    if (uVar16 != uVar21) goto LAB_0007389e;
  }
  uVar16 = local_44;
  if (local_4c != 0) goto LAB_0007391c;
LAB_000736d6:
  uVar24 = piVar22[6];
  if (-1 < (int)(uVar24 << 0x17)) {
    uVar24 = piVar22[2];
    if (uVar24 != 0) {
      local_44 = local_44 | 2;
    }
    goto LAB_00073698;
  }
  goto LAB_00073694;
LAB_00073c10:
  pXVar11 = (X509_NAME *)sk_value(p_Var23,iVar15);
  iVar9 = X509_NAME_cmp(pXVar8,pXVar11);
  iVar15 = iVar15 + 1;
  if (iVar9 == 0) goto LAB_00073c7a;
  goto LAB_00073c1e;
LAB_00073c7a:
  local_44 = local_44 | 0x200;
LAB_000737da:
  if (local_4c == 0) {
    uVar21 = local_44;
    if ((int)(local_44 << 0x16) < 0) goto LAB_00073852;
  }
  else {
LAB_00073ab0:
    uVar21 = local_44;
    if ((local_44 & local_4c) == local_4c) {
LAB_00073852:
      uVar21 = local_44 | 1;
    }
  }
LAB_0007368c:
  uVar24 = *param_1;
  local_44 = uVar21;
  if (((int)uVar24 >> 8 == 3) && (0x302 < (int)uVar24)) goto LAB_000736d6;
LAB_00073694:
  local_44 = local_44 | 0x102;
LAB_00073698:
  if (local_4c == 0) {
    bVar26 = (int)(local_44 << 0x1f) < 0;
    if (!bVar26) {
      uVar24 = piVar22[6];
      local_44 = 0;
    }
    if (bVar26) {
      piVar22[6] = local_44;
    }
    else {
      uVar24 = uVar24 & 0x100;
    }
    if (!bVar26) {
      piVar22[6] = uVar24;
    }
  }
  return local_44;
}

