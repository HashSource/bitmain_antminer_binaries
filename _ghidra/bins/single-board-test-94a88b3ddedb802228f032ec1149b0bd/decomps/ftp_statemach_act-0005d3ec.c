
/* WARNING: Type propagation algorithm not settling */

int ftp_statemach_act(int *param_1)

{
  byte bVar1;
  char cVar2;
  longlong lVar3;
  char *pcVar4;
  byte *pbVar5;
  char *pcVar6;
  ushort **ppuVar7;
  undefined4 uVar8;
  undefined4 extraout_r1;
  char *pcVar9;
  char *pcVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  int iVar14;
  uint uVar15;
  undefined4 uVar16;
  int *piVar17;
  int iVar18;
  int *piVar19;
  int iVar20;
  int iVar21;
  bool bVar22;
  undefined8 uVar23;
  longlong lVar24;
  char local_75;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  time_t local_58;
  char local_54 [16];
  int local_44;
  int local_40;
  int local_3c;
  
  piVar17 = param_1 + 0xf0;
  iVar18 = *param_1;
  local_74 = 0;
  if (param_1[0xf6] != 0) {
    iVar18 = Curl_pp_flushsend(piVar17);
    return iVar18;
  }
  piVar19 = (int *)param_1[0xfb];
  iVar21 = *piVar19;
  uVar23 = Curl_pp_readresp(param_1[0x55],piVar17,&local_5c,&local_74);
  uVar8 = (undefined4)((ulonglong)uVar23 >> 0x20);
  *(int *)(iVar21 + 0x86f4) = local_5c;
  if (local_5c == 0x1a5) {
    Curl_infof(iVar21,"We got a 421 - timeout!\n");
    piVar19[0x10a] = 0;
    return 0x1c;
  }
  if ((int)uVar23 != 0) {
    return (int)uVar23;
  }
  if (local_5c == 0) {
    return 0;
  }
  iVar20 = param_1[0x10a];
  iVar21 = 0;
  switch(iVar20) {
  case 1:
    if (local_5c == 0xe6) goto switchD_0005d44c_caseD_3;
    if (local_5c != 0xdc) {
      Curl_failf(iVar18,"Got a %03d ftp-server response when 220 was expected",local_5c);
      return 8;
    }
    if ((*(int *)(iVar18 + 0x318) != 0) && ((char)param_1[0x5e] == '\0')) {
      uVar15 = *(uint *)(iVar18 + 0x31c);
      param_1[0x109] = 0;
      if (uVar15 < 2) {
        param_1[0x107] = 0;
        param_1[0x108] = 1;
      }
      else {
        if (uVar15 != 2) {
          Curl_failf(iVar18,"unsupported parameter to CURLOPT_FTPSSLAUTH: %d");
          return 0x30;
        }
        param_1[0x108] = -1;
        param_1[0x107] = 1;
      }
      iVar18 = Curl_pp_sendf(piVar17,"AUTH %s",(int)&ftpauth_23839 + param_1[0x107] * 4);
      if (iVar18 == 0) {
        param_1[0x10a] = 2;
        return 0;
      }
      return iVar18;
    }
    goto LAB_0005da6a;
  case 2:
    if (local_5c == 0xea || local_5c == 0x14e) {
      iVar18 = Curl_ssl_connect(param_1,0);
      if (iVar18 != 0) {
        return iVar18;
      }
      *(undefined1 *)(param_1 + 100) = 0;
    }
    else {
      if (param_1[0x109] < 1) {
        iVar18 = param_1[0x107];
        param_1[0x109] = param_1[0x109] + 1;
        param_1[0x107] = iVar18 + param_1[0x108];
        iVar18 = Curl_pp_sendf(piVar17,"AUTH %s",(int)&ftpauth_23839 + (iVar18 + param_1[0x108]) * 4
                              );
        return iVar18;
      }
      if (1 < *(uint *)(iVar18 + 0x318)) {
        return 0x40;
      }
    }
LAB_0005da6a:
    iVar21 = ftp_state_user(param_1);
    break;
  case 3:
  case 4:
switchD_0005d44c_caseD_3:
    iVar21 = ftp_state_user_resp_isra_1(param_1,local_5c);
    break;
  case 5:
    if (local_5c == 0xe6) {
      iVar21 = ftp_state_loggedin(param_1);
    }
    else {
      iVar21 = 0xb;
      Curl_failf(*param_1,"ACCT rejected by server: %03d",local_5c);
    }
    break;
  case 6:
    if (*(int *)(iVar18 + 0x318) == 2) {
      uVar8 = 0x43;
    }
    else {
      uVar8 = 0x50;
    }
    iVar21 = Curl_pp_sendf(piVar17,"PROT %c",uVar8);
    if (iVar21 == 0) {
      param_1[0x10a] = 7;
    }
    break;
  case 7:
    if (local_5c - 200U < 100) {
      iVar21 = *(uint *)(iVar18 + 0x318) - 2;
      if (iVar21 != 0) {
        iVar21 = 1;
      }
      *(char *)(param_1 + 100) = (char)iVar21;
    }
    else if (2 < *(uint *)(iVar18 + 0x318)) {
      return 0x40;
    }
    if (*(int *)(iVar18 + 800) != 0) {
      iVar18 = Curl_pp_sendf(piVar17,"%s",&DAT_0013cb90);
      if (iVar18 == 0) {
        param_1[0x10a] = 8;
        return 0;
      }
      return iVar18;
    }
    goto LAB_0005d75c;
  case 8:
    if ((local_5c < 500) && (iVar18 = Curl_ssl_shutdown(param_1,0), iVar18 != 0)) {
      Curl_failf(*param_1,"Failed to clear the command channel (CCC)");
      return iVar18;
    }
LAB_0005d75c:
    iVar21 = ftp_state_pwd(param_1);
    break;
  case 9:
    if (local_5c == 0x101) {
      pcVar6 = (char *)(*Curl_cmalloc)(local_74 + 1);
      if (pcVar6 == (char *)0x0) {
        return 0x1b;
      }
      cVar2 = *(char *)(iVar18 + 0x5a0);
      if ((cVar2 == '\n') || (cVar2 == '\0')) {
LAB_0005de42:
        (*Curl_cfree)(pcVar6);
        Curl_infof(iVar18,"Failed to figure out path\n");
      }
      else {
        pcVar9 = (char *)(iVar18 + 0x5a0);
        if (cVar2 != '\"') {
          pcVar4 = (char *)(iVar18 + 0x5a1);
          do {
            pcVar9 = pcVar4;
            if ((char *)(iVar18 + 0x459d) <= pcVar9) {
              if (*pcVar9 != '\"') goto LAB_0005de42;
              break;
            }
            cVar2 = *pcVar9;
            if ((cVar2 == '\n') || (cVar2 == '\0')) goto LAB_0005de42;
            pcVar4 = pcVar9 + 1;
          } while (cVar2 != '\"');
        }
        cVar2 = pcVar9[1];
        pcVar4 = pcVar6;
        while (cVar2 != '\0') {
          pcVar10 = pcVar9 + 1;
          if ((cVar2 == '\"') && (pcVar10 = pcVar9 + 2, pcVar9[2] != '\"')) {
            *pcVar4 = '\0';
            break;
          }
          *pcVar4 = cVar2;
          pcVar4 = pcVar4 + 1;
          pcVar9 = pcVar10;
          cVar2 = pcVar10[1];
        }
        if ((param_1[0x10e] == 0) && (*pcVar6 != '/')) {
          iVar21 = Curl_pp_sendf(piVar17,"%s",&DAT_0013cbc0);
          if (iVar21 != 0) {
            (*Curl_cfree)(pcVar6);
            return iVar21;
          }
          (*Curl_cfree)(param_1[0xfe]);
          param_1[0xfe] = (int)pcVar6;
          Curl_infof(iVar18,"Entry path is \'%s\'\n",pcVar6);
          *(int *)(iVar18 + 0x8670) = param_1[0xfe];
          param_1[0x10a] = 10;
          return 0;
        }
        (*Curl_cfree)(param_1[0xfe]);
        param_1[0xfe] = (int)pcVar6;
        Curl_infof(iVar18,"Entry path is \'%s\'\n",pcVar6);
        *(int *)(iVar18 + 0x8670) = param_1[0xfe];
      }
    }
  default:
switchD_0005d44c_default:
    param_1[0x10a] = 0;
    break;
  case 10:
    if (local_5c == 0xd7) {
      pbVar13 = (byte *)(*Curl_cmalloc)(local_74 + 1);
      if (pbVar13 == (byte *)0x0) {
        return 0x1b;
      }
      pbVar11 = (byte *)(iVar18 + 0x5a0);
      if (*(char *)(iVar18 + 0x5a0) == ' ') {
        pbVar5 = (byte *)(iVar18 + 0x5a1);
        do {
          pbVar11 = pbVar5;
          pbVar5 = pbVar11 + 1;
        } while (*pbVar11 == 0x20);
      }
      bVar1 = *pbVar11;
      pbVar5 = pbVar13;
      while ((bVar1 & 0xdf) != 0) {
        *pbVar5 = bVar1;
        pbVar11 = pbVar11 + 1;
        pbVar5 = pbVar5 + 1;
        bVar1 = *pbVar11;
      }
      *pbVar5 = 0;
      iVar18 = curl_strequal(pbVar13,"OS/400");
      if (iVar18 != 0) {
        iVar18 = Curl_pp_sendf(piVar17,"%s","SITE NAMEFMT 1");
        if (iVar18 != 0) {
          (*Curl_cfree)(pbVar13);
          return iVar18;
        }
        (*Curl_cfree)(param_1[0x10e]);
        param_1[0x10e] = (int)pbVar13;
        param_1[0x10a] = 0xb;
        return 0;
      }
      (*Curl_cfree)(param_1[0x10e]);
      param_1[0x10e] = (int)pbVar13;
    }
    goto switchD_0005d44c_default;
  case 0xb:
    if (local_5c == 0xfa) {
      ftp_state_pwd(param_1);
      return 0;
    }
    goto switchD_0005d44c_default;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    if ((local_5c < 400) || (param_1[0x108] != 0)) {
      iVar21 = ftp_state_quote(param_1,0,iVar20);
    }
    else {
      iVar21 = 0x15;
      Curl_failf(*param_1,"QUOT command failed with %03d",local_5c);
    }
    break;
  case 0x10:
    if (local_5c - 200U < 100) {
      iVar18 = param_1[0x107];
      param_1[0x108] = 0;
      iVar21 = iVar18 + 1;
      param_1[0x107] = iVar21;
      if (param_1[0x100] < iVar21) {
        iVar21 = ftp_state_mdtm(param_1);
      }
      else {
        iVar21 = Curl_pp_sendf(piVar17,"CWD %s",*(undefined4 *)(param_1[0xff] + iVar18 * 4));
      }
    }
    else if (((*(int *)(*param_1 + 0x2ec) == 0) || (param_1[0x107] == 0)) || (param_1[0x108] != 0))
    {
      Curl_failf(iVar18,"Server denied you to change to the given directory");
      iVar21 = 9;
      *(undefined1 *)((int)param_1 + 0x40f) = 1;
    }
    else {
      param_1[0x108] = 1;
      iVar21 = Curl_pp_sendf(piVar17,"MKD %s",
                             *(undefined4 *)(param_1[0xff] + (param_1[0x107] + -1) * 4));
      if (iVar21 == 0) {
        param_1[0x10a] = 0x11;
      }
    }
    break;
  case 0x11:
    if ((local_5c - 200U < 100) ||
       (iVar21 = param_1[0x109], param_1[0x109] = iVar21 + -1, iVar21 != 0)) {
      param_1[0x10a] = 0x10;
      iVar21 = Curl_pp_sendf(piVar17,"CWD %s",
                             *(undefined4 *)(param_1[0xff] + (param_1[0x107] + -1) * 4));
    }
    else {
      iVar21 = 9;
      Curl_failf(iVar18,"Failed to MKD dir: %03d",local_5c);
    }
    break;
  case 0x12:
    iVar20 = *param_1;
    iVar18 = *(int *)(iVar20 + 0x14c);
    if (local_5c == 0xd5) {
      iVar14 = iVar20 + 0x59c;
      iVar21 = __isoc99_sscanf(iVar20 + 0x5a0,"%04d%02d%02d%02d%02d%02d",&local_70,&local_6c,
                               &local_68,&local_64,&local_60,&local_5c);
      if (iVar21 == 6) {
        local_58 = time((time_t *)0x0);
        curl_msnprintf(iVar14,0x4001,"%04d%02d%02d %02d:%02d:%02d GMT",local_70,local_6c,local_68,
                       local_64,local_60,local_5c);
        uVar8 = curl_getdate(iVar14,&local_58);
        *(undefined4 *)(iVar20 + 0x8700) = uVar8;
      }
      if ((((*(char *)(iVar20 + 0x307) != '\0') && (param_1[0x102] != 0)) &&
          (*(char *)(iVar20 + 0x2f9) != '\0')) && (-1 < *(int *)(iVar20 + 0x8700))) {
        iVar21 = Curl_gmtime(*(int *)(iVar20 + 0x8700),local_54);
        if (iVar21 != 0) {
          return iVar21;
        }
        if (local_3c == 0) {
          local_3c = 6;
        }
        else {
          local_3c = local_3c + -1;
        }
        curl_msnprintf(iVar14,0x3fff,"Last-Modified: %s, %02d %s %4d %02d:%02d:%02d GMT\r\n",
                       (&Curl_wkday)[local_3c],local_54._12_4_,
                       *(undefined4 *)(Curl_month + local_44 * 4),local_40 + 0x76c,local_54._8_4_,
                       local_54._4_4_,local_54._0_4_);
        iVar21 = Curl_client_write(param_1,3,iVar14,0);
        if (iVar21 != 0) {
          return iVar21;
        }
      }
LAB_0005d8f8:
      iVar21 = 0;
    }
    else {
      if (local_5c != 0x226) {
        Curl_infof(iVar20,"unsupported MDTM reply format\n");
        goto LAB_0005d8f8;
      }
      iVar21 = 0x13;
      Curl_failf(iVar20,"Given file does not exist");
    }
    if (*(int *)(iVar20 + 0x270) != 0) {
      iVar14 = *(int *)(iVar20 + 0x8700);
      if ((iVar14 < 1) || (iVar12 = *(int *)(iVar20 + 0x274), iVar12 < 1)) {
        Curl_infof(iVar20,"Skipping time comparison\n");
      }
      else if (*(int *)(iVar20 + 0x270) == 2) {
        if (iVar12 < iVar14) {
          Curl_infof(iVar20,"The requested document is not old enough\n");
          *(undefined4 *)(iVar18 + 0xc) = 2;
          *(undefined1 *)(iVar20 + 0x8704) = 1;
          param_1[0x10a] = 0;
          return 0;
        }
      }
      else if (iVar14 <= iVar12) {
        Curl_infof(iVar20,"The requested document is not new enough\n");
        *(undefined4 *)(iVar18 + 0xc) = 2;
        *(undefined1 *)(iVar20 + 0x8704) = 1;
        param_1[0x10a] = 0;
        return 0;
      }
    }
    if (iVar21 == 0) {
      iVar21 = ftp_state_type(param_1);
    }
    break;
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
    if (local_5c - 200U < 100) {
      if (local_5c != 200) {
        Curl_infof(*param_1,"Got a %03d response code instead of the assumed 200\n",local_5c);
      }
      iVar21 = ftp_state_type_resp_part_5(param_1,iVar20);
    }
    else {
      iVar21 = 0x11;
      Curl_failf(*param_1,"Couldn\'t set desired mode");
    }
    break;
  case 0x17:
  case 0x18:
  case 0x19:
    iVar18 = *param_1;
    if (local_5c == 0xd5) {
      lVar24 = strtoll((char *)(iVar18 + 0x5a0),(char **)0x0,0);
      uVar16 = (undefined4)((ulonglong)lVar24 >> 0x20);
      uVar8 = (undefined4)lVar24;
      if (iVar20 == 0x17) {
        lVar3 = lVar24;
        if (lVar24 != -1) {
          curl_msnprintf(iVar18 + 0x59c,0x4001,"Content-Length: %lld\r\n");
          uVar23 = Curl_client_write(param_1,3,iVar18 + 0x59c,0,lVar24);
          lVar3 = CONCAT44((int)((ulonglong)uVar23 >> 0x20),uVar8);
          if ((int)uVar23 != 0) {
            return (int)uVar23;
          }
        }
        goto LAB_0005dc9a;
      }
    }
    else {
      lVar24 = CONCAT44(uVar8,0xffffffff);
      uVar16 = 0xffffffff;
      lVar3 = CONCAT44(uVar8,0xffffffff);
      if (iVar20 == 0x17) {
LAB_0005dc9a:
        Curl_pgrsSetDownloadSize(iVar18,(int)((ulonglong)lVar3 >> 0x20),(int)lVar3,uVar16);
        iVar18 = ftp_state_rest(param_1);
        return iVar18;
      }
    }
    uVar8 = (undefined4)lVar24;
    if (iVar20 == 0x18) {
      Curl_pgrsSetDownloadSize(iVar18,(int)((ulonglong)lVar24 >> 0x20),uVar8,uVar16);
      iVar21 = ftp_state_retr(param_1,extraout_r1,uVar8,uVar16);
    }
    else {
      *(undefined4 *)(iVar18 + 0x8698) = uVar8;
      *(undefined4 *)(iVar18 + 0x869c) = uVar16;
      iVar21 = ftp_state_ul_setup(param_1,1);
    }
    break;
  case 0x1a:
  case 0x1b:
    if (iVar20 == 0x1b) {
      if (local_5c == 0x15e) {
        iVar21 = Curl_pp_sendf(piVar17,"RETR %s",param_1[0x102]);
        if (iVar21 == 0) {
          param_1[0x10a] = 0x20;
        }
      }
      else {
        iVar21 = 0x1f;
        Curl_failf(*param_1,"Couldn\'t use REST");
      }
    }
    else {
      if (local_5c == 0x15e) {
        builtin_strncpy(local_54,"Accept-ranges: b",0x10);
        local_44._0_1_ = 'y';
        local_44._1_1_ = 't';
        local_44._2_1_ = 'e';
        local_44._3_1_ = 's';
        local_40 = 0xa0d;
        iVar18 = Curl_client_write(param_1,3,local_54,0);
        if (iVar18 != 0) {
          return iVar18;
        }
      }
      iVar21 = ftp_state_prepare_transfer(param_1);
    }
    break;
  case 0x1c:
    iVar18 = *param_1;
    if (local_5c - 200U < 100) {
      Curl_infof(iVar18,"Connect data stream actively\n");
      param_1[0x10a] = 0;
      iVar21 = ftp_dophase_done(param_1);
    }
    else {
      if (param_1[0x107] == 0) {
        Curl_infof(iVar18,"disabling EPRT usage\n");
        iVar21 = 1;
        *(undefined1 *)((int)param_1 + 0x1fe) = 0;
      }
      else {
        iVar21 = param_1[0x107] + 1;
        if (iVar21 == 2) {
          Curl_failf(iVar18,"Failed to do PORT");
          return 0x1e;
        }
      }
      iVar21 = ftp_state_use_port(param_1,iVar21);
    }
    break;
  case 0x1d:
    if (local_5c == 200) {
      iVar21 = ftp_state_use_pasv(param_1);
    }
    else {
      iVar21 = 0x54;
      Curl_failf(iVar18,"PRET command not accepted: %03d",local_5c);
    }
    break;
  case 0x1e:
    iVar21 = ftp_state_pasv_resp(param_1,local_5c);
    break;
  case 0x1f:
  case 0x20:
    iVar21 = *param_1;
    iVar18 = *(int *)(iVar21 + 0x14c);
    if (local_5c != 0x96 && local_5c != 0x7d) {
      if (local_5c == 0x1c2 && iVar20 == 0x1f) {
        *(undefined4 *)(iVar18 + 0xc) = 2;
        param_1[0x10a] = (uint)(local_5c == 0x96 || local_5c == 0x7d);
        return 0;
      }
      Curl_failf(iVar21,"RETR response: %03d",local_5c);
      if (local_5c != 0x226 || iVar20 != 0x20) {
        return 0x13;
      }
      return 0x4e;
    }
    if ((iVar20 == 0x1f) || (*(char *)(iVar21 + 0x2fb) != '\0')) {
      lVar24 = *(longlong *)(iVar18 + 0x10);
      if (*(int *)(iVar18 + 0x14) < 0) goto LAB_0005dbd6;
    }
    else {
      lVar24 = *(longlong *)(iVar18 + 0x10);
      if (*(int *)(iVar18 + 0x14) < (int)(uint)(*(int *)(iVar18 + 0x10) == 0)) {
        pcVar6 = strstr((char *)(iVar21 + 0x59c)," bytes");
        pbVar13 = (byte *)(pcVar6 + -1);
        if (pcVar6 == (char *)0x0) {
LAB_0005dbd6:
          lVar24 = -1;
        }
        else {
          iVar18 = (int)pbVar13 - (iVar21 + 0x59c);
          if (iVar18 == 1) {
LAB_0005dec2:
            if (pbVar13 == (byte *)0x0) goto LAB_0005dbd6;
          }
          else {
            uVar15 = (uint)(byte)pcVar6[-1];
            if (uVar15 != 0x28) {
              ppuVar7 = __ctype_b_loc();
              pbVar11 = (byte *)(pcVar6 + -2);
              do {
                pbVar13 = pbVar11;
                if (-1 < (int)((uint)(*ppuVar7)[uVar15] << 0x14)) goto LAB_0005dbd6;
                if (pbVar13 == (byte *)(pcVar6 + -iVar18)) goto LAB_0005dec2;
                uVar15 = (uint)*pbVar13;
                pbVar11 = pbVar13 + -1;
              } while (uVar15 != 0x28);
            }
          }
          lVar24 = strtoll((char *)(pbVar13 + 1),(char **)0x0,0);
        }
      }
    }
    iVar14 = (int)((ulonglong)lVar24 >> 0x20);
    uVar15 = *(uint *)(iVar21 + 0x60);
    iVar18 = *(int *)(iVar21 + 100);
    lVar3 = *(longlong *)(iVar21 + 0x60);
    bVar22 = uVar15 < (uint)lVar24;
    if (((int)((iVar18 - iVar14) - (uint)bVar22) < 0 ==
         (SBORROW4(iVar18,iVar14) != SBORROW4(iVar18 - iVar14,(uint)bVar22))) ||
       (iVar18 < (int)(uint)(uVar15 == 0))) {
      if (iVar20 != 0x1f) {
        if (*(char *)(iVar21 + 0x2fb) != '\0') {
          lVar24 = -1;
        }
        Curl_infof(iVar21,"Maxdownload = %lld\n",uVar15,iVar18);
        goto LAB_0005dbb8;
      }
      Curl_infof(iVar21,"Maxdownload = %lld\n",uVar15,iVar18);
    }
    else {
      *(uint *)(iVar21 + 0x50) = uVar15;
      *(int *)(iVar21 + 0x54) = iVar18;
      Curl_infof(iVar21,"Maxdownload = %lld\n",uVar15,iVar18);
      lVar24 = lVar3;
      if (iVar20 != 0x1f) {
LAB_0005dbb8:
        Curl_infof(iVar21,"Getting file with size: %lld\n",(int)lVar24,
                   (int)((ulonglong)lVar24 >> 0x20));
      }
    }
    param_1[0x10b] = iVar20;
    *(longlong *)(param_1 + 0x10c) = lVar24;
    if (*(char *)(iVar21 + 0x2fe) != '\0') {
      iVar18 = AllowServerConnect(param_1,&local_75);
      if (iVar18 != 0) {
        return iVar18;
      }
      if (local_75 == '\0') {
        Curl_infof(iVar21,"Data conn was not available immediately\n");
        param_1[0x10a] = 0;
        *(undefined1 *)(param_1 + 0x104) = 1;
        return 0;
      }
      return 0;
    }
LAB_0005da20:
    iVar21 = InitiateTransfer(param_1);
    break;
  case 0x21:
    iVar18 = *param_1;
    if (local_5c < 400) {
      param_1[0x10b] = 0x21;
      if (*(char *)(iVar18 + 0x2fe) != '\0') {
        param_1[0x10a] = 0;
        iVar21 = AllowServerConnect(param_1,&local_75);
        if (iVar21 != 0) {
          return iVar21;
        }
        if (local_75 == '\0') {
          Curl_infof(iVar18,"Data conn was not available immediately\n");
          *(undefined1 *)(param_1 + 0x104) = 1;
          return 0;
        }
        return 0;
      }
      goto LAB_0005da20;
    }
    iVar21 = 0x19;
    Curl_failf(iVar18,"Failed FTP upload: %0d",local_5c);
    goto switchD_0005d44c_default;
  }
  return iVar21;
}

