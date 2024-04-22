
uint x509_object_idx_cnt(_STACK *param_1,int param_2,X509_ALGOR *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int local_130;
  X509 *local_12c;
  undefined auStack_128 [60];
  X509_ALGOR *local_ec;
  X509 local_cc;
  
  if (param_2 == 1) {
    local_12c = (X509 *)&local_cc.nc;
    local_cc.nc = (NAME_CONSTRAINTS *)(auStack_128 + 0x28);
    local_ec = param_3;
  }
  else {
    if (param_2 != 2) {
      return 0xffffffff;
    }
    local_12c = &local_cc;
    local_cc.cert_info = (X509_CINF *)auStack_128;
    auStack_128._8_4_ = param_3;
  }
  local_130 = param_2;
  uVar1 = sk_find(param_1,&local_130);
  uVar4 = ~uVar1 >> 0x1f;
  if (param_4 == (int *)0x0) {
    uVar4 = 0;
  }
  if (uVar4 != 0) {
    *param_4 = 1;
    uVar4 = uVar1;
    while( true ) {
      uVar4 = uVar4 + 1;
      iVar2 = sk_num(param_1);
      if (iVar2 <= (int)uVar4) break;
      piVar3 = (int *)sk_value(param_1,uVar4);
      iVar2 = *piVar3;
      if (iVar2 != local_130) {
        return uVar1;
      }
      if (iVar2 == 1) {
        iVar2 = X509_subject_name_cmp((X509 *)piVar3[1],local_12c);
joined_r0x000c38ec:
        if (iVar2 != 0) {
          return uVar1;
        }
      }
      else if (iVar2 == 2) {
        iVar2 = X509_CRL_cmp((X509_CRL *)piVar3[1],(X509_CRL *)local_12c);
        goto joined_r0x000c38ec;
      }
      *param_4 = *param_4 + 1;
    }
  }
  return uVar1;
}

