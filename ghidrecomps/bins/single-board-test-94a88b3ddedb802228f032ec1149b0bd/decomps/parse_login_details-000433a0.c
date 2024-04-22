
/* WARNING: Type propagation algorithm not settling */

char ** parse_login_details(char *param_1,size_t param_2,void **param_3,void **param_4,
                           char **param_5)

{
  code **ppcVar1;
  void **ppvVar2;
  void **ppvVar3;
  char **ppcVar4;
  char **__dest;
  void **__dest_00;
  void **ppvVar5;
  uint uVar6;
  uint uVar7;
  size_t sVar8;
  char **__n;
  void *__dest_01;
  
  ppvVar2 = param_4;
  if ((param_4 != (void **)0x0) &&
     (ppvVar2 = (void **)strchr(param_1,0x3a), param_1 + param_2 <= ppvVar2)) {
    ppvVar2 = (void **)0x0;
  }
  sVar8 = param_2;
  if ((param_5 == (char **)0x0) ||
     (ppvVar3 = (void **)strchr(param_1,0x3b), param_1 + param_2 <= ppvVar3)) {
    if (ppvVar2 != (void **)0x0) {
      ppvVar3 = (void **)0x0;
      uVar7 = 1;
      ppvVar5 = (void **)0x0;
      sVar8 = (int)ppvVar2 - (int)param_1;
      goto LAB_000433ea;
    }
    ppvVar3 = (void **)0x0;
LAB_0004358a:
    ppvVar5 = (void **)0x0;
LAB_00043446:
    if (ppvVar3 == (void **)0x0) {
      __n = (char **)0x0;
      goto LAB_0004346a;
    }
    if (ppvVar2 == (void **)0x0 || ppvVar2 <= ppvVar3) {
LAB_0004340a:
      __n = (char **)(param_1 + (param_2 - (int)ppvVar3) + -1);
      goto LAB_0004346a;
    }
  }
  else {
    if (ppvVar2 == (void **)0x0) {
      if (ppvVar3 != (void **)0x0) {
        sVar8 = (int)ppvVar3 - (int)param_1;
      }
      goto LAB_0004358a;
    }
    ppvVar5 = ppvVar3;
    if (ppvVar3 != (void **)0x0) {
      ppvVar5 = (void **)0x1;
    }
    uVar7 = (uint)(ppvVar3 < ppvVar2);
    if ((uVar7 & (uint)ppvVar5) == 0) {
      sVar8 = (int)ppvVar2 - (int)param_1;
    }
    else {
      sVar8 = (int)ppvVar3 - (int)param_1;
    }
LAB_000433ea:
    if (ppvVar2 < ppvVar3) {
      uVar6 = (uint)ppvVar5 & 1;
    }
    else {
      uVar6 = 0;
    }
    if (uVar6 == 0) {
      ppvVar5 = (void **)(param_1 + (param_2 - (int)ppvVar2) + -1);
      goto LAB_00043446;
    }
    if (ppvVar2 == (void **)0x0) {
      uVar7 = 0;
    }
    ppvVar5 = (void **)((int)ppvVar3 + (-1 - (int)ppvVar2));
    if (uVar7 == 0) goto LAB_0004340a;
  }
  __n = (char **)((int)ppvVar2 + (-1 - (int)ppvVar3));
LAB_0004346a:
  if (sVar8 == 0 || param_3 == (void **)0x0) {
    __dest_01 = (void *)0x0;
  }
  else {
    __dest_01 = (void *)(**DAT_000435c0)(sVar8 + 1);
    if (__dest_01 == (void *)0x0) {
      return (char **)0x1b;
    }
  }
  __dest_00 = param_4;
  if (((param_4 == (void **)0x0) || (__dest_00 = ppvVar5, ppvVar5 == (void **)0x0)) ||
     (__dest_00 = (void **)(**DAT_000435c0)((int)ppvVar5 + 1), __dest_00 != (void **)0x0)) {
    __dest = param_5;
    if (((param_5 == (char **)0x0) || (__dest = __n, __n == (char **)0x0)) ||
       (__dest = (char **)(**DAT_000435c0)((char *)((int)__n + 1)), ppcVar1 = DAT_000435bc,
       __dest != (char **)0x0)) {
      if (__dest_01 != (void *)0x0) {
        memcpy(__dest_01,param_1,sVar8);
        ppcVar1 = DAT_000435bc;
        *(undefined *)((int)__dest_01 + sVar8) = 0;
        (**ppcVar1)(*param_3);
        *param_3 = __dest_01;
      }
      if (__dest_00 != (void **)0x0) {
        memcpy(__dest_00,(void *)((int)ppvVar2 + 1),(size_t)ppvVar5);
        ppcVar1 = DAT_000435bc;
        *(undefined *)((int)__dest_00 + (int)ppvVar5) = 0;
        (**ppcVar1)(*param_4);
        *param_4 = __dest_00;
      }
      ppcVar4 = __dest;
      if (__dest != (char **)0x0) {
        memcpy(__dest,(void *)((int)ppvVar3 + 1),(size_t)__n);
        ppcVar1 = DAT_000435bc;
        *(char *)((int)__dest + (int)__n) = '\0';
        (**ppcVar1)(*param_5);
        ppcVar4 = (char **)0x0;
        *param_5 = (char *)__dest;
      }
    }
    else {
      (**DAT_000435bc)(__dest_00);
      (**ppcVar1)(__dest_01);
      ppcVar4 = (char **)0x1b;
    }
  }
  else {
    (**DAT_000435bc)(__dest_01);
    ppcVar4 = (char **)0x1b;
  }
  return ppcVar4;
}

