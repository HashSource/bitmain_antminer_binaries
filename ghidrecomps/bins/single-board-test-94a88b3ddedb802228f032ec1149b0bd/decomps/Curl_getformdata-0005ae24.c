
int * Curl_getformdata(int param_1,undefined4 *param_2,int *param_3,int param_4,uint *param_5)

{
  code **ppcVar1;
  FILE **ppFVar2;
  size_t sVar3;
  int iVar4;
  int *piVar5;
  size_t sVar6;
  int iVar7;
  size_t sVar8;
  uint uVar9;
  code *pcVar10;
  int *piVar11;
  undefined4 *puVar12;
  FILE *__stream;
  bool bVar13;
  undefined4 local_238;
  undefined4 local_234;
  uint local_230;
  uint uStack_22c;
  undefined auStack_228 [516];
  
  *param_2 = 0;
  local_238 = 0;
  local_230 = 0;
  uStack_22c = 0;
  piVar5 = param_3;
  if (param_3 != (int *)0x0) {
    sVar3 = formboundary();
    piVar5 = (int *)0x1b;
    if (sVar3 != 0) {
      iVar4 = DAT_0005b074;
      if (param_4 != 0) {
        iVar4 = param_4;
      }
      sVar6 = sVar3;
      piVar5 = (int *)AddFormDataf(&local_238,0,DAT_0005b078,iVar4,sVar3);
      ppcVar1 = DAT_0005b0a8;
      if (piVar5 == (int *)0x0) {
        local_234 = local_238;
        iVar4 = 0;
LAB_0005ae84:
        if (((((local_230 | uStack_22c) != 0) &&
             (piVar5 = (int *)AddFormDataf(&local_238,&local_230,DAT_0005b07c,uStack_22c,sVar6),
             piVar5 != (int *)0x0)) ||
            (piVar5 = (int *)AddFormDataf(&local_238,&local_230,DAT_0005b080,sVar3,sVar6),
            piVar5 != (int *)0x0)) ||
           (piVar5 = (int *)AddFormDataf(&local_238,&local_230,DAT_0005b084), piVar5 != (int *)0x0))
        goto LAB_0005afd0;
        sVar6 = param_3[2];
        piVar5 = (int *)AddFormData(&local_238,0,param_3[1],sVar6,sVar6,(int)sVar6 >> 0x1f,
                                    &local_230);
        if ((piVar5 != (int *)0x0) ||
           (piVar5 = (int *)AddFormDataf(&local_238,&local_230,DAT_0005b088), piVar5 != (int *)0x0))
        goto LAB_0005afd0;
        iVar7 = param_3[9];
        if (iVar7 != 0) {
          (**ppcVar1)(iVar4);
          iVar4 = formboundary(param_1);
          if (iVar4 == 0) {
            piVar5 = (int *)0x1b;
LAB_0005afd0:
            Curl_formclean(&local_234);
            (**ppcVar1)(iVar4);
            (**ppcVar1)(sVar3);
            return piVar5;
          }
          piVar5 = (int *)AddFormDataf(&local_238,&local_230,DAT_0005b08c,iVar4);
          if (piVar5 != (int *)0x0) goto LAB_0005afd0;
          iVar7 = param_3[9];
        }
        ppFVar2 = DAT_0005b0ac;
        piVar5 = (int *)0x0;
        piVar11 = param_3;
        if (iVar7 == 0) goto LAB_0005b056;
LAB_0005af20:
        piVar5 = (int *)AddFormDataf(&local_238,&local_230,DAT_0005b090,iVar4);
        if (piVar5 == (int *)0x0) {
          piVar5 = (int *)formdata_add_filename(piVar11,&local_238,&local_230);
          while (piVar5 == (int *)0x0) {
            piVar5 = (int *)0x0;
            do {
              if (piVar11[7] == 0) {
                puVar12 = (undefined4 *)piVar11[8];
                if (puVar12 != (undefined4 *)0x0) goto LAB_0005afbe;
                if (piVar5 != (int *)0x0) goto LAB_0005afd0;
              }
              else {
                piVar5 = (int *)AddFormDataf(&local_238,&local_230,DAT_0005b094);
                if (piVar5 != (int *)0x0) goto LAB_0005afd0;
                for (puVar12 = (undefined4 *)piVar11[8]; puVar12 != (undefined4 *)0x0;
                    puVar12 = (undefined4 *)puVar12[1]) {
LAB_0005afbe:
                  piVar5 = (int *)AddFormDataf(&local_238,&local_230,DAT_0005b0a0,*puVar12);
                  if (piVar5 != (int *)0x0) goto LAB_0005afd0;
                }
              }
              piVar5 = (int *)AddFormDataf(&local_238,&local_230,DAT_0005b0a4);
              if (piVar5 != (int *)0x0) goto LAB_0005afd0;
              sVar8 = param_3[10];
              if ((sVar8 & 3) == 0) {
                if ((int)(sVar8 << 0x1b) < 0) {
                  sVar6 = param_3[6];
                  piVar5 = (int *)AddFormData(&local_238,1,param_3[5],sVar6,sVar6,(int)sVar6 >> 0x1f
                                              ,&local_230);
                  uVar9 = 1 - (int)piVar5;
                  if ((int *)0x1 < piVar5) {
                    uVar9 = 0;
                  }
                }
                else if ((int)(sVar8 << 0x19) < 0) {
                  sVar6 = sVar8 << 0x18;
                  bVar13 = (int)sVar6 < 0;
                  if (!bVar13) {
                    sVar6 = param_3[4];
                  }
                  if (bVar13) {
                    iVar7 = param_3[0xf];
                    sVar6 = param_3[0xe];
                  }
                  else {
                    iVar7 = (int)sVar6 >> 0x1f;
                  }
                  piVar5 = (int *)AddFormData(&local_238,2,param_3[0xc],sVar6,sVar6,iVar7,&local_230
                                             );
                  uVar9 = 1 - (int)piVar5;
                  if ((int *)0x1 < piVar5) {
                    uVar9 = 0;
                  }
                }
                else {
                  bVar13 = (int)(sVar8 << 0x18) < 0;
                  if (!bVar13) {
                    sVar8 = param_3[4];
                  }
                  if (bVar13) {
                    iVar7 = param_3[0xf];
                    sVar6 = param_3[0xe];
                  }
                  else {
                    iVar7 = (int)sVar8 >> 0x1f;
                    sVar6 = sVar8;
                  }
                  piVar5 = (int *)AddFormData(&local_238,1,param_3[3],sVar6,sVar6,iVar7,&local_230);
                  uVar9 = 1 - (int)piVar5;
                  if ((int *)0x1 < piVar5) {
                    uVar9 = 0;
                  }
                }
              }
              else {
                iVar7 = curl_strequal(DAT_0005b1b0,piVar11[3]);
                if (iVar7 == 0) {
                  __stream = fopen64((char *)piVar11[3],DAT_0005b1b4);
                }
                else {
                  __stream = *ppFVar2;
                }
                if (__stream == (FILE *)0x0) {
                  if (param_1 != 0) {
                    Curl_failf(param_1,DAT_0005b1b8,piVar11[3]);
                  }
                  piVar5 = (int *)0x1a;
                  *param_2 = 0;
                  goto LAB_0005afd0;
                }
                if (__stream == *ppFVar2) {
                  do {
                    sVar8 = fread(auStack_228,1,0x200,__stream);
                    uVar9 = 1;
                    if (sVar8 == 0) {
                      piVar5 = (int *)0x0;
                      goto LAB_0005b03e;
                    }
                    piVar5 = (int *)AddFormData(&local_238,1,auStack_228,0,sVar8,0,&local_230);
                    sVar6 = sVar8;
                  } while (piVar5 == (int *)0x0);
                  uVar9 = 0;
                }
                else {
                  fclose(__stream);
                  sVar6 = 0;
                  piVar5 = (int *)AddFormData(&local_238,3,piVar11[3],0,0,0,&local_230);
                  uVar9 = 1 - (int)piVar5;
                  if ((int *)0x1 < piVar5) {
                    uVar9 = 0;
                  }
                }
              }
LAB_0005b03e:
              piVar11 = (int *)piVar11[9];
              if (piVar11 == (int *)0x0) {
                uVar9 = 0;
              }
              else {
                uVar9 = uVar9 & 1;
              }
              if (uVar9 == 0) {
                if ((piVar5 != (int *)0x0) ||
                   ((param_3[9] != 0 &&
                    (piVar5 = (int *)AddFormDataf(&local_238,&local_230,DAT_0005b098,iVar4),
                    piVar5 != (int *)0x0)))) goto LAB_0005afd0;
                param_3 = (int *)*param_3;
                if (param_3 != (int *)0x0) goto LAB_0005ae84;
                piVar5 = (int *)AddFormDataf(&local_238,&local_230,DAT_0005b09c,sVar3);
                if (piVar5 == (int *)0x0) {
                  pcVar10 = *ppcVar1;
                  *param_5 = local_230;
                  param_5[1] = uStack_22c;
                  (*pcVar10)(iVar4);
                  (**ppcVar1)(sVar3);
                  *param_2 = local_234;
                  return (int *)0x0;
                }
                goto LAB_0005afd0;
              }
              if (param_3[9] != 0) goto LAB_0005af20;
LAB_0005b056:
            } while ((param_3[10] & 0x51U) == 0);
            if ((param_3[0xb] != 0) || (param_3[10] << 0x1f < 0)) {
              piVar5 = (int *)formdata_add_filename(param_3,&local_238,&local_230);
            }
          }
        }
        goto LAB_0005afd0;
      }
      (**DAT_0005b1bc)(sVar3);
    }
  }
  return piVar5;
}

