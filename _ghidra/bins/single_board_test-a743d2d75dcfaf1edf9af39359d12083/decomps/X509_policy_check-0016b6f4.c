
int X509_policy_check(X509_POLICY_TREE **ptree,int *pexplicit_policy,stack_st_X509 *certs,
                     stack_st_ASN1_OBJECT *policy_oids,uint flags)

{
  int iVar1;
  X509 *x;
  int iVar2;
  _STACK *p_Var3;
  X509_POLICY_TREE *tree;
  void *pvVar4;
  ASN1_OBJECT *pAVar5;
  int *piVar6;
  void *pvVar7;
  int *piVar8;
  uint *puVar9;
  _STACK *st;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  X509_POLICY_TREE *pXVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  bool bVar18;
  int local_60;
  int local_5c;
  int local_50;
  _STACK *local_2c [2];
  
  iVar11 = 0;
  *ptree = (X509_POLICY_TREE *)0x0;
  *pexplicit_policy = 0;
  local_2c[0] = (_STACK *)0x0;
  iVar1 = sk_num(&certs->stack);
  if (-1 < (int)(flags << 0x17)) {
    iVar11 = iVar1 + 1;
  }
  if ((int)(flags << 0x16) < 0) {
    local_60 = 0;
  }
  else {
    local_60 = iVar1 + 1;
  }
  if ((int)(flags << 0x15) < 0) {
    iVar16 = 0;
  }
  else {
    iVar16 = iVar1 + 1;
  }
  if (iVar1 == 1) {
    return 1;
  }
  iVar14 = iVar1 + -2;
  if (-1 < iVar14) {
    iVar17 = 1;
    iVar15 = iVar14;
    do {
      x = (X509 *)sk_value(&certs->stack,iVar15);
      X509_check_purpose(x,-1,-1);
      iVar2 = policy_cache_set(x);
      if (iVar2 == 0) {
        return 0;
      }
      if ((int)(x->ex_flags << 0x14) < 0) {
        iVar17 = -1;
      }
      else if ((iVar17 == 1) && (*(int *)(iVar2 + 4) == 0)) {
        iVar17 = 2;
      }
      if (0 < iVar11) {
        iVar2 = *(int *)(iVar2 + 0xc);
        if (-1 < (int)(x->ex_flags << 0x1a)) {
          iVar11 = iVar11 + -1;
        }
        if ((iVar2 != -1) && (iVar2 <= iVar11)) {
          iVar11 = iVar2;
        }
      }
      bVar18 = iVar15 != 0;
      iVar15 = iVar15 + -1;
    } while (bVar18);
    if (iVar17 != 1) {
      if (iVar11 == 0 && iVar17 == 2) {
        *pexplicit_policy = 1;
        return -2;
      }
      if (iVar17 != 2) {
        if (iVar17 == 0) {
          return 0;
        }
        return iVar15;
      }
      return 1;
    }
  }
  tree = (X509_POLICY_TREE *)CRYPTO_malloc(0x18,"pcy_tree.c",0xdf);
  if (tree == (X509_POLICY_TREE *)0x0) {
    return 0;
  }
  *(undefined4 *)(tree + 0x14) = 0;
  pvVar4 = CRYPTO_malloc(iVar1 << 4,"pcy_tree.c",0xe5);
  *(undefined4 *)(tree + 4) = 0;
  *(undefined4 *)(tree + 8) = 0;
  *(undefined4 *)(tree + 0xc) = 0;
  *(undefined4 *)(tree + 0x10) = 0;
  *(void **)tree = pvVar4;
  if (pvVar4 == (void *)0x0) {
    CRYPTO_free(tree);
    return 0;
  }
  memset(pvVar4,0,iVar1 << 4);
  *(int *)(tree + 4) = iVar1;
  puVar12 = *(undefined4 **)tree;
  pAVar5 = OBJ_nid2obj(0x2ea);
  iVar1 = policy_data_new(0,pAVar5,0);
  if ((iVar1 == 0) || (iVar1 = level_add_node(puVar12,iVar1,0,tree), iVar1 == 0)) {
    sk_free(*(_STACK **)(tree + 0xc));
    sk_pop_free(*(_STACK **)(tree + 0x10),(func *)0x16b665);
    if (0 < *(int *)(tree + 4)) {
      iVar11 = 0;
      puVar12 = *(undefined4 **)tree;
      do {
        iVar11 = iVar11 + 1;
        HintPreloadData(puVar12 + 0x15);
        if ((X509 *)*puVar12 != (X509 *)0x0) {
          X509_free((X509 *)*puVar12);
        }
        if ((_STACK *)puVar12[1] != (_STACK *)0x0) {
          sk_pop_free((_STACK *)puVar12[1],policy_node_free);
        }
        if ((void *)puVar12[2] != (void *)0x0) {
          policy_node_free((void *)puVar12[2]);
        }
        puVar12 = puVar12 + 4;
      } while (iVar11 < *(int *)(tree + 4));
    }
    p_Var3 = *(_STACK **)(tree + 8);
    goto joined_r0x0016bfda;
  }
  if (-1 < iVar14) {
    do {
      pvVar4 = sk_value(&certs->stack,iVar14);
      piVar6 = (int *)policy_cache_set();
      CRYPTO_add_lock((int *)((int)pvVar4 + 0x10),1,3,"pcy_tree.c",0x101);
      iVar1 = *piVar6;
      puVar12[4] = pvVar4;
      if (iVar1 == 0) {
        HintPreloadData(puVar12 + 0x13);
        puVar12[7] = puVar12[7] | 0x200;
      }
      iVar1 = *(int *)((int)pvVar4 + 0x28);
      if (local_60 == 0) {
        if ((-1 < iVar1 << 0x1a) || (iVar14 == 0)) {
          puVar12[7] = puVar12[7] | 0x200;
        }
LAB_0016ba08:
        if (iVar16 == 0) goto LAB_0016ba0e;
LAB_0016baee:
        iVar15 = piVar6[4];
        if (-1 < iVar1 << 0x1a) {
          iVar16 = iVar16 + -1;
        }
        if ((-1 < iVar15) && (iVar15 <= iVar16)) {
          iVar16 = iVar15;
        }
      }
      else {
        iVar15 = piVar6[2];
        if (-1 < iVar1 << 0x1a) {
          local_60 = local_60 + -1;
        }
        if (iVar15 < 0) goto LAB_0016ba08;
        if (iVar15 <= local_60) {
          local_60 = iVar15;
        }
        if (iVar16 != 0) goto LAB_0016baee;
LAB_0016ba0e:
        puVar12[7] = puVar12[7] | 0x400;
      }
      bVar18 = iVar14 != 0;
      iVar14 = iVar14 + -1;
      puVar12 = puVar12 + 4;
    } while (bVar18);
  }
  if (iVar11 == 0) {
    *pexplicit_policy = 1;
  }
  else if (tree == (X509_POLICY_TREE *)0x0) {
    return 1;
  }
  iVar1 = *(int *)(tree + 4);
  iVar11 = *(int *)tree;
  if (1 < iVar1) {
    local_5c = iVar11 + -0x10;
    local_50 = 1;
    iVar16 = iVar11;
    do {
      iVar14 = iVar16 + 0x10;
      piVar6 = (int *)policy_cache_set(*(undefined4 *)(iVar16 + 0x10));
      iVar1 = 0;
      iVar11 = sk_num((_STACK *)piVar6[1]);
      if (0 < iVar11) {
        do {
          bVar18 = false;
          pvVar4 = sk_value((_STACK *)piVar6[1],iVar1);
          iVar11 = 0;
          while( true ) {
            iVar15 = sk_num(*(_STACK **)(local_5c + 0x14));
            iVar17 = iVar11 + 1;
            if (iVar15 <= iVar11) break;
            pvVar7 = sk_value(*(_STACK **)(local_5c + 0x14),iVar11);
            iVar15 = policy_node_match(iVar16,pvVar7,*(undefined4 *)((int)pvVar4 + 4));
            iVar11 = iVar17;
            if (iVar15 != 0) {
              iVar15 = level_add_node(iVar14,pvVar4,pvVar7,0);
              if (iVar15 == 0) goto LAB_0016b83a;
              bVar18 = true;
            }
          }
          if (((!bVar18) && (*(int *)(local_5c + 0x18) != 0)) &&
             (iVar11 = level_add_node(iVar14,pvVar4,*(int *)(local_5c + 0x18),0), iVar11 == 0))
          goto LAB_0016b83a;
          iVar1 = iVar1 + 1;
          iVar11 = sk_num((_STACK *)piVar6[1]);
        } while (iVar1 < iVar11);
      }
      uVar10 = *(uint *)(iVar16 + 0x1c);
      HintPreloadData(iVar16 + 0x2c);
      if ((uVar10 & 0x200) == 0) {
        for (iVar11 = 0; iVar1 = sk_num(*(_STACK **)(local_5c + 0x14)), iVar11 < iVar1;
            iVar11 = iVar11 + 1) {
          piVar8 = (int *)sk_value(*(_STACK **)(local_5c + 0x14),iVar11);
          if (((*(uint *)(iVar16 + 0xc) & 0x400) == 0) && (*(int *)*piVar8 << 0x1f < 0)) {
            p_Var3 = (_STACK *)((int *)*piVar8)[3];
            iVar15 = piVar8[2];
            iVar1 = sk_num(p_Var3);
            if (iVar15 != iVar1) {
              for (iVar1 = 0; iVar15 = sk_num(p_Var3), iVar1 < iVar15; iVar1 = iVar1 + 1) {
                pvVar4 = sk_value(p_Var3,iVar1);
                iVar15 = level_find_node(iVar14,piVar8,pvVar4);
                if (iVar15 == 0) {
                  if (pvVar4 == (void *)0x0) {
                    pvVar4 = (void *)((uint *)*piVar8)[1];
                  }
                  puVar9 = (uint *)policy_data_new(0,pvVar4,*(uint *)*piVar8 & 0x10);
                  if (puVar9 == (uint *)0x0) goto LAB_0016b83a;
                  puVar9[2] = *(uint *)(*piVar6 + 8);
                  *puVar9 = *puVar9 | 4;
                  iVar15 = level_add_node(iVar14,puVar9,piVar8,tree);
                  if (iVar15 == 0) {
                    policy_data_free(puVar9);
                    goto LAB_0016b83a;
                  }
                }
              }
            }
          }
          else if (piVar8[2] == 0) {
            puVar9 = (uint *)policy_data_new(0,((uint *)*piVar8)[1],*(uint *)*piVar8 & 0x10);
            if (puVar9 == (uint *)0x0) goto LAB_0016b83a;
            iVar1 = *piVar6;
            *puVar9 = *puVar9 | 4;
            puVar9[2] = *(uint *)(iVar1 + 8);
            iVar1 = level_add_node(iVar14,puVar9,piVar8,tree);
            if (iVar1 == 0) {
              policy_data_free(puVar9);
              goto LAB_0016b83a;
            }
          }
        }
        HintPreloadData(iVar16 + 0x18);
        if ((*(int *)(local_5c + 0x18) != 0) &&
           (iVar11 = level_add_node(iVar14,*piVar6,*(int *)(local_5c + 0x18),0), iVar11 == 0))
        goto LAB_0016b83a;
        uVar10 = *(uint *)(iVar16 + 0x1c);
      }
      p_Var3 = *(_STACK **)(iVar16 + 0x14);
      iVar1 = iVar14;
      if ((int)(uVar10 << 0x15) < 0) {
        iVar11 = sk_num(p_Var3);
        iVar11 = iVar11 + -1;
        if (-1 < iVar11) {
          do {
            puVar12 = (undefined4 *)sk_value(p_Var3,iVar11);
            if ((*(uint *)*puVar12 & 3) != 0) {
              *(int *)(puVar12[1] + 8) = *(int *)(puVar12[1] + 8) + -1;
              CRYPTO_free(puVar12);
              sk_delete(p_Var3,iVar11);
            }
            bVar18 = iVar11 != 0;
            iVar11 = iVar11 + -1;
          } while (bVar18);
        }
      }
      do {
        iVar16 = iVar1 + -0x10;
        p_Var3 = *(_STACK **)(iVar1 + -0xc);
        iVar11 = sk_num(p_Var3);
        iVar11 = iVar11 + -1;
        if (-1 < iVar11) {
          do {
            while (pvVar4 = sk_value(p_Var3,iVar11), *(int *)((int)pvVar4 + 8) == 0) {
              *(int *)(*(int *)((int)pvVar4 + 4) + 8) = *(int *)(*(int *)((int)pvVar4 + 4) + 8) + -1
              ;
              CRYPTO_free(pvVar4);
              sk_delete(p_Var3,iVar11);
              bVar18 = iVar11 == 0;
              iVar11 = iVar11 + -1;
              if (bVar18) goto LAB_0016bc76;
            }
            bVar18 = iVar11 != 0;
            iVar11 = iVar11 + -1;
          } while (bVar18);
        }
LAB_0016bc76:
        pvVar4 = *(void **)(iVar1 + -8);
        HintPreloadData(iVar1 + -0x38);
        if ((pvVar4 != (void *)0x0) && (*(int *)((int)pvVar4 + 8) == 0)) {
          iVar11 = *(int *)((int)pvVar4 + 4);
          if (iVar11 != 0) {
            *(int *)(iVar11 + 8) = *(int *)(iVar11 + 8) + -1;
          }
          CRYPTO_free(pvVar4);
          *(undefined4 *)(iVar1 + -8) = 0;
        }
        iVar11 = *(int *)tree;
        iVar1 = iVar16;
      } while (iVar16 != iVar11);
      if (*(int *)(iVar11 + 8) == 0) {
        sk_free(*(_STACK **)(tree + 0xc));
        sk_pop_free(*(_STACK **)(tree + 0x10),(func *)0x16b665);
        if (0 < *(int *)(tree + 4)) {
          iVar11 = 0;
          puVar12 = *(undefined4 **)tree;
          do {
            iVar11 = iVar11 + 1;
            HintPreloadData(puVar12 + 0x15);
            if ((X509 *)*puVar12 != (X509 *)0x0) {
              X509_free((X509 *)*puVar12);
            }
            if ((_STACK *)puVar12[1] != (_STACK *)0x0) {
              sk_pop_free((_STACK *)puVar12[1],policy_node_free);
            }
            if ((void *)puVar12[2] != (void *)0x0) {
              policy_node_free((void *)puVar12[2]);
            }
            puVar12 = puVar12 + 4;
          } while (iVar11 < *(int *)(tree + 4));
        }
        if (*(_STACK **)(tree + 8) != (_STACK *)0x0) {
          sk_pop_free(*(_STACK **)(tree + 8),policy_data_free);
        }
        CRYPTO_free(*(void **)tree);
        CRYPTO_free(tree);
        if (*pexplicit_policy == 0) {
          return 1;
        }
        return -2;
      }
      iVar1 = *(int *)(tree + 4);
      local_50 = local_50 + 1;
      local_5c = local_5c + 0x10;
      iVar16 = iVar14;
    } while (local_50 < iVar1);
  }
  pvVar4 = *(void **)(iVar11 + iVar1 * 0x10 + -8);
  if (pvVar4 == (void *)0x0) {
    pXVar13 = tree + 0xc;
    goto LAB_0016bcf8;
  }
  if (*(_STACK **)(tree + 0xc) != (_STACK *)0x0) {
    iVar11 = sk_find(*(_STACK **)(tree + 0xc),pvVar4);
    if (iVar11 == -1) {
      p_Var3 = *(_STACK **)(tree + 0xc);
LAB_0016bff2:
      iVar11 = sk_push(p_Var3,pvVar4);
      if (iVar11 == 0) goto LAB_0016b83a;
    }
    iVar11 = *(int *)tree;
    pXVar13 = (X509_POLICY_TREE *)local_2c;
    iVar1 = *(int *)(tree + 4);
LAB_0016bcf8:
    if ((1 < iVar1) && (iVar1 = *(int *)(iVar11 + 8), iVar1 != 0)) {
      iVar16 = 1;
LAB_0016bd10:
      iVar14 = 0;
LAB_0016bd16:
      do {
        iVar15 = sk_num(*(_STACK **)(iVar11 + 0x14));
        iVar17 = iVar14 + 1;
        if (iVar15 <= iVar14) goto LAB_0016be26;
        pvVar4 = sk_value(*(_STACK **)(iVar11 + 0x14),iVar14);
        iVar14 = iVar17;
        if (iVar1 == *(int *)((int)pvVar4 + 4)) {
          if (*(_STACK **)pXVar13 == (_STACK *)0x0) {
            p_Var3 = (_STACK *)policy_node_cmp_new();
            *(_STACK **)pXVar13 = p_Var3;
            if (p_Var3 == (_STACK *)0x0) goto LAB_0016b83a;
          }
          else {
            iVar15 = sk_find(*(_STACK **)pXVar13,pvVar4);
            if (iVar15 != -1) goto LAB_0016bd16;
            p_Var3 = *(_STACK **)pXVar13;
          }
          iVar15 = sk_push(p_Var3,pvVar4);
          if (iVar15 == 0) goto LAB_0016b83a;
        }
      } while( true );
    }
LAB_0016be42:
    if (pXVar13 == (X509_POLICY_TREE *)local_2c) {
      iVar11 = 2;
    }
    else {
      iVar11 = 1;
      local_2c[0] = *(_STACK **)(tree + 0xc);
    }
    p_Var3 = local_2c[0];
    iVar1 = sk_num(&policy_oids->stack);
    if (0 < iVar1) {
      piVar6 = *(int **)(*(int *)tree + *(int *)(tree + 4) * 0x10 + -8);
      iVar1 = 0;
      do {
        iVar16 = sk_num(&policy_oids->stack);
        if (iVar16 <= iVar1) {
          iVar1 = 0;
          goto LAB_0016bec6;
        }
        pAVar5 = (ASN1_OBJECT *)sk_value(&policy_oids->stack,iVar1);
        iVar16 = OBJ_obj2nid(pAVar5);
        iVar1 = iVar1 + 1;
      } while (iVar16 != 0x2ea);
      *(uint *)(tree + 0x14) = *(uint *)(tree + 0x14) | 2;
    }
LAB_0016b8ec:
    if (iVar11 == 2) {
      sk_free(p_Var3);
    }
    iVar11 = *pexplicit_policy;
    *ptree = tree;
    if (iVar11 != 0) {
      p_Var3 = &X509_policy_tree_get0_user_policies(tree)->stack;
      iVar11 = sk_num(p_Var3);
      if (iVar11 < 1) {
        return -2;
      }
    }
    return 1;
  }
  p_Var3 = (_STACK *)policy_node_cmp_new();
  *(_STACK **)(tree + 0xc) = p_Var3;
  if (p_Var3 != (_STACK *)0x0) goto LAB_0016bff2;
  goto LAB_0016b83e;
LAB_0016be26:
  iVar16 = iVar16 + 1;
  if (*(int *)(tree + 4) <= iVar16) goto LAB_0016be42;
  iVar1 = *(int *)(iVar11 + 0x18);
  HintPreloadData(iVar11 + 0x48);
  iVar11 = iVar11 + 0x10;
  if (iVar1 == 0) goto LAB_0016be42;
  goto LAB_0016bd10;
  while( true ) {
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      *(_STACK **)(tree + 0x10) = st;
      if (st == (_STACK *)0x0) goto LAB_0016b8ec;
    }
    iVar16 = sk_push(st,pvVar4);
    if (iVar16 == 0) break;
LAB_0016bec6:
    iVar16 = sk_num(&policy_oids->stack);
    iVar14 = iVar1 + 1;
    if (iVar16 <= iVar1) goto LAB_0016b8ec;
    pvVar7 = sk_value(&policy_oids->stack,iVar1);
    pvVar4 = (void *)tree_find_sk(p_Var3,pvVar7);
    iVar1 = iVar14;
    if (pvVar4 == (void *)0x0) {
      if (piVar6 == (int *)0x0) goto LAB_0016bec6;
      puVar12 = (undefined4 *)policy_data_new(0,pvVar7,*(uint *)*piVar6 & 0x10);
      if (puVar12 == (undefined4 *)0x0) break;
      iVar14 = *piVar6;
      iVar16 = piVar6[1];
      *puVar12 = 0xc;
      puVar12[2] = *(undefined4 *)(iVar14 + 8);
      pvVar4 = (void *)level_add_node(0,puVar12,iVar16,tree);
      st = *(_STACK **)(tree + 0x10);
    }
    else {
      st = *(_STACK **)(tree + 0x10);
    }
  }
