
int CMS_add_standard_smimecap(stack_st_X509_ALGOR **smcap)

{
  char *pcVar1;
  EVP_CIPHER *pEVar2;
  int iVar3;
  EVP_MD *pEVar4;
  
  pcVar1 = OBJ_nid2sn(0x1ab);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if ((pEVar2 == (EVP_CIPHER *)0x0) || (iVar3 = CMS_add_simple_smimecap(smcap,0x1ab,-1), iVar3 != 0)
     ) {
    pcVar1 = OBJ_nid2sn(0x3d6);
    pEVar4 = EVP_get_digestbyname(pcVar1);
    if ((pEVar4 == (EVP_MD *)0x0) || (iVar3 = CMS_add_simple_smimecap(smcap,0x3d6,-1), iVar3 != 0))
    {
      pcVar1 = OBJ_nid2sn(0x3d7);
      pEVar4 = EVP_get_digestbyname(pcVar1);
      if ((pEVar4 == (EVP_MD *)0x0) || (iVar3 = CMS_add_simple_smimecap(smcap,0x3d7,-1), iVar3 != 0)
         ) {
        pcVar1 = OBJ_nid2sn(0x329);
        pEVar4 = EVP_get_digestbyname(pcVar1);
        if ((pEVar4 == (EVP_MD *)0x0) ||
           (iVar3 = CMS_add_simple_smimecap(smcap,0x329,-1), iVar3 != 0)) {
          pcVar1 = OBJ_nid2sn(0x32d);
          pEVar2 = EVP_get_cipherbyname(pcVar1);
          if ((pEVar2 == (EVP_CIPHER *)0x0) ||
             (iVar3 = CMS_add_simple_smimecap(smcap,0x32d,-1), iVar3 != 0)) {
            pcVar1 = OBJ_nid2sn(0x1a7);
            pEVar2 = EVP_get_cipherbyname(pcVar1);
            if ((pEVar2 == (EVP_CIPHER *)0x0) ||
               (iVar3 = CMS_add_simple_smimecap(smcap,0x1a7,-1), iVar3 != 0)) {
              pcVar1 = OBJ_nid2sn(0x1a3);
              pEVar2 = EVP_get_cipherbyname(pcVar1);
              if ((((pEVar2 == (EVP_CIPHER *)0x0) ||
                   (iVar3 = CMS_add_simple_smimecap(smcap,0x1a3,-1), iVar3 != 0)) &&
                  (iVar3 = cms_add_cipher_smcap(smcap,0x2c,0xffffffff), iVar3 != 0)) &&
                 (((iVar3 = cms_add_cipher_smcap(smcap,0x25,0x80), iVar3 != 0 &&
                   (iVar3 = cms_add_cipher_smcap(smcap,0x25,0x40), iVar3 != 0)) &&
                  (iVar3 = cms_add_cipher_smcap(smcap,0x1f,0xffffffff), iVar3 != 0)))) {
                iVar3 = cms_add_cipher_smcap(smcap,0x25,0x28);
                if (iVar3 != 0) {
                  iVar3 = 1;
                }
                return iVar3;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

