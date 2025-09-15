
int smb_request_state(int *param_1,undefined1 *param_2)

{
  undefined2 uVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  short sVar13;
  uint uVar14;
  uint uVar15;
  short sVar16;
  undefined8 uVar17;
  undefined2 local_5c;
  undefined1 local_5a;
  int local_58;
  int local_54;
  undefined1 local_50;
  uint3 uStack_4f;
  undefined4 local_4c;
  undefined1 local_48;
  undefined4 local_44;
  undefined1 local_40;
  undefined2 uStack_3f;
  undefined4 uStack_3d;
  undefined1 uStack_39;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined1 local_2c;
  undefined1 uStack_2b;
  undefined1 local_2a;
  
  piVar9 = *(int **)(*param_1 + 0x14c);
  local_58 = 0;
  if (*piVar9 == 0) {
    iVar4 = smb_send_tree_connect();
    if (iVar4 == 0) {
      **(undefined4 **)(*param_1 + 0x14c) = 1;
      goto LAB_00056e0c;
    }
    goto LAB_00056e36;
  }
LAB_00056e0c:
  iVar4 = smb_send_and_recv(param_1,&local_58);
  if (iVar4 != 0x51 && iVar4 != 0) goto LAB_00056e36;
  if (local_58 == 0) {
    return 0;
  }
  switch(*piVar9) {
  case 1:
    if (*(int *)(local_58 + 9) != 0) {
      if (*(int *)(local_58 + 9) == 0x50001) {
        iVar4 = 9;
      }
      else {
        iVar4 = 0x4e;
      }
      piVar9[4] = iVar4;
      goto LAB_00056eea;
    }
    *(undefined2 *)(piVar9 + 3) = *(undefined2 *)(local_58 + 0x1c);
    param_1[0xfb] = 0;
    iVar4 = smb_send_open(param_1);
    uVar6 = 2;
    break;
  case 2:
    if (*(int *)(local_58 + 9) == 0) {
      iVar4 = *param_1;
      cVar2 = *(char *)(iVar4 + 0x309);
      *(undefined2 *)((int)piVar9 + 0xe) = *(undefined2 *)(local_58 + 0x2a);
      *(undefined4 *)(iVar4 + 0xc0) = 0;
      *(undefined4 *)(iVar4 + 0xc4) = 0;
      if (cVar2 == '\0') {
        uVar10 = *(undefined4 *)(local_58 + 0x5c);
        uVar6 = *(undefined4 *)(local_58 + 0x60);
        *(undefined4 *)(iVar4 + 0x50) = uVar10;
        *(undefined4 *)(iVar4 + 0x54) = uVar6;
        Curl_pgrsSetDownloadSize(iVar4,iVar4,uVar10);
LAB_000570b6:
        iVar4 = *param_1;
        local_40 = 0;
        uStack_3d = *(undefined4 *)(iVar4 + 0xc0);
        iVar7 = *(int *)(iVar4 + 0xc4);
        uStack_2b = 0;
        local_34 = 0;
        local_2a = 0;
        uStack_3f = *(undefined2 *)(*(int *)(iVar4 + 0x14c) + 0xe);
        param_1[0xfb] = 0;
        local_30 = iVar7 << 8;
        local_2c = (undefined1)((uint)iVar7 >> 0x18);
        uStack_39 = 0;
        local_44 = 0xff0c;
        local_38 = 0x800080;
        iVar4 = smb_send_message(param_1,0x2e,&local_44,0x1b);
        uVar6 = 3;
      }
      else {
        *(undefined4 *)(iVar4 + 0x50) = *(undefined4 *)(iVar4 + 0x86b0);
        *(undefined4 *)(iVar4 + 0x54) = *(undefined4 *)(iVar4 + 0x86b4);
        Curl_pgrsSetUploadSize(iVar4);
        iVar8 = *param_1;
        uVar5 = *(uint *)(iVar8 + 0x50);
        iVar4 = *(int *)(iVar8 + 0x54);
        uVar11 = *(uint *)(iVar8 + 0x70);
        iVar7 = *(int *)(iVar8 + 0x74);
LAB_00056f4e:
        uVar14 = uVar5 - uVar11;
        param_1[0xfb] = 0;
        uVar6 = *(undefined4 *)(iVar8 + 0xc0);
        iVar12 = *(int *)(iVar8 + 0x14c);
        uVar10 = *(undefined4 *)(iVar8 + 0xc4);
        if ((int)-((iVar4 - iVar7) - (uint)(uVar5 < uVar11)) < (int)(uint)(0x7ffe < uVar14)) {
          uVar14 = 0x7fff;
          iVar4 = 0x801f;
          sVar13 = 0x7fff;
          sVar16 = -0x8000;
        }
        else {
          sVar13 = (short)uVar14;
          iVar4 = uVar14 + 0x20;
          sVar16 = sVar13 + 1;
        }
        memset((void *)(iVar8 + 0x459d),0,0x44);
        *(undefined1 *)(iVar8 + 0x45c1) = 0xe;
        *(undefined1 *)(iVar8 + 0x45c2) = 0xff;
        uVar1 = *(undefined2 *)(iVar12 + 0xe);
        *(undefined4 *)(iVar8 + 0x45c8) = uVar6;
        *(undefined4 *)(iVar8 + 0x45da) = uVar10;
        *(undefined2 *)(iVar8 + 0x45c6) = uVar1;
        *(short *)(iVar8 + 0x45d6) = sVar13;
        *(short *)(iVar8 + 0x45de) = sVar16;
        *(undefined1 *)(iVar8 + 0x45d8) = 0x40;
        *(undefined1 *)(iVar8 + 0x45d9) = 0;
        smb_format_message(param_1,iVar8 + 0x459d,0x2f,iVar4);
        iVar4 = Curl_write(param_1,0,*param_1 + 0x459d,0x44,&local_54);
        if (iVar4 == 0) {
          param_1[0xf8] = uVar14;
          if (local_54 != 0x44) {
            param_1[0xf9] = 0x44;
          }
          if (local_54 != 0x44) {
            param_1[0xfa] = local_54;
          }
        }
        uVar6 = 4;
      }
      break;
    }
    piVar9[4] = 0x4e;
  case 5:
    param_1[0xfb] = 0;
    local_5c = 0;
    local_5a = 0;
    iVar4 = smb_send_message(param_1,0x71,&local_5c,3);
    uVar6 = 6;
    break;
  case 3:
    if (*(int *)(local_58 + 9) == 0) {
      uVar5 = Curl_read16_le(local_58 + 0x2f);
      uVar17 = Curl_read16_le(local_58 + 0x31);
      if (uVar5 == 0) {
        iVar4 = *param_1;
        Curl_pgrsSetDownloadCounter
                  (iVar4,(int)((ulonglong)uVar17 >> 0x20),*(undefined4 *)(iVar4 + 0x70),
                   *(undefined4 *)(iVar4 + 0x74));
LAB_00057174:
        iVar8 = *param_1;
      }
      else {
        if ((uint)param_1[0xfb] < (int)uVar17 + uVar5 + 4) {
          Curl_failf(*param_1,"Invalid input packet");
          iVar4 = 0x38;
        }
        else {
          iVar4 = Curl_client_write(param_1,1,local_58 + (int)uVar17 + 4,uVar5);
          if (iVar4 == 0) {
            iVar4 = *param_1;
            uVar15 = uVar5 & 0xffff;
            uVar11 = *(uint *)(iVar4 + 0x70);
            uVar14 = *(uint *)(iVar4 + 0xc0);
            *(uint *)(iVar4 + 0x70) = uVar11 + uVar15;
            *(uint *)(iVar4 + 0x74) = *(int *)(iVar4 + 0x74) + (uint)CARRY4(uVar11,uVar15);
            *(uint *)(iVar4 + 0xc0) = uVar14 + uVar15;
            *(uint *)(iVar4 + 0xc4) = *(int *)(iVar4 + 0xc4) + (uint)CARRY4(uVar14,uVar15);
            Curl_pgrsSetDownloadCounter(iVar4);
            if ((int)(uVar5 << 0x10) < 0) goto LAB_000570b6;
            goto LAB_00057174;
          }
        }
        piVar9[4] = iVar4;
        iVar8 = *param_1;
      }
    }
    else {
      iVar8 = *param_1;
      piVar9[4] = 0x38;
    }
    goto LAB_00056e9a;
  case 4:
    if (*(int *)(local_58 + 9) == 0) {
      uVar3 = Curl_read16_le(local_58 + 0x29);
      iVar4 = *param_1;
      uVar14 = (uint)uVar3;
      uVar5 = *(uint *)(iVar4 + 0x70);
      uVar11 = *(uint *)(iVar4 + 0xc0);
      *(uint *)(iVar4 + 0x70) = uVar5 + uVar14;
      *(uint *)(iVar4 + 0x74) = *(int *)(iVar4 + 0x74) + (uint)CARRY4(uVar5,uVar14);
      *(uint *)(iVar4 + 0xc0) = uVar11 + uVar14;
      *(uint *)(iVar4 + 0xc4) = *(int *)(iVar4 + 0xc4) + (uint)CARRY4(uVar11,uVar14);
      Curl_pgrsSetUploadCounter(iVar4);
      iVar8 = *param_1;
      uVar11 = *(uint *)(iVar8 + 0x70);
      iVar7 = *(int *)(iVar8 + 0x74);
      uVar5 = *(uint *)(iVar8 + 0x50);
      iVar4 = *(int *)(iVar8 + 0x54);
      if ((int)((iVar7 - iVar4) - (uint)(uVar11 < uVar5)) < 0 !=
          (SBORROW4(iVar7,iVar4) != SBORROW4(iVar7 - iVar4,(uint)(uVar11 < uVar5))))
      goto LAB_00056f4e;
    }
    else {
      iVar8 = *param_1;
      piVar9[4] = 0x19;
    }
LAB_00056e9a:
    iVar4 = *(int *)(iVar8 + 0x14c);
    local_48 = 0;
    param_1[0xfb] = 0;
    local_4c = 0;
    _local_50 = CONCAT31((uint3)*(ushort *)(iVar4 + 0xe),3);
    iVar4 = smb_send_message(param_1,4,&local_50,9);
    uVar6 = 5;
    break;
  case 6:
    iVar4 = piVar9[4];
LAB_00056eea:
    param_1[0xfb] = 0;
    uVar6 = 7;
    *param_2 = 1;
    break;
  default:
    param_1[0xfb] = 0;
    return 0;
  }
  if (iVar4 == 0) {
    **(undefined4 **)(*param_1 + 0x14c) = uVar6;
  }
  else {
LAB_00056e36:
    *(undefined1 *)((int)param_1 + 0x1ed) = 1;
  }
  return iVar4;
}

