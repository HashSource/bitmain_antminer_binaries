
undefined4
ecd_item_verify(EVP_MD_CTX *param_1,undefined4 param_2,undefined4 param_3,X509_ALGOR *param_4,
               undefined4 param_5,EVP_PKEY *param_6)

{
  int iVar1;
  undefined4 uVar2;
  ASN1_OBJECT *local_10;
  int local_c;
  
  X509_ALGOR_get0(&local_10,&local_c,(void **)0x0,param_4);
  iVar1 = OBJ_obj2nid(local_10);
  if ((iVar1 - 0x43fU < 2) && (local_c == -1)) {
    iVar1 = EVP_DigestVerifyInit(param_1,(EVP_PKEY_CTX **)0x0,(EVP_MD *)0x0,(ENGINE *)0x0,param_6);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 2;
    }
    return uVar2;
  }
  ERR_put_error(0x10,0x10e,0x66,"crypto/ec/ecx_meth.c",0x205);
  return 0;
}

