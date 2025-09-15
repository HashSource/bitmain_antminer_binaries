
int cca_rsa_verify(int param_1,uchar *param_2,int param_3,undefined4 param_4,undefined4 param_5,
                  RSA *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  int local_80;
  uint local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  uchar *local_64;
  undefined1 auStack_60 [8];
  undefined4 local_58;
  undefined4 uStack_54;
  X509_SIG local_50;
  ASN1_TYPE local_48;
  X509_ALGOR local_40;
  ASN1_OCTET_STRING local_38;
  
  local_70 = 1;
  local_58 = 0x53434b50;
  uStack_54 = 0x312e312d;
  local_78 = param_5;
  local_74 = 0;
  puVar1 = (undefined4 *)RSA_get_ex_data(param_6,hndidx);
  local_68 = 0x24;
  local_6c = *puVar1;
  if (param_1 == 4 || param_1 == 0x40) {
    local_50.algor = &local_40;
    local_40.algorithm = OBJ_nid2obj(param_1);
    if (local_40.algorithm == (ASN1_OBJECT *)0x0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CCA4758_lib_error_code,0x6a,0x6d,"e_4758cca.c",0x280);
      return 0;
    }
    if ((local_40.algorithm)->length == 0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CCA4758_lib_error_code,0x6a,0x65,"e_4758cca.c",0x286);
      return 0;
    }
    local_40.parameter = &local_48;
    local_50.digest = &local_38;
    local_48.value.ptr = (char *)0x0;
    local_48.type = 5;
    local_38.length = param_3;
    local_38.data = param_2;
    local_68 = i2d_X509_SIG(&local_50,(uchar **)0x0);
  }
  iVar2 = RSA_size(param_6);
  if (iVar2 < local_68 + -1) {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    iVar2 = 0x299;
LAB_000d8cc8:
    ERR_put_error(CCA4758_lib_error_code,0x6a,0x6b,"e_4758cca.c",iVar2);
    return 0;
  }
  if (param_1 == 0x40) {
    param_2 = (uchar *)CRYPTO_malloc(iVar2 + 1,"e_4758cca.c",0x2b7);
    if (param_2 == (uchar *)0x0) {
      local_64 = param_2;
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x2b9;
LAB_000d8cfc:
      ERR_put_error(CCA4758_lib_error_code,0x6a,0x41,"e_4758cca.c",iVar2);
      return 0;
    }
  }
  else {
    if (param_1 == 0x72) {
      if (param_3 != 0x24) {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = ERR_get_next_error_library();
        }
        iVar2 = 0x2a1;
        goto LAB_000d8cc8;
      }
      local_68 = 0x24;
      goto LAB_000d8c46;
    }
    if (param_1 != 4) {
      return 0;
    }
    param_2 = (uchar *)CRYPTO_malloc(iVar2 + 1,"e_4758cca.c",0x2ab);
    if (param_2 == (uchar *)0x0) {
      local_64 = param_2;
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x2ad;
      goto LAB_000d8cfc;
    }
  }
  local_64 = param_2;
  i2d_X509_SIG(&local_50,&local_64);
LAB_000d8c46:
  (*digitalSignatureVerify)
            (&local_80,&local_7c,&local_74,auStack_60,&local_70,&local_58,&local_6c,puVar1 + 1,
             &local_68,param_2,&local_78,param_4);
  if (param_1 == 4 || param_1 == 0x40) {
    OPENSSL_cleanse(param_2,iVar2 + 1);
    CRYPTO_free(param_2);
  }
  if (local_80 != 0) {
    return 0;
  }
  if (1 < local_7c) {
    return 0;
  }
  return 1 - local_7c;
}

