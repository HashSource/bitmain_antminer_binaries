
int X509_policy_check(X509_POLICY_TREE **ptree,int *pexplicit_policy,stack_st_X509 *certs,
                     stack_st_ASN1_OBJECT *policy_oids,uint flags)

{
  void *pvVar1;
  X509 *x;
  int iVar2;
  _STACK *p_Var3;
  void **tree;
  void *pvVar4;
  ASN1_OBJECT *pAVar5;
  int *piVar6;
  uint **ppuVar7;
  uint *puVar8;
  undefined4 *puVar9;
  _STACK *st;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  X509 **ppXVar13;
  void **ppvVar14;
  _STACK **pp_Var15;
  int iVar16;
  int iVar17;
  int iVar18;
  void *pvVar19;
  int iVar20;
  void *pvVar21;
  bool bVar22;
  int local_60;
  int local_5c;
  int local_50;
  _STACK *local_2c [2];
  
  iVar12 = 0;
  *ptree = (X509_POLICY_TREE *)0x0;
  *pexplicit_policy = 0;
  local_2c[0] = (_STACK *)0x0;
  pvVar1 = (void *)sk_num(&certs->stack);
  if (-1 < (int)(flags << 0x17)) {
    iVar12 = (int)pvVar1 + 1;
  }
  if ((int)(flags << 0x16) < 0) {
    local_60 = 0;
  }
  else {
    local_60 = (int)pvVar1 + 1;
  }
  if ((int)(flags << 0x15) < 0) {
    iVar18 = 0;
  }
  else {
    iVar18 = (int)pvVar1 + 1;
  }
  if (pvVar1 == (void *)0x1) {
    return 1;
  }
  iVar16 = (int)pvVar1 + -2;
  if (-1 < iVar16) {
    iVar20 = 1;
    iVar17 = iVar16;
    do {
      x = (X509 *)sk_value(&certs->stack,iVar17);
      X509_check_purpose(x,-1,-1);
      iVar2 = policy_cache_set(x);
      if (iVar2 == 0) {
        return 0;
      }
      if ((int)(x->ex_flags << 0x14) < 0) {
        iVar20 = -1;
      }
      else if ((iVar20 == 1) && (*(int *)(iVar2 + 4) == 0)) {
        iVar20 = 2;
      }
      if (0 < iVar12) {
        iVar2 = *(int *)(iVar2 + 0xc);
        if (-1 < (int)(x->ex_flags << 0x1a)) {
          iVar12 = iVar12 + -1;
        }
        if ((iVar2 != -1) && (iVar2 <= iVar12)) {
          iVar12 = iVar2;
        }
      }
      bVar22 = iVar17 != 0;
      iVar17 = iVar17 + -1;
    } while (bVar22);
    if (iVar20 != 1) {
      if (iVar12 == 0 && iVar20 == 2) {
        *pexplicit_policy = 1;
        return -2;
      }
      if (iVar20 != 2) {
        if (iVar20 == 0) {
          return 0;
        }
        return iVar17;
      }
      return 1;
    }
  }
  tree = (void **)CRYPTO_malloc(0x18,DAT_000cdd60,0xdf);
  if (tree == (void **)0x0) {
    return 0;
  }
  tree[5] = (void *)0x0;
  pvVar4 = CRYPTO_malloc((int)pvVar1 << 4,DAT_000cdd60,0xe5);
  tree[1] = (void *)0x0;
  tree[2] = (void *)0x0;
  tree[3] = (void *)0x0;
  tree[4] = (void *)0x0;
  *tree = pvVar4;
  if (pvVar4 == (void *)0x0) {
    CRYPTO_free(tree);
    return 0;
  }
  memset(pvVar4,0,(int)pvVar1 << 4);
  tree[1] = pvVar1;
  ppvVar14 = (void **)*tree;
  pAVar5 = OBJ_nid2obj(0x2ea);
  iVar17 = policy_data_new(0,pAVar5,0);
  if ((iVar17 == 0) || (iVar17 = level_add_node(ppvVar14,iVar17,0,tree), iVar17 == 0)) {
    sk_free((_STACK *)tree[3]);
    sk_pop_free((_STACK *)tree[4],DAT_000ce250);
    if (0 < (int)tree[1]) {
      iVar12 = 0;
      ppXVar13 = (X509 **)*tree;
      do {
        iVar12 = iVar12 + 1;
        HintPreloadData(ppXVar13 + 0x15);
        if (*ppXVar13 != (X509 *)0x0) {
          X509_free(*ppXVar13);
        }
        if (ppXVar13[1] != (X509 *)0x0) {
          sk_pop_free((_STACK *)ppXVar13[1],DAT_000ce254);
        }
        if (ppXVar13[2] != (X509 *)0x0) {
          policy_node_free(ppXVar13[2]);
        }
        ppXVar13 = ppXVar13 + 4;
      } while (iVar12 < (int)tree[1]);
    }
    p_Var3 = (_STACK *)tree[2];
    goto joined_r0x000ce21a;
  }
  if (-1 < iVar16) {
    do {
      pvVar1 = sk_value(&certs->stack,iVar16);
      piVar6 = (int *)policy_cache_set();
      CRYPTO_add_lock((int *)((int)pvVar1 + 0x10),1,3,DAT_000cdd60,0x101);
      iVar17 = *piVar6;
      ppvVar14[4] = pvVar1;
      if (iVar17 == 0) {
        HintPreloadData(ppvVar14 + 0x13);
        ppvVar14[7] = (void *)((uint)ppvVar14[7] | 0x200);
      }
      iVar17 = *(int *)((int)pvVar1 + 0x28);
      if (local_60 == 0) {
        if ((-1 < iVar17 << 0x1a) || (iVar16 == 0)) {
          ppvVar14[7] = (void *)((uint)ppvVar14[7] | 0x200);
        }
LAB_000cdc48:
        if (iVar18 == 0) goto LAB_000cdc4e;
LAB_000cdd2e:
        iVar20 = piVar6[4];
        if (-1 < iVar17 << 0x1a) {
          iVar18 = iVar18 + -1;
        }
        if ((-1 < iVar20) && (iVar20 <= iVar18)) {
          iVar18 = iVar20;
        }
      }
      else {
        iVar20 = piVar6[2];
        if (-1 < iVar17 << 0x1a) {
          local_60 = local_60 + -1;
        }
        if (iVar20 < 0) goto LAB_000cdc48;
        if (iVar20 <= local_60) {
          local_60 = iVar20;
        }
        if (iVar18 != 0) goto LAB_000cdd2e;
LAB_000cdc4e:
        ppvVar14[7] = (void *)((uint)ppvVar14[7] | 0x400);
      }
      bVar22 = iVar16 != 0;
      iVar16 = iVar16 + -1;
      ppvVar14 = ppvVar14 + 4;
    } while (bVar22);
  }
  if (iVar12 == 0) {
    *pexplicit_policy = 1;
  }
  else if (tree == (void **)0x0) {
    return 1;
  }
  pvVar4 = tree[1];
  pvVar1 = *tree;
  if (1 < (int)pvVar4) {
    local_5c = (int)pvVar1 + -0x10;
    local_50 = 1;
    pvVar21 = pvVar1;
    do {
      pvVar19 = (void *)((int)pvVar21 + 0x10);
      piVar6 = (int *)policy_cache_set(*(undefined4 *)((int)pvVar21 + 0x10));
      iVar18 = 0;
      iVar12 = sk_num((_STACK *)piVar6[1]);
      if (0 < iVar12) {
        do {
          bVar22 = false;
          pvVar1 = sk_value((_STACK *)piVar6[1],iVar18);
          iVar12 = 0;
          while( true ) {
            iVar16 = sk_num(*(_STACK **)(local_5c + 0x14));
            iVar17 = iVar12 + 1;
            if (iVar16 <= iVar12) break;
            pvVar4 = sk_value(*(_STACK **)(local_5c + 0x14),iVar12);
            iVar16 = policy_node_match(pvVar21,pvVar4,*(undefined4 *)((int)pvVar1 + 4));
            iVar12 = iVar17;
            if (iVar16 != 0) {
              iVar16 = level_add_node(pvVar19,pvVar1,pvVar4,0);
              if (iVar16 == 0) goto LAB_000cda7a;
              bVar22 = true;
            }
          }
          if (((!bVar22) && (*(int *)(local_5c + 0x18) != 0)) &&
             (iVar12 = level_add_node(pvVar19,pvVar1,*(int *)(local_5c + 0x18),0), iVar12 == 0))
          goto LAB_000cda7a;
          iVar18 = iVar18 + 1;
          iVar12 = sk_num((_STACK *)piVar6[1]);
        } while (iVar18 < iVar12);
      }
      uVar11 = *(uint *)((int)pvVar21 + 0x1c);
      HintPreloadData((int)pvVar21 + 0x2c);
      if ((uVar11 & 0x200) == 0) {
        for (iVar12 = 0; iVar18 = sk_num(*(_STACK **)(local_5c + 0x14)), iVar12 < iVar18;
            iVar12 = iVar12 + 1) {
          ppuVar7 = (uint **)sk_value(*(_STACK **)(local_5c + 0x14),iVar12);
          if (((*(uint *)((int)pvVar21 + 0xc) & 0x400) == 0) && ((int)(**ppuVar7 << 0x1f) < 0)) {
            p_Var3 = (_STACK *)(*ppuVar7)[3];
            puVar10 = ppuVar7[2];
            puVar8 = (uint *)sk_num(p_Var3);
            if (puVar10 != puVar8) {
              for (iVar18 = 0; iVar16 = sk_num(p_Var3), iVar18 < iVar16; iVar18 = iVar18 + 1) {
                pvVar1 = sk_value(p_Var3,iVar18);
                iVar16 = level_find_node(pvVar19,ppuVar7,pvVar1);
                if (iVar16 == 0) {
                  if (pvVar1 == (void *)0x0) {
                    pvVar1 = (void *)(*ppuVar7)[1];
                  }
                  puVar8 = (uint *)policy_data_new(0,pvVar1,**ppuVar7 & 0x10);
                  if (puVar8 == (uint *)0x0) goto LAB_000cda7a;
                  puVar8[2] = *(uint *)(*piVar6 + 8);
                  *puVar8 = *puVar8 | 4;
                  iVar16 = level_add_node(pvVar19,puVar8,ppuVar7,tree);
                  if (iVar16 == 0) {
                    policy_data_free(puVar8);
                    goto LAB_000cda7a;
                  }
                }
              }
            }
          }
          else if (ppuVar7[2] == (uint *)0x0) {
            puVar8 = (uint *)policy_data_new(0,(*ppuVar7)[1],**ppuVar7 & 0x10);
            if (puVar8 == (uint *)0x0) goto LAB_000cda7a;
            iVar18 = *piVar6;
            *puVar8 = *puVar8 | 4;
            puVar8[2] = *(uint *)(iVar18 + 8);
            iVar18 = level_add_node(pvVar19,puVar8,ppuVar7,tree);
            if (iVar18 == 0) {
              policy_data_free(puVar8);
              goto LAB_000cda7a;
            }
          }
        }
        HintPreloadData((int)pvVar21 + 0x18);
        if ((*(int *)(local_5c + 0x18) != 0) &&
           (iVar12 = level_add_node(pvVar19,*piVar6,*(int *)(local_5c + 0x18),0), iVar12 == 0))
        goto LAB_000cda7a;
        uVar11 = *(uint *)((int)pvVar21 + 0x1c);
      }
      p_Var3 = *(_STACK **)((int)pvVar21 + 0x14);
      pvVar4 = pvVar19;
      if ((int)(uVar11 << 0x15) < 0) {
        iVar12 = sk_num(p_Var3);
        iVar12 = iVar12 + -1;
        if (-1 < iVar12) {
          do {
            ppuVar7 = (uint **)sk_value(p_Var3,iVar12);
            if ((**ppuVar7 & 3) != 0) {
              ppuVar7[1][2] = ppuVar7[1][2] - 1;
              CRYPTO_free(ppuVar7);
              sk_delete(p_Var3,iVar12);
            }
            bVar22 = iVar12 != 0;
            iVar12 = iVar12 + -1;
          } while (bVar22);
        }
      }
      do {
        pvVar21 = (void *)((int)pvVar4 + -0x10);
        p_Var3 = *(_STACK **)((int)pvVar4 + -0xc);
        iVar12 = sk_num(p_Var3);
        iVar12 = iVar12 + -1;
        if (-1 < iVar12) {
          do {
            while (pvVar1 = sk_value(p_Var3,iVar12), *(int *)((int)pvVar1 + 8) == 0) {
              *(int *)(*(int *)((int)pvVar1 + 4) + 8) = *(int *)(*(int *)((int)pvVar1 + 4) + 8) + -1
              ;
              CRYPTO_free(pvVar1);
              sk_delete(p_Var3,iVar12);
              bVar22 = iVar12 == 0;
              iVar12 = iVar12 + -1;
              if (bVar22) goto LAB_000cdeb6;
            }
            bVar22 = iVar12 != 0;
            iVar12 = iVar12 + -1;
          } while (bVar22);
        }
LAB_000cdeb6:
        pvVar1 = *(void **)((int)pvVar4 + -8);
        HintPreloadData((int)pvVar4 + -0x38);
        if ((pvVar1 != (void *)0x0) && (*(int *)((int)pvVar1 + 8) == 0)) {
          iVar12 = *(int *)((int)pvVar1 + 4);
          if (iVar12 != 0) {
            *(int *)(iVar12 + 8) = *(int *)(iVar12 + 8) + -1;
          }
          CRYPTO_free(pvVar1);
          *(undefined4 *)((int)pvVar4 + -8) = 0;
        }
        pvVar1 = *tree;
        pvVar4 = pvVar21;
      } while (pvVar21 != pvVar1);
      if (*(int *)((int)pvVar1 + 8) == 0) {
        sk_free((_STACK *)tree[3]);
        sk_pop_free((_STACK *)tree[4],DAT_000ce250);
        if (0 < (int)tree[1]) {
          iVar12 = 0;
          ppXVar13 = (X509 **)*tree;
          do {
            iVar12 = iVar12 + 1;
            HintPreloadData(ppXVar13 + 0x15);
            if (*ppXVar13 != (X509 *)0x0) {
              X509_free(*ppXVar13);
            }
            if (ppXVar13[1] != (X509 *)0x0) {
              sk_pop_free((_STACK *)ppXVar13[1],DAT_000ce254);
            }
            if (ppXVar13[2] != (X509 *)0x0) {
              policy_node_free(ppXVar13[2]);
            }
            ppXVar13 = ppXVar13 + 4;
          } while (iVar12 < (int)tree[1]);
        }
        if ((_STACK *)tree[2] != (_STACK *)0x0) {
          sk_pop_free((_STACK *)tree[2],DAT_000ce258);
        }
        CRYPTO_free(*tree);
        CRYPTO_free(tree);
        if (*pexplicit_policy == 0) {
          return 1;
        }
        return -2;
      }
      pvVar4 = tree[1];
      local_50 = local_50 + 1;
      local_5c = local_5c + 0x10;
      pvVar21 = pvVar19;
    } while (local_50 < (int)pvVar4);
  }
  pvVar21 = *(void **)((int)pvVar1 + (int)pvVar4 * 0x10 + -8);
  if (pvVar21 == (void *)0x0) {
    pp_Var15 = (_STACK **)(tree + 3);
    goto LAB_000cdf38;
  }
  if ((_STACK *)tree[3] != (_STACK *)0x0) {
    iVar12 = sk_find((_STACK *)tree[3],pvVar21);
    if (iVar12 == -1) {
      p_Var3 = (_STACK *)tree[3];
LAB_000ce232:
      iVar12 = sk_push(p_Var3,pvVar21);
      if (iVar12 == 0) goto LAB_000cda7a;
    }
    pvVar1 = *tree;
    pp_Var15 = local_2c;
    pvVar4 = tree[1];
LAB_000cdf38:
    if ((1 < (int)pvVar4) && (iVar12 = *(int *)((int)pvVar1 + 8), iVar12 != 0)) {
      iVar18 = 1;
LAB_000cdf50:
      iVar16 = 0;
LAB_000cdf56:
      do {
        iVar17 = sk_num(*(_STACK **)((int)pvVar1 + 0x14));
        iVar20 = iVar16 + 1;
        if (iVar17 <= iVar16) goto LAB_000ce066;
        pvVar4 = sk_value(*(_STACK **)((int)pvVar1 + 0x14),iVar16);
        iVar16 = iVar20;
        if (iVar12 == *(int *)((int)pvVar4 + 4)) {
          if (*pp_Var15 == (_STACK *)0x0) {
            p_Var3 = (_STACK *)policy_node_cmp_new();
            *pp_Var15 = p_Var3;
            if (p_Var3 == (_STACK *)0x0) goto LAB_000cda7a;
          }
          else {
            iVar17 = sk_find(*pp_Var15,pvVar4);
            if (iVar17 != -1) goto LAB_000cdf56;
            p_Var3 = *pp_Var15;
          }
          iVar17 = sk_push(p_Var3,pvVar4);
          if (iVar17 == 0) goto LAB_000cda7a;
        }
      } while( true );
    }
LAB_000ce082:
    if (pp_Var15 == local_2c) {
      iVar12 = 2;
    }
    else {
      iVar12 = 1;
      local_2c[0] = (_STACK *)tree[3];
    }
    p_Var3 = local_2c[0];
    iVar18 = sk_num(&policy_oids->stack);
    if (0 < iVar18) {
      ppuVar7 = *(uint ***)((int)*tree + (int)tree[1] * 0x10 + -8);
      iVar18 = 0;
      do {
        iVar16 = sk_num(&policy_oids->stack);
        if (iVar16 <= iVar18) {
          iVar18 = 0;
          goto LAB_000ce106;
        }
        pAVar5 = (ASN1_OBJECT *)sk_value(&policy_oids->stack,iVar18);
        iVar16 = OBJ_obj2nid(pAVar5);
        iVar18 = iVar18 + 1;
      } while (iVar16 != 0x2ea);
      tree[5] = (void *)((uint)tree[5] | 2);
    }
LAB_000cdb2c:
    if (iVar12 == 2) {
      sk_free(p_Var3);
    }
    iVar12 = *pexplicit_policy;
    *ptree = (X509_POLICY_TREE *)tree;
    if (iVar12 != 0) {
      p_Var3 = &X509_policy_tree_get0_user_policies((X509_POLICY_TREE *)tree)->stack;
      iVar12 = sk_num(p_Var3);
      if (iVar12 < 1) {
        return -2;
      }
    }
    return 1;
  }
  p_Var3 = (_STACK *)policy_node_cmp_new();
  tree[3] = p_Var3;
  if (p_Var3 != (_STACK *)0x0) goto LAB_000ce232;
  goto LAB_000cda7e;
LAB_000ce066:
  iVar18 = iVar18 + 1;
  if ((int)tree[1] <= iVar18) goto LAB_000ce082;
  iVar12 = *(int *)((int)pvVar1 + 0x18);
  HintPreloadData((int)pvVar1 + 0x48);
  pvVar1 = (void *)((int)pvVar1 + 0x10);
  if (iVar12 == 0) goto LAB_000ce082;
  goto LAB_000cdf50;
  while( true ) {
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      tree[4] = st;
      if (st == (_STACK *)0x0) goto LAB_000cdb2c;
    }
    iVar16 = sk_push(st,pvVar1);
    if (iVar16 == 0) break;
LAB_000ce106:
    iVar16 = sk_num(&policy_oids->stack);
    iVar17 = iVar18 + 1;
    if (iVar16 <= iVar18) goto LAB_000cdb2c;
    pvVar4 = sk_value(&policy_oids->stack,iVar18);
    pvVar1 = (void *)tree_find_sk(p_Var3,pvVar4);
    iVar18 = iVar17;
    if (pvVar1 == (void *)0x0) {
      if (ppuVar7 == (uint **)0x0) goto LAB_000ce106;
      puVar9 = (undefined4 *)policy_data_new(0,pvVar4,**ppuVar7 & 0x10);
      if (puVar9 == (undefined4 *)0x0) break;
      puVar10 = *ppuVar7;
      puVar8 = ppuVar7[1];
      *puVar9 = 0xc;
      puVar9[2] = puVar10[2];
      pvVar1 = (void *)level_add_node(0,puVar9,puVar8,tree);
      st = (_STACK *)tree[4];
    }
    else {
      st = (_STACK *)tree[4];
    }
  }
LAB_000cda7a:
  p_Var3 = (_STACK *)tree[3];
LAB_000cda7e:
  sk_free(p_Var3);
  sk_pop_free((_STACK *)tree[4],DAT_000cdd54);
  if (0 < (int)tree[1]) {
    iVar12 = 0;
    ppXVar13 = (X509 **)*tree;
    do {
      iVar12 = iVar12 + 1;
      HintPreloadData(ppXVar13 + 0x15);
      if (*ppXVar13 != (X509 *)0x0) {
        X509_free(*ppXVar13);
      }
      if (ppXVar13[1] != (X509 *)0x0) {
        sk_pop_free((_STACK *)ppXVar13[1],DAT_000cdd58);
      }
      if (ppXVar13[2] != (X509 *)0x0) {
        policy_node_free(ppXVar13[2]);
      }
      ppXVar13 = ppXVar13 + 4;
    } while (iVar12 < (int)tree[1]);
  }
  p_Var3 = (_STACK *)tree[2];
joined_r0x000ce21a:
  if (p_Var3 != (_STACK *)0x0) {
    sk_pop_free(p_Var3,DAT_000cdd5c);
  }
  CRYPTO_free(*tree);
  CRYPTO_free(tree);
  return 0;
}

