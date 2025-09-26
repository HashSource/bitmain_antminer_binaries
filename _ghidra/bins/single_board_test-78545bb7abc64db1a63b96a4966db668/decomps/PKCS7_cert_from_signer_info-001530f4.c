
X509 * PKCS7_cert_from_signer_info(PKCS7 *p7,PKCS7_SIGNER_INFO *si)

{
  int iVar1;
  X509 *pXVar2;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (iVar1 == 0x16) {
    pXVar2 = X509_find_by_issuer_and_serial
                       (((p7->d).sign)->cert,si->issuer_and_serial->issuer,
                        si->issuer_and_serial->serial);
    return pXVar2;
  }
  return (X509 *)0x0;
}