LAB_0016b83a:
  p_Var3 = *(_STACK **)(tree + 0xc);
LAB_0016b83e:
  sk_free(p_Var3);
  sk_pop_free(*(_STACK **)(tree + 0x10),(func *)0x16b665);
  if (0 < *(int *)(tree + 4)) {
    iVar11 = 0;
    puVar12 = *(undefined4 **)tree;
    do {
      iVar11 = iVar11 + 1;
      HintPreloadData(puVar12 + 0x15);
      if ((X509 *)*puVar12 != (X509 *)0x0) {
        X509_free((X509 *)*puVar12);
      }
      if ((_STACK *)puVar12[1] != (_STACK *)0x0) {
        sk_pop_free((_STACK *)puVar12[1],policy_node_free);
      }
      if ((void *)puVar12[2] != (void *)0x0) {
        policy_node_free((void *)puVar12[2]);
      }
      puVar12 = puVar12 + 4;
    } while (iVar11 < *(int *)(tree + 4));
  }
  p_Var3 = *(_STACK **)(tree + 8);
joined_r0x0016bfda:
  if (p_Var3 != (_STACK *)0x0) {
    sk_pop_free(p_Var3,policy_data_free);
  }
  CRYPTO_free(*(void **)tree);
  CRYPTO_free(tree);
  return 0;
}

