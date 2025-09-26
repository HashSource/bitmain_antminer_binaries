
int X509_policy_check(X509_POLICY_TREE **ptree,int *pexplicit_policy,stack_st_X509 *certs,
                     stack_st_ASN1_OBJECT *policy_oids,uint flags)

{
  uint uVar1;
  X509 *x;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint *puVar8;
  void *pvVar9;
  ASN1_OBJECT *pAVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  X509_POLICY_TREE *pXVar20;
  uint uVar21;
  int iVar22;
  bool bVar23;
  undefined8 uVar24;
  X509_POLICY_TREE *local_54;
  int local_50;
  uint local_44;
  undefined4 local_2c [2];
  
  *ptree = (X509_POLICY_TREE *)0x0;
  *pexplicit_policy = 0;
  local_2c[0] = 0;
  uVar1 = OPENSSL_sk_num(certs);
  uVar14 = uVar1;
  if ((flags & 0x100) != 0) {
    uVar14 = 0;
  }
  uVar15 = uVar1;
  if ((flags & 0x200) != 0) {
    uVar15 = 0;
  }
  uVar21 = uVar1;
  if ((flags & 0x400) != 0) {
    uVar21 = 0;
  }
  if (uVar1 == 1) {
LAB_00178bcc:
    local_54 = (X509_POLICY_TREE *)0x0;
    goto LAB_00178bd0;
  }
  iVar19 = uVar1 - 2;
  iVar16 = iVar19;
  if (iVar19 < 0) {
    uVar17 = 1;
  }
  else {
    do {
      x = (X509 *)OPENSSL_sk_value(certs,iVar16);
      iVar16 = iVar16 + -1;
      X509_check_purpose(x,-1,0);
      iVar2 = policy_cache_set(x);
      if (iVar2 == 0) {
        return 0;
      }
    } while (iVar16 != -1);
    uVar17 = 1;
    uVar13 = uVar14;
    iVar16 = iVar19;
    do {
      if (((int)uVar13 < 1) && ((int)(uVar17 << 0x1e) < 0)) {
        if (uVar13 != 0) goto LAB_00178bcc;
        uVar17 = 6;
        local_44 = 4;
        local_54 = (X509_POLICY_TREE *)0x0;
        goto LAB_00178c82;
      }
      uVar7 = OPENSSL_sk_value(certs,iVar16);
      uVar3 = X509_get_extension_flags();
      if ((uVar3 & 0x800) != 0) {
        return -1;
      }
      iVar2 = policy_cache_set(uVar7);
      if (((uVar17 & 1) != 0) && (*(int *)(iVar2 + 4) == 0)) {
        uVar17 = 2;
      }
      uVar14 = uVar13;
      if (0 < (int)uVar13) {
        if (-1 < (int)(uVar3 << 0x1a)) {
          uVar13 = uVar13 - 1;
        }
        uVar14 = *(uint *)(iVar2 + 0xc);
        uVar3 = ~uVar14 >> 0x1f;
        if ((int)uVar13 <= (int)uVar14) {
          uVar3 = 0;
        }
        if (uVar3 == 0) {
          uVar14 = uVar13;
        }
      }
      bVar23 = iVar16 != 0;
      iVar16 = iVar16 + -1;
      uVar13 = uVar14;
    } while (bVar23);
  }
  if (uVar14 == 0) {
    uVar14 = uVar17 & 1;
    uVar17 = uVar17 | 4;
    if (uVar14 != 0) goto LAB_00178d3a;
    local_44 = 4;
    local_54 = (X509_POLICY_TREE *)0x0;
LAB_00178c82:
    *pexplicit_policy = 1;
    if ((int)(uVar17 << 0x1e) < 0) {
      return -2;
    }
  }
  else {
    if ((uVar17 & 1) == 0) {
      local_54 = (X509_POLICY_TREE *)0x0;
    }
    else {
LAB_00178d3a:
      local_54 = (X509_POLICY_TREE *)CRYPTO_zalloc(0x18,"crypto/x509v3/pcy_tree.c",0xa6);
      if (local_54 == (X509_POLICY_TREE *)0x0) {
        ERR_put_error(0x22,0xac,0x41,"crypto/x509v3/pcy_tree.c",0xa7);
        return 0;
      }
      iVar16 = CRYPTO_zalloc(uVar1 << 4,"crypto/x509v3/pcy_tree.c",0xb2);
      *(int *)local_54 = iVar16;
      if (iVar16 == 0) {
        CRYPTO_free(local_54);
        ERR_put_error(0x22,0xac,0x41,"crypto/x509v3/pcy_tree.c",0xb4);
        return 0;
      }
      *(uint *)(local_54 + 4) = uVar1;
      pAVar10 = OBJ_nid2obj(0x2ea);
      puVar8 = (uint *)policy_data_new(0,pAVar10);
      if (puVar8 == (uint *)0x0) goto LAB_00178d1e;
      iVar2 = level_add_node(iVar16,puVar8,0,local_54);
      if (iVar2 == 0) {
LAB_001790cc:
        policy_data_free(puVar8);
        goto LAB_00178d1e;
      }
      if (-1 < iVar19) {
        iVar16 = iVar16 + 0x4c;
        do {
          uVar7 = OPENSSL_sk_value(certs,iVar19);
          uVar14 = X509_get_extension_flags();
          piVar4 = (int *)policy_cache_set(uVar7);
          X509_up_ref(uVar7);
          *(undefined4 *)(iVar16 + -0x3c) = uVar7;
          if (*piVar4 == 0) {
            HintPreloadData(iVar16);
            *(uint *)(iVar16 + -0x30) = *(uint *)(iVar16 + -0x30) | 0x200;
          }
          if (uVar15 == 0) {
            uVar1 = uVar15;
            if (iVar19 == 0 || (uVar14 & 0x20) == 0) {
              *(uint *)(iVar16 + -0x30) = *(uint *)(iVar16 + -0x30) | 0x200;
              goto LAB_001792f8;
            }
            if (uVar21 != 0) goto LAB_00179302;
LAB_00178df2:
            *(uint *)(iVar16 + -0x30) = *(uint *)(iVar16 + -0x30) | 0x400;
            uVar21 = 0;
          }
          else {
            if ((uVar14 & 0x20) == 0) {
              uVar15 = uVar15 - 1;
            }
            uVar1 = piVar4[2];
            if ((int)uVar1 < 0 || (int)uVar15 <= (int)uVar1) {
              uVar1 = uVar15;
            }
LAB_001792f8:
            if (uVar21 == 0) goto LAB_00178df2;
            if ((uVar14 & 0x20) == 0) {
              uVar21 = uVar21 - 1;
            }
LAB_00179302:
            uVar14 = piVar4[4];
            if (-1 < (int)uVar14 && (int)uVar14 < (int)uVar21) {
              uVar21 = uVar14;
            }
          }
          iVar19 = iVar19 + -1;
          iVar16 = iVar16 + 0x10;
          uVar15 = uVar1;
        } while (iVar19 != -1);
      }
      local_44 = uVar17 & 4;
      if (local_44 != 0) goto LAB_00178c82;
    }
    local_44 = uVar17 & 2;
    if (local_44 != 0) {
LAB_00178bd0:
      X509_policy_tree_free(local_54);
      return 1;
    }
  }
  iVar19 = *(int *)(local_54 + 4);
  iVar16 = *(int *)local_54;
  if (1 < iVar19) {
    local_50 = 1;
    iVar2 = iVar16;
    do {
      iVar22 = iVar2 + 0x10;
      piVar4 = (int *)policy_cache_set(*(undefined4 *)(iVar2 + 0x10));
      iVar19 = 0;
      uVar24 = OPENSSL_sk_num(piVar4[1]);
      iVar16 = (int)((ulonglong)uVar24 >> 0x20);
      if (0 < (int)uVar24) {
        do {
          bVar23 = false;
          iVar5 = OPENSSL_sk_value(piVar4[1],iVar19);
          iVar16 = 0;
          while( true ) {
            iVar6 = OPENSSL_sk_num(*(undefined4 *)(iVar2 + 4));
            iVar18 = iVar16 + 1;
            if (iVar6 <= iVar16) break;
            uVar7 = OPENSSL_sk_value(*(undefined4 *)(iVar2 + 4));
            iVar6 = policy_node_match(iVar2,uVar7,*(undefined4 *)(iVar5 + 4));
            iVar16 = iVar18;
            if (iVar6 != 0) {
              bVar23 = true;
              iVar6 = level_add_node(iVar22,iVar5,uVar7,0);
              if (iVar6 == 0) goto LAB_00178d1e;
            }
          }
          if ((!bVar23) && (*(int *)(iVar2 + 8) != 0)) {
            uVar24 = level_add_node(iVar22,iVar5,*(int *)(iVar2 + 8),0);
            iVar16 = (int)((ulonglong)uVar24 >> 0x20);
            if ((int)uVar24 == 0) goto LAB_00178d1e;
          }
          iVar19 = iVar19 + 1;
          uVar24 = OPENSSL_sk_num(piVar4[1],iVar16);
          iVar16 = (int)((ulonglong)uVar24 >> 0x20);
        } while (iVar19 < (int)uVar24);
      }
      uVar14 = *(uint *)(iVar2 + 0x1c);
      HintPreloadData(iVar2 + 0x2c);
      if ((uVar14 & 0x200) == 0) {
        for (iVar19 = 0; iVar16 = OPENSSL_sk_num(*(undefined4 *)(iVar2 + 4),iVar16), iVar19 < iVar16
            ; iVar19 = iVar19 + 1) {
          uVar24 = OPENSSL_sk_value(*(undefined4 *)(iVar2 + 4),iVar19);
          iVar16 = (int)((ulonglong)uVar24 >> 0x20);
          puVar11 = (undefined4 *)uVar24;
          if (((*(uint *)(iVar2 + 0xc) & 0x400) == 0) && (*(int *)*puVar11 << 0x1f < 0)) {
            iVar6 = ((int *)*puVar11)[3];
            iVar18 = puVar11[2];
            uVar24 = OPENSSL_sk_num(iVar6);
            iVar16 = (int)((ulonglong)uVar24 >> 0x20);
            iVar5 = 0;
            if (iVar18 != (int)uVar24) {
              while (iVar16 = iVar5, iVar5 = OPENSSL_sk_num(iVar6), iVar16 < iVar5) {
                uVar14 = OPENSSL_sk_value(iVar6);
                iVar5 = level_find_node(iVar22,puVar11,uVar14);
                if (iVar5 == 0) {
                  if (uVar14 == 0) {
                    uVar14 = ((uint *)*puVar11)[1];
                  }
                  puVar8 = (uint *)policy_data_new(0,uVar14,*(uint *)*puVar11 & 0x10);
                  if (puVar8 == (uint *)0x0) goto LAB_00178d1e;
                  puVar8[2] = *(uint *)(*piVar4 + 8);
                  *puVar8 = *puVar8 | 4;
                  iVar5 = level_add_node(iVar22,puVar8,puVar11,local_54);
                  if (iVar5 == 0) goto LAB_001790cc;
                }
                iVar5 = iVar16 + 1;
              }
            }
          }
          else if (puVar11[2] == 0) {
            puVar8 = (uint *)policy_data_new(0,((uint *)*puVar11)[1],*(uint *)*puVar11 & 0x10);
            if (puVar8 == (uint *)0x0) goto LAB_00178d1e;
            uVar14 = *(uint *)(*piVar4 + 8);
            *puVar8 = *puVar8 | 4;
            puVar8[2] = uVar14;
            uVar24 = level_add_node(iVar22,puVar8,puVar11,local_54);
            iVar16 = (int)((ulonglong)uVar24 >> 0x20);
            if ((int)uVar24 == 0) {
              policy_data_free(puVar8);
              X509_policy_tree_free(local_54);
              return 0;
            }
          }
        }
        HintPreloadData(iVar2 + 0x18);
        if ((*(int *)(iVar2 + 8) != 0) &&
           (iVar16 = level_add_node(iVar22,*piVar4,*(int *)(iVar2 + 8),0), iVar16 == 0))
        goto LAB_00178d1e;
        uVar14 = *(uint *)(iVar2 + 0x1c);
      }
      iVar16 = iVar22;
      if ((int)(uVar14 << 0x15) < 0) {
        uVar7 = *(undefined4 *)(iVar2 + 0x14);
        iVar19 = OPENSSL_sk_num(uVar7);
        iVar19 = iVar19 + -1;
        if (-1 < iVar19) {
          do {
            puVar11 = (undefined4 *)OPENSSL_sk_value(uVar7,iVar19);
            if ((*(uint *)*puVar11 & 3) != 0) {
              *(int *)(puVar11[1] + 8) = *(int *)(puVar11[1] + 8) + -1;
              CRYPTO_free(puVar11);
              OPENSSL_sk_delete(uVar7,iVar19);
            }
            bVar23 = iVar19 != 0;
            iVar19 = iVar19 + -1;
          } while (bVar23);
        }
      }
      do {
        iVar2 = iVar16;
        iVar16 = iVar2 + -0x10;
        uVar7 = *(undefined4 *)(iVar2 + -0xc);
        iVar19 = OPENSSL_sk_num(uVar7);
        iVar19 = iVar19 + -1;
        if (-1 < iVar19) {
          do {
            while (pvVar9 = (void *)OPENSSL_sk_value(uVar7,iVar19), *(int *)((int)pvVar9 + 8) == 0)
            {
              *(int *)(*(int *)((int)pvVar9 + 4) + 8) = *(int *)(*(int *)((int)pvVar9 + 4) + 8) + -1
              ;
              CRYPTO_free(pvVar9);
              OPENSSL_sk_delete(uVar7,iVar19);
              bVar23 = iVar19 == 0;
              iVar19 = iVar19 + -1;
              if (bVar23) goto LAB_00178f66;
            }
            bVar23 = iVar19 != 0;
            iVar19 = iVar19 + -1;
          } while (bVar23);
        }
LAB_00178f66:
        pvVar9 = *(void **)(iVar2 + -8);
        HintPreloadData(iVar2 + -0x38);
        if ((pvVar9 != (void *)0x0) && (*(int *)((int)pvVar9 + 8) == 0)) {
          iVar19 = *(int *)((int)pvVar9 + 4);
          if (iVar19 != 0) {
            *(int *)(iVar19 + 8) = *(int *)(iVar19 + 8) + -1;
          }
          CRYPTO_free(pvVar9);
          *(undefined4 *)(iVar2 + -8) = 0;
        }
      } while (iVar16 != *(int *)local_54);
      if (*(int *)(iVar2 + -8) == 0) {
        X509_policy_tree_free(local_54);
        if (local_44 != 0) {
          return -2;
        }
        return 1;
      }
      iVar19 = *(int *)(local_54 + 4);
      local_50 = local_50 + 1;
      iVar2 = iVar22;
    } while (local_50 < iVar19);
  }
  iVar2 = *(int *)(iVar16 + iVar19 * 0x10 + -8);
  if (iVar2 == 0) {
    pXVar20 = local_54 + 0xc;
    if ((1 < iVar19) && (iVar19 = *(int *)(iVar16 + 8), iVar19 != 0)) goto LAB_00178ff6;
LAB_00179136:
    if (pXVar20 != (X509_POLICY_TREE *)local_2c) {
      iVar16 = 1;
      local_2c[0] = *(undefined4 *)(local_54 + 0xc);
      goto LAB_00179144;
    }
  }
  else {
    iVar16 = *(int *)(local_54 + 0xc);
    if (iVar16 == 0) {
      iVar16 = policy_node_cmp_new();
      *(int *)(local_54 + 0xc) = iVar16;
      if (iVar16 == 0) goto LAB_00178d1e;
    }
    iVar16 = OPENSSL_sk_find(iVar16,iVar2);
    if ((iVar16 < 0) &&
       (iVar16 = OPENSSL_sk_push(*(undefined4 *)(local_54 + 0xc),iVar2), iVar16 == 0)) {
LAB_00178d1e:
      X509_policy_tree_free(local_54);
      return 0;
    }
    iVar16 = *(int *)local_54;
    if ((1 < *(int *)(local_54 + 4)) && (iVar19 = *(int *)(iVar16 + 8), iVar19 != 0)) {
      pXVar20 = (X509_POLICY_TREE *)local_2c;
LAB_00178ff6:
      iVar2 = 1;
      iVar16 = iVar16 + 0x48;
      do {
        iVar22 = 0;
LAB_00178ffe:
        iVar5 = OPENSSL_sk_num(*(undefined4 *)(iVar16 + -0x34));
        iVar6 = iVar22 + 1;
        if (iVar22 < iVar5) {
          iVar5 = OPENSSL_sk_value(*(undefined4 *)(iVar16 + -0x34),iVar22);
          iVar22 = iVar6;
          if (iVar19 == *(int *)(iVar5 + 4)) {
            iVar6 = *(int *)pXVar20;
            if (iVar6 == 0) {
              iVar6 = policy_node_cmp_new();
              *(int *)pXVar20 = iVar6;
              if (iVar6 != 0) goto LAB_0017902a;
            }
            else {
LAB_0017902a:
              iVar6 = OPENSSL_sk_find(iVar6,iVar5);
              if ((-1 < iVar6) || (iVar5 = OPENSSL_sk_push(*(int *)pXVar20,iVar5), iVar5 != 0))
              goto LAB_00178ffe;
            }
            if (pXVar20 == (X509_POLICY_TREE *)local_2c) {
              OPENSSL_sk_free(local_2c[0]);
            }
            goto LAB_00178d1e;
          }
          goto LAB_00178ffe;
        }
        iVar2 = iVar2 + 1;
        if (*(int *)(local_54 + 4) <= iVar2) break;
        HintPreloadData(iVar16);
        iVar19 = *(int *)(iVar16 + -0x30);
        iVar16 = iVar16 + 0x10;
      } while (iVar19 != 0);
      goto LAB_00179136;
    }
  }
  iVar16 = 2;
LAB_00179144:
  uVar7 = local_2c[0];
  iVar19 = OPENSSL_sk_num(policy_oids);
  if (0 < iVar19) {
    piVar4 = *(int **)(*(int *)local_54 + *(int *)(local_54 + 4) * 0x10 + -8);
    iVar19 = 0;
    do {
      iVar2 = OPENSSL_sk_num(policy_oids);
      if (iVar2 <= iVar19) {
        iVar2 = 0;
        goto LAB_001791a8;
      }
      pAVar10 = (ASN1_OBJECT *)OPENSSL_sk_value(policy_oids,iVar19);
      iVar2 = OBJ_obj2nid(pAVar10);
      iVar19 = iVar19 + 1;
    } while (iVar2 != 0x2ea);
    *(uint *)(local_54 + 0x14) = *(uint *)(local_54 + 0x14) | 2;
  }
LAB_00179282:
  if (iVar16 == 2) {
    OPENSSL_sk_free(uVar7);
  }
  *ptree = local_54;
  if (local_44 != 0) {
    X509_policy_tree_get0_user_policies(local_54);
    iVar16 = OPENSSL_sk_num();
    if (iVar16 < 1) {
      return -2;
    }
    return 1;
  }
  return 1;
LAB_001791a8:
  do {
    do {
      iVar19 = OPENSSL_sk_num(policy_oids,iVar19);
      iVar22 = iVar2 + 1;
      if (iVar19 <= iVar2) goto LAB_00179282;
      iVar19 = OPENSSL_sk_value(policy_oids,iVar2);
      iVar5 = tree_find_sk(uVar7,iVar19);
      iVar2 = iVar22;
      if (iVar5 != 0) {
        iVar19 = *(int *)(local_54 + 0x10);
        if (iVar19 != 0) goto LAB_0017919e;
LAB_0017920a:
        iVar19 = OPENSSL_sk_new_null();
        *(int *)(local_54 + 0x10) = iVar19;
        if (iVar19 == 0) goto LAB_00179282;
        uVar24 = OPENSSL_sk_push(iVar19,iVar5);
        iVar19 = (int)((ulonglong)uVar24 >> 0x20);
        if ((int)uVar24 == 0) goto LAB_00179220;
        goto LAB_001791a8;
      }
    } while (piVar4 == (int *)0x0);
    puVar11 = (undefined4 *)policy_data_new(0,iVar19,*(uint *)*piVar4 & 0x10);
    if (puVar11 == (undefined4 *)0x0) break;
    uVar12 = *(undefined4 *)(*piVar4 + 8);
    *puVar11 = 0xc;
    puVar11[2] = uVar12;
    iVar5 = level_add_node(0,puVar11,piVar4[1],local_54);
    iVar19 = *(int *)(local_54 + 0x10);
    if (iVar19 == 0) goto LAB_0017920a;
LAB_0017919e:
    uVar24 = OPENSSL_sk_push(iVar19,iVar5);
    iVar19 = (int)((ulonglong)uVar24 >> 0x20);
  } while ((int)uVar24 != 0);
LAB_00179220:
  if (iVar16 == 2) {
    OPENSSL_sk_free(uVar7);
  }
  goto LAB_00178d1e;
}

