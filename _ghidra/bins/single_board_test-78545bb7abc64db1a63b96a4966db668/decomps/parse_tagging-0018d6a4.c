
undefined4 parse_tagging(char *param_1,int param_2,ulong *param_3,undefined4 *param_4)

{
  ulong uVar1;
  undefined4 uVar2;
  char local_20 [4];
  char *local_1c [2];
  
  if (param_1 == (char *)0x0) {
    return 0;
  }
  uVar1 = strtoul(param_1,local_1c,10);
  if (local_1c[0] == (char *)0x0) {
    if ((int)uVar1 < 0) goto LAB_0018d75c;
    *param_3 = uVar1;
    goto switchD_0018d6da_caseD_43;
  }
  if ((*local_1c[0] != '\0') && (param_1 + param_2 < local_1c[0])) {
    return 0;
  }
  if ((int)uVar1 < 0) {
LAB_0018d75c:
    ERR_put_error(0xd,0xb6,0xbb,"crypto/asn1/asn1_gen.c",0x168);
    return 0;
  }
  *param_3 = uVar1;
  if (param_2 == (int)local_1c[0] - (int)param_1) {
switchD_0018d6da_caseD_43:
    uVar2 = 1;
    *param_4 = 0x80;
  }
  else {
    local_20[0] = *local_1c[0];
    switch(local_20[0]) {
    case 'A':
      uVar2 = 1;
      *param_4 = 0x40;
      break;
    default:
      uVar2 = 0;
      local_20[1] = 0;
      ERR_put_error(0xd,0xb6,0xba,"crypto/asn1/asn1_gen.c",0x187);
      ERR_add_error_data(2,"Char=",local_20);
      break;
    case 'C':
      goto switchD_0018d6da_caseD_43;
    case 'P':
      uVar2 = 1;
      *param_4 = 0xc0;
      break;
    case 'U':
      uVar2 = 1;
      *param_4 = 0;
    }
  }
  return uVar2;
}

