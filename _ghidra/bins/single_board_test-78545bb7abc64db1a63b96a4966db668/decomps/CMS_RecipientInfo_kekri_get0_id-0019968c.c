
int CMS_RecipientInfo_kekri_get0_id
              (CMS_RecipientInfo *ri,X509_ALGOR **palg,ASN1_OCTET_STRING **pid,
              ASN1_GENERALIZEDTIME **pdate,ASN1_OBJECT **potherid,ASN1_TYPE **pothertype)

{
  undefined4 *puVar1;
  
  if (*(int *)ri != 2) {
    ERR_put_error(0x2e,0x89,0x7b,"crypto/cms/cms_env.c",0x24b);
    return 0;
  }
  puVar1 = *(undefined4 **)(*(int *)(ri + 4) + 4);
  if (palg != (X509_ALGOR **)0x0) {
    *palg = *(X509_ALGOR **)(*(int *)(ri + 4) + 8);
  }
  if (pid != (ASN1_OCTET_STRING **)0x0) {
    *pid = (ASN1_OCTET_STRING *)*puVar1;
  }
  if (pdate != (ASN1_GENERALIZEDTIME **)0x0) {
    *pdate = (ASN1_GENERALIZEDTIME *)puVar1[1];
  }
  if (potherid != (ASN1_OBJECT **)0x0) {
    if ((undefined4 *)puVar1[2] == (undefined4 *)0x0) {
      *potherid = (ASN1_OBJECT *)0x0;
    }
    else {
      *potherid = *(ASN1_OBJECT **)puVar1[2];
    }
  }
  if (pothertype != (ASN1_TYPE **)0x0) {
    if (puVar1[2] == 0) {
      *pothertype = (ASN1_TYPE *)0x0;
      return 1;
    }
    *pothertype = *(ASN1_TYPE **)(puVar1[2] + 4);
  }
  return 1;
}

