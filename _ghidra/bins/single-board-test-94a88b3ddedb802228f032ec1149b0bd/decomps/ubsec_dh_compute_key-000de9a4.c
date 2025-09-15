
void ubsec_dh_compute_key(uchar *param_1,BIGNUM *param_2,DH *param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  DH_METHOD *pDVar6;
  ulong *puVar7;
  ulong *puVar8;
  ulong *puVar9;
  int local_2c [2];
  
  local_2c[0] = BN_num_bits(param_3->p);
  iVar2 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
  pcVar1 = p_UBSEC_diffie_hellman_agree_ioctl;
  if (iVar2 < 1) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,0x65,0x6c,"e_ubsec.c",0x38d);
  }
  else {
    puVar7 = param_3->priv_key->d;
    iVar3 = BN_num_bits(param_3->priv_key);
    puVar8 = param_2->d;
    iVar4 = BN_num_bits(param_2);
    puVar9 = param_3->p->d;
    iVar5 = BN_num_bits(param_3->p);
    iVar3 = (*pcVar1)(iVar2,puVar7,iVar3,puVar8,iVar4,puVar9,iVar5,param_1,local_2c);
    if (iVar3 == 0) {
      (*p_UBSEC_ubsec_close)(iVar2);
      (*p_UBSEC_ubsec_bits_to_bytes)(local_2c[0]);
      return;
    }
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,0x65,0x6a,"e_ubsec.c",0x39d);
    (*p_UBSEC_ubsec_close)(iVar2);
  }
  pDVar6 = DH_OpenSSL();
  (*pDVar6->compute_key)(param_1,param_2,param_3);
  return;
}

