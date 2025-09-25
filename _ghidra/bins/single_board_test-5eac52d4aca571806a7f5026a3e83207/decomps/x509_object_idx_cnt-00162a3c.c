
uint x509_object_idx_cnt(undefined4 param_1,int param_2,ulong param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int local_178;
  X509 *local_174;
  X509 XStack_170;
  X509 XStack_e8;
  
  if (param_2 == 1) {
    local_174 = &XStack_e8;
    XStack_e8.ex_flags = param_3;
  }
  else {
    if (param_2 == 0) {
      return 0xffffffff;
    }
    if (param_2 == 2) {
      local_174 = &XStack_170;
      XStack_170.valid = param_3;
    }
  }
  local_178 = param_2;
  uVar1 = OPENSSL_sk_find(param_1,&local_178);
  uVar4 = ~uVar1 >> 0x1f;
  if (param_4 == (int *)0x0) {
    uVar4 = 0;
  }
  if (uVar4 != 0) {
    iVar5 = uVar1 + 1;
    *param_4 = 1;
    iVar2 = OPENSSL_sk_num(param_1);
    if (iVar5 < iVar2) {
      do {
        piVar3 = (int *)OPENSSL_sk_value(param_1,iVar5);
        iVar2 = *piVar3;
        if (iVar2 != local_178) {
          return uVar1;
        }
        if (iVar2 == 1) {
          iVar2 = X509_subject_name_cmp((X509 *)piVar3[1],local_174);
LAB_00162aa6:
          if (iVar2 != 0) {
            return uVar1;
          }
        }
        else if (iVar2 == 2) {
          iVar2 = X509_CRL_cmp((X509_CRL *)piVar3[1],(X509_CRL *)local_174);
          goto LAB_00162aa6;
        }
        iVar5 = iVar5 + 1;
        *param_4 = *param_4 + 1;
        iVar2 = OPENSSL_sk_num(param_1);
      } while (iVar5 < iVar2);
    }
  }
  return uVar1;
}

