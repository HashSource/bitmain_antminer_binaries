
int CMS_SignerInfo_get0_signer_id
              (CMS_SignerInfo *si,ASN1_OCTET_STRING **keyid,X509_NAME **issuer,ASN1_INTEGER **sno)

{
  int iVar1;
  
  iVar1 = cms_SignerIdentifier_get0_signer_id(*(undefined4 *)(si + 4));
  return iVar1;
}

