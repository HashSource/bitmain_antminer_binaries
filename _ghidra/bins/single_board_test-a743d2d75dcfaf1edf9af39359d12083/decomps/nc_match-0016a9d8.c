
int nc_match(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  X509_NAME *pXVar9;
  X509_NAME *pXVar10;
  char *pcVar11;
  
  iVar8 = 0;
  for (iVar7 = 0; iVar2 = sk_num((_STACK *)*param_2), iVar7 < iVar2; iVar7 = iVar7 + 1) {
    puVar3 = (undefined4 *)sk_value((_STACK *)*param_2,iVar7);
    piVar5 = (int *)*puVar3;
    iVar2 = *param_1;
    if (iVar2 != *piVar5) goto LAB_0016a9e6;
    if (puVar3[1] != 0) {
      return 0x31;
    }
    if (puVar3[2] != 0) {
      return 0x31;
    }
    if (iVar8 == 2) goto LAB_0016aa3e;
    if (iVar8 == 0) {
      iVar8 = 1;
    }
    switch(iVar2) {
    case 1:
      iVar2 = nc_email(param_1[1],piVar5[1]);
      goto joined_r0x0016aa3c;
    case 2:
      pcVar4 = (char *)((int *)piVar5[1])[2];
      pcVar11 = (char *)((int *)param_1[1])[2];
      cVar1 = *pcVar4;
      if (cVar1 == '\0') goto LAB_0016aa3e;
      iVar2 = *(int *)param_1[1];
      iVar6 = *(int *)piVar5[1];
      if (((iVar2 <= iVar6) || (pcVar11 = pcVar11 + (iVar2 - iVar6), cVar1 == '.')) ||
         (pcVar11[-1] == '.')) {
        iVar2 = strcasecmp(pcVar4,pcVar11);
        goto joined_r0x0016aac2;
      }
      break;
    default:
      goto switchD_0016aa24_caseD_3;
    case 4:
      pXVar9 = (X509_NAME *)param_1[1];
      pXVar10 = (X509_NAME *)piVar5[1];
      if ((pXVar9->modified != 0) && (iVar2 = i2d_X509_NAME(pXVar9,(uchar **)0x0), iVar2 < 0)) {
        return 0x11;
      }
      if ((pXVar10->modified != 0) && (iVar2 = i2d_X509_NAME(pXVar10,(uchar **)0x0), iVar2 < 0)) {
        return 0x11;
      }
      if (pXVar10->canon_enclen <= pXVar9->canon_enclen) {
        iVar2 = memcmp(pXVar10->canon_enc,pXVar9->canon_enc,pXVar10->canon_enclen);
joined_r0x0016aac2:
        if (iVar2 == 0) goto LAB_0016aa3e;
      }
      break;
    case 6:
      iVar2 = nc_uri(param_1[1],piVar5[1],piVar5,iVar2 + -1,param_4);
joined_r0x0016aa3c:
      if (iVar2 == 0) {
LAB_0016aa3e:
        iVar8 = 2;
      }
      else if (iVar2 != 0x2f) {
        return iVar2;
      }
    }
LAB_0016a9e6:
  }
  if (iVar8 == 1) {
    return 0x2f;
  }
  iVar7 = 0;
  do {
    iVar8 = sk_num((_STACK *)param_2[1]);
    if (iVar8 <= iVar7) {
      return 0;
    }
    puVar3 = (undefined4 *)sk_value((_STACK *)param_2[1],iVar7);
    piVar5 = (int *)*puVar3;
    if (*param_1 != *piVar5) goto LAB_0016aae6;
    if ((puVar3[1] != 0) || (puVar3[2] != 0)) {
      return 0x31;
    }
    switch(*param_1) {
    case 1:
      iVar8 = nc_email(param_1[1],piVar5[1]);
      goto LAB_0016aadc;
    case 2:
      pcVar4 = (char *)((int *)piVar5[1])[2];
      pcVar11 = (char *)((int *)param_1[1])[2];
      cVar1 = *pcVar4;
      if (cVar1 == '\0') {
        return 0x30;
      }
      iVar8 = *(int *)param_1[1];
      iVar2 = *(int *)piVar5[1];
      if (((iVar8 <= iVar2) || (pcVar11 = pcVar11 + (iVar8 - iVar2), cVar1 == '.')) ||
         (pcVar11[-1] == '.')) {
        iVar8 = strcasecmp(pcVar4,pcVar11);
joined_r0x0016ab5e:
        if (iVar8 == 0) {
          return 0x30;
        }
      }
      break;
    default:
switchD_0016aa24_caseD_3:
      return 0x33;
    case 4:
      pXVar9 = (X509_NAME *)param_1[1];
      pXVar10 = (X509_NAME *)piVar5[1];
      if (((pXVar9->modified != 0) && (iVar8 = i2d_X509_NAME(pXVar9,(uchar **)0x0), iVar8 < 0)) ||
         ((pXVar10->modified != 0 && (iVar8 = i2d_X509_NAME(pXVar10,(uchar **)0x0), iVar8 < 0)))) {
        return 0x11;
      }
      if (pXVar10->canon_enclen <= pXVar9->canon_enclen) {
        iVar8 = memcmp(pXVar10->canon_enc,pXVar9->canon_enc,pXVar10->canon_enclen);
        goto joined_r0x0016ab5e;
      }
      break;
    case 6:
      iVar8 = nc_uri(param_1[1],piVar5[1]);
LAB_0016aadc:
      if (iVar8 == 0) {
        return 0x30;
      }
      if (iVar8 != 0x2f) {
        return iVar8;
      }
    }
LAB_0016aae6:
    iVar7 = iVar7 + 1;
  } while( true );
}

