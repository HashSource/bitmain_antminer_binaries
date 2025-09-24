
undefined4 i2r_ADMISSION_SYNTAX(undefined4 param_1,int *param_2,BIO *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  ASN1_STRING *v;
  int iVar5;
  ASN1_OBJECT *o;
  char *pcVar6;
  undefined4 uVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  int local_c0;
  int local_bc;
  char *local_b0;
  char acStack_a8 [132];
  
  if ((*param_2 == 0) ||
     ((((iVar1 = BIO_printf(param_3,"%*sadmissionAuthority:\n",param_4,""), 0 < iVar1 &&
        (iVar1 = BIO_printf(param_3,"%*s  ",param_4,""), 0 < iVar1)) &&
       (iVar1 = GENERAL_NAME_print(param_3,(GENERAL_NAME *)*param_2), 0 < iVar1)) &&
      (iVar1 = BIO_printf(param_3,"\n"), 0 < iVar1)))) {
    local_bc = 0;
    local_b0 = "";
    while (iVar1 = OPENSSL_sk_num(param_2[1]), local_bc < iVar1) {
      iVar9 = local_bc + 1;
      piVar2 = (int *)OPENSSL_sk_value(param_2[1],local_bc);
      iVar1 = iVar9;
      iVar3 = BIO_printf(param_3,"%*sEntry %0d:\n",param_4,"",iVar9);
      if ((iVar3 < 1) ||
         (((*piVar2 != 0 &&
           (((iVar3 = BIO_printf(param_3,"%*s  admissionAuthority:\n",param_4,"",iVar1), iVar3 < 1
             || (iVar1 = BIO_printf(param_3,"%*s    ",param_4,"",iVar1), iVar1 < 1)) ||
            ((iVar1 = GENERAL_NAME_print(param_3,(GENERAL_NAME *)*piVar2), iVar1 < 1 ||
             (iVar1 = BIO_printf(param_3,"\n"), iVar1 < 1)))))) ||
          ((piVar2[1] != 0 &&
           (iVar1 = i2r_NAMING_AUTHORITY_isra_0(piVar2[1],param_3,param_4), iVar1 < 1))))))
      goto LAB_001c733a;
      local_c0 = 0;
      while (iVar1 = OPENSSL_sk_num(piVar2[2]), local_bc = iVar9, local_c0 < iVar1) {
        iVar10 = local_c0 + 1;
        piVar4 = (int *)OPENSSL_sk_value(piVar2[2],local_c0);
        iVar1 = iVar10;
        iVar3 = BIO_printf(param_3,"%*s  Profession Info Entry %0d:\n",param_4,"",iVar10);
        if (((iVar3 < 1) ||
            ((piVar4[3] != 0 &&
             (((iVar3 = BIO_printf(param_3,"%*s    registrationNumber: ",param_4,"",iVar1),
               iVar3 < 1 || (iVar3 = ASN1_STRING_print(param_3,(ASN1_STRING *)piVar4[3]), iVar3 < 1)
               ) || (iVar3 = BIO_printf(param_3,"\n"), iVar3 < 1)))))) ||
           ((*piVar4 != 0 &&
            (iVar3 = i2r_NAMING_AUTHORITY_isra_0(*piVar4,param_3,param_4 + 2), iVar3 < 1))))
        goto LAB_001c733a;
        if (piVar4[1] != 0) {
          iVar3 = BIO_printf(param_3,"%*s    Info Entries:\n",param_4,"",iVar1);
          if (iVar3 < 1) goto LAB_001c733a;
          iVar3 = 0;
          while( true ) {
            iVar5 = OPENSSL_sk_num(piVar4[1]);
            if (iVar5 <= iVar3) break;
            v = (ASN1_STRING *)OPENSSL_sk_value(piVar4[1],iVar3);
            iVar5 = BIO_printf(param_3,"%*s      ",param_4,"");
            if (((iVar5 < 1) || (iVar5 = ASN1_STRING_print(param_3,v), iVar5 < 1)) ||
               (iVar5 = BIO_printf(param_3,"\n"), iVar3 = iVar3 + 1, iVar5 < 1)) goto LAB_001c733a;
          }
        }
        local_c0 = iVar10;
        if (piVar4[2] != 0) {
          iVar1 = BIO_printf(param_3,"%*s    Profession OIDs:\n",param_4,"",iVar1);
          if (iVar1 < 1) goto LAB_001c733a;
          iVar1 = 0;
          while( true ) {
            iVar3 = OPENSSL_sk_num(piVar4[2]);
            if (iVar3 <= iVar1) break;
            o = (ASN1_OBJECT *)OPENSSL_sk_value(piVar4[2],iVar1);
            iVar3 = OBJ_obj2nid(o);
            pcVar6 = OBJ_nid2ln(iVar3);
            OBJ_obj2txt(acStack_a8,0x80,o,1);
            pcVar8 = local_b0;
            pcVar11 = local_b0;
            pcVar12 = local_b0;
            if (pcVar6 != (char *)0x0) {
              pcVar8 = ")";
              pcVar11 = " (";
              pcVar12 = pcVar6;
            }
            iVar1 = iVar1 + 1;
            iVar3 = BIO_printf(param_3,"%*s      %s%s%s%s\n",param_4,"",pcVar12,pcVar11,acStack_a8,
                               pcVar8);
            if (iVar3 < 1) goto LAB_001c733a;
          }
        }
      }
    }
    uVar7 = 1;
  }
  else {
LAB_001c733a:
    uVar7 = 0xffffffff;
  }
  return uVar7;
}

