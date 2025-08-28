
stack_st_CONF_VALUE *
i2v_GENERAL_NAME(X509V3_EXT_METHOD *method,GENERAL_NAME *gen,stack_st_CONF_VALUE *ret)

{
  char *pcVar1;
  size_t sVar2;
  stack_st_X509_NAME_ENTRY *psVar3;
  BUF_MEM *pBVar4;
  stack_st_CONF_VALUE *local_124;
  char acStack_120 [8];
  char local_118 [260];
  
  local_124 = ret;
  switch(gen->type) {
  case 0:
    X509V3_add_value("othername","<unsupported>",&local_124);
    break;
  case 1:
    X509V3_add_value_uchar("email",(char *)((gen->d).rfc822Name)->data,&local_124);
    break;
  case 2:
    X509V3_add_value_uchar("DNS",(char *)((gen->d).rfc822Name)->data,&local_124);
    break;
  case 3:
    X509V3_add_value("X400Name","<unsupported>",&local_124);
    break;
  case 4:
    X509_NAME_oneline((gen->d).directoryName,local_118,0x100);
    X509V3_add_value("DirName",local_118,&local_124);
    break;
  case 5:
    X509V3_add_value("EdiPartyName","<unsupported>",&local_124);
    break;
  case 6:
    X509V3_add_value_uchar("URI",(char *)((gen->d).rfc822Name)->data,&local_124);
    break;
  case 7:
    psVar3 = ((gen->d).directoryName)->entries;
    pBVar4 = ((gen->d).directoryName)->bytes;
    if (psVar3 == (stack_st_X509_NAME_ENTRY *)0x4) {
      BIO_snprintf(local_118,0x100,"%d.%d.%d.%d",(uint)(byte)pBVar4->length,
                   (uint)*(byte *)((int)&pBVar4->length + 1),
                   (uint)*(byte *)((int)&pBVar4->length + 2),
                   (uint)*(byte *)((int)&pBVar4->length + 3));
    }
    else {
      if (psVar3 != (stack_st_X509_NAME_ENTRY *)0x10) {
        X509V3_add_value("IP Address","<invalid>",&local_124);
        return local_124;
      }
      local_118[0] = '\0';
      BIO_snprintf(acStack_120,5,"%X",
                   (uint)CONCAT11((char)pBVar4->length,*(undefined1 *)((int)&pBVar4->length + 1)));
      strcat(local_118,acStack_120);
      sVar2 = strlen(local_118);
      pcVar1 = local_118 + sVar2;
      pcVar1[0] = ':';
      pcVar1[1] = '\0';
      BIO_snprintf(acStack_120,5,"%X",
                   (uint)CONCAT11(*(undefined1 *)((int)&pBVar4->length + 2),
                                  *(undefined1 *)((int)&pBVar4->length + 3)));
      strcat(local_118,acStack_120);
      sVar2 = strlen(local_118);
      pcVar1 = local_118 + sVar2;
      pcVar1[0] = ':';
      pcVar1[1] = '\0';
      BIO_snprintf(acStack_120,5,"%X",
                   (uint)CONCAT11(*(undefined1 *)&pBVar4->data,
                                  *(undefined1 *)((int)&pBVar4->data + 1)));
      strcat(local_118,acStack_120);
      sVar2 = strlen(local_118);
      pcVar1 = local_118 + sVar2;
      pcVar1[0] = ':';
      pcVar1[1] = '\0';
      BIO_snprintf(acStack_120,5,"%X",
                   (uint)CONCAT11(*(undefined1 *)((int)&pBVar4->data + 2),
                                  *(undefined1 *)((int)&pBVar4->data + 3)));
      strcat(local_118,acStack_120);
      sVar2 = strlen(local_118);
      pcVar1 = local_118 + sVar2;
      pcVar1[0] = ':';
      pcVar1[1] = '\0';
      BIO_snprintf(acStack_120,5,"%X",
                   (uint)CONCAT11((char)pBVar4->max,*(undefined1 *)((int)&pBVar4->max + 1)));
      strcat(local_118,acStack_120);
      sVar2 = strlen(local_118);
      pcVar1 = local_118 + sVar2;
      pcVar1[0] = ':';
      pcVar1[1] = '\0';
      BIO_snprintf(acStack_120,5,"%X",
                   (uint)CONCAT11(*(undefined1 *)((int)&pBVar4->max + 2),
                                  *(undefined1 *)((int)&pBVar4->max + 3)));
      strcat(local_118,acStack_120);
      sVar2 = strlen(local_118);
      pcVar1 = local_118 + sVar2;
      pcVar1[0] = ':';
      pcVar1[1] = '\0';
      BIO_snprintf(acStack_120,5,"%X",
                   (uint)CONCAT11((char)pBVar4[1].length,*(undefined1 *)((int)&pBVar4[1].length + 1)
                                 ));
      strcat(local_118,acStack_120);
      sVar2 = strlen(local_118);
      pcVar1 = local_118 + sVar2;
      pcVar1[0] = ':';
      pcVar1[1] = '\0';
      BIO_snprintf(acStack_120,5,"%X",
                   (uint)CONCAT11(*(undefined1 *)((int)&pBVar4[1].length + 2),
                                  *(undefined1 *)((int)&pBVar4[1].length + 3)));
      strcat(local_118,acStack_120);
    }
    X509V3_add_value("IP Address",local_118,&local_124);
    break;
  case 8:
    i2t_ASN1_OBJECT(local_118,0x100,(gen->d).registeredID);
    X509V3_add_value("Registered ID",local_118,&local_124);
  }
  return local_124;
}

