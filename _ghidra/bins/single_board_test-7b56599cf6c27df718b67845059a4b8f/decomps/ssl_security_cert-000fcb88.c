
undefined4
ssl_security_cert(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 unaff_r10;
  bool bVar6;
  undefined8 uVar7;
  undefined4 local_2c;
  int local_28;
  int local_24 [2];
  
  bVar6 = param_4 != 0;
  if (bVar6) {
    unaff_r10 = 0x61011;
  }
  uVar4 = 0x61010;
  if (!bVar6) {
    uVar4 = 0x60010;
  }
  uVar1 = 0x61012;
  if (!bVar6) {
    unaff_r10 = 0x60011;
    uVar1 = 0x60012;
  }
  if (param_5 == 0) {
    uVar7 = X509_get0_pubkey(param_3);
    uVar4 = 0xffffffff;
    if ((int)uVar7 != 0) {
      uVar4 = EVP_PKEY_security_bits((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0xffffffff);
    }
    if (param_1 == 0) {
      iVar2 = ssl_ctx_security(param_2,unaff_r10,uVar4,0,param_3);
    }
    else {
      iVar2 = ssl_security(param_1,unaff_r10,uVar4,0);
    }
    if (iVar2 == 0) {
      return 0x18d;
    }
  }
  else {
    uVar7 = X509_get0_pubkey(param_3);
    uVar5 = 0xffffffff;
    if ((int)uVar7 != 0) {
      uVar5 = EVP_PKEY_security_bits((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0xffffffff);
    }
    if (param_1 == 0) {
      iVar2 = ssl_ctx_security(param_2,uVar4,uVar5,0,param_3);
    }
    else {
      iVar2 = ssl_security(param_1,uVar4,uVar5,0);
    }
    if (iVar2 == 0) {
      return 399;
    }
  }
  uVar3 = X509_get_extension_flags(param_3);
  if ((uVar3 & 0x2000) != 0) {
    return 1;
  }
  iVar2 = X509_get_signature_info(param_3,&local_28,local_24,&local_2c,0);
  if (iVar2 == 0) {
    local_2c = 0xffffffff;
  }
  if (local_28 == 0) {
    local_28 = local_24[0];
  }
  if (param_1 == 0) {
    iVar2 = ssl_ctx_security(param_2,uVar1,local_2c,local_28,param_3);
  }
  else {
    iVar2 = ssl_security(param_1);
  }
  if (iVar2 == 0) {
    uVar4 = 0x18e;
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}

