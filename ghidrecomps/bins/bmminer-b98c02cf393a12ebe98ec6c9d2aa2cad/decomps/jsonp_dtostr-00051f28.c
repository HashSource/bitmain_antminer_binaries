
uint jsonp_dtostr(char *param_1,uint param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  lconv *plVar3;
  char *pcVar4;
  size_t __n;
  char *__src;
  char *__dest;
  uint uVar5;
  
  if (param_3 == 0) {
    param_3 = 0x11;
  }
  uVar2 = snprintf(param_1,param_2,"%.*g",param_3);
  if (((int)uVar2 < 0) || (param_2 <= uVar2)) {
    return 0xffffffff;
  }
  plVar3 = localeconv();
  if (((byte)*plVar3->decimal_point != 0x2e) &&
     (pcVar4 = strchr(param_1,(uint)(byte)*plVar3->decimal_point), pcVar4 != (char *)0x0)) {
    *pcVar4 = '.';
  }
  pcVar4 = strchr(param_1,0x2e);
  uVar5 = uVar2;
  if (pcVar4 == (char *)0x0) {
    pcVar4 = strchr(param_1,0x65);
    if (pcVar4 != (char *)0x0) goto LAB_00051f7e;
    if (param_2 <= uVar2 + 3) {
      return 0xffffffff;
    }
    uVar5 = uVar2 + 2;
    param_1[uVar2] = '.';
    param_1[uVar2 + 1] = '0';
    param_1[uVar5] = '\0';
  }
  pcVar4 = strchr(param_1,0x65);
  uVar2 = uVar5;
  if (pcVar4 == (char *)0x0) {
    return uVar5;
  }
LAB_00051f7e:
  __src = pcVar4 + 2;
  cVar1 = pcVar4[2];
  if (pcVar4[1] == '-') {
    if (cVar1 != '0') {
      return uVar2;
    }
    cVar1 = pcVar4[3];
    __dest = __src;
    __src = pcVar4 + 3;
  }
  else {
    __dest = pcVar4 + 1;
  }
  while (cVar1 == '0') {
    __src = __src + 1;
    cVar1 = *__src;
  }
  if (__dest != __src) {
    __n = uVar2 - ((int)__src - (int)param_1);
    uVar2 = uVar2 - ((int)__src - (int)__dest);
    memmove(__dest,__src,__n);
  }
  return uVar2;
}

