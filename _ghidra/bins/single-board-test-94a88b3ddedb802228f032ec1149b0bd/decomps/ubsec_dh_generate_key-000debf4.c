
int ubsec_dh_generate_key(DH *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  DH_METHOD *pDVar5;
  BIGNUM *pBVar6;
  ulong *puVar7;
  ulong *puVar8;
  BIGNUM *a;
  ulong *puVar9;
  int iVar10;
  ulong *puVar11;
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
    pBVar6 = param_1->p;
    if (pBVar6->top <= a->dmax) goto LAB_000ded56;
    pBVar6 = bn_expand2(a,pBVar6->top);
    if (pBVar6 == (BIGNUM *)0x0) {
      return 0;
    }
    do {
      pBVar6 = param_1->p;
LAB_000ded56:
      iVar10 = BN_rand_range(a,pBVar6);
      if (iVar10 == 0) {
        return 0;
      }
    } while (a->top == 0);
    iVar10 = BN_num_bits(a);
  }
  else {
    iVar10 = 0;
  }
  local_44 = param_1->pub_key;
  if (local_44 != (BIGNUM *)0x0) {
LAB_000dec14:
    iVar2 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
    pcVar1 = p_UBSEC_diffie_hellman_generate_ioctl;
    if (iVar2 < 1) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,0x6f,0x6c,"e_ubsec.c",0x3d5);
      pDVar5 = DH_OpenSSL();
      iVar10 = (*pDVar5->generate_key)(param_1);
      return iVar10;
    }
    puVar7 = a->d;
    puVar9 = param_1->g->d;
    puVar11 = local_44->d;
    iVar3 = BN_num_bits(param_1->g);
    puVar8 = param_1->p->d;
    iVar4 = BN_num_bits(param_1->p);
    iVar10 = (*pcVar1)(iVar2,puVar7,local_2c,puVar11,&local_30,puVar9,iVar3,puVar8,iVar4,0,0,iVar10)
    ;
    if (iVar10 != 0) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,0x6f,0x6a,"e_ubsec.c",1000);
      (*p_UBSEC_ubsec_close)(iVar2);
      pDVar5 = DH_OpenSSL();
      iVar10 = (*pDVar5->generate_key)(param_1);
      return iVar10;
    }
    (*p_UBSEC_ubsec_close)(iVar2);
    iVar10 = local_30 + 0x1f;
    if (local_30 + 0x1f < 0) {
      iVar10 = local_30 + 0x3e;
    }
    iVar2 = local_2c[0] + 0x1f;
    if (local_2c[0] + 0x1f < 0) {
      iVar2 = local_2c[0] + 0x3e;
    }
    param_1->pub_key = local_44;
    local_44->top = iVar10 >> 5;
    param_1->priv_key = a;
    a->top = iVar2 >> 5;
    return 1;
  }
  local_44 = BN_new();
  if (local_44 != (BIGNUM *)0x0) {
    local_30 = BN_num_bits(param_1->p);
    iVar2 = param_1->p->top;
    if ((iVar2 <= local_44->dmax) || (pBVar6 = bn_expand2(local_44,iVar2), pBVar6 != (BIGNUM *)0x0))
    goto LAB_000dec14;
  }
  return 0;
}

