
int BIO_dump_indent_cb_constprop_4(code *param_1,undefined4 param_2,int param_3,uint param_4)

{
  byte bVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  int local_230;
  int local_22c;
  int local_228;
  int local_224;
  int local_220;
  int local_21c;
  int local_218;
  int local_214;
  int local_210;
  int local_20c;
  int local_208;
  int local_200;
  char *local_1fc;
  int local_1f8;
  uint local_1ec;
  char acStack_1e4 [20];
  char local_1d0 [132];
  char local_14c [296];
  
  bVar8 = true;
  if ((int)param_4 < 1) {
    local_1ec = 0;
  }
  else {
    bVar1 = *(byte *)(param_3 + param_4 + -1);
    local_1ec = bVar1 & 0xdf;
    if ((bVar1 & 0xdf) == 0) {
      do {
        bVar8 = param_4 != 0;
        param_4 = param_4 - 1;
        local_1ec = local_1ec + 1;
        if (param_4 == 0) {
          local_1d0[0] = '\0';
          local_200 = 0;
          goto LAB_0019bd26;
        }
      } while ((*(byte *)(param_3 + param_4 + -1) & 0xdf) == 0);
    }
    else {
      local_1ec = 0;
      bVar8 = true;
    }
  }
  uVar5 = param_4 + 0xf & (int)param_4 >> 0x20;
  if (!bVar8) {
    uVar5 = param_4;
  }
  local_1f8 = (int)uVar5 >> 4;
  local_1d0[0] = '\0';
  if (param_4 != local_1f8 * 0x10 &&
      (int)(param_4 + local_1f8 * -0x10) < 0 == SBORROW4(param_4,local_1f8 * 0x10)) {
    local_1f8 = local_1f8 + 1;
  }
  if (local_1f8 < 1) {
    local_200 = 0;
  }
  else {
    iVar6 = 0;
    local_200 = 0;
    iVar7 = 0;
    iVar3 = param_3;
    do {
      local_1fc = local_1d0;
      local_14c[0] = '\0';
      BUF_strlcpy(local_14c,local_1fc,0x121);
      BIO_snprintf(acStack_1e4,0x14,"%04x - ",iVar6);
      BUF_strlcat(local_14c,acStack_1e4,0x121);
      if (iVar6 < (int)param_4) {
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(param_3 + iVar6),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 1 < (int)param_4) goto LAB_0019bdd2;
LAB_0019c386:
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 2) goto LAB_0019c39c;
LAB_0019bdfa:
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 2),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 3 < (int)param_4) goto LAB_0019be22;
LAB_0019c3b2:
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 4) goto LAB_0019c3c8;
LAB_0019be4a:
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 4),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 5 < (int)param_4) goto LAB_0019be74;
LAB_0019c3f4:
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 6) goto LAB_0019c40c;
LAB_0019be9e:
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 6),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 7 < (int)param_4) goto LAB_0019bec8;
LAB_0019c424:
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 8) goto LAB_0019c43c;
LAB_0019bef2:
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 8),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 9 < (int)param_4) goto LAB_0019bf1c;
LAB_0019c454:
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 10) goto LAB_0019c46c;
LAB_0019bf46:
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 10),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 0xb < (int)param_4) goto LAB_0019bf70;
LAB_0019c484:
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 0xc) goto LAB_0019c49c;
LAB_0019bf9a:
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 0xc),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 0xd < (int)param_4) goto LAB_0019bfc4;
LAB_0019c4b4:
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 0xe) goto LAB_0019c4cc;
LAB_0019bfee:
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 0xe),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 0xf < (int)param_4) goto LAB_0019c018;
LAB_0019c4e4:
        BUF_strlcat(local_14c,"   ",0x121);
      }
      else {
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 1) goto LAB_0019c386;
LAB_0019bdd2:
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 1),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 2 < (int)param_4) goto LAB_0019bdfa;
LAB_0019c39c:
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 3) goto LAB_0019c3b2;
LAB_0019be22:
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 3),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 4 < (int)param_4) goto LAB_0019be4a;
LAB_0019c3c8:
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 5) goto LAB_0019c3f4;
LAB_0019be74:
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 5),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 6 < (int)param_4) goto LAB_0019be9e;
LAB_0019c40c:
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 7) goto LAB_0019c424;
LAB_0019bec8:
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 7),0x2d);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 8 < (int)param_4) goto LAB_0019bef2;
LAB_0019c43c:
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 9) goto LAB_0019c454;
LAB_0019bf1c:
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 9),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 10 < (int)param_4) goto LAB_0019bf46;
LAB_0019c46c:
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 0xb) goto LAB_0019c484;
LAB_0019bf70:
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 0xb),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 0xc < (int)param_4) goto LAB_0019bf9a;
LAB_0019c49c:
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 0xd) goto LAB_0019c4b4;
LAB_0019bfc4:
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 0xd),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 0xe < (int)param_4) goto LAB_0019bfee;
LAB_0019c4cc:
        BUF_strlcat(local_14c,"   ",0x121);
        if ((int)param_4 <= iVar6 + 0xf) goto LAB_0019c4e4;
