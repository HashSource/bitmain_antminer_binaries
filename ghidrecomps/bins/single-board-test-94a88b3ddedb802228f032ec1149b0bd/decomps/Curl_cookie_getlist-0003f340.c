
int ** Curl_cookie_getlist(int **param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  code **ppcVar2;
  int **ppiVar3;
  code **ppcVar4;
  int *piVar5;
  int iVar6;
  size_t __n;
  char *__s;
  char *pcVar7;
  size_t sVar8;
  int **ppiVar9;
  undefined4 *__base;
  int *piVar10;
  int **ppiVar11;
  int *piVar12;
  int **ppiVar13;
  int **ppiVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  code *pcVar17;
  int iVar18;
  int **ppiVar19;
  int *piVar20;
  size_t local_38;
  
  piVar5 = (int *)time((time_t *)0x0);
  ppcVar4 = DAT_0003f584;
  if ((param_1 != (int **)0x0) && (*param_1 != (int *)0x0)) {
    remove_expired(param_1);
    iVar6 = isip(param_2);
    param_1 = (int **)*param_1;
    ppcVar4 = DAT_0003f584;
    if (param_1 != (int **)0x0) {
      local_38 = 0;
      ppiVar19 = (int **)0x0;
LAB_0003f398:
      do {
        piVar10 = param_1[6];
        piVar12 = param_1[7];
        if (((((uint)piVar10 | (uint)piVar12) == 0) ||
            (iVar18 = (int)piVar5 >> 0x1f,
            (int)((iVar18 - (int)piVar12) - (uint)(piVar5 < piVar10)) < 0 !=
            (SBORROW4(iVar18,(int)piVar12) !=
            SBORROW4(iVar18 - (int)piVar12,(uint)(piVar5 < piVar10))))) &&
           ((*(char *)(param_1 + 0xc) == '\0' || (param_4 != 0)))) {
          piVar10 = param_1[5];
          if (piVar10 != (int *)0x0) {
            if ((*(char *)(param_1 + 9) != '\0') && (iVar6 == 0)) {
              iVar18 = tailmatch(piVar10,param_2);
              if (iVar18 != 0) goto LAB_0003f3d2;
              if (*(char *)(param_1 + 9) != '\0') goto LAB_0003f38c;
              piVar10 = param_1[5];
            }
            iVar18 = Curl_raw_equal(param_2,piVar10);
            if (iVar18 == 0) goto LAB_0003f38c;
          }
LAB_0003f3d2:
          piVar10 = param_1[4];
          if ((piVar10 == (int *)0x0) || (__n = strlen((char *)piVar10), __n == 1))
          goto LAB_0003f44a;
          __s = (char *)(*Curl_cstrdup)(param_3);
          if (__s != (char *)0x0) {
            pcVar7 = strchr(__s,0x3f);
            if (pcVar7 != (char *)0x0) {
              *pcVar7 = '\0';
            }
            if (*__s != '/') {
              (*Curl_cfree)(__s);
              __s = (char *)(*Curl_cstrdup)(DAT_0003f588);
              if (__s == (char *)0x0) goto LAB_0003f38c;
            }
            ppcVar4 = DAT_0003f584;
            sVar8 = strlen(__s);
            if ((__n <= sVar8) && (iVar18 = strncmp((char *)piVar10,__s,__n), iVar18 == 0)) {
              if (__n == sVar8) {
                (**ppcVar4)(__s);
              }
              else {
                cVar1 = __s[__n];
                (**ppcVar4)(__s);
                if (cVar1 != '/') goto LAB_0003f38c;
              }
LAB_0003f44a:
              ppiVar9 = (int **)(*Curl_cmalloc)(0x38);
              ppcVar4 = DAT_0003f584;
              if (ppiVar9 == (int **)0x0) goto joined_r0x0003f562;
              ppiVar3 = ppiVar9;
              ppiVar14 = param_1;
              do {
                ppiVar13 = ppiVar14;
                ppiVar11 = ppiVar3;
                piVar20 = ppiVar13[1];
                piVar12 = ppiVar13[2];
                piVar10 = ppiVar13[3];
                ppiVar14 = ppiVar13 + 4;
                *ppiVar11 = *ppiVar13;
                ppiVar11[1] = piVar20;
                ppiVar11[2] = piVar12;
                ppiVar11[3] = piVar10;
                ppiVar3 = ppiVar11 + 4;
              } while (ppiVar14 != param_1 + 0xc);
              local_38 = local_38 + 1;
              piVar10 = ppiVar13[5];
              ppiVar11[4] = *ppiVar14;
              ppiVar11[5] = piVar10;
              *ppiVar9 = (int *)ppiVar19;
              param_1 = (int **)*param_1;
              ppiVar19 = ppiVar9;
              if (param_1 == (int **)0x0) break;
              goto LAB_0003f398;
            }
            (**ppcVar4)(__s);
          }
        }
LAB_0003f38c:
        param_1 = (int **)*param_1;
      } while (param_1 != (int **)0x0);
      if (local_38 == 0) {
        return ppiVar19;
      }
      __base = (undefined4 *)(**DAT_0003f58c)(local_38 * 4);
      ppcVar4 = DAT_0003f584;
      if (__base != (undefined4 *)0x0) {
        piVar5 = __base + -1;
        for (; ppiVar19 != (int **)0x0; ppiVar19 = (int **)*ppiVar19) {
          piVar5 = piVar5 + 1;
          *piVar5 = (int)ppiVar19;
        }
        qsort(__base,local_38,4,DAT_0003f590);
        ppiVar19 = (int **)*__base;
        if (local_38 != 1) {
          puVar15 = __base + 1;
          do {
            puVar16 = puVar15 + 1;
            *(undefined4 *)puVar15[-1] = *puVar15;
            puVar15 = puVar16;
          } while (puVar16 != __base + local_38);
        }
        pcVar17 = *DAT_0003f584;
        *(undefined4 *)__base[local_38 - 1] = 0;
        (*pcVar17)(__base);
        return ppiVar19;
      }
joined_r0x0003f562:
      while (ppcVar2 = DAT_0003f584, ppiVar19 != (int **)0x0) {
        ppiVar19 = (int **)*ppiVar19;
        pcVar17 = *DAT_0003f584;
        DAT_0003f584 = ppcVar4;
        (*pcVar17)();
        ppcVar4 = DAT_0003f584;
        DAT_0003f584 = ppcVar2;
      }
    }
  }
  DAT_0003f584 = ppcVar4;
  return (int **)0x0;
}

