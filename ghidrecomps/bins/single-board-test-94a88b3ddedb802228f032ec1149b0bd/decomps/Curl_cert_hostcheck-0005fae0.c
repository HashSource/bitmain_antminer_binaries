
undefined4 Curl_cert_hostcheck(char *param_1,char *param_2)

{
  char *__s;
  char *__s_00;
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char cVar6;
  undefined4 uVar7;
  code **ppcVar8;
  bool bVar9;
  undefined auStack_38 [12];
  undefined auStack_2c [20];
  
  ppcVar8 = DAT_0005fbfc;
  if ((((param_1 == (char *)0x0) || (*param_1 == '\0')) || (param_2 == (char *)0x0)) ||
     ((*param_2 == '\0' || (__s = (char *)(**DAT_0005fbfc)(), __s == (char *)0x0)))) {
    return 0;
  }
  __s_00 = (char *)(**ppcVar8)(param_2);
  if (__s_00 == (char *)0x0) {
    uVar7 = 0;
    ppcVar8 = DAT_0005fc00;
    goto LAB_0005fb5c;
  }
  sVar1 = strlen(__s_00);
  cVar6 = __s_00[sVar1 - 1];
  bVar9 = cVar6 == '.';
  if (bVar9) {
    cVar6 = '\0';
  }
  if (bVar9) {
    __s_00[sVar1 - 1] = cVar6;
  }
  sVar1 = strlen(__s);
  cVar6 = __s[sVar1 - 1];
  bVar9 = cVar6 == '.';
  if (bVar9) {
    cVar6 = '\0';
  }
  if (bVar9) {
    __s[sVar1 - 1] = cVar6;
  }
  pcVar2 = strchr(__s,0x2a);
  if (pcVar2 == (char *)0x0) {
LAB_0005fb92:
    iVar3 = Curl_raw_equal(__s,__s_00);
    if (iVar3 != 0) {
      iVar3 = 1;
    }
joined_r0x0005fba2:
    if (iVar3 == 0) goto LAB_0005fb52;
    uVar7 = 1;
  }
  else {
    iVar3 = inet_pton(2,__s_00,auStack_38);
    if ((iVar3 < 1) && (iVar3 = inet_pton(10,__s_00,auStack_2c), iVar3 < 1)) {
      pcVar4 = strchr(__s,0x2e);
      if ((pcVar4 == (char *)0x0) ||
         (((pcVar5 = strchr(pcVar4 + 1,0x2e), pcVar5 == (char *)0x0 || (pcVar4 < pcVar2)) ||
          (iVar3 = Curl_raw_nequal(__s,DAT_0005fc04,4), iVar3 != 0)))) goto LAB_0005fb92;
      pcVar5 = strchr(__s_00,0x2e);
      if (((pcVar5 == (char *)0x0) || (iVar3 = Curl_raw_equal(pcVar4,pcVar5), iVar3 == 0)) ||
         (((int)pcVar5 - (int)__s_00 < (int)pcVar4 - (int)__s ||
          (iVar3 = Curl_raw_nequal(__s,__s_00,(int)pcVar2 - (int)__s), iVar3 == 0))))
      goto LAB_0005fb52;
      iVar3 = Curl_raw_nequal(pcVar2 + 1,(int)pcVar5 - ((int)pcVar4 - (int)(pcVar2 + 1)));
      goto joined_r0x0005fba2;
    }
LAB_0005fb52:
    uVar7 = 0;
  }
  ppcVar8 = DAT_0005fc00;
  (**DAT_0005fc00)(__s_00);
LAB_0005fb5c:
  (**ppcVar8)(__s);
  return uVar7;
}

