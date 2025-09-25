
int OCSP_basic_add1_nonce(OCSP_BASICRESP *resp,uchar *val,int len)

{
  int iVar1;
  uchar *local_24;
  int local_20 [2];
  uchar *local_18;
  
  if (len < 1) {
    len = 0x10;
  }
  local_20[0] = ASN1_object_size(0,len,4);
  if (local_20[0] < 0) {
    return 0;
  }
  local_18 = (uchar *)CRYPTO_malloc(local_20[0],"crypto/ocsp/ocsp_ext.c",0x106);
  if (local_18 == (uchar *)0x0) {
    iVar1 = 0;
  }
  else {
    local_24 = local_18;
    ASN1_put_object(&local_24,0,len,4,0);
    if (val == (uchar *)0x0) {
      iVar1 = RAND_bytes(local_24,len);
      if (iVar1 < 1) {
        iVar1 = 0;
        goto LAB_0013fd66;
      }
    }
    else {
      memcpy(local_24,val,len);
    }
    iVar1 = X509V3_add1_i2d((stack_st_X509_EXTENSION **)&resp[1].signatureAlgorithm,0x16e,local_20,0
                            ,2);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
LAB_0013fd66:
  CRYPTO_free(local_18);
  return iVar1;
}

