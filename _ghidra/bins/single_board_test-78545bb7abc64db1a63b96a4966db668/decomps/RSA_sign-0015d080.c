
int RSA_sign(int type,uchar *m,uint m_length,uchar *sigret,uint *siglen,RSA *rsa)

{
  int iVar1;
  _union_263 flen;
  uint uVar2;
  uint *extraout_r3;
  uint *puVar3;
  _union_263 _Var4;
  _union_263 _Var5;
  _union_263 local_4c;
  X509_SIG local_48;
  X509_ALGOR local_40;
  ASN1_TYPE local_38;
  ASN1_OCTET_STRING local_30;
  
  _Var4 = (_union_263)rsa->meth->rsa_sign;
  if ((_func_1768 *)_Var4.ptr != (_func_1768 *)0x0) {
    iVar1 = (*(code *)_Var4)(type,m,m_length,sigret,siglen,rsa);
    return iVar1;
  }
  if (type == 0x72) {
    if (m_length != 0x24) {
      ERR_put_error(4,0x75,0x83,"crypto/rsa/rsa_sign.c",0x58);
      return 0;
    }
    flen.boolean = 0x24;
LAB_0015d0ec:
    iVar1 = RSA_size(rsa);
    if (flen.boolean < iVar1 + -10) {
      uVar2 = RSA_private_encrypt(flen.boolean,m,sigret,rsa,1);
      puVar3 = extraout_r3;
      if (0 < (int)uVar2) {
        puVar3 = siglen;
      }
      _Var5.boolean._1_3_ = 0;
      _Var5.boolean._0_1_ = 0 < (int)uVar2;
      if (0 < (int)uVar2) {
        *puVar3 = uVar2;
      }
    }
    else {
      _Var5.ptr = (char *)0x0;
      ERR_put_error(4,0x75,0x70,"crypto/rsa/rsa_sign.c",100);
    }
  }
  else {
    local_48.algor = &local_40;
    local_4c = _Var4;
    local_40.algorithm = OBJ_nid2obj(type);
    if ((local_48.algor)->algorithm == (ASN1_OBJECT *)0x0) {
      ERR_put_error(4,0x92,0x75,"crypto/rsa/rsa_sign.c",0x2c);
    }
    else {
      iVar1 = OBJ_length();
      if (iVar1 == 0) {
        ERR_put_error(4,0x92,0x74,"crypto/rsa/rsa_sign.c",0x31);
      }
      else {
        local_38.value = _Var4;
        local_30.length = m_length;
        (local_48.algor)->parameter = &local_38;
        local_48.digest = &local_30;
        local_38.type = 5;
        local_30.data = m;
        flen.boolean = i2d_X509_SIG(&local_48,(uchar **)&local_4c.ptr);
        m = (uchar *)local_4c;
        _Var4 = local_4c;
        if (-1 < flen.boolean) goto LAB_0015d0ec;
      }
    }
    _Var5.ptr = (char *)0x0;
    flen.ptr = _Var5.ptr;
    _Var4.ptr = _Var5.ptr;
  }
  CRYPTO_clear_free(_Var4.ptr,flen.ptr,"crypto/rsa/rsa_sign.c",0x70);
  return (int)_Var5.ptr;
}

