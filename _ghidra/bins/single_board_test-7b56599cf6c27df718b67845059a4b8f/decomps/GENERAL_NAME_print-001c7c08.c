
int GENERAL_NAME_print(BIO *out,GENERAL_NAME *gen)

{
  BUF_MEM *pBVar1;
  undefined1 *puVar2;
  char *format;
  stack_st_X509_NAME_ENTRY *psVar3;
  char **ppcVar4;
  BUF_MEM *pBVar5;
  
  switch(gen->type) {
  case 0:
    BIO_printf(out,"othername:<unsupported>");
    return 1;
  case 1:
    format = "email:";
    break;
  case 2:
    format = "DNS:";
    break;
  case 3:
    BIO_printf(out,"X400Name:<unsupported>");
    return 1;
  case 4:
    BIO_printf(out,"DirName:");
    X509_NAME_print_ex(out,(gen->d).directoryName,0,0x82031f);
    return 1;
  case 5:
    BIO_printf(out,"EdiPartyName:<unsupported>");
    return 1;
  case 6:
    format = "URI:";
    break;
  case 7:
    psVar3 = ((gen->d).directoryName)->entries;
    pBVar5 = ((gen->d).directoryName)->bytes;
    if (psVar3 == (stack_st_X509_NAME_ENTRY *)0x4) {
      BIO_printf(out,"IP Address:%d.%d.%d.%d",(uint)(byte)pBVar5->length,
                 (uint)*(byte *)((int)&pBVar5->length + 1),(uint)*(byte *)((int)&pBVar5->length + 2)
                 ,(uint)*(byte *)((int)&pBVar5->length + 3));
      return 1;
    }
    if (psVar3 != (stack_st_X509_NAME_ENTRY *)0x10) {
      BIO_printf(out,"IP Address:<invalid>");
      return 1;
    }
    ppcVar4 = (char **)((int)&pBVar5->length + 2);
    BIO_printf(out,"IP Address");
    do {
      pBVar1 = (BUF_MEM *)((int)ppcVar4 + -2);
      puVar2 = (undefined1 *)((int)ppcVar4 + -1);
      ppcVar4 = (char **)((int)ppcVar4 + 2);
      BIO_printf(out,":%X",(uint)CONCAT11((char)pBVar1->length,*puVar2));
    } while (ppcVar4 != (char **)((int)&pBVar5[1].data + 2));
    BIO_puts(out,"\n");
    return 1;
  case 8:
    BIO_printf(out,"Registered ID:");
    i2a_ASN1_OBJECT(out,(gen->d).registeredID);
    return 1;
  default:
    return 1;
  }
  BIO_printf(out,format);
  ASN1_STRING_print(out,(ASN1_STRING *)(gen->d).otherName);
  return 1;
}

