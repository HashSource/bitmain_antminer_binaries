
BIGNUM * ubsec_dsa_do_sign(uchar *param_1,int param_2,DSA *param_3)

{
  BIGNUM *a;
  BIGNUM *a_00;
  undefined4 uVar1;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulong *puVar7;
  int iVar8;
  DSA_METHOD *pDVar9;
  int iVar10;
  ulong *puVar11;
  ulong *puVar12;
  ulong *puVar13;
  int iVar14;
  code *pcVar15;
  undefined4 local_44;
  undefined4 local_40;
  BIGNUM BStack_3c;
  
  local_44 = 0xa0;
  local_40 = 0xa0;
  BN_init(&BStack_3c);
  a = BN_new();
  a_00 = BN_new();
  iVar10 = DAT_000de9a0;
  if (a == (BIGNUM *)0x0 || a_00 == (BIGNUM *)0x0) {
LAB_000de926:
    if (a_00 != (BIGNUM *)0x0) {
      BN_free(a_00);
    }
  }
  else {
    uVar1 = (**(code **)(DAT_000de9a0 + 0xc))(param_1,param_2);
    if (((a_00->dmax < 5) && (pBVar2 = bn_expand2(a_00,5), pBVar2 == (BIGNUM *)0x0)) ||
       ((a->dmax < 5 && (pBVar2 = bn_expand2(a,5), pBVar2 == (BIGNUM *)0x0)))) {
      iVar14 = DAT_000de9a0;
      iVar10 = *(int *)(iVar10 + 4);
      if (iVar10 == 0) {
        iVar10 = ERR_get_next_error_library();
        *(int *)(iVar14 + 4) = iVar10;
      }
      iVar14 = 0x301;
LAB_000de91a:
      ERR_put_error(iVar10,0x66,0x65,DAT_000de99c,iVar14);
      goto LAB_000de926;
    }
    pBVar2 = BN_bin2bn(param_1,param_2,&BStack_3c);
    iVar14 = DAT_000de9a0;
    if (pBVar2 == (BIGNUM *)0x0) {
      iVar10 = *(int *)(iVar10 + 4);
      if (iVar10 == 0) {
        iVar10 = ERR_get_next_error_library();
        *(int *)(iVar14 + 4) = iVar10;
      }
      iVar14 = 0x306;
      goto LAB_000de91a;
    }
    iVar3 = (**(code **)(iVar10 + 0x14))(DAT_000de998);
    iVar14 = DAT_000de9a0;
    if (iVar3 < 1) {
      iVar10 = *(int *)(DAT_000de9a0 + 4);
      if (iVar10 == 0) {
        iVar10 = ERR_get_next_error_library();
        *(int *)(iVar14 + 4) = iVar10;
      }
      ERR_put_error(iVar10,0x66,0x6c,DAT_000de99c,0x30d);
    }
    else {
      pcVar15 = *(code **)(DAT_000de9a0 + 0x2c);
      puVar13 = param_3->p->d;
      iVar4 = BN_num_bits(param_3->p);
      puVar11 = param_3->q->d;
      iVar5 = BN_num_bits(param_3->q);
      puVar12 = param_3->g->d;
      iVar6 = BN_num_bits(param_3->g);
      puVar7 = param_3->priv_key->d;
      iVar8 = BN_num_bits(param_3->priv_key);
      iVar4 = (*pcVar15)(iVar3,0,param_1,uVar1,0,0,puVar13,iVar4,puVar11,iVar5,puVar12,iVar6,puVar7,
                         iVar8,a_00->d,&local_40,a->d,&local_44);
      if (iVar4 == 0) {
        (**(code **)(iVar14 + 0x18))(iVar3);
        a_00->top = 5;
        a->top = 5;
        pBVar2 = (BIGNUM *)DSA_SIG_new();
        if (pBVar2 != (BIGNUM *)0x0) {
          pBVar2->d = (ulong *)a_00;
          pBVar2->top = (int)a;
          goto LAB_000de8a2;
        }
        iVar10 = *(int *)(iVar14 + 4);
        if (iVar10 == 0) {
          iVar10 = ERR_get_next_error_library();
          *(int *)(iVar14 + 4) = iVar10;
        }
        iVar14 = 0x333;
        goto LAB_000de91a;
      }
      iVar4 = *(int *)(iVar14 + 4);
      if (iVar4 == 0) {
        iVar4 = ERR_get_next_error_library();
        *(int *)(iVar14 + 4) = iVar4;
      }
      ERR_put_error(iVar4,0x66,0x6a,DAT_000de99c,0x324);
      (**(code **)(iVar10 + 0x18))(iVar3);
    }
    pDVar9 = DSA_OpenSSL();
    pBVar2 = (BIGNUM *)(*pDVar9->dsa_do_sign)(param_1,param_2,param_3);
    if (pBVar2 != (BIGNUM *)0x0) goto LAB_000de8a2;
    BN_free(a_00);
  }
  pBVar2 = a;
  if (a != (BIGNUM *)0x0) {
    pBVar2 = (BIGNUM *)0x0;
    BN_free(a);
  }
LAB_000de8a2:
  BN_clear_free(&BStack_3c);
  return pBVar2;
}

