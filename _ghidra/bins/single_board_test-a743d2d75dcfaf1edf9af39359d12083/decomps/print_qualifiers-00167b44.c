
void print_qualifiers(BIO *param_1,_STACK *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  ASN1_INTEGER *aint;
  int *piVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  int local_30;
  
  local_30 = 0;
  while( true ) {
    iVar1 = sk_num(param_2);
    if (iVar1 <= local_30) break;
    puVar2 = (undefined4 *)sk_value(param_2,local_30);
    iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*puVar2);
    if (iVar1 == 0xa4) {
      BIO_printf(param_1,"%*sCPS: %s\n",param_3,"",*(undefined4 *)(puVar2[1] + 8));
    }
    else if (iVar1 == 0xa5) {
      BIO_printf(param_1,"%*sUser Notice:\n",param_3,"");
      piVar4 = (int *)puVar2[1];
      iVar1 = param_3 + 2;
      piVar6 = (int *)*piVar4;
      if (piVar6 != (int *)0x0) {
        iVar5 = 0;
        BIO_printf(param_1,"%*sOrganization: %s\n",iVar1,"",*(undefined4 *)(*piVar6 + 8));
        iVar3 = sk_num((_STACK *)piVar6[1]);
        pcVar7 = "";
        if (1 < iVar3) {
          pcVar7 = "s";
        }
        BIO_printf(param_1,"%*sNumber%s: ",iVar1,"",pcVar7);
        for (; iVar3 = sk_num((_STACK *)piVar6[1]), iVar5 < iVar3; iVar5 = iVar5 + 1) {
          aint = (ASN1_INTEGER *)sk_value((_STACK *)piVar6[1],iVar5);
          if (iVar5 != 0) {
            BIO_puts(param_1,", ");
          }
          pcVar7 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,aint);
          BIO_puts(param_1,pcVar7);
          CRYPTO_free(pcVar7);
        }
        BIO_puts(param_1,"\n");
      }
      iVar3 = piVar4[1];
      if (iVar3 != 0) {
        BIO_printf(param_1,"%*sExplicit Text: %s\n",iVar1,"",*(undefined4 *)(iVar3 + 8));
      }
    }
    else {
      BIO_printf(param_1,"%*sUnknown Qualifier: ",param_3 + 2,"");
      i2a_ASN1_OBJECT(param_1,(ASN1_OBJECT *)*puVar2);
      BIO_puts(param_1,"\n");
    }
    local_30 = local_30 + 1;
  }
  return;
}

