
int CMS_set1_signers_certs(CMS_ContentInfo *cms,stack_st_X509 *certs,uint flags)

{
  int iVar1;
  int iVar2;
  CMS_SignerInfo *si;
  int iVar3;
  int *piVar4;
  X509 *pXVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    iVar1 = *(int *)(cms + 4);
    if (iVar1 != 0) {
      iVar9 = 0;
      iVar8 = 0;
      uVar10 = *(undefined4 *)(iVar1 + 0xc);
      do {
        iVar2 = OPENSSL_sk_num(*(undefined4 *)(iVar1 + 0x14));
        if (iVar2 <= iVar8) {
          return iVar9;
        }
        si = (CMS_SignerInfo *)OPENSSL_sk_value(*(undefined4 *)(iVar1 + 0x14),iVar8);
        if (*(int *)(si + 0x1c) == 0) {
          iVar2 = 0;
          do {
            iVar3 = OPENSSL_sk_num(certs);
            if (iVar3 <= iVar2) {
              if (*(int *)(si + 0x1c) != 0) goto LAB_0018dd5e;
              goto LAB_0018ddaa;
            }
            pXVar5 = (X509 *)OPENSSL_sk_value(certs,iVar2);
            iVar3 = CMS_SignerInfo_cert_cmp(si,pXVar5);
            iVar2 = iVar2 + 1;
          } while (iVar3 != 0);
          CMS_SignerInfo_set1_signer_cert(si,pXVar5);
          iVar9 = iVar9 + 1;
          if (*(int *)(si + 0x1c) == 0) {
LAB_0018ddaa:
            uVar6 = flags & 0x10;
            if ((flags & 0x10) == 0) {
              do {
                do {
                  iVar2 = OPENSSL_sk_num(uVar10);
                  uVar7 = uVar6 + 1;
                  if (iVar2 <= (int)uVar6) goto LAB_0018dd5e;
                  piVar4 = (int *)OPENSSL_sk_value(uVar10,uVar6);
                  uVar6 = uVar7;
                } while (*piVar4 != 0);
                pXVar5 = (X509 *)piVar4[1];
                iVar2 = CMS_SignerInfo_cert_cmp(si,pXVar5);
              } while (iVar2 != 0);
              CMS_SignerInfo_set1_signer_cert(si,pXVar5);
              iVar9 = iVar9 + 1;
            }
          }
        }
LAB_0018dd5e:
        iVar8 = iVar8 + 1;
      } while( true );
    }
  }
  else {
    ERR_put_error(0x2e,0x85,0x6c,"crypto/cms/cms_sd.c",0x1a);
  }
  return -1;
}