LAB_0019c018:
        HintPreloadData(param_3 + 0x1f + iVar6);
        BIO_snprintf(acStack_1e4,0x14,"%02x%c",(uint)*(byte *)(iVar3 + 0xf),0x20);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
      }
      local_208 = iVar6 + 0xf;
      local_20c = iVar6 + 0xe;
      local_210 = iVar6 + 0xd;
      local_214 = iVar6 + 0xc;
      local_218 = iVar6 + 0xb;
      local_21c = iVar6 + 10;
      local_220 = iVar6 + 9;
      local_224 = iVar6 + 8;
      local_228 = iVar6 + 7;
      local_22c = iVar6 + 6;
      local_230 = iVar6 + 5;
      BUF_strlcat(local_14c,"  ",0x121);
      if (iVar6 < (int)param_4) {
        uVar5 = (uint)*(byte *)(param_3 + iVar6);
        if (0x5e < uVar5 - 0x20) {
          uVar5 = 0x2e;
        }
        BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
        BUF_strlcat(local_14c,acStack_1e4,0x121);
        if (iVar6 + 1 < (int)param_4) {
          uVar5 = (uint)*(byte *)(iVar3 + 1);
          if (0x5e < uVar5 - 0x20) {
            uVar5 = 0x2e;
          }
          BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
          BUF_strlcat(local_14c,acStack_1e4,0x121);
          if (iVar6 + 2 < (int)param_4) {
            uVar5 = (uint)*(byte *)(iVar3 + 2);
            if (0x5e < uVar5 - 0x20) {
              uVar5 = 0x2e;
            }
            BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
            BUF_strlcat(local_14c,acStack_1e4,0x121);
            if (iVar6 + 3 < (int)param_4) {
              uVar5 = (uint)*(byte *)(iVar3 + 3);
              if (0x5e < uVar5 - 0x20) {
                uVar5 = 0x2e;
              }
              BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
              BUF_strlcat(local_14c,acStack_1e4,0x121);
              if (iVar6 + 4 < (int)param_4) {
                uVar5 = (uint)*(byte *)(iVar3 + 4);
                if (0x5e < uVar5 - 0x20) {
                  uVar5 = 0x2e;
                }
                BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
                BUF_strlcat(local_14c,acStack_1e4,0x121);
                if (local_230 < (int)param_4) {
                  uVar5 = (uint)*(byte *)(iVar3 + 5);
                  if (0x5e < uVar5 - 0x20) {
                    uVar5 = 0x2e;
                  }
                  BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
                  BUF_strlcat(local_14c,acStack_1e4,0x121);
                  if (local_22c < (int)param_4) {
                    uVar5 = (uint)*(byte *)(iVar3 + 6);
                    if (0x5e < uVar5 - 0x20) {
                      uVar5 = 0x2e;
                    }
                    BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
                    BUF_strlcat(local_14c,acStack_1e4,0x121);
                    if (local_228 < (int)param_4) {
                      uVar5 = (uint)*(byte *)(iVar3 + 7);
                      if (0x5e < uVar5 - 0x20) {
                        uVar5 = 0x2e;
                      }
                      BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
                      BUF_strlcat(local_14c,acStack_1e4,0x121);
                      if (local_224 < (int)param_4) {
                        uVar5 = (uint)*(byte *)(iVar3 + 8);
                        if (0x5e < uVar5 - 0x20) {
                          uVar5 = 0x2e;
                        }
                        BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
                        BUF_strlcat(local_14c,acStack_1e4,0x121);
                        if (local_220 < (int)param_4) {
                          uVar5 = (uint)*(byte *)(iVar3 + 9);
                          if (0x5e < uVar5 - 0x20) {
                            uVar5 = 0x2e;
                          }
                          BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
                          BUF_strlcat(local_14c,acStack_1e4,0x121);
                          if (local_21c < (int)param_4) {
                            uVar5 = (uint)*(byte *)(iVar3 + 10);
                            if (0x5e < uVar5 - 0x20) {
                              uVar5 = 0x2e;
                            }
                            BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
                            BUF_strlcat(local_14c,acStack_1e4,0x121);
                            if (local_218 < (int)param_4) {
                              uVar5 = (uint)*(byte *)(iVar3 + 0xb);
                              if (0x5e < uVar5 - 0x20) {
                                uVar5 = 0x2e;
                              }
                              BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
                              BUF_strlcat(local_14c,acStack_1e4,0x121);
                              if (local_214 < (int)param_4) {
                                uVar5 = (uint)*(byte *)(iVar3 + 0xc);
                                if (0x5e < uVar5 - 0x20) {
                                  uVar5 = 0x2e;
                                }
                                BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
                                BUF_strlcat(local_14c,acStack_1e4,0x121);
                                if (local_210 < (int)param_4) {
                                  uVar5 = (uint)*(byte *)(iVar3 + 0xd);
                                  if (0x5e < uVar5 - 0x20) {
                                    uVar5 = 0x2e;
                                  }
                                  BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
                                  BUF_strlcat(local_14c,acStack_1e4,0x121);
                                  if (local_20c < (int)param_4) {
                                    uVar5 = (uint)*(byte *)(iVar3 + 0xe);
                                    if (0x5e < uVar5 - 0x20) {
                                      uVar5 = 0x2e;
                                    }
                                    BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
                                    BUF_strlcat(local_14c,acStack_1e4,0x121);
                                    if (local_208 < (int)param_4) {
                                      uVar5 = (uint)*(byte *)(iVar3 + 0xf);
                                      if (0x5e < uVar5 - 0x20) {
                                        uVar5 = 0x2e;
                                      }
                                      BIO_snprintf(acStack_1e4,0x14,"%c",uVar5);
                                      BUF_strlcat(local_14c,acStack_1e4,0x121);
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      iVar7 = iVar7 + 1;
      BUF_strlcat(local_14c,"\n",0x121);
      iVar6 = iVar6 + 0x10;
      sVar2 = strlen(local_14c);
      iVar4 = (*param_1)(local_14c,sVar2,param_2);
      iVar3 = iVar3 + 0x10;
      local_200 = local_200 + iVar4;
    } while (iVar7 != local_1f8);
  }
LAB_0019bd26:
  local_1fc = local_1d0;
  if (local_1ec != 0) {
    BIO_snprintf(local_14c,0x121,"%s%04x - <SPACES/NULS>\n",local_1fc,local_1ec + param_4);
    sVar2 = strlen(local_14c);
    iVar3 = (*param_1)(local_14c,sVar2,param_2);
    local_200 = local_200 + iVar3;
  }
  return local_200;
}

