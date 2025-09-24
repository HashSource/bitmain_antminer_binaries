
int PKCS5_v2_scrypt_keyivgen
              (EVP_CIPHER_CTX *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,int param_7)

{
  EVP_CIPHER *pEVar1;
  int *piVar2;
  size_t len;
  int iVar3;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  size_t local_68;
  int iStack_64;
  
  pEVar1 = EVP_CIPHER_CTX_cipher(param_1);
  if (pEVar1 == (EVP_CIPHER *)0x0) {
    ERR_put_error(6,0xb4,0x83,"crypto/asn1/p5_scrypt.c",0xe0);
  }
  else {
    piVar2 = (int *)ASN1_TYPE_unpack_sequence(&SCRYPT_PARAMS_it,param_4);
    if (piVar2 != (int *)0x0) {
      len = EVP_CIPHER_CTX_key_length(param_1);
      if ((piVar2[4] == 0) ||
         ((iVar3 = ASN1_INTEGER_get_uint64(&local_68), iVar3 != 0 &&
          (iStack_64 == 0 && len == local_68)))) {
        iVar3 = ASN1_INTEGER_get_uint64(&local_70,piVar2[1]);
        if ((iVar3 == 0) ||
           (((iVar3 = ASN1_INTEGER_get_uint64(&local_78,piVar2[2]), iVar3 == 0 ||
             (iVar3 = ASN1_INTEGER_get_uint64(&local_80,piVar2[3]), iVar3 == 0)) ||
            (iVar3 = EVP_PBE_scrypt(0,0,0,0,local_70,uStack_6c,local_78,uStack_74,local_80,uStack_7c
                                    ,0,0,0,0), iVar3 == 0)))) {
          iVar3 = 0;
          ERR_put_error(6,0xb4,0xab,"crypto/asn1/p5_scrypt.c",0x100);
        }
        else {
          iVar3 = EVP_PBE_scrypt(param_2,param_3,((undefined4 *)*piVar2)[2],*(undefined4 *)*piVar2,
                                 local_70,uStack_6c,local_78,uStack_74,local_80,uStack_7c,0,0,
                                 &local_68,len);
          if (iVar3 == 0) {
            iVar3 = 0;
          }
          else {
            iVar3 = EVP_CipherInit_ex(param_1,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)&local_68,
                                      (uchar *)0x0,param_7);
          }
        }
      }
      else {
        iVar3 = 0;
        ERR_put_error(6,0xb4,0x7b,"crypto/asn1/p5_scrypt.c",0xf6);
      }
      if (len != 0) {
        OPENSSL_cleanse(&local_68,len);
      }
      SCRYPT_PARAMS_free(piVar2);
      return iVar3;
    }
    ERR_put_error(6,0xb4,0x72,"crypto/asn1/p5_scrypt.c",0xe9);
  }
  SCRYPT_PARAMS_free(0);
  return 0;
}

