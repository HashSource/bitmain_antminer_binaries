
void ubsec_dh_compute_key(uchar *param_1,BIGNUM *param_2,DH *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  DH_METHOD *pDVar6;
  ulong *puVar7;
  code *pcVar8;
  ulong *puVar9;
  ulong *puVar10;
  int local_2c [2];
  
  iVar1 = DAT_000dea70;
  local_2c[0] = BN_num_bits(param_3->p);
  iVar2 = (**(code **)(iVar1 + 0x14))(DAT_000dea74);
  if (iVar2 < 1) {
    iVar2 = *(int *)(iVar1 + 4);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar2;
    }
    ERR_put_error(iVar2,0x65,0x6c,DAT_000dea78,0x38d);
  }
  else {
    pcVar8 = *(code **)(iVar1 + 0x20);
    puVar7 = param_3->priv_key->d;
    iVar3 = BN_num_bits(param_3->priv_key);
    puVar9 = param_2->d;
    iVar4 = BN_num_bits(param_2);
    puVar10 = param_3->p->d;
    iVar5 = BN_num_bits(param_3->p);
    iVar3 = (*pcVar8)(iVar2,puVar7,iVar3,puVar9,iVar4,puVar10,iVar5,param_1,local_2c);
    if (iVar3 == 0) {
      (**(code **)(iVar1 + 0x18))(iVar2);
      (**(code **)(iVar1 + 0x10))(local_2c[0]);
      return;
    }
    iVar3 = *(int *)(iVar1 + 4);
    if (iVar3 == 0) {
      iVar3 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar3;
    }
    ERR_put_error(iVar3,0x65,0x6a,DAT_000dea78,0x39d);
    (**(code **)(iVar1 + 0x18))(iVar2);
  }
  pDVar6 = DH_OpenSSL();
  (*pDVar6->compute_key)(param_1,param_2,param_3);
  return;
}

