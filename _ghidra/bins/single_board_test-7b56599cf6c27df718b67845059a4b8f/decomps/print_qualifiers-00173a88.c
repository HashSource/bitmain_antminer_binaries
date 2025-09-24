
void print_qualifiers(BIO *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  ASN1_INTEGER *aint;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  char *pcVar8;
  
  iVar7 = 0;
  iVar1 = OPENSSL_sk_num(param_2);
  if (0 < iVar1) {
    do {
      puVar2 = (undefined4 *)OPENSSL_sk_value(param_2,iVar7);
      iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*puVar2);
      if (iVar1 == 0xa4) {
        BIO_printf(param_1,"%*sCPS: %.*s\n",param_3,"",*(undefined4 *)puVar2[1],
                   ((undefined4 *)puVar2[1])[2]);
      }
      else if (iVar1 == 0xa5) {
        iVar1 = param_3 + 2;
        pcVar8 = "";
        BIO_printf(param_1,"%*sUser Notice:\n",param_3,"");
        puVar2 = (undefined4 *)puVar2[1];
        puVar6 = (undefined4 *)*puVar2;
        if (puVar6 != (undefined4 *)0x0) {
          uVar5 = ((undefined4 *)*puVar6)[2];
          BIO_printf(param_1,"%*sOrganization: %.*s\n",iVar1,"",*(undefined4 *)*puVar6,uVar5);
          iVar3 = OPENSSL_sk_num(puVar6[1]);
          if (1 < iVar3) {
            pcVar8 = "s";
          }
          BIO_printf(param_1,"%*sNumber%s: ",iVar1,"",pcVar8,uVar5);
          for (iVar3 = 0; iVar4 = OPENSSL_sk_num(puVar6[1]), iVar3 < iVar4; iVar3 = iVar3 + 1) {
            aint = (ASN1_INTEGER *)OPENSSL_sk_value(puVar6[1],iVar3);
            if (iVar3 == 0) {
              if (aint != (ASN1_INTEGER *)0x0) goto LAB_00173b50;
LAB_00173b98:
              BIO_puts(param_1,"(null)");
            }
            else {
              BIO_puts(param_1,", ");
              if (aint == (ASN1_INTEGER *)0x0) goto LAB_00173b98;
LAB_00173b50:
              pcVar8 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,aint);
              if (pcVar8 == (char *)0x0) goto LAB_00173bc6;
              BIO_puts(param_1,pcVar8);
              CRYPTO_free(pcVar8);
            }
          }
          BIO_puts(param_1,"\n");
        }
        puVar2 = (undefined4 *)puVar2[1];
        if (puVar2 != (undefined4 *)0x0) {
          BIO_printf(param_1,"%*sExplicit Text: %.*s\n",iVar1,"",*puVar2,puVar2[2]);
        }
      }
      else {
        BIO_printf(param_1,"%*sUnknown Qualifier: ",param_3 + 2,"");
        i2a_ASN1_OBJECT(param_1,(ASN1_OBJECT *)*puVar2);
        BIO_puts(param_1,"\n");
      }
LAB_00173bc6:
      iVar7 = iVar7 + 1;
      iVar1 = OPENSSL_sk_num(param_2);
    } while (iVar7 < iVar1);
  }
  return;
}

