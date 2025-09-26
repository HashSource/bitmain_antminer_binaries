
uint rsa_pss_param_print(BIO *param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  X509_ALGOR *a;
  undefined4 *puVar4;
  
  iVar1 = BIO_indent(param_1,param_4,0x80);
  if (iVar1 != 0) {
    if (param_2 == 0) {
      if (param_3 == (undefined4 *)0x0) {
        iVar1 = BIO_puts(param_1,"(INVALID PSS PARAMETERS)\n");
        return (uint)(0 < iVar1);
      }
      iVar1 = BIO_puts(param_1,"\n");
      if (0 < iVar1) goto LAB_00157b98;
    }
    else {
      if (param_3 == (undefined4 *)0x0) {
        iVar1 = BIO_puts(param_1,"No PSS parameter restrictions\n");
        return (uint)(0 < iVar1);
      }
      iVar1 = BIO_puts(param_1,"PSS parameter restrictions:");
      if (iVar1 < 1) {
        return 0;
      }
      iVar1 = BIO_puts(param_1,"\n");
      if (0 < iVar1) {
        param_4 = param_4 + 2;
LAB_00157b98:
        iVar1 = BIO_indent(param_1,param_4,0x80);
        if ((iVar1 != 0) && (iVar1 = BIO_puts(param_1,"Hash Algorithm: "), 0 < iVar1)) {
          if ((undefined4 *)*param_3 == (undefined4 *)0x0) {
            iVar1 = BIO_puts(param_1,"sha1 (default)");
          }
          else {
            iVar1 = i2a_ASN1_OBJECT(param_1,*(ASN1_OBJECT **)*param_3);
          }
          if ((((0 < iVar1) && (iVar1 = BIO_puts(param_1,"\n"), 0 < iVar1)) &&
              (iVar1 = BIO_indent(param_1,param_4,0x80), iVar1 != 0)) &&
             (iVar1 = BIO_puts(param_1,"Mask Algorithm: "), 0 < iVar1)) {
            if ((undefined4 *)param_3[1] == (undefined4 *)0x0) {
              iVar1 = BIO_puts(param_1,"mgf1 with sha1 (default)");
joined_r0x00157d24:
              if (0 < iVar1) {
                a = (X509_ALGOR *)0x0;
LAB_00157c48:
                BIO_puts(param_1,"\n");
                uVar3 = BIO_indent(param_1,param_4,0x80);
                if (uVar3 == 0) goto LAB_00157b76;
                if (param_2 == 0) {
                  pcVar2 = "";
                }
                else {
                  pcVar2 = "Minimum";
                }
                iVar1 = BIO_printf(param_1,"%s Salt Length: 0x",pcVar2);
                if (0 < iVar1) {
                  if ((ASN1_INTEGER *)param_3[2] == (ASN1_INTEGER *)0x0) {
                    iVar1 = BIO_puts(param_1,"14 (default)");
                    if (iVar1 < 1) {
                      uVar3 = 0;
                      goto LAB_00157b76;
                    }
                  }
                  else {
                    iVar1 = i2a_ASN1_INTEGER(param_1,(ASN1_INTEGER *)param_3[2]);
                    if (iVar1 < 1) goto LAB_00157d2c;
                  }
                  BIO_puts(param_1,"\n");
                  uVar3 = BIO_indent(param_1,param_4,0x80);
                  if (uVar3 == 0) goto LAB_00157b76;
                  iVar1 = BIO_puts(param_1,"Trailer Field: 0x");
                  if (0 < iVar1) {
                    if ((ASN1_INTEGER *)param_3[3] == (ASN1_INTEGER *)0x0) {
                      iVar1 = BIO_puts(param_1,"BC (default)");
                      if (iVar1 < 1) {
                        uVar3 = 0;
                        goto LAB_00157b76;
                      }
                    }
                    else {
                      iVar1 = i2a_ASN1_INTEGER(param_1,(ASN1_INTEGER *)param_3[3]);
                      if (iVar1 < 1) goto LAB_00157d2c;
                    }
                    uVar3 = 1;
                    BIO_puts(param_1,"\n");
                    goto LAB_00157b76;
                  }
                }
LAB_00157d2c:
                uVar3 = 0;
                goto LAB_00157b76;
              }
            }
            else {
              iVar1 = i2a_ASN1_OBJECT(param_1,*(ASN1_OBJECT **)param_3[1]);
              if ((0 < iVar1) && (iVar1 = BIO_puts(param_1," with "), 0 < iVar1)) {
                puVar4 = (undefined4 *)param_3[1];
                iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*puVar4);
                if ((iVar1 != 0x38f) ||
                   (a = (X509_ALGOR *)ASN1_TYPE_unpack_sequence(X509_ALGOR_it,puVar4[1]),
                   a == (X509_ALGOR *)0x0)) {
                  iVar1 = BIO_puts(param_1,"INVALID");
                  goto joined_r0x00157d24;
                }
                iVar1 = i2a_ASN1_OBJECT(param_1,a->algorithm);
                if (0 < iVar1) goto LAB_00157c48;
                goto LAB_00157d2c;
              }
            }
          }
        }
      }
    }
  }
  a = (X509_ALGOR *)0x0;
  uVar3 = 0;
LAB_00157b76:
  X509_ALGOR_free(a);
  return uVar3;
}

