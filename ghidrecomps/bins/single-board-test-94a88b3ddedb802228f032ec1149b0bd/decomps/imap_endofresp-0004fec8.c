
undefined4 imap_endofresp(int *param_1,char *param_2,uint param_3,undefined4 *param_4)

{
  size_t __n;
  int iVar1;
  undefined4 uVar2;
  char *__s1;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  __n = strlen((char *)(param_1 + 0x108));
  iVar4 = *(int *)(iVar3 + 0x14c);
  if (((__n + 1 <= param_3) && (iVar1 = memcmp(param_1 + 0x108,param_2,__n), iVar1 == 0)) &&
     (param_2[__n] == ' ')) {
    if (1 < ~__n + param_3) {
      param_2 = param_2 + __n + 1;
      iVar4 = memcmp(param_2,DAT_000500fc,2);
      if (iVar4 == 0) {
        *param_4 = 0x4f;
        return 1;
      }
      iVar4 = memcmp(param_2,DAT_00050100,2);
      if (iVar4 == 0) {
        *param_4 = 0x4e;
        return 1;
      }
      if ((~__n + param_3 != 2) && (iVar4 = memcmp(param_2,DAT_00050104,3), iVar4 == 0)) {
        *param_4 = 0x42;
        return 1;
      }
    }
    Curl_failf(iVar3,DAT_00050138);
    *param_4 = 0xffffffff;
    return 1;
  }
  if ((param_3 < 2) || (iVar1 = memcmp(DAT_000500f8,param_2,2), iVar1 != 0)) {
    if (*(int *)(iVar4 + 0x1c) == 0) {
      if (param_3 == 3) {
        if (*param_2 == '+') goto LAB_0004ffb0;
      }
      else if (param_3 < 2) goto switchD_0004ff1a_caseD_3;
      iVar4 = memcmp(DAT_00050108,param_2,2);
      if (iVar4 == 0) {
LAB_0004ffb0:
        if ((param_1[0xfe] != 5) && (param_1[0xfe] != 0xb)) {
          Curl_failf(iVar3,DAT_0005010c);
          *param_4 = 0xffffffff;
          return 1;
        }
        *param_4 = 0x2b;
        return 1;
      }
    }
    goto switchD_0004ff1a_caseD_3;
  }
  switch(param_1[0xfe]) {
  case 2:
    iVar3 = imap_matchresp(param_2,param_3,DAT_00050134);
    break;
  default:
    goto switchD_0004ff1a_caseD_3;
  case 7:
    if (*(int *)(iVar4 + 0x1c) == 0) {
      iVar3 = imap_matchresp(param_2,param_3,DAT_00050110);
      if (iVar3 == 0) goto switchD_0004ff1a_caseD_3;
      if (*(int *)(iVar4 + 0x1c) == 0) goto switchD_0004ff1a_caseD_8;
    }
    iVar3 = imap_matchresp(param_2,param_3);
    if (iVar3 == 0) {
      __s1 = *(char **)(iVar4 + 0x1c);
      iVar3 = strcmp(__s1,DAT_0005011c);
      if (iVar3 == 0) {
        iVar3 = imap_matchresp(param_2,param_3,DAT_00050118);
        if (iVar3 != 0) goto switchD_0004ff1a_caseD_8;
        __s1 = *(char **)(iVar4 + 0x1c);
      }
      iVar3 = strcmp(__s1,DAT_00050120);
      if (((((iVar3 != 0) && (iVar3 = strcmp(__s1,DAT_00050124), iVar3 != 0)) &&
           (iVar3 = strcmp(__s1,DAT_00050114), iVar3 != 0)) &&
          ((iVar3 = strcmp(__s1,DAT_00050128), iVar3 != 0 &&
           (iVar3 = strcmp(__s1,DAT_0005012c), iVar3 != 0)))) &&
         (((*__s1 != 'U' || ((__s1[1] != 'I' || (__s1[2] != 'D')))) || (__s1[3] != '\0')))) {
        iVar3 = strcmp(__s1,DAT_00050130);
        break;
      }
    }
  case 8:
    goto switchD_0004ff1a_caseD_8;
  case 9:
    iVar3 = imap_matchresp(param_2,param_3,DAT_00050118);
    break;
  case 0xd:
    iVar3 = imap_matchresp(param_2,param_3,DAT_00050114);
  }
  if (iVar3 == 0) {
switchD_0004ff1a_caseD_3:
    uVar2 = 0;
  }
  else {
switchD_0004ff1a_caseD_8:
    uVar2 = 1;
    *param_4 = 0x2a;
  }
  return uVar2;
}

