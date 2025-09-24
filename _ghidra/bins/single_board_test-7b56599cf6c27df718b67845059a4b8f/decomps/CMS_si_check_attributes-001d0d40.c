
undefined4 CMS_si_check_attributes(CMS_SignerInfo *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  X509_ATTRIBUTE *pXVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int nid;
  stack_st_X509_ATTRIBUTE *psVar8;
  
  iVar1 = CMS_signed_get_attr_count(param_1);
  piVar6 = &cms_attribute_properties;
  iVar2 = CMS_unsigned_get_attr_count(param_1);
  do {
    while( true ) {
      nid = *piVar6;
      psVar8 = *(stack_st_X509_ATTRIBUTE **)(param_1 + 0xc);
      uVar7 = piVar6[1];
      iVar3 = X509at_get_attr_by_NID(psVar8,nid,-1);
      if ((iVar3 < 0) || (pXVar4 = X509at_get_attr(psVar8,iVar3), pXVar4 == (X509_ATTRIBUTE *)0x0))
      {
        if ((0 < iVar1) && ((uVar7 & 0x11) == 0x11)) goto LAB_001d0d98;
      }
      else {
        iVar5 = X509_ATTRIBUTE_count(pXVar4);
        if ((-1 < (int)(uVar7 << 0x1f)) ||
           ((((int)(uVar7 << 0x1a) < 0 &&
             (iVar3 = X509at_get_attr_by_NID(psVar8,nid,iVar3), -1 < iVar3)) &&
            (pXVar4 = X509at_get_attr(psVar8,iVar3), pXVar4 != (X509_ATTRIBUTE *)0x0))))
        goto LAB_001d0d98;
        if ((int)(uVar7 << 0x19) < 0) {
          if (iVar5 != 1) goto LAB_001d0d98;
        }
        else if (iVar5 == 0) goto LAB_001d0d98;
      }
      psVar8 = *(stack_st_X509_ATTRIBUTE **)(param_1 + 0x18);
      iVar3 = X509at_get_attr_by_NID(psVar8,nid,-1);
      if ((-1 < iVar3) && (pXVar4 = X509at_get_attr(psVar8,iVar3), pXVar4 != (X509_ATTRIBUTE *)0x0))
      break;
      if (iVar2 < 1) goto LAB_001d0df8;
      if ((uVar7 & 0x12) == 0x12) goto LAB_001d0d98;
      piVar6 = piVar6 + 2;
      if (piVar6 == (int *)"crypto/cms/cms_att.c") {
        return 1;
      }
    }
    iVar5 = X509_ATTRIBUTE_count(pXVar4);
    if ((-1 < (int)(uVar7 << 0x1e)) ||
       ((((int)(uVar7 << 0x1a) < 0 && (iVar3 = X509at_get_attr_by_NID(psVar8,nid,iVar3), -1 < iVar3)
         ) && (pXVar4 = X509at_get_attr(psVar8,iVar3), pXVar4 != (X509_ATTRIBUTE *)0x0)))) {
LAB_001d0d98:
      ERR_put_error(0x2e,0xb7,0xa1,"crypto/cms/cms_att.c",0x117);
      return 0;
    }
    if ((int)(uVar7 << 0x19) < 0) {
      if (iVar5 != 1) goto LAB_001d0d98;
LAB_001d0df8:
      piVar6 = piVar6 + 2;
      if (piVar6 == (int *)"crypto/cms/cms_att.c") {
        return 1;
      }
    }
    else {
      if (iVar5 == 0) goto LAB_001d0d98;
      piVar6 = piVar6 + 2;
      if (piVar6 == (int *)"crypto/cms/cms_att.c") {
        return 1;
      }
    }
  } while( true );
}

