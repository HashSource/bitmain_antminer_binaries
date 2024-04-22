
int asn1_template_ex_d2i
              (ASN1_VALUE **param_1,char **param_2,undefined4 param_3,ASN1_TEMPLATE *param_4,
              undefined param_5,undefined4 param_6)

{
  int iVar1;
  int line;
  char *pcVar2;
  char local_30 [7];
  char local_29;
  char *local_28;
  char *local_24;
  
  if (param_1 == (ASN1_VALUE **)0x0) {
    return 0;
  }
  local_24 = *param_2;
  if ((param_4->flags & 0x10) == 0) {
    iVar1 = asn1_template_noexp_d2i();
    return iVar1;
  }
  iVar1 = asn1_check_tlen(&local_28,0,0,&local_29,local_30,&local_24,param_3,param_4->tag,
                          param_4->flags & 0xc0,param_5,param_6);
  pcVar2 = local_24;
  line = 0x221;
  if (iVar1 != 0) {
    if (iVar1 == -1) {
      return -1;
    }
    if (local_30[0] == '\0') {
      ERR_put_error(0xd,0x84,0x78,DAT_000bb8bc,0x227);
      return 0;
    }
    iVar1 = asn1_template_noexp_d2i(param_1,&local_24,local_28,param_4,0,param_6);
    if (iVar1 != 0) {
      local_28 = pcVar2 + ((int)local_28 - (int)local_24);
      if (local_29 == '\0') {
        pcVar2 = local_24;
        if (local_28 == (char *)0x0) goto LAB_000bb89e;
        ERR_put_error(0xd,0x84,0x77,DAT_000bb8bc,0x23e);
      }
      else {
        if (((1 < (int)local_28) && (*local_24 == '\0')) &&
           (pcVar2 = local_24 + 2, local_24[1] == '\0')) {
LAB_000bb89e:
          *param_2 = pcVar2;
          return 1;
        }
        ERR_put_error(0xd,0x84,0x89,DAT_000bb8bc,0x235);
      }
      ASN1_template_free(param_1,param_4);
      return 0;
    }
    line = 0x22d;
    iVar1 = 0;
  }
  ERR_put_error(0xd,0x84,0x3a,DAT_000bb8bc,line);
  return iVar1;
}

