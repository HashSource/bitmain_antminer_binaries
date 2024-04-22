
BIGNUM * BN_GF2m_mod_mul_arr(BIGNUM *param_1,int *param_2,int *param_3,int *param_4,BN_CTX *param_5)

{
  BIGNUM *a;
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong *puVar5;
  int iVar6;
  ulong *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint unaff_r10;
  bool bVar11;
  uint local_60;
  int local_54;
  int local_50;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c [2];
  
  if (param_2 == param_3) {
    pBVar1 = (BIGNUM *)BN_GF2m_mod_sqr_arr(param_1,param_2,param_4,param_5);
    return pBVar1;
  }
  BN_CTX_start(param_5);
  a = BN_CTX_get(param_5);
  pBVar1 = a;
  if (a != (BIGNUM *)0x0) {
    iVar6 = param_2[1] + param_3[1];
    iVar4 = iVar6 + 4;
    if ((iVar4 <= a->dmax) || (pBVar1 = bn_expand2(a,iVar4), pBVar1 != (BIGNUM *)0x0)) {
      a->top = iVar4;
      if (0 < iVar4) {
        puVar7 = a->d;
        if (iVar6 < 5) {
          iVar2 = 0;
        }
        else {
          iVar2 = 0;
          puVar5 = puVar7;
          do {
            iVar2 = iVar2 + 8;
            HintPreloadData(puVar5 + 0x22);
            *puVar5 = 0;
            puVar5[1] = 0;
            puVar5[2] = 0;
            puVar5[3] = 0;
            puVar5[4] = 0;
            puVar5[5] = 0;
            puVar5[6] = 0;
            puVar5[7] = 0;
            puVar5 = puVar5 + 8;
          } while (iVar2 != (iVar6 - 5U & 0xfffffff8) + 8);
        }
        puVar7 = puVar7 + iVar2 + -1;
        do {
          iVar2 = iVar2 + 1;
          puVar7 = puVar7 + 1;
          *puVar7 = 0;
        } while (iVar2 < iVar4);
      }
      iVar4 = param_3[1];
      if (0 < iVar4) {
        iVar6 = param_2[1];
        local_54 = 0;
        local_50 = 0;
        do {
          bVar11 = local_50 + 1 != iVar4;
          iVar2 = local_50;
          if (bVar11) {
            iVar2 = local_54;
          }
          uVar9 = *(uint *)(*param_3 + local_54);
          if (bVar11) {
            local_60 = *(uint *)(*param_3 + iVar2 + 4);
          }
          else {
            local_60 = 0;
          }
          if (0 < iVar6) {
            iVar8 = 1;
            iVar2 = 0;
            iVar4 = local_54;
            do {
              if (iVar6 == iVar8) {
                unaff_r10 = 0;
              }
              if (iVar6 != iVar8) {
                unaff_r10 = *(uint *)(*param_2 + iVar8 * 4);
              }
              iVar8 = iVar8 + 2;
              uVar10 = *(uint *)(*param_2 + iVar2 * 4);
              iVar2 = iVar2 + 2;
              bn_GF2m_mul_1x1(local_2c,&local_30,unaff_r10,local_60);
              bn_GF2m_mul_1x1(&local_34,&local_38,uVar10,uVar9);
              bn_GF2m_mul_1x1(&local_40,&local_3c,unaff_r10 ^ uVar10,local_60 ^ uVar9);
              iVar3 = iVar4 + 8;
              unaff_r10 = local_34 ^ local_30 ^ local_40;
              puVar7 = a->d;
              local_30 = unaff_r10 ^ local_2c[0];
              local_34 = local_2c[0] ^ local_40 ^ local_38 ^ local_3c ^ local_30;
              *(uint *)((int)puVar7 + iVar4) = *(uint *)((int)puVar7 + iVar4) ^ local_38;
              *(uint *)((int)puVar7 + iVar4 + 4) = local_34 ^ *(uint *)((int)puVar7 + iVar4 + 4);
              *(uint *)((int)puVar7 + iVar3) = local_30 ^ *(uint *)((int)puVar7 + iVar3);
              *(uint *)((int)puVar7 + iVar4 + 0xc) =
                   local_2c[0] ^ *(uint *)((int)puVar7 + iVar4 + 0xc);
              iVar6 = param_2[1];
              iVar4 = iVar3;
            } while (iVar2 < iVar6);
            iVar4 = param_3[1];
          }
          local_50 = local_50 + 2;
          local_54 = local_54 + 8;
        } while (local_50 < iVar4);
      }
      iVar4 = a->top;
      if (0 < iVar4) {
        puVar7 = a->d + iVar4 + -1;
        do {
          if (*puVar7 != 0) break;
          iVar4 = iVar4 + -1;
          puVar7 = puVar7 + -1;
        } while (iVar4 != 0);
        a->top = iVar4;
      }
      if (*param_4 == 0) {
        BN_set_word(param_1,0);
      }
      else {
        if (param_1 != a) {
          if (param_1->dmax < iVar4) {
            pBVar1 = bn_expand2(param_1,iVar4);
            if (pBVar1 == (BIGNUM *)0x0) goto LAB_001233b2;
            iVar4 = a->top;
          }
          if (0 < iVar4) {
            iVar2 = 0;
            puVar7 = a->d;
            iVar6 = 0;
            puVar5 = param_1->d;
            do {
              iVar6 = iVar6 + 1;
              *(undefined4 *)((int)puVar5 + iVar2) = *(undefined4 *)((int)puVar7 + iVar2);
              iVar2 = iVar2 + 4;
              iVar4 = a->top;
            } while (iVar6 < iVar4);
          }
          param_1->top = iVar4;
        }
        pBVar1 = (BIGNUM *)BN_GF2m_mod_arr_part_0(param_1,param_4);
        if (pBVar1 == (BIGNUM *)0x0) goto LAB_001233b2;
      }
      pBVar1 = (BIGNUM *)0x1;
    }
  }
LAB_001233b2:
  BN_CTX_end(param_5);
  return pBVar1;
}

