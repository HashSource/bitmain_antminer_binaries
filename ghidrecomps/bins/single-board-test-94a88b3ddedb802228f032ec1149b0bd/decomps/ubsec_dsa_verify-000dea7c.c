
int ubsec_dsa_verify(uchar *param_1,int param_2,DSA_SIG *param_3,DSA *param_4)

{
  BIGNUM *pBVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  DSA_METHOD *pDVar11;
  ulong *puVar12;
  ulong *puVar13;
  ulong *puVar14;
  ulong *puVar15;
  ulong *puVar16;
  code *pcVar17;
  ulong *puVar18;
  int local_40;
  BIGNUM local_3c;
  
  BN_init(&local_3c);
  pBVar1 = param_4->p;
  if (local_3c.dmax < pBVar1->top) {
    pBVar1 = bn_expand2(&local_3c,pBVar1->top);
    iVar4 = DAT_000debe8;
    if (pBVar1 == (BIGNUM *)0x0) {
      iVar10 = *(int *)(DAT_000debe8 + 4);
      if (iVar10 == 0) {
        iVar10 = ERR_get_next_error_library();
        *(int *)(iVar4 + 4) = iVar10;
      }
      iVar4 = 0;
      ERR_put_error(iVar10,0x67,0x65,DAT_000debf0,0x350);
      goto LAB_000deb5c;
    }
    pBVar1 = param_4->p;
  }
  iVar10 = DAT_000debe8;
  local_40 = BN_num_bits(pBVar1);
  uVar2 = (**(code **)(iVar10 + 0xc))(param_1,param_2);
  iVar3 = (**(code **)(iVar10 + 0x14))(DAT_000debec);
  if (iVar3 < 1) {
    iVar4 = *(int *)(iVar10 + 4);
    if (iVar4 == 0) {
      iVar4 = ERR_get_next_error_library();
      *(int *)(iVar10 + 4) = iVar4;
    }
    ERR_put_error(iVar4,0x67,0x6c,DAT_000debf0,0x35b);
  }
  else {
    pcVar17 = *(code **)(iVar10 + 0x30);
    puVar12 = param_4->p->d;
    iVar4 = BN_num_bits(param_4->p);
    puVar13 = param_4->q->d;
    iVar5 = BN_num_bits(param_4->q);
    puVar18 = param_4->g->d;
    iVar6 = BN_num_bits(param_4->g);
    puVar14 = param_4->pub_key->d;
    iVar7 = BN_num_bits(param_4->pub_key);
    puVar15 = param_3->r->d;
    iVar8 = BN_num_bits(param_3->r);
    puVar16 = param_3->s->d;
    iVar9 = BN_num_bits(param_3->s);
    iVar4 = (*pcVar17)(iVar3,0,param_1,uVar2,puVar12,iVar4,puVar13,iVar5,puVar18,iVar6,puVar14,iVar7
                       ,puVar15,iVar8,puVar16,iVar9,local_3c.d,&local_40);
    if (iVar4 == 0) {
      iVar4 = 1;
      (**(code **)(iVar10 + 0x18))(iVar3);
      goto LAB_000deb5c;
    }
    iVar4 = *(int *)(iVar10 + 4);
    if (iVar4 == 0) {
      iVar4 = ERR_get_next_error_library();
      *(int *)(iVar10 + 4) = iVar4;
    }
    ERR_put_error(iVar4,0x67,0x6a,DAT_000debf0,0x371);
    (**(code **)(iVar10 + 0x18))(iVar3);
  }
  pDVar11 = DSA_OpenSSL();
  iVar4 = (*pDVar11->dsa_do_verify)(param_1,param_2,param_3,param_4);
LAB_000deb5c:
  BN_clear_free(&local_3c);
  return iVar4;
}

