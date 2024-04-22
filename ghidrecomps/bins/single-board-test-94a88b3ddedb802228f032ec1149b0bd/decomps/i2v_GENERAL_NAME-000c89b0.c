
/* WARNING: Type propagation algorithm not settling */

stack_st_CONF_VALUE *
i2v_GENERAL_NAME(X509V3_EXT_METHOD *method,GENERAL_NAME *gen,stack_st_CONF_VALUE *ret)

{
  undefined2 uVar1;
  size_t sVar2;
  stack_st_X509_NAME_ENTRY *psVar3;
  BUF_MEM *pBVar4;
  stack_st_CONF_VALUE *local_124;
  char acStack_120 [8];
  undefined2 local_118 [130];
  
  local_124 = ret;
  switch(gen->type) {
  case 0:
    X509V3_add_value(DAT_000c8bc4,DAT_000c8bc0,&local_124);
    break;
  case 1:
    X509V3_add_value_uchar(DAT_000c8bc8,(char *)((gen->d).rfc822Name)->data,&local_124);
    break;
  case 2:
    X509V3_add_value_uchar(DAT_000c8bcc,(char *)((gen->d).rfc822Name)->data,&local_124);
    break;
  case 3:
    X509V3_add_value(DAT_000c8bd0,DAT_000c8bc0,&local_124);
    break;
  case 4:
    X509_NAME_oneline((gen->d).directoryName,(char *)local_118,0x100);
    X509V3_add_value(DAT_000c8bd4,(char *)local_118,&local_124);
    break;
  case 5:
    X509V3_add_value(DAT_000c8bd8,DAT_000c8bc0,&local_124);
    break;
  case 6:
    X509V3_add_value_uchar(DAT_000c8bdc,(char *)((gen->d).rfc822Name)->data,&local_124);
    break;
  case 7:
    psVar3 = ((gen->d).directoryName)->entries;
    pBVar4 = ((gen->d).directoryName)->bytes;
    if (psVar3 == (stack_st_X509_NAME_ENTRY *)0x4) {
      BIO_snprintf((char *)local_118,0x100,DAT_000c8be4,(uint)*(byte *)&pBVar4->length,
                   (uint)*(byte *)((int)&pBVar4->length + 1),
                   (uint)*(byte *)((int)&pBVar4->length + 2),
                   (uint)*(byte *)((int)&pBVar4->length + 3));
    }
    else {
      if (psVar3 != (stack_st_X509_NAME_ENTRY *)0x10) {
        X509V3_add_value(DAT_000c8bb8,DAT_000c8be0,&local_124);
        return local_124;
      }
      local_118[0]._0_1_ = '\0';
      BIO_snprintf(acStack_120,5,DAT_000c8bb0,
                   (uint)CONCAT11(*(undefined *)&pBVar4->length,
                                  *(undefined *)((int)&pBVar4->length + 1)));
      strcat((char *)local_118,acStack_120);
      sVar2 = strlen((char *)local_118);
      uVar1 = *DAT_000c8bb4;
      *(undefined2 *)((int)local_118 + sVar2) = uVar1;
      BIO_snprintf(acStack_120,5,DAT_000c8bb0,
                   (uint)CONCAT11(*(undefined *)((int)&pBVar4->length + 2),
                                  *(undefined *)((int)&pBVar4->length + 3)));
      strcat((char *)local_118,acStack_120);
      sVar2 = strlen((char *)local_118);
      *(undefined2 *)((int)local_118 + sVar2) = uVar1;
      BIO_snprintf(acStack_120,5,DAT_000c8bb0,
                   (uint)CONCAT11(*(undefined *)&pBVar4->data,*(undefined *)((int)&pBVar4->data + 1)
                                 ));
      strcat((char *)local_118,acStack_120);
      sVar2 = strlen((char *)local_118);
      *(undefined2 *)((int)local_118 + sVar2) = uVar1;
      BIO_snprintf(acStack_120,5,DAT_000c8bb0,
                   (uint)CONCAT11(*(undefined *)((int)&pBVar4->data + 2),
                                  *(undefined *)((int)&pBVar4->data + 3)));
      strcat((char *)local_118,acStack_120);
      sVar2 = strlen((char *)local_118);
      *(undefined2 *)((int)local_118 + sVar2) = uVar1;
      BIO_snprintf(acStack_120,5,DAT_000c8bb0,
                   (uint)CONCAT11(*(undefined *)&pBVar4->max,*(undefined *)((int)&pBVar4->max + 1)))
      ;
      strcat((char *)local_118,acStack_120);
      sVar2 = strlen((char *)local_118);
      *(undefined2 *)((int)local_118 + sVar2) = uVar1;
      BIO_snprintf(acStack_120,5,DAT_000c8bb0,
                   (uint)CONCAT11(*(undefined *)((int)&pBVar4->max + 2),
                                  *(undefined *)((int)&pBVar4->max + 3)));
      strcat((char *)local_118,acStack_120);
      sVar2 = strlen((char *)local_118);
      *(undefined2 *)((int)local_118 + sVar2) = uVar1;
      BIO_snprintf(acStack_120,5,DAT_000c8bb0,
                   (uint)CONCAT11(*(undefined *)&pBVar4[1].length,
                                  *(undefined *)((int)&pBVar4[1].length + 1)));
      strcat((char *)local_118,acStack_120);
      sVar2 = strlen((char *)local_118);
      *(undefined2 *)((int)local_118 + sVar2) = uVar1;
      BIO_snprintf(acStack_120,5,DAT_000c8bb0,
                   (uint)CONCAT11(*(undefined *)((int)&pBVar4[1].length + 2),
                                  *(undefined *)((int)&pBVar4[1].length + 3)));
      strcat((char *)local_118,acStack_120);
    }
    X509V3_add_value(DAT_000c8bb8,(char *)local_118,&local_124);
    break;
  case 8:
    i2t_ASN1_OBJECT((char *)local_118,0x100,(gen->d).registeredID);
    X509V3_add_value(DAT_000c8bbc,(char *)local_118,&local_124);
  }
  return local_124;
}

