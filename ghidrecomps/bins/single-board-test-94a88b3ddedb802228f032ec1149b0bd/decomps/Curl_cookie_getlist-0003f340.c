
/* WARNING: Type propagation algorithm not settling */

int * Curl_cookie_getlist(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  code *pcVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  size_t __n;
  char *__s;
  char *pcVar6;
  size_t sVar7;
  int *piVar8;
  undefined4 *__base;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  char *__s_00;
  int iVar16;
  int *piVar17;
  int iVar18;
  size_t local_38;
  
  uVar4 = time((time_t *)0x0);
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    remove_expired(param_1);
    iVar5 = isip(param_2);
    param_1 = (int *)*param_1;
    if (param_1 != (int *)0x0) {
      local_38 = 0;
      piVar17 = (int *)0x0;
LAB_0003f398:
      do {
        uVar9 = param_1[6];
        iVar11 = param_1[7];
        if (((uVar9 == 0 && iVar11 == 0) ||
            (iVar16 = (int)uVar4 >> 0x1f,
            (int)((iVar16 - iVar11) - (uint)(uVar4 < uVar9)) < 0 !=
            (SBORROW4(iVar16,iVar11) != SBORROW4(iVar16 - iVar11,(uint)(uVar4 < uVar9))))) &&
           (((char)param_1[0xc] == '\0' || (param_4 != 0)))) {
          iVar11 = param_1[5];
          if (iVar11 != 0) {
            if (((char)param_1[9] != '\0') && (iVar5 == 0)) {
              iVar11 = tailmatch(iVar11,param_2);
              if (iVar11 != 0) goto LAB_0003f3d2;
              if ((char)param_1[9] != '\0') goto LAB_0003f38c;
              iVar11 = param_1[5];
            }
            iVar11 = Curl_raw_equal(param_2,iVar11);
            if (iVar11 == 0) goto LAB_0003f38c;
          }
LAB_0003f3d2:
          __s_00 = (char *)param_1[4];
          if ((__s_00 == (char *)0x0) || (__n = strlen(__s_00), __n == 1)) goto LAB_0003f44a;
          __s = (char *)(*Curl_cstrdup)(param_3);
          if (__s != (char *)0x0) {
            pcVar6 = strchr(__s,0x3f);
            if (pcVar6 != (char *)0x0) {
              *pcVar6 = '\0';
            }
            if (*__s != '/') {
              (*Curl_cfree)(__s);
              __s = (char *)(*Curl_cstrdup)(&DAT_00135588);
              if (__s == (char *)0x0) goto LAB_0003f38c;
            }
            sVar7 = strlen(__s);
            if ((__n <= sVar7) && (iVar11 = strncmp(__s_00,__s,__n), iVar11 == 0)) {
              if (__n == sVar7) {
                (*Curl_cfree)(__s);
              }
              else {
                cVar1 = __s[__n];
                (*Curl_cfree)(__s);
                if (cVar1 != '/') goto LAB_0003f38c;
              }
LAB_0003f44a:
              piVar8 = (int *)(*Curl_cmalloc)(0x38);
              if (piVar8 == (int *)0x0) goto joined_r0x0003f562;
              piVar3 = piVar8;
              piVar13 = param_1;
              do {
                piVar12 = piVar13;
                piVar10 = piVar3;
                iVar18 = piVar12[1];
                iVar16 = piVar12[2];
                iVar11 = piVar12[3];
                piVar13 = piVar12 + 4;
                *piVar10 = *piVar12;
                piVar10[1] = iVar18;
                piVar10[2] = iVar16;
                piVar10[3] = iVar11;
                piVar3 = piVar10 + 4;
              } while (piVar13 != param_1 + 0xc);
              local_38 = local_38 + 1;
              iVar11 = piVar12[5];
              piVar10[4] = *piVar13;
              piVar10[5] = iVar11;
              *piVar8 = (int)piVar17;
              param_1 = (int *)*param_1;
              piVar17 = piVar8;
              if (param_1 == (int *)0x0) break;
              goto LAB_0003f398;
            }
            (*Curl_cfree)(__s);
          }
        }
LAB_0003f38c:
        param_1 = (int *)*param_1;
      } while (param_1 != (int *)0x0);
      if (local_38 == 0) {
        return piVar17;
      }
      __base = (undefined4 *)(*Curl_cmalloc)(local_38 * 4);
      if (__base != (undefined4 *)0x0) {
        piVar8 = __base + -1;
        for (; piVar17 != (int *)0x0; piVar17 = (int *)*piVar17) {
          piVar8 = piVar8 + 1;
          *piVar8 = (int)piVar17;
        }
        qsort(__base,local_38,4,(__compar_fn_t)0x3e895);
        piVar17 = (int *)*__base;
        if (local_38 != 1) {
          puVar14 = __base + 1;
          do {
            puVar15 = puVar14 + 1;
            *(undefined4 *)puVar14[-1] = *puVar14;
            puVar14 = puVar15;
          } while (puVar15 != __base + local_38);
        }
        pcVar2 = Curl_cfree;
        *(undefined4 *)__base[local_38 - 1] = 0;
        (*pcVar2)(__base);
        return piVar17;
      }
joined_r0x0003f562:
      while (piVar17 != (int *)0x0) {
        piVar17 = (int *)*piVar17;
        (*Curl_cfree)();
      }
    }
  }
  return (int *)0x0;
}

