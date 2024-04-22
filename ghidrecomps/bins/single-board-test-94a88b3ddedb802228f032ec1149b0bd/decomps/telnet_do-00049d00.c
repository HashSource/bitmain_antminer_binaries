
int telnet_do(int *param_1,undefined *param_2)

{
  byte bVar1;
  code **ppcVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int **ppiVar7;
  int iVar8;
  int **ppiVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  void *__buf;
  int iVar19;
  uint uVar20;
  int iVar21;
  int **ppiVar22;
  bool bVar23;
  bool bVar24;
  undefined8 uVar25;
  undefined4 local_88;
  undefined4 local_84;
  int local_74;
  uint local_70;
  int iStack_6c;
  uint local_60;
  int iStack_5c;
  uint local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  int local_38;
  undefined2 local_34;
  ushort local_32;
  int local_30;
  undefined2 local_2c;
  ushort local_2a;
  
  ppcVar2 = DAT_00049fa0;
  iVar14 = param_1[0x55];
  iVar21 = 0x1b;
  iVar19 = *param_1;
  *param_2 = 1;
  iVar4 = (**ppcVar2)(1,0x1ebc);
  if (iVar4 != 0) {
    *(int *)(*param_1 + 0x14c) = iVar4;
    *(undefined4 *)(iVar4 + 0x1eb8) = 0;
    piVar15 = *(int **)(iVar19 + 0x14c);
    *(undefined4 *)(iVar4 + 0x814) = 1;
    *(undefined4 *)(iVar4 + 0x808) = 1;
    *(int *)(iVar4 + 0x1eb0) = iVar4 + 0x1cb0;
    *(undefined4 *)(iVar4 + 0x1414) = 1;
    *(undefined4 *)(iVar4 + 0x1408) = 1;
    *(undefined4 *)(iVar4 + 0x140c) = 1;
    *(undefined4 *)(iVar4 + 0x1884) = 1;
    iVar21 = check_telnet_options(param_1);
    if (iVar21 == 0) {
      local_34 = 1;
      local_38 = iVar14;
      if (*(int *)(iVar19 + 0x1b8) == 0) {
        local_88 = 2;
        local_74 = 2;
        local_30 = fileno(*(FILE **)(iVar19 + 0x86c4));
        local_84 = 1000;
        local_2c = 1;
      }
      else {
        local_88 = 1;
        local_84 = 100;
        local_74 = 1;
      }
      local_70 = 0;
      iStack_6c = 0;
      __buf = (void *)(iVar19 + 0x59c);
      local_60 = 0;
      iStack_5c = 0;
      iVar4 = 0;
LAB_00049da8:
      iVar21 = Curl_poll(&local_38,local_88,local_84);
      if (iVar21 != -1) {
        if (iVar21 == 0) {
          local_32 = 0;
          local_2a = 0;
          goto LAB_0004a1c2;
        }
        if (-1 < (int)((uint)local_32 << 0x1f)) goto LAB_0004a1c2;
        uVar25 = Curl_read(param_1,iVar14,__buf,0x3fff,&local_44);
        iVar4 = (int)uVar25;
        iVar21 = iVar4;
        if (iVar4 == 0x51) goto LAB_0004a1d4;
        if ((iVar4 != 0) || ((int)local_44 < 1)) goto LAB_0004a1f2;
        bVar23 = CARRY4(local_60,local_44);
        local_60 = local_60 + local_44;
        iStack_5c = iStack_5c + ((int)local_44 >> 0x1f) + (uint)bVar23;
        Curl_pgrsSetDownloadCounter(iVar19,(int)((ulonglong)uVar25 >> 0x20),local_60,iStack_5c);
        uVar3 = local_44;
        iVar16 = *param_1;
        puVar17 = *(undefined4 **)(iVar16 + 0x14c);
        if (local_44 == 0) {
LAB_0004a14e:
          if ((*piVar15 != 0) && (piVar15[1] == 0)) {
            iVar16 = 1;
            piVar11 = (int *)(*(int *)(*param_1 + 0x14c) + 0x808);
            iVar21 = 0;
            do {
              if (iVar21 != 1) {
                if (*piVar11 == 1) {
                  iVar6 = *(int *)(*param_1 + 0x14c);
                  iVar8 = *(int *)(iVar6 + (iVar21 + 2) * 4);
                  if (iVar8 == 2) {
                    if (*(int *)(iVar6 + (iVar21 + 0x102) * 4) == 1) {
                      *(undefined4 *)(iVar6 + (iVar21 + 0x102) * 4) = 0;
                    }
                  }
                  else if (iVar8 == 3) {
                    if (*(int *)(iVar6 + (iVar21 + 0x102) * 4) == 0) {
                      *(undefined4 *)(iVar6 + (iVar21 + 0x102) * 4) = 1;
                    }
                  }
                  else if (iVar8 == 0) {
                    *(undefined4 *)(iVar6 + (iVar21 + 2) * 4) = 2;
                    send_negotiation(param_1,0xfb,iVar21);
                  }
                }
                if (piVar11[0x300] == 1) {
                  iVar6 = *(int *)(*param_1 + 0x14c);
                  iVar8 = *(int *)(iVar6 + (iVar21 + 0x302) * 4);
                  if (iVar8 == 2) {
                    if (*(int *)(iVar6 + (iVar21 + 0x402) * 4) == 1) {
                      *(undefined4 *)(iVar6 + (iVar21 + 0x402) * 4) = 0;
                    }
                  }
                  else if (iVar8 == 3) {
                    if (*(int *)(iVar6 + (iVar21 + 0x402) * 4) == 0) {
                      *(undefined4 *)(iVar6 + (iVar21 + 0x402) * 4) = 1;
                    }
                  }
                  else if (iVar8 == 0) {
                    *(undefined4 *)(iVar6 + (iVar21 + 0x302) * 4) = 2;
                    send_negotiation(param_1,0xfd,iVar21);
                  }
                }
                if (iVar16 == 0x28) goto LAB_0004a4b6;
              }
              iVar21 = iVar21 + 1;
              iVar16 = iVar16 + 1;
              piVar11 = piVar11 + 1;
            } while( true );
          }
          goto LAB_0004a1c2;
        }
        ppiVar22 = (int **)(puVar17 + 0x7ac);
        puVar18 = puVar17 + 0x7ae;
        uVar20 = 0xffffffff;
        piVar11 = puVar17 + 0x72c;
        uVar12 = 0;
LAB_00049e42:
        do {
          uVar10 = uVar12;
          bVar1 = *(byte *)((int)__buf + uVar10);
          uVar12 = (uint)bVar1;
          switch(*puVar18) {
          case 0:
            if (uVar12 != 0xff) {
              if (uVar12 == 0xd) {
                *puVar18 = 6;
              }
LAB_0004a0e0:
              if (uVar20 == 0xffffffff) {
                uVar20 = uVar10;
              }
              goto joined_r0x00049fda;
            }
            *puVar18 = 1;
            if ((uVar20 == 0xffffffff) ||
               (iVar21 = Curl_client_write(param_1,1,(int)__buf + uVar20,uVar10 - uVar20),
               iVar21 == 0)) goto LAB_00049fd2;
            goto LAB_00049f0e;
          case 1:
switchD_00049e4c_caseD_1:
            switch(uVar12) {
            case 0xfa:
              *puVar18 = 7;
              *ppiVar22 = piVar11;
              break;
            case 0xfb:
              *puVar18 = 2;
              break;
            case 0xfc:
              *puVar18 = 3;
              break;
            case 0xfd:
              *puVar18 = 4;
              break;
            case 0xfe:
              *puVar18 = 5;
              break;
            case 0xff:
              *puVar18 = 0;
              goto LAB_0004a0e0;
            default:
              *puVar18 = 0;
              printoption(iVar16,DAT_0004a294,0xff,uVar12);
            }
            break;
          case 2:
            printoption(iVar16,DAT_0004a294,0xfb,uVar12);
            iVar21 = uVar12 + 0x302;
            iVar8 = *(int *)(*param_1 + 0x14c);
            *puVar17 = 1;
            iVar6 = *(int *)(iVar8 + iVar21 * 4);
            if (iVar6 == 2) {
              iVar6 = *(int *)(iVar8 + (uVar12 + 0x402) * 4);
              if (iVar6 == 0) {
                iVar6 = 1;
LAB_0004a302:
                *(int *)(iVar8 + iVar21 * 4) = iVar6;
              }
              else if (iVar6 == 1) {
                *(undefined4 *)(iVar8 + (uVar12 + 0x402) * 4) = 0;
                *(undefined4 *)(iVar8 + iVar21 * 4) = 3;
                send_negotiation(param_1,0xfe,uVar12);
              }
            }
            else if (iVar6 == 3) {
              iVar6 = *(int *)(iVar8 + (uVar12 + 0x402) * 4);
              if (iVar6 == 0) goto LAB_0004a302;
              if (iVar6 == 1) {
                *(undefined4 *)(iVar8 + iVar21 * 4) = 1;
                *(uint *)(iVar8 + (uVar12 + 0x402) * 4) = (uint)(iVar6 != 1);
              }
            }
            else if (iVar6 == 0) {
              if (*(int *)(iVar8 + (uVar12 + 0x502) * 4) == 1) {
                *(undefined4 *)(iVar8 + iVar21 * 4) = 1;
                uVar5 = 0xfd;
              }
              else {
                uVar5 = 0xfe;
              }
              send_negotiation(param_1,uVar5,uVar12);
            }
            *puVar18 = 0;
            break;
          case 3:
            printoption(iVar16,DAT_0004a294,0xfc,uVar12);
            iVar21 = uVar12 + 0x302;
            iVar8 = *(int *)(*param_1 + 0x14c);
            *puVar17 = 1;
            iVar6 = *(int *)(iVar8 + iVar21 * 4);
            if (iVar6 == 2) {
              iVar13 = uVar12 + 0x402;
              iVar6 = *(int *)(iVar8 + iVar13 * 4);
              if (iVar6 == 0) goto LAB_0004a366;
LAB_0004a378:
              if (iVar6 == 1) {
                *(undefined4 *)(iVar8 + iVar21 * 4) = 0;
                *(undefined4 *)(iVar8 + iVar13 * 4) = 0;
              }
            }
            else if (iVar6 == 3) {
              iVar6 = *(int *)(iVar8 + (uVar12 + 0x402) * 4);
              if (iVar6 == 0) goto LAB_0004a366;
              if (iVar6 == 1) {
                *(undefined4 *)(iVar8 + (uVar12 + 0x402) * 4) = 0;
                *(undefined4 *)(iVar8 + iVar21 * 4) = 2;
                send_negotiation(param_1,0xfd,uVar12);
              }
            }
            else if (iVar6 == 1) {
              *(undefined4 *)(iVar8 + iVar21 * 4) = 0;
              send_negotiation(param_1,0xfe,uVar12);
            }
            goto LAB_0004a020;
          case 4:
            printoption(iVar16,DAT_00049fa4,0xfd,uVar12);
            iVar21 = uVar12 + 2;
            iVar8 = *(int *)(*param_1 + 0x14c);
            *puVar17 = 1;
            iVar6 = *(int *)(iVar8 + iVar21 * 4);
            if (iVar6 == 2) {
              iVar6 = *(int *)(iVar8 + (uVar12 + 0x102) * 4);
              if (iVar6 == 0) {
                *(undefined4 *)(iVar8 + iVar21 * 4) = 1;
                iVar21 = *(int *)(iVar8 + (uVar12 + 0x602) * 4);
joined_r0x0004a324:
                if (iVar21 == 1) {
                  sendsuboption(param_1,uVar12);
                }
              }
              else if (iVar6 == 1) {
                *(undefined4 *)(iVar8 + iVar21 * 4) = 3;
                *(undefined4 *)(iVar8 + (uVar12 + 0x402) * 4) = 0;
                send_negotiation(param_1,0xfc,uVar12);
              }
            }
            else if (iVar6 == 3) {
              iVar6 = *(int *)(iVar8 + (uVar12 + 0x102) * 4);
              if (iVar6 == 0) {
                *(undefined4 *)(iVar8 + iVar21 * 4) = 0;
              }
              else if (iVar6 == 1) {
                *(undefined4 *)(iVar8 + iVar21 * 4) = 1;
                *(undefined4 *)(iVar8 + (uVar12 + 0x102) * 4) = 0;
              }
            }
            else if (iVar6 == 0) {
              if (*(int *)(iVar8 + (uVar12 + 0x202) * 4) == 1) {
                *(undefined4 *)(iVar8 + iVar21 * 4) = 1;
                send_negotiation(param_1,0xfb,uVar12);
                iVar21 = *(int *)(iVar8 + (uVar12 + 0x602) * 4);
                goto joined_r0x0004a324;
              }
              if (*(int *)(iVar8 + (uVar12 + 0x602) * 4) == 1) {
                *(undefined4 *)(iVar8 + iVar21 * 4) = 1;
                send_negotiation(param_1,0xfb,uVar12);
                sendsuboption(param_1,uVar12);
              }
              else {
                send_negotiation(param_1,0xfc,uVar12);
              }
            }
            *puVar18 = 0;
            break;
          case 5:
            printoption(iVar16,DAT_0004a294,0xfe,uVar12);
            iVar21 = uVar12 + 2;
            iVar8 = *(int *)(*param_1 + 0x14c);
            *puVar17 = 1;
            iVar6 = *(int *)(iVar8 + iVar21 * 4);
            if (iVar6 == 2) {
              iVar13 = uVar12 + 0x102;
              iVar6 = *(int *)(iVar8 + iVar13 * 4);
              if (iVar6 != 0) goto LAB_0004a378;
LAB_0004a366:
              *(int *)(iVar8 + iVar21 * 4) = iVar6;
            }
            else if (iVar6 == 3) {
              iVar6 = *(int *)(iVar8 + (uVar12 + 0x102) * 4);
              if (iVar6 == 0) goto LAB_0004a366;
              if (iVar6 == 1) {
                *(undefined4 *)(iVar8 + (uVar12 + 0x102) * 4) = 0;
                *(undefined4 *)(iVar8 + iVar21 * 4) = 2;
                send_negotiation(param_1,0xfb,uVar12);
              }
            }
            else if (iVar6 == 1) {
              *(undefined4 *)(iVar8 + iVar21 * 4) = 0;
              send_negotiation(param_1,0xfc,uVar12);
            }
LAB_0004a020:
            *puVar18 = 0;
            break;
          case 6:
            *puVar18 = 0;
            if (uVar12 != 0) goto LAB_0004a0e0;
            if ((uVar20 != 0xffffffff) &&
               (iVar21 = Curl_client_write(param_1,1,(int)__buf + uVar20,uVar10 - uVar20),
               iVar21 != 0)) goto LAB_00049f0e;
LAB_00049fd2:
            uVar20 = 0xffffffff;
joined_r0x00049fda:
            uVar12 = uVar10 + 1;
            if (uVar10 + 1 == uVar3) goto LAB_00049eea;
            goto LAB_00049e42;
          case 7:
            if (uVar12 == 0xff) {
              *puVar18 = 8;
            }
            else {
              ppiVar9 = (int **)*ppiVar22;
              if (ppiVar9 < ppiVar22) {
                *(byte *)ppiVar9 = bVar1;
                *ppiVar22 = (int *)((int)ppiVar9 + 1);
              }
            }
            break;
          case 8:
            ppiVar9 = (int **)*ppiVar22;
            if (uVar12 == 0xf0) {
              if (ppiVar9 < ppiVar22) {
                ppiVar7 = (int **)((int)ppiVar9 + 1);
                *(undefined *)ppiVar9 = 0xff;
                *ppiVar22 = (int *)ppiVar7;
                if (ppiVar22 <= ppiVar7) {
                  ppiVar9 = ppiVar7;
                }
                if (ppiVar7 < ppiVar22) {
                  *(byte *)((int)ppiVar9 + 1) = bVar1;
                  ppiVar9 = (int **)((int)ppiVar9 + 2);
                }
              }
              puVar17[0x7ad] = (int)ppiVar9 + -2;
              *ppiVar22 = piVar11;
              suboption(param_1);
              goto LAB_0004a020;
            }
            if (uVar12 != 0xff) {
              if (ppiVar9 < ppiVar22) {
                ppiVar7 = (int **)((int)ppiVar9 + 1);
                *(undefined *)ppiVar9 = 0xff;
                *ppiVar22 = (int *)ppiVar7;
                if (ppiVar22 <= ppiVar7) {
                  ppiVar9 = ppiVar7;
                }
                if (ppiVar7 < ppiVar22) {
                  *(byte *)((int)ppiVar9 + 1) = bVar1;
                  ppiVar9 = (int **)((int)ppiVar9 + 2);
                }
              }
              uVar5 = DAT_00049fa8;
              *ppiVar22 = piVar11;
              puVar17[0x7ad] = (int)ppiVar9 + -2;
              printoption(iVar16,uVar5,0xff,uVar12);
              suboption(param_1);
              *puVar18 = 1;
              goto switchD_00049e4c_caseD_1;
            }
            if (ppiVar9 < ppiVar22) {
              *(byte *)ppiVar9 = bVar1;
              *ppiVar22 = (int *)((int)ppiVar9 + 1);
            }
            *puVar18 = 7;
          }
          uVar12 = uVar10 + 1;
        } while (uVar10 + 1 != uVar3);
LAB_00049eea:
        if ((uVar20 == 0xffffffff) ||
           (iVar21 = Curl_client_write(param_1,1,(int)__buf + uVar20,(uVar10 + 1) - uVar20),
           iVar21 == 0)) goto LAB_0004a14e;
LAB_00049f0e:
        bVar23 = false;
        goto LAB_0004a1d6;
      }
      goto LAB_00049e66;
    }
  }
  return iVar21;
LAB_0004a4b6:
  piVar15[1] = 1;
LAB_0004a1c2:
  local_44 = 0;
  iVar21 = iVar4;
  if (local_74 == 2) {
    if (-1 < (int)((uint)local_2a << 0x1f)) goto LAB_0004a1d4;
    local_44 = read(local_30,__buf,0x3fff);
LAB_0004a250:
    if ((int)local_44 < 1) {
      if (local_44 == 0) goto LAB_0004a1d4;
LAB_0004a1f2:
      iVar16 = *(int *)(iVar19 + 0x200);
      bVar23 = false;
      goto joined_r0x0004a1fa;
    }
    uVar25 = send_telnet_data(param_1,__buf);
    iVar21 = (int)uVar25;
    iVar4 = iVar21;
    if (iVar21 != 0) goto LAB_0004a1f2;
    bVar23 = true;
    bVar24 = CARRY4(local_70,local_44);
    local_70 = local_70 + local_44;
    iStack_6c = iStack_6c + ((int)local_44 >> 0x1f) + (uint)bVar24;
    Curl_pgrsSetUploadCounter(iVar19,(int)((ulonglong)uVar25 >> 0x20),local_70,iStack_6c);
  }
  else {
    local_44 = (**(code **)(iVar19 + 0x86c0))(__buf,1,0x3fff,*(undefined4 *)(iVar19 + 0x86c4));
    if (local_44 == 0x10000000) goto LAB_0004a1f2;
    if (local_44 != 0x10000001) goto LAB_0004a250;
LAB_0004a1d4:
    bVar23 = true;
  }
LAB_0004a1d6:
  iVar16 = *(int *)(iVar19 + 0x200);
  iVar4 = iVar21;
joined_r0x0004a1fa:
  if (iVar16 != 0) {
    curlx_tvnow(&local_40);
    iVar21 = curlx_tvdiff(local_40,uStack_3c,param_1[0x53],param_1[0x54]);
    if (*(int *)(iVar19 + 0x200) <= iVar21) {
      bVar23 = false;
      iVar4 = 0x1c;
      Curl_failf(iVar19,DAT_0004a298);
    }
  }
  iVar21 = Curl_pgrsUpdate(param_1);
  if (iVar21 != 0) {
    iVar4 = 0x2a;
    goto LAB_00049e66;
  }
  if (!bVar23) {
LAB_00049e66:
    Curl_setup_transfer(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,0xffffffff,0);
    return iVar4;
  }
  goto LAB_00049da8;
}

