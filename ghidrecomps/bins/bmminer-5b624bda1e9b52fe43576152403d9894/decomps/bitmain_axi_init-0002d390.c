
/* WARNING: Unknown calling convention */

int bitmain_axi_init(void)

{
  char *pcVar1;
  int iVar2;
  uint *puVar3;
  void *pvVar4;
  undefined4 *puVar5;
  char cVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  uint data;
  char tmp42 [2048];
  
  iVar2 = open(DAT_0002d614,2);
  *DAT_0002d618 = iVar2;
  iVar8 = DAT_0002d61c;
  if (iVar2 < 0) {
    if (*DAT_0002d77c == '\0') goto LAB_0002d746;
    pcVar7 = DAT_0002d794;
    if ((*DAT_0002d780 == '\0') && (*DAT_0002d784 == '\0')) {
      iVar8 = *DAT_0002d778;
joined_r0x0002d72c:
      if (iVar8 < 7) goto LAB_0002d746;
    }
LAB_0002d738:
    snprintf(tmp42,0x800,pcVar7,iVar2);
    _applog(7,tmp42,false);
LAB_0002d746:
    perror(DAT_0002d798);
    return -1;
  }
  puVar3 = (uint *)mmap((void *)0x0,0x160,3,1,iVar2,0);
  *(uint **)(iVar8 + 0x8d4) = puVar3;
  pcVar1 = DAT_0002d638;
  pcVar7 = DAT_0002d620;
  if (puVar3 == (uint *)0x0) {
    if (*DAT_0002d77c == '\0') {
      return -1;
    }
    pcVar7 = DAT_0002d788;
    if ((*DAT_0002d780 != '\0') || (*DAT_0002d784 != '\0')) goto LAB_0002d6a2;
    iVar2 = *DAT_0002d778;
  }
  else {
    if (*DAT_0002d620 != '\0') {
      if (((*DAT_0002d638 == '\0') && (*DAT_0002d63c == '\0')) && (*DAT_0002d648 < 7)) {
        uVar9 = *puVar3;
        if ((undefined *)(uVar9 & 0xffff) == &LAB_0000c500_1) {
LAB_0002d5d0:
          if ((*pcVar1 == '\0') && (*DAT_0002d63c == '\0')) goto LAB_0002d4dc;
        }
        else {
LAB_0002d4ce:
          if ((*DAT_0002d63c != '\0') || (6 < *DAT_0002d648)) {
LAB_0002d5aa:
            snprintf(tmp42,0x800,DAT_0002d65c,uVar9,&LAB_0000c500_1);
            _applog(7,tmp42,false);
            cVar6 = *pcVar7;
            goto LAB_0002d5ca;
          }
LAB_0002d4dc:
          if (*DAT_0002d648 < 7) goto LAB_0002d3d0;
        }
        snprintf(tmp42,0x800,DAT_0002d64c,uVar9);
        _applog(7,tmp42,false);
      }
      else {
        snprintf(tmp42,0x800,DAT_0002d644,puVar3);
        _applog(7,tmp42,false);
        cVar6 = *pcVar7;
        uVar9 = **(uint **)(iVar8 + 0x8d4);
        if ((undefined *)(uVar9 & 0xffff) == &LAB_0000c500_1) {
LAB_0002d5ca:
          if (cVar6 != '\0') goto LAB_0002d5d0;
        }
        else if (cVar6 != '\0') {
          if (*pcVar1 == '\0') goto LAB_0002d4ce;
          goto LAB_0002d5aa;
        }
      }
    }
LAB_0002d3d0:
    iVar2 = open(DAT_0002d624,2);
    *DAT_0002d628 = iVar2;
    iVar8 = DAT_0002d62c;
    if (iVar2 < 0) {
      if (*pcVar7 == '\0') goto LAB_0002d746;
      pcVar7 = DAT_0002d79c;
      if ((*DAT_0002d780 == '\0') && (*DAT_0002d784 == '\0')) {
        iVar8 = *DAT_0002d778;
        goto joined_r0x0002d72c;
      }
      goto LAB_0002d738;
    }
    pvVar4 = mmap((void *)0x0,0x1000000,3,1,iVar2,0);
    cVar6 = *pcVar7;
    *(void **)(iVar8 + 0x200) = pvVar4;
    pcVar1 = DAT_0002d638;
    if (pvVar4 != (void *)0x0) {
      if (cVar6 == '\0') {
        *(void **)(iVar8 + 0x204) = pvVar4;
        *(int *)(iVar8 + 0x208) = (int)pvVar4 + 0x200000;
        *(int *)(iVar8 + 0x20c) = (int)pvVar4 + 0x210000;
        goto LAB_0002d41c;
      }
      if (((*DAT_0002d638 == '\0') && (*DAT_0002d63c == '\0')) && (*DAT_0002d778 < 7)) {
        *(void **)(iVar8 + 0x204) = pvVar4;
        *(int *)(iVar8 + 0x208) = (int)pvVar4 + 0x200000;
        *(int *)(iVar8 + 0x20c) = (int)pvVar4 + 0x210000;
      }
      else {
        snprintf(tmp42,0x800,DAT_0002d650,pvVar4);
        _applog(7,tmp42,false);
        iVar2 = *(int *)(iVar8 + 0x200);
        cVar6 = *pcVar7;
        *(int *)(iVar8 + 0x204) = iVar2;
        *(int *)(iVar8 + 0x208) = iVar2 + 0x200000;
        *(int *)(iVar8 + 0x20c) = iVar2 + 0x210000;
        if (cVar6 == '\0') goto LAB_0002d41c;
      }
      if (((*pcVar1 == '\0') && (*DAT_0002d63c == '\0')) && (*DAT_0002d648 < 7)) {
LAB_0002d582:
        if (*DAT_0002d648 < 7) goto LAB_0002d41c;
      }
      else {
        snprintf(tmp42,0x800,DAT_0002d654);
        _applog(7,tmp42,false);
        if (*pcVar7 == '\0') goto LAB_0002d41c;
        if ((*pcVar1 == '\0') && (*DAT_0002d63c == '\0')) goto LAB_0002d582;
      }
      snprintf(tmp42,0x800,DAT_0002d658,*(undefined4 *)(iVar8 + 0x20c));
      _applog(7,tmp42,false);
LAB_0002d41c:
      iVar2 = DAT_0002d630;
      set_nonce2_and_job_id_store_address(*(uint *)(DAT_0002d630 + 0x8c));
      set_job_start_address(*(int *)(iVar2 + 0x8c) + 0x200000);
      puVar5 = (undefined4 *)calloc(0x301c,1);
      *DAT_0002d634 = puVar5;
      if (puVar5 != (undefined4 *)0x0) {
        cVar6 = *pcVar7;
        *puVar5 = *(undefined4 *)(iVar8 + 0x208);
        if (cVar6 != '\0') {
          if (((*DAT_0002d638 == '\0') && (*DAT_0002d63c == '\0')) && (*DAT_0002d648 < 7)) {
            return 0;
          }
          tmp42._0_4_ = *DAT_0002d640;
          tmp42._4_4_ = DAT_0002d640[1];
          tmp42._8_4_ = DAT_0002d640[2];
          tmp42._12_4_ = DAT_0002d640[3];
          tmp42._16_4_ = DAT_0002d640[4];
          tmp42._20_4_ = DAT_0002d640[5];
          tmp42._24_2_ = (undefined2)DAT_0002d640[6];
          _applog(7,tmp42,false);
        }
        return 0;
      }
      if (*pcVar7 == '\0') {
        return -1;
      }
      if (((*DAT_0002d780 == '\0') && (*DAT_0002d784 == '\0')) && (*DAT_0002d778 < 7)) {
        return -1;
      }
      tmp42._0_4_ = *DAT_0002d790;
      tmp42._4_4_ = DAT_0002d790[1];
      tmp42._8_4_ = DAT_0002d790[2];
      tmp42._12_4_ = DAT_0002d790[3];
      tmp42._16_4_ = DAT_0002d790[4];
      tmp42._20_4_ = DAT_0002d790[5];
      tmp42[24] = (char)DAT_0002d790[6];
      _applog(7,tmp42,false);
      return -1;
    }
    if (cVar6 == '\0') {
      return -1;
    }
    pcVar7 = DAT_0002d78c;
    if ((*DAT_0002d780 != '\0') || (*DAT_0002d784 != '\0')) goto LAB_0002d6a2;
    iVar2 = *DAT_0002d778;
  }
  if (iVar2 < 7) {
    return -1;
  }
LAB_0002d6a2:
  snprintf(tmp42,0x800,pcVar7,0);
  _applog(7,tmp42,false);
  return -1;
}

