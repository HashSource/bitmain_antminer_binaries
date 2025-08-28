
int ubsec_dsa_verify(uchar *param_1,int param_2,DSA_SIG *param_3,DSA *param_4)

{
  code *pcVar1;
  BIGNUM *pBVar2;
  undefined4 uVar3;
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
  ulong *puVar17;
  int local_40;
  BIGNUM local_3c;
  
  BN_init(&local_3c);
  pBVar2 = param_4->p;
  if (local_3c.dmax < pBVar2->top) {
    pBVar2 = bn_expand2(&local_3c,pBVar2->top);
    if (pBVar2 == (BIGNUM *)0x0) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      iVar5 = 0;
      ERR_put_error(UBSEC_lib_error_code,0x67,0x65,"e_ubsec.c",0x350);
      goto LAB_000deb5c;
    }
    pBVar2 = param_4->p;
  }
  local_40 = BN_num_bits(pBVar2);
  uVar3 = (*p_UBSEC_ubsec_bytes_to_bits)(param_1,param_2);
  iVar4 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
  pcVar1 = p_UBSEC_dsa_verify_ioctl;
  if (iVar4 < 1) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,0x67,0x6c,"e_ubsec.c",0x35b);
  }
  else {
    puVar12 = param_4->p->d;
    iVar5 = BN_num_bits(param_4->p);
    puVar13 = param_4->q->d;
    iVar6 = BN_num_bits(param_4->q);
    puVar17 = param_4->g->d;
    iVar7 = BN_num_bits(param_4->g);
    puVar14 = param_4->pub_key->d;
    iVar8 = BN_num_bits(param_4->pub_key);
    puVar15 = param_3->r->d;
    iVar9 = BN_num_bits(param_3->r);
    puVar16 = param_3->s->d;
    iVar10 = BN_num_bits(param_3->s);
    iVar5 = (*pcVar1)(iVar4,0,param_1,uVar3,puVar12,iVar5,puVar13,iVar6,puVar17,iVar7,puVar14,iVar8,
                      puVar15,iVar9,puVar16,iVar10,local_3c.d,&local_40);
    if (iVar5 == 0) {
      iVar5 = 1;
      (*p_UBSEC_ubsec_close)(iVar4);
      goto LAB_000deb5c;
    }
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,0x67,0x6a,"e_ubsec.c",0x371);
    (*p_UBSEC_ubsec_close)(iVar4);
  }
  pDVar11 = DSA_OpenSSL();
  iVar5 = (*pDVar11->dsa_do_verify)(param_1,param_2,param_3,param_4);
LAB_000deb5c:
  BN_clear_free(&local_3c);
  return iVar5;
}

