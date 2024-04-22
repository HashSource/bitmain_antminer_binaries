
/* WARNING: Type propagation algorithm not settling */

X509 * tls1_check_chain(X509 **param_1,X509 *param_2,X509 *param_3,X509 *param_4,uint param_5)

{
  int *piVar1;
  undefined4 uVar2;
  EVP_PKEY *pEVar3;
  X509 *pXVar4;
  stack_st_IPAddressFamily *psVar5;
  EC_GROUP *pEVar6;
  EC_METHOD *pEVar7;
  EC_POINT *pEVar8;
  point_conversion_form_t pVar9;
  X509_NAME *pXVar10;
  int iVar11;
  X509_NAME *pXVar12;
  int iVar13;
  EVP_MD *pEVar14;
  char cVar15;
  int iVar16;
  X509 *pXVar17;
  int *piVar18;
  NAME_CONSTRAINTS *pNVar19;
  X509_CINF *pXVar20;
  stack_st_IPAddressFamily *psVar21;
  int *piVar22;
  AUTHORITY_KEYID *pAVar23;
  rsa_st *prVar24;
  X509 **ppXVar25;
  _STACK *p_Var26;
  uint uVar27;
  X509 *pXVar28;
  bool bVar29;
  X509 *local_50;
  uint local_4c;
  int local_48;
  X509 *local_44;
  undefined local_38 [8];
  char local_30;
  char local_2f;
  
  pXVar28 = param_1[0x26];
  local_44 = (X509 *)((uint)pXVar28->skid & 0x30000);
  if (param_5 != 0xffffffff) {
    iVar16 = param_5 + 2;
    bVar29 = iVar16 != 0;
    if (bVar29) {
      ppXVar25 = (X509 **)((int)pXVar28->sha1_hash + param_5 * 0x1c + 0xffffffe4);
    }
    else {
      ppXVar25 = (X509 **)pXVar28->cert_info;
      iVar16 = -0x49249249;
      param_5 = (int)ppXVar25 - (int)&pXVar28->akid;
    }
    param_2 = *ppXVar25;
    if (!bVar29) {
      param_5 = (int)param_5 >> 2;
    }
    local_50 = ppXVar25[1];
    uVar27 = (uint)pXVar28->skid & 0x30001;
    if (!bVar29) {
      param_5 = iVar16 * param_5;
    }
    param_4 = ppXVar25[3];
    if (param_2 != (X509 *)0x0 && local_50 != (X509 *)0x0) {
      if (local_44 == (X509 *)0x0) {
        pXVar17 = (X509 *)0x30;
        local_4c = 0;
      }
      else {
        iVar16 = X509_chain_check_suiteb(0,param_2,param_4,local_44);
        if (iVar16 != 0) {
          local_4c = 0;
          pXVar4 = (X509 *)0x0;
          goto LAB_0007368c;
        }
        pXVar17 = (X509 *)0x830;
        local_44 = (X509 *)0x800;
        local_4c = 0;
      }
      goto LAB_00073754;
    }
    local_4c = 0;
    pXVar4 = (X509 *)0x0;
    goto LAB_0007368c;
  }
  if ((param_2 == (X509 *)0x0 || param_3 == (X509 *)0x0) ||
     (param_5 = ssl_cert_type(param_2,param_3), param_5 == 0xffffffff)) {
    return (X509 *)0x0;
  }
  if (((uint)pXVar28->skid & 0x30001) == 0) {
    local_4c = 0x50;
  }
  else {
    local_4c = 0x6f0;
  }
  ppXVar25 = (X509 **)((int)pXVar28->sha1_hash + param_5 * 0x1c + 0xffffffe4);
  local_50 = param_3;
  if (local_44 == (X509 *)0x0) {
    pXVar17 = (X509 *)0x30;
    uVar27 = 1;
  }
  else {
    iVar16 = X509_chain_check_suiteb(0,param_2,param_4);
    if (iVar16 != 0) {
      pXVar17 = (X509 *)0x30;
    }
    else {
      pXVar17 = (X509 *)0x830;
    }
    uVar27 = 1;
    if (iVar16 != 0) {
      local_44 = (X509 *)0x0;
    }
    else {
      local_44 = (X509 *)0x800;
    }
    local_4c = local_4c | 0x800;
  }
LAB_00073754:
  if ((((int)*param_1 >> 8 != 3) || ((int)*param_1 < 0x303)) || (uVar27 == 0)) {
    if (local_4c == 0) {
      local_48 = 2;
    }
    else {
LAB_0007391c:
      local_44 = pXVar17;
      local_48 = 1;
    }
LAB_0007376a:
    pEVar3 = X509_get_pubkey(param_2);
    if (pEVar3 == (EVP_PKEY *)0x0) goto LAB_00073928;
    if (pEVar3->type == 0x198) {
      prVar24 = (pEVar3->pkey).rsa;
      if (((prVar24 == (rsa_st *)0x0) ||
          (pEVar6 = EC_KEY_get0_group((EC_KEY *)prVar24), pEVar6 == (EC_GROUP *)0x0)) ||
         (pEVar7 = EC_GROUP_method_of(pEVar6), pEVar7 == (EC_METHOD *)0x0)) {
LAB_00073922:
        EVP_PKEY_free(pEVar3);
      }
      else {
        iVar16 = EC_METHOD_get_field_type(pEVar7);
        EC_GROUP_get_curve_name(pEVar6);
        iVar11 = tls1_ec_nid2curve_id();
        if (iVar11 == 0) {
          local_30 = -1;
          if (iVar16 != 0x196) {
            local_2f = '\x02';
          }
          else {
            local_2f = '\x01';
          }
        }
        else {
          local_2f = (char)iVar11;
          local_30 = '\0';
        }
        pEVar8 = EC_KEY_get0_public_key((EC_KEY *)prVar24);
        if (pEVar8 == (EC_POINT *)0x0) goto LAB_00073922;
        pVar9 = EC_KEY_get_conv_form((EC_KEY *)prVar24);
        if (pVar9 == POINT_CONVERSION_COMPRESSED) {
          if (iVar16 != 0x196) {
            local_38[0] = 2;
          }
          else {
            local_38[0] = 1;
          }
        }
        else {
          local_38[0] = 0;
        }
        EVP_PKEY_free(pEVar3);
        pXVar4 = param_1[9];
        if (pXVar4 != (X509 *)0x0) {
          pXVar4 = (X509 *)&local_30;
        }
        iVar16 = tls1_check_ec_key(param_1,pXVar4,local_38);
        if (iVar16 != 0) {
          pXVar4 = param_1[0x26];
          if (((uint)pXVar4->skid & 0x30000) == 0) goto LAB_00073786;
          if (local_30 == '\0') {
            if (local_2f == '\x17') {
              iVar16 = 0x31a;
            }
            else {
              if (local_2f != '\x18') goto LAB_00073928;
              iVar16 = 0x31b;
            }
            if (*(int *)((int)(pXVar4 + 2) + 0x60) != 0) {
              if (*(int *)(*(int *)((int)(pXVar4 + 2) + 0x5c) + 8) != iVar16) {
                iVar13 = 0;
                iVar11 = *(int *)((int)(pXVar4 + 2) + 0x5c);
                do {
                  iVar13 = iVar13 + 1;
                  if (iVar13 == *(int *)((int)(pXVar4 + 2) + 0x60)) goto LAB_00073928;
                  piVar22 = (int *)(iVar11 + 0x18);
                  iVar11 = iVar11 + 0x10;
                } while (*piVar22 != iVar16);
              }
              if (local_48 == 2) {
                if (iVar16 == 0x31a) {
                  pEVar14 = EVP_sha256();
                  *(EVP_MD **)((int)(pXVar4 + 1) + 0x60) = pEVar14;
                }
                else {
                  pEVar14 = EVP_sha384();
                  *(EVP_MD **)((int)(pXVar4 + 1) + 0x60) = pEVar14;
                }
              }
              goto LAB_00073786;
            }
          }
        }
      }
LAB_00073928:
      pXVar4 = local_44;
      if (local_4c == 0) goto LAB_0007368c;
    }
    else {
      EVP_PKEY_free(pEVar3);
LAB_00073786:
      local_44 = (X509 *)((uint)local_44 | 0x40);
    }
    if (param_1[9] == (X509 *)0x0) {
      local_44 = (X509 *)((uint)local_44 | 0x80);
      if (uVar27 != 0) {
LAB_000737a0:
        pXVar20 = local_50->cert_info;
        if (pXVar20 == (X509_CINF *)0x74) {
          cVar15 = '\x02';
LAB_00073b6a:
          pAVar23 = *(AUTHORITY_KEYID **)((int)(pXVar28 + 2) + 0x3c);
          if (pAVar23 == (AUTHORITY_KEYID *)0x0) {
            pNVar19 = *(NAME_CONSTRAINTS **)((int)(param_1[0x16] + 7) + 0x4c);
            pAVar23 = (AUTHORITY_KEYID *)((int)(param_1[0x16] + 7) + 0x50);
          }
          else {
            pNVar19 = *(NAME_CONSTRAINTS **)((int)(pXVar28 + 2) + 0x40);
          }
          if (0 < (int)pNVar19) {
            if (*(char *)&pAVar23->keyid != cVar15) {
              uVar2 = pAVar23 + 0xffffffff;
              do {
                if (pAVar23 == (AUTHORITY_KEYID *)((char *)(uVar2 + 0xb) + (int)pNVar19))
                goto LAB_00073b98;
                pAVar23 = (AUTHORITY_KEYID *)((int)&pAVar23->keyid + 1);
              } while (*(char *)&pAVar23->keyid != cVar15);
            }
            local_44 = (X509 *)((uint)local_44 | 0x400);
          }
LAB_00073b98:
          if (((uint)local_44 & 0x400 | local_4c) == 0) {
            local_4c = 0;
            pXVar4 = local_44;
            goto LAB_0007368c;
          }
        }
        else {
          if (0x74 < (int)pXVar20) {
            if (pXVar20 != (X509_CINF *)0x198) {
              if (pXVar20 == (X509_CINF *)0x398) goto LAB_00073bd6;
              goto LAB_000737ba;
            }
            cVar15 = '@';
            goto LAB_00073b6a;
          }
          if (pXVar20 == (X509_CINF *)0x6) {
            cVar15 = '\x01';
            goto LAB_00073b6a;
          }
          if (pXVar20 == (X509_CINF *)0x1c) {
LAB_00073bd6:
            uVar27 = X509_certificate_type(param_2,(EVP_PKEY *)local_50);
            if ((uVar27 & 0x100) == 0) {
              cVar15 = '\0';
            }
            else {
              cVar15 = '\x03';
            }
            if ((int)(uVar27 << 0x16) < 0) {
              cVar15 = '\x04';
            }
            else if (cVar15 == '\0') goto LAB_000737ba;
            goto LAB_00073b6a;
          }
LAB_000737ba:
          local_44 = (X509 *)((uint)local_44 | 0x400);
        }
        p_Var26 = *(_STACK **)((int)(param_1[0x16] + 7) + 0x5c);
        iVar16 = sk_num(p_Var26);
        if (iVar16 == 0) {
          local_44 = (X509 *)((uint)local_44 | 0x200);
        }
        if (((uint)local_44 & 0x200) == 0) {
          pXVar10 = X509_get_issuer_name(param_2);
          iVar16 = 0;
LAB_00073c1e:
          iVar11 = sk_num(p_Var26);
          if (iVar16 < iVar11) goto LAB_00073c10;
          for (iVar16 = 0; iVar11 = sk_num((_STACK *)param_4), iVar16 < iVar11; iVar16 = iVar16 + 1)
          {
            pXVar28 = (X509 *)sk_value((_STACK *)param_4,iVar16);
            pXVar10 = X509_get_issuer_name(pXVar28);
            iVar11 = 0;
            while( true ) {
              iVar13 = sk_num(p_Var26);
              if (iVar13 <= iVar11) break;
              pXVar12 = (X509_NAME *)sk_value(p_Var26,iVar11);
              iVar13 = X509_NAME_cmp(pXVar10,pXVar12);
              iVar11 = iVar11 + 1;
              if (iVar13 == 0) goto LAB_00073c7a;
            }
          }
        }
        goto LAB_000737da;
      }
    }
    else if (uVar27 != 0) {
      iVar11 = 0;
      pXVar17 = (X509 *)((uint)local_44 | 0x80);
      iVar16 = sk_num((_STACK *)param_4);
      if (0 < iVar16) {
        do {
          pXVar4 = (X509 *)sk_value((_STACK *)param_4,iVar11);
          pEVar3 = X509_get_pubkey(pXVar4);
          if (pEVar3 == (EVP_PKEY *)0x0) {
LAB_000739b6:
            pXVar4 = pXVar17;
            pXVar17 = local_44;
            if (local_4c == 0) goto LAB_0007368c;
            break;
          }
          if (pEVar3->type == 0x198) {
            prVar24 = (pEVar3->pkey).rsa;
            if (((prVar24 != (rsa_st *)0x0) &&
                (pEVar6 = EC_KEY_get0_group((EC_KEY *)prVar24), pEVar6 != (EC_GROUP *)0x0)) &&
               (pEVar7 = EC_GROUP_method_of(pEVar6), pEVar7 != (EC_METHOD *)0x0)) {
              iVar16 = EC_METHOD_get_field_type(pEVar7);
              EC_GROUP_get_curve_name(pEVar6);
              iVar13 = tls1_ec_nid2curve_id();
              if (iVar13 == 0) {
                local_30 = -1;
                if (iVar16 == 0x196) {
                  local_2f = '\x01';
                }
                else {
                  local_2f = '\x02';
                }
              }
              else {
                local_2f = (char)iVar13;
                local_30 = '\0';
              }
              pEVar8 = EC_KEY_get0_public_key((EC_KEY *)prVar24);
              if (pEVar8 != (EC_POINT *)0x0) {
                pVar9 = EC_KEY_get_conv_form((EC_KEY *)prVar24);
                if (pVar9 == POINT_CONVERSION_COMPRESSED) {
                  local_38[0] = 2;
                  if (iVar16 == 0x196) {
                    local_38[0] = 1;
                  }
                }
                else {
                  local_38[0] = 0;
                }
                EVP_PKEY_free(pEVar3);
                pXVar4 = param_1[9];
                if (pXVar4 != (X509 *)0x0) {
                  pXVar4 = (X509 *)&local_30;
                }
                iVar16 = tls1_check_ec_key(param_1,pXVar4,local_38);
                if (iVar16 == 0) goto LAB_000739b6;
                goto LAB_0007382a;
              }
            }
            EVP_PKEY_free(pEVar3);
            goto LAB_000739b6;
          }
          EVP_PKEY_free(pEVar3);
LAB_0007382a:
          iVar11 = iVar11 + 1;
          iVar16 = sk_num((_STACK *)param_4);
        } while (iVar11 < iVar16);
      }
      local_44 = pXVar17;
      if (param_1[9] == (X509 *)0x0) goto LAB_000737a0;
    }
    local_44 = (X509 *)((uint)local_44 | 0x600);
    if (local_4c == 0) goto LAB_00073852;
    goto LAB_00073ab0;
  }
  iVar16 = 0;
  if (*(stack_st_DIST_POINT **)((int)(pXVar28 + 2) + 0x44) != (stack_st_DIST_POINT *)0x0) {
LAB_00073adc:
    iVar11 = X509_get_signature_nid(param_2);
    if (iVar16 == 0) {
      if (*(int **)((int)(pXVar28 + 2) + 0x60) != (int *)0x0) {
        if (iVar11 != (*(int **)((int)(pXVar28 + 2) + 0x5c))[2]) {
          piVar22 = (int *)0x0;
          piVar18 = *(int **)((int)(pXVar28 + 2) + 0x5c);
          do {
            piVar22 = (int *)((int)piVar22 + 1);
            if (piVar22 == *(int **)((int)(pXVar28 + 2) + 0x60)) goto LAB_000738aa;
            piVar1 = piVar18 + 6;
            piVar18 = piVar18 + 4;
          } while (iVar11 != *piVar1);
        }
        goto LAB_00073c9c;
      }
    }
    else {
LAB_000738a4:
      if (iVar11 == iVar16) goto LAB_00073c9c;
    }
LAB_000738aa:
    pXVar4 = local_44;
    if (local_4c == 0) goto LAB_0007368c;
LAB_000738b4:
    pXVar4 = (X509 *)((uint)local_44 | 0x20);
    for (iVar11 = 0; iVar13 = sk_num((_STACK *)param_4), iVar11 < iVar13; iVar11 = iVar11 + 1) {
      sk_value((_STACK *)param_4,iVar11);
      if (iVar16 != -1) {
        iVar13 = X509_get_signature_nid();
        if (iVar16 == 0) {
          if (*(int **)((int)(pXVar28 + 2) + 0x60) == (int *)0x0) {
LAB_0007390e:
            pXVar17 = local_44;
            if (local_4c != 0) goto LAB_0007391c;
            goto LAB_0007368c;
          }
          if (iVar13 != (*(int **)((int)(pXVar28 + 2) + 0x5c))[2]) {
            piVar22 = (int *)0x0;
            piVar18 = *(int **)((int)(pXVar28 + 2) + 0x5c);
            do {
              piVar22 = (int *)((int)piVar22 + 1);
              if (piVar22 == *(int **)((int)(pXVar28 + 2) + 0x60)) goto LAB_0007390e;
              piVar1 = piVar18 + 6;
              piVar18 = piVar18 + 4;
            } while (iVar13 != *piVar1);
          }
        }
        else if (iVar13 != iVar16) goto LAB_0007390e;
      }
    }
    pXVar17 = pXVar4;
    if (local_4c != 0) goto LAB_0007391c;
    local_48 = 2;
    local_44 = pXVar4;
    goto LAB_0007376a;
  }
  if (5 < param_5) {
    iVar16 = -1;
LAB_00073c9c:
    local_44 = (X509 *)((uint)local_44 | 0x10);
    goto LAB_000738b4;
  }
  iVar16 = *(int *)(DAT_00073b30 + param_5 * 4 + 0x120);
  if (iVar16 < 1) {
    if (iVar16 != -1) goto LAB_00073adc;
    goto LAB_00073c9c;
  }
  pNVar19 = *(NAME_CONSTRAINTS **)((int)(pXVar28 + 2) + 0x4c);
  if (pNVar19 == (NAME_CONSTRAINTS *)0x0) {
LAB_0007389e:
    iVar11 = X509_get_signature_nid(param_2);
    goto LAB_000738a4;
  }
  psVar5 = *(stack_st_IPAddressFamily **)((int)(pXVar28 + 2) + 0x50);
  psVar21 = (stack_st_IPAddressFamily *)0x0;
  if (psVar5 != (stack_st_IPAddressFamily *)0x0) {
    do {
      if ((*(char *)((int)&psVar21->stack + (int)&pNVar19->permittedSubtrees) == '\x02') &&
         (*(char *)((int)&psVar21->stack + (int)&pNVar19->permittedSubtrees + 1U) ==
          *(char *)(DAT_00073b30 + param_5 + 0x138))) break;
      psVar21 = (stack_st_IPAddressFamily *)((int)&psVar21->stack + 2);
    } while (psVar21 < psVar5);
    if (psVar5 != psVar21) goto LAB_0007389e;
  }
  pXVar17 = local_44;
  if (local_4c != 0) goto LAB_0007391c;
LAB_000736d6:
  pXVar28 = ppXVar25[6];
  if (-1 < (int)pXVar28 << 0x17) {
    pXVar28 = ppXVar25[2];
    if (pXVar28 != (X509 *)0x0) {
      local_44 = (X509 *)((uint)local_44 | 2);
    }
    goto LAB_00073698;
  }
  goto LAB_00073694;
LAB_00073c10:
  pXVar12 = (X509_NAME *)sk_value(p_Var26,iVar16);
  iVar11 = X509_NAME_cmp(pXVar10,pXVar12);
  iVar16 = iVar16 + 1;
  if (iVar11 == 0) goto LAB_00073c7a;
  goto LAB_00073c1e;
LAB_00073c7a:
  local_44 = (X509 *)((uint)local_44 | 0x200);
LAB_000737da:
  if (local_4c == 0) {
    pXVar4 = local_44;
    if ((int)local_44 << 0x16 < 0) goto LAB_00073852;
  }
  else {
LAB_00073ab0:
    pXVar4 = local_44;
    if (((uint)local_44 & local_4c) == local_4c) {
LAB_00073852:
      pXVar4 = (X509 *)((uint)local_44 | 1);
    }
  }
LAB_0007368c:
  pXVar28 = *param_1;
  local_44 = pXVar4;
  if (((int)pXVar28 >> 8 == 3) && (0x302 < (int)pXVar28)) goto LAB_000736d6;
LAB_00073694:
  local_44 = (X509 *)((uint)local_44 | 0x102);
LAB_00073698:
  if (local_4c == 0) {
    bVar29 = (int)local_44 << 0x1f < 0;
    if (!bVar29) {
      pXVar28 = ppXVar25[6];
      local_44 = (X509 *)0x0;
    }
    if (bVar29) {
      ppXVar25[6] = local_44;
    }
    else {
      pXVar28 = (X509 *)((uint)pXVar28 & 0x100);
    }
    if (!bVar29) {
      ppXVar25[6] = pXVar28;
    }
  }
  return local_44;
}

