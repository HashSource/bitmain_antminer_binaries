
int tftp_multi_statemach(int *param_1,undefined *param_2)

{
  undefined uVar1;
  undefined uVar2;
  void *pvVar3;
  int iVar4;
  long lVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 extraout_r1;
  int iVar8;
  undefined *puVar9;
  int *piVar10;
  uint uVar11;
  char *__nptr;
  int iVar12;
  char *__s;
  int iVar13;
  uint uVar14;
  size_t sVar15;
  uint uVar16;
  char *pcVar17;
  int local_b0;
  size_t local_ac;
  sockaddr asStack_a8 [8];
  
  piVar10 = (int *)param_1[0xf0];
  iVar12 = *param_1;
  time(&local_b0);
  iVar8 = piVar10[10];
  if (iVar8 < local_b0) {
    piVar10[2] = -99;
    *piVar10 = 3;
    *param_2 = 0;
LAB_0004e6e2:
    Curl_failf(iVar12,DAT_0004e978);
    iVar8 = 0x1c;
  }
  else {
    if (piVar10[0xb] + piVar10[7] < local_b0) {
      time(piVar10 + 0xb);
      iVar8 = piVar10[10];
      *param_2 = 0;
      if (iVar8 - local_b0 < 1) goto LAB_0004e6e2;
      iVar8 = tftp_state_machine(piVar10,7);
joined_r0x0004e6ba:
      if (iVar8 != 0) {
        return iVar8;
      }
      iVar8 = *piVar10;
      *param_2 = iVar8 == 3;
      if (iVar8 == 3) {
        Curl_setup_transfer(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,0xffffffff,0);
        return 0;
      }
    }
    else {
      *param_2 = 0;
      if (iVar8 - local_b0 < 1) goto LAB_0004e6e2;
      iVar8 = Curl_socket_check(piVar10[5],0xffffffff,0xffffffff,0);
      if (iVar8 == -1) {
        piVar6 = __errno_location();
        uVar7 = Curl_strerror(param_1,*piVar6);
        Curl_failf(iVar12,DAT_0004e97c,uVar7);
        piVar10[3] = 5;
        return 0;
      }
      if (iVar8 != 0) {
        iVar13 = param_1[0xf0];
        iVar12 = *param_1;
        local_ac = 0x80;
        iVar8 = recvfrom(*(int *)(iVar13 + 0x14),*(void **)(iVar13 + 0x148),
                         *(int *)(iVar13 + 0x140) + 4,0,asStack_a8,&local_ac);
        *(int *)(iVar13 + 0x138) = iVar8;
        if (*(int *)(iVar13 + 0x134) == 0) {
          memcpy((void *)(iVar13 + 0xb4),asStack_a8,local_ac);
          iVar8 = *(int *)(iVar13 + 0x138);
          *(size_t *)(iVar13 + 0x134) = local_ac;
        }
        if (iVar8 < 4) {
          Curl_failf(iVar12,DAT_0004e9a4);
          *(undefined4 *)(iVar13 + 0xc) = 7;
        }
        else {
          puVar9 = *(undefined **)(iVar13 + 0x148);
          uVar1 = puVar9[1];
          uVar2 = *puVar9;
          *(uint *)(iVar13 + 0xc) = (uint)CONCAT11(uVar2,uVar1);
          uVar7 = DAT_0004e9a0;
          switch((uint)CONCAT11(uVar2,uVar1)) {
          case 3:
            if ((iVar8 != 4) &&
               ((short)(*(short *)(iVar13 + 0x30) + 1) == CONCAT11(puVar9[2],puVar9[3]))) {
              iVar8 = Curl_client_write(param_1,1,puVar9 + 4,iVar8 + -4);
              if (iVar8 != 0) {
                tftp_state_machine(iVar13,5);
                return iVar8;
              }
              uVar11 = *(uint *)(iVar12 + 0x70);
              uVar16 = *(int *)(iVar13 + 0x138) - 4;
              *(uint *)(iVar12 + 0x70) = uVar11 + uVar16;
              *(uint *)(iVar12 + 0x74) =
                   *(int *)(iVar12 + 0x74) + ((int)uVar16 >> 0x1f) + (uint)CARRY4(uVar11,uVar16);
              Curl_pgrsSetDownloadCounter(iVar12);
            }
            break;
          case 4:
            break;
          case 5:
            *(uint *)(iVar13 + 8) = (uint)CONCAT11(puVar9[2],puVar9[3]);
            Curl_infof(iVar12,uVar7,puVar9 + 4);
            break;
          case 6:
            iVar12 = **(int **)(iVar13 + 0x10);
            *(undefined4 *)(iVar13 + 0x140) = 0x200;
            __s = puVar9 + 2;
            while (__s < puVar9 + iVar8) {
              uVar11 = (int)(puVar9 + iVar8) - (int)__s;
              pvVar3 = memchr(__s,0,uVar11);
              uVar16 = uVar11;
              if (pvVar3 != (void *)0x0) {
                uVar16 = (int)pvVar3 - (int)__s;
              }
              uVar14 = uVar16 + 1;
              if (uVar11 <= uVar14) {
LAB_0004e920:
                Curl_failf(iVar12,DAT_0004e9a8);
                return 0x47;
              }
              sVar15 = uVar11 - uVar14;
              pvVar3 = memchr(__s + uVar14,0,sVar15);
              if (pvVar3 != (void *)0x0) {
                sVar15 = (int)pvVar3 - (int)(__s + uVar14);
              }
              uVar16 = sVar15 + uVar16 + 2;
              if (uVar11 < uVar16) goto LAB_0004e920;
              sVar15 = strlen(__s);
              pcVar17 = __s + uVar16;
              __nptr = __s + sVar15 + 1;
              if (pcVar17 == (char *)0x0) goto LAB_0004e920;
              Curl_infof(iVar12,DAT_0004e98c,__s,__nptr);
              sVar15 = strlen(__s);
              iVar4 = Curl_raw_nequal(__s,DAT_0004e990,sVar15);
              if (iVar4 == 0) {
                sVar15 = strlen(__s);
                iVar4 = Curl_raw_nequal(__s,DAT_0004e994,sVar15);
                __s = pcVar17;
                if (iVar4 != 0) {
                  lVar5 = strtol(__nptr,(char **)0x0,10);
                  Curl_infof(iVar12,DAT_0004e998,DAT_0004e99c,lVar5);
                  if (*(char *)(iVar12 + 0x309) == '\0') {
                    if (lVar5 == 0) {
                      Curl_failf(iVar12,DAT_0004e9c4,__nptr);
                      return 0x47;
                    }
                    Curl_pgrsSetDownloadSize(iVar12,extraout_r1,lVar5,lVar5 >> 0x1f);
                  }
                }
              }
              else {
                lVar5 = strtol(__nptr,(char **)0x0,10);
                if (lVar5 == 0) {
                  Curl_failf(iVar12,DAT_0004e9c0);
                  return 0x47;
                }
                if (0xffb8 < lVar5) {
                  Curl_failf(iVar12,DAT_0004e9b4,DAT_0004e9bc,0xffb8);
                  return 0x47;
                }
                if (lVar5 < 8) {
                  Curl_failf(iVar12,DAT_0004e9b4,DAT_0004e9b8,8);
                  return 0x47;
                }
                if (*(int *)(iVar13 + 0x144) < lVar5) {
                  Curl_failf(iVar12,DAT_0004e9ac,DAT_0004e9b0,lVar5);
                  return 0x47;
                }
                *(long *)(iVar13 + 0x140) = lVar5;
                Curl_infof(iVar12,DAT_0004e984,DAT_0004e988,lVar5,"requested",
                           *(int *)(iVar13 + 0x144));
                __s = pcVar17;
              }
            }
            break;
          default:
            Curl_failf(iVar12,DAT_0004e97c,DAT_0004e980);
          }
          iVar8 = Curl_pgrsUpdate(param_1);
          if (iVar8 != 0) {
            tftp_state_machine(iVar13,5);
            return 0x2a;
          }
        }
        iVar8 = tftp_state_machine(piVar10,piVar10[3]);
        goto joined_r0x0004e6ba;
      }
    }
    iVar8 = 0;
  }
  return iVar8;
}

