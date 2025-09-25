
EVP_CIPHER_CTX *
PKCS5_pbe2_set_scrypt
          (EVP_CIPHER *param_1,void *param_2,int param_3,void *param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
          undefined4 param_10)

{
  int iVar1;
  EVP_CIPHER_CTX *a;
  ASN1_OBJECT *pAVar2;
  ASN1_TYPE *pAVar3;
  int iVar4;
  size_t __n;
  EVP_CIPHER_CTX *ctx;
  int *piVar5;
  EVP_CIPHER *pEVar6;
  EVP_CIPHER_CTX *a_00;
  ASN1_INTEGER *pAVar7;
  X509_ALGOR *pXVar8;
  undefined8 uVar9;
  uchar auStack_38 [20];
  
  if (param_1 == (EVP_CIPHER *)0x0) {
    iVar4 = 0x34;
    iVar1 = 0x43;
  }
  else {
    iVar1 = EVP_PBE_scrypt(0,0,0,0,param_5,param_6,param_7,param_8,param_9,param_10,0,0,0,0);
    if (iVar1 == 0) {
      iVar4 = 0x3a;
      iVar1 = 0xe3;
    }
    else {
      iVar1 = EVP_CIPHER_type(param_1);
      if (iVar1 != 0) {
        a = (EVP_CIPHER_CTX *)PBE2PARAM_new();
        if (a == (EVP_CIPHER_CTX *)0x0) {
LAB_001c7502:
          a_00 = (EVP_CIPHER_CTX *)0x0;
        }
        else {
          pXVar8 = (X509_ALGOR *)a->engine;
          pAVar2 = OBJ_nid2obj(iVar1);
          pXVar8->algorithm = pAVar2;
          pAVar3 = ASN1_TYPE_new();
          pXVar8->parameter = pAVar3;
          if (pAVar3 == (ASN1_TYPE *)0x0) goto LAB_001c7502;
          iVar4 = EVP_CIPHER_iv_length(param_1);
          if (iVar4 != 0) {
            if (param_4 == (void *)0x0) {
              iVar4 = EVP_CIPHER_iv_length(param_1);
              iVar4 = RAND_bytes(auStack_38,iVar4);
              if (iVar4 < 1) {
                ctx = (EVP_CIPHER_CTX *)0x0;
                a_00 = (EVP_CIPHER_CTX *)0x0;
                goto LAB_001c74c4;
              }
            }
            else {
              __n = EVP_CIPHER_iv_length(param_1);
              memcpy(auStack_38,param_4,__n);
            }
          }
          ctx = EVP_CIPHER_CTX_new();
          if (ctx == (EVP_CIPHER_CTX *)0x0) goto LAB_001c7502;
          iVar4 = EVP_CipherInit_ex(ctx,param_1,(ENGINE *)0x0,(uchar *)0x0,auStack_38,0);
          if (iVar4 == 0) {
            a_00 = (EVP_CIPHER_CTX *)0x0;
            goto LAB_001c74c4;
          }
          iVar4 = EVP_CIPHER_param_to_asn1(ctx,pXVar8->parameter);
          if (iVar4 < 1) {
            ERR_put_error(0xd,0xe7,0x72,"crypto/asn1/p5_scrypt.c",0x62);
            a_00 = (EVP_CIPHER_CTX *)0x0;
            goto LAB_001c74c4;
          }
          EVP_CIPHER_CTX_free(ctx);
          if (iVar1 == 0x25) {
            iVar1 = EVP_CIPHER_key_length(param_1);
          }
          else {
            iVar1 = 0;
          }
          X509_ALGOR_free((X509_ALGOR *)a->cipher);
          piVar5 = (int *)SCRYPT_PARAMS_new();
          if (piVar5 == (int *)0x0) {
LAB_001c748a:
            pEVar6 = (EVP_CIPHER *)0x0;
LAB_001c748c:
            ERR_put_error(0xd,0xe8,0x41,"crypto/asn1/p5_scrypt.c",0xcd);
LAB_001c749e:
            SCRYPT_PARAMS_free(piVar5);
            X509_ALGOR_free((X509_ALGOR *)pEVar6);
            a_00 = (EVP_CIPHER_CTX *)0x0;
            a->cipher = (EVP_CIPHER *)0x0;
          }
          else {
            if (param_3 == 0) {
              param_3 = 8;
            }
            iVar4 = ASN1_STRING_set((ASN1_STRING *)*piVar5,param_2,param_3);
            if (iVar4 == 0) goto LAB_001c748a;
            if ((param_2 == (void *)0x0) &&
               (iVar4 = RAND_bytes(*(uchar **)(*piVar5 + 8),param_3), iVar4 < 1)) {
              pEVar6 = (EVP_CIPHER *)0x0;
              goto LAB_001c749e;
            }
            uVar9 = ASN1_INTEGER_set_uint64(piVar5[1]);
            if ((((int)uVar9 == 0) ||
                (uVar9 = ASN1_INTEGER_set_uint64
                                   (piVar5[2],(int)((ulonglong)uVar9 >> 0x20),param_7,param_8),
                (int)uVar9 == 0)) ||
               (iVar4 = ASN1_INTEGER_set_uint64
                                  (piVar5[3],(int)((ulonglong)uVar9 >> 0x20),param_9,param_10),
               iVar4 == 0)) goto LAB_001c748a;
            if (iVar1 != 0) {
              pAVar7 = ASN1_INTEGER_new();
              piVar5[4] = (int)pAVar7;
              if ((pAVar7 == (ASN1_INTEGER *)0x0) || (iVar1 = ASN1_INTEGER_set_int64(), iVar1 == 0))
              goto LAB_001c748a;
            }
            pEVar6 = (EVP_CIPHER *)X509_ALGOR_new();
            if (pEVar6 == (EVP_CIPHER *)0x0) goto LAB_001c748a;
            pAVar2 = OBJ_nid2obj(0x3cd);
            pEVar6->nid = (int)pAVar2;
            iVar1 = ASN1_TYPE_pack_sequence(&SCRYPT_PARAMS_it,piVar5,&pEVar6->block_size);
            if (iVar1 == 0) goto LAB_001c748c;
            SCRYPT_PARAMS_free(piVar5);
            a->cipher = pEVar6;
            a_00 = (EVP_CIPHER_CTX *)X509_ALGOR_new();
            if (a_00 == (EVP_CIPHER_CTX *)0x0) goto LAB_001c7502;
            pEVar6 = (EVP_CIPHER *)OBJ_nid2obj(0xa1);
            a_00->cipher = pEVar6;
            iVar1 = ASN1_TYPE_pack_sequence(PBE2PARAM_it,a,&a_00->engine);
            if (iVar1 != 0) {
              PBE2PARAM_free((PBE2PARAM *)a);
              return a_00;
            }
          }
        }
        ERR_put_error(0xd,0xe7,0x41,"crypto/asn1/p5_scrypt.c",0x8a);
        ctx = (EVP_CIPHER_CTX *)0x0;
        goto LAB_001c74c4;
      }
      iVar4 = 0x41;
      iVar1 = 0x6c;
    }
  }
  a = (EVP_CIPHER_CTX *)0x0;
  ERR_put_error(0xd,0xe7,iVar1,"crypto/asn1/p5_scrypt.c",iVar4);
  ctx = a;
  a_00 = a;
LAB_001c74c4:
  PBE2PARAM_free((PBE2PARAM *)a);
  X509_ALGOR_free((X509_ALGOR *)a_00);
  EVP_CIPHER_CTX_free(ctx);
  return (EVP_CIPHER_CTX *)0x0;
}

