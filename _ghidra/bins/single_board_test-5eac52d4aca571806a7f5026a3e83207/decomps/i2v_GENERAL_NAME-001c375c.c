
stack_st_CONF_VALUE *
i2v_GENERAL_NAME(X509V3_EXT_METHOD *method,GENERAL_NAME *gen,stack_st_CONF_VALUE *ret)

{
  char *pcVar1;
  int iVar2;
  size_t sVar3;
  stack_st_X509_NAME_ENTRY *psVar4;
  char **ppcVar5;
  char **ppcVar6;
  BUF_MEM *pBVar7;
  stack_st_CONF_VALUE *local_12c;
  char acStack_128 [8];
  char local_120 [256];
  
  local_12c = ret;
  switch(gen->type) {
  case 0:
    iVar2 = X509V3_add_value("othername","<unsupported>",&local_12c);
    ret = local_12c;
    break;
  case 1:
    iVar2 = x509v3_add_len_value_uchar
                      ("email",((gen->d).rfc822Name)->data,((gen->d).rfc822Name)->length,&local_12c)
    ;
    ret = local_12c;
    break;
  case 2:
    iVar2 = x509v3_add_len_value_uchar
                      (&DAT_00236530,((gen->d).rfc822Name)->data,((gen->d).rfc822Name)->length,
                       &local_12c);
    ret = local_12c;
    break;
  case 3:
    iVar2 = X509V3_add_value("X400Name","<unsupported>",&local_12c);
    ret = local_12c;
    break;
  case 4:
    pcVar1 = X509_NAME_oneline((gen->d).directoryName,local_120,0x100);
    if (pcVar1 != (char *)0x0) {
      iVar2 = X509V3_add_value("DirName",local_120,&local_12c);
      ret = local_12c;
      break;
    }
    goto LAB_001c37be;
  case 5:
    iVar2 = X509V3_add_value("EdiPartyName","<unsupported>",&local_12c);
    ret = local_12c;
    break;
  case 6:
    iVar2 = x509v3_add_len_value_uchar
                      (&DAT_00236534,((gen->d).rfc822Name)->data,((gen->d).rfc822Name)->length,
                       &local_12c);
    ret = local_12c;
    break;
  case 7:
    psVar4 = ((gen->d).directoryName)->entries;
    pBVar7 = ((gen->d).directoryName)->bytes;
    if (psVar4 == (stack_st_X509_NAME_ENTRY *)0x4) {
      BIO_snprintf(local_120,0x100,"%d.%d.%d.%d",(uint)(byte)pBVar7->length,
                   (uint)*(byte *)((int)&pBVar7->length + 1),
                   (uint)*(byte *)((int)&pBVar7->length + 2),
                   (uint)*(byte *)((int)&pBVar7->length + 3));
    }
    else {
      if (psVar4 != (stack_st_X509_NAME_ENTRY *)0x10) {
        iVar2 = X509V3_add_value("IP Address","<invalid>",&local_12c);
        ret = local_12c;
        break;
      }
      local_120[0] = '\0';
      BIO_snprintf(acStack_128,5,"%X",
                   (uint)CONCAT11((char)pBVar7->length,*(undefined1 *)((int)&pBVar7->length + 1)));
      strcat(local_120,acStack_128);
      ppcVar5 = &pBVar7->data;
      do {
        ppcVar6 = (char **)((int)ppcVar5 + 2);
        sVar3 = strlen(local_120);
        pcVar1 = local_120 + sVar3;
        pcVar1[0] = ':';
        pcVar1[1] = '\0';
        BIO_snprintf(acStack_128,5,"%X",
                     (uint)CONCAT11(*(undefined1 *)((int)ppcVar5 + -2),
                                    *(undefined1 *)((int)ppcVar5 + -1)));
        strcat(local_120,acStack_128);
        ppcVar5 = ppcVar6;
      } while (ppcVar6 != (char **)((int)&pBVar7[1].data + 2));
    }
    iVar2 = X509V3_add_value("IP Address",local_120,&local_12c);
    ret = local_12c;
    break;
  case 8:
    i2t_ASN1_OBJECT(local_120,0x100,(gen->d).registeredID);
    iVar2 = X509V3_add_value("Registered ID",local_120,&local_12c);
    ret = local_12c;
    break;
  default:
    goto switchD_001c376c_default;
  }
  if (iVar2 == 0) {
LAB_001c37be:
    ret = (stack_st_CONF_VALUE *)0x0;
  }
switchD_001c376c_default:
  return ret;
}

