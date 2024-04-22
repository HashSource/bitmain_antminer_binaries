
/* WARNING: Type propagation algorithm not settling */

int ftp_statemach_act(int *param_1)

{
  byte bVar1;
  char cVar2;
  longlong lVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  char *pcVar7;
  ushort **ppuVar8;
  undefined4 uVar9;
  undefined4 extraout_r1;
  char *pcVar10;
  char *pcVar11;
  byte *pbVar12;
  int iVar13;
  byte *pbVar14;
  uint uVar15;
  int *piVar16;
  int iVar17;
  int *piVar18;
  int iVar19;
  int iVar20;
  bool bVar21;
  undefined8 uVar22;
  longlong lVar23;
  char local_75;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  time_t local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  uint local_40;
  int local_3c;
  
  piVar16 = param_1 + 0xf0;
  iVar17 = *param_1;
  local_74 = 0;
  if (param_1[0xf6] != 0) {
    iVar17 = Curl_pp_flushsend(piVar16);
    return iVar17;
  }
  piVar18 = (int *)param_1[0xfb];
  iVar20 = *piVar18;
  uVar22 = Curl_pp_readresp(param_1[0x55],piVar16,&local_5c,&local_74);
  uVar9 = (undefined4)((ulonglong)uVar22 >> 0x20);
  *(int *)(iVar20 + 0x86f4) = local_5c;
  iVar6 = DAT_0005ddd0;
  if (local_5c == 0x1a5) {
    Curl_infof(iVar20,DAT_0005d7a8);
    piVar18[0x10a] = 0;
    return 0x1c;
  }
  if ((int)uVar22 != 0) {
    return (int)uVar22;
  }
  if (local_5c == 0) {
    return 0;
  }
  iVar19 = param_1[0x10a];
  iVar20 = 0;
  switch(iVar19) {
  case 1:
    if (local_5c == 0xe6) goto switchD_0005d44c_caseD_3;
    if (local_5c != 0xdc) {
      Curl_failf(iVar17,DAT_0005daa4,local_5c);
      return 8;
    }
    if ((*(int *)(iVar17 + 0x318) != 0) && (*(char *)(param_1 + 0x5e) == '\0')) {
      uVar15 = *(uint *)(iVar17 + 0x31c);
      param_1[0x109] = 0;
      if (uVar15 < 2) {
        param_1[0x107] = 0;
        param_1[0x108] = 1;
      }
      else {
        if (uVar15 != 2) {
          Curl_failf(iVar17,DAT_0005df9c);
          return 0x30;
        }
        param_1[0x108] = -1;
        param_1[0x107] = 1;
      }
      iVar17 = Curl_pp_sendf(piVar16,DAT_0005ddd4,DAT_0005ddd0 + param_1[0x107] * 4);
      if (iVar17 == 0) {
        param_1[0x10a] = 2;
        return 0;
      }
      return iVar17;
    }
    goto LAB_0005da6a;
  case 2:
    if (local_5c == 0xea || local_5c == 0x14e) {
      iVar17 = Curl_ssl_connect(param_1,0);
      if (iVar17 != 0) {
        return iVar17;
      }
      *(undefined *)(param_1 + 100) = 0;
    }
    else {
      if (param_1[0x109] < 1) {
        iVar17 = param_1[0x107];
        param_1[0x109] = param_1[0x109] + 1;
        uVar9 = DAT_0005ddd4;
        param_1[0x107] = iVar17 + param_1[0x108];
        iVar17 = Curl_pp_sendf(piVar16,uVar9,iVar6 + (iVar17 + param_1[0x108]) * 4);
        return iVar17;
      }
      if (1 < *(uint *)(iVar17 + 0x318)) {
        return 0x40;
      }
    }
LAB_0005da6a:
    iVar20 = ftp_state_user(param_1);
    break;
  case 3:
  case 4:
switchD_0005d44c_caseD_3:
    iVar20 = ftp_state_user_resp_isra_1(param_1,local_5c);
    break;
  case 5:
    if (local_5c == 0xe6) {
      iVar20 = ftp_state_loggedin(param_1);
    }
    else {
      iVar20 = 0xb;
      Curl_failf(*param_1,DAT_0005d7b8,local_5c);
    }
    break;
  case 6:
    if (*(int *)(iVar17 + 0x318) == 2) {
      uVar9 = 0x43;
    }
    else {
      uVar9 = 0x50;
    }
    iVar20 = Curl_pp_sendf(piVar16,DAT_0005da80,uVar9);
    if (iVar20 == 0) {
      param_1[0x10a] = 7;
    }
    break;
  case 7:
    if (local_5c - 200U < 100) {
      iVar6 = *(uint *)(iVar17 + 0x318) - 2;
      if (iVar6 != 0) {
        iVar6 = 1;
      }
      *(char *)(param_1 + 100) = (char)iVar6;
    }
    else if (2 < *(uint *)(iVar17 + 0x318)) {
      return 0x40;
    }
    if (*(int *)(iVar17 + 800) != 0) {
      iVar17 = Curl_pp_sendf(piVar16,DAT_0005d7c8,DAT_0005d7cc);
      if (iVar17 == 0) {
        param_1[0x10a] = 8;
        return 0;
      }
      return iVar17;
    }
    goto LAB_0005d75c;
  case 8:
    if ((local_5c < 500) && (iVar17 = Curl_ssl_shutdown(param_1,0), iVar17 != 0)) {
      Curl_failf(*param_1,DAT_0005ddf0);
      return iVar17;
    }
LAB_0005d75c:
    iVar20 = ftp_state_pwd(param_1);
    break;
  case 9:
    if (local_5c == 0x101) {
      pcVar7 = (char *)(**DAT_0005d7ac)(local_74 + 1);
      if (pcVar7 == (char *)0x0) {
        return 0x1b;
      }
      cVar2 = *(char *)(iVar17 + 0x5a0);
      if ((cVar2 == '\n') || (cVar2 == '\0')) {
LAB_0005de42:
        (**DAT_0005df94)(pcVar7);
        Curl_infof(iVar17,DAT_0005df98);
      }
      else {
        pcVar10 = (char *)(iVar17 + 0x5a0);
        if (cVar2 != '\"') {
          pcVar4 = (char *)(iVar17 + 0x5a1);
          do {
            pcVar10 = pcVar4;
            if ((char *)(iVar17 + 0x459d) <= pcVar10) {
              if (*pcVar10 != '\"') goto LAB_0005de42;
              break;
            }
            cVar2 = *pcVar10;
            if ((cVar2 == '\n') || (cVar2 == '\0')) goto LAB_0005de42;
            pcVar4 = pcVar10 + 1;
          } while (cVar2 != '\"');
        }
        cVar2 = pcVar10[1];
        pcVar4 = pcVar7;
        while (cVar2 != '\0') {
          pcVar11 = pcVar10 + 1;
          if ((cVar2 == '\"') && (pcVar11 = pcVar10 + 2, pcVar10[2] != '\"')) {
            *pcVar4 = '\0';
            break;
          }
          *pcVar4 = cVar2;
          pcVar4 = pcVar4 + 1;
          pcVar10 = pcVar11;
          cVar2 = pcVar11[1];
        }
        if ((param_1[0x10e] == 0) && (*pcVar7 != '/')) {
          iVar6 = Curl_pp_sendf(piVar16,DAT_0005dfa8,DAT_0005dfac);
          if (iVar6 != 0) {
            (**DAT_0005df94)(pcVar7);
            return iVar6;
          }
          (**DAT_0005df94)(param_1[0xfe]);
          param_1[0xfe] = (int)pcVar7;
          Curl_infof(iVar17,DAT_0005dfb0,pcVar7);
          *(int *)(iVar17 + 0x8670) = param_1[0xfe];
          param_1[0x10a] = 10;
          return 0;
        }
        (**DAT_0005d7b0)(param_1[0xfe]);
        param_1[0xfe] = (int)pcVar7;
        Curl_infof(iVar17,DAT_0005d7b4,pcVar7);
        *(int *)(iVar17 + 0x8670) = param_1[0xfe];
      }
    }
  default:
switchD_0005d44c_caseD_21:
    param_1[0x10a] = 0;
    break;
  case 10:
    if (local_5c == 0xd7) {
      pbVar14 = (byte *)(**DAT_0005da88)(local_74 + 1);
      if (pbVar14 == (byte *)0x0) {
        return 0x1b;
      }
      pbVar12 = (byte *)(iVar17 + 0x5a0);
      if (*(char *)(iVar17 + 0x5a0) == ' ') {
        pbVar5 = (byte *)(iVar17 + 0x5a1);
        do {
          pbVar12 = pbVar5;
          pbVar5 = pbVar12 + 1;
        } while (*pbVar12 == 0x20);
      }
      bVar1 = *pbVar12;
      pbVar5 = pbVar14;
      while ((bVar1 & 0xdf) != 0) {
        *pbVar5 = bVar1;
        pbVar12 = pbVar12 + 1;
        pbVar5 = pbVar5 + 1;
        bVar1 = *pbVar12;
      }
      *pbVar5 = 0;
      iVar17 = curl_strequal(pbVar14,DAT_0005da8c);
      if (iVar17 != 0) {
        iVar17 = Curl_pp_sendf(piVar16,DAT_0005da90,DAT_0005da94);
        if (iVar17 != 0) {
          (**DAT_0005da98)(pbVar14);
          return iVar17;
        }
        (**DAT_0005da98)(param_1[0x10e]);
        param_1[0x10e] = (int)pbVar14;
        param_1[0x10a] = 0xb;
        return 0;
      }
      (**DAT_0005df94)(param_1[0x10e]);
      param_1[0x10e] = (int)pbVar14;
    }
    goto switchD_0005d44c_caseD_21;
  case 0xb:
    if (local_5c == 0xfa) {
      ftp_state_pwd(param_1);
      return 0;
    }
    goto switchD_0005d44c_caseD_21;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    if ((local_5c < 400) || (param_1[0x108] != 0)) {
      iVar20 = ftp_state_quote(param_1,0,iVar19);
    }
    else {
      iVar20 = 0x15;
      Curl_failf(*param_1,DAT_0005ddc0,local_5c);
    }
    break;
  case 0x10:
    if (local_5c - 200U < 100) {
      iVar17 = param_1[0x107];
      param_1[0x108] = 0;
      iVar6 = iVar17 + 1;
      param_1[0x107] = iVar6;
      if (param_1[0x100] < iVar6) {
        iVar20 = ftp_state_mdtm(param_1);
      }
      else {
        iVar20 = Curl_pp_sendf(piVar16,DAT_0005daa0,*(undefined4 *)(param_1[0xff] + iVar17 * 4));
      }
    }
    else if (((*(int *)(*param_1 + 0x2ec) == 0) || (param_1[0x107] == 0)) || (param_1[0x108] != 0))
    {
      Curl_failf(iVar17,DAT_0005da84);
      iVar20 = 9;
      *(undefined *)((int)param_1 + 0x40f) = 1;
    }
    else {
      param_1[0x108] = 1;
      iVar20 = Curl_pp_sendf(piVar16,DAT_0005df8c,
                             *(undefined4 *)(param_1[0xff] + (param_1[0x107] + -1) * 4));
      if (iVar20 == 0) {
        param_1[0x10a] = 0x11;
      }
    }
    break;
  case 0x11:
    if ((local_5c - 200U < 100) || (iVar6 = param_1[0x109], param_1[0x109] = iVar6 + -1, iVar6 != 0)
       ) {
      param_1[0x10a] = 0x10;
      iVar20 = Curl_pp_sendf(piVar16,DAT_0005daa0,
                             *(undefined4 *)(param_1[0xff] + (param_1[0x107] + -1) * 4));
    }
    else {
      iVar20 = 9;
      Curl_failf(iVar17,DAT_0005ddbc,local_5c);
    }
    break;
  case 0x12:
    iVar6 = *param_1;
    iVar17 = *(int *)(iVar6 + 0x14c);
    if (local_5c == 0xd5) {
      iVar19 = iVar6 + 0x59c;
      iVar20 = __isoc99_sscanf(iVar6 + 0x5a0,DAT_0005ddac,&local_70,&local_6c,&local_68,&local_64,
                               &local_60,&local_5c);
      if (iVar20 == 6) {
        local_58 = time((time_t *)0x0);
        curl_msnprintf(iVar19,0x4001,DAT_0005dfa4,local_70,local_6c,local_68,local_64,local_60,
                       local_5c);
        uVar9 = curl_getdate(iVar19,&local_58);
        *(undefined4 *)(iVar6 + 0x8700) = uVar9;
      }
      if ((((*(char *)(iVar6 + 0x307) != '\0') && (param_1[0x102] != 0)) &&
          (*(char *)(iVar6 + 0x2f9) != '\0')) && (-1 < *(int *)(iVar6 + 0x8700))) {
        iVar20 = Curl_gmtime(*(int *)(iVar6 + 0x8700),&local_54);
        if (iVar20 != 0) {
          return iVar20;
        }
        if (local_3c == 0) {
          local_3c = 6;
        }
        else {
          local_3c = local_3c + -1;
        }
        curl_msnprintf(iVar19,0x3fff,DAT_0005ddb8,*(undefined4 *)(DAT_0005ddb4 + local_3c * 4),
                       local_48,*(undefined4 *)(DAT_0005ddb0 + local_44 * 4),local_40 + 0x76c,
                       local_4c,local_50,local_54);
        iVar20 = Curl_client_write(param_1,3,iVar19,0);
        if (iVar20 != 0) {
          return iVar20;
        }
      }
LAB_0005d8f8:
      iVar20 = 0;
    }
    else {
      if (local_5c != 0x226) {
        Curl_infof(iVar6,DAT_0005da9c);
        goto LAB_0005d8f8;
      }
      iVar20 = 0x13;
      Curl_failf(iVar6,DAT_0005dabc);
    }
    if (*(int *)(iVar6 + 0x270) != 0) {
      iVar19 = *(int *)(iVar6 + 0x8700);
      if ((iVar19 < 1) || (iVar13 = *(int *)(iVar6 + 0x274), iVar13 < 1)) {
        Curl_infof(iVar6,DAT_0005dddc);
      }
      else if (*(int *)(iVar6 + 0x270) == 2) {
        if (iVar13 < iVar19) {
          Curl_infof(iVar6,DAT_0005dde0);
          *(undefined4 *)(iVar17 + 0xc) = 2;
          *(undefined *)(iVar6 + 0x8704) = 1;
          param_1[0x10a] = 0;
          return 0;
        }
      }
      else if (iVar19 <= iVar13) {
        Curl_infof(iVar6,DAT_0005daa8);
        *(undefined4 *)(iVar17 + 0xc) = 2;
        *(undefined *)(iVar6 + 0x8704) = 1;
        param_1[0x10a] = 0;
        return 0;
      }
    }
    if (iVar20 == 0) {
      iVar20 = ftp_state_type(param_1);
    }
    break;
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
    if (local_5c - 200U < 100) {
      if (local_5c != 200) {
        Curl_infof(*param_1,DAT_0005d7c4,local_5c);
      }
      iVar20 = ftp_state_type_resp_part_5(param_1,iVar19);
    }
    else {
      iVar20 = 0x11;
      Curl_failf(*param_1,DAT_0005dab4);
    }
    break;
  case 0x17:
  case 0x18:
  case 0x19:
    iVar17 = *param_1;
    if (local_5c == 0xd5) {
      lVar23 = strtoll((char *)(iVar17 + 0x5a0),(char **)0x0,0);
      iVar20 = (int)((ulonglong)lVar23 >> 0x20);
      iVar6 = (int)lVar23;
      if (iVar19 == 0x17) {
        lVar3 = lVar23;
        if (iVar20 != -1 || iVar6 != -1) {
          curl_msnprintf(iVar17 + 0x59c,0x4001,DAT_0005ddd8);
          uVar22 = Curl_client_write(param_1,3,iVar17 + 0x59c,0,lVar23);
          lVar3 = CONCAT44((int)((ulonglong)uVar22 >> 0x20),iVar6);
          if ((int)uVar22 != 0) {
            return (int)uVar22;
          }
        }
        goto LAB_0005dc9a;
      }
    }
    else {
      lVar23 = CONCAT44(uVar9,0xffffffff);
      iVar20 = -1;
      lVar3 = CONCAT44(uVar9,0xffffffff);
      if (iVar19 == 0x17) {
LAB_0005dc9a:
        Curl_pgrsSetDownloadSize(iVar17,(int)((ulonglong)lVar3 >> 0x20),(int)lVar3,iVar20);
        iVar17 = ftp_state_rest(param_1);
        return iVar17;
      }
    }
    uVar9 = (undefined4)lVar23;
    if (iVar19 == 0x18) {
      Curl_pgrsSetDownloadSize(iVar17,(int)((ulonglong)lVar23 >> 0x20),uVar9,iVar20);
      iVar20 = ftp_state_retr(param_1,extraout_r1,uVar9,iVar20);
    }
    else {
      *(undefined4 *)(iVar17 + 0x8698) = uVar9;
      *(int *)(iVar17 + 0x869c) = iVar20;
      iVar20 = ftp_state_ul_setup(param_1,1);
    }
    break;
  case 0x1a:
  case 0x1b:
    if (iVar19 == 0x1b) {
      if (local_5c == 0x15e) {
        iVar20 = Curl_pp_sendf(piVar16,DAT_0005dde8,param_1[0x102]);
        if (iVar20 == 0) {
          param_1[0x10a] = 0x20;
        }
      }
      else {
        iVar20 = 0x1f;
        Curl_failf(*param_1,DAT_0005daac);
      }
    }
    else {
      if (local_5c == 0x15e) {
        local_54 = *DAT_0005ddec;
        local_50 = DAT_0005ddec[1];
        local_4c = DAT_0005ddec[2];
        local_48 = DAT_0005ddec[3];
        local_44 = DAT_0005ddec[4];
        local_40 = DAT_0005ddec[5] & 0xffffff;
        iVar17 = Curl_client_write(param_1,3,&local_54,0);
        if (iVar17 != 0) {
          return iVar17;
        }
      }
      iVar20 = ftp_state_prepare_transfer(param_1);
    }
    break;
  case 0x1c:
    iVar17 = *param_1;
    if (local_5c - 200U < 100) {
      Curl_infof(iVar17,DAT_0005ddcc);
      param_1[0x10a] = 0;
      iVar20 = ftp_dophase_done(param_1);
    }
    else {
      if (param_1[0x107] == 0) {
        Curl_infof(iVar17,DAT_0005dab8);
        iVar6 = 1;
        *(undefined *)((int)param_1 + 0x1fe) = 0;
      }
      else {
        iVar6 = param_1[0x107] + 1;
        if (iVar6 == 2) {
          Curl_failf(iVar17,DAT_0005d7bc);
          return 0x1e;
        }
      }
      iVar20 = ftp_state_use_port(param_1,iVar6);
    }
    break;
  case 0x1d:
    if (local_5c == 200) {
      iVar20 = ftp_state_use_pasv(param_1);
    }
    else {
      iVar20 = 0x54;
      Curl_failf(iVar17,DAT_0005d7c0,local_5c);
    }
    break;
  case 0x1e:
    iVar20 = ftp_state_pasv_resp(param_1,local_5c);
    break;
  case 0x1f:
  case 0x20:
    iVar6 = *param_1;
    iVar17 = *(int *)(iVar6 + 0x14c);
    if (local_5c != 0x96 && local_5c != 0x7d) {
      if (local_5c == 0x1c2 && iVar19 == 0x1f) {
        *(undefined4 *)(iVar17 + 0xc) = 2;
        param_1[0x10a] = (uint)(local_5c == 0x96 || local_5c == 0x7d);
        return 0;
      }
      Curl_failf(iVar6,DAT_0005dde4,local_5c);
      if (local_5c != 0x226 || iVar19 != 0x20) {
        return 0x13;
      }
      return 0x4e;
    }
    if ((iVar19 == 0x1f) || (*(char *)(iVar6 + 0x2fb) != '\0')) {
      lVar23 = *(longlong *)(iVar17 + 0x10);
      if (*(int *)(iVar17 + 0x14) < 0) goto LAB_0005dbd6;
    }
    else {
      lVar23 = *(longlong *)(iVar17 + 0x10);
      bVar21 = *(int *)(longlong *)(iVar17 + 0x10) == 0;
      if ((int)(*(int *)(iVar17 + 0x14) - (uint)bVar21) < 0 !=
          (SBORROW4(*(int *)(iVar17 + 0x14),(uint)bVar21) != false)) {
        pcVar7 = strstr((char *)(iVar6 + 0x59c),DAT_0005dfa0);
        pbVar14 = (byte *)(pcVar7 + -1);
        if (pcVar7 == (char *)0x0) {
LAB_0005dbd6:
          lVar23 = -1;
        }
        else {
          iVar17 = (int)pbVar14 - (int)(char *)(iVar6 + 0x59c);
          if (iVar17 == 1) {
LAB_0005dec2:
            if (pbVar14 == (byte *)0x0) goto LAB_0005dbd6;
          }
          else {
            uVar15 = (uint)(byte)pcVar7[-1];
            if (uVar15 != 0x28) {
              ppuVar8 = __ctype_b_loc();
              pbVar12 = (byte *)(pcVar7 + -2);
              do {
                pbVar14 = pbVar12;
                if (-1 < (int)((uint)(*ppuVar8)[uVar15] << 0x14)) goto LAB_0005dbd6;
                if (pbVar14 == (byte *)(pcVar7 + -iVar17)) goto LAB_0005dec2;
                uVar15 = (uint)*pbVar14;
                pbVar12 = pbVar14 + -1;
              } while (uVar15 != 0x28);
            }
          }
          lVar23 = strtoll((char *)(pbVar14 + 1),(char **)0x0,0);
        }
      }
    }
    iVar20 = (int)((ulonglong)lVar23 >> 0x20);
    uVar15 = *(uint *)(longlong *)(iVar6 + 0x60);
    iVar17 = *(int *)(iVar6 + 100);
    lVar3 = *(longlong *)(iVar6 + 0x60);
    bVar21 = uVar15 < (uint)lVar23;
    if (((int)((iVar17 - iVar20) - (uint)bVar21) < 0 ==
         (SBORROW4(iVar17,iVar20) != SBORROW4(iVar17 - iVar20,(uint)bVar21))) ||
       ((int)(iVar17 - (uint)(uVar15 == 0)) < 0 != (SBORROW4(iVar17,(uint)(uVar15 == 0)) != false)))
    {
      if (iVar19 != 0x1f) {
        if (*(char *)(iVar6 + 0x2fb) != '\0') {
          lVar23 = -1;
        }
        Curl_infof(iVar6,DAT_0005ddc4,uVar15,iVar17);
        goto LAB_0005dbb8;
      }
      Curl_infof(iVar6,DAT_0005df90,uVar15,iVar17);
    }
    else {
      *(uint *)(iVar6 + 0x50) = uVar15;
      *(int *)(iVar6 + 0x54) = iVar17;
      Curl_infof(iVar6,DAT_0005d7a0,uVar15,iVar17);
      lVar23 = lVar3;
      if (iVar19 != 0x1f) {
LAB_0005dbb8:
        Curl_infof(iVar6,DAT_0005ddc8,(int)lVar23,(int)((ulonglong)lVar23 >> 0x20));
      }
    }
    param_1[0x10b] = iVar19;
    *(longlong *)(param_1 + 0x10c) = lVar23;
    if (*(char *)(iVar6 + 0x2fe) != '\0') {
      iVar17 = AllowServerConnect(param_1,&local_75);
      if (iVar17 != 0) {
        return iVar17;
      }
      if (local_75 == '\0') {
        Curl_infof(iVar6,DAT_0005d7a4);
        param_1[0x10a] = 0;
        *(undefined *)(param_1 + 0x104) = 1;
        return 0;
      }
      return 0;
    }
LAB_0005da20:
    iVar20 = InitiateTransfer(param_1);
    break;
  case 0x21:
    iVar17 = *param_1;
    if (local_5c < 400) {
      param_1[0x10b] = 0x21;
      if (*(char *)(iVar17 + 0x2fe) != '\0') {
        param_1[0x10a] = 0;
        iVar6 = AllowServerConnect(param_1,&local_75);
        if (iVar6 != 0) {
          return iVar6;
        }
        if (local_75 == '\0') {
          Curl_infof(iVar17,DAT_0005d7a4);
          *(undefined *)(param_1 + 0x104) = 1;
          return 0;
        }
        return 0;
      }
      goto LAB_0005da20;
    }
    iVar20 = 0x19;
    Curl_failf(iVar17,DAT_0005dab0,local_5c);
    goto switchD_0005d44c_caseD_21;
  }
  return iVar20;
}

