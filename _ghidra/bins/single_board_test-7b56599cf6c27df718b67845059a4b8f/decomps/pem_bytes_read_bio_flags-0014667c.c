
undefined4
pem_bytes_read_bio_flags
          (undefined4 *param_1,long *param_2,undefined4 *param_3,char *param_4,undefined4 param_5,
          undefined1 *param_6,void *param_7,uint param_8)

{
  char *str;
  int iVar1;
  int iVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  ulong uVar4;
  uint uVar5;
  bool bVar6;
  char *pcVar7;
  undefined4 uVar8;
  char cVar9;
  char *local_4c;
  char *local_48;
  uchar *local_44;
  long local_40;
  EVP_CIPHER_INFO local_3c;
  
  local_4c = (char *)0x0;
  uVar5 = param_8 & 1;
  local_48 = (char *)0x0;
  local_44 = (uchar *)0x0;
  local_40 = 0;
  pcVar7 = (char *)0x0;
LAB_001466be:
  while( true ) {
    if (uVar5 == 0) {
      CRYPTO_free(pcVar7);
      CRYPTO_free(local_48);
      CRYPTO_free(local_44);
    }
    else {
      CRYPTO_secure_clear_free(pcVar7,0,"crypto/pem/pem_lib.c",0xdd);
      CRYPTO_secure_clear_free(local_48,0,"crypto/pem/pem_lib.c",0xdd);
      CRYPTO_secure_clear_free(local_44,local_40,"crypto/pem/pem_lib.c",0xdd);
    }
    iVar1 = PEM_read_bio_ex(param_5,&local_4c,&local_48,&local_44,&local_40,param_8);
    str = local_4c;
    if (iVar1 == 0) {
      uVar4 = ERR_peek_error();
      if ((uVar4 & 0xfff) == 0x6c) {
        ERR_add_error_data(2,"Expecting: ",param_4);
        return 0;
      }
      return 0;
    }
    iVar1 = strcmp(local_4c,param_4);
    if (iVar1 == 0) goto LAB_0014673a;
    iVar1 = strcmp(param_4,"ANY PRIVATE KEY");
    if (iVar1 != 0) break;
    iVar1 = strcmp(str,"ENCRYPTED PRIVATE KEY");
    if ((iVar1 == 0) || (iVar1 = strcmp(str,"PRIVATE KEY"), iVar1 == 0)) goto LAB_0014673a;
    iVar1 = pem_check_suffix(str,"PRIVATE KEY");
    pcVar7 = local_4c;
    if ((0 < iVar1) &&
       (pEVar3 = EVP_PKEY_asn1_find_str((ENGINE **)0x0,str,iVar1), pcVar7 = local_4c,
       pEVar3 != (EVP_PKEY_ASN1_METHOD *)0x0)) {
      iVar1 = *(int *)(pEVar3 + 0x60);
joined_r0x00146876:
      local_4c = pcVar7;
      if (iVar1 != 0) goto LAB_0014673a;
    }
  }
  iVar1 = strcmp(param_4,"PARAMETERS");
  if (iVar1 == 0) {
    iVar1 = pem_check_suffix(str,"PARAMETERS");
    pcVar7 = local_4c;
    if ((0 < iVar1) &&
       (pEVar3 = EVP_PKEY_asn1_find_str((ENGINE **)&local_3c,str,iVar1), pcVar7 = local_4c,
       pEVar3 != (EVP_PKEY_ASN1_METHOD *)0x0)) {
      iVar1 = *(int *)(pEVar3 + 0x3c);
      ENGINE_finish((ENGINE *)local_3c.cipher);
      pcVar7 = local_4c;
      goto joined_r0x00146876;
    }
    goto LAB_001466be;
  }
  iVar1 = strcmp(str,"X9.42 DH PARAMETERS");
  if ((((iVar1 == 0) && (iVar1 = strcmp(param_4,"DH PARAMETERS"), iVar1 == 0)) ||
      ((iVar1 = strcmp(str,"X509 CERTIFICATE"), iVar1 == 0 &&
       (iVar2 = strcmp(param_4,"CERTIFICATE"), iVar2 == 0)))) ||
     ((iVar2 = strcmp(str,"NEW CERTIFICATE REQUEST"), iVar2 == 0 &&
      (iVar2 = strcmp(param_4,"CERTIFICATE REQUEST"), iVar2 == 0)))) goto LAB_0014673a;
  iVar2 = strcmp(str,"CERTIFICATE");
  pcVar7 = str;
  if (iVar2 == 0) {
    iVar1 = strcmp(param_4,"TRUSTED CERTIFICATE");
    if ((iVar1 == 0) || (iVar1 = strcmp(param_4,"PKCS7"), iVar1 == 0)) goto LAB_0014673a;
    if (*param_4 != 'C') goto LAB_001466be;
    cVar9 = param_4[1];
    if (((cVar9 == 'M') && (param_4[2] == 'S')) && (param_4[3] == '\0')) goto LAB_0014673a;
    iVar1 = strcmp(str,"PKCS7");
    if (iVar1 != 0) goto LAB_001466be;
  }
  else {
    if (((iVar1 == 0) && (iVar1 = strcmp(param_4,"TRUSTED CERTIFICATE"), iVar1 == 0)) ||
       ((iVar1 = strcmp(str,"PKCS #7 SIGNED DATA"), iVar1 == 0 &&
        (iVar1 = strcmp(param_4,"PKCS7"), iVar1 == 0)))) goto LAB_0014673a;
    iVar1 = strcmp(str,"PKCS7");
    if ((iVar1 != 0) || (*param_4 != 'C')) goto LAB_001466be;
    cVar9 = param_4[1];
  }
  if (((cVar9 != 'M') || (param_4[2] != 'S')) || (param_4[3] != '\0')) goto LAB_001466be;
LAB_0014673a:
  iVar1 = PEM_get_EVP_CIPHER_INFO(local_48,&local_3c);
  if ((iVar1 == 0) ||
     (iVar1 = PEM_do_header(&local_3c,local_44,&local_40,param_6,param_7), iVar1 == 0)) {
    bVar6 = false;
LAB_0014674a:
    if (uVar5 != 0) {
      CRYPTO_secure_clear_free(local_4c,0,"crypto/pem/pem_lib.c",0xdd);
LAB_00146970:
      CRYPTO_secure_clear_free(local_48,0,"crypto/pem/pem_lib.c",0xdd);
      goto LAB_0014676a;
    }
    CRYPTO_free(local_4c);
  }
  else {
    *param_1 = local_44;
    *param_2 = local_40;
    if (param_3 == (undefined4 *)0x0) {
      bVar6 = true;
      goto LAB_0014674a;
    }
    bVar6 = true;
    *param_3 = local_4c;
    if (uVar5 != 0) goto LAB_00146970;
  }
  CRYPTO_free(local_48);
LAB_0014676a:
  if (bVar6) {
    uVar8 = 1;
  }
  else {
    if (uVar5 == 0) {
      CRYPTO_free(local_44);
      return 0;
    }
    CRYPTO_secure_clear_free(local_44,local_40,"crypto/pem/pem_lib.c",0xdd);
    uVar8 = 0;
  }
  return uVar8;
}

