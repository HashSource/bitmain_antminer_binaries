
int ubsec_dh_generate_key(DH *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  DH_METHOD *pDVar4;
  BIGNUM *pBVar5;
  ulong *puVar6;
  int iVar7;
  ulong *puVar8;
  BIGNUM *a;
  code *pcVar9;
  ulong *puVar10;
  int iVar11;
  ulong *puVar12;
  BIGNUM *local_44;
  int local_30;
  int local_2c [2];
  
  a = param_1->priv_key;
  local_30 = 0;
  local_2c[0] = 0;
  if (a == (BIGNUM *)0x0) {
    a = BN_new();
    if (a == (BIGNUM *)0x0) {
      return 0;
    }
    local_2c[0] = BN_num_bits(param_1->p);
    pBVar5 = param_1->p;
    if (pBVar5->top <= a->dmax) goto LAB_000ded56;
    pBVar5 = bn_expand2(a,pBVar5->top);
    if (pBVar5 == (BIGNUM *)0x0) {
      return 0;
    }
    do {
      pBVar5 = param_1->p;
LAB_000ded56:
      iVar11 = BN_rand_range(a,pBVar5);
      if (iVar11 == 0) {
        return 0;
      }
    } while (a->top == 0);
    iVar11 = BN_num_bits(a);
  }
  else {
    iVar11 = 0;
  }
  local_44 = param_1->pub_key;
  if (local_44 != (BIGNUM *)0x0) {
LAB_000dec14:
    iVar7 = DAT_000ded70;
    iVar1 = (**(code **)(DAT_000ded70 + 0x14))(DAT_000ded74);
    if (iVar1 < 1) {
      iVar11 = *(int *)(iVar7 + 4);
      if (iVar11 == 0) {
        iVar11 = ERR_get_next_error_library();
        *(int *)(iVar7 + 4) = iVar11;
      }
      ERR_put_error(iVar11,0x6f,0x6c,DAT_000ded78,0x3d5);
      pDVar4 = DH_OpenSSL();
      iVar11 = (*pDVar4->generate_key)(param_1);
      return iVar11;
    }
    pcVar9 = *(code **)(iVar7 + 0x1c);
    puVar6 = a->d;
    puVar10 = param_1->g->d;
    puVar12 = local_44->d;
    iVar2 = BN_num_bits(param_1->g);
    puVar8 = param_1->p->d;
    iVar3 = BN_num_bits(param_1->p);
    iVar11 = (*pcVar9)(iVar1,puVar6,local_2c,puVar12,&local_30,puVar10,iVar2,puVar8,iVar3,0,0,iVar11
                      );
    if (iVar11 != 0) {
      iVar11 = *(int *)(iVar7 + 4);
      if (iVar11 == 0) {
        iVar11 = ERR_get_next_error_library();
        *(int *)(iVar7 + 4) = iVar11;
      }
      ERR_put_error(iVar11,0x6f,0x6a,DAT_000ded78,1000);
      (**(code **)(iVar7 + 0x18))(iVar1);
      pDVar4 = DH_OpenSSL();
      iVar11 = (*pDVar4->generate_key)(param_1);
      return iVar11;
    }
    (**(code **)(iVar7 + 0x18))(iVar1);
    iVar11 = local_30 + 0x1f;
    if (local_30 + 0x1f < 0) {
      iVar11 = local_30 + 0x3e;
    }
    iVar7 = local_2c[0] + 0x1f;
    if (local_2c[0] + 0x1f < 0) {
      iVar7 = local_2c[0] + 0x3e;
    }
    param_1->pub_key = local_44;
    local_44->top = iVar11 >> 5;
    param_1->priv_key = a;
    a->top = iVar7 >> 5;
    return 1;
  }
  local_44 = BN_new();
  if (local_44 != (BIGNUM *)0x0) {
    local_30 = BN_num_bits(param_1->p);
    iVar7 = param_1->p->top;
    if ((iVar7 <= local_44->dmax) || (pBVar5 = bn_expand2(local_44,iVar7), pBVar5 != (BIGNUM *)0x0))
    goto LAB_000dec14;
  }
  return 0;
}

