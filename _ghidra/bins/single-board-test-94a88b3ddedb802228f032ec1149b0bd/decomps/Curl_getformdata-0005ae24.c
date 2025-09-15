
int * Curl_getformdata(int param_1,undefined4 *param_2,int *param_3,char *param_4,int *param_5)

{
  code *pcVar1;
  size_t sVar2;
  int iVar3;
  FILE *__stream;
  int *piVar4;
  char *pcVar5;
  size_t sVar6;
  int iVar7;
  size_t sVar8;
  uint uVar9;
  int *piVar10;
  undefined4 *puVar11;
  bool bVar12;
  undefined4 local_238;
  undefined4 local_234;
  int local_230;
  int iStack_22c;
  undefined1 auStack_228 [516];
  
  *param_2 = 0;
  local_238 = 0;
  local_230 = 0;
  iStack_22c = 0;
  piVar4 = param_3;
  if (param_3 != (int *)0x0) {
    sVar2 = formboundary();
    piVar4 = (int *)0x1b;
    if (sVar2 != 0) {
      pcVar5 = "Content-Type: multipart/form-data";
      if (param_4 != (char *)0x0) {
        pcVar5 = param_4;
      }
      sVar6 = sVar2;
      piVar4 = (int *)AddFormDataf(&local_238,0,"%s; boundary=%s\r\n",pcVar5,sVar2);
      if (piVar4 == (int *)0x0) {
        local_234 = local_238;
        iVar3 = 0;
LAB_0005ae84:
        if ((((local_230 != 0 || iStack_22c != 0) &&
             (piVar4 = (int *)AddFormDataf(&local_238,&local_230,&DAT_0013c1d4,iStack_22c,sVar6),
             piVar4 != (int *)0x0)) ||
            (piVar4 = (int *)AddFormDataf(&local_238,&local_230,"--%s\r\n",sVar2,sVar6),
            piVar4 != (int *)0x0)) ||
           (piVar4 = (int *)AddFormDataf(&local_238,&local_230,
                                         "Content-Disposition: form-data; name=\""),
           piVar4 != (int *)0x0)) goto LAB_0005afd0;
        sVar6 = param_3[2];
        piVar4 = (int *)AddFormData(&local_238,0,param_3[1],sVar6,sVar6,(int)sVar6 >> 0x1f,
                                    &local_230);
        if ((piVar4 != (int *)0x0) ||
           (piVar4 = (int *)AddFormDataf(&local_238,&local_230,&DAT_00183544), piVar4 != (int *)0x0)
           ) goto LAB_0005afd0;
        iVar7 = param_3[9];
        if (iVar7 != 0) {
          (*Curl_cfree)(iVar3);
          iVar3 = formboundary(param_1);
          if (iVar3 == 0) {
            piVar4 = (int *)0x1b;
LAB_0005afd0:
            Curl_formclean(&local_234);
            (*Curl_cfree)(iVar3);
            (*Curl_cfree)(sVar2);
            return piVar4;
          }
          piVar4 = (int *)AddFormDataf(&local_238,&local_230,
                                       "\r\nContent-Type: multipart/mixed; boundary=%s\r\n",iVar3);
          if (piVar4 != (int *)0x0) goto LAB_0005afd0;
          iVar7 = param_3[9];
        }
        piVar4 = (int *)0x0;
        piVar10 = param_3;
        if (iVar7 == 0) goto LAB_0005b056;
LAB_0005af20:
        piVar4 = (int *)AddFormDataf(&local_238,&local_230,
                                     "\r\n--%s\r\nContent-Disposition: attachment",iVar3);
        if (piVar4 == (int *)0x0) {
          piVar4 = (int *)formdata_add_filename(piVar10,&local_238,&local_230);
          while (piVar4 == (int *)0x0) {
            piVar4 = (int *)0x0;
            do {
              if (piVar10[7] == 0) {
                puVar11 = (undefined4 *)piVar10[8];
                if (puVar11 != (undefined4 *)0x0) goto LAB_0005afbe;
                if (piVar4 != (int *)0x0) goto LAB_0005afd0;
              }
              else {
                piVar4 = (int *)AddFormDataf(&local_238,&local_230,"\r\nContent-Type: %s");
                if (piVar4 != (int *)0x0) goto LAB_0005afd0;
                for (puVar11 = (undefined4 *)piVar10[8]; puVar11 != (undefined4 *)0x0;
                    puVar11 = (undefined4 *)puVar11[1]) {
LAB_0005afbe:
                  piVar4 = (int *)AddFormDataf(&local_238,&local_230,&DAT_0013c1a0,*puVar11);
                  if (piVar4 != (int *)0x0) goto LAB_0005afd0;
                }
              }
              piVar4 = (int *)AddFormDataf(&local_238,&local_230,"\r\n\r\n");
              if (piVar4 != (int *)0x0) goto LAB_0005afd0;
              sVar8 = param_3[10];
              if ((sVar8 & 3) == 0) {
                if ((int)(sVar8 << 0x1b) < 0) {
                  sVar6 = param_3[6];
                  piVar4 = (int *)AddFormData(&local_238,1,param_3[5],sVar6,sVar6,(int)sVar6 >> 0x1f
                                              ,&local_230);
                  uVar9 = 1 - (int)piVar4;
                  if ((int *)0x1 < piVar4) {
                    uVar9 = 0;
                  }
                }
                else if ((int)(sVar8 << 0x19) < 0) {
                  sVar6 = sVar8 << 0x18;
                  bVar12 = (int)sVar6 < 0;
                  if (!bVar12) {
                    sVar6 = param_3[4];
                  }
                  if (bVar12) {
                    iVar7 = param_3[0xf];
                    sVar6 = param_3[0xe];
                  }
                  else {
                    iVar7 = (int)sVar6 >> 0x1f;
                  }
                  piVar4 = (int *)AddFormData(&local_238,2,param_3[0xc],sVar6,sVar6,iVar7,&local_230
                                             );
                  uVar9 = 1 - (int)piVar4;
                  if ((int *)0x1 < piVar4) {
                    uVar9 = 0;
                  }
                }
                else {
                  bVar12 = (int)(sVar8 << 0x18) < 0;
                  if (!bVar12) {
                    sVar8 = param_3[4];
                  }
                  if (bVar12) {
                    iVar7 = param_3[0xf];
                    sVar6 = param_3[0xe];
                  }
                  else {
                    iVar7 = (int)sVar8 >> 0x1f;
                    sVar6 = sVar8;
                  }
                  piVar4 = (int *)AddFormData(&local_238,1,param_3[3],sVar6,sVar6,iVar7,&local_230);
                  uVar9 = 1 - (int)piVar4;
                  if ((int *)0x1 < piVar4) {
                    uVar9 = 0;
                  }
                }
              }
              else {
                iVar7 = curl_strequal("-",piVar10[3]);
                __stream = stdin;
                if (iVar7 == 0) {
                  __stream = fopen64((char *)piVar10[3],"rb");
                }
                if (__stream == (FILE *)0x0) {
                  if (param_1 != 0) {
                    Curl_failf(param_1,"couldn\'t open file \"%s\"",piVar10[3]);
                  }
                  piVar4 = (int *)0x1a;
                  *param_2 = 0;
                  goto LAB_0005afd0;
                }
                if (__stream == stdin) {
                  do {
                    sVar8 = fread(auStack_228,1,0x200,__stream);
                    uVar9 = 1;
                    if (sVar8 == 0) {
                      piVar4 = (int *)0x0;
                      goto LAB_0005b03e;
                    }
                    piVar4 = (int *)AddFormData(&local_238,1,auStack_228,0,sVar8,0,&local_230);
                    sVar6 = sVar8;
                  } while (piVar4 == (int *)0x0);
                  uVar9 = 0;
                }
                else {
                  fclose(__stream);
                  sVar6 = 0;
                  piVar4 = (int *)AddFormData(&local_238,3,piVar10[3],0,0,0,&local_230);
                  uVar9 = 1 - (int)piVar4;
                  if ((int *)0x1 < piVar4) {
                    uVar9 = 0;
                  }
                }
              }
LAB_0005b03e:
              piVar10 = (int *)piVar10[9];
              if (piVar10 == (int *)0x0) {
                uVar9 = 0;
              }
              else {
                uVar9 = uVar9 & 1;
              }
              if (uVar9 == 0) {
                if ((piVar4 != (int *)0x0) ||
                   ((param_3[9] != 0 &&
                    (piVar4 = (int *)AddFormDataf(&local_238,&local_230,"\r\n--%s--",iVar3),
                    piVar4 != (int *)0x0)))) goto LAB_0005afd0;
                param_3 = (int *)*param_3;
                if (param_3 != (int *)0x0) goto LAB_0005ae84;
                piVar4 = (int *)AddFormDataf(&local_238,&local_230,&DAT_0013c1cc,sVar2);
                pcVar1 = Curl_cfree;
                if (piVar4 == (int *)0x0) {
                  *param_5 = local_230;
                  param_5[1] = iStack_22c;
                  (*pcVar1)(iVar3);
                  (*Curl_cfree)(sVar2);
                  *param_2 = local_234;
                  return (int *)0x0;
                }
                goto LAB_0005afd0;
              }
              if (param_3[9] != 0) goto LAB_0005af20;
LAB_0005b056:
            } while ((param_3[10] & 0x51U) == 0);
            if ((param_3[0xb] != 0) || (param_3[10] << 0x1f < 0)) {
              piVar4 = (int *)formdata_add_filename(param_3,&local_238,&local_230);
            }
          }
        }
        goto LAB_0005afd0;
      }
      (*Curl_cfree)(sVar2);
    }
  }
  return piVar4;
}

