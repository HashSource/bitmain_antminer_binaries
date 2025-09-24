
undefined4 ecx_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  ASN1_OBJECT *aobj;
  int iVar1;
  int iVar2;
  uchar *local_2c;
  ASN1_OCTET_STRING local_28;
  
  local_2c = (uchar *)0x0;
  if ((*(int *)(param_2 + 0x18) != 0) &&
     (local_28.data = *(uchar **)(*(int *)(param_2 + 0x18) + 0x3c), local_28.data != (uchar *)0x0))
  {
    iVar2 = **(int **)(param_2 + 0xc);
    if (iVar2 == 0x40a || iVar2 == 0x43f) {
      local_28.length = 0x20;
    }
    else if (iVar2 == 0x40b) {
      local_28.length = 0x38;
    }
    else {
      local_28.length = 0x39;
    }
    local_28.flags = 0;
    iVar2 = i2d_ASN1_OCTET_STRING(&local_28,&local_2c);
    if (iVar2 < 0) {
      iVar2 = 0xd8;
    }
    else {
      aobj = OBJ_nid2obj(**(int **)(param_2 + 0xc));
      iVar1 = PKCS8_pkey_set0(param_1,aobj,0,-1,(void *)0x0,local_2c,iVar2);
      if (iVar1 != 0) {
        return 1;
      }
      CRYPTO_clear_free(local_2c,iVar2,"crypto/ec/ecx_meth.c",0xde);
      iVar2 = 0xdf;
    }
    ERR_put_error(0x10,0x10b,0x41,"crypto/ec/ecx_meth.c",iVar2);
    return 0;
  }
  ERR_put_error(0x10,0x10b,0x7b,"crypto/ec/ecx_meth.c",0xce);
  return 0;
}

